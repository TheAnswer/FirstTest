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

#ifndef THROWDIRECTPOOLATTACKTARGETSKILL_H_
#define THROWDIRECTPOOLATTACKTARGETSKILL_H_

#include "ThrowAttackTargetSkill.h"
#include "../../../../tangible/weapons/ThrowableWeapon.h"
#include "../../../../tangible/weapons/throwable/TrapThrowableWeapon.h"

class ThrowDirectPoolAttackTargetSkill: public ThrowAttackTargetSkill {
public:
	/*
	 * The constructor.
	 * \param name The skill name.
	 * \param anim The animation.
	 * \param serv The ZoneProcessServerImplementation.
	 */
	ThrowDirectPoolAttackTargetSkill(const String& name, const String& anim,
			ZoneProcessServerImplementation* serv) : ThrowAttackTargetSkill(name, anim, THROW, serv) {
		healthPoolAttackChance = 0;
		strengthPoolAttackChance = 0;
		constitutionPoolAttackChance = 0;

		actionPoolAttackChance = 0;
		quicknessPoolAttackChance = 0;
		staminaPoolAttackChance = 0;

		mindPoolAttackChance = 0;
		focusPoolAttackChance = 0;
		willpowerPoolAttackChance = 0;

		type = THROW;
		damageRatio = 1.0;

		requiredWeaponType = 0xFF;

		range = 32.0f;

		missed = false;
		isDebuff = false;

		dotType = 0;

		snareStateChance = 0;
		rootStateChance = 0;

		meleeDefDebuff = 0;
		rangedDefDebuff = 0;
		stunDefDebuff = 0;
		intimidateDefDebuff = 0;

		debuffHitMessage = "";
		debuffStrFile = "";
		debuffMissMessage = "";
	}

	/*
	 * Activates the target skill (throw).
	 * \param creature The creature, that activates the skill.
	 * \param target The target.
	 * \param modifier The modifiers, contains the traps object id.
	 */
	int doSkill(CreatureObject* creature, SceneObject* target,
			const String& modifier, bool doAnimation) {
		TrapThrowableWeapon* trap = (TrapThrowableWeapon*) getThrowableWeapon(
				creature, modifier);

		if (trap == NULL)
			return 0;

		if (!target->isPlayer() && !target->isNonPlayerCreature())
			return 0;

		if (!creature->isPlayer())
			return 0;

		CreatureObject* targetCreature = (CreatureObject*) target;
		Player* player = (Player*) creature;

		/*if (!player->hasCooldownExpired(getSkillName())) {
			player->sendSystemMessage("trap/trap", "sys_not_ready");
			return 0;
		}*/

		if (!targetCreature->isCreature()) {
			player->sendSystemMessage("traps/traps", "sys_creatures_only");
			return 0;
		}

		player->addCooldown(getSkillName(),8000);

		int damage = calculateThrowItemDamage(creature, (TangibleObject*)target, ((Weapon*) trap));

		if (damage && targetCreature->hasAttackDelay())
			targetCreature->clearAttackDelay();

		if (damage > 0) {
			applyDot(creature,targetCreature, damage);
			String type = "trapping";

			int xp = 14 * targetCreature->getLevel() - 48;

			if (xp < 50)
				xp = 50;
			else if (xp > 600)
				xp = 600;

			player->addXp(type, xp, true);

		}

		return damage;
	}

	/*
	 * Calculates the damage of the trap. Calls getCombatManager::calculateTrapDamage.
	 * \param creature The creature, that throws the trap.
	 * \param target The target.
	 * \param weapon The trap.
	 * \return Returns Returns the damage.
	 */
	virtual int calculateThrowItemDamage(CreatureObject* creature, TangibleObject* target, Weapon* weapon) {
		return server->getCombatManager()->calculateThrowItemDamage(creature, target, this, false, false, weapon);
	}

	virtual bool isTrapSkill() {
		return true;
	}

	void doMiss(CreatureObject* creature, CreatureObject* target, int32 damage) {
		if (hasCbtSpamMiss())
			creature->sendCombatSpam(target, NULL, -(int32)damage, getCbtSpamMiss());

		target->showFlyText("trap/trap", "sys_miss", 0xFF, 0xFF, 0xFF);
		target->addDamage(creature,1);
	}

};

#endif /* THROWDIRECTPOOLATTACKTARGETSKILL_H_ */
