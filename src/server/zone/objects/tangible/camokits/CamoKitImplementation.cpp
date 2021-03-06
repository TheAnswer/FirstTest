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

#include "../../../managers/item/ItemManager.h"

#include "../TangibleObject.h"

#include "engine/engine.h"

#include "CamoKitImplementation.h"

#include "../../../packets.h"

CamoKitImplementation::CamoKitImplementation(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn)
	: CamoKitServant(oid, CAMOKIT) {
	objectCRC = tempCRC;

	stfFile = "obj_n";
	stfName = tempn;

	customName = n;

	setUsesRemaining(5);
	setEquipped(false);

	init();
}

CamoKitImplementation::CamoKitImplementation(Player* player, unsigned int tempCRC, const UnicodeString& n, const String& tempn)
	: CamoKitServant(player->getNewItemID(), CAMOKIT) {
	objectCRC = tempCRC;

	stfFile = "obj_n";
	stfName = tempn;

	customName = n;

	usesRemaining = 5;

	init();

	setParent((TangibleObject*) player->getInventory(), 0xFFFFFFFF);

	setEquipped(false);
}

void CamoKitImplementation::init() {
	switch(objectCRC) {
		case 0x82EDE91E:
			setPlanet(0);
			setConcealMin(40);
			break;
		case 0x3EDB35EE:
			setPlanet(1);
			setConcealMin(80);
			break;
		case 0x16346E3E:
			setPlanet(2);
			setConcealMin(100);
			break;
		case 0x833521B4:
			setPlanet(3);
			setConcealMin(80);
			break;
		case 0xE9A14DB2:
			setPlanet(4);
			setConcealMin(80);
			break;
		case 0x416F97B6:
			setPlanet(5);
			setConcealMin(40);
			break;
		case 0xAAF7CBB0:
			setPlanet(6);
			setConcealMin(40);
			break;
		case 0x583DE19C:
			setPlanet(7);
			setConcealMin(40);
			break;
		case 0xBEAE8881:
			setPlanet(8);
			setConcealMin(40);
			break;
		case 0x42B8E295:
			setPlanet(9);
			setConcealMin(80);
			break;
	}
}

void CamoKitImplementation::updateCraftingValues(DraftSchematic* draftSchematic) {
	// Incoming values available
	//
	// unitIntegrity (Range: 1000 - 1000)
	// quantity      (Range: 5 - 20)
	//***********************************

	DraftSchematicValues* craftingValues = draftSchematic->getCraftingValues();

	usesRemaining = (int)craftingValues->getCurrentValue("quantity");
	String attr = "uses";
	itemAttributes->setIntAttribute(attr, usesRemaining);

}

void CamoKitImplementation::useCharge(Player* player) {
	if (usesRemaining <= 0) {
		remove(player);
		return;
	}

	setUsesRemaining(getUsesRemaining() - 1);
	updated = true;

	if (usesRemaining == 0)
		remove(player);
}

int CamoKitImplementation::getPlanet() {
	return planet;
}

int CamoKitImplementation::getUsesRemaining() {
	return usesRemaining;
}

int CamoKitImplementation::getConcealMin() {
	return concealMin;
}


void CamoKitImplementation::setPlanet(const int tp) {
	planet = tp;
	String attr = "planetType";
	itemAttributes->setIntAttribute(attr, planet);
}

void CamoKitImplementation::setUsesRemaining(const int us) {
	usesRemaining = us;
	String attr = "uses";
	itemAttributes->setIntAttribute(attr, usesRemaining);
}

void CamoKitImplementation::setConcealMin(const int min) {
	concealMin = min;
	String attr = "concealMin";
	itemAttributes->setIntAttribute(attr, concealMin);
}

void CamoKitImplementation::remove(Player* player) {
	ItemManager* itemManager = player->getZone()->getZoneServer()->getItemManager();

	itemManager->deletePlayerItem(player, _this, false);

	player->removeInventoryItem(objectID);

	BaseMessage* msg = new SceneObjectDestroyMessage(objectID);
	player->sendMessage(msg);
}

void CamoKitImplementation::sendDeltas(Player* player) {
	TangibleObjectDeltaMessage3 * dtano3 = new TangibleObjectDeltaMessage3((TangibleObject*)_this);
	dtano3->addIntUpdate(7, (getUsesRemaining() == 1) ? 0 : getUsesRemaining()); //Update the number of charges on the pack in inventory.
	dtano3->close();
	player->sendMessage(dtano3);
}

void CamoKitImplementation::addHeaderAttributes(AttributeListMessage* alm) {
	alm->insertAttribute("volume", "1");
	alm->insertAttribute("counter_uses_remaining", getUsesRemaining());

	if(craftersName != ""){
		alm->insertAttribute("crafter", craftersName);
	}

	if(craftedSerial != ""){
		alm->insertAttribute("serial_number", craftedSerial);
	}
}

void CamoKitImplementation::addFooterAttributes(AttributeListMessage* alm) {
	//alm->insertAttribute("healing_ability", getPlanet());
}

void CamoKitImplementation::addAttributes(AttributeListMessage* alm) {
	addHeaderAttributes(alm);
	addFooterAttributes(alm);
}

void CamoKitImplementation::generateAttributes(SceneObject* obj) {
	if (!obj->isPlayer())
		return;

	Player* player = (Player*) obj;
	AttributeListMessage* alm = new AttributeListMessage((TangibleObject*) _this);

	addAttributes(alm);

	player->sendMessage(alm);
}

void CamoKitImplementation::parseItemAttributes() {
	String attr = "uses";
	setUsesRemaining(itemAttributes->getIntAttribute(attr));
	attr = "planetType";
	setPlanet(itemAttributes->getIntAttribute(attr));
	attr = "concealMin";
	setConcealMin(itemAttributes->getIntAttribute(attr));
}
