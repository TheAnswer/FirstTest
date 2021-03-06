/*
 *	server/zone/objects/area/ActiveArea.h generated by engine3 IDL compiler 0.55
 */

#ifndef ACTIVEAREA_H_
#define ACTIVEAREA_H_

#include "engine/orb/DistributedObjectBroker.h"

class Area;

class Player;

#include "Area.h"

class ActiveArea : public Area {
public:
	ActiveArea(float x, float y, float z, float radius);

	void onEnter(Player* player);

	void onExit(Player* player);

protected:
	ActiveArea(DummyConstructorParameter* param);

	virtual ~ActiveArea();

	friend class ActiveAreaHelper;
};

class ActiveAreaImplementation;

class ActiveAreaAdapter : public AreaAdapter {
public:
	ActiveAreaAdapter(ActiveAreaImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void onEnter(Player* player);

	void onExit(Player* player);

};

class ActiveAreaHelper : public DistributedObjectClassHelper, public Singleton<ActiveAreaHelper> {
	static ActiveAreaHelper* staticInitializer;

public:
	ActiveAreaHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<ActiveAreaHelper>;
};

#include "AreaImplementation.h"

class ActiveAreaServant : public AreaImplementation {
public:
	ActiveArea* _this;

public:
	ActiveAreaServant(float x, float y, float z, float radius);
	virtual ~ActiveAreaServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*ACTIVEAREA_H_*/
