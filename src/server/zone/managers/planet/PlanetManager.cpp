/*
 *	server/zone/managers/planet/PlanetManager.cpp generated by engine3 IDL compiler 0.60
 */

#include "PlanetManager.h"

#include "server/zone/Zone.h"

#include "server/zone/ZoneProcessServerImplementation.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/managers/structure/StructureManager.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/objects/creature/shuttle/ShuttleCreature.h"

#include "server/zone/objects/player/PlayerCreature.h"

/*
 *	PlanetManagerStub
 */

PlanetManager::PlanetManager(Zone* planet, ZoneProcessServerImplementation* srv) : ManagedObject(DummyConstructorParameter::instance()) {
	ManagedObject::_setImplementation(new PlanetManagerImplementation(planet, srv));
	ManagedObject::_getImplementation()->_setStub(this);
}

PlanetManager::PlanetManager(DummyConstructorParameter* param) : ManagedObject(param) {
}

PlanetManager::~PlanetManager() {
}


void PlanetManager::initializeTransientMembers() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((PlanetManagerImplementation*) _getImplementation())->initializeTransientMembers();
}

void PlanetManager::initialize() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		((PlanetManagerImplementation*) _getImplementation())->initialize();
}

void PlanetManager::loadRegions() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		method.executeWithVoidReturn();
	} else
		((PlanetManagerImplementation*) _getImplementation())->loadRegions();
}

void PlanetManager::loadNoBuildAreas() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		method.executeWithVoidReturn();
	} else
		((PlanetManagerImplementation*) _getImplementation())->loadNoBuildAreas();
}

void PlanetManager::loadShuttles() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		method.executeWithVoidReturn();
	} else
		((PlanetManagerImplementation*) _getImplementation())->loadShuttles();
}

void PlanetManager::loadBadgeAreas() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		method.executeWithVoidReturn();
	} else
		((PlanetManagerImplementation*) _getImplementation())->loadBadgeAreas();
}

ShuttleCreature* PlanetManager::getShuttle(const String& arrivalPoint) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addAsciiParameter(arrivalPoint);

		return (ShuttleCreature*) method.executeWithObjectReturn();
	} else
		return ((PlanetManagerImplementation*) _getImplementation())->getShuttle(arrivalPoint);
}

void PlanetManager::addShuttle(const String& city, ShuttleCreature* shuttle) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addAsciiParameter(city);
		method.addObjectParameter(shuttle);

		method.executeWithVoidReturn();
	} else
		((PlanetManagerImplementation*) _getImplementation())->addShuttle(city, shuttle);
}

bool PlanetManager::isNoBuildArea(float x, float y, StringId& fullAreaName) {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		return ((PlanetManagerImplementation*) _getImplementation())->isNoBuildArea(x, y, fullAreaName);
}

unsigned int PlanetManager::getTravelFare(const String& departurePlanet, const String& arrivalPlanet) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addAsciiParameter(departurePlanet);
		method.addAsciiParameter(arrivalPlanet);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((PlanetManagerImplementation*) _getImplementation())->getTravelFare(departurePlanet, arrivalPlanet);
}

void PlanetManager::sendPlanetTravelPointListResponse(PlayerCreature* player) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((PlanetManagerImplementation*) _getImplementation())->sendPlanetTravelPointListResponse(player);
}

StructureManager* PlanetManager::getStructureManager() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		return (StructureManager*) method.executeWithObjectReturn();
	} else
		return ((PlanetManagerImplementation*) _getImplementation())->getStructureManager();
}

TerrainManager* PlanetManager::getTerrainManager() {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		return ((PlanetManagerImplementation*) _getImplementation())->getTerrainManager();
}

Region* PlanetManager::getRegion(float x, float y) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);
		method.addFloatParameter(x);
		method.addFloatParameter(y);

		return (Region*) method.executeWithObjectReturn();
	} else
		return ((PlanetManagerImplementation*) _getImplementation())->getRegion(x, y);
}

int PlanetManager::getRegionCount() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		return method.executeWithSignedIntReturn();
	} else
		return ((PlanetManagerImplementation*) _getImplementation())->getRegionCount();
}

Region* PlanetManager::getRegion(int index) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);
		method.addSignedIntParameter(index);

		return (Region*) method.executeWithObjectReturn();
	} else
		return ((PlanetManagerImplementation*) _getImplementation())->getRegion(index);
}

void PlanetManager::addRegion(Region* region) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);
		method.addObjectParameter(region);

		method.executeWithVoidReturn();
	} else
		((PlanetManagerImplementation*) _getImplementation())->addRegion(region);
}

bool PlanetManager::hasRegion(const String& name) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);
		method.addAsciiParameter(name);

		return method.executeWithBooleanReturn();
	} else
		return ((PlanetManagerImplementation*) _getImplementation())->hasRegion(name);
}

/*
 *	PlanetManagerImplementation
 */

PlanetManagerImplementation::PlanetManagerImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


PlanetManagerImplementation::~PlanetManagerImplementation() {
	PlanetManagerImplementation::finalize();
}


void PlanetManagerImplementation::_initializeImplementation() {
	_setClassHelper(PlanetManagerHelper::instance());

	_serializationHelperMethod();
}

void PlanetManagerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (PlanetManager*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* PlanetManagerImplementation::_getStub() {
	return _this;
}

PlanetManagerImplementation::operator const PlanetManager*() {
	return _this;
}

TransactionalObject* PlanetManagerImplementation::clone() {
	return (TransactionalObject*) new PlanetManagerImplementation(*this);
}


void PlanetManagerImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void PlanetManagerImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void PlanetManagerImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void PlanetManagerImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void PlanetManagerImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void PlanetManagerImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void PlanetManagerImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void PlanetManagerImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("PlanetManager");

	addSerializableVariable("zone", &zone);
	addSerializableVariable("regionMap", &regionMap);
	addSerializableVariable("structureManager", &structureManager);
}

PlanetManagerImplementation::PlanetManagerImplementation(Zone* planet, ZoneProcessServerImplementation* srv) {
	_initializeImplementation();
	// server/zone/managers/planet/PlanetManager.idl(86):  		zone = planet;
	zone = planet;
	// server/zone/managers/planet/PlanetManager.idl(87):  		server = srv;
	server = srv;
	// server/zone/managers/planet/PlanetManager.idl(89):  		Logger.setLoggingName("PlanetManager");
	Logger::setLoggingName("PlanetManager");
	// server/zone/managers/planet/PlanetManager.idl(90):  		Logger.setLogging(false);
	Logger::setLogging(false);
	// server/zone/managers/planet/PlanetManager.idl(91):  		Logger.setGlobalLogging(true);
	Logger::setGlobalLogging(true);
	// server/zone/managers/planet/PlanetManager.idl(93):  		terrainManager = null;
	terrainManager = NULL;
	// server/zone/managers/planet/PlanetManager.idl(95):  		structureManager = null;
	structureManager = NULL;
}

ShuttleCreature* PlanetManagerImplementation::getShuttle(const String& arrivalPoint) {
	Locker _locker(_this);
	// server/zone/managers/planet/PlanetManager.idl(109):  		return shuttleMap.get(arrivalPoint);
	return (&shuttleMap)->get(arrivalPoint);
}

void PlanetManagerImplementation::addShuttle(const String& city, ShuttleCreature* shuttle) {
	Locker _locker(_this);
	// server/zone/managers/planet/PlanetManager.idl(113):  		shuttleMap.put(city, shuttle);
	(&shuttleMap)->put(city, shuttle);
}

StructureManager* PlanetManagerImplementation::getStructureManager() {
	// server/zone/managers/planet/PlanetManager.idl(129):  		return structureManager;
	return structureManager;
}

TerrainManager* PlanetManagerImplementation::getTerrainManager() {
	// server/zone/managers/planet/PlanetManager.idl(134):  		return terrainManager;
	return terrainManager;
}

Region* PlanetManagerImplementation::getRegion(float x, float y) {
	// server/zone/managers/planet/PlanetManager.idl(138):  		return regionMap.getRegion(x, y);
	return (&regionMap)->getRegion(x, y);
}

int PlanetManagerImplementation::getRegionCount() {
	// server/zone/managers/planet/PlanetManager.idl(142):  		return regionMap.size();
	return (&regionMap)->size();
}

Region* PlanetManagerImplementation::getRegion(int index) {
	// server/zone/managers/planet/PlanetManager.idl(146):  		return regionMap.getRegion(index);
	return (&regionMap)->getRegion(index);
}

void PlanetManagerImplementation::addRegion(Region* region) {
	// server/zone/managers/planet/PlanetManager.idl(150):  		regionMap.addRegion(region);
	(&regionMap)->addRegion(region);
}

bool PlanetManagerImplementation::hasRegion(const String& name) {
	// server/zone/managers/planet/PlanetManager.idl(154):  		return regionMap.containsRegion(name);
	return (&regionMap)->containsRegion(name);
}

/*
 *	PlanetManagerAdapter
 */

PlanetManagerAdapter::PlanetManagerAdapter(PlanetManagerImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* PlanetManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	case 7:
		finalize();
		break;
	case 8:
		initialize();
		break;
	case 9:
		loadRegions();
		break;
	case 10:
		loadNoBuildAreas();
		break;
	case 11:
		loadShuttles();
		break;
	case 12:
		loadBadgeAreas();
		break;
	case 13:
		resp->insertLong(getShuttle(inv->getAsciiParameter(_param0_getShuttle__String_))->_getObjectID());
		break;
	case 14:
		addShuttle(inv->getAsciiParameter(_param0_addShuttle__String_ShuttleCreature_), (ShuttleCreature*) inv->getObjectParameter());
		break;
	case 15:
		resp->insertInt(getTravelFare(inv->getAsciiParameter(_param0_getTravelFare__String_String_), inv->getAsciiParameter(_param1_getTravelFare__String_String_)));
		break;
	case 16:
		sendPlanetTravelPointListResponse((PlayerCreature*) inv->getObjectParameter());
		break;
	case 17:
		resp->insertLong(getStructureManager()->_getObjectID());
		break;
	case 18:
		resp->insertLong(getRegion(inv->getFloatParameter(), inv->getFloatParameter())->_getObjectID());
		break;
	case 19:
		resp->insertSignedInt(getRegionCount());
		break;
	case 20:
		resp->insertLong(getRegion(inv->getSignedIntParameter())->_getObjectID());
		break;
	case 21:
		addRegion((Region*) inv->getObjectParameter());
		break;
	case 22:
		resp->insertBoolean(hasRegion(inv->getAsciiParameter(_param0_hasRegion__String_)));
		break;
	default:
		return NULL;
	}

	return resp;
}

void PlanetManagerAdapter::initializeTransientMembers() {
	((PlanetManagerImplementation*) impl)->initializeTransientMembers();
}

void PlanetManagerAdapter::finalize() {
	((PlanetManagerImplementation*) impl)->finalize();
}

void PlanetManagerAdapter::initialize() {
	((PlanetManagerImplementation*) impl)->initialize();
}

void PlanetManagerAdapter::loadRegions() {
	((PlanetManagerImplementation*) impl)->loadRegions();
}

void PlanetManagerAdapter::loadNoBuildAreas() {
	((PlanetManagerImplementation*) impl)->loadNoBuildAreas();
}

void PlanetManagerAdapter::loadShuttles() {
	((PlanetManagerImplementation*) impl)->loadShuttles();
}

void PlanetManagerAdapter::loadBadgeAreas() {
	((PlanetManagerImplementation*) impl)->loadBadgeAreas();
}

ShuttleCreature* PlanetManagerAdapter::getShuttle(const String& arrivalPoint) {
	return ((PlanetManagerImplementation*) impl)->getShuttle(arrivalPoint);
}

void PlanetManagerAdapter::addShuttle(const String& city, ShuttleCreature* shuttle) {
	((PlanetManagerImplementation*) impl)->addShuttle(city, shuttle);
}

unsigned int PlanetManagerAdapter::getTravelFare(const String& departurePlanet, const String& arrivalPlanet) {
	return ((PlanetManagerImplementation*) impl)->getTravelFare(departurePlanet, arrivalPlanet);
}

void PlanetManagerAdapter::sendPlanetTravelPointListResponse(PlayerCreature* player) {
	((PlanetManagerImplementation*) impl)->sendPlanetTravelPointListResponse(player);
}

StructureManager* PlanetManagerAdapter::getStructureManager() {
	return ((PlanetManagerImplementation*) impl)->getStructureManager();
}

Region* PlanetManagerAdapter::getRegion(float x, float y) {
	return ((PlanetManagerImplementation*) impl)->getRegion(x, y);
}

int PlanetManagerAdapter::getRegionCount() {
	return ((PlanetManagerImplementation*) impl)->getRegionCount();
}

Region* PlanetManagerAdapter::getRegion(int index) {
	return ((PlanetManagerImplementation*) impl)->getRegion(index);
}

void PlanetManagerAdapter::addRegion(Region* region) {
	((PlanetManagerImplementation*) impl)->addRegion(region);
}

bool PlanetManagerAdapter::hasRegion(const String& name) {
	return ((PlanetManagerImplementation*) impl)->hasRegion(name);
}

/*
 *	PlanetManagerHelper
 */

PlanetManagerHelper* PlanetManagerHelper::staticInitializer = PlanetManagerHelper::instance();

PlanetManagerHelper::PlanetManagerHelper() {
	className = "PlanetManager";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void PlanetManagerHelper::finalizeHelper() {
	PlanetManagerHelper::finalize();
}

DistributedObject* PlanetManagerHelper::instantiateObject() {
	return new PlanetManager(DummyConstructorParameter::instance());
}

DistributedObjectServant* PlanetManagerHelper::instantiateServant() {
	return new PlanetManagerImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* PlanetManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new PlanetManagerAdapter((PlanetManagerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

