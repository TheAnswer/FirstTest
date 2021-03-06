/*
 *	server/zone/objects/tangible/wearables/Wearable.h generated by engine3 IDL compiler 0.55
 */

#ifndef WEARABLE_H_
#define WEARABLE_H_

#include "engine/orb/DistributedObjectBroker.h"

class CreatureObject;

class Player;

class SceneObject;

class TangibleObject;

class Attachment;

#include "../TangibleObject.h"

class Wearable : public TangibleObject {
public:
	Wearable(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, bool eqp = false);

	Wearable(CreatureObject* creature, unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, bool eqp = false);

	Wearable(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempn, bool eqp = false);

	void parseItemAttributes();

	void init();

	void generateAttributes(SceneObject* obj);

	void sendTo(Player* player, bool doClose = true);

	bool hasSkillMod(String& skillModName);

	void setMaxSockets(int socket);

	void setHealthEncumbrance(int healthEnc);

	void setActionEncumbrance(int actionEnc);

	void setMindEncumbrance(int mindEnc);

	String& getSkillModType(int i);

	int getSkillModValue(String& name);

	int getMaxSockets();

	int socketsUsed();

	int getHealthEncumbrance();

	int getActionEncumbrance();

	int getMindEncumbrance();

	void applyAttachment(Player* player, Attachment* attachment);

	void reclaimAttachments(Player* player);

	void conditionReduction(float damage);

protected:
	Wearable(DummyConstructorParameter* param);

	virtual ~Wearable();

	String _return_getSkillModType;

	friend class WearableHelper;
};

class WearableImplementation;

class WearableAdapter : public TangibleObjectAdapter {
public:
	WearableAdapter(WearableImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void parseItemAttributes();

	void init();

	void generateAttributes(SceneObject* obj);

	void sendTo(Player* player, bool doClose);

	bool hasSkillMod(String& skillModName);

	void setMaxSockets(int socket);

	void setHealthEncumbrance(int healthEnc);

	void setActionEncumbrance(int actionEnc);

	void setMindEncumbrance(int mindEnc);

	String& getSkillModType(int i);

	int getSkillModValue(String& name);

	int getMaxSockets();

	int socketsUsed();

	int getHealthEncumbrance();

	int getActionEncumbrance();

	int getMindEncumbrance();

	void applyAttachment(Player* player, Attachment* attachment);

	void reclaimAttachments(Player* player);

	void conditionReduction(float damage);

protected:
	String _param0_hasSkillMod__String_;
	String _param0_getSkillModValue__String_;
};

class WearableHelper : public DistributedObjectClassHelper, public Singleton<WearableHelper> {
	static WearableHelper* staticInitializer;

public:
	WearableHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<WearableHelper>;
};

#include "../TangibleObjectImplementation.h"

class WearableServant : public TangibleObjectImplementation {
public:
	Wearable* _this;

public:
	WearableServant(unsigned long long oid, int tp);
	virtual ~WearableServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*WEARABLE_H_*/
