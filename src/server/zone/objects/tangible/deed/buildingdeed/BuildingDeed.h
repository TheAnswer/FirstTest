/*
 *	server/zone/objects/tangible/deed/buildingdeed/BuildingDeed.h generated by engine3 IDL compiler 0.55
 */

#ifndef BUILDINGDEED_H_
#define BUILDINGDEED_H_

#include "engine/orb/DistributedObjectBroker.h"

class DeedObject;

class CreatureObject;

class Player;

class SceneObject;

#include "../DeedObject.h"

class BuildingDeed : public DeedObject {
public:
	BuildingDeed(CreatureObject* creature, unsigned int objcrc, const UnicodeString& customname, const String& stfname);

	BuildingDeed(unsigned long long objid, unsigned int objcrc, const UnicodeString& customname, const String& stfname);

	int useObject(Player* player);

	SceneObject* generateObject(Player* player);

	void parseItemAttributes();

	void setReclaimFee(unsigned int fee);

	void setMaintenanceRate(float rate);

	void setSurplusMaintenance(unsigned int maint);

	void setTargetConstructionObjectCRC(unsigned int objcrc);

	void setTargetConditionMax(unsigned int condmax);

	void setLotSize(unsigned char lotsize);

	void setCellCount(unsigned int cellcount);

	float getMaintenanceRate();

	unsigned int getSurplusMaintenance();

	unsigned int getTargetConstructionObjectCRC();

	unsigned int getCellCount();

	unsigned int getReclaimFee();

	bool isMaintenanceEmpty();

protected:
	BuildingDeed(DummyConstructorParameter* param);

	virtual ~BuildingDeed();

	friend class BuildingDeedHelper;
};

class BuildingDeedImplementation;

class BuildingDeedAdapter : public DeedObjectAdapter {
public:
	BuildingDeedAdapter(BuildingDeedImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int useObject(Player* player);

	SceneObject* generateObject(Player* player);

	void parseItemAttributes();

	void setReclaimFee(unsigned int fee);

	void setMaintenanceRate(float rate);

	void setSurplusMaintenance(unsigned int maint);

	void setTargetConstructionObjectCRC(unsigned int objcrc);

	void setTargetConditionMax(unsigned int condmax);

	void setLotSize(unsigned char lotsize);

	void setCellCount(unsigned int cellcount);

	float getMaintenanceRate();

	unsigned int getSurplusMaintenance();

	unsigned int getTargetConstructionObjectCRC();

	unsigned int getCellCount();

	unsigned int getReclaimFee();

	bool isMaintenanceEmpty();

};

class BuildingDeedHelper : public DistributedObjectClassHelper, public Singleton<BuildingDeedHelper> {
	static BuildingDeedHelper* staticInitializer;

public:
	BuildingDeedHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<BuildingDeedHelper>;
};

#include "../DeedObjectImplementation.h"

class BuildingDeedServant : public DeedObjectImplementation {
public:
	BuildingDeed* _this;

public:
	BuildingDeedServant(CreatureObject* creature, unsigned int objcrc, const UnicodeString& customname, const String& stfname);
	BuildingDeedServant(unsigned long long objid, unsigned int objcrc, const UnicodeString& customname, const String& stfname);
	virtual ~BuildingDeedServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*BUILDINGDEED_H_*/
