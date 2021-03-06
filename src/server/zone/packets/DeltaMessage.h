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

#ifndef DELTAMESSAGE_H_
#define DELTAMESSAGE_H_

#include "engine/engine.h"

class DeltaMessage : public BaseMessage {
	int updateCount;
	
public:
	DeltaMessage(uint64 oid, uint32 name, uint8 type) {
		insertShort(0x05);
		insertInt(0x12862153);
		insertLong(oid);
		insertInt(name);
		//insertInt(generateRandomObjectCRC());
		insertByte(type);
		insertInt(0);
	
		updateCount = 0;
		insertShort(updateCount);
	}

	uint32 generateRandomObjectCRC() {
		int idx = System::random(4);
		
		if (idx == 0)
			return 0x4352454F;  // CREO;
		else if (idx == 1)
			return 0x504C4159;  // PLAY 
		else if (idx == 2)
			return 0x54414E4F;  // TANO 
		else 
			return System::random(0xFFFFFFFF); 
	};

	inline void startUpdate(uint16 type) {
		++updateCount;
		insertShort(type);
	}

	inline void addByteUpdate(uint16 type, uint8 value) {
		startUpdate(type);
		insertByte(value);
	}

	inline void addShortUpdate(uint16 type, uint16 value) {
		startUpdate(type);
		insertShort(value);
	}

	inline void addIntUpdate(uint16 type, uint32 value) {
		startUpdate(type);
		insertInt(value);
	}

	inline void addLongUpdate(uint16 type, uint64 value) {
		startUpdate(type);
		insertLong(value);
	}

	inline void addFloatUpdate(uint16 type, float value) {
		startUpdate(type);
		insertFloat(value);
	}
	
	inline void addAsciiUpdate(uint16 type, const String& val) {
		startUpdate(type);
		insertAscii(val.toCharArray());
	}
	
	inline void addUnicodeUpdate(uint16 type, const String& val) {
		startUpdate(type);
		UnicodeString v = UnicodeString(val);
		insertUnicode(v);
	}

	inline void startList(uint32 cnt, uint32 updcnt) {
		insertInt(cnt);

		//updcnt += cnt;
		insertInt(updcnt);
	}

	inline void addListIntElement(uint16 index, uint32 value) {
		insertByte(0x01);
		insertShort(index);
		insertInt(value);
	}
	
	inline void addListFloatElement(uint16 index, float value) {
		insertByte(0x01);
		insertShort(index);
		insertFloat(value);
	}

	inline void addListLongElement(uint16 index, uint64 value) {
		insertByte(0x01);
		insertShort(index);
		insertLong(value);
	}

	inline void addListAsciiElement(const String& value) {
		insertByte(0x00);
		insertAscii(value.toCharArray());
	}

	inline void removeListIntElement(uint16 index, uint32 value) {
		insertByte(0x02);
		insertShort(index);
		insertInt(value);
	}
	
	inline void removeListFloatElement(uint16 index, float value) {
		insertByte(0x02);
		insertShort(index);
		insertFloat(value);
	}

	inline void removeListLongElement(uint16 index, uint64 value) {
		insertByte(0x02);
		insertShort(index);
		insertLong(value);
	}

	inline void removeListLongElement(uint16 index) {
		insertByte(0x03);
		insertShort(index);
	}

	inline void removeListAsciiElement(const String& value) {
		insertByte(0x01);
		insertAscii(value.toCharArray());
	}

	inline void close() {
		insertInt(23, size() - 27);
		insertShort(27, updateCount);
	}
	
};

#endif /*DELTAMESSAGE_H_*/
