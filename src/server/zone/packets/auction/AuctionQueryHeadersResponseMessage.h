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

#ifndef AUCTIONQUERYHEADERSRESPONSEMESSAGE_H_
#define AUCTIONQUERYHEADERSRESPONSEMESSAGE_H_

#include "engine/engine.h"

#include "../../objects/auction/AuctionItem.h"
#include "../../objects/auction/AuctionItemImplementation.h"

class AuctionQueryHeadersResponseMessage : public BaseMessage {

	Vector<AuctionItem*> itemList;

	Vector<String> locationList;

public:
	AuctionQueryHeadersResponseMessage(int screen, int counter) : BaseMessage() {
		insertShort(0x08);
		insertInt(0xFA500E52);  // opcode

		insertInt(counter);
		insertInt(screen); // Vendor screen number
	}

	void addItemToList(AuctionItem* ai) {
		try {
			ai->wlock();

			//ai->setLocationPointer(-1);
			int pointer = -1;

			for (int i = 0; i < locationList.size(); i++) {
				if (locationList.get(i) == ai->getTerminalTitle()) {
					pointer = i;
					ai->setLocationPointer(i);
				}
			}

			if (pointer == -1) {
				ai->setLocationPointer(locationList.size());
				locationList.add(locationList.size(), ai->getTerminalTitle());
			}

			pointer = -1;

			for (int i = 0; i < locationList.size(); i++) {
				if (locationList.get(i) == ai->getOwnerName()){
					pointer = i;
					ai->setOwnerPointer(i);
				}
			}

			if (pointer == -1) {
				ai->setOwnerPointer(locationList.size());
				locationList.add(locationList.size(), ai->getOwnerName());
			}

			ai->unlock();

		} catch (...) {
			ai->unlock();
		}

		itemList.add(ai);
	}

	void dumpLocationList() {
		int llSize = locationList.size();

		insertInt(llSize);

		for (int i = 0; i < locationList.size(); i++) {
			insertAscii(locationList.get(i));
		}
	}

	void dumpItemNameList() {
		int ilSize = itemList.size();

		insertInt(ilSize);

		for (int i = 0; i < itemList.size(); i++) {
			AuctionItem* il = itemList.get(i);

	    	UnicodeString name = il->getItemName();
	    	insertUnicode(name); //name
		}
	}

	void dumpItemInfoList() {
		int ilSize = itemList.size();

		insertInt(ilSize);

		for (int i = 0; i < itemList.size(); i++) {
			AuctionItem* il = itemList.get(i);

			insertLong(il->getID()); //item id
			insertByte(i);  // List item String number

			insertInt(il->getPrice()); //item cost.

			Time expireTime;
			uint32 expire = il->getExpireTime() - expireTime.getMiliTime() / 1000;

			insertInt(expire);

	    	if (il->getAuction())
	    		insertByte(0);
	    	else
	    		insertByte(1);

	    	insertShort(il->getLocationPointer());

	    	insertLong(il->getOwnerID()); // seller ID
	    	insertShort(il->getOwnerPointer());

	    	insertLong(il->getBuyerID()); // buyer ID

	    	insertShort(0);
	    	insertInt(il->getPrice()); // my proxy not implemented yet
	    	insertInt(il->getPrice()); // my bid default to price

	    	insertInt(il->getItemType());

	    	insertInt(10);
	    	insertInt(20);  // Vendor entrance fee
		}
	}

	void createMessage(int offset = 0, bool continues = false) {
		dumpLocationList();

		dumpItemNameList();

		dumpItemInfoList();

		insertShort(offset); // Item list start offset

		insertByte(continues); // more to come?
	}

	inline int getListSize() {
		return itemList.size();
	}

};

#endif /*AUCTIONQUERYHEADERSRESPONSEMESSAGE_H_*/
