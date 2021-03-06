/*
 *	server/zone/objects/tangible/crafting/factorycrate/FactoryCrate.cpp generated by engine3 IDL compiler 0.55
 */

#include "FactoryCrate.h"

#include "FactoryCrateImplementation.h"

#include "../../../player/Player.h"

#include "../component/Component.h"

#include "../../../creature/CreatureObject.h"

#include "../../TangibleObject.h"

/*
 *	FactoryCrateStub
 */

FactoryCrate::FactoryCrate(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new FactoryCrateImplementation(oid, tempCRC, n, tempn);
	_impl->_setStub(this);
}

FactoryCrate::FactoryCrate(unsigned long long oid, TangibleObject* tano) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new FactoryCrateImplementation(oid, tano);
	_impl->_setStub(this);
}

FactoryCrate::FactoryCrate(unsigned long long oid) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new FactoryCrateImplementation(oid);
	_impl->_setStub(this);
}

FactoryCrate::FactoryCrate(DummyConstructorParameter* param) : TangibleObject(param) {
}

FactoryCrate::~FactoryCrate() {
}

void FactoryCrate::generateAttributes(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((FactoryCrateImplementation*) _impl)->generateAttributes(player);
}

int FactoryCrate::useObject(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		return method.executeWithSignedIntReturn();
	} else
		return ((FactoryCrateImplementation*) _impl)->useObject(player);
}

void FactoryCrate::sendTo(Player* player, bool doClose) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);
		method.addBooleanParameter(doClose);

		method.executeWithVoidReturn();
	} else
		((FactoryCrateImplementation*) _impl)->sendTo(player, doClose);
}

void FactoryCrate::sendDeltas(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((FactoryCrateImplementation*) _impl)->sendDeltas(player);
}

TangibleObject* FactoryCrate::getTangibleObject() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return (TangibleObject*) method.executeWithObjectReturn();
	} else
		return ((FactoryCrateImplementation*) _impl)->getTangibleObject();
}

void FactoryCrate::setTangibleObject(TangibleObject* item) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addObjectParameter(item);

		method.executeWithVoidReturn();
	} else
		((FactoryCrateImplementation*) _impl)->setTangibleObject(item);
}

/*
 *	FactoryCrateAdapter
 */

FactoryCrateAdapter::FactoryCrateAdapter(FactoryCrateImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* FactoryCrateAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		generateAttributes((Player*) inv->getObjectParameter());
		break;
	case 7:
		resp->insertSignedInt(useObject((Player*) inv->getObjectParameter()));
		break;
	case 8:
		sendTo((Player*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 9:
		sendDeltas((Player*) inv->getObjectParameter());
		break;
	case 10:
		resp->insertLong(getTangibleObject()->_getObjectID());
		break;
	case 11:
		setTangibleObject((TangibleObject*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void FactoryCrateAdapter::generateAttributes(Player* player) {
	return ((FactoryCrateImplementation*) impl)->generateAttributes(player);
}

int FactoryCrateAdapter::useObject(Player* player) {
	return ((FactoryCrateImplementation*) impl)->useObject(player);
}

void FactoryCrateAdapter::sendTo(Player* player, bool doClose) {
	return ((FactoryCrateImplementation*) impl)->sendTo(player, doClose);
}

void FactoryCrateAdapter::sendDeltas(Player* player) {
	return ((FactoryCrateImplementation*) impl)->sendDeltas(player);
}

TangibleObject* FactoryCrateAdapter::getTangibleObject() {
	return ((FactoryCrateImplementation*) impl)->getTangibleObject();
}

void FactoryCrateAdapter::setTangibleObject(TangibleObject* item) {
	return ((FactoryCrateImplementation*) impl)->setTangibleObject(item);
}

/*
 *	FactoryCrateHelper
 */

FactoryCrateHelper* FactoryCrateHelper::staticInitializer = FactoryCrateHelper::instance();

FactoryCrateHelper::FactoryCrateHelper() {
	className = "FactoryCrate";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void FactoryCrateHelper::finalizeHelper() {
	FactoryCrateHelper::finalize();
}

DistributedObject* FactoryCrateHelper::instantiateObject() {
	return new FactoryCrate(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* FactoryCrateHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new FactoryCrateAdapter((FactoryCrateImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	FactoryCrateServant
 */

FactoryCrateServant::FactoryCrateServant(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int tp) : TangibleObjectImplementation(oid, tempCRC, n, tempn, tp) {
	_classHelper = FactoryCrateHelper::instance();
}

FactoryCrateServant::FactoryCrateServant(unsigned long long oid, int tp) : TangibleObjectImplementation(oid, tp) {
	_classHelper = FactoryCrateHelper::instance();
}

FactoryCrateServant::~FactoryCrateServant() {
}

void FactoryCrateServant::_setStub(DistributedObjectStub* stub) {
	_this = (FactoryCrate*) stub;
	TangibleObjectServant::_setStub(stub);
}

DistributedObjectStub* FactoryCrateServant::_getStub() {
	return _this;
}

