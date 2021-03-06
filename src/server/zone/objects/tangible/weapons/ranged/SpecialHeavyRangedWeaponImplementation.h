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

#ifndef SPECIALHEAVYRANGEDWEAPONIMPLEMENTATION_H_
#define SPECIALHEAVYRANGEDWEAPONIMPLEMENTATION_H_

#include "SpecialHeavyRangedWeapon.h"

class SpecialHeavyRangedWeaponImplementation : public SpecialHeavyRangedWeaponServant {

public:
	SpecialHeavyRangedWeaponImplementation(uint64 objid, uint32 tempcrc, const UnicodeString& n, const String& tempn, bool eqp = false)
			: SpecialHeavyRangedWeaponServant(objid, tempcrc, n, tempn, SPECIALHEAVYWEAPON, eqp) {
		init();
	}

	SpecialHeavyRangedWeaponImplementation(CreatureObject* creature, const String& temp, const UnicodeString& n, const String& tempn, bool eqp = false)
			: SpecialHeavyRangedWeaponServant(creature, temp, n, tempn, SPECIALHEAVYWEAPON, eqp) {
		init();
	}

	void init() {
		objectSubType = TangibleObjectImplementation::SPECIALHEAVYWEAPON;
		setAttackSpeed(6.1f);

		setMinDamage(25);
		setMaxDamage(284);
		setWoundsRatio(36);

		setPointBlankAccuracy(10);
		setPointBlankRange(0);

		setIdealAccuracy(-65);
		setIdealRange(50);

		setMaxRangeAccuracy(-120);
		setMaxRange(64);

		setHealthAttackCost(64);
		setActionAttackCost(25);
		setMindAttackCost(35);

		switch(objectCRC) {
		case 0xC105AB54:
			setType(RIFLEFLAMETHROWER);
			setCategory(RANGED);
			setSpeedSkillMod("heavy_flame_thrower_speed");

			setDamageType(HEAT);
			setArmorPiercing(NONE);

			cert = "cert_rifle_flame_thrower";
			break;
		case 0x2A3988BD:
			setType(RIFLELIGHTNING);
			setCategory(RANGED);
			setSpeedSkillMod("heavy_rifle_lightning_speed");

			setDamageType(ELECTRICITY);
			setArmorPiercing(LIGHT);

			cert = "cert_rifle_lightning";
			break;
		case 0xC677369F:
			setType(RIFLEACIDBEAM);
			setCategory(RANGED);
			setSpeedSkillMod("heavy_rifle_acid_speed");

			setDamageType(ACID);
			setArmorPiercing(NONE);

			cert = "cert_rifle_acid_beam";
			break;
		}

		setXpType();
	}
};

#endif /*SPECIALHEAVYRANGEDWEAPONIMPLEMENTATION_H_*/
