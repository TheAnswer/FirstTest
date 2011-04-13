/*
 *	server/zone/objects/tangible/fishing/FishingBaitObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "FishingBaitObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/objects/player/PlayerCreature.h"

/*
 *	FishingBaitObjectStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6,RPC_GETFRESHNESS__,RPC_SETFRESHNESS__INT_,RPC_LESSFRESH__,RPC_GETUSECOUNT__,RPC_FILLATTRIBUTELIST__ATTRIBUTELISTMESSAGE_PLAYERCREATURE_};

FishingBaitObject::FishingBaitObject() : TangibleObject(DummyConstructorParameter::instance()) {
	FishingBaitObjectImplementation* _implementation = new FishingBaitObjectImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

FishingBaitObject::FishingBaitObject(DummyConstructorParameter* param) : TangibleObject(param) {
}

FishingBaitObject::~FishingBaitObject() {
}


void FishingBaitObject::initializeTransientMembers() {
	FishingBaitObjectImplementation* _implementation = (FishingBaitObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

int FishingBaitObject::getFreshness() {
	FishingBaitObjectImplementation* _implementation = (FishingBaitObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETFRESHNESS__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getFreshness();
}

void FishingBaitObject::setFreshness(int value) {
	FishingBaitObjectImplementation* _implementation = (FishingBaitObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETFRESHNESS__INT_);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		_implementation->setFreshness(value);
}

void FishingBaitObject::lessFresh() {
	FishingBaitObjectImplementation* _implementation = (FishingBaitObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_LESSFRESH__);

		method.executeWithVoidReturn();
	} else
		_implementation->lessFresh();
}

int FishingBaitObject::getUseCount() {
	FishingBaitObjectImplementation* _implementation = (FishingBaitObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETUSECOUNT__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getUseCount();
}

void FishingBaitObject::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	FishingBaitObjectImplementation* _implementation = (FishingBaitObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_FILLATTRIBUTELIST__ATTRIBUTELISTMESSAGE_PLAYERCREATURE_);
		method.addObjectParameter(msg);
		method.addObjectParameter(object);

		method.executeWithVoidReturn();
	} else
		_implementation->fillAttributeList(msg, object);
}

DistributedObjectServant* FishingBaitObject::_getImplementation() {

	_updated = true;
	return _impl;
}

void FishingBaitObject::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	FishingBaitObjectImplementation
 */

FishingBaitObjectImplementation::FishingBaitObjectImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}


FishingBaitObjectImplementation::~FishingBaitObjectImplementation() {
}


void FishingBaitObjectImplementation::finalize() {
}

void FishingBaitObjectImplementation::_initializeImplementation() {
	_setClassHelper(FishingBaitObjectHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void FishingBaitObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (FishingBaitObject*) stub;
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* FishingBaitObjectImplementation::_getStub() {
	return _this;
}

FishingBaitObjectImplementation::operator const FishingBaitObject*() {
	return _this;
}

void FishingBaitObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void FishingBaitObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void FishingBaitObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void FishingBaitObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void FishingBaitObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void FishingBaitObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void FishingBaitObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void FishingBaitObjectImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("FishingBaitObject");

}

void FishingBaitObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(FishingBaitObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool FishingBaitObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TangibleObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "freshness") {
		TypeInfo<int >::parseFromBinaryStream(&freshness, stream);
		return true;
	}


	return false;
}

void FishingBaitObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = FishingBaitObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int FishingBaitObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "freshness";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&freshness, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + TangibleObjectImplementation::writeObjectMembers(stream);
}

FishingBaitObjectImplementation::FishingBaitObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/fishing/FishingBaitObject.idl():  		Logger.setLoggingName("FishingBaitObject");
	Logger::setLoggingName("FishingBaitObject");
	// server/zone/objects/tangible/fishing/FishingBaitObject.idl():  		freshness = 0;
	freshness = 0;
}

void FishingBaitObjectImplementation::initializeTransientMembers() {
	// server/zone/objects/tangible/fishing/FishingBaitObject.idl():  		super.initializeTransientMembers();
	TangibleObjectImplementation::initializeTransientMembers();
	// server/zone/objects/tangible/fishing/FishingBaitObject.idl():  		Logger.setLoggingName("FishingBaitObject");
	Logger::setLoggingName("FishingBaitObject");
}

int FishingBaitObjectImplementation::getFreshness() {
	// server/zone/objects/tangible/fishing/FishingBaitObject.idl():  		return freshness;
	return freshness;
}

void FishingBaitObjectImplementation::setFreshness(int value) {
	// server/zone/objects/tangible/fishing/FishingBaitObject.idl():  	}
	if ((value > -1) && (value < 10))	// server/zone/objects/tangible/fishing/FishingBaitObject.idl():  			freshness = value;
	freshness = value;
}

void FishingBaitObjectImplementation::lessFresh() {
	// server/zone/objects/tangible/fishing/FishingBaitObject.idl():  		freshness += 1;
	freshness += 1;
}

/*
 *	FishingBaitObjectAdapter
 */

FishingBaitObjectAdapter::FishingBaitObjectAdapter(FishingBaitObjectImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* FishingBaitObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		initializeTransientMembers();
		break;
	case RPC_GETFRESHNESS__:
		resp->insertSignedInt(getFreshness());
		break;
	case RPC_SETFRESHNESS__INT_:
		setFreshness(inv->getSignedIntParameter());
		break;
	case RPC_LESSFRESH__:
		lessFresh();
		break;
	case RPC_GETUSECOUNT__:
		resp->insertSignedInt(getUseCount());
		break;
	case RPC_FILLATTRIBUTELIST__ATTRIBUTELISTMESSAGE_PLAYERCREATURE_:
		fillAttributeList((AttributeListMessage*) inv->getObjectParameter(), (PlayerCreature*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void FishingBaitObjectAdapter::initializeTransientMembers() {
	((FishingBaitObjectImplementation*) impl)->initializeTransientMembers();
}

int FishingBaitObjectAdapter::getFreshness() {
	return ((FishingBaitObjectImplementation*) impl)->getFreshness();
}

void FishingBaitObjectAdapter::setFreshness(int value) {
	((FishingBaitObjectImplementation*) impl)->setFreshness(value);
}

void FishingBaitObjectAdapter::lessFresh() {
	((FishingBaitObjectImplementation*) impl)->lessFresh();
}

int FishingBaitObjectAdapter::getUseCount() {
	return ((FishingBaitObjectImplementation*) impl)->getUseCount();
}

void FishingBaitObjectAdapter::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	((FishingBaitObjectImplementation*) impl)->fillAttributeList(msg, object);
}

/*
 *	FishingBaitObjectHelper
 */

FishingBaitObjectHelper* FishingBaitObjectHelper::staticInitializer = FishingBaitObjectHelper::instance();

FishingBaitObjectHelper::FishingBaitObjectHelper() {
	className = "FishingBaitObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void FishingBaitObjectHelper::finalizeHelper() {
	FishingBaitObjectHelper::finalize();
}

DistributedObject* FishingBaitObjectHelper::instantiateObject() {
	return new FishingBaitObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* FishingBaitObjectHelper::instantiateServant() {
	return new FishingBaitObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* FishingBaitObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new FishingBaitObjectAdapter((FishingBaitObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
