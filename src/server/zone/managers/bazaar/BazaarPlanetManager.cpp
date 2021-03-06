/*
 *	server/zone/managers/bazaar/BazaarPlanetManager.cpp generated by engine3 IDL compiler 0.55
 */

#include "BazaarPlanetManager.h"

#include "BazaarPlanetManagerImplementation.h"

#include "../../objects/auction/AuctionItem.h"

#include "../../objects/player/Player.h"

#include "../../objects/tangible/terminal/bazaar/RegionBazaar.h"

/*
 *	BazaarPlanetManagerStub
 */

BazaarPlanetManager::BazaarPlanetManager(int planet) {
	_impl = new BazaarPlanetManagerImplementation(planet);
	_impl->_setStub(this);
}

BazaarPlanetManager::BazaarPlanetManager(DummyConstructorParameter* param) {
	_impl = NULL;
}

BazaarPlanetManager::~BazaarPlanetManager() {
}

void BazaarPlanetManager::setPlanet(int planet) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addSignedIntParameter(planet);

		method.executeWithVoidReturn();
	} else
		((BazaarPlanetManagerImplementation*) _impl)->setPlanet(planet);
}

void BazaarPlanetManager::addBazaarItem(AuctionItem* item) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(item);

		method.executeWithVoidReturn();
	} else
		((BazaarPlanetManagerImplementation*) _impl)->addBazaarItem(item);
}

void BazaarPlanetManager::removeBazaarItem(long long objectid) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addSignedLongParameter(objectid);

		method.executeWithVoidReturn();
	} else
		((BazaarPlanetManagerImplementation*) _impl)->removeBazaarItem(objectid);
}

void BazaarPlanetManager::addBazaar(BazaarTerminalDetails* terminal) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(terminal);

		method.executeWithVoidReturn();
	} else
		((BazaarPlanetManagerImplementation*) _impl)->addBazaar(terminal);
}

void BazaarPlanetManager::getBazaarData(Player* player, long long objectid, int screen, int extent, unsigned int category, int count, int offset) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addObjectParameter(player);
		method.addSignedLongParameter(objectid);
		method.addSignedIntParameter(screen);
		method.addSignedIntParameter(extent);
		method.addUnsignedIntParameter(category);
		method.addSignedIntParameter(count);
		method.addSignedIntParameter(offset);

		method.executeWithVoidReturn();
	} else
		((BazaarPlanetManagerImplementation*) _impl)->getBazaarData(player, objectid, screen, extent, category, count, offset);
}

/*
 *	BazaarPlanetManagerAdapter
 */

BazaarPlanetManagerAdapter::BazaarPlanetManagerAdapter(BazaarPlanetManagerImplementation* obj) : DistributedObjectAdapter((DistributedObjectServant*) obj) {
}

Packet* BazaarPlanetManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		setPlanet(inv->getSignedIntParameter());
		break;
	case 7:
		addBazaarItem((AuctionItem*) inv->getObjectParameter());
		break;
	case 8:
		removeBazaarItem(inv->getSignedLongParameter());
		break;
	case 9:
		addBazaar((BazaarTerminalDetails*) inv->getObjectParameter());
		break;
	case 10:
		getBazaarData((Player*) inv->getObjectParameter(), inv->getSignedLongParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter(), inv->getUnsignedIntParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void BazaarPlanetManagerAdapter::setPlanet(int planet) {
	return ((BazaarPlanetManagerImplementation*) impl)->setPlanet(planet);
}

void BazaarPlanetManagerAdapter::addBazaarItem(AuctionItem* item) {
	return ((BazaarPlanetManagerImplementation*) impl)->addBazaarItem(item);
}

void BazaarPlanetManagerAdapter::removeBazaarItem(long long objectid) {
	return ((BazaarPlanetManagerImplementation*) impl)->removeBazaarItem(objectid);
}

void BazaarPlanetManagerAdapter::addBazaar(BazaarTerminalDetails* terminal) {
	return ((BazaarPlanetManagerImplementation*) impl)->addBazaar(terminal);
}

void BazaarPlanetManagerAdapter::getBazaarData(Player* player, long long objectid, int screen, int extent, unsigned int category, int count, int offset) {
	return ((BazaarPlanetManagerImplementation*) impl)->getBazaarData(player, objectid, screen, extent, category, count, offset);
}

/*
 *	BazaarPlanetManagerHelper
 */

BazaarPlanetManagerHelper* BazaarPlanetManagerHelper::staticInitializer = BazaarPlanetManagerHelper::instance();

BazaarPlanetManagerHelper::BazaarPlanetManagerHelper() {
	className = "BazaarPlanetManager";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void BazaarPlanetManagerHelper::finalizeHelper() {
	BazaarPlanetManagerHelper::finalize();
}

DistributedObject* BazaarPlanetManagerHelper::instantiateObject() {
	return new BazaarPlanetManager(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* BazaarPlanetManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new BazaarPlanetManagerAdapter((BazaarPlanetManagerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	BazaarPlanetManagerServant
 */

BazaarPlanetManagerServant::BazaarPlanetManagerServant() {
	_classHelper = BazaarPlanetManagerHelper::instance();
}

BazaarPlanetManagerServant::~BazaarPlanetManagerServant() {
}

void BazaarPlanetManagerServant::_setStub(DistributedObjectStub* stub) {
	_this = (BazaarPlanetManager*) stub;
}

DistributedObjectStub* BazaarPlanetManagerServant::_getStub() {
	return _this;
}

