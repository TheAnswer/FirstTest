/*
 *	server/zone/objects/structure/installation/factory/FactoryObject.h generated by engine3 IDL compiler 0.55
 */

#ifndef FACTORYOBJECT_H_
#define FACTORYOBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

class InstallationDeed;

class InstallationObject;

#include "../InstallationObject.h"

class FactoryObject : public InstallationObject {
public:
	FactoryObject(unsigned long long objid);

	FactoryObject(unsigned long long objid, InstallationDeed* theDeed);

	void setHopperSizeMax(float size);

	void setFactoryType(unsigned char type);

	float getHopperSizeMax();

	unsigned char getFactoryType();

protected:
	FactoryObject(DummyConstructorParameter* param);

	virtual ~FactoryObject();

	friend class FactoryObjectHelper;
};

class FactoryObjectImplementation;

class FactoryObjectAdapter : public InstallationObjectAdapter {
public:
	FactoryObjectAdapter(FactoryObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void setHopperSizeMax(float size);

	void setFactoryType(unsigned char type);

	float getHopperSizeMax();

	unsigned char getFactoryType();

};

class FactoryObjectHelper : public DistributedObjectClassHelper, public Singleton<FactoryObjectHelper> {
	static FactoryObjectHelper* staticInitializer;

public:
	FactoryObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<FactoryObjectHelper>;
};

#include "../InstallationObjectImplementation.h"

class FactoryObjectServant : public InstallationObjectImplementation {
public:
	FactoryObject* _this;

public:
	FactoryObjectServant(unsigned long long objid);
	virtual ~FactoryObjectServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*FACTORYOBJECT_H_*/
