/*
 *	server/zone/managers/bazaar/BazaarPlanetManager.h generated by engine3 IDL compiler 0.55
 */

#ifndef BAZAARPLANETMANAGER_H_
#define BAZAARPLANETMANAGER_H_

#include "engine/orb/DistributedObjectBroker.h"

class AuctionItem;

class Player;

class RegionBazaar;

#include "../../ZoneProcessServerImplementation.h"

#include "BazaarTerminalDetails.h"

class BazaarPlanetManager : public DistributedObjectStub {
public:
	BazaarPlanetManager(int planet);

	void setPlanet(int planet);

	void addBazaarItem(AuctionItem* item);

	void removeBazaarItem(long long objectid);

	void addBazaar(BazaarTerminalDetails* terminal);

	void getBazaarData(Player* player, long long objectid, int screen, int extent, unsigned int category, int count, int offset);

protected:
	BazaarPlanetManager(DummyConstructorParameter* param);

	virtual ~BazaarPlanetManager();

	friend class BazaarPlanetManagerHelper;
};

class BazaarPlanetManagerImplementation;

class BazaarPlanetManagerAdapter : public DistributedObjectAdapter {
public:
	BazaarPlanetManagerAdapter(BazaarPlanetManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void setPlanet(int planet);

	void addBazaarItem(AuctionItem* item);

	void removeBazaarItem(long long objectid);

	void addBazaar(BazaarTerminalDetails* terminal);

	void getBazaarData(Player* player, long long objectid, int screen, int extent, unsigned int category, int count, int offset);

};

class BazaarPlanetManagerHelper : public DistributedObjectClassHelper, public Singleton<BazaarPlanetManagerHelper> {
	static BazaarPlanetManagerHelper* staticInitializer;

public:
	BazaarPlanetManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<BazaarPlanetManagerHelper>;
};

class BazaarPlanetManagerServant : public DistributedObjectServant {
public:
	BazaarPlanetManager* _this;

public:
	BazaarPlanetManagerServant();
	virtual ~BazaarPlanetManagerServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*BAZAARPLANETMANAGER_H_*/
