/*
 *	server/zone/objects/area/BadgeActiveArea.cpp generated by engine3 IDL compiler 0.55
 */

#include "BadgeActiveArea.h"

#include "BadgeActiveAreaImplementation.h"

#include "ActiveArea.h"

#include "../player/Player.h"

/*
 *	BadgeActiveAreaStub
 */

BadgeActiveArea::BadgeActiveArea(float x, float y, float z, float radius, unsigned int badge) : ActiveArea(DummyConstructorParameter::instance()) {
	_impl = new BadgeActiveAreaImplementation(x, y, z, radius, badge);
	_impl->_setStub(this);
}

BadgeActiveArea::BadgeActiveArea(DummyConstructorParameter* param) : ActiveArea(param) {
}

BadgeActiveArea::~BadgeActiveArea() {
}

void BadgeActiveArea::onEnter(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((BadgeActiveAreaImplementation*) _impl)->onEnter(player);
}

/*
 *	BadgeActiveAreaAdapter
 */

BadgeActiveAreaAdapter::BadgeActiveAreaAdapter(BadgeActiveAreaImplementation* obj) : ActiveAreaAdapter(obj) {
}

Packet* BadgeActiveAreaAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		onEnter((Player*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void BadgeActiveAreaAdapter::onEnter(Player* player) {
	return ((BadgeActiveAreaImplementation*) impl)->onEnter(player);
}

/*
 *	BadgeActiveAreaHelper
 */

BadgeActiveAreaHelper* BadgeActiveAreaHelper::staticInitializer = BadgeActiveAreaHelper::instance();

BadgeActiveAreaHelper::BadgeActiveAreaHelper() {
	className = "BadgeActiveArea";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void BadgeActiveAreaHelper::finalizeHelper() {
	BadgeActiveAreaHelper::finalize();
}

DistributedObject* BadgeActiveAreaHelper::instantiateObject() {
	return new BadgeActiveArea(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* BadgeActiveAreaHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new BadgeActiveAreaAdapter((BadgeActiveAreaImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	BadgeActiveAreaServant
 */

BadgeActiveAreaServant::BadgeActiveAreaServant(float x, float y, float z, float radius) : ActiveAreaImplementation(x, y, z, radius) {
	_classHelper = BadgeActiveAreaHelper::instance();
}

BadgeActiveAreaServant::~BadgeActiveAreaServant() {
}

void BadgeActiveAreaServant::_setStub(DistributedObjectStub* stub) {
	_this = (BadgeActiveArea*) stub;
	ActiveAreaServant::_setStub(stub);
}

DistributedObjectStub* BadgeActiveAreaServant::_getStub() {
	return _this;
}

