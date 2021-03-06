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

#ifndef TAMETARGETSKILL_H_
#define TAMETARGETSKILL_H_


#include "../../pet/CreaturePet.h"
#include "events/TameEvent.h"

class TameTargetSkill : public TargetSkill {

public:
	/*
	 * The constructor. Camo Type is set to NONE.
	 * \param name The skill name
	 * \param serv The ZoneProcessServerImplementation.
	 */
	TameTargetSkill(const String& name, ZoneProcessServerImplementation* serv) : TargetSkill(name, "", PETSKILL, serv) {
	}


	/*
	 * Activates the target skill (conceal).
	 * \param creature The creature, that activates the skill.
	 * \param target The target to conceal, if null the self.
	 * \param modifier The modifiers, not used.
	 */
	virtual int doSkill(CreatureObject* creature, SceneObject* target, const String& modifier, bool doAnimation = true) {
		if (!creature->isPlayer())
			return 0;

		Player* player = (Player*) creature;

		if(player == NULL) {
			player->sendSystemMessage("Failed to tame creature.");
			return 0;
		}

		if (!target->isNonPlayerCreature()) {
			player->sendSystemMessage("Failed to tame creature.");
			return 0;
		}

		Creature* targetCreature = (Creature*) target;

		if (targetCreature == NULL) {
			player->sendSystemMessage("Failed to tame creature.");
			return 0;
		}

		if (!targetCreature->isBaby()) {
			player->sendSystemMessage("Failed to tame creature.");
			return 0;
		}

		if (targetCreature->isInCombat()) {
			player->setTameing(false);
			player->sendSystemMessage("Failed to tame creature.");
			return 0;
		}

		if (targetCreature->isAggressiveBaby() && player->getSkillMod("tame_aggro") == 0) {
			player->sendSystemMessage("pet/pet_menu","sys_lack_skill");
			return 0;
		}

		if (targetCreature->getLevel() > player->getSkillMod("tame_level")) {
			player->sendSystemMessage("pet/pet_menu","sys_lack_skill");
			return 0;
		}

		if (!player->isInRange(targetCreature,10.0f)) {
			player->setTameing(false);
			player->sendSystemMessage("Failed to tame creature.");
			return 0;
		}

		int stage = 0;

		if (!modifier.isEmpty())
			stage = Integer::valueOf(modifier);
		if (!player->isTameing() && (0 != stage)) {
			player->sendSystemMessage("Failed to tame creature.");
			player->setTameing(false);
			return 0;
		}

		if (player->isTameing() && (0 == stage)) {
			player->setTameing(false);
			player->sendSystemMessage("You have to wait to tame another creature.");
			return 0;
		}

		tame(player,targetCreature,stage);
		return 0;

	}

	void tame(Player* player, Creature* creature, int stage) {
		if (player == NULL || creature == NULL)
			return;
		if (creature->isInCombat() || player->isInCombat() ||
				creature->isIncapacitated() || creature->isDead() ||
				player->isIncapacitated() || player->isDead()) {
			player->sendSystemMessage("Failed to tame creature.");
			player->setTameing(false);
			return;
		}

		player->setTameing(true);

		switch(stage) {
			case 0:
				if (!player->canStoreMorePets()) {
					player->sendSystemMessage("pet/pet_menu","sys_too_many_stored");
					return;
				}

				if (System::random(1) == 1)
					player->say("Good..er..boy?");
				else
					player->say("Don't be scared.");

			break;
			case 1:
				if (System::random(1) == 1)
					player->say("Steady");
				else
					player->say("Easy");
			break;
			case 2:
				player->say("Don't bite me.");
				bool notInRange = !player->isInRange(creature,10.0f);

				if (notInRange || (creature->isAggressiveBaby() && creature->getLevel() > System::random(player->getSkillMod("tame_aggro")))) {
					player->sendSystemMessage("Failed to tame Creature.");
					if (System::random(1) == 1) {
						creature->updateTarget(player);
						creature->setCombatState();
						player->setCombatState();
						creature->attack(player);
						creature->addPatrolPoint(player->getPositionX(),player->getPositionY(),false);
					}
					player->setTameing(false);
					return;
				}else if (notInRange || creature->getLevel() > System::random(player->getSkillMod("tame_non_aggro"))) {
					player->sendSystemMessage("Failed to tame creature.");
					if (System::random(4) == 1) {
						creature->updateTarget(player);
						creature->setCombatState();
						player->setCombatState();
						creature->attack(player);
						creature->addPatrolPoint(player->getPositionX(),player->getPositionY(),false);
					}
					player->setTameing(false);
					return;
				}
				CreaturePet* pet = new CreaturePet(player,player->getNewItemID());

				if (pet == NULL) {
					player->setTameing(false);
					return;
				}
				pet->init(creature,0.5f);
				creature->unload();
				/*try {
					player->wlock();
					pet->createDataPad();
					player->unlock();
				} catch(...) {
					System::out <<"tame lock\n";
					player->unlock();
				}*/
				String chType = "creaturehandler";
				player->addXp(chType, (200 + 10 * (pet->getLevel() - player->getLevel())), true);
				player->setTameing(false);

				return;

		}

		TameEvent* event = new TameEvent(player,creature,++stage);
		ZoneProcessServerImplementation* server = player->getZoneProcessServer();
		server->addEvent(event);

	}

	/*
	 * Does the animation.
	 * \param creature The creature The creature, that activates the skill.
	 */
	void doAnimations(CreatureObject* creature) {
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
		return true;
	}


	/*
	 * Calculates the costs of the skill.
	 * \param creature The creature, that is checked.
	 * \return Returns if costs are applied.
	 */
	virtual bool calculateCost(CreatureObject* creature) {
		return true;
	}

};

#endif
