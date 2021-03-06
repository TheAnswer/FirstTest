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

#include "SuiResourceBoxImplementation.h"
#include "../SuiWindowType.h"

SuiResourceBoxImplementation::SuiResourceBoxImplementation(Player* player, ResourceManager* resourcemanager) :
		SuiResourceBoxServant(player, SuiWindowType::FREE_RESOURCE) {
	resourceManager = resourcemanager;

	boxType = RESOURCEBOX;
}

SuiResourceBoxImplementation::~SuiResourceBoxImplementation() {
}

void SuiResourceBoxImplementation::nextStage() {

}

void SuiResourceBoxImplementation::previousStage() {

}

void SuiResourceBoxImplementation::onSelect(uint32 menuchoice) {
	System::out << "Menu choice " << menuchoice << " was selected." << endl;
}


BaseMessage* SuiResourceBoxImplementation::generateMessage() {
	SuiCreatePageMessage* message = new SuiCreatePageMessage(boxID, "Script.listBox");

	//Declare Headers:
	addHeader("List.lstList", "SelectedRow");
	addHeader("bg.caption.lblTitle", "Text");

	//Set Body Options:
	addSetting("3", "bg.caption.lblTitle", "Text", "@veteran:resource_title");
	addSetting("3", "Prompt.lblPrompt", "Text", promptText);
	addSetting("3", "btnOther", "Text", "@revert");
	addSetting("3", "btnOther", "Enabled", "true");
	addSetting("3", "btnOther", "Visible", "true");
	//addSetting("3", "btnCancel", "Text", "@cancel");
	addSetting("3", "btnOk", "Text", "@ok");

	//Data Container Option
	addSetting("1", "List.dataList", "", "");

	for (int i = 0; i < getMenuSize(); i++) {
		addSetting("4", "List.dataList", "Name", String::valueOf(i));
		addSetting("3", "List.dataList." + i, "Text", menuItems.get(i)->getOptionName());
	}

	/*
	//Fill the above Data Container
	String tempVal = "";
	for (int i = 0; i < getMenuSize(); i++) {
		char tempStr[30];
		sprintf(tempStr, "%d", i);

		addSetting("4", "List.dataList", "Name", String::valueOf(i));

		sprintf(tempStr, "List.dataList.%d", i);

		tempVal = menuItems.get(i)->getOptionName();

		addSetting("3", tempStr, "Text", tempVal);
	}*/

	//Generate Packet:
	/*
	switch(type) {
	case HANDLESTATUSUI:
		generateHeader(message, "handleStatusUi");
		break;
	case HANDLEDESTROYUI:
		generateHeader(message, "handleDestroyUi");
		break;
	default:
		generateHeader(message, "msgSelected");
	}*/

	generateHeader(message, "msgSelected");
	generateBody(message);
	generateFooter(message);
	hasGenerated = true;

	return message;
}
