/*
 *	server/zone/objects/tangible/pharmaceutical/DotPack.cpp generated by engine3 IDL compiler 0.55
 */

#include "DotPack.h"

#include "DotPackImplementation.h"

#include "../../scene/SceneObject.h"

#include "../../creature/CreatureObject.h"

#include "../../player/Player.h"

#include "../TangibleObject.h"

#include "Pharmaceutical.h"

/*
 *	DotPackStub
 */

DotPack::DotPack(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn) : Pharmaceutical(DummyConstructorParameter::instance()) {
	_impl = new DotPackImplementation(oid, tempCRC, n, tempn);
	_impl->_setStub(this);
}

DotPack::DotPack(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempn) : Pharmaceutical(DummyConstructorParameter::instance()) {
	_impl = new DotPackImplementation(creature, tempCRC, n, tempn);
	_impl->_setStub(this);
}

DotPack::DotPack(DummyConstructorParameter* param) : Pharmaceutical(param) {
}

DotPack::~DotPack() {
}

void DotPack::generateAttributes(SceneObject* obj) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		((DotPackImplementation*) _impl)->generateAttributes(obj);
}

int DotPack::calculatePower(CreatureObject* creature) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(creature);

		return method.executeWithSignedIntReturn();
	} else
		return ((DotPackImplementation*) _impl)->calculatePower(creature);
}

void DotPack::setEffectiveness(float eff) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addFloatParameter(eff);

		method.executeWithVoidReturn();
	} else
		((DotPackImplementation*) _impl)->setEffectiveness(eff);
}

float DotPack::getEffectiveness() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithFloatReturn();
	} else
		return ((DotPackImplementation*) _impl)->getEffectiveness();
}

void DotPack::setRange(float rng) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addFloatParameter(rng);

		method.executeWithVoidReturn();
	} else
		((DotPackImplementation*) _impl)->setRange(rng);
}

float DotPack::getRange(CreatureObject* creature) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addObjectParameter(creature);

		return method.executeWithFloatReturn();
	} else
		return ((DotPackImplementation*) _impl)->getRange(creature);
}

void DotPack::setDuration(int dur) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addSignedIntParameter(dur);

		method.executeWithVoidReturn();
	} else
		((DotPackImplementation*) _impl)->setDuration(dur);
}

int DotPack::getDuration() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		return method.executeWithSignedIntReturn();
	} else
		return ((DotPackImplementation*) _impl)->getDuration();
}

void DotPack::setArea(float ar) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addFloatParameter(ar);

		method.executeWithVoidReturn();
	} else
		((DotPackImplementation*) _impl)->setArea(ar);
}

float DotPack::getArea() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		return method.executeWithFloatReturn();
	} else
		return ((DotPackImplementation*) _impl)->getArea();
}

float DotPack::getPotency() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		return method.executeWithFloatReturn();
	} else
		return ((DotPackImplementation*) _impl)->getPotency();
}

void DotPack::setPotency(float pot) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);
		method.addFloatParameter(pot);

		method.executeWithVoidReturn();
	} else
		((DotPackImplementation*) _impl)->setPotency(pot);
}

int DotPack::getPool() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		return method.executeWithSignedIntReturn();
	} else
		return ((DotPackImplementation*) _impl)->getPool();
}

void DotPack::setPool(int pl) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);
		method.addSignedIntParameter(pl);

		method.executeWithVoidReturn();
	} else
		((DotPackImplementation*) _impl)->setPool(pl);
}

/*
 *	DotPackAdapter
 */

DotPackAdapter::DotPackAdapter(DotPackImplementation* obj) : PharmaceuticalAdapter(obj) {
}

Packet* DotPackAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		generateAttributes((SceneObject*) inv->getObjectParameter());
		break;
	case 7:
		resp->insertSignedInt(calculatePower((CreatureObject*) inv->getObjectParameter()));
		break;
	case 8:
		setEffectiveness(inv->getFloatParameter());
		break;
	case 9:
		resp->insertFloat(getEffectiveness());
		break;
	case 10:
		setRange(inv->getFloatParameter());
		break;
	case 11:
		resp->insertFloat(getRange((CreatureObject*) inv->getObjectParameter()));
		break;
	case 12:
		setDuration(inv->getSignedIntParameter());
		break;
	case 13:
		resp->insertSignedInt(getDuration());
		break;
	case 14:
		setArea(inv->getFloatParameter());
		break;
	case 15:
		resp->insertFloat(getArea());
		break;
	case 16:
		resp->insertFloat(getPotency());
		break;
	case 17:
		setPotency(inv->getFloatParameter());
		break;
	case 18:
		resp->insertSignedInt(getPool());
		break;
	case 19:
		setPool(inv->getSignedIntParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void DotPackAdapter::generateAttributes(SceneObject* obj) {
	return ((DotPackImplementation*) impl)->generateAttributes(obj);
}

int DotPackAdapter::calculatePower(CreatureObject* creature) {
	return ((DotPackImplementation*) impl)->calculatePower(creature);
}

void DotPackAdapter::setEffectiveness(float eff) {
	return ((DotPackImplementation*) impl)->setEffectiveness(eff);
}

float DotPackAdapter::getEffectiveness() {
	return ((DotPackImplementation*) impl)->getEffectiveness();
}

void DotPackAdapter::setRange(float rng) {
	return ((DotPackImplementation*) impl)->setRange(rng);
}

float DotPackAdapter::getRange(CreatureObject* creature) {
	return ((DotPackImplementation*) impl)->getRange(creature);
}

void DotPackAdapter::setDuration(int dur) {
	return ((DotPackImplementation*) impl)->setDuration(dur);
}

int DotPackAdapter::getDuration() {
	return ((DotPackImplementation*) impl)->getDuration();
}

void DotPackAdapter::setArea(float ar) {
	return ((DotPackImplementation*) impl)->setArea(ar);
}

float DotPackAdapter::getArea() {
	return ((DotPackImplementation*) impl)->getArea();
}

float DotPackAdapter::getPotency() {
	return ((DotPackImplementation*) impl)->getPotency();
}

void DotPackAdapter::setPotency(float pot) {
	return ((DotPackImplementation*) impl)->setPotency(pot);
}

int DotPackAdapter::getPool() {
	return ((DotPackImplementation*) impl)->getPool();
}

void DotPackAdapter::setPool(int pl) {
	return ((DotPackImplementation*) impl)->setPool(pl);
}

/*
 *	DotPackHelper
 */

DotPackHelper* DotPackHelper::staticInitializer = DotPackHelper::instance();

DotPackHelper::DotPackHelper() {
	className = "DotPack";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void DotPackHelper::finalizeHelper() {
	DotPackHelper::finalize();
}

DistributedObject* DotPackHelper::instantiateObject() {
	return new DotPack(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* DotPackHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DotPackAdapter((DotPackImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	DotPackServant
 */

DotPackServant::DotPackServant(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int mptype) : PharmaceuticalImplementation(oid, tempCRC, n, tempn, mptype) {
	_classHelper = DotPackHelper::instance();
}

DotPackServant::DotPackServant(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int mptype) : PharmaceuticalImplementation(creature, tempCRC, n, tempn, mptype) {
	_classHelper = DotPackHelper::instance();
}

DotPackServant::~DotPackServant() {
}

void DotPackServant::_setStub(DistributedObjectStub* stub) {
	_this = (DotPack*) stub;
	PharmaceuticalServant::_setStub(stub);
}

DistributedObjectStub* DotPackServant::_getStub() {
	return _this;
}

