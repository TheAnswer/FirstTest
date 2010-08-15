/*
 *	server/zone/objects/player/sui/listbox/SuiListBoxMenuItem.cpp generated by engine3 IDL compiler 0.60
 */

#include "SuiListBoxMenuItem.h"

#include "server/zone/objects/player/sui/listbox/SuiListBox.h"

/*
 *	SuiListBoxMenuItemStub
 */

SuiListBoxMenuItem::SuiListBoxMenuItem(const String& name, unsigned long long oid) : ManagedObject(DummyConstructorParameter::instance()) {
	ManagedObject::_setImplementation(new SuiListBoxMenuItemImplementation(name, oid));
	ManagedObject::_getImplementation()->_setStub(this);
}

SuiListBoxMenuItem::SuiListBoxMenuItem(DummyConstructorParameter* param) : ManagedObject(param) {
}

SuiListBoxMenuItem::~SuiListBoxMenuItem() {
}


unsigned long long SuiListBoxMenuItem::getObjectID() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		return method.executeWithUnsignedLongReturn();
	} else
		return ((SuiListBoxMenuItemImplementation*) _getImplementation())->getObjectID();
}

String SuiListBoxMenuItem::getOptionName() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithAsciiReturn(_return_getOptionName);
		return _return_getOptionName;
	} else
		return ((SuiListBoxMenuItemImplementation*) _getImplementation())->getOptionName();
}

/*
 *	SuiListBoxMenuItemImplementation
 */

SuiListBoxMenuItemImplementation::SuiListBoxMenuItemImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


SuiListBoxMenuItemImplementation::~SuiListBoxMenuItemImplementation() {
}


void SuiListBoxMenuItemImplementation::finalize() {
}

void SuiListBoxMenuItemImplementation::_initializeImplementation() {
	_setClassHelper(SuiListBoxMenuItemHelper::instance());

	_serializationHelperMethod();
}

void SuiListBoxMenuItemImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (SuiListBoxMenuItem*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* SuiListBoxMenuItemImplementation::_getStub() {
	return _this;
}

SuiListBoxMenuItemImplementation::operator const SuiListBoxMenuItem*() {
	return _this;
}

TransactionalObject* SuiListBoxMenuItemImplementation::clone() {
	return (TransactionalObject*) new SuiListBoxMenuItemImplementation(*this);
}


void SuiListBoxMenuItemImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void SuiListBoxMenuItemImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void SuiListBoxMenuItemImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void SuiListBoxMenuItemImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void SuiListBoxMenuItemImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void SuiListBoxMenuItemImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void SuiListBoxMenuItemImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void SuiListBoxMenuItemImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("SuiListBoxMenuItem");

	addSerializableVariable("optionName", &optionName);
	addSerializableVariable("objectID", &objectID);
}

SuiListBoxMenuItemImplementation::SuiListBoxMenuItemImplementation(const String& name, unsigned long long oid) {
	_initializeImplementation();
	// server/zone/objects/player/sui/listbox/SuiListBoxMenuItem.idl(55):  		optionName = name;
	optionName = name;
	// server/zone/objects/player/sui/listbox/SuiListBoxMenuItem.idl(56):  		objectID = oid;
	objectID = oid;
}

unsigned long long SuiListBoxMenuItemImplementation::getObjectID() {
	// server/zone/objects/player/sui/listbox/SuiListBoxMenuItem.idl(60):  		return objectID;
	return objectID;
}

String SuiListBoxMenuItemImplementation::getOptionName() {
	// server/zone/objects/player/sui/listbox/SuiListBoxMenuItem.idl(64):  		return optionName;
	return optionName;
}

/*
 *	SuiListBoxMenuItemAdapter
 */

SuiListBoxMenuItemAdapter::SuiListBoxMenuItemAdapter(SuiListBoxMenuItemImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* SuiListBoxMenuItemAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertLong(getObjectID());
		break;
	case 7:
		resp->insertAscii(getOptionName());
		break;
	default:
		return NULL;
	}

	return resp;
}

unsigned long long SuiListBoxMenuItemAdapter::getObjectID() {
	return ((SuiListBoxMenuItemImplementation*) impl)->getObjectID();
}

String SuiListBoxMenuItemAdapter::getOptionName() {
	return ((SuiListBoxMenuItemImplementation*) impl)->getOptionName();
}

/*
 *	SuiListBoxMenuItemHelper
 */

SuiListBoxMenuItemHelper* SuiListBoxMenuItemHelper::staticInitializer = SuiListBoxMenuItemHelper::instance();

SuiListBoxMenuItemHelper::SuiListBoxMenuItemHelper() {
	className = "SuiListBoxMenuItem";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void SuiListBoxMenuItemHelper::finalizeHelper() {
	SuiListBoxMenuItemHelper::finalize();
}

DistributedObject* SuiListBoxMenuItemHelper::instantiateObject() {
	return new SuiListBoxMenuItem(DummyConstructorParameter::instance());
}

DistributedObjectServant* SuiListBoxMenuItemHelper::instantiateServant() {
	return new SuiListBoxMenuItemImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SuiListBoxMenuItemHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SuiListBoxMenuItemAdapter((SuiListBoxMenuItemImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

