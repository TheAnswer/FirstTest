/*
 *	server/zone/objects/creature/recruiter/imperial/ImperialRecruiterCreature.h generated by engine3 IDL compiler 0.55
 */

#ifndef IMPERIALRECRUITERCREATURE_H_
#define IMPERIALRECRUITERCREATURE_H_

#include "engine/orb/DistributedObjectBroker.h"

class RecruiterCreature;

#include "../RecruiterCreature.h"

class ImperialRecruiterCreature : public RecruiterCreature {
public:
	ImperialRecruiterCreature(unsigned long long oid);

protected:
	ImperialRecruiterCreature(DummyConstructorParameter* param);

	virtual ~ImperialRecruiterCreature();

	friend class ImperialRecruiterCreatureHelper;
};

class ImperialRecruiterCreatureImplementation;

class ImperialRecruiterCreatureAdapter : public RecruiterCreatureAdapter {
public:
	ImperialRecruiterCreatureAdapter(ImperialRecruiterCreatureImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

};

class ImperialRecruiterCreatureHelper : public DistributedObjectClassHelper, public Singleton<ImperialRecruiterCreatureHelper> {
	static ImperialRecruiterCreatureHelper* staticInitializer;

public:
	ImperialRecruiterCreatureHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<ImperialRecruiterCreatureHelper>;
};

#include "../RecruiterCreatureImplementation.h"

class ImperialRecruiterCreatureServant : public RecruiterCreatureImplementation {
public:
	ImperialRecruiterCreature* _this;

public:
	ImperialRecruiterCreatureServant(unsigned long long oid);
	virtual ~ImperialRecruiterCreatureServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*IMPERIALRECRUITERCREATURE_H_*/
