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

#ifndef CONCEALSKILL_H_
#define CONCEALSKILL_H_

#include "../CamoSkill.h"
#include "../../../tangible/camokits/CamoKit.h"

#include "../../../../managers/player/PlayerManager.h"
#include "../../../player/Player.h"

class ConcealSkill : public CamoSkill {

public:
	/*
	 * The constructor. Camo Type is set to NONE.
	 * \param name The skill name
	 * \param serv The ZoneProcessServerImplementation.
	 */
	ConcealSkill(const String& name, ZoneProcessServerImplementation* serv) : CamoSkill(name, SELF, serv) {
		setDuration(0);
		setCamoType(NONE);
	}


	/*
	 * Activates the target skill (conceal).
	 * \param creature The creature, that activates the skill.
	 * \param target The target to conceal, if null the self.
	 * \param modifier The modifiers, not used.
	 */
	void doSkill(CreatureObject* creature,SceneObject* target, String& modifier) {
		Player* player = (Player*) creature;

		if(player == NULL)
			return;

		CamoKit* camoKit = findCamopack(creature);

		if (camoKit == NULL) {
			player->sendSystemMessage("skl_use", "sys_conceal_nokit");
			return;
		}

		int camoMod = creature->getSkillMod("camouflage") +  creature->getSkillModBonus("camouflage");

		if (camoMod < camoKit->getConcealMin()) {
			player->sendSystemMessage("skl_use", "sys_conceal_noskill");
			return;
		}

		if (target != NULL) {
			if(!target->isPlayer()) {
				player->sendSystemMessage("skl_use", "sys_conceal_notplayer");
				return;
			}
			Player* tar = (Player*) target;

			if (!isUseful(tar)) {
				return;
			}

			if (!calculateCost(tar)) {
				return;
			}

			if (creature-> isPlayer()) {
				camoKit->useCharge((Player*) creature);
			} else
				return;

			tar->setCamoType(camoKit->getPlanet());
			tar->activateCamo(getNameCRC(),(int)getDuration(),camoMod);
			tar->setCamoXPTraget(player);

			StfParameter* params = new StfParameter();
			params->addTT(tar->getCharacterName());

			player->sendSystemMessage("skl_use", "sys_conceal_apply", params);
			delete params;
		} else {
			if (!isUseful(creature)) {
				return;
			}

			if (creature-> isPlayer()) {
				camoKit->useCharge((Player*) creature);
			} else
				return;

			creature->setCamoType(camoKit->getPlanet());
			creature->activateCamo(getNameCRC(),(int)getDuration(),camoMod);
		}
	}

	/*
	 * Does the animation.
	 * \param creature The creature The creature, that activates the skill.
	 */
	void doAnimations(CreatureObject* creature) {
	}

	/*
	 * Deactivates the conceal skill.
	 * \param creature The creature, that is unconcealed.
	 */
	void finish(CreatureObject* creature) {
		creature->deactivateCamo(false);
	}

	/*
	 * Returns the speed of the skill.
	 * \return creature The creature The creature, that activates the skill.
	 */
	float calculateSpeed(CreatureObject* creature) {
			return 0;
	}

	/*
	 * Checks if the skill can be used
	 * \param creature The creature, that is checked.
	 * \return Returns false if not usefull else true.
	 */
	bool isUseful(CreatureObject* creature) {

		Player* player = (Player*) creature;

		if(player == NULL)
			return false;

		//if (creature->isInCombat() || creature->hasQueuedState(getNameCRC()) || creature->isMeditating()) {

		if (creature->getCamoType() < 10) {
			player->sendSystemMessage("skl_use", "sys_target_concealed");
			return false;
		}

		if (creature->isInCombat() || creature->isMeditating()) {
			player->sendSystemMessage("skl_use", "sys_conceal_cant");
			return false;
		}

		if (creature->getCamoType() == 10) {
			player->sendSystemMessage("skl_use", "sys_conceal_scentmasked");
			return false;
		}

		if(!creature->isCamoCooldownActive()) {

			int left = creature->getCamoCooldownLeft() / 1000;
			int seconds = left % 60;

			StfParameter* params = new StfParameter();
			params->addDI(seconds);

			player->sendSystemMessage("skl_use", "sys_conceal_delay", params);
			delete params;

			return false;
		}

		return true;
	}

	/**
	 * 	This finds a usable camo kit ,that is usable on the current planet, in the inventory.
	 *  \param creature The creature in whichs inventory the kit is searched.
	 *  \return Returns the camo kit or NULL if no usable kit is found.
	 */
	CamoKit* findCamopack(CreatureObject* creature) {
		CamoKit* camoKit= NULL;


		Inventory* inventory = creature->getInventory();

		for (int i=0; i< inventory->getContainerObjectsSize(); i++) {
			TangibleObject* item = (TangibleObject*) inventory->getObject(i);

			if (item != NULL && item->isCamoKit()) {
				camoKit = (CamoKit*) item;

				if (creature->getZoneID() == camoKit->getPlanet())
					return camoKit;
			}
		}

		return NULL; //Never found a usable kit
	}

	/*
	 * Calculates the costs of the skill.
	 * \param creature The creature, that is checked.
	 * \return Returns if costs are applied.
	 */
	virtual bool calculateCost(CreatureObject* creature) {
		/*if (!creature->isPlayer())
			return true;

		Player* player = (Player*) creature;

		int wpnHealth = 100;
		int wpnAction = 200;
		int wpnMind = 100;

		int healthAttackCost = wpnHealth - (wpnHealth * creature->getStrength()
				/ 1500);
		int actionAttackCost = wpnAction - (wpnAction
				* creature->getQuickness() / 1500);
		int mindAttackCost = wpnMind - (wpnMind * creature->getFocus() / 1500);

		if (healthAttackCost < 0)
			healthAttackCost = 0;

		if (actionAttackCost < 0)
			actionAttackCost = 0;

		if (mindAttackCost < 0)
			mindAttackCost = 0;

		if (!player->changeHAMBars(-healthAttackCost, -actionAttackCost,
				-mindAttackCost))
			return false;
		 */
		return true;
	}

};

#endif
