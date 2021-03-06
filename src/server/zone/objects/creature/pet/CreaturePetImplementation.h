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

#ifndef CREATUREPETIMPLEMENTATION_H_
#define CREATUREPETIMPLEMENTATION_H_

#include "engine/engine.h"

#include "CreaturePet.h"
#include "../../scene/ItemAttributes.h"
#include "../../../packets/scene/AttributeListMessage.h"
#include "PetCommandHelper.h"
#include "../mount/VehicleObject.h"
#include "PetFriendSet.h"

class Player;

class CreatureObject;

class Creature;

class CreatureManagerImplementation;

class VehicleObject;

class CreaturePetImplementation : public CreaturePetServant ,public VehicleObject {
	uint8 petType;
	uint8 commandState;
	int commandToTrain;
	int trainingPhase;
	int trainingPhaseCounter;

	PetCommandHelper* commandHelper;

	Time lastGrowth;
	float growth;

	uint32 maxLevel;

	int nextAttack;

	PetFriendSet* befriendList;
	Player* followTarget;

	Coordinate* nextMovementPosition;
	uint8 positionNumber;
	uint8 formation;

	uint64 attackGrowth;
	//Vector<Coordinate*> patrolPoints;
	//uint8 nextPatrolPoint;

	static const bool debug = true;
public:
	static const uint8 CHPET = 0x10;
	static const uint8 CHPETUNTRAINEDMOUNT = 0x11;
	static const uint8 CHPETTRAINEDMOUNT = 0x12;
	static const uint8 DROID = 0x20;
	static const uint8 DROIDCOMBAT = 0x21;
	static const uint8 FACTIONPET = 0x30;
	static const uint8 FACTIONPETREBEL = 0x31;
	static const uint8 FACTIONPETIMPERIAL = 0x32;

	static const uint8 STATEFOLLOW = 1;
	static const uint8 STATEGUARD = 2;
	static const uint8 STATESTAY = 3;
	static const uint8 STATEPATROL = 4;
	static const uint8 STATEFOLLOWOTHER = 5;

	static const uint8 FORMATIONNONE = 0;
	static const uint8 FORMATIONWEDGE = 1;
	static const uint8 FORMATIONCOLUM = 2;

public:

	/*
	 * Constructor.
	 */
	CreaturePetImplementation(Player* owner, uint64 oid);

	/*
	 * Destructor.
	 */
	~CreaturePetImplementation();

	// pet creation
	void init();

	/*
	 * Initializes the pets stats with the creatuers stats.
	 * \param creature - the creature with the stats
	 */
	void init(Creature* creature, float growth = 0.5f);

	/*
	 * Creates the datapad item in the pet owners datapad.
	 */
	void createDataPad(uint32 datapadCRC);

	//pet store/load

	/*
	 * Creates the pets attribute list for the db.
	 */
	void createItemAttributes();

	/*
	 * Parses the attribute list.
	 */
	void parseItemAttributes();

	void loadItems();

	/*
	 * Send the radial options..
	 * \param player - the player that requested the radial.
	 * \param omr - the radial response mendu.
	 */
	void sendRadialResponseTo(Player* player, ObjectMenuResponse* omr);
	void sendTo(Player* player, bool doClose = true);

	void addAttributes(AttributeListMessage* alm);

	// pet managment

	/*
	 * Calls the pet from the datapad.
	 */
	void call();

	/*
	 * Stores the pad to the datapad.
	 */
	void store(bool doLock = true);

	/*
	 * Checks if the owner can call the pet
	 * \return can the pet be called ?
	 */
	bool canCall();

	// basic methods
	bool isAttackable();
	bool isAttackableBy(CreatureObject* creature);
	void onIncapacitated(SceneObject* attacker);

	/**
	 * Action performed to recover from incapacitation.
	 */
	void recoverFromIncapacitation();

	void setFaction(uint32 fac);

	bool isFriend(CreatureObject* creo) {
		for (int i = 0 ; i < befriendList->size() ; i++) {
			if (!creo->isPlayer())
				continue;
			Player* petFriend = befriendList->get(i);
			if (petFriend == creo)
				return true;
		}

		return false;
	}

	inline void setMaxLevel(uint32 level) {
		maxLevel = level;
		setLevel((uint32) ((float)maxLevel * growth));
		String attr = "maxLevel";
		itemAttributes->setIntAttribute(attr, maxLevel);
	}

	inline void setPetType(uint8 type) {
		petType = type;
		String attr = "petType";
		itemAttributes->setIntAttribute(attr,petType);
	}

	inline void setGrowth(float gr) {
		growth = gr;
		String attr = "growth";
		itemAttributes->setFloatAttribute(attr,growth);
	}

	inline void setLastGrowth(uint32 stamp) {
		Time mStamp(stamp);
		lastGrowth = mStamp;
		String attr("lastGrowth");
		itemAttributes->setUnsignedLongAttribute(attr, stamp);
	}

	inline void setAttackGrowth(uint64 att) {
		attackGrowth = att;
		String attr("attackGrowth");
		itemAttributes->setUnsignedLongAttribute(attr, attackGrowth);
	}

	inline bool isCHPet() {
		return petType & CHPET;
	}

	bool isMountTrainable() {
		return (petType == CHPETUNTRAINEDMOUNT) && growth > 0.8f;
	}

	inline bool isMount() {
		return petType == CHPETTRAINEDMOUNT;
	}

	inline bool isDroid() {
		return petType & DROID;
	}

	inline bool isCombatDroid() {
		return petType & DROIDCOMBAT;
	}

	inline bool isFactionPet() {
		return petType & FACTIONPET;
	}

	inline bool isRebelFactionPet() {
		return petType & FACTIONPETREBEL;
	}

	inline bool isImperialFactionPet() {
		return petType & FACTIONPETIMPERIAL;
	}

	void doGrowUp(bool updateTime = true);

	// ai
	void initTrainingState(int command);
	void setPetName(String& name);
	void parseCommandMessage(Player* player, const UnicodeString& message);

	inline bool isInFollowState() {
		return commandState == STATEFOLLOW;
	}

	inline bool isInStayState() {
		return commandState == STATESTAY;
	}

	inline bool isInGuardState() {
		return commandState == STATEGUARD;
	}

	inline bool isInPatrolState() {
		return commandState == STATEPATROL;
	}

	inline bool isInTrainingState() {
		return commandToTrain != -1;
	}

	inline void setCommmandState(uint8 state) {
		commandState = state;
	}

	inline void setPositionNumber(uint8 posNumber) {
		positionNumber = posNumber;
	}

	inline uint8 getPositionNumber() {
		return positionNumber;
	}

	inline bool hasCommandTrained(int command) {
		return !commandHelper->getBaseCommand(command).isEmpty();
	}
	void notifyPositionUpdate(QuadTreeEntry* obj);
	bool activate();
	bool attack(CreatureObject* target);
	void deaggro();

	void handleAttackCommand(Player* player);
	void handleFollowCommand(Player* target);
	void handleStayCommand();
	void handleGuardCommand();
	void handleStoreCommand();
	void handleTransferCommand();
	void handleTrickCommand(String anim,int mod,int cost);
	void handleEnrageCommand();
	void handleEmboldenCommand();
	void handleSpecialAttackCommand(Player* player,int att);
	bool consumeOwnerHam(int h, int a, int m);
	void healPetMind(int mod);
	void handleGroupCommand(Player* player);
	void handleFriendCommand();
	void handleFormationCommand(uint8 form);
	void handleAddPatrolPointCommand(Player* player);
	void handleActivatePatrolCommand();
	void handleClearPatrolPointsCommand();

	void trainMount();

	Coordinate* calculateRelativePosition();
	void updateNextMovementPosition(Coordinate* nextPostition);

	inline Player* getFollowTarget() {
		return followTarget;
	}
};

#endif /* CREATUREPETIMPLEMENTATION_H_ */
