/*
 *	server/zone/objects/waypoint/WaypointObject.cpp generated by engine3 IDL compiler 0.55
 */

#include "WaypointObject.h"

#include "WaypointObjectImplementation.h"

#include "../scene/SceneObject.h"

#include "../player/Player.h"

/*
 *	WaypointObjectStub
 */

WaypointObject::WaypointObject(unsigned long long objid) : SceneObject(DummyConstructorParameter::instance()) {
	_impl = new WaypointObjectImplementation(objid);
	_impl->_setStub(this);
}

WaypointObject::WaypointObject(unsigned long long objid, SceneObject* obj) : SceneObject(DummyConstructorParameter::instance()) {
	_impl = new WaypointObjectImplementation(objid, obj);
	_impl->_setStub(this);
}

WaypointObject::WaypointObject(DummyConstructorParameter* param) : SceneObject(param) {
}

WaypointObject::~WaypointObject() {
}

void WaypointObject::activate(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((WaypointObjectImplementation*) _impl)->activate(player);
}

void WaypointObject::deactivate(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((WaypointObjectImplementation*) _impl)->deactivate(player);
}

void WaypointObject::updateWaypoint(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((WaypointObjectImplementation*) _impl)->updateWaypoint(player);
}

void WaypointObject::updateCustomName(Player* player, const String& value) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(player);
		method.addAsciiParameter(value);

		method.executeWithVoidReturn();
	} else
		((WaypointObjectImplementation*) _impl)->updateCustomName(player, value);
}

bool WaypointObject::toggleActivation() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return method.executeWithBooleanReturn();
	} else
		return ((WaypointObjectImplementation*) _impl)->toggleActivation();
}

void WaypointObject::setInternalNote(const String& message) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addAsciiParameter(message);

		method.executeWithVoidReturn();
	} else
		((WaypointObjectImplementation*) _impl)->setInternalNote(message);
}

void WaypointObject::setPlanetName(const String& planet) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addAsciiParameter(planet);

		method.executeWithVoidReturn();
	} else
		((WaypointObjectImplementation*) _impl)->setPlanetName(planet);
}

void WaypointObject::setWaypointType(unsigned char type) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addUnsignedCharParameter(type);

		method.executeWithVoidReturn();
	} else
		((WaypointObjectImplementation*) _impl)->setWaypointType(type);
}

void WaypointObject::setActivated(bool active) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addBooleanParameter(active);

		method.executeWithVoidReturn();
	} else
		((WaypointObjectImplementation*) _impl)->setActivated(active);
}

String& WaypointObject::getPlanetName() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		method.executeWithAsciiReturn(_return_getPlanetName);
		return _return_getPlanetName;
	} else
		return ((WaypointObjectImplementation*) _impl)->getPlanetName();
}

unsigned int WaypointObject::getPlanetCRC() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((WaypointObjectImplementation*) _impl)->getPlanetCRC();
}

String& WaypointObject::getInternalNote() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		method.executeWithAsciiReturn(_return_getInternalNote);
		return _return_getInternalNote;
	} else
		return ((WaypointObjectImplementation*) _impl)->getInternalNote();
}

unsigned char WaypointObject::getWaypointType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		return method.executeWithUnsignedCharReturn();
	} else
		return ((WaypointObjectImplementation*) _impl)->getWaypointType();
}

bool WaypointObject::isActivated() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);

		return method.executeWithBooleanReturn();
	} else
		return ((WaypointObjectImplementation*) _impl)->isActivated();
}

/*
 *	WaypointObjectAdapter
 */

WaypointObjectAdapter::WaypointObjectAdapter(WaypointObjectImplementation* obj) : SceneObjectAdapter(obj) {
}

Packet* WaypointObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		activate((Player*) inv->getObjectParameter());
		break;
	case 7:
		deactivate((Player*) inv->getObjectParameter());
		break;
	case 8:
		updateWaypoint((Player*) inv->getObjectParameter());
		break;
	case 9:
		updateCustomName((Player*) inv->getObjectParameter(), inv->getAsciiParameter(_param1_updateCustomName__Player_String_));
		break;
	case 10:
		resp->insertBoolean(toggleActivation());
		break;
	case 11:
		setInternalNote(inv->getAsciiParameter(_param0_setInternalNote__String_));
		break;
	case 12:
		setPlanetName(inv->getAsciiParameter(_param0_setPlanetName__String_));
		break;
	case 13:
		setWaypointType(inv->getUnsignedCharParameter());
		break;
	case 14:
		setActivated(inv->getBooleanParameter());
		break;
	case 15:
		resp->insertAscii(getPlanetName());
		break;
	case 16:
		resp->insertInt(getPlanetCRC());
		break;
	case 17:
		resp->insertAscii(getInternalNote());
		break;
	case 18:
		resp->insertByte(getWaypointType());
		break;
	case 19:
		resp->insertBoolean(isActivated());
		break;
	default:
		return NULL;
	}

	return resp;
}

void WaypointObjectAdapter::activate(Player* player) {
	return ((WaypointObjectImplementation*) impl)->activate(player);
}

void WaypointObjectAdapter::deactivate(Player* player) {
	return ((WaypointObjectImplementation*) impl)->deactivate(player);
}

void WaypointObjectAdapter::updateWaypoint(Player* player) {
	return ((WaypointObjectImplementation*) impl)->updateWaypoint(player);
}

void WaypointObjectAdapter::updateCustomName(Player* player, const String& value) {
	return ((WaypointObjectImplementation*) impl)->updateCustomName(player, value);
}

bool WaypointObjectAdapter::toggleActivation() {
	return ((WaypointObjectImplementation*) impl)->toggleActivation();
}

void WaypointObjectAdapter::setInternalNote(const String& message) {
	return ((WaypointObjectImplementation*) impl)->setInternalNote(message);
}

void WaypointObjectAdapter::setPlanetName(const String& planet) {
	return ((WaypointObjectImplementation*) impl)->setPlanetName(planet);
}

void WaypointObjectAdapter::setWaypointType(unsigned char type) {
	return ((WaypointObjectImplementation*) impl)->setWaypointType(type);
}

void WaypointObjectAdapter::setActivated(bool active) {
	return ((WaypointObjectImplementation*) impl)->setActivated(active);
}

String& WaypointObjectAdapter::getPlanetName() {
	return ((WaypointObjectImplementation*) impl)->getPlanetName();
}

unsigned int WaypointObjectAdapter::getPlanetCRC() {
	return ((WaypointObjectImplementation*) impl)->getPlanetCRC();
}

String& WaypointObjectAdapter::getInternalNote() {
	return ((WaypointObjectImplementation*) impl)->getInternalNote();
}

unsigned char WaypointObjectAdapter::getWaypointType() {
	return ((WaypointObjectImplementation*) impl)->getWaypointType();
}

bool WaypointObjectAdapter::isActivated() {
	return ((WaypointObjectImplementation*) impl)->isActivated();
}

/*
 *	WaypointObjectHelper
 */

WaypointObjectHelper* WaypointObjectHelper::staticInitializer = WaypointObjectHelper::instance();

WaypointObjectHelper::WaypointObjectHelper() {
	className = "WaypointObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void WaypointObjectHelper::finalizeHelper() {
	WaypointObjectHelper::finalize();
}

DistributedObject* WaypointObjectHelper::instantiateObject() {
	return new WaypointObject(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* WaypointObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new WaypointObjectAdapter((WaypointObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	WaypointObjectServant
 */

WaypointObjectServant::WaypointObjectServant(unsigned long long objid, int type) : SceneObjectImplementation(objid, type) {
	_classHelper = WaypointObjectHelper::instance();
}

WaypointObjectServant::~WaypointObjectServant() {
}

void WaypointObjectServant::_setStub(DistributedObjectStub* stub) {
	_this = (WaypointObject*) stub;
	SceneObjectServant::_setStub(stub);
}

DistributedObjectStub* WaypointObjectServant::_getStub() {
	return _this;
}

