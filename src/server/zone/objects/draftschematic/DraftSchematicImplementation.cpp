/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

#include "DraftSchematicImplementation.h"

DraftSchematicImplementation::DraftSchematicImplementation(uint32 sID, const String& n,
		const String& file, const String& sname, uint32 objCRC, const String& groupName, uint32 complexity,
		uint32 schematicSize, int craftingToolTab) :
			DraftSchematicServant() {
	DraftSchematicImplementation::schematicID = sID;
	DraftSchematicImplementation::customName = n;
	DraftSchematicImplementation::stfFile = file;
	DraftSchematicImplementation::stfName = sname;
	DraftSchematicImplementation::objectCRC = objCRC;
	DraftSchematicImplementation::groupName = groupName;
	DraftSchematicImplementation::complexity = complexity;
	DraftSchematicImplementation::schematicSize = schematicSize;
	DraftSchematicImplementation::craftingToolTab = craftingToolTab;

	craftingValues = new DraftSchematicValues();

	persistent = false;
	expPointsUsed = 0;

	finished = false;
}

DraftSchematicImplementation::DraftSchematicImplementation(
		DraftSchematic* draftSchematic, uint32 sID) :
	DraftSchematicServant() {

	schematicID = sID;
	customName = draftSchematic->getCustomName();
	stfFile = draftSchematic->getStfFile();
	stfName = draftSchematic->getStfName();
	objectCRC = draftSchematic->getObjectCRC();
	groupName = draftSchematic->getGroupName();
	complexity = draftSchematic->getComplexity();
	schematicSize = draftSchematic->getSchematicSize();
	craftingToolTab = draftSchematic->getCraftingToolTab();

	craftingValues = new DraftSchematicValues();

	persistent = false;

	finished = false;

	resourcesRemoved = false;

	for (int i = 0; i < draftSchematic->getIngredientListSize(); ++i) {
		dsIngredients.add(draftSchematic->cloneIngredient(i));
	}

	for (int i = 0; i < draftSchematic->getExpPropGroupListSize(); ++i) {
		dsExpPropGroups.add(draftSchematic->cloneExpPropGroup(i));
	}

	tanoAttributes = draftSchematic->getTanoAttributes();
	xpType = draftSchematic->getXpType();
	xp = draftSchematic->getXp();

	experimentingSkill = draftSchematic->getExperimentingSkill();
	assemblySkill = draftSchematic->getAssemblySkill();
	customizationSkill = draftSchematic->getCustomizationSkill();

	for (int i = 0; i < draftSchematic->getCustomizationOptionCount(); ++i) {
		customizationOptions.add(draftSchematic->getCustomizationOption(i));
		customizationDefaults.add(draftSchematic->getCustomizationDefaultValue(i));
	}

	customizationSkill = draftSchematic->getCustomizationSkill();

	//toString();
}

DraftSchematicImplementation::~DraftSchematicImplementation(){
	while (dsExpPropGroups.size() > 0)
		dsExpPropGroups.remove(0)->finalize();

	while (dsIngredients.size() > 0)
		dsIngredients.remove(0)->finalize();

	craftingValues->finalize();
	craftingValues = NULL;
}

DraftSchematic* DraftSchematicImplementation::dsClone(DraftSchematic* draftSchematic) {
	if (draftSchematic != NULL) {
		return new DraftSchematic(draftSchematic, draftSchematic->getSchematicID());
	} else {
		return NULL;
	}
}

void DraftSchematicImplementation::close(Player* player) {
	if (player == NULL)
		return;

	BaseMessage* msg = new SceneObjectCloseMessage(_this->getObjectID());
	player->sendMessage(msg);
}

void DraftSchematicImplementation::destroy(Player* player) {
	if (player == NULL)
		return;

	BaseMessage* msg = new SceneObjectDestroyMessage(_this->getObjectID());
	player->sendMessage(msg);
}

void DraftSchematicImplementation::sendTo(Player* player) {
	// This sends the initial DraftSchematic data to begin the crafting Session
	if (player == NULL)
		return;

	// Scene Create
	BaseMessage* create = new SceneObjectCreateMessage(_this->getObjectID(), 0x3819C409);
	player->sendMessage(create);

	// Link to Crafting Tool
	BaseMessage* link = new UpdateContainmentMessage(_this->getObjectID(), _this->getParent()->getObjectID(), 4);
	player->sendMessage(link);

	// MSCO3
	UnicodeString& uniPlayerName = player->getCharacterName();

	ManufactureSchematicObjectMessage3* msco3 =
		new ManufactureSchematicObjectMessage3(_this->getObjectID(), _this->getComplexity(), uniPlayerName);
	player->sendMessage(msco3);

	// MSCO6
	ManufactureSchematicObjectMessage6* msco6 =
		new ManufactureSchematicObjectMessage6(_this->getObjectID(), _this->getObjectCRC());
	player->sendMessage(msco6);

	// MSCO8
	ManufactureSchematicObjectMessage8* msco8 =
		new ManufactureSchematicObjectMessage8(_this->getObjectID());
	player->sendMessage(msco8);

	// MSCO9
	ManufactureSchematicObjectMessage9* msco9 =
		new ManufactureSchematicObjectMessage9(_this->getObjectID());
	player->sendMessage(msco9);

	// Scene Close
	BaseMessage* close = new SceneObjectCloseMessage(_this->getObjectID());
	player->sendMessage(close);

}

void DraftSchematicImplementation::generateAttributes(SceneObject* obj) {
	if (!obj->isPlayer())
		return;

	Player* player = (Player*) obj;

	/*AttributeListMessage* alm = new AttributeListMessage(_this);

	addAttributes(alm);

	player->sendMessage(alm);*/

	sendIngredientsToPlayer(player);
	sendExperimentalPropertiesToPlayer(player);
}

void DraftSchematicImplementation::addAttributes(AttributeListMessage* alm) {

}

void DraftSchematicImplementation::parseItemAttributes() {

}
void DraftSchematicImplementation::synchronizedUIListen(Player* player, int value) {
	ManagedReference<CraftingTool> tool = player->getActiveCraftingTool();

	if (tool == NULL)
		return;

	ManagedReference<TangibleObject> workingTano = tool->getWorkingTano();

	if (workingTano == NULL)
		return;

	ManufactureSchematicObjectMessage7 * msco7 = new ManufactureSchematicObjectMessage7(_this);
	player->sendMessage(msco7);

	// Object Controller w/ Ingredients ***************************
	ObjectControllerMessage* objMsg =
			new ObjectControllerMessage(player->getObjectID(), 0x0B, 0x0103);
	objMsg->insertLong(tool->getObjectID()); // Crafting Tool Object ID
	objMsg->insertLong(objectID);// Draft Schematic Object ID
	//objMsg->insertInt(schematicID);
	//objMsg->insertInt(objectCRC);
	objMsg->insertLong(workingTano->getObjectID()); // Crafting Tangible Object ID
	objMsg->insertInt(2);
	objMsg->insertByte(1);

	// Sends requested ingredients to the player
	helperSendIngredientsToPlayer(objMsg);

	player->sendMessage(objMsg);
	// End Object Controller w/ Ingredients ************************
}

void DraftSchematicImplementation::synchronizedUIStopListen(Player* player, int value) {

}
// Ingredient Methods
void DraftSchematicImplementation::addIngredient(const String& ingredientTemplateName, const String& ingredientTitleName,
		const int slotoption, const String& resourceType, uint32 resourceQuantity, uint32 combineType, uint32 contribution) {

	float contrib = float(contribution) / 100;

	DraftSchematicIngredient* ingredient = new DraftSchematicIngredient(ingredientTemplateName,
			ingredientTitleName, slotoption, resourceType, resourceQuantity, combineType, contrib);

	dsIngredients.add(ingredient);
}

void DraftSchematicImplementation::sendIngredientsToPlayer(Player* player) {
	ObjectControllerMessage* msg = new ObjectControllerMessage(player->getObjectID(), 0x0B, 0x01BF);

	//msg->insertLong(objectID);

	msg->insertInt(schematicID);
	msg->insertInt(objectCRC);

	msg->insertInt(complexity); // ex: 3
	msg->insertInt(schematicSize); // ex: 1
	msg->insertByte(2);

	helperSendIngredientsToPlayer(msg);

	player->sendMessage(msg);
}

void DraftSchematicImplementation::helperSendIngredientsToPlayer(ObjectControllerMessage* objMsg) {
	int listSize = dsIngredients.size();
	objMsg->insertInt(listSize);

	// Send all the ingredient data
	for (int i = 0; i < listSize; i++) {
		DraftSchematicIngredient* dsi = dsIngredients.get(i);
		dsi->helperSendToPlayer(objMsg);
	}

	/* for debugging
		 StringBuffer ss;
		 ss << msg->toString();
		 player->info(ss.toString());*/

	objMsg->insertShort(0);
}

// Experimental Property Methods
// UPDATE THIS METHOD WHEN WE CAN PASS VECTORS AROUND IN IDL
void DraftSchematicImplementation::addExperimentalProperty(uint32 groupNumber, String experimentalProperty,
		uint32 weight, String title, String subtitle, float min, float max, int precision) {
	if (groupNumber < dsExpPropGroups.size()) {
		dsExpPropGroups.get(groupNumber)->addExperimentalProperty(experimentalProperty,	weight, min, max, precision);
	} else {
		DraftSchematicExpPropGroup* dsEpg = new DraftSchematicExpPropGroup(title, subtitle);
		dsEpg->addExperimentalProperty(experimentalProperty, weight, min, max, precision);

		dsExpPropGroups.add(dsEpg);
	}
}

void DraftSchematicImplementation::sendExperimentalPropertiesToPlayer(Player* player) {
	ObjectControllerMessage* msg = new ObjectControllerMessage(player->getObjectID(), 0x1B, 0x0207);

	//msg->insertLong(objectID);
	msg->insertInt(schematicID);
	msg->insertInt(objectCRC);

	uint8 listSize = dsExpPropGroups.size();

	msg->insertByte(listSize);
	// Send all the resource batch property data
	for (int i = 0; i < listSize; i++) {

		DraftSchematicExpPropGroup* dsEpg = dsExpPropGroups.get(i);
		dsEpg->sendBatchToPlayer(msg);
	}

	msg->insertByte(listSize);
	// Send all the experimental property data
	for (int i = 0; i < listSize; i++) {

		DraftSchematicExpPropGroup* dsEpg = dsExpPropGroups.get(i);
		dsEpg->sendToPlayer(msg);
	}
	player->sendMessage(msg);
}


int DraftSchematicImplementation::getRequiredIngredientCount() {
	DraftSchematicIngredient* dsi;
	int count = 0;

	for (int i = 0; i < dsIngredients.size(); i++) {
		dsi = dsIngredients.get(i);

		if (!dsi->isOptionalSlot())
			count++;
	}

	return count;
}

void DraftSchematicImplementation::toString() {
	System::out << "Name: " << customName.toString();
	System::out << "\nSchematicID: " << schematicID;
	System::out << "\nobjectID: " << objectID;
	System::out << "\nschematicCRC: " << objectCRC;
	System::out << "\ngroupName: " << groupName;
	System::out << "\ncomplexity: " << complexity;
	System::out << "\nschematicSize: " << schematicSize;
	System::out << "\ncraftingToolTab: " << craftingToolTab;

	System::out << "\nxpType: " << xpType;
	System::out << "\nxp: " << xp;
	System::out << "\ntanoAttributes: " << tanoAttributes;

	System::out << "\nAssembly Skill: " << assemblySkill;
	System::out << "\nExperimenting Skill: " << experimentingSkill;

	DraftSchematicIngredient* ingredient;
	for (int i = 0;i < dsIngredients.size(); ++i) {
		ingredient = dsIngredients.get(i);

		System::out << "\n*************************" << endl;
		System::out << "Ingredient " << i << endl;
		System::out << "Title: " << ingredient->getTitleName() << endl;
		System::out << "Resource Type: " << ingredient->getResourceType() << endl;
		System::out << "Template Name: " << ingredient->getTemplateName() << endl;
		System::out << "Quantity: " << ingredient->getResourceQuantity() << endl;
		System::out << "Slot Type: " << ingredient->getSlotType() << endl;
		System::out << "**************************" << endl;
	}

	DraftSchematicExpPropGroup* tempGroup;
	for (int i = 0;i < dsExpPropGroups.size(); ++i) {
		tempGroup = dsExpPropGroups.get(i);

		System::out << "\n*************************" << endl;
		System::out << "Exp Property " << i << endl;
		System::out << "Type and Weight: " << tempGroup->getTypeAndWeight(i) << endl;
		System::out << "Percentage: " << tempGroup->getExpPropPercentage(i) << endl;
		System::out << "**************************" << endl;
	}

	/*DraftSchematicAttribute* tempAttribute;
	for (int i = 0;i < attributesToSet.size(); ++i) {
		tempAttribute = attributesToSet.get(i);

		System::out << "\n*************************" << endl;
		System::out << "Attribute " << i << endl;
		System::out << "Name: " << tempAttribute->getAttributeName() << endl;
		System::out << "Property: " << tempAttribute->getAttributeExperimentalProperty() << endl;
		System::out << "Min: " << tempAttribute->getMinValue() << endl;
		System::out << "Max: " << tempAttribute->getMaxValue() << endl;
		System::out << "Range: " << tempAttribute->getRange() << endl;
		System::out << "**************************" << endl;
	}

	float tempProperty;
	for (int i = 0;i < experimentalProperties.size(); ++i) {
		tempProperty = experimentalProperties.get(i);

		System::out << "*************************" << endl;
		System::out << "Prop " << i << endl;
		System::out << "Prop: " << tempProperty << endl;
		System::out << "**************************" << endl;
	}*/

	craftingValues->toString();
}
