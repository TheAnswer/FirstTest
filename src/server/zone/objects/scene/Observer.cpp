/*
 *	server/zone/objects/scene/Observer.cpp generated by engine3 IDL compiler 0.60
 */

#include "Observer.h"

#include "server/zone/objects/scene/Observable.h"

/*
 *	ObserverStub
 */

Observer::Observer(DummyConstructorParameter* param) : ManagedObject(param) {
}

Observer::~Observer() {
}


int Observer::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addUnsignedIntParameter(eventType);
		method.addObjectParameter(observable);
		method.addObjectParameter(arg1);
		method.addSignedLongParameter(arg2);

		return method.executeWithSignedIntReturn();
	} else
		return ((ObserverImplementation*) _getImplementation())->notifyObserverEvent(eventType, observable, arg1, arg2);
}

unsigned long long Observer::getObjectID() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		return method.executeWithUnsignedLongReturn();
	} else
		return ((ObserverImplementation*) _getImplementation())->getObjectID();
}

int Observer::compareTo(Observer* obj) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(obj);

		return method.executeWithSignedIntReturn();
	} else
		return ((ObserverImplementation*) _getImplementation())->compareTo(obj);
}

/*
 *	ObserverImplementation
 */

ObserverImplementation::ObserverImplementation() : ManagedObjectImplementation() {
	_initializeImplementation();
}

ObserverImplementation::ObserverImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


ObserverImplementation::~ObserverImplementation() {
}


void ObserverImplementation::finalize() {
}

void ObserverImplementation::_initializeImplementation() {
	_setClassHelper(ObserverHelper::instance());

	_serializationHelperMethod();
}

void ObserverImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (Observer*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ObserverImplementation::_getStub() {
	return _this;
}

ObserverImplementation::operator const Observer*() {
	return _this;
}

TransactionalObject* ObserverImplementation::clone() {
	return (TransactionalObject*) new ObserverImplementation(*this);
}


void ObserverImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void ObserverImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void ObserverImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void ObserverImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void ObserverImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void ObserverImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void ObserverImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void ObserverImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("Observer");

}

int ObserverImplementation::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	// server/zone/objects/scene/Observer.idl(56):  		return 1;
	return 1;
}

int ObserverImplementation::compareTo(Observer* obj) {
	// server/zone/objects/scene/Observer.idl(69):  
	if (getObjectID() < obj->getObjectID())	// server/zone/objects/scene/Observer.idl(70):  			return 1;
	return 1;

	else 	// server/zone/objects/scene/Observer.idl(71):  
	if (getObjectID() > obj->getObjectID())	// server/zone/objects/scene/Observer.idl(72):  			return -1;
	return -1;

	else 	// server/zone/objects/scene/Observer.idl(74):  			return 0;
	return 0;
}

/*
 *	ObserverAdapter
 */

ObserverAdapter::ObserverAdapter(ObserverImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* ObserverAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(notifyObserverEvent(inv->getUnsignedIntParameter(), (Observable*) inv->getObjectParameter(), (ManagedObject*) inv->getObjectParameter(), inv->getSignedLongParameter()));
		break;
	case 7:
		resp->insertLong(getObjectID());
		break;
	case 8:
		resp->insertSignedInt(compareTo((Observer*) inv->getObjectParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

int ObserverAdapter::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	return ((ObserverImplementation*) impl)->notifyObserverEvent(eventType, observable, arg1, arg2);
}

unsigned long long ObserverAdapter::getObjectID() {
	return ((ObserverImplementation*) impl)->getObjectID();
}

int ObserverAdapter::compareTo(Observer* obj) {
	return ((ObserverImplementation*) impl)->compareTo(obj);
}

/*
 *	ObserverHelper
 */

ObserverHelper* ObserverHelper::staticInitializer = ObserverHelper::instance();

ObserverHelper::ObserverHelper() {
	className = "Observer";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ObserverHelper::finalizeHelper() {
	ObserverHelper::finalize();
}

DistributedObject* ObserverHelper::instantiateObject() {
	return new Observer(DummyConstructorParameter::instance());
}

DistributedObjectServant* ObserverHelper::instantiateServant() {
	return new ObserverImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ObserverHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ObserverAdapter((ObserverImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

