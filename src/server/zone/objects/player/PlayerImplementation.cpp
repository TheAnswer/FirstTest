/*Copyright (C) 2007 <SWGEmu>

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

#include "../../ZoneClientSession.h"
#include "../../ZoneServer.h"

#include "../../objects.h"
#include "../../packets.h"

#include "../../managers/player/PlayerManager.h"
#include "../../managers/player/ProfessionManager.h"
#include "../../managers/crafting/CraftingManager.h"
#include "../../managers/item/ItemManager.h"
#include "../../managers/combat/CombatManager.h"
#include "../../managers/guild/GuildManager.h"
#include "../../managers/group/GroupManager.h"
#include "../../managers/planet/PlanetManager.h"
#include "../../managers/structure/StructureManager.h"
#include "../../managers/resource/ResourceManager.h"
#include "../../managers/loot/LootManager.h"
#include "../../managers/sui/SuiManager.h"
#include "../../managers/mission/MissionManager.h"

#include "../../../chat/ChatManager.h"
#include "../../../ServerCore.h"

#include "EquippedItems.h"

#include "Races.h"

#include "../terrain/Terrain.h"
#include "../terrain/RegionNames.h"

#include "../tangible/weapons/WeaponImplementation.h"

#include "Player.h"
#include "PlayerImplementation.h"

#include "PlayerHAM.h"

#include "events/PlayerLogoutEvent.h"
#include "events/PlayerDisconnectEvent.h"
#include "events/PlayerSaveStateEvent.h"
#include "events/PlayerRecoveryEvent.h"
#include "events/PlayerDigestEvent.h"
#include "events/CommandQueueActionEvent.h"
#include "events/ChangeFactionStatusEvent.h"
#include "events/CenterOfBeingEvent.h"
#include "events/PowerboostEventWane.h"
#include "events/SurveyEvent.h"
#include "events/EntertainerEvent.h"
#include "events/SampleEvent.h"
#include "events/InvisibleDelayEvent.h"

#include "events/ForageDelayEvent.h"
#include "../creature/skills/self/ForageZone.h"

#include "../creature/events/DizzyFallDownEvent.h"

#include "professions/Certification.h"
#include "professions/profession/FourByFourProfession.h"
#include "professions/profession/OneByFourProfession.h"
#include "professions/profession/PyramidProfession.h"

#include "../../managers/combat/CommandQueueAction.h"
#include "../../managers/skills/SkillManager.h"
#include "badges/Badge.h"

PlayerImplementation::PlayerImplementation() : PlayerServant(0) {
	zoneID = 1;
	//zoneID = 8;

	setHeight(1.0f);
	imagedesignXpGiven = false;
}

PlayerImplementation::PlayerImplementation(uint64 cid) : PlayerServant(baseID = cid << 32) {
	characterID = cid;
	imagedesignXpGiven = false;
}

PlayerImplementation::~PlayerImplementation() {

	if (isInQuadTree()){
		System::out << "ERROR deleting a player that is still in the Quadtree\n";
		raise(SIGSEGV);
	}

	clearBuffs(false);

	for (int i = 0; i < suiBoxes.size(); ++i) {
		SuiBox* box =  suiBoxes.get(i);
		box->finalize();
	}

	for (int i = 0; i < missionMap.size(); ++i) {
		MissionObject* miso = missionMap.get(i);
		miso->finalize();
	}

	missionMap.removeAll();

	if (playerObject != NULL) {
		playerObject->finalize();
		playerObject = NULL;
	}

	if (datapad != NULL) {
		info("undeploying player datapad");

		datapad->finalize();
		datapad = NULL;
	}

	if (hairObj != NULL) {
		hairObj->finalize();
		hairObj = NULL;
	}

	if (centerOfBeingEvent != NULL) {
		server->removeEvent(centerOfBeingEvent);

		delete centerOfBeingEvent;
		centerOfBeingEvent = NULL;
	}

	if (invisibleDelayEvent != NULL) {
		if (invisibleDelayEvent->isQueued())
			server->removeEvent(invisibleDelayEvent);

		delete invisibleDelayEvent;
		invisibleDelayEvent = NULL;
	}

	if (recoveryEvent != NULL) {
		if (recoveryEvent->isQueued())
			server->removeEvent(recoveryEvent);

		delete recoveryEvent;
		recoveryEvent = NULL;
	}

	if (digestEvent != NULL) {
		if (digestEvent->isQueued())
			server->removeEvent(digestEvent);

		delete digestEvent;
		digestEvent = NULL;
	}

	if (suiChoicesList != NULL) {
		suiChoicesList->finalize();
		suiChoicesList = NULL;
	}

	if (badges != NULL) {
		badges->finalize();
		badges = NULL;
	}

	if (camp != NULL) {
		camp->disbandCamp();
		camp = NULL;
	}

	if (draftSchematicMap != NULL) {
		delete draftSchematicMap;
	}

	server->getZoneServer()->increaseTotalDeletedPlayers();

	info("undeploying player");

}

void PlayerImplementation::initializePlayer() {
	objectType = PLAYER;

	accountID = 0;

	owner = NULL;
	zone = NULL;

	onlineStatus  = LOGGINGIN;

	// objects
	playerObject = NULL;

	disconnectEvent = NULL;
	logoutEvent = NULL;

	playerSaveStateEvent = NULL;

	recoveryEvent = NULL;
	digestEvent = NULL;

	changeFactionEvent = NULL;

	invisibleDelayEvent = NULL;

	datapad = NULL;
	equippedItems = NULL;

	stfFile = "species";

	// modifiers
	weaponSpeedModifier = 1;

	// constants
	itemShift = 100;

	attackable = true;

	// pvp stuff
	incapacitationCounter = 0;
	pvpRating = PVPRATING_DEFAULT; //New players start with pvpRating of 1200
	duelList.setInsertPlan(SortedVector<Player*>::NO_DUPLICATE);
	factionStatus = 0;

	// profession
	skillPoints = 0;
	forceStatus = System::random(5);
	skillBoxesToSave.setInsertPlan(SortedVector<SkillBox*>::NO_DUPLICATE);
	certificationList.setInsertPlan(SortedVector<Certification*>::NO_DUPLICATE);
	certificationList.setNullValue(NULL);
	xpCapList.setInsertPlan(SortedVector<int>::ALLOW_OVERWRITE);

	// Draft Schematics
	draftSchematicUpdateCount = 0;
	draftSchematicMap = new DraftSchematicMap(_this);

	//Crafting
	activeCraftingTool = NULL;

	//GM Flags
	chatMuted = false;
	immune = false;
	invisible = false;

	//Mission Vars
	misoRFC = 0x01;
	misoBSB = 0;
	curMisoKeys = "";
	finMisoKeys = "";
	missionMap.setNullValue(NULL);

 	regionId = 31; //Ancorhead I think lols.

 	conversatingCreature = NULL;

 	chatRooms.setInsertPlan(SortedVector<ChatRoom*>::NO_DUPLICATE);
 	missionMap.setInsertPlan(SortedVector<ChatRoom*>::NO_DUPLICATE);
 	missionMap.setNullValue(NULL);

 	setLotsRemaining(10);
 	centered = false;

 	powerboosted = false;

 	foraging = false;
 	forageDelayEvent = NULL;

 	acceptingBandFlourishes = true;

	centerOfBeingEvent = new CenterOfBeingEvent(this);

	invisibleDelayEvent = new InvisibleDelayEvent(this);

	lastTestPositionX = 0.f;
	lastTestPositionY = 0.f;

	tradeRequestedPlayer = 0;
	moneyToTrade = 0;
	acceptedTrade = false;
	verifiedTrade = false;

	surveyEvent = NULL;
	entertainerEvent = NULL;
	sampleEvent = NULL;
	firstSampleEvent = NULL;
	surveyWaypoint = NULL;
	surveyTool = NULL;
	cancelSample = false;
	surveyErrorMessage = false;
	sampleErrorMessage = false;

	activeCraftingTool = NULL;

	// Stat Migration
	setMigrationHealth(0);
	setMigrationStrength(0);
	setMigrationConstitution(0);
	setMigrationAction(0);
	setMigrationQuickness(0);
	setMigrationStamina(0);
	setMigrationMind(0);
	setMigrationFocus(0);
	setMigrationWillpower(0);

	suiBoxes.setInsertPlan(SortedVector<SuiBox*>::NO_DUPLICATE);
	suiBoxes.setNullValue(NULL);

	suiChoicesList = new SuiListBoxVector();

	suiBoxNextID = 0;

	guildLeader = false;

	setLogging(false);
	setGlobalLogging(true);

	teachingTarget = NULL;
	teachingTrainer = NULL;
	teachingSkillList.removeAll();
	teachingOffer = false;
	activeArea = NULL;
	badges = new Badges();
	camp = NULL;
	campAggro = 0;

	//Cloning
	cloningFacility = NULL;

	if (getWeapon() == NULL) {
		int templevel = calcPlayerLevel("combat_meleespecialize_unarmed");
		if (calcPlayerLevel("medical") > templevel)
			templevel = calcPlayerLevel("medical");
		setLevel(templevel);
	} else {
		int templevel = calcPlayerLevel(getWeapon()->getXpType());
		if (calcPlayerLevel("medical") > templevel)
			templevel = calcPlayerLevel("medical");
		setLevel(templevel);
	}

	powerboostEventWane = NULL;

	if (!isDead() && !isIncapacitated() && (!isOnFullHealth() || hasWounds() || hasShockWounds() || hasStates()))
		activateRecovery();

	numberOfCHPets = 0;
	levelOfCHPets = 0;
	droidCalled = false;
	factionPetCalled = false;
	petList.setInsertPlan(SortedVector<CreaturePet*>::NO_DUPLICATE);
	petList.setNullValue(NULL);

	tameing = false;

}

void PlayerImplementation::create(ZoneClientSession* client) {
	playerObject = new PlayerObject(_this);

	setClient(client);
	client->setPlayer(_this);

	String logName = "Player = " + firstName;

	setLockName(logName);
	//client->setLockName("ZoneClient = " + firstName);

	setLoggingName(logName);

	info("created player");
}

void PlayerImplementation::makeCharacterMask() {
	characterMask = 0;

	if (this->isRebel())
		characterMask |= REBEL;
	else if (this->isImperial())
		characterMask |= IMPERIAL;
	else
		characterMask |= NEUTRAL;

	if (this->isOnLeave())
		characterMask |= COVERT;

	switch (raceID) {
	case 0:
		characterMask |= MALE | HUMAN;
		break;
	case 1:
		characterMask |= MALE | TRANDOSHAN;
		break;
	case 2:
		characterMask |= MALE | TWILEK;
		break;
	case 3:
		characterMask |= MALE | BOTHAN;
		break;
	case 4:
		characterMask |= MALE | ZABRAK;
		break;
	case 5:
		characterMask |= MALE | RODIAN;
		break;
	case 6:
		characterMask |= MALE | MONCALAMARI;
		break;
	case 7:
		characterMask |= MALE | WOOKIEE;
		break;
	case 8:
		characterMask |= MALE | SULLUSTAN;
		break;
	case 9:
		characterMask |= MALE | ITHORIAN;
		break;
	case 10:
		characterMask |= FEMALE | HUMAN;
		break;
	case 11:
		characterMask |= FEMALE | TRANDOSHAN;
		break;
	case 12:
		characterMask |= FEMALE | TWILEK;
		break;
	case 13:
		characterMask |= FEMALE | BOTHAN;
		break;
	case 14:
		characterMask |= FEMALE | ZABRAK;
		break;
	case 15:
		characterMask |= FEMALE | RODIAN;
		break;
	case 16:
		characterMask |= FEMALE | MONCALAMARI;
		break;
	case 17:
		characterMask |= FEMALE | WOOKIEE;
		break;
	case 18:
		characterMask |= FEMALE | SULLUSTAN;
		break;
	case 19:
		characterMask |= FEMALE | ITHORIAN;
		break;
	}
}

void PlayerImplementation::refuseCreate(ZoneClientSession* client) {
	info("name refused for character creation");

	BaseMessage* msg = new ClientCreateCharacterFailed("name_declined_in_use");
	client->sendMessage(msg);

	client->disconnect();
}

void PlayerImplementation::load(ZoneClientSession* client) {
	try {
		//wlock();

		setLoggingIn();

		owner = client;
		client->setPlayer(_this);

		StringBuffer logName;
		logName << "Player = " << firstName << " (0x" << hex << objectID << dec << ")";

		setLockName(logName.toString());
		setLoggingName(logName.toString());

		info("loading player");

		makeCharacterMask();

		loadItems();
		setLoggingIn(); //Anyone notice this is in here twice?

		Zone* zone = server->getZoneServer()->getZone(zoneID);
		insertToZone(zone);

		initializeEvents();

		resetArmorEncumbrance();

		missionMap.removeAll();
		loadMissions();

		PlayerManager* playerManager = server->getZoneServer()->getPlayerManager();
		playerManager->updateOtherFriendlists(_this, true);
		displayMessageoftheDay();

		// clear camp
		if (camp == NULL) {
			//getCamp()->abandonCamp();
			//setCamp(NULL);
			setCampAggroMod(0);
			setCampModifier(0);
		}

		//unlock();
	} catch (Exception& e) {
		//unlock();

		error("logging in character");
		error(e.getMessage());

		client->disconnect();
	}
}

void PlayerImplementation::reload(ZoneClientSession* client) {
	try {
		wlock();

		if (inventory == NULL) { // we should be in load() not in reload()
			load(client);

			unlock();

			return;
		}

		if (isLoggingOut()) {
			if (disconnectEvent != NULL) {
				server->removeEvent(disconnectEvent);

				delete disconnectEvent;
				disconnectEvent = NULL;
			}

			info("reloading player");
		} else if (logoutEvent != NULL) {
			server->removeEvent(logoutEvent);

			delete logoutEvent;
			logoutEvent = NULL;
		} else if (isLoggingIn()) {
			info("kicking player over network failure");

			unlock();

			if (owner != NULL && owner != client)
				owner->disconnect();

			wlock();

			info("loading player");
		} else if (isOnline()) {
			info("already loaded");

			unlock();

			client->disconnect();
			return;
		} else if (isOffline()) {
			info("reloading player from Cache");
		}

		if (isLinkDead()) {
			info("clearing link dead status");
			if (playerObject != NULL)
				playerObject->clearCharacterBit(PlayerObjectImplementation::LD, true);
		}

		owner = client;
		client->setPlayer(_this);

		setLoggingIn();

		initializeEvents();

		Zone* zone = server->getZoneServer()->getZone(zoneID);

		if (isInQuadTree())
			reinsertToZone(zone);
		else
			insertToZone(zone);

		PlayerManager* playerManager = server->getZoneServer()->getPlayerManager();
		playerObject->updateAllFriends(playerObject);
		playerManager->updateGuildStatus(_this);

		if (isRidingMount())
			dismount(true, true);

		//resetArmorEncumbrance();

		activateRecovery();

		//reset mission vars:
		loadMissions();

		playerManager->updateOtherFriendlists(_this, true);
		displayMessageoftheDay();

		unlock();
	} catch (Exception& e) {
		error("reconnecting in character");
		error(e.getMessage());

		unlock();

		client->disconnect();
	}
}

void PlayerImplementation::unload() {
	info("unloading player");

	tradeItems.removeAll();

	for (int i = 0; i < commandQueue.size(); ++i) {
		CommandQueueAction* action = commandQueue.get(i);

		delete action;
	}

	for (int i = 0 ; i < petList.size() ; i++) {
		CreaturePet* pet = petList.get(i);
		try {
			if (pet->getLinkedCreature() == _this) {
				pet->lock();
				pet->store(false);
				pet->unlock();
			}
		} catch (...) {
			pet->unlock();
			System::out << "exception PlayerImplementation::switchMap pet\n";
		}
	}

	commandQueue.removeAll();

	forageZones.removeAll();
	medForageZones.removeAll();

	removePowerboost();

	clearCombatState(); // remove the defenders

	removeEvents();

	PlayerManager* playerManager = server->getZoneServer()->getPlayerManager();
	playerManager->updateOtherFriendlists(_this, false);

	// remove from group

	// remove from chat rooms
	while (!chatRooms.isEmpty()) {
		ChatRoom* room = chatRooms.get(0);
		room->removePlayer(_this, false);
	}

	// unload mount from world
	if (mount != NULL) {
		//CreatureObject* mnt = (CreatureObject*) mount;
		mount->lock();

		((VehicleObject*)mount)->store(false);

		mount->unlock();
	}

	savePlayerState();

	if (zone != NULL) {
		ZoneServer* zserver = zone->getZoneServer();

		PlayerManager* playerManager = zserver->getPlayerManager();
		playerManager->unload(_this);

		if (isInQuadTree()) {
			if (isDancing())
				stopDancing();
			else if (isPlayingMusic())
				stopPlayingMusic();

			if (isWatching())
				stopWatch(watchID);

			if (isListening())
				stopListen(listenID);

			clearTarget();

			removeFromZone(true);
			//zone = NULL;
		}
	}

	// clear camp
	if (camp != NULL) {
		getCamp()->disbandCamp();
		setCamp(NULL);
		setCampAggroMod(0);
		setCampModifier(0);
	}

	if (group != NULL) {
		GroupManager* groupManager = server->getGroupManager();
		ManagedReference<GroupObject> groupObject = group;
		groupManager->leaveGroup(groupObject, _this);
	}

	clearDuelList();

	activateRecovery();
}

void PlayerImplementation::savePlayerState(bool doSchedule) {
	info("saving player state");

	saveWaypoints(_this);

	playerObject->saveFriends();
	playerObject->saveIgnore();

	if (zone != NULL) {
		ZoneServer* zserver = zone->getZoneServer();

		PlayerManager* playerManager = zserver->getPlayerManager();
		playerManager->save(_this);

		ItemManager* itemManager = zserver->getItemManager();
		itemManager->unloadPlayerItems(_this);
		itemManager->unloadDatapadItems(_this);

		saveMissions();
	}

	if (doSchedule)
		activateSaveStateEvent();
}

void PlayerImplementation::logout(bool doLock) {
	wlock(doLock);

	if (disconnectEvent == NULL) {
		info("creating disconnect event");

		disconnectEvent = new PlayerDisconnectEvent(_this);

		if (isLoggingOut()) {
			server->addEvent(disconnectEvent, 10);
		} else {
			server->addEvent(disconnectEvent, 1000);
			setLoggingOut();
		}
	}

	unlock(doLock);
}


void PlayerImplementation::userLogout(int msgCounter) {
	if (msgCounter < 0 || msgCounter > 3)
		msgCounter = 3;

	if (!isSitting() && !isInCombat() && !isDead() && !isIncapacitated())
		changePosture(CreaturePosture::SITTING);

	if (isSitting() && !isInCombat()) {
		logoutEvent = new PlayerLogoutEvent(_this, msgCounter);

		uint8 duration = 30; //Logout event lasts x seconds.
		uint8 multiplier = 5; //Interval multiplier of x seconds.
		uint8 timeLeft = duration; //How much time is remaining.

		switch (msgCounter) {
			case 0: { // Disconnect!!!
				sendSystemMessage("logout", "safe_to_log_out"); //You may now logout safely.

				info("Safe Logout");

				setLoggingOut();

				ClientLogout * packet = new ClientLogout();
				sendMessage(packet);

				delete logoutEvent;
				logoutEvent = NULL;
				break;
			}
			case 1:
				timeLeft -= 10;
			case 2:
				timeLeft -= 15;
			case 3: {

				StfParameter* stfp = new StfParameter();
				stfp->addDI(timeLeft);
				sendSystemMessage("logout", "time_left", stfp); //You have %DI seconds before you may logout safely.
				delete stfp;

				server->addEvent(logoutEvent, multiplier * msgCounter * 1000);
				break;
			}
		}
	} else {
		if (logoutEvent != NULL) { // we better dont delete the event from where
									//we are running this so we make sure we make it null in event::activate() before calling this
			if (logoutEvent->isQueued())
				server->removeEvent(logoutEvent);

			delete logoutEvent;
			logoutEvent = NULL;
		}

		sendSystemMessage("logout", "must_be_sitting"); //You must be sitting in order to log out safely.
	}
}

void PlayerImplementation::disconnect(bool closeClient, bool doLock) {
	try {
		wlock(doLock);

		if (!isOnline()) {
			unlock(doLock);
			return;
		}

		// User is disconnecting in combat.  Will remain LD.
		if (isInCombat() && !isLinkDead()) {
			info("link dead");

			setLinkDead();
		} else {
			info("disconnecting player");

			unload();

			setOffline();
		}

		if (disconnectEvent != NULL)
			disconnectEvent = NULL;

		if (logoutEvent != NULL) {
			server->removeEvent(logoutEvent);
			delete logoutEvent;

			logoutEvent = NULL;
		}

		if (closeClient && owner != NULL) {
			owner->closeConnection(false);
		}

		owner = NULL;

		unlock(doLock);
	} catch (Exception& e) {
		error("Exception on Player::disconnect()");
		e.printStackTrace();

		clearDisconnectEvent();
		unlock(doLock);
	} catch (...) {
		error("unreported exception on Player::disconnect()");

		clearDisconnectEvent();
		unlock(doLock);
	}
}

void PlayerImplementation::initializeEvents() {
	if (playerSaveStateEvent == NULL) {
		playerSaveStateEvent = new PlayerSaveStateEvent(_this);

		server->addEvent(playerSaveStateEvent);
	}

	PowerboostSelfSkill* skill = (PowerboostSelfSkill*)creatureSkills.get(0x8C2221CB); //Get the Powerboost skill.
	powerboostEventWane = new PowerboostEventWane(_this, skill);

	if (dizzyFallDownEvent == NULL)
		dizzyFallDownEvent = new DizzyFallDownEvent(this);
}

void PlayerImplementation::removeEvents() {
	if (firstSampleEvent != NULL) {
		if (firstSampleEvent->isQueued())
			server->removeEvent(firstSampleEvent);

		delete firstSampleEvent;
		firstSampleEvent = NULL;
	}

	if (sampleEvent != NULL) {
		if (sampleEvent->isQueued())
			server->removeEvent(sampleEvent);

		delete sampleEvent;
		sampleEvent = NULL;
	}

	if (entertainerEvent != NULL) {
		if (entertainerEvent->isQueued())
			server->removeEvent(entertainerEvent);

		delete entertainerEvent;
		entertainerEvent = NULL;
	}

	if (isInQuadTree()) {
		if (dizzyFallDownEvent != NULL ) {
			if (dizzyFallDownEvent->isQueued())
				server->removeEvent(dizzyFallDownEvent);

			delete dizzyFallDownEvent;
			dizzyFallDownEvent = NULL;
		}

		if (changeFactionEvent != NULL) {
			server->removeEvent(changeFactionEvent);

			delete changeFactionEvent;
			changeFactionEvent = NULL;
		}
	}

	if (playerSaveStateEvent != NULL) {
		if (playerSaveStateEvent->isQueued())
			server->removeEvent(playerSaveStateEvent);

		delete playerSaveStateEvent;
		playerSaveStateEvent = NULL;
	}
}

void PlayerImplementation::loadItems(bool newcharacter) {
	inventory = new Inventory(_this);
	inventory->setContainerVolumeLimit(80);

	bankContainer = new BankInventory(_this);
	bankContainer->setContainerVolumeLimit(100);

	datapad = new Datapad(_this);
	datapad->setContainerVolumeLimit(100);

	equippedItems = new EquippedItems(_this);

	ItemManager* itemManager = zone->getZoneServer()->getItemManager();
	if (newcharacter) {
		itemManager->loadDefaultPlayerItems(_this);
		itemManager->loadPlayerDatapadItems(_this);
	} else {
		itemManager->loadPlayerItems(_this);
	}

	if (!hairObject.isEmpty()) {
		hairObj = new HairObject(_this, hairObject.hashCode(), UnicodeString("hair"), "hair");

		String hairAppearance;
		getHairAppearance(hairAppearance);

		hairObj->setCustomizationString(hairAppearance);
	}
}

void PlayerImplementation::updateHair() {
	if (hairObj != NULL) {
		if (zone != NULL) {
			//unequipItem(hairObj);
			ZoneServer* zserver = zone->getZoneServer();

			ItemManager* itemManager = zserver->getItemManager();
			removeInventoryItem(hairObj);

			BaseMessage* msg = new SceneObjectDestroyMessage(hairObj);
			broadcastMessage(msg);

			hairObj->finalize();
			hairObj = NULL;
		}
	}

	if (!hairObject.isEmpty()) {
		hairObj = new HairObject(_this, hairObject.hashCode(), UnicodeString("hair"), "hair");

		String hairAppearance;
		getHairAppearance(hairAppearance);

		hairObj->setCustomizationString(hairAppearance);
		hairObj->sendTo(_this);

		unequipItem(hairObj);
		equipItem(hairObj);
	}
}

void PlayerImplementation::createBaseStats() {
	//TODO: bit hackish, find more clean solution

	int hamValues[9];

	if (startingProfession == "crafting_artisan")
		memcpy(hamValues, professionHams[0], sizeof(hamValues));
	else if (startingProfession == "combat_brawler")
		memcpy(hamValues, professionHams[1], sizeof(hamValues));
	else if (startingProfession == "social_entertainer")
		memcpy(hamValues, professionHams[2], sizeof(hamValues));
	else if (startingProfession == "combat_marksman")
		memcpy(hamValues, professionHams[3], sizeof(hamValues));
	else if (startingProfession == "science_medic")
		memcpy(hamValues, professionHams[4], sizeof(hamValues));
	else if (startingProfession == "outdoors_scout")
		memcpy(hamValues, professionHams[5], sizeof(hamValues));
	else
		memcpy(hamValues, professionHams[6], sizeof(hamValues));

	int race = Races::getRaceID(raceFile);

	// Add the race mods
	int hamMods[9];
	memcpy(hamMods, raceHamMods[race % 10], sizeof(hamMods));

	for (int i = 0; i < 9; i++)
		hamValues[i] += hamMods[i];

	setBaseHealth(hamValues[0]);
	setBaseStrength(hamValues[1]);
	setBaseConstitution(hamValues[2]);
	setBaseAction(hamValues[3]);
	setBaseQuickness(hamValues[4]);
	setBaseStamina(hamValues[5]);
	setBaseMind(hamValues[6]);
	setBaseFocus(hamValues[7]);
	setBaseWillpower(hamValues[8]);
}

void PlayerImplementation::trainStartingProfession() {
	trainSkillBox(startingProfession + "_novice");

	ProfessionManager* professionManager = server->getProfessionManager();
	professionManager->loadDefaultSkills(this);

}

void PlayerImplementation::decayInventory() {
	if (inventory != NULL) {
		for (int i = 0; i < inventory->getContainerObjectsSize(); i++) {
			TangibleObject* item = ((TangibleObject*) inventory->getObject(i));

			if (item->isDecayable()) {
				if (item->isInsured()) {
					item->decay(0.01f);
				} else {
					item->decay(0.05f);
				}
			}

			item->sendTo(_this);
		}
	}
}

void PlayerImplementation::resetArmorEncumbrance() {
	if (equippedItems == NULL) {
		System::out << "ERROR - equippedItems not initialised" << endl;
		return;
	}
	healthEncumbrance = equippedItems->getHealthEncumbrance();
	actionEncumbrance = equippedItems->getActionEncumbrance();
	mindEncumbrance = equippedItems->getMindEncumbrance();
}

void PlayerImplementation::sendToOwner(bool doClose) {

	// Why is this here? -Bobius
	//if (faction != 0)
	//	pvpStatusBitmask |= CreatureFlag::OVERT;

	info("PlayerImplementation::sendToOwner");
	CreatureObjectImplementation::sendToOwner(_this, false);

	playerObject->sendToOwner();

	sendItemsTo(_this);
	sendDatapadItems();
	sendGuildList();

	//if (parent != NULL)
	//	parent->sendTo(_this);

	if (doClose)
		SceneObjectImplementation::close(owner);
}

void PlayerImplementation::sendTo(Player* player, bool doClose) {
	CreatureObjectImplementation::sendTo(player, false);

	playerObject->sendTo(player);

	if (doClose)
		SceneObjectImplementation::close(player->getClient());
}

void PlayerImplementation::sendDatapadItems() {
	//datapad
	datapad->sendTo(_this, false);

	for (int i = 0; i < datapad->getContainerObjectsSize(); ++i) {
		SceneObject* item = datapad->getObject(i);

		item->sendTo(_this);
	}

	datapad->close(_this);
}

void PlayerImplementation::insertToZone(Zone* zone) {
	PlayerImplementation::zone = zone;

	if (onlineStatus != LOGGINGIN)
		onlineStatus = LOADING;

	if (owner == NULL)
		return;

	try {
		zone->lock();

		info("PlayerImplementation::insertToZone");

		if (parent == NULL) {
			setPosition(positionX, zone->getHeight(positionX, positionY), positionY);
			updatePlayerPosition(false);
		}

		zone->registerObject(_this);

		owner->balancePacketCheckupTime();

		sendToOwner();

		if (parent != NULL && parent->isCell()) {
			info("parent is not null and is a cell");
			BuildingObject* building = (BuildingObject*) parent->getParent();
			insertToBuilding(building);

			/* TODO: This shouldn't ever really happen neways...
			if (!building->getStorageLoaded()) {
				ZoneServer* zserver = zone->getZoneServer();
				ItemManager* itemManager = zserver->getItemManager();

				zone->unlock();

				itemManager->loadStructurePlayerItems(_this, parent->getObjectID());

				zone->lock();
			}*/
		} else {
			zone->insert(this);
			zone->inRange(this, 128);
		}



		owner->resetPacketCheckupTime();

		zone->unlock();
	} catch (...) {
		error("exception Player::insertToZone(Zone* zone)");

		zone->unlock();
	}
}

void PlayerImplementation::insertToBuilding(BuildingObject* building, bool doLock) {
	if (owner == NULL || isInQuadTree() || !parent->isCell())
		return;

	try {
		building->lock();

		info("PlayerImplementation::insertToBuilding");

		((CellObject*)parent)->addChild(_this);

		building->insert(this);
		building->inRange(this, 128);

		building->unlock();

		building->notifyInsertToZone(_this);

		linkType = 0xFFFFFFFF;
		//linkType = 0x04;
		broadcastMessage(link(parent->getObjectID(), 0xFFFFFFFF), 128, false);

		info("just sent cell link to everyone else");
	} catch (...) {
		error("exception PlayerImplementation::insertToBuilding(BuildingObject* building)");

		building->unlock();
	}
}

void PlayerImplementation::reinsertToZone(Zone* zone) {
	if (onlineStatus != LOGGINGIN)
		onlineStatus = LOADING;

	try {
		zone->lock();

		info("reinserting to zone");

		owner->balancePacketCheckupTime();

		sendToOwner();

    	for (int i = 0; i < inRangeObjectCount(); ++i) {
			QuadTreeEntry* obj = getInRangeObject(i);

			notifyInsert(obj);
		}

		owner->resetPacketCheckupTime();

		zone->unlock();
	} catch (...) {
		error("exception Player::reinsertToZone(Zone* zone)");

		zone->unlock();
	}

}

void PlayerImplementation::updateZone(bool lightUpdate) {
	if (zone == NULL || isIncapacitated() || isDead())
		return;

	//bool insert = false;

	/*if (zone->getZoneID() == 8) {
		float height = zone->getHeight(positionX, positionY);
		System::out << "(" << positionX << "," << height << "," << positionY << "\n";
	}*/

	if (isRidingMount()) {
		updateMountPosition();
	}
	try {
		//info("updating player in Zone");

		zone->lock();

		if (parent != NULL && parent->isCell()) {
			CellObject* cell = (CellObject*)parent;

			removeFromBuilding((BuildingObject*)cell->getParent());

			parent = NULL;
//			insert = true;
			zone->insert(this);

		}
		else {
			zone->update(this);
		}
	/*	if (insert)
			zone->insert(this);
		else
			zone->update(this);
*/
		zone->inRange(this, 128);

		if (!isRidingMount())
			updatePlayerPosition(lightUpdate);

		zone->unlock();

		//info("finished player update in Zone");
	} catch (...) {
		error("exception Player::updateZone()");

		zone->unlock();
	}
}

void PlayerImplementation::updateZoneWithParent(uint64 Parent, bool lightUpdate) {
	if (isRidingMount())
		dismount(true, true);

	if (zone == NULL)
		return;

	SceneObject* newParent = parent;

	if (parent == NULL || (parent != NULL && parent->getObjectID() != Parent))
		newParent = zone->lookupObject(Parent);

	if (newParent == NULL)
		return;

	if (!newParent->isCell()) {
		return;
	}

	bool insert = false;

	try {
		zone->lock();

		if (newParent != parent) {
			if (parent == NULL) {
				zone->remove(this);
				insert = true;
			} else {
				if (parent->isCell()) {
					BuildingObject* building = (BuildingObject*) parent->getParent();
					SceneObject* newObj = newParent->getParent();

					if (newObj->isBuilding()) {
						BuildingObject* newBuilding = (BuildingObject*) newObj;

						if (building != newBuilding) {
							//System::out << "Does this actually ever happen when someone goes from one building to another?" << endl;

							removeFromBuilding(building);

							insert = true;
						}
					}

					// remove from old cell
					if (parent != NULL)
						((CellObject*) parent)->removeChild(_this);
				} else
					insert = true;
			}

			//System::out << "Cell Transition.  Old: " << hex << parent <<  dec << " New: " << hex << newParent << dec << endl;
			// add to new cell
			parent = newParent;
			((CellObject*) parent)->addChild(_this);

			//linkType = 0x04;
			broadcastMessage(link(parent->getObjectID(), 0xFFFFFFFF), 128, false);

		}

		BuildingObject* building = (BuildingObject*) parent->getParent();

		if (insert) {
			info("insertToBuilding from updateZoneWithParent");
			insertToBuilding(building, false);

		} else {
			building->lock();

			building->update(this);
			building->inRange(this, 128);

			building->unlock();
		}

		updatePlayerPosition(lightUpdate);

		zone->unlock();
	} catch (...) {
		zone->unlock();
		error("Exception in PlayerImplementation::updateZoneWithParent");
	}
}

void PlayerImplementation::updatePlayerPosition(bool doLightUpdate) {
	for (int i = 0; i < inRangeObjectCount(); ++i) {
		SceneObject* obj = (SceneObject*) (((SceneObjectImplementation*) getInRangeObject(i))->_getStub());

		if (obj != _this && obj->isPlayer()) {
			Player* player = (Player*) obj;

			if (doLightUpdate) {
				if (parent != NULL && parent->isCell()) {
					LightUpdateTransformWithParentMessage* umsg = new LightUpdateTransformWithParentMessage(_this);
					player->sendMessage(umsg);
				} else {
					LightUpdateTransformMessage* umsg = new LightUpdateTransformMessage(_this);
					player->sendMessage(umsg);
				}
			} else {
				if (parent != NULL && parent->isCell()) {
					UpdateTransformWithParentMessage* umsg = new UpdateTransformWithParentMessage(_this);
					player->sendMessage(umsg);
				} else {
					UpdateTransformMessage* umsg = new UpdateTransformMessage(_this);
					player->sendMessage(umsg);
				}
			}
		}
	}
}

void PlayerImplementation::updateMountPosition() {
	if (parent == NULL || !isRidingMount())
		return;

	try {
		mount->wlock();

		mount->setDirection(directionX, directionZ, directionY, directionW);
		mount->setPosition(positionX, positionZ, positionY);
		mount->updateZone();

		mount->unlock();
	} catch (...) {
		System::out << "Unreported exception in PlayerImplementation::updateMount()\n";
		mount->unlock();
	}
}

void PlayerImplementation::removeFromZone(bool doLock) {
	if (zone == NULL)
		return;

	try {
		zone->lock(doLock);

		info("removing from zone");

		SceneObject* par = NULL;

		if (parent != NULL && parent->isCell()) {
			CellObject* cell = (CellObject*) parent;
			BuildingObject* building = (BuildingObject*)parent->getParent();

			par = parent;

			removeFromBuilding(building);
		} else
			zone->remove(this);

		for (int i = 0; i < inRangeObjectCount(); ++i) {
			QuadTreeEntry* obj = getInRangeObject(i);

			if (obj != this)
				obj->removeInRangeObject(this);
		}

		removeInRangeObjects();

		zone->deleteObject(objectID);

		if (par != NULL)
			parent = par;

		zone->unlock(doLock);
	} catch (...) {
		error("exception Player::removeFromZone(bool doLock)");

		zone->unlock(doLock);
	}
}

void PlayerImplementation::deaggro() {
	// TODO: FIX: this will deadlock if its called with a player from this defender list locked: eg: command handler @summon
	// Temporarly moved to ::load and ::reload till we figure a better solution
	// pre this wlocked
	// post this wlocked
	try {
		if (isInCombat()) {

			SceneObject* scno = NULL;
			Creature* defender = NULL;

			CreatureObject* aggroedCreature = NULL;
			Player* aggroedPlayer = NULL;

			for (int i = 0; i < getDefenderListSize(); ++i) {
				scno = getDefender(i);

				try {
					if ((SceneObject*) scno != (SceneObject*) _this)
						scno->wlock(_this);

					scno->dropDamageDone((CreatureObject*)_this);

					if (scno->isNonPlayerCreature()) {

						defender = (Creature*) scno;
						aggroedCreature = defender->getAggroedCreature();

						if (aggroedCreature != NULL && aggroedCreature->isPlayer()) {

							aggroedPlayer = (Player*) aggroedCreature;

							if (aggroedPlayer->getFirstName() == getFirstName()) {
								defender->deaggro();
								defender->removeFromDamageMap(aggroedCreature);
								removeDefender(scno);
							}
						}
					}

					if ((SceneObject*) scno != (SceneObject*) _this)
						scno->unlock();
				} catch (...) {
					if ((SceneObject*) scno != (SceneObject*) _this)
						scno->unlock();
				}

				if (scno->isPlayer()) {
					aggroedPlayer = (Player*) scno;

					try {
						if ((SceneObject*) aggroedPlayer != (SceneObject*) _this)
							aggroedPlayer->wlock(_this);

						aggroedPlayer->removeDefender(_this);
						removeDefender(scno);

						if ((SceneObject*) aggroedPlayer != (SceneObject*) _this)
							aggroedPlayer->unlock();
					} catch (...) {
						if ((SceneObject*) aggroedPlayer != (SceneObject*) _this)
							aggroedPlayer->unlock();
					}

				}

			}

			postureState = CreaturePosture::UPRIGHT;
			updateStates();

		}

	} catch (...) {
		error("unreported exception caught in PlayerImplementation::deaggro()");
	}
}

void PlayerImplementation::removeFromBuilding(BuildingObject* building, bool doLock) {
	if (building == NULL || !isInQuadTree() || !parent->isCell())
		return;

	try {
		building->lock();

		info("removing from building");

		//broadcastMessage(link(0, 0x04), 128, false);
		broadcastMessage(link((uint64)0, (uint32)0xFFFFFFFF), 128, false);

		((CellObject*)parent)->removeChild(_this);

		building->remove(this);

		building->unlock();
	} catch (...) {
		error("exception PlayerImplementation::removeFromBuilding(BuildingObject* building, bool doLock)");

		//building->unlock(doLock);
	}
}

void PlayerImplementation::notifyInsert(QuadTreeEntry* obj) {
	SceneObject* scno = (SceneObject*) (((SceneObjectImplementation*) obj)->_getStub());

	Player* player;
	Creature* creature;
	TangibleObject* tangible;
	StaticObject* statico;
	BuildingObject* buio;

	//AttackableObject* attacko;

	if (parent == scno)
		return;

	SceneObject* scnoParent = scno->getParent();

	if (scnoParent != NULL && scnoParent->isNonPlayerCreature())
		return;

	switch (scno->getObjectType()) {
	case SceneObjectImplementation::PLAYER:
		if (objectID == obj->getObjectID())
			break;

		player = (Player*) scno;

		if (player->isInvisible()) {
			break;
		}

		player->sendTo(_this);
		player->sendItemsTo(_this);

		break;
	case SceneObjectImplementation::NONPLAYERCREATURE:
		creature = (Creature*) scno;

		creature->sendTo(_this);
		creature->sendItemsTo(_this);

		break;
	case SceneObjectImplementation::TANGIBLE:
		tangible = (TangibleObject*) scno;
		tangible->sendTo(_this);

		break;

	case SceneObjectImplementation::STATIC:
		statico = (StaticObject*) scno;
		statico->sendTo(_this);
		break;

	case SceneObjectImplementation::BUILDING:
		buio = (BuildingObject*) scno;
		buio->sendTo(_this);
		break;
	}
}

void PlayerImplementation::notifyDissapear(QuadTreeEntry* obj) {
	//System::out << "PlayerImplementation::notifyDissapear" << endl;

	SceneObject* scno = (SceneObject*) (((SceneObjectImplementation*) obj)->_getStub());

	Player* player;
	Creature* creature;

	TangibleObject* tano;
	BuildingObject* buio;

	switch (scno->getObjectType()) {
	case SceneObjectImplementation::PLAYER:
		player = (Player*) scno;
		player->sendDestroyTo(_this);

		break;

	case SceneObjectImplementation::NONPLAYERCREATURE:
		creature = (Creature*) scno;
		creature->sendDestroyTo(_this);

		break;

	case SceneObjectImplementation::BUILDING:
		buio = (BuildingObject*) scno;
		buio->sendDestroyTo(_this);

		break;

	case SceneObjectImplementation::TANGIBLE:
		tano = (TangibleObject*) scno;
		tano->sendDestroyTo(_this);

		break;
	}
}

void PlayerImplementation::switchMap(int planetid) {
	if (zone == NULL)
		return;

	saveMissions();

	if (mount != NULL) {
		try {
			mount->lock();
			//TODO: What's going on here!?
			((VehicleObject*)mount)->store(false);
			//TODO: Move this to your store method...
			setPosture(CreaturePosture::UPRIGHT);
			clearState(CreatureState::RIDINGMOUNT);
			mount->unlock();
		} catch (...) {
			mount->unlock();
			System::out << "exception PlayerImplementation::switchMap vehicle\n";
		}
	}

	for (int i = 0 ; i < petList.size() ; i++) {
		CreaturePet* pet = petList.get(i);
		try {
			if (pet->getLinkedCreature() == _this) {
				pet->lock();
				pet->deaggro();
				pet->store(false);
				pet->unlock();
			}
		} catch (...) {
			pet->unlock();
			System::out << "exception PlayerImplementation::switchMap pet\n";
		}
	}

	removeFromZone();

	parent = NULL;

	setIgnoreMovementTests(5);

	zoneID = planetid;
	ZoneServer* server = zone->getZoneServer();
	Zone* zone = server->getZone(zoneID);

	terrainName = Terrain::getTerrainName(zoneID);

	initializePosition(positionX, zone->getHeight(positionX, positionY), positionY);

	insertToZone(zone);

	// Reload Missions after changing level
	loadMissions();
}

void PlayerImplementation::doWarp(float x, float y, float z, float randomizeDistance, uint64 parentID) {
	if (zone == NULL)
		return;

	saveMissions();

	if (isRidingMount())
		dismount(true, true);

	removeFromZone();

	parent = NULL;

	initializePosition(x, zone->getHeight(x, y), y);

	if (parentID != 0) {
		SceneObject* newParent = zone->lookupObject(parentID);

		if (newParent != NULL && newParent->isCell())
			parent = newParent;
	}

	setIgnoreMovementTests(10);

	if (randomizeDistance != 0)
		randomizePosition(randomizeDistance);

	insertToZone(zone);

	loadMissions();
}

void PlayerImplementation::bounceBack() {
	if (parent != NULL && parent->isCell()) {
		DataTransformWithParent* trans = new DataTransformWithParent(_this);
		sendMessage(trans);
	} else {
		DataTransform* trans = new DataTransform(_this);
		sendMessage(trans);
	}
}

void PlayerImplementation::drag(Player* targetPlayer, float maxRange, float maxMovement, bool needsConsent, bool canDragLiveTarget) {
	if (targetPlayer == NULL) {
		return;
	}

	if (targetPlayer == _this) {
		sendSystemMessage("healing_response", "healing_response_a5"); //"You must first have a valid target to drag before you can perform this command."
		return;
	}

	//Check minimum range.
	if (isInRange(targetPlayer, 0.01f)) {
		return;
	}

	//Check maximum range.
	if (!isInRange(targetPlayer, maxRange)) {
		StfParameter* rangeParam = new StfParameter;
		rangeParam->addDI((int)maxRange);
		sendSystemMessage("healing_response", "healing_response_b1", rangeParam); //"Your maximum drag range is %DI meters! Try getting closer."
		delete rangeParam;
		return;
	}

	//Check if target is dead or incapacitated.
	if (!canDragLiveTarget) {
		if (!targetPlayer->isDead() && !targetPlayer->isIncapacitated()) {
			sendSystemMessage("healing_response", "healing_response_a7"); //"You may only drag incapacitated or dying players!"
			return;
		}
	}

	//Check for consent to drag.
	if (needsConsent) {
		bool hasConsentFrom = targetPlayer->hasConsented(getFirstName());
		bool isGroupedWith = isInGroupWith((CreatureObject*)targetPlayer);
		if (!hasConsentFrom && !isGroupedWith) {
			sendSystemMessage("healing_response", "healing_response_b4"); //"You must be grouped with or have consent from your drag target!"
			return;
		}
	}

	//Collect locations of the dragger and the target player.
	Coordinate* dragger = new Coordinate(getPositionX(), getPositionZ(), getPositionY());
	Coordinate* target = new Coordinate(targetPlayer->getPositionX(), targetPlayer->getPositionZ(), targetPlayer->getPositionY());

	//Check for height being too far above or below.
	float heightDifference = dragger->getPositionZ() - target->getPositionZ();
	if (abs((int)heightDifference) > maxRange) {
		if (heightDifference > 0) {
			sendSystemMessage("healing_response", "healing_response_b2"); //"Your target is too far below you to drag"
			return;
		} else {
			sendSystemMessage("healing_response", "healing_response_b3"); //"Your target is too far above you to drag."
			return;
		}
	}

	//Set the proper orientation of the target (feet toward the dragger).
	float dx = dragger->getPositionX() - target->getPositionX();
	float dy = dragger->getPositionY() - target->getPositionY();
	float directionangle = atan2(dy, dx);
	float radangle = M_PI / 2 - directionangle;
	targetPlayer->setRadialDirection(radangle);

	//Set the new location of the target player.
	Coordinate* newPosition = getCoordinate(targetPlayer, _this, maxMovement);
	targetPlayer->setPosition(newPosition->getPositionX(), newPosition->getPositionZ(), newPosition->getPositionY());
	targetPlayer->increaseMovementCounter();

	//targetPlayer->updatePlayerPosition(false); //Updates everyone except targetPlayer of their movement.
	if (parent != NULL && parent->isCell())
		targetPlayer->updateZoneWithParent(parent->getObjectID(), false);
	else
		targetPlayer->updateZone(false);

	targetPlayer->bounceBack(); //Updates targetPlayer with the new location.

	//Visuals.
	targetPlayer->showFlyText("base_player", "fly_drag", 255, 0, 0);

	StfParameter* targetParam = new StfParameter;
	targetParam->addTT(targetPlayer->getObjectID());
	sendSystemMessage("healing_response", "healing_response_b5", targetParam); //"Attempting to drag %TT to your location..."
	delete targetParam;

	delete dragger;
	delete target;
	delete newPosition;
}

void PlayerImplementation::notifySceneReady() {
	PlayerObject* playerObject = getPlayerObject();

	if (onlineStatus  == LOGGINGIN) {

		playerObject->loadFriends();
		playerObject->loadIgnore();

		loadGuildChat();
		loadStaffChat();

		if (isDead())
			onDeath();

	} else {
		playerObject->friendsMagicNumberReset();
	}

	updateBuffWindow();
	//updateHAMBars();

	ChatManager* chatManager = server->getChatManager();
	chatManager->listMail(_this);

	if (parent == NULL) {
		setPosition(positionX, zone->getHeight(positionX, positionY), positionY);
		bounceBack();
		updatePlayerPosition(false);
	}

	info("scene ready");
	setOnline();
    updateWeather();
}

void PlayerImplementation::loadGuildChat() {
	ChatManager* chatManager = server->getChatManager();

	if (chatManager)
		chatManager->sendGuildChat(_this);
	else
		error("Error: PlayerManagerImplementation::loadGuildChat() chatManager is null ");
}

void PlayerImplementation::loadStaffChat() {
	if (!isPrivileged())
		return;

	ChatManager* chatmanager = server->getChatManager();

	if (chatmanager != NULL)
		chatmanager->sendStaffChat(_this);
	else
		error("Error sending StaffChat channel to privileged player.");
}

void PlayerImplementation::updateAdminLevel(uint32 level) {
	setAdminLevel(level);

	ChatManager* chatmanager = server->getChatManager();
	ChatRoom* staffchat = chatmanager->getStaffChat();

	if (!isPrivileged()) {
		try {
			staffchat->wlock();
			staffchat->removePlayer(_this, false);
			staffchat->sendDestroyTo(_this);
			staffchat->unlock();
		} catch (...) {
			error("Unhandled exception in PlayerImplementation::updateAdminLevel");
			staffchat->unlock();
		}
	}

	loadStaffChat();

	//Update the name.
	TangibleObjectDeltaMessage3* dtano3 = new TangibleObjectDeltaMessage3(_this);
	dtano3->updateName(getCharacterName().toString());
	dtano3->close();
	broadcastMessage(dtano3);
}

void PlayerImplementation::sendSystemMessage(const String& message) {
	UnicodeString msg(message);
	sendSystemMessage(msg);
}

void PlayerImplementation::sendSystemMessage(const String& file, const String& str, uint64 targetid) {
	ChatSystemMessage* msg = new ChatSystemMessage(file, str, targetid);
	sendMessage(msg);
}

void PlayerImplementation::sendSystemMessage(const String& file, const String& str,StfParameter * param) {
	ChatSystemMessage* msg = new ChatSystemMessage(file, str, param);
	sendMessage(msg);
}

void PlayerImplementation::sendMail(String& mailSender, UnicodeString& subjectSender,
		UnicodeString& bodySender, String& charNameSender) {

	ChatManager * chat=  zone->getChatManager();

	chat->sendMail(mailSender, subjectSender, bodySender, charNameSender);
}

void PlayerImplementation::sendSystemMessage(UnicodeString& message) {
	ChatSystemMessage* smsg = new ChatSystemMessage(message);
	sendMessage(smsg);
}

void PlayerImplementation::sendBattleFatigueMessage(CreatureObject* target) {
	uint32 battleFatigue = target->getShockWounds();

	String targetName = target->getCharacterName().toString();

	StringBuffer msgPlayer, msgTarget;

	if (battleFatigue < 250) {
		return;
	} else if (battleFatigue < 500) {
		msgPlayer << targetName << "'s battle fatigue is reducing the effectiveness of the medicine.";
		msgTarget << "Your battle fatigue is reducing the effectiveness of the medicine.";
	} else if (battleFatigue < 750) {
		msgPlayer << targetName << "'s battle fatigue is significantly reducing the effectiveness of the medicine.";
		msgTarget << "Your battle fatigue is significantly reducing the effectiveness of the medicine.";
	} else if (battleFatigue < 1000) {
		msgPlayer << targetName << "'s battle fatigue is greatly reducing the effectiveness of the medicine.";
		msgTarget << "Your battle fatigue is greatly reducing the effectiveness of the medicine. You should seek an entertainer.";
	} else {
		msgPlayer << targetName << "'s battle fatigue is too high for the medicine to do any good.";
		msgTarget << "Your battle fatigue is too high for the medicine to do any good. You should seek an entertainer.";
	}

	target->sendSystemMessage(msgTarget.toString());
	if (_this != target)
		sendSystemMessage(msgPlayer.toString());
}

void PlayerImplementation::sendHealMessage(CreatureObject* target, int h, int a, int m) {
	//TODO: Revisit this once Stf Concatenation is figured out.

	/*
	StfParameter* stfp = new StfParameter();
	String msgPlayer, msgTarget;

	if (h > 0 && a > 0 && m > 0 ) {
		msgPlayer = "";
		msgTarget = "";
	} else if (h > 0 && a > 0) {
		msgPlayer = "";
		msgTarget = "";
	} else if (h > 0 && m > 0) {
		msgPlayer = "";
		msgTarget = "";
	} else if (a > 0 && m > 0) {
		msgPlayer = "";
		msgTarget = "";
	} else if (h > 0) {
		msgPlayer = "";
		msgTarget = "";
	} else if (a > 0) {
		msgPlayer = "";
		msgTarget = "";
	} else if (m > 0) {
		msgPlayer = "";
		msgTarget = "";
	} else {
		return;
	}

	target->sendSystemMessage("healing_response", msgTarget.toString());
	if (_this != target)
		sendSystemMessage("healing_response", msgPlayer.toString(), stfp);
	*/

	return;
}

void PlayerImplementation::queueFlourish(const String& modifier, uint64 target, uint32 actionCntr) {
	//TODO: Refactor this part later somehow?
	if (!isPlayer())
		return;

	//PlayerImplementation* player = (PlayerImplementation*) this;

	String skillBox = "social_entertainer_novice";

	if (!getSkillBoxesSize() || !hasSkillBox(skillBox)) {
		// TODO: sendSystemMessage("cmd_err", "ability_prose", creature);
		sendSystemMessage("You do not have sufficient abilities to Flourish");
		return;
	}

	int fid = Integer::valueOf(modifier);

    if (modifier == "") {
    	sendSystemMessage("performance", "flourish_format");
    	return;
    }

    if (fid < 1 || fid > 8) {
    	sendSystemMessage("performance", "flourish_not_valid");
    	sendSystemMessage("performance", "flourish_format");
    	return;
    }

    uint32 actionCRC = String("flourish+" + modifier).hashCode(); // get the CRC for flourish+1, etc

    PlayerObject* po = getPlayerObject();
    queueAction(po->getPlayer(), target, actionCRC, actionCntr, modifier);
}

void PlayerImplementation::queueAction(Player* player, uint64 target, uint32 actionCRC, uint32 actionCntr, const String& amod) {
	/*StringBuffer ident;
	ident << "0x" << hex << actionCRC << " (" << actionCntr << ")";

	sendSystemMessage("queing action " + ident.toString());*/

	// Try to queue some music skills
	Skill* skill = creatureSkills.get(actionCRC);

	if ((isDancing() || isPlayingMusic())
		&& (skill != NULL) && !(skill->isEntertainSkill() || skill->isDanceSkill() || skill->isMusicSkill())) {

		player->sendSystemMessage("You cant use skills while dancing/playing music!");
		clearQueueAction(actionCntr);
	} else if (commandQueue.size() < 15) {
		CommandQueueAction* action = new CommandQueueAction(player, target, actionCRC, actionCntr, amod);

		if (!doAction(action)) {
			delete action;
		}
	} else
		clearQueueAction(actionCntr);

	/*sendSystemMessage("queing action " + ident.toString() + " finished");*/

	return;
}

void PlayerImplementation::doInstantAction(uint64 target, uint32 actionCRC, uint32 actionCntr, const String& amod) {
	CombatManager* combatManager = server->getCombatManager();
	CommandQueueAction* action = new CommandQueueAction(_this, target, actionCRC, actionCntr, amod);

	Skill* skill = creatureSkills.get(actionCRC);

	if (skill == NULL) {
		action->clearError(2);
		return;
	}

	updateTarget(action->getTargetID());

	action->setTarget(targetObject.get());
	action->setSkill(skill);

	if (!action->check()) {
		delete action;
		return;
	}

	combatManager->handleAction(action);
}

bool PlayerImplementation::doAction(CommandQueueAction* action) {
	CombatManager* combatManager = server->getCombatManager();

	uint32 actionCRC = action->getActionCRC();
	Skill* skill = creatureSkills.get(actionCRC);

	if (skill == NULL) {
		action->clearError(2);
		return false;
	}

	updateTarget(action->getTargetID());

	action->setTarget(targetObject.get());
	action->setSkill(skill);

	if (!action->check())
		return false;

	if (commandQueue.size() != 0 || !nextAction.isPast()) {
		if (commandQueue.size() == 0) {
			CommandQueueActionEvent* e = new CommandQueueActionEvent(_this);
			server->addEvent(e, nextAction);
		}
		commandQueue.add(action);
	} else {
		nextAction.update();
		activateQueueAction(action);

	}

	return true;
}

void PlayerImplementation::activateQueueAction(CommandQueueAction* action) {
	if (!isOnline()) {
		return;
	}

	if (nextAction.isFuture()) {
		Event* e = new CommandQueueActionEvent(_this);
		server->addEvent(e, nextAction);

		return;
	}

	if (action == NULL) {
		if (commandQueue.size() == 0)
			return;

		action = commandQueue.remove(0);
	}

	StringBuffer msg;
	msg << "activating action " << action->getSkill()->getSkillName() << " " << hex << "0x" << action->getActionCRC() << " ("
		<< action->getActionCounter() << ")";
	info(msg);

	//sendSystemMessage(msg.toString());

	CombatManager* combatManager = server->getCombatManager();

	if (!isIncapacitated() && !isDead()) {
		if (action->validate()) {
			float time = combatManager->handleAction(action);
			action->clear(time);
			uint64 ctime = nextAction.getMiliTime();

			nextAction.update();
			nextAction.addMiliTime((uint32) (time * 1000));
		} else {
			action->clearError(1, 19);
		}
	} else {
		action->clearError(1, 19);
	}

	delete action;

	activateRecovery();

	if (commandQueue.size() != 0) {
		Event* e = new CommandQueueActionEvent(_this);

		if (!nextAction.isFuture()) {
			nextAction.update();
			nextAction.addMiliTime(100);
		}

		server->addEvent(e, nextAction);
	}
}

void PlayerImplementation::clearQueueAction(uint32 actioncntr, float timer, uint32 tab1, uint32 tab2) {
	BaseMessage* queuemsg = new CommandQueueRemove(_this, actioncntr, timer, tab1, tab2);
	sendMessage(queuemsg);
}

void PlayerImplementation::deleteQueueAction(uint32 actioncntr) {
	for (int i = 0; i < commandQueue.size(); ++i) {
		CommandQueueAction* action = commandQueue.get(i);

		if (action->getActionCounter() == actioncntr) {
			commandQueue.remove(i);
			delete action;
			break;
		}
	}
}


//Deprecated
//Use incapacitate() and the event handlers.
void PlayerImplementation::doIncapacitate() {
	//TODO:Is this code ever executed ??
	//Please remove the above line if so...

	if (isRidingMount())
		dismount(true, true);

	clearCombatState();

	if (isDead())
		return;

	if (incapacitationCounter == 0) {
		firstIncapacitationTime.update();
		firstIncapacitationTime.addMiliTime(900000);
	} else if (incapacitationCounter != 0 && firstIncapacitationTime.isPast()) {
		incapacitationCounter = 0;
		firstIncapacitationTime.update();
		firstIncapacitationTime.addMiliTime(900000);
	}

	if (++incapacitationCounter < 3) {
		//TODO: Calculate incap time based on health.
		uint32 seconds = 10;
		sendIncapacitationTimer(10);

		clearStates();
		setPosture(CreaturePosture::INCAPACITATED);

		rescheduleRecovery(seconds * 1000);
	} else {
		if (firstIncapacitationTime.isFuture())
			die();
	}
}

void PlayerImplementation::changePosture(int post) {
	if (logoutEvent != NULL) {
		if (post == CreaturePosture::SITTING) {
			clearQueueAction(actionCounter);
			return;
		}

		sendSystemMessage("logout", "aborted"); //Your attempt to log out safely has been aborted.
		server->removeEvent(logoutEvent);
		delete logoutEvent;

		logoutEvent = NULL;
	}

	if (!getCanSample() && !getCancelSample()) {
		sendSystemMessage("You stop taking resource samples.");

		if (firstSampleEvent != NULL && firstSampleEvent->isQueued()) {
			server->removeEvent(firstSampleEvent);

			delete firstSampleEvent;
			firstSampleEvent = NULL;
		}

		if (sampleEvent != NULL) {
			uint64 time = -(sampleEvent->getTimeStamp().miliDifference());
			if (sampleEvent->isQueued())
				server->removeEvent(sampleEvent);

			delete sampleEvent;
			sampleEvent = NULL;

			String str = "";
			sampleEvent = new SampleEvent(_this, str, true);
			server->addEvent(sampleEvent, time);
			setCancelSample(true);
		}
	}

	if (isRidingMount())
		return;

	if (hasAttackDelay()) {
		clearQueueAction(actionCounter);
		return;
	}

	if (isMeditating()) {
		updateMood(Races::getMood(moodid));
		clearState(CreatureState::ALERT);
		updateStates();
		sendSystemMessage("teraskasi", "med_end");
	}

	if (foraging) {
		foraging = false;
		if (forageDelayEvent != NULL){
			if (forageDelayEvent->isQueued()) {
				server->removeEvent(forageDelayEvent);
			}
		}
	    sendSystemMessage("skl_use", "sys_forage_movefail");  //"You failed to forage because you moved.
	}

	if (isInCombat() && post == CreaturePosture::SITTING) {
		clearQueueAction(actionCounter);
		return;
	}

	if (isDizzied() && post == CreaturePosture::UPRIGHT) {
		if ((getSkillMod("combat_equillibrium") >> 1) > System::random(100)) {
			if (!dizzyFallDownEvent->isQueued())
				server->addEvent(dizzyFallDownEvent, 100);
			setPosture(post, true);
		} else {
			setPosture(CreaturePosture::KNOCKEDDOWN, true);
			sendSystemMessage("cbt_spam", "dizzy_fall_down_single");
		}
	} else
		setPosture(post);

	clearQueueAction(actionCounter);
}

void PlayerImplementation::activateRecovery() {
	if (recoveryEvent == NULL) {
		recoveryEvent = new PlayerRecoveryEvent(_this);

		server->addEvent(recoveryEvent, 3000);
	}
}

void PlayerImplementation::activateSaveStateEvent() {
	if (playerSaveStateEvent == NULL) {
		playerSaveStateEvent = new PlayerSaveStateEvent(_this);

		server->addEvent(playerSaveStateEvent);
	}
}

void PlayerImplementation::rescheduleSaveStateEvent(int time) {
	if ((playerSaveStateEvent != NULL) && playerSaveStateEvent->isQueued()) {
		server->removeEvent(playerSaveStateEvent);
	} else
		playerSaveStateEvent = new PlayerSaveStateEvent(_this);

	server->addEvent(playerSaveStateEvent, time);
}

void PlayerImplementation::rescheduleRecovery(int time) {
	if (recoveryEvent != NULL && recoveryEvent->isQueued()) {
		server->removeEvent(recoveryEvent);
	} else {
		recoveryEvent = new PlayerRecoveryEvent(_this);
	}

	server->addEvent(recoveryEvent, time);
}

/**
 * Action performed to recover from incapacitation.
 */
void PlayerImplementation::recoverFromIncapacitation() {
	setPosture(CreaturePosture::UPRIGHT);
	onIncapacitationRecovery();
	rescheduleRecovery(0);
	onIncapacitationRecovery();
}

void PlayerImplementation::doRecovery() {
	if (isLinkDead()) {
		if (logoutTimeStamp.isPast()) {
			info("unloading dead linked player");

			unload();

			setOffline();

			if (owner != NULL)
				owner->closeConnection(false);

			return;
		} else {
			info("keeping dead linked player in game");

			activateRecovery();
		}
	}

	if (isIncapacitated())
		recoverFromIncapacitation();

	//TODO: Redo this too.
	if (lastCombatAction.miliDifference() > 15000) {
		clearCombatState();
	} else if (isInCombat() && targetObject != NULL && !isPeaced()
			&& (commandQueue.size() == 0)) {
		queueAction(_this, getTargetID(), 0xA8FEF90A, ++actionCounter, ""); // Do default attack
	}

	//TODO: Redo this?
	if (!isOnFullHealth() || hasWounds() || hasShockWounds() || isPowerboosted())
		onRegenerateHAM();

	if (hasStates())
		doStateRecovery();

	if (isJedi())
		calculateForceRegen();

	activateRecovery();
}

void PlayerImplementation::doStateRecovery() {
	if (isDizzied() && dizzyRecoveryTime.isPast())
		clearState(CreatureState::DIZZY);

	if (isBlinded() && blindRecoveryTime.isPast())
		clearState(CreatureState::BLINDED);

	if (isStunned() && stunRecoveryTime.isPast())
		clearState(CreatureState::STUNNED);

	if (isIntimidated() && intimidateRecoveryTime.isPast())
		clearState(CreatureState::INTIMIDATED);

	if (isBerserked() && berserkRecoveryTime.isPast()) {
		clearState(CreatureState::BERSERK);
		setBerserkDamage(0);
	}

	if (isAiming() && aimRecoveryTime.isPast()) {
		clearState(CreatureState::AIMING);
	}

	applyDots();

	updateStates();
}

void PlayerImplementation::activateDigest() {
	if (digestEvent == NULL) {
		digestEvent = new PlayerDigestEvent(_this);

		server->addEvent(digestEvent, 18000);
	}
}

void PlayerImplementation::doDigest() {
	if (playerObject == NULL)
		return;

	if (!playerObject->isDigesting())
		return;

	if (playerObject->getFoodFilling() > 0)
		playerObject->changeFoodFilling(-1, true);

	if (playerObject->getDrinkFilling() > 0)
		playerObject->changeDrinkFilling(-1, true);

	activateDigest();
}

void PlayerImplementation::startForaging(int foragetype) {
	foraging = true;

	//Collect player's current position.
	forageX = getPositionX();
	forageY = getPositionY();
	foragePlanet = zone->getZoneID();

	//Queue the forage delay event.
	int delay = 8500;
	forageDelayEvent = new ForageDelayEvent(this, foragetype);
	server->addEvent(forageDelayEvent, delay);
}

void PlayerImplementation::finishForaging(int foragetype) {
    if (isLinkDead() || !isForaging())
    	return;

    foraging = false;

    //Check if player entered combat.
    if (isInCombat() || isDead() || isIncapacitated()) {
    	sendSystemMessage("skl_use", "sys_forage_combatfail"); //"Combat distracts you from your foraging attempt."
    	return;
    }

    //Check if player moved while foraging.
    bool success = forageMoveCheck(forageX, forageY, foragePlanet);
    if (success == false)
    	return;

    //Determine if player is allowed to forage in this area.
    success = forageZoneCheck(foragetype);
    if (success == false)
    	return;

    //Determine if player gets items.
    int forageMod;
    int myTickets;
    giveReg = 0;
    giveBonus = 0;

    if (foragetype == 0) {
    	forageMod = getSkillMod("foraging");
    	myTickets = (int)(25 + (forageMod * 0.75));

    	giveReg += lottery(myTickets, 99);
    	giveBonus = lottery(myTickets, 49999); //1 in 500 at +100 mod.

    	if (forageMod >= 25)
    		giveReg += lottery(myTickets, 2999);

    	if (forageMod >=50)
        	giveReg += lottery(myTickets, 2999);
    }

    if (foragetype == 1) {
    	forageMod = getSkillMod("medical_foraging");
    	myTickets = (int)(50 + (forageMod * 0.50));

    	giveReg += lottery(myTickets, 99);
        giveBonus = lottery(myTickets, 249999); //1 in 2500 at +100 mod.

        if (giveBonus == 1) {
        	giveBonus = 2; //Give 2 identical items with same serial number.
        	giveReg = 0;
        }
    }

    //Send success or fail message.
    if (giveReg > 0 || giveBonus > 0)
    	sendSystemMessage("skl_use", "sys_forage_success"); //"Your attempt at foraging was a success!"

    else {
       	sendSystemMessage("skl_use", "sys_forage_fail"); //"You failed to find anything worth foraging."
        return;
    }

    //Discard items if the player's inventory is full.
    success = discardForageItems();
    if (success == false)
        	return;

    //Give items to the player.
    giveForageItems(foragetype);
}

bool PlayerImplementation::forageMoveCheck(float startx, float starty, int startplanet) {
    int movementX = abs((int)getPositionX() - (int)startx);
    int movementY = abs((int)getPositionY() - (int)starty);

    if (movementX > 5 || movementY > 5 || zone->getZoneID() != startplanet || isRidingMount() || !isStanding()) {
    	sendSystemMessage("skl_use", "sys_forage_movefail"); //"You fail to forage because you moved."
    	return false;
    } else
    	return true;
}

bool PlayerImplementation::forageZoneCheck(int foragetype) {
	ForageZone* fZone;
	Vector<ForageZone*>* zoneContainer;
	int8 zoneStatus = -1;
	int8 authorized = -1;

	//Point to the correct forage zone container.
	if (foragetype == 0)
		zoneContainer = &forageZones;
	else
		zoneContainer = &medForageZones;

	//Check each zone for permission to forage.
	for (int i = 0; i < zoneContainer->size(); i++) {
		fZone = zoneContainer->get(i);
		zoneStatus = fZone->zonePermission(forageX, forageY, foragePlanet);

        if (zoneStatus == 0) { //Zone is time expired, delete.
            zoneContainer->remove(i);
            i -= 1; //Indexes shift down 1 when deleting an element, compensate.
        }

        //If zoneStatus == 1, player is not in the zone but it's not expired, so ignore it.

        if (zoneStatus == 2) { //Player is in this zone but was allowed to forage.
        	authorized = i; //Remember which zone gave permission.
        }

        if (zoneStatus == 3) { //Player is not allowed to forage in this zone, deny.
        	sendSystemMessage("skl_use", "sys_forage_empty"); //"There is nothing in this area to forage."
        	return false;
        }
    }

	//Check if a zone gave permission to forage.
    if (authorized != -1) { //A zone gave permission to forage.
    	fZone = zoneContainer->get(authorized);
    	fZone->uses += 1; //Add 1 use to the last zone to allow forage (zones can overlap).

    } else { //Player is not in any zones, so make a new one.
    	if (zoneContainer->size() == 20) { //Determines how many zones to remember.
    		zoneContainer->remove(0); //If at capacity, delete the oldest zone.
    	}

    	ForageZone* newZone = new ForageZone(forageX, forageY, foragePlanet);
    	zoneContainer->add(newZone);
    }
    return true;
}

int PlayerImplementation::lottery(int mytickets, int totaltickets) {
	int target = totaltickets - mytickets;
    int randomNum = System::random(totaltickets);

    if (randomNum > target)
    	return 1; //Win.
    else
    	return 0; //Lose.
}

bool PlayerImplementation::discardForageItems() {
    Inventory* inventory = getInventory();

    int inventoryRoom = InventoryImplementation::MAXUNEQUIPPEDCOUNT - inventory->getUnequippedItemCount();

    if (inventoryRoom < 1) {
        sendSystemMessage("skl_use", "sys_forage_noroom"); //"Some foraged items were discarded, because your inventory is full."
 	    return false;
    }

    int itemCount = giveReg + giveBonus;
    int drop = itemCount - inventoryRoom;

    if (drop > 0) {
        sendSystemMessage("skl_use", "sys_forage_noroom");

        while (drop > 0) {
               if (giveReg == 0) break;
               giveReg -= 1;
               drop -= 1;
        }

        while (drop > 0) {
               if (giveBonus == 0) break;
               giveBonus -= 1;
               drop -= 1;
        }
    }
    return true;
}

void PlayerImplementation::giveForageItems(int foragetype) {
	ItemManager* itemManager = getZone()->getZoneServer()->getItemManager();
	ResourceManager* resourceManager = getZone()->getZoneServer()->getResourceManager();

    if (foragetype == 0) {
    		itemManager->giveForageItem(_this, 1, giveReg); //basic forage items.

        if (giveBonus == 1)
        	itemManager->giveForageItem(_this, 2, 1); //rare forage item.
    }

    if (foragetype == 1) {
        if (giveReg == 1) {
	    	int randnum = System::random(99);

	    	if (randnum < 25) { //Give food.
	    		itemManager->giveForageItem(_this, 3, 1); //medicalforage food.
	    		return;
	    	}
	    	if (randnum < 50) { //Give resource.
                resourceManager->giveForageResource(_this, forageX, forageY, foragePlanet);
	    		return;
	        }

	    	if (randnum < 100) { //Give component.
	    		randnum = System::random(99);
	    		if (randnum < 85) {
	    			itemManager->giveForageItem(_this, 4, 1); //basic component.
	    		} else {
	    			itemManager->giveForageItem(_this, 5, 1); //advanced component.
	    		}
	    		return;
	    	}
        }

    	if (giveBonus > 0) //Give rare components.
    		itemManager->giveForageItem(_this, 6, giveBonus); //exceptional component.
    }
}

bool PlayerImplementation::doPowerboost() {
	uint32 pbCRC = 0x8C2221CB; //powerboost
	PowerboostSelfSkill* skill = (PowerboostSelfSkill*)creatureSkills.get(pbCRC); //Get the Powerboost skill.

	//Check if already powerboosted.
	if (powerboosted) {
		sendSystemMessage("teraskasi", "powerboost_active"); //"[meditation] You are unable to channel your energies any further."
		return false;
	}

    //Make sure player is meditating.
	if (!isMeditating()) {
		sendSystemMessage("teraskasi", "powerboost_fail"); //"You must be meditating to perform that command."
		return false;
	}

	//Check if player has enough mind.
	float bonus = skill->getBonus();
	int availableMind = getMindMax() - getMindWounds();
    if (availableMind <= getBaseMind() * bonus) {
    	sendSystemMessage("teraskasi", "powerboost_mind"); //"[meditation] You currently lack the mental capacity to focus your energies."
    	return false;
    }

	//Calculate duration.
	int meditateMod = getSkillMod("meditate");
	int duration = 300000 + (3000 * meditateMod);

    //Start Powerboost.
    powerboosted = true;
	sendSystemMessage("teraskasi", "powerboost_begin"); //"[meditation] You focus your energies into your physical form."

	//Queue the wane event.
	if (powerboostEventWane != NULL) {
		if (powerboostEventWane->isQueued()) {
			server->removeEvent(powerboostEventWane);
		}
	} else {
		powerboostEventWane = new PowerboostEventWane(_this, skill);
	}

	server->addEvent(powerboostEventWane, duration);

	return true;
}

void PlayerImplementation::removePowerboost() {
	if (powerboostEventWane != NULL) {
		if (powerboostEventWane->isQueued()) {
			server->removeEvent(powerboostEventWane);
		}

		delete powerboostEventWane;
		powerboostEventWane = NULL;
	}

	if (!powerboosted)
		return;

	CreatureObject* creature = (CreatureObject*)_this;
	creature->removePowerboost();

	powerboosted = false;
}

void PlayerImplementation::doCenterOfBeing() {
	if (centered) {
		sendSystemMessage("combat_effects", "already_centered");
		return;
	}

	int duration = 0;
	int efficacy = 0;

	if (weaponObject == NULL) {
		duration = getSkillMod("center_of_being_duration_unarmed");
		efficacy = getSkillMod("unarmed_center_of_being_efficacy");
	} else {
		switch (weaponObject->getType()) {
		case WeaponImplementation::UNARMED:
			duration = getSkillMod("center_of_being_duration_unarmed");
			efficacy = getSkillMod("unarmed_center_of_being_efficacy");
			break;

		case WeaponImplementation::ONEHANDED:
			duration = getSkillMod("center_of_being_duration_onehandmelee");
			efficacy = getSkillMod("onehandmelee_center_of_being_efficacy");
			break;

		case WeaponImplementation::TWOHANDED:
			duration = getSkillMod("center_of_being_duration_twohandmelee");
			efficacy = getSkillMod("twohandmelee_center_of_being_efficacy");
			break;

		case WeaponImplementation::POLEARM:
			duration = getSkillMod("center_of_being_duration_polearm");
			efficacy = getSkillMod("polearm_center_of_being_efficacy");
			break;
		default:
			break;
		}
	}

	if (duration == 0 || efficacy == 0)
		return;

	//defenseBonus += efficacy;
	centeredBonus = efficacy;

	sendSystemMessage("combat_effects", "center_start");
	showFlyText("combat_effects", "center_start_fly", 0, 255, 0);

	server->addEvent(centerOfBeingEvent, duration * 1000);

	centered = true;
}

void PlayerImplementation::removeCenterOfBeing() {
	if (!centered)
		return;

	server->removeEvent(centerOfBeingEvent);

	//defenseBonus -= centeredBonus;
	centeredBonus = 0;

	sendSystemMessage("combat_effects", "center_stop");
	showFlyText("combat_effects", "center_stop_fly", 255, 0, 0);
	centered = false;
}

void PlayerImplementation::doPeace() {
	//info("trying Peace action");

	for (int i = 0; i < defenderList.size(); ++i) {
		ManagedReference<SceneObject> defender = defenderList.get(i);

		try {
			defender->wlock(_this);

			if (defender->hasDefender(_this)) {
				if (defender->isPeaced()) {
					removeDefender(defender);
					defender->removeDefender(_this);

					i--;
				}
			} else {
				removeDefender(defender);
				i--;
			}

			defender->unlock();

		} catch (...) {
			error("unknown exception in PlayerImplementation::doPeace()\n");
			defender->unlock();
		}

	}

	if (defenderList.size() != 0) {
		//info("defenderList not empty, trying to set Peace State");

		if (setState(CreatureState::PEACE))
			updateStates();
	}

	//info("finished doPeace");
}

void PlayerImplementation::lootCorpse(bool lootAll) {
	if (targetObject == NULL || !targetObject->isNonPlayerCreature())
		return;

	Creature* target = (Creature*) targetObject.get();

	if (target->isMount())
		return;

	if (!isIncapacitated() && !isDead() && isInRange(target, 20)) {
		LootManager* lootManager = server->getLootManager();

		if (lootAll)
			lootManager->lootCorpse(_this, target);
		else
			lootManager->showLoot(_this, target);
	}
}

void PlayerImplementation::lootObject(Creature* creature, SceneObject* object) {
	if (creature->isMount())
		return;

	LootManager* lootManager = server->getLootManager();

	lootManager->lootObject(_this, creature, object->getObjectID());
}

void PlayerImplementation::checkForceStatus() {
	switch (forceStatus) {
	case (0):
		sendSystemMessage("jedi_spam", "fs_progress_0");
		break;
	case (1):
		sendSystemMessage("jedi_spam", "fs_progress_1");
		break;
	case (2):
		sendSystemMessage("jedi_spam", "fs_progress_2");
		break;
	case (3):
		sendSystemMessage("jedi_spam", "fs_progress_3");
		break;
	case (4):
		sendSystemMessage("jedi_spam", "fs_progress_4");
		break;
	case (5):
		sendSystemMessage("jedi_spam", "fs_progress_5");
		break;
	default:
		sendSystemMessage("jedi_spam", "fs_progress_0");
		break;
	}
}

void PlayerImplementation::calculateForceRegen() {
	if (isJedi() && !playerObject->isOnFullForce()) {
		if (getPosture() == CreaturePosture::SITTING)
			changeForcePowerBar(playerObject->getForceRegen()); // probably shouldn't be here *shrug*
		else // 3 second tick do a full regen every 10 secs ish
			changeForcePowerBar( (int)((playerObject->getForceRegen() / 3.0) + .5));
	}
}

bool PlayerImplementation::changeForcePowerBar(int32 fp) {
	int32 newForce = playerObject->getForcePower() + fp;

	if (newForce <= 0)
		return false;

	setForcePowerBar(MIN(newForce, playerObject->getForcePowerMax()));

	if (fp < 0)
		activateRecovery();

	return true;
}

void PlayerImplementation::addBuff(uint32 buffcrc, float time) {
	Buffs* bf = new Buffs(_this, buffcrc, time);
	sendMessage(bf);
}

void PlayerImplementation::clearBuffs(bool doUpdatePlayer) {
	removeBuffs(doUpdatePlayer);
}

/*
*
*		GM METHODS
*
*/
void PlayerImplementation::mutePlayer() {
	chatMuted = !chatMuted;
}

void PlayerImplementation::toggleImmune() {
	if (isInvisible()){
		sendSystemMessage("You can't disable immune while invisible.");
		return;
	}

	if (!immune) {
		clearDuelList();
		clearCombatState();
		setPvpStatusBitmask(0);
		sendSystemMessage("You are now immune to attacks.");
	} else {
		setPvpStatusBitmask(CreatureFlag::PLAYER);
		sendSystemMessage("You are no longer immune to attacks.");
	}

	immune = !immune;

	UpdatePVPStatusMessage * mess = new UpdatePVPStatusMessage(this, pvpStatusBitmask);
	broadcastMessage(mess);
}

void PlayerImplementation::activateInvisible() {
	if (getZoneID() > 9) {
		sendSystemMessage("You can't toggle invisible in this zone.");
		return;
	}

	if (isInvisible() && isRidingMount()) {
		sendSystemMessage("You can't become visible while mounted.");
		return;
	}

	if (invisibleDelayEvent->isQueued()) {
		sendSystemMessage("You can't toggle invisibility this often.");
		return;
	}

	PlayClientEffectLoc* effect = new PlayClientEffectLoc("clienteffect/pl_force_resist_disease_self.cef", zone->getZoneID(), getPositionX(), getPositionZ(), getPositionY());
	broadcastMessage(effect);
	server->addEvent(invisibleDelayEvent, 1700);
}

void PlayerImplementation::toggleInvisible() {
	if (!isInvisible()) {

		try {
			zone->lock(true);

			for (int i = 0; i < inRangeObjectCount(); ++i) {
				QuadTreeEntry* obj = getInRangeObject(i);
				SceneObject* scno = (SceneObject*) (((SceneObjectImplementation*) obj)->_getStub());

				if (obj != this && scno->isPlayer()) {
					obj->notifyDissapear(this);
				}
			}

			zone->unlock(true);
		} catch (...) {
			System::out << "Unreported exception in PlayerImplementation::toggleInvisible().\n";
			zone->unlock(true);
		}

		sendSystemMessage("You are now invisible to other players. They WILL NOT see your spatial chat or emotes!");
		sendSystemMessage("DO NOT change your equipped items while invisible!");

		if (!isImmune())
			toggleImmune();

		invisible = true;

	} else {
		invisible = false;

		try {
			zone->lock();

	    	for (int i = 0; i < inRangeObjectCount(); ++i) {
				QuadTreeEntry* obj = getInRangeObject(i);

				if (obj != this) {
					obj->notifyInsert(this);
				}
			}

			zone->unlock();
		} catch (...) {
			error("Unreported exception in PlayerImplementation::toggleInvisible().\n");

			zone->unlock();
		}

		sendSystemMessage("You are now visible to other players.");
		if (isImmune())
			toggleImmune();
	}
}


/*
 *	Item manipulation methods
 */

void PlayerImplementation::addInventoryItem(TangibleObject* item) {

	CreatureObjectImplementation::addInventoryItem(item);

	if (item->isEquipped())
		equipPlayerItem(item);

}

void PlayerImplementation::addInventoryResource(ResourceContainer* item) {

	CreatureObjectImplementation::addInventoryResource(item);
}

void PlayerImplementation::equipPlayerItem(TangibleObject* item, bool updateLevel) {
	if(item->isEquipped())
		item->setEquipped(false);

	if (item->isInstrument() || item->isWeapon())
		changeWeapon(item->getObjectID(), updateLevel);
	else {
		if (equippedItems == NULL)
			return;

		equippedItems->equipItem(item);
	}
}

bool PlayerImplementation::hasItemPermission(TangibleObject * item) {
	uint16 maskRes = ~(item->getPlayerUseMask()) & characterMask;

	if (maskRes == 0)
		return true;

	//suppress system message if item is being taken off.
	if (item->isEquipped())
		return false;

	if (maskRes == COVERT) {
		this->sendSystemMessage("You can not use this item while on leave.");
		return false;
	} else if (maskRes & (COVERT | REBEL | IMPERIAL | NEUTRAL)) {
		this->sendSystemMessage("You are not the proper faction to use this item.");
		return false;
	} else if (maskRes & 0x0FFC) {
		this->sendSystemMessage("Your species can not use this item.");
		return false;
	} else if (maskRes & (MALE | FEMALE)) {
		this->sendSystemMessage("This item is not appropriate for your gender.");
		return false;
	}

	//should never get here
	this->sendSystemMessage("There was an error, while trying to equip this item.");
	return false;
}

void PlayerImplementation::changeCloth(uint64 itemid) {
	changeArmor(itemid, false);
}

void PlayerImplementation::changeWeapon(uint64 itemid, bool updateLevel) {
	ManagedReference<SceneObject> obj = inventory->getObject(itemid);

	if (obj == NULL || !obj->isTangible())
		return;

	if (!((TangibleObject*)obj.get())->isWeapon() && !((TangibleObject*)obj.get())->isInstrument())
		return;

	TangibleObject* item = (TangibleObject*)obj.get();

	equippedItems->changeWeapon(item);

	Weapon* weapon = NULL;

	if (equippedItems->getInstrument() != NULL)
		return;
	else if (equippedItems->getWeapon() != NULL)
		weapon = equippedItems->getWeapon();

	setWeapon(weapon);

	if (centered)
		removeCenterOfBeing();

	setPlayerLevel(updateLevel);
}

void PlayerImplementation::setPlayerLevel(bool updateLevel) {
	int playerlevel;

	if (getWeapon() == NULL)
		playerlevel = calcPlayerLevel("combat_meleespecialize_unarmed");
	else
		playerlevel = calcPlayerLevel(getWeapon()->getXpType());

	if (calcPlayerLevel("medical") > playerlevel)
		setLevel(calcPlayerLevel("medical"));
	else
		setLevel(playerlevel);

	if (isInAGroup()) {
		getGroupObject()->calcGroupLevel();
		GroupObjectDeltaMessage6* grp = new GroupObjectDeltaMessage6(getGroupObject());
		grp->updateLevel(getGroupObject()->getGroupLevel());
		grp->close();

		broadcastMessage(grp);
	}

	if (updateLevel) {
		CreatureObjectDeltaMessage6* dcreo6 = new CreatureObjectDeltaMessage6(_this);
		if (isInAGroup()) {
			dcreo6->updateLevel(getGroupObject()->getGroupLevel());
		} else {
			dcreo6->updateLevel(getLevel());
		}
		dcreo6->close();

		broadcastMessage(dcreo6);
	}
}

void PlayerImplementation::setWeaponAccuracy(Weapon* weapon) {
	if (weapon == NULL) {
		accuracy = getSkillMod("unarmed_accuracy");
		return;
	}

	switch (weapon->getType()) {
		case WeaponImplementation::UNARMED:
			accuracy = getSkillMod("unarmed_accuracy");
			break;

		case WeaponImplementation::ONEHANDED:
			accuracy = getSkillMod("onehandmelee_accuracy");
			break;

		case WeaponImplementation::TWOHANDED:
			accuracy = getSkillMod("twohandmelee_accuracy");
			break;

		case WeaponImplementation::POLEARM:
			accuracy = getSkillMod("polearm_accuracy");
			break;

		case WeaponImplementation::PISTOL:
			accuracy = getSkillMod("pistol_accuracy");
			break;

		case WeaponImplementation::CARBINE:
			accuracy = getSkillMod("carbine_accuracy");
			break;

		case WeaponImplementation::RIFLE:
			accuracy = getSkillMod("rifle_accuracy");
			break;

		case WeaponImplementation::HEAVYWEAPON:
			accuracy = getSkillMod("heavyweapon_accuracy");
			break;

		case WeaponImplementation::RIFLEFLAMETHROWER:
			accuracy = getSkillMod("heavy_flame_thrower_accuracy") + getSkillMod("heavyweapon_accuracy");
			break;

		case WeaponImplementation::RIFLELIGHTNING:
			accuracy = getSkillMod("heavy_rifle_lightning_accuracy") + getSkillMod("heavyweapon_accuracy");
			break;

		case WeaponImplementation::RIFLEACIDBEAM:
			accuracy = getSkillMod("heavy_rifle_acid_accuracy") + getSkillMod("heavyweapon_accuracy");
			break;

		case WeaponImplementation::ONEHANDSABER:
			accuracy = getSkillMod("onehandlightsaber_accuracy");
			break;

		case WeaponImplementation::TWOHANDSABER:
			accuracy = getSkillMod("twohandlightsaber_accuracy");
			break;

		case WeaponImplementation::POLEARMSABER:
			accuracy = getSkillMod("polearmlightsaber_accuracy");
			break;
	}

}

void PlayerImplementation::changeArmor(uint64 itemid, bool forced) {
	ManagedReference<SceneObject> obj = inventory->getObject(itemid);

	if (obj == NULL || !obj->isTangible())
		return;

	if (!((TangibleObject*)obj.get())->isArmor()
			&& !((TangibleObject*)obj.get())->isClothing()
			&& !((TangibleObject*)obj.get())->isWearableContainer())
		return;

	Wearable* cloth = (Wearable*) obj.get();

	if (equippedItems == NULL) {
		System::out << "ERROR - equippedItems not initialised" << endl;
		return;
	}
	equippedItems->changeWearable(cloth, forced);

	BaseMessage* creo6 = new CreatureObjectMessage6(_this);
	BaseMessage* creo4 = new CreatureObjectMessage4(this);

	sendMessage(creo6);
	sendMessage(creo4);
}

void PlayerImplementation::setItemSkillMod(int type, int value) {
	switch (type) {
	case 1:
		addSkillModBonus("melee_defense", value, true);
		break;
	case 2:
		addSkillModBonus("ranged_defense", value, true);
		break;
	case 3:
		addSkillModBonus("stun_defense", value, true);
		break;
	case 4:
		addSkillModBonus("dizzy_defense", value, true);
		break;
	case 5:
		addSkillModBonus("blind_defense", value, true);
		break;
	case 6:
		addSkillModBonus("knockdown_defense", value, true);
		break;
	case 7:
		addSkillModBonus("intimidate_defense", value, true);
		break;
	case 8:
		addSkillModBonus("pistol_speed", value, true);
		break;
	case 9:
		addSkillModBonus("carbine_speed", value, true);
		break;
	case 10:
		addSkillModBonus("rifle_speed", value, true);
		break;
	case 11:
		addSkillModBonus("unarmed_speed", value, true);
		break;
	case 12:
		addSkillModBonus("onehandmelee_speed", value, true);
		break;
	case 13:
		addSkillModBonus("twohandmelee_speed", value, true);
		break;
	case 14:
		addSkillModBonus("polearm_speed", value, true);
		break;
	case 15:
		addSkillModBonus("pistol_accuracy", value, true);
		break;
	case 16:
		addSkillModBonus("carbine_accuracy", value, true);
		break;
	case 17:
		addSkillModBonus("rifle_accuracy", value, true);
		break;
	case 18:
		addSkillModBonus("unarmed_accuracy", value, true);
		break;
	case 19:
		addSkillModBonus("onehandmelee_accuracy", value, true);
		break;
	case 20:
		addSkillModBonus("twohandmelee_accuracy", value, true);
		break;
	case 21:
		addSkillModBonus("polearm_accuracy", value, true);
		break;
	case 22:
		addSkillModBonus("dodge", value, true);
		break;
	case 23:
		addSkillModBonus("block", value, true);
		break;
	case 24:
		addSkillModBonus("counterattack", value, true);
		break;
	case 25:
		addSkillModBonus("resistance_bleeding", value, true);
		break;
	case 26:
		addSkillModBonus("resistance_disease", value, true);
		break;
	case 27:
		addSkillModBonus("resistance_fire", value, true);
		break;
	case 28:
		addSkillModBonus("resistance_poison", value, true);
		break;
	case 29:
		addSkillModBonus("slope_move", value, true);
		break;
	case 30:
		addSkillModBonus("heavyweapon_speed", value, true);
		break;
	case 31:
		addSkillModBonus("heavyweapon_accuracy", value, true);
		break;
	}
}
//TODO: never used ? delete
void PlayerImplementation::setWeaponSkillMods(Weapon* weapon) {
	switch (weapon->getType()) {
		case WeaponImplementation::UNARMED:
			accuracy = getSkillMod("unarmed_accuracy");
			break;

		case WeaponImplementation::ONEHANDED:
			accuracy = getSkillMod("onehandmelee_accuracy");
			break;

		case WeaponImplementation::TWOHANDED:
			accuracy = getSkillMod("twohandmelee_accuracy");
			break;

		case WeaponImplementation::POLEARM:
			accuracy = getSkillMod("polearm_accuracy");
			break;

		case WeaponImplementation::PISTOL:
			accuracy = getSkillMod("pistol_accuracy");
			break;

		case WeaponImplementation::CARBINE:
			accuracy = getSkillMod("carbine_accuracy");
			break;

		case WeaponImplementation::RIFLE:
			accuracy = getSkillMod("rifle_accuracy");
			break;

		case WeaponImplementation::HEAVYWEAPON:
			accuracy = getSkillMod("heavyweapon_accuracy");
			break;

		case WeaponImplementation::RIFLEFLAMETHROWER:
			accuracy = getSkillMod("heavy_flame_thrower_accuracy") + getSkillMod("heavyweapon_accuracy");
			break;

		case WeaponImplementation::RIFLELIGHTNING:
			accuracy = getSkillMod("heavy_rifle_lightning_accuracy") + getSkillMod("heavyweapon_accuracy");
			break;

		case WeaponImplementation::RIFLEACIDBEAM:
			accuracy = getSkillMod("heavy_rifle_acid_accuracy") + getSkillMod("heavyweapon_accuracy");
			break;

		/*case Weapon::ONEHANDSABER:
			accuracy = SkillMods.get("");
			break;

		case Weapon::TWOHANDSABER:
			accuracy = SkillMods.get("");
			break;

		case Weapon::POLEARMSABER:
			accuracy = SkillMods.get("");
			break;*/
	}
	weapon->onEquip(_this);

	if (checkCertification(weapon->getCert())) {
		weapon->setCertified(true);
	} else {
		sendSystemMessage("You are not certified to use this weapon. Damage will be reduced.");
		weapon->setCertified(false);
	}
}
//TODO: never used ? delete
void PlayerImplementation::unsetWeaponSkillMods(Weapon* weapon) {
	weapon->onUnequip(_this);

	accuracy = getSkillMod("unarmed_accuracy");
}

bool PlayerImplementation::setArmorEncumbrance(Armor* armor, bool forced) {
	int healthEncumb = armor->getHealthEncumbrance();
	int actionEncumb = armor->getActionEncumbrance();
	int mindEncumb = armor->getMindEncumbrance();

	if ((healthEncumb >= getStrength() || healthEncumb >= getConstitution() ||
		actionEncumb >= getQuickness() || actionEncumb >= getStamina() ||
		mindEncumb >= getFocus() || mindEncumb >= getWillpower()) && !forced)
		return false;

	if ((getStrength() > 100000 || getConstitution() > 100000 ||
		getQuickness() > 100000 || getStamina() > 100000 ||
		getFocus() > 100000 || getWillpower() > 100000) && !forced)
		return false;

	healthEncumbrance += healthEncumb;
	actionEncumbrance += actionEncumb;
	mindEncumbrance += mindEncumb;

	changeStrengthMax(-healthEncumb);
	changeConstitutionMax(-healthEncumb);
	changeQuicknessMax(-actionEncumb);
	changeStaminaMax(-actionEncumb);
	changeFocusMax(-mindEncumb);
	changeWillpowerMax(-mindEncumb);

	changeStrength(-healthEncumb);
	changeConstitution(-healthEncumb);
	changeQuickness(-actionEncumb);
	changeStamina(-actionEncumb);
	changeFocus(-mindEncumb);
	changeWillpower(-mindEncumb);

	return true;

}

void PlayerImplementation::unsetArmorEncumbrance(Armor* armor) {
	int healthEncumb = armor->getHealthEncumbrance();
	int actionEncumb = armor->getActionEncumbrance();
	int mindEncumb = armor->getMindEncumbrance();

	healthEncumbrance -= healthEncumb;
	actionEncumbrance -= actionEncumb;
	mindEncumbrance -= mindEncumb;

	changeStrengthMax(healthEncumb);
	changeConstitutionMax(healthEncumb);
	changeQuicknessMax(actionEncumb);
	changeStaminaMax(actionEncumb);
	changeFocusMax(mindEncumb);
	changeWillpowerMax(mindEncumb);

	changeStrength(healthEncumb);
	changeConstitution(healthEncumb);
	changeQuickness(actionEncumb);
	changeStamina(actionEncumb);
	changeFocus(mindEncumb);
	changeWillpower(mindEncumb);
}

void PlayerImplementation::applyPowerup(uint64 powerupID, uint64 targetID) {
	SceneObject* invObj = getInventoryItem(powerupID);
	if (invObj == NULL || !invObj->isTangible())
		return;

	TangibleObject* tano = (TangibleObject*) invObj;
	if (!tano->isWeaponPowerup())
		return;

	Powerup* powerup = (Powerup*) tano;

	invObj = getInventoryItem(targetID);
	if (invObj == NULL || !invObj->isTangible())
		return;

	tano = (TangibleObject*) invObj;
	if (!tano->isWeapon())
		return;

	Weapon* weapon = (Weapon*) tano;

	weapon->wlock(_this);

	powerup->wlock(_this);

	if (weapon->getPowerupUses() == 0) {
		StringBuffer msg;
		msg << "You powerup your " << weapon->getCustomName().toString() << " with " << powerup->getCustomName().toString();
		sendSystemMessage(msg.toString());

		powerup->apply(weapon);

		powerup->remove(_this);

		powerup->unlock();
		powerup->finalize();

		weapon->unlock();

		return;
	} else {
		sendSystemMessage("This weapon is already powered up!");

		powerup->unlock();

		weapon->unlock();
	}
}


void PlayerImplementation::applyAttachment(uint64 attachmentID, uint64 targetID) {
	ManagedReference<SceneObject> invObj = getInventoryItem(attachmentID);

	if (invObj == NULL || !invObj->isTangible())
		return;

	ManagedReference<TangibleObject> tano = (TangibleObject*) invObj.get();

	if (!tano->isAttachment())
		return;

	ManagedReference<Attachment> attachment = (Attachment*) tano.get();

	invObj = getInventoryItem(targetID);

	if (invObj == NULL || !invObj->isTangible())
		return;

	tano = (TangibleObject*) invObj.get();

	if (tano->isArmor() || tano->isClothing()) {

		ManagedReference<Wearable> wearable = (Wearable*) tano.get();

		if(wearable == NULL)
			return;

		try {

			wearable->wlock();
			attachment->wlock();

			wearable->applyAttachment(_this, attachment);

			attachment->unlock();
			wearable->unlock();

		} catch (...) {

			attachment->unlock();
			wearable->unlock();

		}
	}
}

void PlayerImplementation::setOvert() {
	if (!(pvpStatusBitmask & CreatureFlag::OVERT))
		pvpStatusBitmask |= CreatureFlag::OVERT;

	if (pvpStatusBitmask & CreatureFlag::CHANGEFACTIONSTATUS)
		pvpStatusBitmask -= CreatureFlag::CHANGEFACTIONSTATUS;

	characterMask &= ~COVERT;

	factionStatus = 2;

	uint32 pvpBitmask = pvpStatusBitmask;

	sendSystemMessage("faction_recruiter", "overt_complete");

	try {
		zone->lock();

		for (int i = 0; i < inRangeObjectCount(); ++i) {
			SceneObject* object = (SceneObject*) (((SceneObjectImplementation*) getInRangeObject(i))->_getStub());

			if (object->isPlayer()) {
				Player* player = (Player*) object;
				sendFactionStatusTo(player, true);
			} else if (object->isNonPlayerCreature()) {
				CreatureObjectImplementation * npc = (CreatureObjectImplementation *) object->_getImplementation();
				npc->sendFactionStatusTo(_this);
			}
		}

		zone->unlock();
	} catch (...) {
		error("exception Player::setOvert()");
		zone->unlock();
	}
}

void PlayerImplementation::setCovert() {
	if (pvpStatusBitmask & CreatureFlag::OVERT)
		pvpStatusBitmask -= CreatureFlag::OVERT;

	if (pvpStatusBitmask & CreatureFlag::CHANGEFACTIONSTATUS)
		pvpStatusBitmask -= CreatureFlag::CHANGEFACTIONSTATUS;

	characterMask |= COVERT;

	factionStatus = 1;

	sendSystemMessage("faction_recruiter", "covert_complete");

	try {
		zone->lock();

		for (int i = 0; i < inRangeObjectCount(); ++i) {
			SceneObject* object = (SceneObject*) (((SceneObjectImplementation*) getInRangeObject(i))->_getStub());

			if (object->isPlayer()) {
				Player* player = (Player*) object;
				sendFactionStatusTo(player, true);
			} else if (object->isNonPlayerCreature()) {
				CreatureObjectImplementation * npc = (CreatureObjectImplementation *) object->_getImplementation();
				npc->sendFactionStatusTo(_this);
			}
		}

		zone->unlock();
	} catch (...) {
		error("exception PlayerImplementation::setCovert()");
		zone->unlock();
	}
}

void PlayerImplementation::setOnLeave() {
	if (pvpStatusBitmask & CreatureFlag::OVERT)
		pvpStatusBitmask -= CreatureFlag::OVERT;

	if (pvpStatusBitmask & CreatureFlag::CHANGEFACTIONSTATUS)
		pvpStatusBitmask -= CreatureFlag::CHANGEFACTIONSTATUS;

	if (faction != 0)
		characterMask |= COVERT;

	factionStatus = 0;

	if (faction != 0)
		sendSystemMessage("faction_recruiter", "on_leave_complete");

	try {
		zone->lock();

		for (int i = 0; i < inRangeObjectCount(); ++i) {
			SceneObject* object = (SceneObject*) (((SceneObjectImplementation*) getInRangeObject(i))->_getStub());

			if (object->isPlayer()) {
				Player* player = (Player*) object;
				sendFactionStatusTo(player, true);
			} else if (object->isNonPlayerCreature()) {
				CreatureObjectImplementation * npc = (CreatureObjectImplementation *) object->_getImplementation();
				npc->sendFactionStatusTo(_this);
			}
		}

		zone->unlock();
	} catch (...) {
		error("exception PlayerImplementation::setOnLeave()");
		zone->unlock();
	}
}

void PlayerImplementation::setLinkDead() {
	onlineStatus = LINKDEAD;

	if (playerObject != NULL)
		playerObject->setCharacterBit(PlayerObjectImplementation::LD, true);

	logoutTimeStamp.update();
	logoutTimeStamp.addMiliTime(30000);

	activateRecovery();
}

void PlayerImplementation::setOnline() {
	if (isLinkDead()) {
		if (playerObject != NULL)
			playerObject->clearCharacterBit(PlayerObjectImplementation::LD, true);
	}

	onlineStatus = ONLINE;
}

void PlayerImplementation::setOffline() {
	if(isLinkDead()) {
		if (playerObject != NULL)
			playerObject->clearCharacterBit(PlayerObjectImplementation::LD, true);
	}

	onlineStatus = OFFLINE;
}

bool PlayerImplementation::isInDuelWith(Player* targetPlayer, bool doLock) {
	if (_this == targetPlayer)
		return false;

	try {
		if (doLock)
			targetPlayer->wlock(_this);

		bool res;
		if (requestedDuelTo(targetPlayer) && targetPlayer->requestedDuelTo(_this))
			res = true;
		else
			res = false;

		if (doLock)
			targetPlayer->unlock();

		return res;
	} catch (...) {
		if (doLock)
			targetPlayer->unlock();

		return false;
	}
}

void PlayerImplementation::addToDuelList(Player* targetPlayer) {
	if (duelList.put(targetPlayer) != -1)
		info("player [" + targetPlayer->getLoggingName() + "] added to duel list");
	else
		error("player [" + targetPlayer->getLoggingName() + "] was already in duel list");

}

void PlayerImplementation::removeFromDuelList(Player* targetPlayer) {
	if (duelList.drop(targetPlayer))
		info("player [" + targetPlayer->getLoggingName() + "] removed from duel list");
	else
		error("player [" + targetPlayer->getLoggingName() + "] was not found in duel list for removal");
}

void PlayerImplementation::clearDuelList() {
	if (zone != NULL) {
		CombatManager* combatManager = server->getCombatManager();
		combatManager->freeDuelList(_this);
	}
}

// Mission Functions
bool PlayerImplementation::isOnCurMisoKey(const String& tmk) {
	if (curMisoKeys.indexOf(tmk) >= 0)
		return true;
	else
		return false;
}

bool PlayerImplementation::hasCompletedMisoKey(const String& tmk) {
	if (finMisoKeys.indexOf(tmk) >= 0)
		return true;
	else
		return false;
}

//Called by the mission manager when a new mission is added
void PlayerImplementation::addMission(const String& key, MissionObject* miso) {
	curMisoKeys += (key + ",");
	missionMap.put(key, miso);
}

/**
 * Runs through all missions notifying the objectives within those missions of special
 * tracked events like a kill, player death etc
 */
void PlayerImplementation::updateMissions(int type, uint32 objCrc, const String& str, int increment) {
	for(int i = 0; i < missionMap.size(); i++) {
		MissionObject* mo = missionMap.get(i);
		if(mo != NULL) {
			if(!mo->isComplete()) {
				String updateStr = "";
				// If objective update completes, send the player a friendly notification
				int ret = mo->updateStatus(type, objCrc, str, updateStr, increment);
				if(ret >= 1) {
					if(ret == 1) { // Progress Update
						if(updateStr.length() > 0)
							_this->sendSystemMessage(updateStr);
					} else { // Instant Complete
						MissionManager* mm = server->getMissionManager();
						if(mm != NULL)
							mm->evalMission((Player*)_this, mo);
					}
				}
			}
		}
	}
}

/**
 * Returns a mission object belonging to a player
 */
MissionObject* PlayerImplementation::getPlayerMission(const String& key) {
	return missionMap.get(key);
}

/**
 * Save all missions & mission vars belonging to the player. Called on player save intervals
 */
void PlayerImplementation::saveMissions() {
	MissionManager* mm = server->getMissionManager();
	if(mm == NULL)
		return;

	for(int i = 0; i < missionMap.size(); i++) {
		mm->savePlayerMission(_this, missionMap.get(i));
	}

	mm->savePlayerKeys(_this, curMisoKeys, finMisoKeys);
}

/**
 * Load missions
 */

void PlayerImplementation::loadMissions() {
	misoRFC = 0x01;
	misoBSB = 0;

	MissionManager* mm = server->getMissionManager();
	if(mm == NULL)
		return;

	//If the mission map is empty:
	if(missionMap.size() == 0) {
		mm->loadPlayerMissions(_this, true);
	} else { //Else, resend missions that are cached
		String temp;
		StringTokenizer mTok(curMisoKeys);
		mTok.setDelimeter(",");

		while(mTok.hasMoreTokens()) {
			mTok.getStringToken(temp);
			if(!temp.isEmpty())
				mm->sendMission(_this, temp, true);
		}
	}
}

//Called by the mission manager when a mission is dropped
void PlayerImplementation::dropMission(const String& key, bool finished) {
	MissionObject* miso = missionMap.get(key);
	if(miso == NULL)
		return;

	String tck = key + ",";

	//Add to finished keys if the mission was completed successfully. Distribute rewards
	if(finished) {
		// Add to completed keys if the mission was completed for the first time
		if(!hasCompletedMisoKey(key))
			finMisoKeys += tck;
	}

	//Relinquish all mission specific assets
	miso->assetPart(finished);

	missionMap.drop(key);

	miso->finalize();

	//Drop from the current mission key set:
	int pos = curMisoKeys.indexOf(tck);
	if (pos == -1) {
		System::out << "PlayerImplementation::dropMission() : player does not have mission." << endl;
		return;
	}

	StringBuffer tempKeys(curMisoKeys);
	tempKeys.deleteRange(pos, pos + tck.length());

	curMisoKeys = tempKeys.toString();
}

/**
 * Administrative purposes only.
 */
void PlayerImplementation::dropAllMissions() {
	for(int i = 0; i < missionMap.size(); i++) {
		MissionObject* miso = missionMap.get(i);
		if(miso != NULL) {
			miso->sendDestroyTo(_this);

			miso->finalize();
		}
	}

	missionMap.removeAll();

	curMisoKeys = "";
	finMisoKeys = "";
}

// Crafting

CraftingTool* PlayerImplementation::getCraftingTool(const int type, bool doLock) {

	wlock(doLock);

	TangibleObject* item= NULL;

	// The For loop is looking for something in inventory with the same name as what is passed in
	for (int i = 0; i < inventory->getContainerObjectsSize(); i++) {

		item = (TangibleObject*) inventory->getObject(i);

		if (item != NULL && item->isCraftingTool()) {

			CraftingTool* possibleTool = (CraftingTool*)item;

			if ((possibleTool->getToolType() == type)
					&& (possibleTool->isReady())) {

				unlock(doLock);
				return possibleTool;

			}
		}
	}
	unlock(doLock);
	return NULL;

}

// Draft Schematics

void PlayerImplementation::addDraftSchematicsFromGroupName(const String& schematicGroupName) {
	CraftingManager* craftingManager = server->getCraftingManager();
	craftingManager->addDraftSchematicsFromGroupName(_this, schematicGroupName);
}

void PlayerImplementation::subtractDraftSchematicsFromGroupName(const String& schematicGroupName) {
	CraftingManager* craftingManager = server->getCraftingManager();
	craftingManager->subtractDraftSchematicsFromGroupName(_this, schematicGroupName);
}

void PlayerImplementation::addDraftSchematic(DraftSchematic* ds) {
	draftSchematicMap->add(ds);
}

void PlayerImplementation::subtractDraftSchematic(const uint32 objectCRC) {
	draftSchematicMap->remove(objectCRC);
}

void PlayerImplementation::sendDraftSchematics() {
	draftSchematicMap->sendTo();
}

int PlayerImplementation::getDraftSchematicIndex(uint32 schematicID) {
	return draftSchematicMap->getIndexOf(schematicID);
}

// Get by key
DraftSchematic* PlayerImplementation::getDraftSchematicByID(uint32 schematicID) {
	return draftSchematicMap->getByID(schematicID);
}

// Get by index
DraftSchematic* PlayerImplementation::getDraftSchematicByIndex(int index) {
	return draftSchematicMap->getByIndex(index);
}

void PlayerImplementation::broadcastMessageToOthersAround(Player* player, BaseMessage* msg) {
	try {
		Zone* zone = player->getZone();
		if (zone == NULL)
			return;

		zone->lock();

		for (int i = 0; i < player->inRangeObjectCount(); ++i) {
			SceneObject* object = (SceneObject*) (((SceneObjectImplementation*) player->getInRangeObject(i))->_this);

			if (object->isPlayer()) {
				Player* creature = (Player*) object;

				if (creature != player) {
					if (player->isInRange(creature, 128)) {
						creature->sendMessage(msg);
					}
				}
			}
		}

		zone->unlock();

	} catch (...) {
		zone->unlock();
		System::out << "Exception PlayerImplementation::broadcastMessageToOthersAround(Player* player, const String& msg)\n";
	}
}

void PlayerImplementation::sendMessage(BaseMessage* msg) {
	if (owner != NULL)
		owner->sendMessage(msg);
	else
		delete msg;
}

void PlayerImplementation::sendMessage(StandaloneBaseMessage* msg) {
	if (owner != NULL)
		owner->sendMessage(msg);
	else
		delete msg;
}

void PlayerImplementation::addSkillBox(SkillBox* skillBox, bool updateClient) {
	skillBoxes.put(skillBox->getName(), skillBox);
	loadXpTypeCap();

	if (updateClient) {
		CreatureObjectDeltaMessage1* dcreo1;

		dcreo1 = new CreatureObjectDeltaMessage1(this);
		dcreo1->startSkillBoxListUpdate(1);
		dcreo1->addSkillBox(skillBox->getName());

		dcreo1->close();
		sendMessage(dcreo1);
	}
}

void PlayerImplementation::removeSkillBox(SkillBox* skillBox, bool updateClient) {
	skillBoxes.remove(skillBox->getName());
	loadXpTypeCap();

	if (updateClient) {
		CreatureObjectDeltaMessage1* dcreo1;

		dcreo1 = new CreatureObjectDeltaMessage1(this);
		dcreo1->startSkillBoxListUpdate(1);
		dcreo1->removeSkillBox(skillBox->getName());

		dcreo1->close();
		sendMessage(dcreo1);
	}
}

void PlayerImplementation::addCertifications(Vector<Certification*>& certs, bool updateClient) {
	PlayerObjectDeltaMessage9* dplay9;

	if (updateClient) {
		dplay9 = new PlayerObjectDeltaMessage9(playerObject);
		dplay9->startSkillListUpdate(certs.size());
	}

	for (int i = 0; i < certs.size(); i++) {
		Certification* cert = certs.get(i);
		if (!certificationList.contains(cert->getName())) {
			certificationList.put(cert->getName(), cert);
			skillsAndCertifications.add(cert->getName());

			if (updateClient)
				dplay9->addSkill(cert->getName(), skillsAndCertifications.size() - 1);
		}
	}

	if (updateClient) {
		dplay9->close();
		sendMessage(dplay9);
	}
}

void PlayerImplementation::removeCertifications(Vector<Certification*>& certs, bool updateClient) {
	Vector<int> indexes;

	for (int i = 0; i < certs.size(); i++) {
		Certification* cert = certs.get(i);
		certificationList.drop(cert->getName());

		for (int j = 0; j < skillsAndCertifications.size(); ++j) {
			if (cert->getName() == skillsAndCertifications.get(j)) {
				indexes.add(j);

				skillsAndCertifications.remove(j);
			}
		}
	}

	if (updateClient) {
		PlayerObjectDeltaMessage9* dplay9 = new PlayerObjectDeltaMessage9(playerObject);
		dplay9->startSkillListUpdate(certs.size());

		for (int i = 0; i < certs.size(); ++i) {
			int idx = indexes.get(i);

			dplay9->removeSkill(idx);
		}

		dplay9->close();
		sendMessage(dplay9);
	}
}

void PlayerImplementation::toggleCharacterBit(uint32 bit) {
	if (playerObject != NULL) {
		if (!playerObject->setCharacterBit(bit, true))
			playerObject->clearCharacterBit(bit, true);
	}
}


bool PlayerImplementation::setGuildPermissionsBit(uint32 bit, bool updateClient) {
	if (!(guildPermissionsBitmask & bit)) {
		guildPermissionsBitmask |= bit;

		return true;

	} else
		return false;
}

bool PlayerImplementation::clearGuildPermissionsBit(uint32 bit, bool updateClient) {
	if (guildPermissionsBitmask & bit) {
		guildPermissionsBitmask &= ~bit;

		return true;

	} else
		return false;
}

void PlayerImplementation::toggleGuildPermissionsBit(uint32 bit) {
	if (!setGuildPermissionsBit(bit, true))
		clearGuildPermissionsBit(bit, true);
}

void PlayerImplementation::awardBadge(uint8 badge) {
	if (!Badge::exists(badge))
		return;

	StfParameter * badgeName = new StfParameter();
	badgeName->addTO("badge_n", Badge::getName(badge));

	if (hasBadge(badge)) {
		sendSystemMessage("badge_n", "prose_hasbadge", badgeName);
		delete badgeName;
		return;
	}

	badges->setBadge(badge);
	sendSystemMessage("badge_n", "prose_grant", badgeName);
	delete badgeName;

	switch (badges->getNumBadges()) {
	case 5:
		awardBadge(Badge::COUNT_5);
		break;
	case 10:
		awardBadge(Badge::COUNT_10);
		break;
	case 25:
		awardBadge(Badge::COUNT_25);
		break;
	case 50:
		awardBadge(Badge::COUNT_50);
		break;
	case 75:
		awardBadge(Badge::COUNT_75);
		break;
	case 100:
		awardBadge(Badge::COUNT_100);
		break;
	case 125:
		awardBadge(Badge::COUNT_125);
		break;
	default:
		break;
	}

	if (Badge::getType(badge) == Badge::EXPLORATION) {
		switch (badges->getTypeCount(Badge::EXPLORATION)) {
		case 10:
			awardBadge(Badge::BDG_EXP_10_BADGES);
			break;
		case 20:
			awardBadge(Badge::BDG_EXP_20_BADGES);
			break;
		case 30:
			awardBadge(Badge::BDG_EXP_30_BADGES);
			break;
		case 40:
			awardBadge(Badge::BDG_EXP_40_BADGES);
			break;
		case 45:
			awardBadge(Badge::BDG_EXP_45_BADGES);
			break;
		default:
			break;
		}
	}
}

void PlayerImplementation::removeBadge(uint8 badge) {
	if (!Badge::exists(badge) || !badges->hasBadge(badge))
		return;

	StfParameter * badgeName = new StfParameter();
	badgeName->addTO("badge_n", Badge::getName(badge));

	badges->unsetBadge(badge);
	sendSystemMessage("badge_n", "prose_revoke", badgeName);

	delete badgeName;

	switch (badges->getNumBadges()) {
	case 5:
		removeBadge(Badge::COUNT_5);
		break;
	case 10:
		removeBadge(Badge::COUNT_10);
		break;
	case 25:
		removeBadge(Badge::COUNT_25);
		break;
	case 50:
		removeBadge(Badge::COUNT_50);
		break;
	case 75:
		removeBadge(Badge::COUNT_75);
		break;
	case 100:
		removeBadge(Badge::COUNT_100);
		break;
	case 125:
		removeBadge(Badge::COUNT_125);
		break;
	default:
		break;
	}

	if (Badge::getType(badge) == Badge::EXPLORATION) {
		switch (badges->getTypeCount(Badge::EXPLORATION)) {
		case 9:
			removeBadge(Badge::BDG_EXP_10_BADGES);
			break;
		case 19:
			removeBadge(Badge::BDG_EXP_20_BADGES);
			break;
		case 29:
			removeBadge(Badge::BDG_EXP_30_BADGES);
			break;
		case 39:
			removeBadge(Badge::BDG_EXP_40_BADGES);
			break;
		case 44:
			removeBadge(Badge::BDG_EXP_45_BADGES);
			break;
		default:
			break;
		}
	}
}

void PlayerImplementation::getPlayersNearYou() {
	if (zone == NULL || objectID <= 0x15 || isIncapacitated() || isDead())
		return;

	try {
		zone->lock();

		PlayersNearYouMessage* pny = new PlayersNearYouMessage(_this);

		uint32 counter = 0;

		for (int i = 0; i < inRangeObjectCount(); ++i) {
			SceneObject* obj = (SceneObject*) (((SceneObjectImplementation*) getInRangeObject(i))->_getStub());

			if (obj->isPlayer()) {
				++counter;
				Player* player = (Player*) obj;
				pny->addFoundPlayer(player);
			}
		}

		pny->insertPlayerCounter(counter);
		sendMessage(pny);

		zone->unlock();
	} catch (...) {
		error("exception PlayerImplementation::getPlayersNearYou()");
		zone->unlock();
	}
}

void PlayerImplementation::addDatapadItem(SceneObject* item) {
	datapad->addObject(item);
}

SceneObject* PlayerImplementation::getDatapadItem(uint64 oid) {
	return datapad->getObject(oid);
}

void PlayerImplementation::removeDatapadItem(uint64 oid) {
	datapad->removeObject(oid);
}

SceneObject* PlayerImplementation::getPlayerItem(uint64 oid) {
	SceneObject* object = NULL;

	object = getInventoryItem(oid);

	if (object == NULL) {
		object = getDatapadItem(oid);

		if (object == NULL)
			object = getWaypoint(oid);
	}

	return object;
}

bool PlayerImplementation::setGuild(uint32 gid) {
	PlayerManager* playerManager = zone->getZoneServer()->getPlayerManager();
	GuildManager* guildManager = playerManager->getGuildManager();

	guild = guildManager->getGuild(gid);

	return guild != NULL;
}

bool PlayerImplementation::updateGuild(uint32 gid) {
	PlayerManager* playerManager = zone->getZoneServer()->getPlayerManager();
	GuildManager* guildManager = playerManager->getGuildManager();

	Guild* gld = guildManager->getGuild(gid);
	if (gld == NULL)
		return false;

	guild = gld;

	sendGuildTo();

	return true;
}

void PlayerImplementation::updateGuild(Guild* gld) {
	guild = gld;

	sendGuildTo();
}

void PlayerImplementation::sendGuildList() {
	if (guild != NULL)
		guild->sendGuildListTo(_this);
}

void PlayerImplementation::saveProfessions() {
	ProfessionManager* professionManager = server->getProfessionManager();
	professionManager->saveProfessions(this);
}

void PlayerImplementation::loadProfessions() {
	ProfessionManager* professionManager = server->getProfessionManager();
	professionManager->loadProfessions(this);

	accuracy = getSkillMod("unarmed_accuracy");
}

bool PlayerImplementation::trainSkillBox(const String& name, bool updateClient) {
	ProfessionManager* professionManager = server->getProfessionManager();

	return professionManager->trainSkillBox(name, this, updateClient);
}

bool PlayerImplementation::surrenderSkillBox(const String& name, bool updateClient) {
	ProfessionManager* professionManager = server->getProfessionManager();

	return professionManager->surrenderSkillBox(name, this, updateClient);
}

void PlayerImplementation::surrenderAll() {
	ProfessionManager* professionManager = server->getProfessionManager();

	professionManager->surrenderAll(this);

	int race = Races::getRaceID(getRaceFileName());

	String speciesBox = String("species_") + Races::getSpecies(race);
	trainSkillBox(speciesBox);
}

void PlayerImplementation::newChangeFactionStatusEvent(uint8 stat, uint32 timer) {
	pvpStatusBitmask |= CreatureFlag::CHANGEFACTIONSTATUS;

	changeFactionEvent = new ChangeFactionStatusEvent(this, stat, timer);
	server->addEvent(changeFactionEvent);

	try {
		zone->lock();

		for (int i = 0; i < inRangeObjectCount(); ++i) {
			SceneObject* object = (SceneObject*) (((SceneObjectImplementation*) getInRangeObject(i))->_getStub());

			if (object->isPlayer()) {
				Player* player = (Player*) object;
				sendFactionStatusTo(player, true);
			}
		}

		zone->unlock();
	} catch (...) {
		error("exception PlayerImplementation::newChangeFactionStatusEvent()");
		zone->unlock();
	}
}

void PlayerImplementation::setEntertainerEvent() {
	if (entertainerEvent != NULL) {
		server->removeEvent(entertainerEvent);
	}

	entertainerEvent = new EntertainerEvent(_this);

	SkillManager* skillManager = server->getSkillManager();
	Performance* performance = NULL;

	if (isDancing())
		performance = skillManager->getDance(getPerformanceName());
	else if (isPlayingMusic() && getInstrument() != NULL)
		performance = skillManager->getSong(getPerformanceName(), getInstrument()->getInstrumentType());
	else
		return;

	if (!performance) { // shouldn't happen
		StringBuffer msg;
		msg << "Performance was null in setEntertainerEvent.  Please report to McMahon! Name: " << getPerformanceName() << " and Type: " << dec << getInstrument()->getInstrumentType();

		sendSystemMessage(msg.toString());
		return;
	}
	// I think the getLoopDuration is wrong now...thinking it should just be flat 10 seconds
	//server->addEvent(entertainerEvent, (uint64) performance->getLoopDuration() * 1000);
	server->addEvent(entertainerEvent, 10000);
}

void PlayerImplementation::addEntertainerFlourishXp(int xp) {
	EntertainerEvent* entEvent = (EntertainerEvent*)entertainerEvent;

	entEvent->addFlourishXp(xp);
}

void PlayerImplementation::addEntertainerHealingXp(int xp) {
	EntertainerEvent* entEvent = (EntertainerEvent*)entertainerEvent;

	entEvent->addHealingXp(xp);
}

void PlayerImplementation::setSurveyEvent(String& resourceName) {
	surveyEvent = new SurveyEvent(_this, resourceName);
	server->addEvent(surveyEvent, 5000);
}

void PlayerImplementation::setSampleEvent(String& resourceName, bool firstTime) {
	if (surveyTool == NULL) {
		sendSystemMessage("Please contact Ritter ASAP and log the exact actions you just took for a bug report. Thank you.");
		return;
	}

	if (getParent() != NULL && getParent()->isCell()) {
		ChatSystemMessage* sysMessage = new ChatSystemMessage("error_message","survey_in_structure");
		sendMessage(sysMessage);
		return;
	} else if (isInCombat()) {
		ChatSystemMessage* sysMessage = new ChatSystemMessage("survey","sample_cancel_attack");
		sendMessage(sysMessage);
		return;
	} else if (isRidingMount()) {
		sendSystemMessage("You can not sample while riding a mount.");
		return;
	} else if (getInventoryItem(surveyTool->getObjectID()) == NULL) {
		ChatSystemMessage* sysMessage = new ChatSystemMessage("survey","sample_gone");
		sendMessage(sysMessage);
		return;
	} else if (getPosture() != CreaturePosture::CROUCHED) {
		return;
	}

	if (firstTime) {

		sampleTool = surveyTool;

		firstSampleEvent = new SampleEvent(_this, resourceName);
		server->addEvent(firstSampleEvent, 2000);

		sampleEvent = new SampleEvent(_this, resourceName, false, true);
		server->addEvent(sampleEvent, 22000);
	} else {
		firstSampleEvent = NULL;

		if (changeActionBar(-200, false) ) {
			activateRecovery();

			sampleEvent = new SampleEvent(_this, resourceName);

			getZone()->getZoneServer()->getResourceManager()->sendSampleMessage(_this, resourceName);

			server->addEvent(sampleEvent, 20000);
		} else {
			sendSystemMessage("You do not have enough action to do that.");
			changePosture(CreaturePosture::UPRIGHT);
		}
	}
}

void PlayerImplementation::sendSampleTimeRemaining() {
	// Precondition: sampleEvent != NULL
	int time = -(sampleEvent->getTimeStamp().miliDifference()) / 1000;

	UnicodeString ustr = "";
	ChatSystemMessage* sysMessage = new ChatSystemMessage("survey","tool_recharge_time",ustr,time,false);
	sendMessage(sysMessage);
}

int PlayerImplementation::getSlicingAbility() {
	String txt0 = "combat_smuggler_novice";
	String txt1 = "combat_smuggler_slicing_01";
	String txt2 = "combat_smuggler_slicing_02";
	String txt3 = "combat_smuggler_slicing_03";
	String txt4 = "combat_smuggler_slicing_04";
	String txt5 = "combat_smuggler_master";

	if (hasSkillBox(txt5))
		return 5;
	else if (hasSkillBox(txt4))
		return 4;
	else if (hasSkillBox(txt3))
		return 3;
	else if (hasSkillBox(txt2))
		return 2;
	else if (hasSkillBox(txt1))
		return 1;
	else if (hasSkillBox(txt0))
		return 0;

	return -1;
}

void PlayerImplementation::updateBuffWindow() {
	for (int i=0; i < creatureBuffs.size(); i++) {
		Buff* buff = creatureBuffs.get(i);

		if (buff->isActive())
			addBuff(buff->getBuffCRC(), buff->getTimeRemaining());
	}
}

void PlayerImplementation::queueHeal(TangibleObject* medPack, uint32 actionCRC, const String& attribute) {
	if (medPack == NULL || !medPack->isPharmaceutical()) {
		sendSystemMessage("healing_response", "healing_resonse_60"); //No valid medicine found.
		return;
	}

	uint64 objectID = medPack->getObjectID();

	StringBuffer actionModifier;
	if (!attribute.isEmpty())
		actionModifier << attribute << "|";

	actionModifier << objectID;
	queueAction(_this, getTargetID(), actionCRC, ++actionCounter, actionModifier.toString());
}

void PlayerImplementation::queueThrow(TangibleObject* throwItem, uint32 actionCRC) {
	uint64 objectID = throwItem->getObjectID();

	StringBuffer actionModifier;

	actionModifier << objectID;

	queueAction(_this, getTargetID(), actionCRC, ++actionCounter, actionModifier.toString());
}

void PlayerImplementation::fireHeavyWeapon(TangibleObject* heavyWeapon, uint32 actionCRC) {
	uint64 objectID = heavyWeapon->getObjectID();
	actionCounter += 32;
	StringBuffer actionModifier;

	CommandQueueEnqueue* msg = new CommandQueueEnqueue(_this, actionCounter, actionCRC);
	sendMessage(msg);
}


void PlayerImplementation::sendRadialResponseTo(Player* player, ObjectMenuResponse* omr) {
	//player = the player requesting the radial
	//_this = the object who's radial was activated (can only be a playerobject)

	//In order to have sub menus, all parent menus have to be declared first.

	if (!isDead() && !isIncapacitated()) {
		//Heal Enhance
		//TODO: Can this be changed to check for an ability, rather than a skillbox?
		String sbox = "science_doctor_wound_02";

		if (player->hasSkillBox(sbox)) {
			RadialMenuParent* enhanceMenu = new RadialMenuParent(100, 3, "@sui:heal_enhance");
			enhanceMenu->addRadialMenuItem(101, 3, "@sui:heal_enhance_health");
			enhanceMenu->addRadialMenuItem(102, 3, "@sui:heal_enhance_action");
			enhanceMenu->addRadialMenuItem(103, 3, "@sui:heal_enhance_strength");
			enhanceMenu->addRadialMenuItem(104, 3, "@sui:heal_enhance_constitution");
			enhanceMenu->addRadialMenuItem(105, 3, "@sui:heal_enhance_quickness");
			enhanceMenu->addRadialMenuItem(106, 3, "@sui:heal_enhance_stamina");
			omr->addRadialParent(enhanceMenu);
		}

		sbox = "science_medic_novice";

		if (player->hasSkillBox(sbox) && hasWounds(true, true, false)) {
			RadialMenuParent* woundMenu = new RadialMenuParent(87, 3, "@sui:heal_wound");

			if (hasWound(CreatureAttribute::HEALTH))
				woundMenu->addRadialMenuItem(88, 3, "@sui:heal_wound_health");
			if (hasWound(CreatureAttribute::ACTION))
				woundMenu->addRadialMenuItem(89, 3, "@sui:heal_wound_action");
			if (hasWound(CreatureAttribute::STRENGTH))
				woundMenu->addRadialMenuItem(90, 3, "@sui:heal_wound_strength");
			if (hasWound(CreatureAttribute::CONSTITUTION))
				woundMenu->addRadialMenuItem(91, 3, "@sui:heal_wound_constitution");
			if (hasWound(CreatureAttribute::QUICKNESS))
				woundMenu->addRadialMenuItem(92, 3, "@sui:heal_wound_quickness");
			if (hasWound(CreatureAttribute::STAMINA))
				woundMenu->addRadialMenuItem(93, 3, "@sui:heal_wound_stamina");
			omr->addRadialParent(woundMenu);
		}
	}

	if (_this->isPlayingMusic()) {
		if (!player->isListening())
			omr->addRadialParent(116, 3, "@radial_performance:listen");
		else
			omr->addRadialParent(116, 3, "@radial_performance:listen_stop");
	}

	if (_this->isDancing()) {
		if (!player->isWatching())
			omr->addRadialParent(116, 3, "@radial_performance:watch");
		else
			omr->addRadialParent(116, 3, "@radial_performance:watch_stop");
	}

	if (!isDead() && !isIncapacitated()) {
		if (_this->isInAGroup() && player->isInAGroup() && (group == player->getGroupObject())) {
			omr->addRadialParent(140, 3, "@cmd_n:teach");
		}
	}

	omr->finish();

	player->sendMessage(omr);
}

void PlayerImplementation::addFactionPoints(String faction, uint32 points) {
	uint32 currentPoints = factionPointsMap.getFactionPoints(faction);

	uint32 maxPoints = getMaxFactionPoints(faction);
	uint32 pointsToAdd = 0;

	if ((currentPoints + points) > maxPoints)
		pointsToAdd = maxPoints - currentPoints;
	else
		pointsToAdd = points;

	if (pointsToAdd > 0) {
		factionPointsMap.addFactionPoints(faction, pointsToAdd);

		StfParameter * param = new StfParameter();
		param->addTO(faction);
		param->addDI(pointsToAdd);
		sendSystemMessage("base_player", "prose_award_faction", param);
		delete param;
	}

	if (pointsToAdd != points) {
		StfParameter * param = new StfParameter();
		param->addTO(faction);
		sendSystemMessage("base_player", "prose_max_faction", param);
		delete param;
	}
}

void PlayerImplementation::subtractFactionPoints(String faction, uint32 points) {
	int currentPoints = factionPointsMap.getFactionPoints(faction);
	uint32 pointsToAdd = 0;

	if ((currentPoints - (int) points) < -5000)
		pointsToAdd = currentPoints - -5000;
	else
		pointsToAdd = points;

	if (pointsToAdd > 0) {
		factionPointsMap.subtractFactionPoints(faction, pointsToAdd);

		StfParameter* param = new StfParameter();
		param->addTO(faction);
		param->addDI(pointsToAdd);
		sendSystemMessage("base_player", "prose_lose_faction", param);

		delete param;
	}

	if (pointsToAdd != points) {
		StfParameter * param = new StfParameter();
		param->addTO(faction);
		sendSystemMessage("base_player", "prose_min_faction", param);
		delete param;
	}
}

void PlayerImplementation::delFactionPoints(Player * player, uint32 amount) {
	if (player == NULL)
		return;

	uint32 charge = (uint32) ceil(amount * FactionRankTable::getDelegateRatio(getFactionRank()));

	String faction;
	if (isImperial())
		faction = "imperial";
	else if (isRebel())
		faction = "rebel";
	else
		return;

	if (getFactionPoints(faction) < charge + 200)
		return;

	subtractFactionPoints(faction, charge);

	try {
		player->wlock(_this);

		player->addFactionPoints(faction, amount);

		player->unlock();
	} catch (...) {
		error("unreported exception caught in PlayerImplementation::delFactionPoints(Player * player, uint32 amount)");
		player->unlock();
	}
}

void PlayerImplementation::updateWeather() {
    ServerWeatherMessage* swm = new ServerWeatherMessage(zone);
    sendMessage(swm);
}

void PlayerImplementation::addSuiBoxChoice(String& choice){
	suiChoicesList->add(choice);
}

void PlayerImplementation::removeLastSuiBoxChoice(){
	suiChoicesList->removeLastElement();
}

void PlayerImplementation::setSuiBoxChoices(SuiListBoxVector* choicesList){
	suiChoicesList->removeAll();
	suiChoicesList = choicesList;
}

SuiListBoxVector* PlayerImplementation::getSuiBoxChoices(){
	return suiChoicesList;
}

void PlayerImplementation::clearSuiBoxChoices(){
	suiChoicesList->removeAll();
}

int PlayerImplementation::getXpTypeCap(String xptype) {
	int xpcap = 0;
	if (xpCapList.contains(xptype))
	 	xpcap = xpCapList.get(xptype);
	if (xpcap > 0)
		return xpcap;
	else
		return 2000;
}

void PlayerImplementation::loadXpTypeCap() {
	resetSkillBoxesIterator();
	xpCapList.removeAll();

	while (hasNextSkillBox()) {
		SkillBox *skillbox = skillBoxes.getNextValue();

		if (skillbox->isNoviceBox()) {
			Profession *prof = skillbox->getProfession();
			SkillBox *plusone;

			if (prof->isFourByFour()) {
				for (int j = 1; j <= 4; j++) {
					FourByFourProfession *curprof = (FourByFourProfession*)prof;

					plusone = curprof->getBox(j, 1);

					if (xpCapList.contains(plusone->getSkillXpType())) {
						if (plusone->getSkillXpCap() > xpCapList.get(plusone->getSkillXpType()))
							xpCapList.put(plusone->getSkillXpType(), plusone->getSkillXpCap());
					} else
						xpCapList.put(plusone->getSkillXpType(), plusone->getSkillXpCap());
				}
			} else if (prof->isOneByFour()) {
				OneByFourProfession *curprof = (OneByFourProfession*)prof;
				plusone = curprof->getBox(1);
				if (xpCapList.contains(plusone->getSkillXpType())) {
					if (plusone->getSkillXpCap() > xpCapList.get(plusone->getSkillXpType()))
						xpCapList.put(plusone->getSkillXpType(), plusone->getSkillXpCap());
				} else
					xpCapList.put(plusone->getSkillXpType(), plusone->getSkillXpCap());
			} else if (prof->isPyramid()) {
				PyramidProfession *curprof = (PyramidProfession*)prof;
				plusone = curprof->getBox(1);
				if (xpCapList.contains(plusone->getSkillXpType())) {
					if (plusone->getSkillXpCap() > xpCapList.get(plusone->getSkillXpType()))
						xpCapList.put(plusone->getSkillXpType(), plusone->getSkillXpCap());
				} else
					xpCapList.put(plusone->getSkillXpType(), plusone->getSkillXpCap());
			}

		} else if (xpCapList.contains(skillbox->getSkillXpType())) {
			if (xpCapList.get(skillbox->getSkillXpType()) < skillbox->getSkillXpCap()) {
				xpCapList.drop(skillbox->getSkillXpType());
				xpCapList.put(skillbox->getSkillXpType(), skillbox->getSkillXpCap());
			}
		} else
			xpCapList.put(skillbox->getSkillXpType(), skillbox->getSkillXpCap());
	}
}

int PlayerImplementation::calcPlayerLevel(String xptype) {
	resetSkillBoxesIterator();
	playerLevel = 0;

	if (xptype == "jedi_general") {
		playerLevel = 10;
		int skillnum = 0;
		while (hasNextSkillBox()) {
			SkillBox *skillbox = skillBoxes.getNextValue();
			if (skillbox->getSkillXpType() == "jedi_general")
				skillnum += 1;

			// no reason to continue
			if (skillnum >= 3) {
				skillnum = 3;
				break;
			}
		}
		playerLevel += 5*skillnum;
		if (playerLevel > 25)
			playerLevel = 25;
		return playerLevel;
	}

	Weapon *weap = getWeapon();
	int wtype;

	if (weap == NULL)
		wtype = WeaponImplementation::UNARMED;
	else
		wtype = weap->getType();

	while ( hasNextSkillBox() ) {
		SkillBox *skillbox = skillBoxes.getNextValue();
		switch (wtype) {
		case WeaponImplementation::UNARMED:
			if (skillbox->getName() == "combat_unarmed_master") {
				playerLevel = 25;
				break;
			}
			else if (skillbox->getName() == "combat_brawler_novice")
				playerLevel += 5;
			else if (skillbox->getName() == "combat_brawler_master")
				playerLevel += 6;
			else if (skillbox->getName() == "combat_unarmed_novice")
				playerLevel += 2;
			else if (skillbox->getSkillXpType() == "combat_meleespecialize_unarmed" && skillbox->getProfession()->getName() == "combat_brawler")
				playerLevel += 1;
			else if (skillbox->getSkillXpType() == "combat_meleespecialize_unarmed" && skillbox->getProfession()->getName() == "combat_unarmed")
				playerLevel += 2;
			break;
		case WeaponImplementation::ONEHANDED:
			if (skillbox->getName() == "combat_1hsword_master") {
				playerLevel = 25;
				break;
			}
			if (skillbox->getName() == "combat_brawler_novice")
				playerLevel += 5;
			else if (skillbox->getName() == "combat_brawler_master")
				playerLevel += 6;
			else if (skillbox->getName() == "combat_1hsword_novice")
				playerLevel += 2;
			else if (skillbox->getSkillXpType() == "combat_meleespecialize_onehand" && skillbox->getProfession()->getName() == "combat_brawler")
				playerLevel += 1;
			else if (skillbox->getSkillXpType() == "combat_meleespecialize_onehand" && skillbox->getProfession()->getName() == "combat_1hsword")
				playerLevel += 2;
			break;
		case WeaponImplementation::TWOHANDED:
			if (skillbox->getName() == "combat_2hsword_master") {
				playerLevel = 25;
				break;
			}
			if (skillbox->getName() == "combat_brawler_novice")
				playerLevel += 5;
			else if (skillbox->getName() == "combat_brawler_master")
				playerLevel += 6;
			else if (skillbox->getName() == "combat_2hsword_novice")
				playerLevel += 2;
			else if (skillbox->getSkillXpType() == "combat_meleespecialize_twohand" && skillbox->getProfession()->getName() == "combat_brawler")
				playerLevel += 1;
			else if (skillbox->getSkillXpType() == "combat_meleespecialize_twohand" && skillbox->getProfession()->getName() == "combat_2hsword")
				playerLevel += 2;
			break;
		case WeaponImplementation::POLEARM:
			if (skillbox->getName() == "combat_polearm_master") {
				playerLevel = 25;
				break;
			}
			if (skillbox->getName() == "combat_brawler_novice")
				playerLevel += 5;
			else if (skillbox->getName() == "combat_brawler_master")
				playerLevel += 6;
			else if (skillbox->getName() == "combat_polearm_novice")
				playerLevel += 2;
			else if (skillbox->getSkillXpType() == "combat_meleespecialize_polearm" && skillbox->getProfession()->getName() == "combat_brawler")
				playerLevel += 1;
			else if (skillbox->getSkillXpType() == "combat_meleespecialize_polearm" && skillbox->getProfession()->getName() == "combat_polearm")
				playerLevel += 2;
			break;
		case WeaponImplementation::PISTOL:
			if (skillbox->getName() == "combat_pistol_master") {
				playerLevel = 25;
				break;
			}
			if (skillbox->getName() == "combat_marksman_novice")
				playerLevel += 5;
			else if (skillbox->getName() == "combat_marksman_master")
				playerLevel += 6;
			else if (skillbox->getName() == "combat_pistol_novice" || skillbox->getName() == "combat_bountyhunter_novice")
				playerLevel += 2;
			else if (skillbox->getSkillXpType() == "combat_rangedspecialize_pistol" && skillbox->getProfession()->getName() == "combat_marksman")
				playerLevel += 1;
			else if (skillbox->getSkillXpType() == "combat_rangedspecialize_pistol" && (skillbox->getProfession()->getName() == "combat_pistol" || skillbox->getProfession()->getName() == "combat_bountyhunter"))
				playerLevel += 2;
			break;
		case WeaponImplementation::CARBINE:
			if (skillbox->getName() == "combat_carbine_master") {
				playerLevel = 25;
				break;
			}
			if (skillbox->getName() == "combat_marksman_novice")
				playerLevel += 5;
			else if (skillbox->getName() == "combat_marksman_master")
				playerLevel += 6;
			else if (skillbox->getName() == "combat_carbine_novice")
				playerLevel += 2;
			else if (skillbox->getSkillXpType() == "combat_rangedspecialize_carbine" && skillbox->getProfession()->getName() == "combat_marksman")
				playerLevel += 1;
			else if (skillbox->getSkillXpType() == "combat_rangedspecialize_carbine" && skillbox->getProfession()->getName() == "combat_carbine")
				playerLevel += 2;
			break;
		case WeaponImplementation::RIFLE:
			if (skillbox->getName() == "combat_rifleman_master") {
				playerLevel = 25;
				break;
			}
			if (skillbox->getName() == "combat_marksman_novice")
				playerLevel += 5;
			else if (skillbox->getName() == "combat_marksman_master")
				playerLevel += 6;
			else if (skillbox->getName() == "combat_rifleman_novice")
				playerLevel += 2;
			else if (skillbox->getSkillXpType() == "combat_rangedspecialize_rifle" && skillbox->getProfession()->getName() == "combat_marksman")
				playerLevel += 1;
			else if (skillbox->getSkillXpType() == "combat_rangedspecialize_rifle" && skillbox->getProfession()->getName() == "combat_rifleman")
				playerLevel += 2;
			break;
		case WeaponImplementation::ONEHANDSABER:
		case WeaponImplementation::TWOHANDSABER:
		case WeaponImplementation::POLEARMSABER:
			return calcPlayerLevel(String("jedi_general"));
			break;
		case WeaponImplementation::RIFLEBEAM:
		case WeaponImplementation::RIFLEFLAMETHROWER:
		case WeaponImplementation::RIFLELIGHTNING:
		case WeaponImplementation::RIFLEACIDBEAM:
		case WeaponImplementation::HEAVYACIDBEAM:
		case WeaponImplementation::HEAVYLIGHTNINGBEAM:
		case WeaponImplementation::HEAVYPARTICLEBEAM:
		case WeaponImplementation::HEAVYROCKETLAUNCHER:
		case WeaponImplementation::HEAVYLAUNCHER:
			if (skillbox->getName() == "combat_commando_master" || skillbox->getName() == "combat_bountyhunter_master") {
				playerLevel = 25;
				break;
			}
			else if (skillbox->getName() == "combat_commando_novice" || skillbox->getName() == "combat_bountyhunter_novice")
				playerLevel += 17;
			else if (skillbox->getSkillXpType() == "combat_rangedspecialize_heavy" )
				playerLevel += 2;
			break;
		default:
			break;
		};
	}

	// force the 5-25 range
	if (playerLevel < 5)
		playerLevel = 5;
	else if (playerLevel > 25)
		playerLevel = 25;

	return playerLevel;
}

void PlayerImplementation::teachPlayer(Player* player) {
	if (teachingSkillList.size() > 0)
		return;

	Vector<SkillBox*> trainboxes;

	resetSkillBoxesIterator();

	if (!hasNextSkillBox()) {
		sendSystemMessage("teaching","no_skills");
		return;
	}

	while (hasNextSkillBox()) {
		SkillBox* sBox = skillBoxes.getNextValue();

		if (sBox->isNoviceBox())
			continue;

		if (sBox->getSkillXpType() == "jedi_general" ||
			sBox->getSkillXpType() == "space_combat_general" ||
			sBox->getSkillXpType() == "fs_crafting" ||
			sBox->getSkillXpType() == "fs_combat" ||
			sBox->getSkillXpType() == "fs_reflex" ||
			sBox->getSkillXpType() == "fs_senses" ||
			sBox->getSkillXpType() == "force_rank_xp")
			continue;

		if (player->hasSkillBox(sBox->getName()))
			continue;

		for (int j = 0; j < sBox->getRequiredSkillsSize(); j++) {
			if (player->hasSkillBox(sBox->getRequiredSkill(j)->getName()))
				trainboxes.add(sBox);
		}
	}

	if (trainboxes.size() > 0) {
		setStudent(player);
		player->setTeacher(_this);
		SuiListBox* sbox = new SuiListBox(player, SuiWindowType::TEACH_PLAYER);
		sbox->setPromptTitle("@sui:teach");
		sbox->setPromptText("What would you like to teach?");
		sbox->setCancelButton(true, "");

		for (int i = 0; i < trainboxes.size(); i++) {
			StringBuffer skillboxname;
			skillboxname << "@skl_n:" << trainboxes.get(i)->getName();
			sbox->addMenuItem(skillboxname.toString());
			teachingSkillList.add(trainboxes.get(i));
		}

		addSuiBox(sbox);
		sendMessage(sbox->generateMessage());
	} else {
		StfParameter* params = new StfParameter();
		params->addTT(player->getFirstNameProper());
		sendSystemMessage("teaching","no_skills_for_student",params);
		delete params;
	}
}

void PlayerImplementation::teachSkill(String& skillname) {
	SkillBox* sBox = server->getProfessionManager()->getSkillBox(skillname);
	StfParameter* params = new StfParameter;

	params->addTO("skl_n",skillname);
	params->addTT(getTeacher()->getFirstNameProper());

	if (sBox->getSkillXpCost() > getXp(sBox->getSkillXpType())) {
		sendSystemMessage("skill_teacher","prose_train_failed", params);
	} else {
		sendSystemMessage("teaching","student_skill_learned", params);
		addXp(sBox->getSkillXpType(), (-1)*sBox->getSkillXpCost(), true);
		trainSkillBox(skillname);

		StfParameter* locparams = new StfParameter;
		locparams->addTT(getFirstNameProper());
		locparams->addTO("skl_n",skillname);

		int xp = 0;
		String xptype("apprenticeship");
		if (sBox->isMasterBox())
			xp = 60;
		else {
			char tier = skillname.charAt(skillname.length()-1);
			xp = ((tier-'0') + 1) * 10;
		}
		locparams->addDI(xp);

		getTeacher()->sendSystemMessage("teaching","teacher_skill_learned", locparams);
		getTeacher()->addXp(xptype, xp, true);

		delete locparams;
	}

	delete params;

	getTeacher()->setStudent(NULL);
	setTeacher(NULL);
}

uint64 PlayerImplementation::getTrap() {
	Inventory* inventory = getInventory();

	if (inventory != NULL) {
		for (int i = 0; i < inventory->getContainerObjectsSize(); ++i) {
			TangibleObject* item = (TangibleObject*) inventory->getObject(i);

			if (item->isTrap()) {
				TrapThrowableWeapon* trap = (TrapThrowableWeapon*) item;

				if (trap->isUsefull(_this) && hasCooldownExpired(trap->getSkill())) {
					return trap->getObjectID();
				}
			}
		}
	}
	return 0;
}

uint64 PlayerImplementation::getGrenade() {
	Inventory* inventory = getInventory();

	if (inventory != NULL) {
		for (int i = 0; i < inventory->getContainerObjectsSize(); ++i) {
			TangibleObject* item = (TangibleObject*) inventory->getObject(i);

			if (item->isGrenade()) {
				GrenadeThrowableWeapon* grenade = (GrenadeThrowableWeapon*) item;

				if (grenade->isUsefull(_this) && hasCooldownExpired(grenade->getSkill())) {
					return grenade->getObjectID();
				}
			}
		}
	}
	return 0;
}

uint64 PlayerImplementation::getHeavyRangedWeapon() {
	Inventory* inventory = getInventory();

	if (inventory != NULL) {
		for (int i = 0; i < inventory->getContainerObjectsSize(); ++i) {
			TangibleObject* item = (TangibleObject*) inventory->getObject(i);

			if (item->isWeapon()) {
				Weapon* weapon = (Weapon*) item;

				if (weapon->isHeavyWeapon()) {
					HeavyRangedWeapon* hw = (HeavyRangedWeapon*) item;

					//TODO: check if useful() and hasCoolDownExpired?
					return hw->getObjectID();
				}
			}
		}
	}
	return 0;
}

void PlayerImplementation::removeOldSuiBoxIfPresent(const int suiWindowType) {
	if (hasSuiBoxWindowType(suiWindowType)) {
		int boxID = getSuiBoxFromWindowType(suiWindowType);
		SuiListBox* sui = (SuiListBox*) getSuiBox(boxID);

		if (sui != NULL) {
			sendMessage(sui->generateCloseMessage());
			removeSuiBox(boxID);
			sui->finalize();
		}
	}
}

void PlayerImplementation::displayMessageoftheDay() {

	String motd = server->getZoneServer()->getMessageoftheDay();

	SuiMessageBox* suiMessageBox = new SuiMessageBox(_this, SuiWindowType::MOTD);

	suiMessageBox->setPromptTitle("Message of the Day");
	suiMessageBox->setPromptText(motd);

	sendMessage(suiMessageBox->generateMessage());
	suiMessageBox->finalize();
}

uint64 PlayerImplementation::getAvailablePower() {
	Inventory* inventory = getInventory();
	uint64 power = 0;

	if (inventory != NULL) {
		for (int i = 0; i < inventory->getContainerObjectsSize(); i++) {
			TangibleObject* tano = (TangibleObject*) inventory->getObject(i);

			if (tano->isResource()) {
				ResourceContainer* rcno = (ResourceContainer*)tano;

				if (rcno->isEnergy()){
					int PE = rcno->getPotentialEnergy();
					if(PE > 500)
						power += (unsigned long long) ( (PE  * 1.0) / 500.0 * (rcno->getContents() * 1.0) );
					else
						power += rcno->getContents();
				}
			}
		}
	}

	return power;
}

void PlayerImplementation::removePower(uint64 power) {
	Inventory* inventory = getInventory();

	uint64 containerPower = 0;

	if (inventory != NULL && power > 0) {
		for (int i = 0; i < inventory->getContainerObjectsSize(); i++ && power > 0) {
			ManagedReference<TangibleObject> tano = (TangibleObject*) inventory->getObject(i);

			if (tano->isResource()) {
				ResourceContainer* rcno = (ResourceContainer*)tano.get();

				if (rcno->isEnergy()){
					int PE = rcno->getPotentialEnergy();
					if(PE > 500)
						containerPower = (unsigned long long) ( (PE  * 1.0) / 500.0 * (rcno->getContents() * 1.0) );
					else
						containerPower = rcno->getContents();


					if(containerPower > power) {
						// remove

						uint64 consumedUnits = (unsigned long long) ( (power * 1.0) / ( (containerPower * 1.0) / rcno->getContents() ) );
						power = 0; // zero it down

						rcno->setContents(rcno->getContents() - consumedUnits);

						// Update the ResourceContainer
						rcno->sendDeltas(_this);
						// Flag ResourceContainer for saving changes
						rcno->setUpdated(true);

					} else {

						power -= containerPower;
						rcno->sendDestroyTo(_this);

						Zone* zone = getZone();

						if (zone != NULL) {
							ZoneServer* zoneServer = zone->getZoneServer();

							ItemManager* itemManager;
							if (zoneServer != NULL && ((itemManager = zoneServer->getItemManager()) != NULL)) {
								removeInventoryItem(rcno->getObjectID());

								itemManager->deletePlayerItem(_this, rcno, false);

								rcno->finalize();
							}
						}
					}
				}
			}
		}
	}
}


/// Sending of Messages
/**
 * This message will display the incapacitation timer on the client.
 * \param seconds How many seconds will the incapacitation timer count down from.
 * \param doRecovery Should recovery be scheduled. For example, feignDeath would use false.
 */
void PlayerImplementation::sendIncapacitationTimer(uint32 seconds, bool doRecovery) {
	CreatureObjectDeltaMessage3* incapTimer = new CreatureObjectDeltaMessage3(_this);
	incapTimer->updateIncapacitationRecoveryTime(seconds);
	incapTimer->close();

	sendMessage(incapTimer);

	if (doRecovery)
		rescheduleRecovery(seconds * 1000);
}

/**
 * This message sends the Bank Tip confirm sui box that is displayed when a 5% tax is added on to a player's tip.
 * \param receiver The player receiving the bank tip.
 */
void PlayerImplementation::sendBankTipConfirm(Player* recipient, uint32 amount) {
	closeSuiWindowType(SuiWindowType::BANK_TIP_CONFIRM);

	SuiBankTipConfirmBox* bankTip = new SuiBankTipConfirmBox(_this, recipient, amount);
	bankTip->setRecipient(recipient);

	addSuiBox(bankTip);
	sendMessage(bankTip->generateMessage());
}

/**
 * This message sends the Consent Sui which shows all players that you have given consent to.
 */
void PlayerImplementation::sendConsentList() {
	closeSuiWindowType(SuiWindowType::CLONE_REQUEST);

	if (consentList.size() <= 0) {
		sendSystemMessage("error_message", "consent_to_empty"); //You have not granted consent to anyone.
		return;
	}

	SuiListBox* consentBox = new SuiListBox(_this, SuiWindowType::CONSENT);

	consentBox->setPromptTitle("@ui:consent_title");
	consentBox->setPromptText("All players whom you have given your consent to are listed below.\n\nHighlight a player's name and click OK to revoke consent.");
	consentBox->setCancelButton(true, "");

	for (int i=0; i < consentList.size(); i++) {
		String entryName = consentList.get(i);
		if (!entryName.isEmpty())
			consentBox->addMenuItem(entryName);
	}

	addSuiBox(consentBox);
	sendMessage(consentBox->generateMessage());
}

/**
 * This message is used to send the activate clone request dialog.
 */
void PlayerImplementation::sendActivateCloneRequest() {
	closeSuiWindowType(SuiWindowType::CLONE_REQUEST);

	SuiListBox* cloneMenu = new SuiListBox(_this, SuiWindowType::CLONE_REQUEST);

	cloneMenu->setPromptTitle("@base_player:revive_title");

	StructureManager* structureManager = getZone()->getPlanetManager()->getStructureManager();

	CloningFacility* closestFacility = structureManager->getClosestCloningFacility(_this);

	if (closestFacility == NULL) {
		cloneMenu->finalize();
		return;
	}

	CloningFacility* preDesignatedFacility = getCloningFacility();

	String closestName = "Not Working Yet";
	String predesignatedName = (preDesignatedFacility != NULL) ? "Not Working Yet" : "None";

	//TODO: Integrate this menu with cloning system.

	StringBuffer promptText;
	promptText << "Closest:\t\t\t" << closestName << "\n"
			   << "Pre-Designated: \t" << predesignatedName << "\n" //Space before tab character is needed for proper formatting in this case.
			   << "Cash Balance:\t\t" << getCashCredits() << "\n\n"
			   << "Select the desired option and click OK.";

	cloneMenu->setPromptText(promptText.toString());

	cloneMenu->addMenuItem("@base_player:revive_closest", closestFacility->getObjectID());

	//Check if predesignated is on this planet or not.
	if (preDesignatedFacility != NULL && preDesignatedFacility->getZoneID() == getZoneID())
		cloneMenu->addMenuItem("@base_player:revive_bind", preDesignatedFacility->getObjectID());

	addSuiBox(cloneMenu);
	sendMessage(cloneMenu->generateMessage());
}

/**
 * This message sends the cloning data confirmation dialog SUI box.
 */
void PlayerImplementation::sendCloningDataStorageConfirm(CloningTerminal* terminal) {
	closeSuiWindowType(SuiWindowType::CLONE_CONFIRM);

	SuiMessageBox* cloneConfirm = new SuiMessageBox(_this, SuiWindowType::CLONE_CONFIRM);
	cloneConfirm->setPromptTitle("@base_player:clone_confirm_title");
	cloneConfirm->setPromptText("@base_player:clone_confirm_prompt");
	cloneConfirm->setCancelButton(true, "");
	cloneConfirm->setUsingObjectID(terminal->getObjectID());

	addSuiBox(cloneConfirm);
	sendMessage(cloneConfirm->generateMessage());
}

/**
 * This message sends the item insurance sui list box.
 */
void PlayerImplementation::sendItemInsuranceMenu(InsuranceTerminal* terminal) {
	closeSuiWindowType(SuiWindowType::INSURANCE_MENU);

	Vector<TangibleObject*> insurableItems = getInsurableItems();

	if (insurableItems.size() <= 0) {
		sendSystemMessage("terminal_ui", "no_insurable_items"); //You do not have any items that can be insured.
		return;
	}

	SuiListBox* insuranceMenu = new SuiListBox(_this, SuiWindowType::INSURANCE_MENU);
	insuranceMenu->setPromptTitle("@sui:mnu_insure");
	insuranceMenu->setPromptText("Select which items you would like to buy insurance for from the list below.");
	insuranceMenu->setUsingObjectID(terminal->getObjectID());

	for (int i = 0; i < insurableItems.size(); i++) {
		TangibleObject* item = insurableItems.get(i);
		insuranceMenu->addMenuItem(item->getCustomName().toString(), item->getObjectID());
	}

	addSuiBox(insuranceMenu);
	sendMessage(insuranceMenu->generateMessage());

	insurableItems.removeAll();
}

void PlayerImplementation::sendItemInsureAllConfirm(InsuranceTerminal* terminal) {
	closeSuiWindowType(SuiWindowType::INSURE_ALL_CONFIRM);

	Vector<TangibleObject*> insurableItems = getInsurableItems();

	if (insurableItems.size() <= 0) {
		sendSystemMessage("terminal_ui", "no_insurable_items"); //You do not have any items that can be insured.
		return;
	}

	StringBuffer promptText;
	promptText << "You are about to insure all your items. The total cost is " << (insurableItems.size() * terminal->getCost()) << " credits.\n\nAre you sure?";

	SuiMessageBox* insureAll = new SuiMessageBox(_this, SuiWindowType::INSURE_ALL_CONFIRM);
	insureAll->setUsingObjectID(terminal->getObjectID());
	insureAll->setPromptTitle("@terminal_ui:insure_all_t");
	insureAll->setPromptText(promptText.toString());
	insureAll->setCancelButton(true, "");

	addSuiBox(insureAll);
	sendMessage(insureAll->generateMessage());

	insurableItems.removeAll();
}

void PlayerImplementation::sendSlicingMenu(TangibleObject* item) {
	if (hasSuiBoxWindowType(SuiWindowType::SLICING_MENU)) {
		sendSystemMessage("slicing/slicing", "already_slicing"); //You are already slicing something.
		return;
	}

	if (item != NULL && item->isSlicable()) {
		item->setSlicerID(getObjectID());

		SuiSlicingBox* slicingMenu = new SuiSlicingBox(_this, item);
		slicingMenu->generateMenu();
		slicingMenu->setCancelButton(true, "");

		addSuiBox(slicingMenu);
		sendMessage(slicingMenu->generateMessage());
	}
}



/// Actions

void PlayerImplementation::incapacitateSelf() {
	setPosture(CreaturePosture::INCAPACITATED);
	onIncapacitated(NULL);
}

void PlayerImplementation::die() {
	resetIncapacitationCounter();

	//TODO: Start resurrection countdown timer.

	CreatureObjectImplementation::die();
	onDeath();
}

/**
 * Clones the player at their designated facility, or, if it hasn't been set or is off planet, at the closest one.
 */
void PlayerImplementation::clone(uint64 facilityID) {
	StructureManager* structureManager = zone->getPlanetManager()->getStructureManager();
	CloningFacility* cloningFacility = NULL;

	if (facilityID > 0)
		cloningFacility = structureManager->getCloningFacility(facilityID);
	else
		cloningFacility = getCloningFacility();

	//Cloning facility is invalid. Try to get the closest facility.
	if (cloningFacility == NULL || cloningFacility->getZoneID() != getZoneID())
		cloningFacility = structureManager->getClosestCloningFacility(_this);

	if (cloningFacility != NULL)
		cloningFacility->clone(_this);
	else
		sendSystemMessage("An error occurred, preventing you from cloning. Please contact a Customer Service Representative.");
}

void PlayerImplementation::resuscitate(CreatureObject* patient, bool forced) {
	SceneObjectImplementation::resuscitate(patient, forced);
}


/**
 * This method is used to increase a player's pvp rating based on an opponent.
 * \param victim Player who was slain.
 */
void PlayerImplementation::increasePvpRating(Player* victim) {
	float killerRating = (float) getPvpRating();
	float victimRating = (float) victim->getPvpRating();

	/// Increase Formula: N = P1 + ((P2 - P1 + 100) / 9), where P2 - P1 - 100 >= 0
	/// P1 = Killer's PVP Rating; P2 = Victim's PVP Rating; N = Points Gained
	int pointsGained = (int)round((victimRating - killerRating + 100.0f) / 9.0f);
	pointsGained = (pointsGained >= 0) ? pointsGained : 0;

	increasePvpRating(pointsGained);

	onPvpRatingGained(victim);
}

/**
 * This method is used to increase a player's pvp rating by a set amount.
 * NOTE: Use decreasePvpRating(amount) in order to decrease a player's pvpRating.
 * \param amount The amount to increase the player's pvpRating by. Should always be positive.
 */
void PlayerImplementation::increasePvpRating(uint32 amount) {
	setPvpRating(getPvpRating() + amount);
}

/**
 * This method is used to decrease a player's pvp rating based on their opponent.
 * \param killer The killer in the pvp contest.
 */
void PlayerImplementation::decreasePvpRating(Player* killer) {
	float killerRating = (float) killer->getPvpRating();
	float victimRating = (float) getPvpRating();

	/// Decrease Formula: N = P1 - ((P1 - P2 + 100) / 5), where P1 - P2 + 100 >= 0
	/// P1 = Victim's PVP Rating; P2 = Killer's PVP Rating; N = Points Lost
	int pointsLost = (int)round((victimRating - killerRating + 100.0f) / 5.0f);
	pointsLost = (pointsLost >= 0) ? pointsLost : 0;

	decreasePvpRating(pointsLost);

	onPvpRatingLost(killer);
}

/**
 * This method is used to decrease a player's pvp rating based on a set amount.
 * \param amount The amount to decrease the player's pvp rating by.
 */
void PlayerImplementation::decreasePvpRating(uint32 amount) {
	setPvpRating(getPvpRating() - amount);
}

void PlayerImplementation::cancelRecoveryEvent() {
	if (server != NULL && recoveryEvent != NULL && recoveryEvent->isQueued())
		server->removeEvent(recoveryEvent);
}

bool PlayerImplementation::makePaymentTo(SceneObject* target, uint32 cost, bool notifyPlayer) {
	if (!verifyCashCredits(cost))
		return false;

	subtractCashCredits(cost);
	target->receivePaymentFrom(_this, cost);

	if (notifyPlayer)
		onMakePaymentTo(target, cost);

	return true;
}

bool PlayerImplementation::makeBankPaymentTo(SceneObject* target, uint32 cost, bool notifyPlayer) {
	if (!verifyBankCredits(cost))
		return false;

	subtractBankCredits(-cost);
	target->receivePaymentFrom(_this, cost);

	if (notifyPlayer)
		onMakeBankPaymentTo(target, cost);

	return true;
}

void PlayerImplementation::insureItem(InsuranceTerminal* terminal, uint64 itemID, bool notifySuccess) {
	TangibleObject* item = (TangibleObject*) getInventoryItem(itemID);

	if (terminal != NULL) {
		if (item != NULL && item->isInsurable()) {
			int cost = terminal->getCost();

			if (makePaymentTo(terminal, cost, notifySuccess)) {
				item->updateInsurance(_this, true);

				if (notifySuccess)
					onInsureItemSuccess(itemID);
			} else {
				onInsureItemInsufficientFunds(itemID);
			}
		} else {
			onInsureItemFailure(itemID);
		}
	} else {
		onInsureItemInvalidTerminal();
	}
}

void PlayerImplementation::insureAllItems(uint64 terminalID) {
	InsuranceTerminal* terminal = NULL;
	SceneObject* scoTerminal = zone->lookupObject(terminalID);

	if (scoTerminal != NULL) {
		TangibleObject* tanoTerminal = (TangibleObject*) scoTerminal;
		if (tanoTerminal->isTerminal()) {
			Terminal* termTerminal = (Terminal*) tanoTerminal;
			if (termTerminal->isInsuranceTerminal())
				terminal = (InsuranceTerminal*) termTerminal;
		}
	}

	if (terminal != NULL) {
		Vector<TangibleObject*> insurableItems = getInsurableItems();
		int size = insurableItems.size();

		if (size > 0) {
			for (int i = 0; i < size; i++)
				insureItem(terminal, insurableItems.get(i)->getObjectID(), false);

			onMakePaymentTo(terminal, terminal->getCost() * size);

			onInsureAllItemsComplete();
		} else {
			onNoValidInsurables();
		}
	} else {
		onInsureItemInvalidTerminal();
	}
}

bool PlayerImplementation::bankTipStart(Player* recipient, uint32 amount) {
	float tax = (float) amount * 0.05f;

	StfParameter* params = new StfParameter();
	params->addDI(amount);
	params->addTT(recipient->getObjectID());

	if (amount > 1000000) {
		sendSystemMessage("You may not bank tip more than 1,000,000 credits at a time.");
		delete params;
		return false;
	}

	if (!verifyBankCredits(amount + (int) tax)) {
		sendSystemMessage("base_player", "prose_tip_nsf_bank", params); //You lack the bank funds to wire %DI credits to %TT.
		delete params;
		return false;
	}

	sendBankTipConfirm(recipient, amount);

	delete params;
	return true;
}

/**
 * Finishes sending a bank wire transfer after a player has accepted the confirmation sui.
 * \param recipient The recipient of the bank transfer.
 * \param amount How much the transfer is for.
 */
void PlayerImplementation::bankTipFinish(Player* recipient, uint32 amount) {
	float tax = (float) amount * 0.05f;

	StfParameter* params = new StfParameter();
	params->addDI(amount);
	params->addTO(recipient->getObjectID());

	recipient->addBankCredits(amount);
	subtractBankCredits(amount + (int) tax);

	sendSystemMessage("base_player", "prose_wire_pass_self", params);  //You have successfully sent %DI bank credits to %TO.

	if (recipient->isOnline()) {
		params->clear();
		params->addDI(amount);
		params->addTO(getObjectID());
		recipient->sendSystemMessage("base_player", "prose_wire_pass_target", params); //You have successfully received %DI bank credits from %TO.
	}

	String mailFrom = "@base_player:prose_wire_mail_from"; //On behalf of %TO...

	UnicodeString mailSubject("@base_player:wire_mail_subject");
	UnicodeString mailMessageSender("An amount of %DI credits have been transferred from your bank to escrow. It will be delivered to %TO as soon as possible.");

	ChatManager* chatManager = server->getChatManager();
	chatManager->sendMail(mailFrom, mailSubject, mailMessageSender, getFirstName());

	UnicodeString mailMessageRecipient("%DI credits from %TO have been successfully delivered from escrow to your bank account.");
	chatManager->sendMail(mailFrom, mailSubject, mailMessageRecipient, recipient->getFirstName());

	delete params;
}


bool PlayerImplementation::cashTip(Player* recipient, uint32 amount) {
	StfParameter* params = new StfParameter();
	params->addDI(amount);
	params->addTT(recipient->getObjectID());

	if (!recipient->isOnline()) {
		sendSystemMessage("base_player", "tip_target_offline"); //You cannot tip someone who is not online.
		delete params;
		return false;
	}

	// Must be within 120 meters to cash tip.
	if (!isInRange(_this, 120)) {
		sendSystemMessage("base_player", "prose_tip_range", params); //You are too far away to tip %TT with cash. You can send a wire transfer instead.
		delete params;
		return false;
	}

	if (amount > 1000000) {
		sendSystemMessage("You may not tip more than 1000000 credits at a time.");
		delete params;
		return false;
	}

	if (!verifyCashCredits(amount)) {
		sendSystemMessage("base_player", "prose_tip_nsf_cash", params); //You lack the cash funds to tip %DI credits to %TT.
		delete params;
		return false;
	}

	recipient->addCashCredits(amount);
	subtractCashCredits(amount);

	sendSystemMessage("base_player", "prose_tip_pass_self", params); //You successfully tip %DI credits to %TT.
	params->clear();
	params->addDI(amount);
	params->addTT(getObjectID());
	recipient->sendSystemMessage("base_player", "prose_tip_pass_target", params); //%TT tips you %DI credits.

	delete params;
	return true;
}

void PlayerImplementation::consent(Player* playerTarget) {
	if (playerTarget == _this) {
		sendSystemMessage("You ask yourself for consent, but receive no answer...");
		return;
	}

	if (playerTarget != NULL && playerTarget->isOnline()) {
		String firstName = playerTarget->getFirstName().toLowerCase();

		if (!hasConsented(firstName)) {
			consentList.add(firstName);
			StfParameter* params = new StfParameter();
			params->addTO(playerTarget->getObjectID());
			sendSystemMessage("base_player", "prose_consent", params); //You give your consent to %TO.
			params->clear();
			params->addTO(getObjectID());
			playerTarget->sendSystemMessage("base_player", "prose_got_consent", params); //%TO consents you.
			delete params;
		} else {
			sendSystemMessage("They already have your consent.");
		}
	}
}

/**
 * This action is used to unconsent a player by first name.
 * \param name The name of the player on your consent list. Should only be the first name.
 */
void PlayerImplementation::unconsent(const String& name) {
	PlayerManager* playerManager = server->getPlayerManager();
	int entryIndex = -1;

	for (int i = 0; i < consentList.size(); i++) {
		if (name == consentList.get(i))
			entryIndex = i;
	}

	if (entryIndex == -1)
		return;

	consentList.remove(entryIndex);

	//Try to get a player that matches the name.
	Player* playerTarget = playerManager->getPlayer(name);

	StfParameter* params = new StfParameter();

	if (playerTarget != NULL && playerTarget->isOnline()) {
		params->addTO(getObjectID());
		playerTarget->sendSystemMessage("base_player", "prose_lost_consent", params); //%TO no longer consents you.
		params->clear();
		params->addTO(playerTarget->getObjectID());
	} else {
		params->addTO(name);
	}

	sendSystemMessage("base_player", "prose_unconsent", params); //You revoke your consent from %TO.
	delete params;
}

void PlayerImplementation::crashClient() {

	// Rick Roll them - optional.
	//LaunchBrowserMessage* lbm = new LaunchBrowserMessage("smouch.net/lol");
	//_this->sendMessage(lbm);

	// Crash Client
	ErrorMessage* errMsg = new ErrorMessage("You aren't welcome", "Get out and don't come back", true);
	_this->sendMessage(errMsg);

}

bool PlayerImplementation::migrateStats() {
	PlayerManager* playerManager = server->getPlayerManager();

	if (getBaseHealth() != getMigrationHealth())
		setBaseHealthBar(getMigrationHealth());

	if (getBaseStrength() != getMigrationStrength())
		setBaseStrengthBar(getMigrationStrength());

	if (getBaseConstitution() != getMigrationConstitution())
		setBaseConstitutionBar(getMigrationConstitution());

	if (getBaseAction() != getMigrationAction())
		setBaseActionBar(getMigrationAction());

	if (getBaseQuickness() != getMigrationQuickness())
		setBaseQuicknessBar(getMigrationQuickness());

	if (getBaseStamina() != getMigrationStamina())
		setBaseStaminaBar(getMigrationStamina());

	if (getBaseMind() != getMigrationMind())
		setBaseMindBar(getMigrationMind());

	if (getBaseFocus() != getMigrationFocus())
		setBaseFocusBar(getMigrationFocus());

	if (getBaseWillpower() != getMigrationWillpower())
		setBaseWillpowerBar(getMigrationWillpower());

	if (playerManager != NULL)
		playerManager->updatePlayerBaseHAMToDatabase(_this);

	return true;
}


float PlayerImplementation::getTotalInventoryPower() {
	float totalpower = 0.0f;

	for (int i = 0; i < inventory->getContainerObjectsSize(); i++) {
		SceneObject* object = inventory->getObject(i);

		if (object != NULL && object->isTangible()) {
			TangibleObject* tangible = (TangibleObject*) object;

			if (tangible->isResource()) {
				ResourceContainer* rcno = (ResourceContainer*) tangible;

				if (rcno->isEnergy()) {
					//Calculate the resources power potential.
					uint32 pe = rcno->getPotentialEnergy();
					float modifier = (pe > 500) ? (((float) (pe - 500)) / 500.0f) + 1.0f : 1.0f;
					totalpower += (modifier * ((float) rcno->getContents()));
				}
			}
		}
	}

	return floor(totalpower);
}

void PlayerImplementation::subtractInventoryPower(uint32 amount) {
	if (amount <= 0)
		return;

	for (int i = 0; i < inventory->getContainerObjectsSize(); i++) {
		SceneObject* object = inventory->getObject(i);

		if (object != NULL && object->isTangible()) {
			TangibleObject* tangible = (TangibleObject*) object;

			if (tangible->isResource()) {
				ResourceContainer* rcno = (ResourceContainer*) tangible;

				if (rcno->isEnergy()) {
					//Calculate the resources power potential.
					uint32 pe = rcno->getPotentialEnergy();
					float modifier = (pe > 500) ? (((float) (pe - 500)) / 500.0f) + 1.0f : 1.0f;
					float containerpower = (modifier * ((float) rcno->getContents()));

					if (containerpower > amount) {
						//This container is enough to satisfy the cost.
						containerpower -= amount;
						float newcontents = floor(containerpower / modifier);
						newcontents = (newcontents < 0) ? 0 : newcontents;
						rcno->setContents((uint32) newcontents);
						rcno->sendDeltas(_this);
						return;
					} else {
						//We are going to need to remove this container totally and go to the next.
						amount -= (uint32)containerpower;
						removeInventoryItem(rcno);
						rcno->sendDestroyTo(_this);
						rcno->finalize();
					}
				}
			}
		}
	}
}


// Event Handlers

/**
 * This event handler takes place when the player has successfully incapacitated a target.
 * \param victim The victim of the incapacitation.
 */
void PlayerImplementation::onIncapacitateTarget(CreatureObject* victim) {
	SceneObjectImplementation::onIncapacitateTarget(victim);
	sendSystemMessage("base_player", "prose_target_incap", victim->getObjectID()); //You incapacitate %TT.
}

/**
 * This event handler takes place when a player is set as incapacitated.
 * \param attacker The object that caused the incapacitation
 */
void PlayerImplementation::onIncapacitated(SceneObject* attacker) {
	//Dismount has to take place before clearStates! ClearStates() also
	//clears the "mount state" so we need to check "isRidingMount()" before cleared

	if (attacker != _this && attacker != NULL)
		attacker->unlock();

	try {

		if (doDancing)
			stopDancing();
		else if (doPlayingMusic)
			stopPlayingMusic();
	} catch (...) {
		error("unreported exception caught in void PlayerImplementation::onIncapacitated(SceneObject* attacker)");
	}

	if (attacker != _this && attacker != NULL)
		attacker->wlock(_this);

	if (isRidingMount())
		dismount(true, true);

	updateIncapacitationCounter();
	clearCombatState();
	clearStates();

	if (getIncapacitationCounter() < 3) {
		setPosture(CreaturePosture::INCAPACITATED);

		if (attacker != NULL)
			sendSystemMessage("base_player", "prose_victim_incap", attacker->getObjectID()); //You have been incapacitated by %TT.
		else
			sendSystemMessage("base_player", "victim_incapacitated"); //You have become incapacitated.

		uint32 incapTime = calculateIncapacitationTimer();
		sendIncapacitationTimer(incapTime);

	} else {
		if (!isFirstIncapacitationExpired()) {
			if (attacker != NULL)
				attacker->deathblow(_this);
			else
				die();
		}
	}
}

/**
 * This event handler gets first after the action die() takes place.
 */
void PlayerImplementation::onDeath() {
	//Dismount has to take place before clearStates! ClearStates() also
	//clears the "mount state" so we need to check "isRidingMount()" before cleared
	if (isRidingMount())
		dismount(true, true);

	if (powerboosted) {
		removePowerboost();
	}

	clearDuelList();
	clearCombatState(true);
	clearStates();
	setPosture(CreaturePosture::DEAD);

	clearBuffs(true);
	resetArmorEncumbrance();

	cancelRecoveryEvent();

	//TODO: Start Revive Countdown
	sendActivateCloneRequest();

	CreatureObjectImplementation::onDeath();
}

/**
 * This event hanlder is fired when being the target of a kill()
 */
void PlayerImplementation::onKilled(SceneObject* killer) {
	sendSystemMessage("base_player", "victim_dead"); //You have died. Requesting clone activation...
	die();
}

/**
 * onDeathblow takes place after the deathblow action has been fired. It handles what the creature does that is performing the deathblow.
 * \param victim Player is the target of the deathblow. Only players can be deathblown. NPC's are just killed.
 */
void PlayerImplementation::onDeathblow(Player* victim) {
	clearCombatState(true);

	sendSystemMessage("base_player", "prose_target_dead", victim->getObjectID()); //%TT is no more.

	if (!isInDuelWith(victim, false)) {
		if (hatesFaction(victim->getFaction())) {
			String victimsFaction = (victim->isImperial()) ? "imperial" : "rebel";
			String killersFaction = (isImperial()) ? "imperial" : "rebel";

			subtractFactionPoints(victimsFaction, 45);
			addFactionPoints(killersFaction, 45);
		}
	} else {
		increasePvpRating(victim);
	}
}

/**
 * onReceiveDeathblow handles what happens to the victim of the deathblow. Do they lose faction? PVP Rating etc.
 * \param killer Killer is the performer of the deathblow.
 */
void PlayerImplementation::onReceiveDeathblow(SceneObject* killer) {
	sendSystemMessage("base_player", "prose_victim_dead", killer->getObjectID()); //You were slain by %TT. Requesting clone activation...

	if (killer->isPlayer()) {
		Player* playerKiller = (Player*) killer;

		if (!isInDuelWith(playerKiller, false)) {
			if (hatesFaction(playerKiller->getFaction())) {
				String victimsFaction = (isImperial()) ? "imperial" : "rebel";
				subtractFactionPoints(victimsFaction, 30);
			}
		} else {
			decreasePvpRating(playerKiller);
		}

		if (playerKiller->requestedDuelTo(_this)) {
			playerKiller->removeFromDuelList(_this);

			BaseMessage* pvpstat = new UpdatePVPStatusMessage(playerKiller, playerKiller->getPvpStatusBitmask());
			sendMessage(pvpstat);

			ChatSystemMessage* csm = new ChatSystemMessage("duel", "end_self", playerKiller->getObjectID());
			sendMessage(csm);

			BaseMessage* pvpstat2 = new UpdatePVPStatusMessage(_this, getPvpStatusBitmask());
			playerKiller->sendMessage(pvpstat2);

			ChatSystemMessage* csm2 = new ChatSystemMessage("duel", "end_target", getObjectID());
			playerKiller->sendMessage(csm2);
		}

		if (requestedDuelTo(playerKiller))
			removeFromDuelList(playerKiller);
	}

	die();
}

/**
 * This event handler takes place after the player has received a potion of pvp rating.
 * \param victim The player who was slain.
 */
void PlayerImplementation::onPvpRatingGained(Player* victim) {
	StfParameter* params = new StfParameter();
	String messages[3] = {"win1", "win2", "win3"};
	params->addTT(victim->getObjectID());
	params->addDI(getPvpRating());
	sendSystemMessage("pvp_rating", messages[System::random(2)], params);
	delete params;
	//TODO: Put in PVP Rating Throttling.
}

/**
 * This event handler takes place after the player has lost a portion of pvp rating.
 * \param killer The player that did the killing...
 */
void PlayerImplementation::onPvpRatingLost(Player* killer) {
	StfParameter* params = new StfParameter();
	String messages[3] = {"killed1", "killed2", "killed3"};
	params->addTT(killer->getObjectID());
	params->addDI(getPvpRating());
	sendSystemMessage("pvp_rating", messages[System::random(2)], params);
	delete params;
	//TODO: Put in PVP Rating Throttling.
}

/**
 * This event hanlder is executed when the player's pvp rating could not increase anymore from the player they killed.
 */

void PlayerImplementation::onPvpRatingGainedThrottled() {
}

/**
 * This event handler is executed when the player's pvp rating can not decrease anymore from dying to their killer.
 */
void PlayerImplementation::onPvpRatingLostThrottled() {
}

/**
 * This event handler is executed when a badge is awarded.
 * \param badge The badge that was awareded.
 */
void PlayerImplementation::onBadgeAwarded(Badge* badge) {

}

/**
 * This event handler is executed when a badge is revoked.
 * \param badge The badge that was revoked.
 */
void PlayerImplementation::onBadgeRevoked(Badge* badge) {

}

/**
 * This event handler is executed when experience is gained.
 * \param xptype String value corresponding with the client side .tre files indicating why type of xp was gained.
 * \param amount How much experience was gained.
 */
void PlayerImplementation::onExperienceGained(const String& xptype, uint32 amount) {

}

/**
 * This event handler is executed when experience is lost.
 * \param xptype String value corresponding with the client side .tre files indicating why type of xp was lost.
 * \param amount How much experience was lost.
 */
void PlayerImplementation::onExperienceLost(const String& xptype, uint32 amount) {

}

/// This event handler is executed when clone data has been stored.
void PlayerImplementation::onCloneDataStored() {
	sendSystemMessage("base_player", "clone_success"); //Clone location successfully updated.
}

/// This event is fired when an attempt to store clone data is made at a facility where it is already stored.
void PlayerImplementation::onCloneDataAlreadyStored() {
	sendSystemMessage("You have already stored your clone data at this location.");
}

/// This event should follow after successfully cloning.
void PlayerImplementation::onClone() {

	setPosture(CreaturePosture::UPRIGHT);

	rescheduleRecovery(3000);
}

void PlayerImplementation::onResuscitated(SceneObject* healer) {
	CreatureObjectImplementation::onResuscitated(healer);

	if (hasSuiBoxWindowType(SuiWindowType::CLONE_REQUEST))
		closeSuiWindowType(SuiWindowType::CLONE_REQUEST);

	rescheduleRecovery(1000);
}

/**
 * This event handler takes place after makePaymentTo.
 * \param target The target of the payment. If null, then money is simply lost.
 * \param cost The amount of the payment.
 */
void PlayerImplementation::onMakePaymentTo(SceneObject* target, uint32 cost) {
	StfParameter* params = new StfParameter();
	params->addDI(cost);

	if (target != NULL) {
		if (target->isPlayer() || target->isNonPlayerCreature()) {
			params->addTT(target->getObjectID());
			sendSystemMessage("base_player", "prose_pay_success", params); //You successfully make a payment of %DI credits to %TO.
		} else {
			params->addTO(target->getObjectID());
			sendSystemMessage("base_player", "prose_pay_acct_success", params); //You successfull make a payment of %DI credits to %TT.
		}
	} else {
		sendSystemMessage("base_player", "prose_pay_success_no_target", params); //You successfully make a payment of %DI credits.
	}

	delete params;

}

void PlayerImplementation::onMakeBankPaymentTo(SceneObject* target, uint32 cost) {

}

/**
 * This event is fired when insufficient funds are available to make a payment.
 * \param target The target of the payment.
 * \param amount The amount of the payment.
 */
void PlayerImplementation::onInsufficientFundsAvailable(SceneObject* target, uint32 amount) {
	StfParameter* params = new StfParameter();
	params->addDI(amount);

	if (target != NULL) {
		params->addTT(target->getObjectID());
		sendSystemMessage("error_message", "prose_pay_nsf", params); //You have insufficient funds to pay %DI credits to %TT.
	} else {
		//TODO: Add in string for no object.
	}

	delete params;
}

/**
 * This event is fired when an item has successfully been insured.
 * \param itemID The objectID of the item being insured.
 */

void PlayerImplementation::onInsureItemSuccess(uint64 itemID) {
	StfParameter* params = new StfParameter();
	params->addTT(itemID);
	sendSystemMessage("base_player", "prose_insure_success", params); //You successfully insure your %TT.
	delete params;
}

/**
 * This event is fired when an item failed to be insured for any reason.
 * \param itemID The objectID of the item being insured.
 */

void PlayerImplementation::onInsureItemFailure(uint64 itemID) {
	StfParameter* params = new StfParameter();
	params->addTT(itemID);
	sendSystemMessage("error_message", "prose_insure_fail", params); //An attempt to insure your %TT has failed. Most likely, this is due to lack of funds.
	delete params;
}

/**
 * This event is fired when insufficient funds are available to pay for the insurance of an item.
 * \param itemID The objectID of the item attempting to be insured.
 */
void PlayerImplementation::onInsureItemInsufficientFunds(uint64 itemID) {
	StfParameter* params = new StfParameter();
	params->addTT(itemID);
	sendSystemMessage("error_message", "prose_nsf_insure", params); //You have insufficient funds to insure your %TT.
	delete params;
}

/// This event is fired when an attempt to insure an item from an invalid insurance terminal is made.
void PlayerImplementation::onInsureItemInvalidTerminal() {
	sendSystemMessage("Insurance failed because the insurance terminal was invalid.");
}

/// This event is fired when all items have been successfully insured.
void PlayerImplementation::onInsureAllItemsComplete() {
	sendSystemMessage("base_player", "insure_success");
}

/// This event is fired when a player tries to insure items, but has no valid items to insure.
void PlayerImplementation::onNoValidInsurables() {
	sendSystemMessage("error_message", "no_uninsured_insurables"); //You do not posses any items that can be insured at this time.
}

/// This event is fired when a bank tip has completed successfully to an offline recipient.
void PlayerImplementation::onBankTipSuccessful() {
	sendSystemMessage("base_player", "wire_pass_self"); //Your /tip transaction was successfully completed.
}

void PlayerImplementation::registerPet(CreaturePet* pet) {
	pet->setPositionNumber(petList.size());
	petList.put(pet->getObjectID(),pet);
}

void PlayerImplementation::unregisterPet(CreaturePet* pet) {
	petList.drop(pet->getObjectID());

	for (int i = 0 ; i < petList.size() ; i++) {
		petList.get(i)->setPositionNumber(i);
	}
}

void PlayerImplementation::sendMessageToPets(const UnicodeString& message, uint64 petID) {
	if (petID != 0) {
		CreaturePet* pet = petList.get(petID);

		if (pet == NULL)
			return;

		if (isInRange(pet,128.0f)) {
			try {
				pet->lock();
				pet->parseCommandMessage(_this,message);
				pet->unlock();
			} catch (...) {
				pet->unlock();
				System::out << "exception PlayerImplementation::sendMessageToPets\n";
			}
		}
		return;
	}
	for (int i = 0 ; i < petList.size() ; i++) {
		CreaturePet* pet = petList.get(i);
		if (isInRange(pet,128.0f)) {
			try {
				pet->lock();
				pet->parseCommandMessage(_this,message);
				pet->unlock();
			} catch (...) {
				pet->unlock();
				System::out << "exception PlayerImplementation::sendMessageToPets\n";
			}
		}
	}
}

void PlayerImplementation::enragePets() {
	for (int i = 0 ; i < petList.size() ; i++) {
		CreaturePet* pet = petList.get(i);
		if (isInRange(pet,128.0f) && pet->isCHPet()) {
			try {
				pet->lock();
				pet->handleEnrageCommand();
				pet->unlock();
			} catch (...) {
				pet->unlock();
				System::out << "exception PlayerImplementation::sendMessageToPets\n";
			}
		}
	}
}

void PlayerImplementation::emboldenPets() {
	for (int i = 0 ; i < petList.size() ; i++) {
		CreaturePet* pet = petList.get(i);
		if (isInRange(pet,128.0f) && pet->isCHPet()) {
			try {
				pet->lock();
				pet->handleEmboldenCommand();
				pet->unlock();
			} catch (...) {
				pet->unlock();
				System::out << "exception PlayerImplementation::sendMessageToPets\n";
			}
		}
	}
}
bool PlayerImplementation::canStoreMorePets() {
	int chPet = 0;
	int chPetNumMax = getSkillMod("stored_pets");

	if (datapad == NULL)
		return false;
	for (int i = 0; i < datapad->getContainerObjectsSize(); ++i) {
		SceneObject* item = datapad->getObject(i);
		if (item->isIntangible()) {
			if (item->isIntangible()) {
				IntangibleObject* itno = (IntangibleObject*)item;
				SceneObject* worldObject = itno->getWorldObject();

				if (worldObject->isNonPlayerCreature()) {
					CreatureObject* crea = (Creature*) worldObject;
					if (crea->isPet()) {
						if (((CreaturePet*)crea)->isCHPet())
							chPet++;
					}
				}
			}
		}
	}

	if (chPetNumMax == 0)
		chPetNumMax = 1;

	return (chPetNumMax > chPet);
}
