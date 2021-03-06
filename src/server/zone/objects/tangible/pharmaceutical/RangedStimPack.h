/*
 *	server/zone/objects/tangible/pharmaceutical/RangedStimPack.h generated by engine3 IDL compiler 0.55
 */

#ifndef RANGEDSTIMPACK_H_
#define RANGEDSTIMPACK_H_

#include "engine/orb/DistributedObjectBroker.h"

class SceneObject;

class CreatureObject;

class Player;

class TangibleObject;

class StimPack;

#include "StimPack.h"

class RangedStimPack : public StimPack {
public:
	RangedStimPack(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn);

	RangedStimPack(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempn);

	void generateAttributes(SceneObject* obj);

	unsigned int calculatePower(CreatureObject* healer, CreatureObject* patient, bool applyBattleFatigue = true);

	void setEffectiveness(float eff);

	float getEffectiveness();

	void setRange(float rng);

	float getRange(CreatureObject* creature = NULL);

	void setArea(float ar);

	float getArea();

protected:
	RangedStimPack(DummyConstructorParameter* param);

	virtual ~RangedStimPack();

	friend class RangedStimPackHelper;
};

class RangedStimPackImplementation;

class RangedStimPackAdapter : public StimPackAdapter {
public:
	RangedStimPackAdapter(RangedStimPackImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void generateAttributes(SceneObject* obj);

	unsigned int calculatePower(CreatureObject* healer, CreatureObject* patient, bool applyBattleFatigue);

	void setEffectiveness(float eff);

	float getEffectiveness();

	void setRange(float rng);

	float getRange(CreatureObject* creature);

	void setArea(float ar);

	float getArea();

};

class RangedStimPackHelper : public DistributedObjectClassHelper, public Singleton<RangedStimPackHelper> {
	static RangedStimPackHelper* staticInitializer;

public:
	RangedStimPackHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<RangedStimPackHelper>;
};

#include "StimPackImplementation.h"

class RangedStimPackServant : public StimPackImplementation {
public:
	RangedStimPack* _this;

public:
	RangedStimPackServant(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn);
	RangedStimPackServant(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempn);
	virtual ~RangedStimPackServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*RANGEDSTIMPACK_H_*/
