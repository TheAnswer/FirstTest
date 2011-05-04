/*
 *	server/zone/objects/ship/SpaceStationObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "SpaceStationObject.h"

/*
 *	SpaceStationObjectStub
 */

enum {};

SpaceStationObject::SpaceStationObject() : ShipObject(DummyConstructorParameter::instance()) {
	SpaceStationObjectImplementation* _implementation = new SpaceStationObjectImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

SpaceStationObject::SpaceStationObject(DummyConstructorParameter* param) : ShipObject(param) {
}

SpaceStationObject::~SpaceStationObject() {
}


DistributedObjectServant* SpaceStationObject::_getImplementation() {

	_updated = true;
	return _impl;
}

void SpaceStationObject::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	SpaceStationObjectImplementation
 */

SpaceStationObjectImplementation::SpaceStationObjectImplementation(DummyConstructorParameter* param) : ShipObjectImplementation(param) {
	_initializeImplementation();
}


SpaceStationObjectImplementation::~SpaceStationObjectImplementation() {
}


void SpaceStationObjectImplementation::finalize() {
}

void SpaceStationObjectImplementation::_initializeImplementation() {
	_setClassHelper(SpaceStationObjectHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void SpaceStationObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (SpaceStationObject*) stub;
	ShipObjectImplementation::_setStub(stub);
}

DistributedObjectStub* SpaceStationObjectImplementation::_getStub() {
	return _this;
}

SpaceStationObjectImplementation::operator const SpaceStationObject*() {
	return _this;
}

void SpaceStationObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void SpaceStationObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void SpaceStationObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void SpaceStationObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void SpaceStationObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void SpaceStationObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void SpaceStationObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void SpaceStationObjectImplementation::_serializationHelperMethod() {
	ShipObjectImplementation::_serializationHelperMethod();

	_setClassName("SpaceStationObject");

}

void SpaceStationObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(SpaceStationObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool SpaceStationObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ShipObjectImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void SpaceStationObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = SpaceStationObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int SpaceStationObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + ShipObjectImplementation::writeObjectMembers(stream);
}

SpaceStationObjectImplementation::SpaceStationObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/ship/SpaceStationObject.idl():  		Logger.setLoggingName("SpaceStationObject");
	Logger::setLoggingName("SpaceStationObject");
}

/*
 *	SpaceStationObjectAdapter
 */

SpaceStationObjectAdapter::SpaceStationObjectAdapter(SpaceStationObjectImplementation* obj) : ShipObjectAdapter(obj) {
}

Packet* SpaceStationObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	default:
		return NULL;
	}

	return resp;
}

/*
 *	SpaceStationObjectHelper
 */

SpaceStationObjectHelper* SpaceStationObjectHelper::staticInitializer = SpaceStationObjectHelper::instance();

SpaceStationObjectHelper::SpaceStationObjectHelper() {
	className = "SpaceStationObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void SpaceStationObjectHelper::finalizeHelper() {
	SpaceStationObjectHelper::finalize();
}

DistributedObject* SpaceStationObjectHelper::instantiateObject() {
	return new SpaceStationObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* SpaceStationObjectHelper::instantiateServant() {
	return new SpaceStationObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SpaceStationObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SpaceStationObjectAdapter((SpaceStationObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
