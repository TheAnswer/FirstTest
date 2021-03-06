/*
 *	server/zone/objects/tangible/deed/installationdeed/InstallationDeed.cpp generated by engine3 IDL compiler 0.55
 */

#include "InstallationDeed.h"

#include "InstallationDeedImplementation.h"

#include "../DeedObject.h"

#include "../../../creature/CreatureObject.h"

#include "../../../player/Player.h"

#include "../../../scene/SceneObject.h"

/*
 *	InstallationDeedStub
 */

InstallationDeed::InstallationDeed(CreatureObject* creature, unsigned int objcrc, const UnicodeString& customname, const String& stfname) : DeedObject(DummyConstructorParameter::instance()) {
	_impl = new InstallationDeedImplementation(creature, objcrc, customname, stfname);
	_impl->_setStub(this);
}

InstallationDeed::InstallationDeed(unsigned long long objid, unsigned int objcrc, const UnicodeString& customname, const String& stfname) : DeedObject(DummyConstructorParameter::instance()) {
	_impl = new InstallationDeedImplementation(objid, objcrc, customname, stfname);
	_impl->_setStub(this);
}

InstallationDeed::InstallationDeed(DummyConstructorParameter* param) : DeedObject(param) {
}

InstallationDeed::~InstallationDeed() {
}

int InstallationDeed::useObject(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		return method.executeWithSignedIntReturn();
	} else
		return ((InstallationDeedImplementation*) _impl)->useObject(player);
}

SceneObject* InstallationDeed::generateObject(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		return (SceneObject*) method.executeWithObjectReturn();
	} else
		return ((InstallationDeedImplementation*) _impl)->generateObject(player);
}

void InstallationDeed::parseItemAttributes() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		method.executeWithVoidReturn();
	} else
		((InstallationDeedImplementation*) _impl)->parseItemAttributes();
}

void InstallationDeed::setMaintenanceRate(float rate) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addFloatParameter(rate);

		method.executeWithVoidReturn();
	} else
		((InstallationDeedImplementation*) _impl)->setMaintenanceRate(rate);
}

void InstallationDeed::setPowerRate(float rate) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addFloatParameter(rate);

		method.executeWithVoidReturn();
	} else
		((InstallationDeedImplementation*) _impl)->setPowerRate(rate);
}

void InstallationDeed::setBaseExtractionRate(float rate) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addFloatParameter(rate);

		method.executeWithVoidReturn();
	} else
		((InstallationDeedImplementation*) _impl)->setBaseExtractionRate(rate);
}

void InstallationDeed::setHopperSizeMax(float size) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addFloatParameter(size);

		method.executeWithVoidReturn();
	} else
		((InstallationDeedImplementation*) _impl)->setHopperSizeMax(size);
}

void InstallationDeed::setSurplusMaintenance(unsigned int maint) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addUnsignedIntParameter(maint);

		method.executeWithVoidReturn();
	} else
		((InstallationDeedImplementation*) _impl)->setSurplusMaintenance(maint);
}

void InstallationDeed::setSurplusPower(unsigned int power) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addUnsignedIntParameter(power);

		method.executeWithVoidReturn();
	} else
		((InstallationDeedImplementation*) _impl)->setSurplusPower(power);
}

void InstallationDeed::setTargetConstructionObjectCRC(unsigned int objcrc) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addUnsignedIntParameter(objcrc);

		method.executeWithVoidReturn();
	} else
		((InstallationDeedImplementation*) _impl)->setTargetConstructionObjectCRC(objcrc);
}

void InstallationDeed::setTargetConditionMax(unsigned int condmax) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);
		method.addUnsignedIntParameter(condmax);

		method.executeWithVoidReturn();
	} else
		((InstallationDeedImplementation*) _impl)->setTargetConditionMax(condmax);
}

void InstallationDeed::setHarvesterType(unsigned char type) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);
		method.addUnsignedCharParameter(type);

		method.executeWithVoidReturn();
	} else
		((InstallationDeedImplementation*) _impl)->setHarvesterType(type);
}

void InstallationDeed::setLotSize(unsigned char lotsize) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);
		method.addUnsignedCharParameter(lotsize);

		method.executeWithVoidReturn();
	} else
		((InstallationDeedImplementation*) _impl)->setLotSize(lotsize);
}

float InstallationDeed::getMaintenanceRate() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);

		return method.executeWithFloatReturn();
	} else
		return ((InstallationDeedImplementation*) _impl)->getMaintenanceRate();
}

float InstallationDeed::getPowerRate() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);

		return method.executeWithFloatReturn();
	} else
		return ((InstallationDeedImplementation*) _impl)->getPowerRate();
}

float InstallationDeed::getBaseExtractionRate() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);

		return method.executeWithFloatReturn();
	} else
		return ((InstallationDeedImplementation*) _impl)->getBaseExtractionRate();
}

float InstallationDeed::getHopperSizeMax() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);

		return method.executeWithFloatReturn();
	} else
		return ((InstallationDeedImplementation*) _impl)->getHopperSizeMax();
}

unsigned int InstallationDeed::getSurplusMaintenance() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((InstallationDeedImplementation*) _impl)->getSurplusMaintenance();
}

unsigned int InstallationDeed::getSurplusPower() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((InstallationDeedImplementation*) _impl)->getSurplusPower();
}

unsigned int InstallationDeed::getTargetConstructionObjectCRC() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((InstallationDeedImplementation*) _impl)->getTargetConstructionObjectCRC();
}

unsigned char InstallationDeed::getHarvesterType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);

		return method.executeWithUnsignedCharReturn();
	} else
		return ((InstallationDeedImplementation*) _impl)->getHarvesterType();
}

bool InstallationDeed::isMaintenanceEmpty() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 27);

		return method.executeWithBooleanReturn();
	} else
		return ((InstallationDeedImplementation*) _impl)->isMaintenanceEmpty();
}

bool InstallationDeed::isPowerEmpty() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 28);

		return method.executeWithBooleanReturn();
	} else
		return ((InstallationDeedImplementation*) _impl)->isPowerEmpty();
}

bool InstallationDeed::isFactoryDeed() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 29);

		return method.executeWithBooleanReturn();
	} else
		return ((InstallationDeedImplementation*) _impl)->isFactoryDeed();
}

bool InstallationDeed::isGeneratorDeed() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 30);

		return method.executeWithBooleanReturn();
	} else
		return ((InstallationDeedImplementation*) _impl)->isGeneratorDeed();
}

bool InstallationDeed::isHarvesterDeed() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 31);

		return method.executeWithBooleanReturn();
	} else
		return ((InstallationDeedImplementation*) _impl)->isHarvesterDeed();
}

bool InstallationDeed::isTurretDeed() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 32);

		return method.executeWithBooleanReturn();
	} else
		return ((InstallationDeedImplementation*) _impl)->isTurretDeed();
}

bool InstallationDeed::isMinefieldDeed() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 33);

		return method.executeWithBooleanReturn();
	} else
		return ((InstallationDeedImplementation*) _impl)->isMinefieldDeed();
}

/*
 *	InstallationDeedAdapter
 */

InstallationDeedAdapter::InstallationDeedAdapter(InstallationDeedImplementation* obj) : DeedObjectAdapter(obj) {
}

Packet* InstallationDeedAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(useObject((Player*) inv->getObjectParameter()));
		break;
	case 7:
		resp->insertLong(generateObject((Player*) inv->getObjectParameter())->_getObjectID());
		break;
	case 8:
		parseItemAttributes();
		break;
	case 9:
		setMaintenanceRate(inv->getFloatParameter());
		break;
	case 10:
		setPowerRate(inv->getFloatParameter());
		break;
	case 11:
		setBaseExtractionRate(inv->getFloatParameter());
		break;
	case 12:
		setHopperSizeMax(inv->getFloatParameter());
		break;
	case 13:
		setSurplusMaintenance(inv->getUnsignedIntParameter());
		break;
	case 14:
		setSurplusPower(inv->getUnsignedIntParameter());
		break;
	case 15:
		setTargetConstructionObjectCRC(inv->getUnsignedIntParameter());
		break;
	case 16:
		setTargetConditionMax(inv->getUnsignedIntParameter());
		break;
	case 17:
		setHarvesterType(inv->getUnsignedCharParameter());
		break;
	case 18:
		setLotSize(inv->getUnsignedCharParameter());
		break;
	case 19:
		resp->insertFloat(getMaintenanceRate());
		break;
	case 20:
		resp->insertFloat(getPowerRate());
		break;
	case 21:
		resp->insertFloat(getBaseExtractionRate());
		break;
	case 22:
		resp->insertFloat(getHopperSizeMax());
		break;
	case 23:
		resp->insertInt(getSurplusMaintenance());
		break;
	case 24:
		resp->insertInt(getSurplusPower());
		break;
	case 25:
		resp->insertInt(getTargetConstructionObjectCRC());
		break;
	case 26:
		resp->insertByte(getHarvesterType());
		break;
	case 27:
		resp->insertBoolean(isMaintenanceEmpty());
		break;
	case 28:
		resp->insertBoolean(isPowerEmpty());
		break;
	case 29:
		resp->insertBoolean(isFactoryDeed());
		break;
	case 30:
		resp->insertBoolean(isGeneratorDeed());
		break;
	case 31:
		resp->insertBoolean(isHarvesterDeed());
		break;
	case 32:
		resp->insertBoolean(isTurretDeed());
		break;
	case 33:
		resp->insertBoolean(isMinefieldDeed());
		break;
	default:
		return NULL;
	}

	return resp;
}

int InstallationDeedAdapter::useObject(Player* player) {
	return ((InstallationDeedImplementation*) impl)->useObject(player);
}

SceneObject* InstallationDeedAdapter::generateObject(Player* player) {
	return ((InstallationDeedImplementation*) impl)->generateObject(player);
}

void InstallationDeedAdapter::parseItemAttributes() {
	return ((InstallationDeedImplementation*) impl)->parseItemAttributes();
}

void InstallationDeedAdapter::setMaintenanceRate(float rate) {
	return ((InstallationDeedImplementation*) impl)->setMaintenanceRate(rate);
}

void InstallationDeedAdapter::setPowerRate(float rate) {
	return ((InstallationDeedImplementation*) impl)->setPowerRate(rate);
}

void InstallationDeedAdapter::setBaseExtractionRate(float rate) {
	return ((InstallationDeedImplementation*) impl)->setBaseExtractionRate(rate);
}

void InstallationDeedAdapter::setHopperSizeMax(float size) {
	return ((InstallationDeedImplementation*) impl)->setHopperSizeMax(size);
}

void InstallationDeedAdapter::setSurplusMaintenance(unsigned int maint) {
	return ((InstallationDeedImplementation*) impl)->setSurplusMaintenance(maint);
}

void InstallationDeedAdapter::setSurplusPower(unsigned int power) {
	return ((InstallationDeedImplementation*) impl)->setSurplusPower(power);
}

void InstallationDeedAdapter::setTargetConstructionObjectCRC(unsigned int objcrc) {
	return ((InstallationDeedImplementation*) impl)->setTargetConstructionObjectCRC(objcrc);
}

void InstallationDeedAdapter::setTargetConditionMax(unsigned int condmax) {
	return ((InstallationDeedImplementation*) impl)->setTargetConditionMax(condmax);
}

void InstallationDeedAdapter::setHarvesterType(unsigned char type) {
	return ((InstallationDeedImplementation*) impl)->setHarvesterType(type);
}

void InstallationDeedAdapter::setLotSize(unsigned char lotsize) {
	return ((InstallationDeedImplementation*) impl)->setLotSize(lotsize);
}

float InstallationDeedAdapter::getMaintenanceRate() {
	return ((InstallationDeedImplementation*) impl)->getMaintenanceRate();
}

float InstallationDeedAdapter::getPowerRate() {
	return ((InstallationDeedImplementation*) impl)->getPowerRate();
}

float InstallationDeedAdapter::getBaseExtractionRate() {
	return ((InstallationDeedImplementation*) impl)->getBaseExtractionRate();
}

float InstallationDeedAdapter::getHopperSizeMax() {
	return ((InstallationDeedImplementation*) impl)->getHopperSizeMax();
}

unsigned int InstallationDeedAdapter::getSurplusMaintenance() {
	return ((InstallationDeedImplementation*) impl)->getSurplusMaintenance();
}

unsigned int InstallationDeedAdapter::getSurplusPower() {
	return ((InstallationDeedImplementation*) impl)->getSurplusPower();
}

unsigned int InstallationDeedAdapter::getTargetConstructionObjectCRC() {
	return ((InstallationDeedImplementation*) impl)->getTargetConstructionObjectCRC();
}

unsigned char InstallationDeedAdapter::getHarvesterType() {
	return ((InstallationDeedImplementation*) impl)->getHarvesterType();
}

bool InstallationDeedAdapter::isMaintenanceEmpty() {
	return ((InstallationDeedImplementation*) impl)->isMaintenanceEmpty();
}

bool InstallationDeedAdapter::isPowerEmpty() {
	return ((InstallationDeedImplementation*) impl)->isPowerEmpty();
}

bool InstallationDeedAdapter::isFactoryDeed() {
	return ((InstallationDeedImplementation*) impl)->isFactoryDeed();
}

bool InstallationDeedAdapter::isGeneratorDeed() {
	return ((InstallationDeedImplementation*) impl)->isGeneratorDeed();
}

bool InstallationDeedAdapter::isHarvesterDeed() {
	return ((InstallationDeedImplementation*) impl)->isHarvesterDeed();
}

bool InstallationDeedAdapter::isTurretDeed() {
	return ((InstallationDeedImplementation*) impl)->isTurretDeed();
}

bool InstallationDeedAdapter::isMinefieldDeed() {
	return ((InstallationDeedImplementation*) impl)->isMinefieldDeed();
}

/*
 *	InstallationDeedHelper
 */

InstallationDeedHelper* InstallationDeedHelper::staticInitializer = InstallationDeedHelper::instance();

InstallationDeedHelper::InstallationDeedHelper() {
	className = "InstallationDeed";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void InstallationDeedHelper::finalizeHelper() {
	InstallationDeedHelper::finalize();
}

DistributedObject* InstallationDeedHelper::instantiateObject() {
	return new InstallationDeed(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* InstallationDeedHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new InstallationDeedAdapter((InstallationDeedImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	InstallationDeedServant
 */

InstallationDeedServant::InstallationDeedServant(CreatureObject* creature, unsigned int objcrc, const UnicodeString& customname, const String& stfname) : DeedObjectImplementation(creature, objcrc, customname, stfname) {
	_classHelper = InstallationDeedHelper::instance();
}

InstallationDeedServant::InstallationDeedServant(unsigned long long objid, unsigned int objcrc, const UnicodeString& customname, const String& stfname) : DeedObjectImplementation(objid, objcrc, customname, stfname) {
	_classHelper = InstallationDeedHelper::instance();
}

InstallationDeedServant::~InstallationDeedServant() {
}

void InstallationDeedServant::_setStub(DistributedObjectStub* stub) {
	_this = (InstallationDeed*) stub;
	DeedObjectServant::_setStub(stub);
}

DistributedObjectStub* InstallationDeedServant::_getStub() {
	return _this;
}

