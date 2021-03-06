/*
 *	server/zone/objects/tangible/terminal/bazaar/RegionBazaar.cpp generated by engine3 IDL compiler 0.55
 */

#include "RegionBazaar.h"

#include "RegionBazaarImplementation.h"

#include "../../../player/Player.h"

#include "../../../scene/SceneObject.h"

#include "../../../auction/AuctionItem.h"

#include "../../../../managers/bazaar/BazaarPlanetManager.h"

/*
 *	RegionBazaarStub
 */

RegionBazaar::RegionBazaar() : SceneObject(DummyConstructorParameter::instance()) {
	_impl = new RegionBazaarImplementation();
	_impl->_setStub(this);
}

RegionBazaar::RegionBazaar(DummyConstructorParameter* param) : SceneObject(param) {
}

RegionBazaar::~RegionBazaar() {
}

void RegionBazaar::addItem(AuctionItem* item) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(item);

		method.executeWithVoidReturn();
	} else
		((RegionBazaarImplementation*) _impl)->addItem(item);
}

bool RegionBazaar::removeItem(unsigned long long objectid) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addUnsignedLongParameter(objectid);

		return method.executeWithBooleanReturn();
	} else
		return ((RegionBazaarImplementation*) _impl)->removeItem(objectid);
}

void RegionBazaar::setRegion(String& region) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addAsciiParameter(region);

		method.executeWithVoidReturn();
	} else
		((RegionBazaarImplementation*) _impl)->setRegion(region);
}

void RegionBazaar::setManager(BazaarPlanetManager* manager) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(manager);

		method.executeWithVoidReturn();
	} else
		((RegionBazaarImplementation*) _impl)->setManager(manager);
}

void RegionBazaar::newBazaarRequest(unsigned long long bazaarID, Player* player, int planet) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addUnsignedLongParameter(bazaarID);
		method.addObjectParameter(player);
		method.addSignedIntParameter(planet);

		method.executeWithVoidReturn();
	} else
		((RegionBazaarImplementation*) _impl)->newBazaarRequest(bazaarID, player, planet);
}

void RegionBazaar::getBazaarData(Player* player, unsigned long long objectid, int screen, int extent, int category, int count, int offset) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addObjectParameter(player);
		method.addUnsignedLongParameter(objectid);
		method.addSignedIntParameter(screen);
		method.addSignedIntParameter(extent);
		method.addSignedIntParameter(category);
		method.addSignedIntParameter(count);
		method.addSignedIntParameter(offset);

		method.executeWithVoidReturn();
	} else
		((RegionBazaarImplementation*) _impl)->getBazaarData(player, objectid, screen, extent, category, count, offset);
}

/*
 *	RegionBazaarAdapter
 */

RegionBazaarAdapter::RegionBazaarAdapter(RegionBazaarImplementation* obj) : SceneObjectAdapter(obj) {
}

Packet* RegionBazaarAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		addItem((AuctionItem*) inv->getObjectParameter());
		break;
	case 7:
		resp->insertBoolean(removeItem(inv->getUnsignedLongParameter()));
		break;
	case 8:
		setRegion(inv->getAsciiParameter(_param0_setRegion__String_));
		break;
	case 9:
		setManager((BazaarPlanetManager*) inv->getObjectParameter());
		break;
	case 10:
		newBazaarRequest(inv->getUnsignedLongParameter(), (Player*) inv->getObjectParameter(), inv->getSignedIntParameter());
		break;
	case 11:
		getBazaarData((Player*) inv->getObjectParameter(), inv->getUnsignedLongParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void RegionBazaarAdapter::addItem(AuctionItem* item) {
	return ((RegionBazaarImplementation*) impl)->addItem(item);
}

bool RegionBazaarAdapter::removeItem(unsigned long long objectid) {
	return ((RegionBazaarImplementation*) impl)->removeItem(objectid);
}

void RegionBazaarAdapter::setRegion(String& region) {
	return ((RegionBazaarImplementation*) impl)->setRegion(region);
}

void RegionBazaarAdapter::setManager(BazaarPlanetManager* manager) {
	return ((RegionBazaarImplementation*) impl)->setManager(manager);
}

void RegionBazaarAdapter::newBazaarRequest(unsigned long long bazaarID, Player* player, int planet) {
	return ((RegionBazaarImplementation*) impl)->newBazaarRequest(bazaarID, player, planet);
}

void RegionBazaarAdapter::getBazaarData(Player* player, unsigned long long objectid, int screen, int extent, int category, int count, int offset) {
	return ((RegionBazaarImplementation*) impl)->getBazaarData(player, objectid, screen, extent, category, count, offset);
}

/*
 *	RegionBazaarHelper
 */

RegionBazaarHelper* RegionBazaarHelper::staticInitializer = RegionBazaarHelper::instance();

RegionBazaarHelper::RegionBazaarHelper() {
	className = "RegionBazaar";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void RegionBazaarHelper::finalizeHelper() {
	RegionBazaarHelper::finalize();
}

DistributedObject* RegionBazaarHelper::instantiateObject() {
	return new RegionBazaar(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* RegionBazaarHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new RegionBazaarAdapter((RegionBazaarImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	RegionBazaarServant
 */

RegionBazaarServant::RegionBazaarServant() : SceneObjectImplementation() {
	_classHelper = RegionBazaarHelper::instance();
}

RegionBazaarServant::~RegionBazaarServant() {
}

void RegionBazaarServant::_setStub(DistributedObjectStub* stub) {
	_this = (RegionBazaar*) stub;
	SceneObjectServant::_setStub(stub);
}

DistributedObjectStub* RegionBazaarServant::_getStub() {
	return _this;
}

