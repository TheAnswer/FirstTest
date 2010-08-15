/*
 *	server/zone/objects/mission/GeneralMissionObjective.cpp generated by engine3 IDL compiler 0.60
 */

#include "GeneralMissionObjective.h"

#include "server/zone/objects/scene/Observer.h"

#include "server/zone/objects/scene/Observable.h"

#include "server/zone/objects/mission/MissionObject.h"

#include "server/zone/objects/mission/MissionObserver.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/area/MissionSpawnActiveArea.h"

#include "server/zone/objects/tangible/lair/LairObject.h"

/*
 *	GeneralMissionObjectiveStub
 */

GeneralMissionObjective::GeneralMissionObjective(MissionObject* mission) : MissionObjective(DummyConstructorParameter::instance()) {
	ManagedObject::_setImplementation(new GeneralMissionObjectiveImplementation(mission));
	ManagedObject::_getImplementation()->_setStub(this);
}

GeneralMissionObjective::GeneralMissionObjective(DummyConstructorParameter* param) : MissionObjective(param) {
}

GeneralMissionObjective::~GeneralMissionObjective() {
}


void GeneralMissionObjective::initializeTransientMembers() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((GeneralMissionObjectiveImplementation*) _getImplementation())->initializeTransientMembers();
}

void GeneralMissionObjective::activate() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		((GeneralMissionObjectiveImplementation*) _getImplementation())->activate();
}

void GeneralMissionObjective::abort() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		method.executeWithVoidReturn();
	} else
		((GeneralMissionObjectiveImplementation*) _getImplementation())->abort();
}

void GeneralMissionObjective::complete() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		method.executeWithVoidReturn();
	} else
		((GeneralMissionObjectiveImplementation*) _getImplementation())->complete();
}

void GeneralMissionObjective::spawnLair() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		method.executeWithVoidReturn();
	} else
		((GeneralMissionObjectiveImplementation*) _getImplementation())->spawnLair();
}

void GeneralMissionObjective::destroyObjectFromDatabase() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		method.executeWithVoidReturn();
	} else
		((GeneralMissionObjectiveImplementation*) _getImplementation())->destroyObjectFromDatabase();
}

int GeneralMissionObjective::notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addObjectParameter(observer);
		method.addUnsignedIntParameter(eventType);
		method.addObjectParameter(observable);
		method.addObjectParameter(arg1);
		method.addSignedLongParameter(arg2);

		return method.executeWithSignedIntReturn();
	} else
		return ((GeneralMissionObjectiveImplementation*) _getImplementation())->notifyObserverEvent(observer, eventType, observable, arg1, arg2);
}

void GeneralMissionObjective::setLairTemplateToSpawn(SharedObjectTemplate* sp) {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		((GeneralMissionObjectiveImplementation*) _getImplementation())->setLairTemplateToSpawn(sp);
}

/*
 *	GeneralMissionObjectiveImplementation
 */

GeneralMissionObjectiveImplementation::GeneralMissionObjectiveImplementation(DummyConstructorParameter* param) : MissionObjectiveImplementation(param) {
	_initializeImplementation();
}


GeneralMissionObjectiveImplementation::~GeneralMissionObjectiveImplementation() {
	GeneralMissionObjectiveImplementation::finalize();
}


void GeneralMissionObjectiveImplementation::_initializeImplementation() {
	_setClassHelper(GeneralMissionObjectiveHelper::instance());

	_serializationHelperMethod();
}

void GeneralMissionObjectiveImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (GeneralMissionObjective*) stub;
	MissionObjectiveImplementation::_setStub(stub);
}

DistributedObjectStub* GeneralMissionObjectiveImplementation::_getStub() {
	return _this;
}

GeneralMissionObjectiveImplementation::operator const GeneralMissionObjective*() {
	return _this;
}

TransactionalObject* GeneralMissionObjectiveImplementation::clone() {
	return (TransactionalObject*) new GeneralMissionObjectiveImplementation(*this);
}


void GeneralMissionObjectiveImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void GeneralMissionObjectiveImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void GeneralMissionObjectiveImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void GeneralMissionObjectiveImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void GeneralMissionObjectiveImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void GeneralMissionObjectiveImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void GeneralMissionObjectiveImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void GeneralMissionObjectiveImplementation::_serializationHelperMethod() {
	MissionObjectiveImplementation::_serializationHelperMethod();

	_setClassName("GeneralMissionObjective");

	addSerializableVariable("lairTemplateToSpawn", &lairTemplateToSpawn);
	addSerializableVariable("spawnActiveArea", &spawnActiveArea);
	addSerializableVariable("lairObject", &lairObject);
}

GeneralMissionObjectiveImplementation::GeneralMissionObjectiveImplementation(MissionObject* mission) : MissionObjectiveImplementation(mission) {
	_initializeImplementation();
	// server/zone/objects/mission/GeneralMissionObjective.idl(69):  		Logger.setLoggingName("GeneralMissionObjective");
	Logger::setLoggingName("GeneralMissionObjective");
}

void GeneralMissionObjectiveImplementation::finalize() {
	// server/zone/objects/mission/GeneralMissionObjective.idl(73):  		Logger.info("deleting from memory", true);
	Logger::info("deleting from memory", true);
}

void GeneralMissionObjectiveImplementation::initializeTransientMembers() {
	// server/zone/objects/mission/GeneralMissionObjective.idl(77):  		super.initializeTransientMembers();
	MissionObjectiveImplementation::initializeTransientMembers();
	// server/zone/objects/mission/GeneralMissionObjective.idl(79):  		Logger.setLoggingName("MissionObject");
	Logger::setLoggingName("MissionObject");
	// server/zone/objects/mission/GeneralMissionObjective.idl(81):  		activate();
	activate();
}

/*
 *	GeneralMissionObjectiveAdapter
 */

GeneralMissionObjectiveAdapter::GeneralMissionObjectiveAdapter(GeneralMissionObjectiveImplementation* obj) : MissionObjectiveAdapter(obj) {
}

Packet* GeneralMissionObjectiveAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		finalize();
		break;
	case 7:
		initializeTransientMembers();
		break;
	case 8:
		activate();
		break;
	case 9:
		abort();
		break;
	case 10:
		complete();
		break;
	case 11:
		spawnLair();
		break;
	case 12:
		destroyObjectFromDatabase();
		break;
	case 13:
		resp->insertSignedInt(notifyObserverEvent((MissionObserver*) inv->getObjectParameter(), inv->getUnsignedIntParameter(), (Observable*) inv->getObjectParameter(), (ManagedObject*) inv->getObjectParameter(), inv->getSignedLongParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

void GeneralMissionObjectiveAdapter::finalize() {
	((GeneralMissionObjectiveImplementation*) impl)->finalize();
}

void GeneralMissionObjectiveAdapter::initializeTransientMembers() {
	((GeneralMissionObjectiveImplementation*) impl)->initializeTransientMembers();
}

void GeneralMissionObjectiveAdapter::activate() {
	((GeneralMissionObjectiveImplementation*) impl)->activate();
}

void GeneralMissionObjectiveAdapter::abort() {
	((GeneralMissionObjectiveImplementation*) impl)->abort();
}

void GeneralMissionObjectiveAdapter::complete() {
	((GeneralMissionObjectiveImplementation*) impl)->complete();
}

void GeneralMissionObjectiveAdapter::spawnLair() {
	((GeneralMissionObjectiveImplementation*) impl)->spawnLair();
}

void GeneralMissionObjectiveAdapter::destroyObjectFromDatabase() {
	((GeneralMissionObjectiveImplementation*) impl)->destroyObjectFromDatabase();
}

int GeneralMissionObjectiveAdapter::notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	return ((GeneralMissionObjectiveImplementation*) impl)->notifyObserverEvent(observer, eventType, observable, arg1, arg2);
}

/*
 *	GeneralMissionObjectiveHelper
 */

GeneralMissionObjectiveHelper* GeneralMissionObjectiveHelper::staticInitializer = GeneralMissionObjectiveHelper::instance();

GeneralMissionObjectiveHelper::GeneralMissionObjectiveHelper() {
	className = "GeneralMissionObjective";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void GeneralMissionObjectiveHelper::finalizeHelper() {
	GeneralMissionObjectiveHelper::finalize();
}

DistributedObject* GeneralMissionObjectiveHelper::instantiateObject() {
	return new GeneralMissionObjective(DummyConstructorParameter::instance());
}

DistributedObjectServant* GeneralMissionObjectiveHelper::instantiateServant() {
	return new GeneralMissionObjectiveImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* GeneralMissionObjectiveHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new GeneralMissionObjectiveAdapter((GeneralMissionObjectiveImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

