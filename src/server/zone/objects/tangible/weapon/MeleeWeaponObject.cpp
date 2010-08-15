/*
 *	server/zone/objects/tangible/weapon/MeleeWeaponObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "MeleeWeaponObject.h"

#include "server/zone/Zone.h"

/*
 *	MeleeWeaponObjectStub
 */

MeleeWeaponObject::MeleeWeaponObject() : WeaponObject(DummyConstructorParameter::instance()) {
	ManagedObject::_setImplementation(new MeleeWeaponObjectImplementation());
	ManagedObject::_getImplementation()->_setStub(this);
}

MeleeWeaponObject::MeleeWeaponObject(DummyConstructorParameter* param) : WeaponObject(param) {
}

MeleeWeaponObject::~MeleeWeaponObject() {
}


void MeleeWeaponObject::initializePrivateData() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((MeleeWeaponObjectImplementation*) _getImplementation())->initializePrivateData();
}

void MeleeWeaponObject::initializeTransientMembers() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		((MeleeWeaponObjectImplementation*) _getImplementation())->initializeTransientMembers();
}

bool MeleeWeaponObject::isMeleeWeapon() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		return method.executeWithBooleanReturn();
	} else
		return ((MeleeWeaponObjectImplementation*) _getImplementation())->isMeleeWeapon();
}

/*
 *	MeleeWeaponObjectImplementation
 */

MeleeWeaponObjectImplementation::MeleeWeaponObjectImplementation(DummyConstructorParameter* param) : WeaponObjectImplementation(param) {
	_initializeImplementation();
}


MeleeWeaponObjectImplementation::~MeleeWeaponObjectImplementation() {
}


void MeleeWeaponObjectImplementation::finalize() {
}

void MeleeWeaponObjectImplementation::_initializeImplementation() {
	_setClassHelper(MeleeWeaponObjectHelper::instance());

	_serializationHelperMethod();
}

void MeleeWeaponObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (MeleeWeaponObject*) stub;
	WeaponObjectImplementation::_setStub(stub);
}

DistributedObjectStub* MeleeWeaponObjectImplementation::_getStub() {
	return _this;
}

MeleeWeaponObjectImplementation::operator const MeleeWeaponObject*() {
	return _this;
}

TransactionalObject* MeleeWeaponObjectImplementation::clone() {
	return (TransactionalObject*) new MeleeWeaponObjectImplementation(*this);
}


void MeleeWeaponObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void MeleeWeaponObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void MeleeWeaponObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void MeleeWeaponObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void MeleeWeaponObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void MeleeWeaponObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void MeleeWeaponObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void MeleeWeaponObjectImplementation::_serializationHelperMethod() {
	WeaponObjectImplementation::_serializationHelperMethod();

	_setClassName("MeleeWeaponObject");

}

MeleeWeaponObjectImplementation::MeleeWeaponObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/weapon/MeleeWeaponObject.idl(54):  		Logger.setLoggingName("MeleeWeaponObject");
	Logger::setLoggingName("MeleeWeaponObject");
	// server/zone/objects/tangible/weapon/MeleeWeaponObject.idl(56):  		initializePrivateData();
	initializePrivateData();
}

void MeleeWeaponObjectImplementation::initializePrivateData() {
	// server/zone/objects/tangible/weapon/MeleeWeaponObject.idl(60):  		super.maxRange = 5;
	WeaponObjectImplementation::maxRange = 5;
}

bool MeleeWeaponObjectImplementation::isMeleeWeapon() {
	// server/zone/objects/tangible/weapon/MeleeWeaponObject.idl(66):  		return true;
	return true;
}

/*
 *	MeleeWeaponObjectAdapter
 */

MeleeWeaponObjectAdapter::MeleeWeaponObjectAdapter(MeleeWeaponObjectImplementation* obj) : WeaponObjectAdapter(obj) {
}

Packet* MeleeWeaponObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializePrivateData();
		break;
	case 7:
		initializeTransientMembers();
		break;
	case 8:
		resp->insertBoolean(isMeleeWeapon());
		break;
	default:
		return NULL;
	}

	return resp;
}

void MeleeWeaponObjectAdapter::initializePrivateData() {
	((MeleeWeaponObjectImplementation*) impl)->initializePrivateData();
}

void MeleeWeaponObjectAdapter::initializeTransientMembers() {
	((MeleeWeaponObjectImplementation*) impl)->initializeTransientMembers();
}

bool MeleeWeaponObjectAdapter::isMeleeWeapon() {
	return ((MeleeWeaponObjectImplementation*) impl)->isMeleeWeapon();
}

/*
 *	MeleeWeaponObjectHelper
 */

MeleeWeaponObjectHelper* MeleeWeaponObjectHelper::staticInitializer = MeleeWeaponObjectHelper::instance();

MeleeWeaponObjectHelper::MeleeWeaponObjectHelper() {
	className = "MeleeWeaponObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void MeleeWeaponObjectHelper::finalizeHelper() {
	MeleeWeaponObjectHelper::finalize();
}

DistributedObject* MeleeWeaponObjectHelper::instantiateObject() {
	return new MeleeWeaponObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* MeleeWeaponObjectHelper::instantiateServant() {
	return new MeleeWeaponObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* MeleeWeaponObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new MeleeWeaponObjectAdapter((MeleeWeaponObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

