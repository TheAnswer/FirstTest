/*
 *	server/zone/objects/tangible/deed/petdeed/PetDeed.h generated by engine3 IDL compiler 0.55
 */

#ifndef PETDEED_H_
#define PETDEED_H_

#include "engine/orb/DistributedObjectBroker.h"

class DeedObject;

class CreatureObject;

class Player;

class SceneObject;

#include "../DeedObject.h"

class PetDeed : public DeedObject {
public:
	PetDeed(CreatureObject* creature, unsigned int objcrc, const UnicodeString& customname, const String& stfname);

	PetDeed(unsigned long long objid, unsigned int objcrc, const UnicodeString& customname, const String& stfname);

	int useObject(Player* player);

	SceneObject* generateObject(Player* player);

	void parseItemAttributes();

protected:
	PetDeed(DummyConstructorParameter* param);

	virtual ~PetDeed();

	friend class PetDeedHelper;
};

class PetDeedImplementation;

class PetDeedAdapter : public DeedObjectAdapter {
public:
	PetDeedAdapter(PetDeedImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int useObject(Player* player);

	SceneObject* generateObject(Player* player);

	void parseItemAttributes();

};

class PetDeedHelper : public DistributedObjectClassHelper, public Singleton<PetDeedHelper> {
	static PetDeedHelper* staticInitializer;

public:
	PetDeedHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<PetDeedHelper>;
};

#include "../DeedObjectImplementation.h"

class PetDeedServant : public DeedObjectImplementation {
public:
	PetDeed* _this;

public:
	PetDeedServant(CreatureObject* creature, unsigned int objcrc, const UnicodeString& customname, const String& stfname);
	PetDeedServant(unsigned long long objid, unsigned int objcrc, const UnicodeString& customname, const String& stfname);
	virtual ~PetDeedServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*PETDEED_H_*/
