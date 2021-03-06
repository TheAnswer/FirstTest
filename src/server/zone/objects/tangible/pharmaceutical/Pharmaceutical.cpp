/*
 *	server/zone/objects/tangible/pharmaceutical/Pharmaceutical.cpp generated by engine3 IDL compiler 0.55
 */

#include "Pharmaceutical.h"

#include "PharmaceuticalImplementation.h"

#include "../../scene/SceneObject.h"

#include "../../creature/CreatureObject.h"

#include "../../player/Player.h"

#include "../TangibleObject.h"

/*
 *	PharmaceuticalStub
 */

Pharmaceutical::Pharmaceutical(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int mptype) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new PharmaceuticalImplementation(oid, tempCRC, n, tempn, mptype);
	_impl->_setStub(this);
}

Pharmaceutical::Pharmaceutical(CreatureObject* creature, unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int mptype) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new PharmaceuticalImplementation(creature, oid, tempCRC, n, tempn, mptype);
	_impl->_setStub(this);
}

Pharmaceutical::Pharmaceutical(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int mptype) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new PharmaceuticalImplementation(creature, tempCRC, n, tempn, mptype);
	_impl->_setStub(this);
}

Pharmaceutical::Pharmaceutical(DummyConstructorParameter* param) : TangibleObject(param) {
}

Pharmaceutical::~Pharmaceutical() {
}

void Pharmaceutical::sendDeltas(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((PharmaceuticalImplementation*) _impl)->sendDeltas(player);
}

void Pharmaceutical::generateAttributes(SceneObject* obj) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		((PharmaceuticalImplementation*) _impl)->generateAttributes(obj);
}

void Pharmaceutical::useCharge(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((PharmaceuticalImplementation*) _impl)->useCharge(player);
}

void Pharmaceutical::setUsesRemaining(int uses) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addSignedIntParameter(uses);

		method.executeWithVoidReturn();
	} else
		((PharmaceuticalImplementation*) _impl)->setUsesRemaining(uses);
}

void Pharmaceutical::setMedicineUseRequired(int meduse) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addSignedIntParameter(meduse);

		method.executeWithVoidReturn();
	} else
		((PharmaceuticalImplementation*) _impl)->setMedicineUseRequired(meduse);
}

void Pharmaceutical::setMedpackType(int mptype) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addSignedIntParameter(mptype);

		method.executeWithVoidReturn();
	} else
		((PharmaceuticalImplementation*) _impl)->setMedpackType(mptype);
}

int Pharmaceutical::getUsesRemaining() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithSignedIntReturn();
	} else
		return ((PharmaceuticalImplementation*) _impl)->getUsesRemaining();
}

int Pharmaceutical::getMedicineUseRequired() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		return method.executeWithSignedIntReturn();
	} else
		return ((PharmaceuticalImplementation*) _impl)->getMedicineUseRequired();
}

int Pharmaceutical::getMedpackType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		return method.executeWithSignedIntReturn();
	} else
		return ((PharmaceuticalImplementation*) _impl)->getMedpackType();
}

bool Pharmaceutical::isEnhancePack() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		return method.executeWithBooleanReturn();
	} else
		return ((PharmaceuticalImplementation*) _impl)->isEnhancePack();
}

bool Pharmaceutical::isWoundPack() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		return method.executeWithBooleanReturn();
	} else
		return ((PharmaceuticalImplementation*) _impl)->isWoundPack();
}

bool Pharmaceutical::isStimPack() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		return method.executeWithBooleanReturn();
	} else
		return ((PharmaceuticalImplementation*) _impl)->isStimPack();
}

bool Pharmaceutical::isStatePack() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		return method.executeWithBooleanReturn();
	} else
		return ((PharmaceuticalImplementation*) _impl)->isStatePack();
}

bool Pharmaceutical::isCurePack() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);

		return method.executeWithBooleanReturn();
	} else
		return ((PharmaceuticalImplementation*) _impl)->isCurePack();
}

bool Pharmaceutical::isRevivePack() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);

		return method.executeWithBooleanReturn();
	} else
		return ((PharmaceuticalImplementation*) _impl)->isRevivePack();
}

bool Pharmaceutical::isRangedStimPack() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);

		return method.executeWithBooleanReturn();
	} else
		return ((PharmaceuticalImplementation*) _impl)->isRangedStimPack();
}

bool Pharmaceutical::isPoisonDeliveryUnit() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);

		return method.executeWithBooleanReturn();
	} else
		return ((PharmaceuticalImplementation*) _impl)->isPoisonDeliveryUnit();
}

bool Pharmaceutical::isDiseaseDeliveryUnit() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);

		return method.executeWithBooleanReturn();
	} else
		return ((PharmaceuticalImplementation*) _impl)->isDiseaseDeliveryUnit();
}

bool Pharmaceutical::isGeneralMedicItem() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);

		return method.executeWithBooleanReturn();
	} else
		return ((PharmaceuticalImplementation*) _impl)->isGeneralMedicItem();
}

bool Pharmaceutical::isCombatMedicItem() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);

		return method.executeWithBooleanReturn();
	} else
		return ((PharmaceuticalImplementation*) _impl)->isCombatMedicItem();
}

bool Pharmaceutical::isArea() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);

		return method.executeWithBooleanReturn();
	} else
		return ((PharmaceuticalImplementation*) _impl)->isArea();
}

float Pharmaceutical::getRange(CreatureObject* creature) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 27);
		method.addObjectParameter(creature);

		return method.executeWithFloatReturn();
	} else
		return ((PharmaceuticalImplementation*) _impl)->getRange(creature);
}

float Pharmaceutical::getArea() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 28);

		return method.executeWithFloatReturn();
	} else
		return ((PharmaceuticalImplementation*) _impl)->getArea();
}

/*
 *	PharmaceuticalAdapter
 */

PharmaceuticalAdapter::PharmaceuticalAdapter(PharmaceuticalImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* PharmaceuticalAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		sendDeltas((Player*) inv->getObjectParameter());
		break;
	case 7:
		generateAttributes((SceneObject*) inv->getObjectParameter());
		break;
	case 8:
		useCharge((Player*) inv->getObjectParameter());
		break;
	case 9:
		setUsesRemaining(inv->getSignedIntParameter());
		break;
	case 10:
		setMedicineUseRequired(inv->getSignedIntParameter());
		break;
	case 11:
		setMedpackType(inv->getSignedIntParameter());
		break;
	case 12:
		resp->insertSignedInt(getUsesRemaining());
		break;
	case 13:
		resp->insertSignedInt(getMedicineUseRequired());
		break;
	case 14:
		resp->insertSignedInt(getMedpackType());
		break;
	case 15:
		resp->insertBoolean(isEnhancePack());
		break;
	case 16:
		resp->insertBoolean(isWoundPack());
		break;
	case 17:
		resp->insertBoolean(isStimPack());
		break;
	case 18:
		resp->insertBoolean(isStatePack());
		break;
	case 19:
		resp->insertBoolean(isCurePack());
		break;
	case 20:
		resp->insertBoolean(isRevivePack());
		break;
	case 21:
		resp->insertBoolean(isRangedStimPack());
		break;
	case 22:
		resp->insertBoolean(isPoisonDeliveryUnit());
		break;
	case 23:
		resp->insertBoolean(isDiseaseDeliveryUnit());
		break;
	case 24:
		resp->insertBoolean(isGeneralMedicItem());
		break;
	case 25:
		resp->insertBoolean(isCombatMedicItem());
		break;
	case 26:
		resp->insertBoolean(isArea());
		break;
	case 27:
		resp->insertFloat(getRange((CreatureObject*) inv->getObjectParameter()));
		break;
	case 28:
		resp->insertFloat(getArea());
		break;
	default:
		return NULL;
	}

	return resp;
}

void PharmaceuticalAdapter::sendDeltas(Player* player) {
	return ((PharmaceuticalImplementation*) impl)->sendDeltas(player);
}

void PharmaceuticalAdapter::generateAttributes(SceneObject* obj) {
	return ((PharmaceuticalImplementation*) impl)->generateAttributes(obj);
}

void PharmaceuticalAdapter::useCharge(Player* player) {
	return ((PharmaceuticalImplementation*) impl)->useCharge(player);
}

void PharmaceuticalAdapter::setUsesRemaining(int uses) {
	return ((PharmaceuticalImplementation*) impl)->setUsesRemaining(uses);
}

void PharmaceuticalAdapter::setMedicineUseRequired(int meduse) {
	return ((PharmaceuticalImplementation*) impl)->setMedicineUseRequired(meduse);
}

void PharmaceuticalAdapter::setMedpackType(int mptype) {
	return ((PharmaceuticalImplementation*) impl)->setMedpackType(mptype);
}

int PharmaceuticalAdapter::getUsesRemaining() {
	return ((PharmaceuticalImplementation*) impl)->getUsesRemaining();
}

int PharmaceuticalAdapter::getMedicineUseRequired() {
	return ((PharmaceuticalImplementation*) impl)->getMedicineUseRequired();
}

int PharmaceuticalAdapter::getMedpackType() {
	return ((PharmaceuticalImplementation*) impl)->getMedpackType();
}

bool PharmaceuticalAdapter::isEnhancePack() {
	return ((PharmaceuticalImplementation*) impl)->isEnhancePack();
}

bool PharmaceuticalAdapter::isWoundPack() {
	return ((PharmaceuticalImplementation*) impl)->isWoundPack();
}

bool PharmaceuticalAdapter::isStimPack() {
	return ((PharmaceuticalImplementation*) impl)->isStimPack();
}

bool PharmaceuticalAdapter::isStatePack() {
	return ((PharmaceuticalImplementation*) impl)->isStatePack();
}

bool PharmaceuticalAdapter::isCurePack() {
	return ((PharmaceuticalImplementation*) impl)->isCurePack();
}

bool PharmaceuticalAdapter::isRevivePack() {
	return ((PharmaceuticalImplementation*) impl)->isRevivePack();
}

bool PharmaceuticalAdapter::isRangedStimPack() {
	return ((PharmaceuticalImplementation*) impl)->isRangedStimPack();
}

bool PharmaceuticalAdapter::isPoisonDeliveryUnit() {
	return ((PharmaceuticalImplementation*) impl)->isPoisonDeliveryUnit();
}

bool PharmaceuticalAdapter::isDiseaseDeliveryUnit() {
	return ((PharmaceuticalImplementation*) impl)->isDiseaseDeliveryUnit();
}

bool PharmaceuticalAdapter::isGeneralMedicItem() {
	return ((PharmaceuticalImplementation*) impl)->isGeneralMedicItem();
}

bool PharmaceuticalAdapter::isCombatMedicItem() {
	return ((PharmaceuticalImplementation*) impl)->isCombatMedicItem();
}

bool PharmaceuticalAdapter::isArea() {
	return ((PharmaceuticalImplementation*) impl)->isArea();
}

float PharmaceuticalAdapter::getRange(CreatureObject* creature) {
	return ((PharmaceuticalImplementation*) impl)->getRange(creature);
}

float PharmaceuticalAdapter::getArea() {
	return ((PharmaceuticalImplementation*) impl)->getArea();
}

/*
 *	PharmaceuticalHelper
 */

PharmaceuticalHelper* PharmaceuticalHelper::staticInitializer = PharmaceuticalHelper::instance();

PharmaceuticalHelper::PharmaceuticalHelper() {
	className = "Pharmaceutical";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void PharmaceuticalHelper::finalizeHelper() {
	PharmaceuticalHelper::finalize();
}

DistributedObject* PharmaceuticalHelper::instantiateObject() {
	return new Pharmaceutical(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* PharmaceuticalHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new PharmaceuticalAdapter((PharmaceuticalImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	PharmaceuticalServant
 */

PharmaceuticalServant::PharmaceuticalServant(unsigned long long oid, int tp) : TangibleObjectImplementation(oid, tp) {
	_classHelper = PharmaceuticalHelper::instance();
}

PharmaceuticalServant::~PharmaceuticalServant() {
}

void PharmaceuticalServant::_setStub(DistributedObjectStub* stub) {
	_this = (Pharmaceutical*) stub;
	TangibleObjectServant::_setStub(stub);
}

DistributedObjectStub* PharmaceuticalServant::_getStub() {
	return _this;
}

