/*
 *	server/zone/objects/tangible/tools/repairtool/RepairTool.h generated by engine3 IDL compiler 0.55
 */

#ifndef REPAIRTOOL_H_
#define REPAIRTOOL_H_

#include "engine/orb/DistributedObjectBroker.h"

class Tool;

class SceneObject;

class CreatureObject;

class Player;

#include "../Tool.h"

class RepairTool : public Tool {
public:
	RepairTool(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn);

	RepairTool(CreatureObject* creature, unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn);

	void generateAttributes(SceneObject* obj);

	int useObject(Player* player);

	void setQuality(int q);

	int getQuality();

protected:
	RepairTool(DummyConstructorParameter* param);

	virtual ~RepairTool();

	friend class RepairToolHelper;
};

class RepairToolImplementation;

class RepairToolAdapter : public ToolAdapter {
public:
	RepairToolAdapter(RepairToolImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void generateAttributes(SceneObject* obj);

	int useObject(Player* player);

	void setQuality(int q);

	int getQuality();

};

class RepairToolHelper : public DistributedObjectClassHelper, public Singleton<RepairToolHelper> {
	static RepairToolHelper* staticInitializer;

public:
	RepairToolHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<RepairToolHelper>;
};

#include "../ToolImplementation.h"

class RepairToolServant : public ToolImplementation {
public:
	RepairTool* _this;

public:
	RepairToolServant(unsigned long long oid, unsigned int type);
	virtual ~RepairToolServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*REPAIRTOOL_H_*/
