/*
 *	server/zone/objects/area/ActiveArea.cpp generated by engine3 IDL compiler 0.55
 */

#include "ActiveArea.h"

#include "ActiveAreaImplementation.h"

#include "Area.h"

#include "../player/Player.h"

/*
 *	ActiveAreaStub
 */

ActiveArea::ActiveArea(float x, float y, float z, float radius) : Area(DummyConstructorParameter::instance()) {
	_impl = new ActiveAreaImplementation(x, y, z, radius);
	_impl->_setStub(this);
}

ActiveArea::ActiveArea(DummyConstructorParameter* param) : Area(param) {
}

ActiveArea::~ActiveArea() {
}

void ActiveArea::onEnter(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ActiveAreaImplementation*) _impl)->onEnter(player);
}

void ActiveArea::onExit(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ActiveAreaImplementation*) _impl)->onExit(player);
}

/*
 *	ActiveAreaAdapter
 */

ActiveAreaAdapter::ActiveAreaAdapter(ActiveAreaImplementation* obj) : AreaAdapter(obj) {
}

Packet* ActiveAreaAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		onEnter((Player*) inv->getObjectParameter());
		break;
	case 7:
		onExit((Player*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ActiveAreaAdapter::onEnter(Player* player) {
	return ((ActiveAreaImplementation*) impl)->onEnter(player);
}

void ActiveAreaAdapter::onExit(Player* player) {
	return ((ActiveAreaImplementation*) impl)->onExit(player);
}

/*
 *	ActiveAreaHelper
 */

ActiveAreaHelper* ActiveAreaHelper::staticInitializer = ActiveAreaHelper::instance();

ActiveAreaHelper::ActiveAreaHelper() {
	className = "ActiveArea";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ActiveAreaHelper::finalizeHelper() {
	ActiveAreaHelper::finalize();
}

DistributedObject* ActiveAreaHelper::instantiateObject() {
	return new ActiveArea(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ActiveAreaHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ActiveAreaAdapter((ActiveAreaImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	ActiveAreaServant
 */

ActiveAreaServant::ActiveAreaServant(float x, float y, float z, float radius) : AreaImplementation(x, y, z, radius) {
	_classHelper = ActiveAreaHelper::instance();
}

ActiveAreaServant::~ActiveAreaServant() {
}

void ActiveAreaServant::_setStub(DistributedObjectStub* stub) {
	_this = (ActiveArea*) stub;
	AreaServant::_setStub(stub);
}

DistributedObjectStub* ActiveAreaServant::_getStub() {
	return _this;
}

