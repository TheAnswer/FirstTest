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

#ifndef GUILDOBJECTMESSAGE3_H_
#define GUILDOBJECTMESSAGE3_H_

#include "../BaseLineMessage.h"

class GuildObjectMessage3 : public BaseLineMessage {
public:
	GuildObjectMessage3(uint64 goId)
			: BaseLineMessage(goId, 0x47494C44, 3, 0x05) {
		insertFloat(1);

		insertAscii("String_id_table");
		insertLong(0);
		insertInt(0);
		insertShort(0);
		
		insertInt(0);
		insertInt(0);
	}
	
	void addListSize(int lstSz) {
		insertInt(lstSz);
		insertInt(lstSz);
	}
	
	void addListSize(int off, int lstSz) { //insert the list size at an offset
		insertInt(off, lstSz);
		insertInt(off + 4, lstSz);
	}
	
	void addListMember(int guildId, String name) {
		char idStr[32];
		sprintf(idStr, "%d", guildId);
		
		StringBuffer guildStr;
		guildStr << idStr << ":" << name;

		insertAscii(guildStr.toString());
	}
	
	void finishGild() { //i think setSize isn't public so we need to call this after building the packet
		setSize();
	}
	
};
#endif /*GUILDOBJECTMESSAGE3_H_*/
