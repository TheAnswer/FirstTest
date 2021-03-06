/*
 *	server/zone/objects/creature/pet/CreaturePet.h generated by engine3 IDL compiler 0.55
 */

#ifndef CREATUREPET_H_
#define CREATUREPET_H_

#include "engine/orb/DistributedObjectBroker.h"

class CreatureManagerImplementation;

class Creature;

class CreatureObject;

class Player;

class IntangibleObject;

class SceneObject;

#include "../Creature.h"

class CreaturePet : public Creature {
public:
	CreaturePet(Player* owner, unsigned long long oid);

	void init(Creature* creature, float growth);

	void createDataPad(unsigned long long datapadCRC);

	void setPetType(unsigned char type);

	void setLinkedCreature(Player* linkCreature);

	Player* getLinkedCreature();

	void setDatapadItem(SceneObject* item);

	IntangibleObject* getDatapadItem();

	Player* getFollowTarget();

	void parseItemAttributes();

	void call();

	void store(bool doLock = true);

	bool canCall();

	bool isAttackable();

	bool isAttackableBy(CreatureObject* creature);

	void onIncapacitated(SceneObject* attacker);

	void recoverFromIncapacitation();

	void setFaction(unsigned int fac);

	void setMaxLevel(unsigned int level);

	bool isCHPet();

	bool isDroid();

	bool isFactionPet();

	bool isInFollowState();

	bool isInStayState();

	bool isInGuardState();

	bool isInPatrolState();

	void doGrowUp(bool updateTime = true);

	void setGrowth(float gr);

	void setLastGrowth(unsigned long long stamp);

	void initTrainingState(int command);

	void setPetName(String& name);

	void parseCommandMessage(Player* player, const UnicodeString& message);

	void setCommmandState(int command);

	bool hasCommandTrained(unsigned int state);

	bool activate();

	void deaggro();

	void handleAttackCommand(Player* player);

	void handleFollowCommand(Player* target);

	void handleStayCommand();

	void handleGuardCommand();

	void handleStoreCommand();

	void handleTransferCommand();

	void handleTrickCommand(String& anim, int mod, int cost);

	void handleEnrageCommand();

	void handleEmboldenCommand();

	void handleSpecialAttackCommand(Player* player, int att);

	void handleGroupCommand(Player* player);

	void handleFriendCommand();

	void handleFormationCommand(unsigned int form);

	void handleAddPatrolPointCommand(Player* player);

	void handleActivatePatrolCommand();

	void handleClearPatrolPointsCommand();

	void trainMount();

	void setPositionNumber(int posNumber);

protected:
	CreaturePet(DummyConstructorParameter* param);

	virtual ~CreaturePet();

	friend class CreaturePetHelper;
};

class CreaturePetImplementation;

class CreaturePetAdapter : public CreatureAdapter {
public:
	CreaturePetAdapter(CreaturePetImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void init(Creature* creature, float growth);

	void createDataPad(unsigned long long datapadCRC);

	void setPetType(unsigned char type);

	void setLinkedCreature(Player* linkCreature);

	Player* getLinkedCreature();

	void setDatapadItem(SceneObject* item);

	IntangibleObject* getDatapadItem();

	Player* getFollowTarget();

	void parseItemAttributes();

	void call();

	void store(bool doLock);

	bool canCall();

	bool isAttackable();

	bool isAttackableBy(CreatureObject* creature);

	void onIncapacitated(SceneObject* attacker);

	void recoverFromIncapacitation();

	void setFaction(unsigned int fac);

	void setMaxLevel(unsigned int level);

	bool isCHPet();

	bool isDroid();

	bool isFactionPet();

	bool isInFollowState();

	bool isInStayState();

	bool isInGuardState();

	bool isInPatrolState();

	void doGrowUp(bool updateTime);

	void setGrowth(float gr);

	void setLastGrowth(unsigned long long stamp);

	void initTrainingState(int command);

	void setPetName(String& name);

	void parseCommandMessage(Player* player, const UnicodeString& message);

	void setCommmandState(int command);

	bool hasCommandTrained(unsigned int state);

	bool activate();

	void deaggro();

	void handleAttackCommand(Player* player);

	void handleFollowCommand(Player* target);

	void handleStayCommand();

	void handleGuardCommand();

	void handleStoreCommand();

	void handleTransferCommand();

	void handleTrickCommand(String& anim, int mod, int cost);

	void handleEnrageCommand();

	void handleEmboldenCommand();

	void handleSpecialAttackCommand(Player* player, int att);

	void handleGroupCommand(Player* player);

	void handleFriendCommand();

	void handleFormationCommand(unsigned int form);

	void handleAddPatrolPointCommand(Player* player);

	void handleActivatePatrolCommand();

	void handleClearPatrolPointsCommand();

	void trainMount();

	void setPositionNumber(int posNumber);

protected:
	String _param0_setPetName__String_;
	UnicodeString _param1_parseCommandMessage__Player_UnicodeString_;
	String _param0_handleTrickCommand__String_int_int_;
};

class CreaturePetHelper : public DistributedObjectClassHelper, public Singleton<CreaturePetHelper> {
	static CreaturePetHelper* staticInitializer;

public:
	CreaturePetHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<CreaturePetHelper>;
};

#include "../CreatureImplementation.h"

class CreaturePetServant : public CreatureImplementation {
public:
	CreaturePet* _this;

public:
	CreaturePetServant(unsigned long long oid);
	virtual ~CreaturePetServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*CREATUREPET_H_*/
