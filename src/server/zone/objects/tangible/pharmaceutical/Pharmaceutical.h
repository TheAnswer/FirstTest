/*
 *	server/zone/objects/tangible/pharmaceutical/Pharmaceutical.h generated by engine3 IDL compiler 0.55
 */

#ifndef PHARMACEUTICAL_H_
#define PHARMACEUTICAL_H_

#include "engine/orb/DistributedObjectBroker.h"

class SceneObject;

class CreatureObject;

class Player;

class TangibleObject;

#include "../TangibleObject.h"

class Pharmaceutical : public TangibleObject {
public:
	Pharmaceutical(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int mptype);

	Pharmaceutical(CreatureObject* creature, unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int mptype);

	Pharmaceutical(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int mptype);

	void sendDeltas(Player* player);

	void generateAttributes(SceneObject* obj);

	void useCharge(Player* player);

	void setUsesRemaining(int uses);

	void setMedicineUseRequired(int meduse);

	void setMedpackType(int mptype);

	int getUsesRemaining();

	int getMedicineUseRequired();

	int getMedpackType();

	bool isEnhancePack();

	bool isWoundPack();

	bool isStimPack();

	bool isStatePack();

	bool isCurePack();

	bool isRevivePack();

	bool isRangedStimPack();

	bool isPoisonDeliveryUnit();

	bool isDiseaseDeliveryUnit();

	bool isGeneralMedicItem();

	bool isCombatMedicItem();

	bool isArea();

	float getRange(CreatureObject* creature = NULL);

	float getArea();

protected:
	Pharmaceutical(DummyConstructorParameter* param);

	virtual ~Pharmaceutical();

	friend class PharmaceuticalHelper;
};

class PharmaceuticalImplementation;

class PharmaceuticalAdapter : public TangibleObjectAdapter {
public:
	PharmaceuticalAdapter(PharmaceuticalImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void sendDeltas(Player* player);

	void generateAttributes(SceneObject* obj);

	void useCharge(Player* player);

	void setUsesRemaining(int uses);

	void setMedicineUseRequired(int meduse);

	void setMedpackType(int mptype);

	int getUsesRemaining();

	int getMedicineUseRequired();

	int getMedpackType();

	bool isEnhancePack();

	bool isWoundPack();

	bool isStimPack();

	bool isStatePack();

	bool isCurePack();

	bool isRevivePack();

	bool isRangedStimPack();

	bool isPoisonDeliveryUnit();

	bool isDiseaseDeliveryUnit();

	bool isGeneralMedicItem();

	bool isCombatMedicItem();

	bool isArea();

	float getRange(CreatureObject* creature);

	float getArea();

};

class PharmaceuticalHelper : public DistributedObjectClassHelper, public Singleton<PharmaceuticalHelper> {
	static PharmaceuticalHelper* staticInitializer;

public:
	PharmaceuticalHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<PharmaceuticalHelper>;
};

#include "../TangibleObjectImplementation.h"

class PharmaceuticalServant : public TangibleObjectImplementation {
public:
	Pharmaceutical* _this;

public:
	PharmaceuticalServant(unsigned long long oid, int tp);
	virtual ~PharmaceuticalServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*PHARMACEUTICAL_H_*/
