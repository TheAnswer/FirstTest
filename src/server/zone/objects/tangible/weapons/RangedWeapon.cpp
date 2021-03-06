/*
 *	server/zone/objects/tangible/weapons/RangedWeapon.cpp generated by engine3 IDL compiler 0.55
 */

#include "RangedWeapon.h"

#include "RangedWeaponImplementation.h"

#include "../../creature/CreatureObject.h"

#include "Weapon.h"

/*
 *	RangedWeaponStub
 */

RangedWeapon::RangedWeapon(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int tp, bool eqp) : Weapon(DummyConstructorParameter::instance()) {
	_impl = new RangedWeaponImplementation(oid, tempCRC, n, tempn, tp, eqp);
	_impl->_setStub(this);
}

RangedWeapon::RangedWeapon(CreatureObject* creature, const String& temp, const UnicodeString& n, const String& tempn, int tp, bool eqp) : Weapon(DummyConstructorParameter::instance()) {
	_impl = new RangedWeaponImplementation(creature, temp, n, tempn, tp, eqp);
	_impl->_setStub(this);
}

RangedWeapon::RangedWeapon(DummyConstructorParameter* param) : Weapon(param) {
}

RangedWeapon::~RangedWeapon() {
}

int RangedWeapon::getRange() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		return method.executeWithSignedIntReturn();
	} else
		return ((RangedWeaponImplementation*) _impl)->getRange();
}

void RangedWeapon::setRange(int rng) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addSignedIntParameter(rng);

		method.executeWithVoidReturn();
	} else
		((RangedWeaponImplementation*) _impl)->setRange(rng);
}

/*
 *	RangedWeaponAdapter
 */

RangedWeaponAdapter::RangedWeaponAdapter(RangedWeaponImplementation* obj) : WeaponAdapter(obj) {
}

Packet* RangedWeaponAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(getRange());
		break;
	case 7:
		setRange(inv->getSignedIntParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

int RangedWeaponAdapter::getRange() {
	return ((RangedWeaponImplementation*) impl)->getRange();
}

void RangedWeaponAdapter::setRange(int rng) {
	return ((RangedWeaponImplementation*) impl)->setRange(rng);
}

/*
 *	RangedWeaponHelper
 */

RangedWeaponHelper* RangedWeaponHelper::staticInitializer = RangedWeaponHelper::instance();

RangedWeaponHelper::RangedWeaponHelper() {
	className = "RangedWeapon";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void RangedWeaponHelper::finalizeHelper() {
	RangedWeaponHelper::finalize();
}

DistributedObject* RangedWeaponHelper::instantiateObject() {
	return new RangedWeapon(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* RangedWeaponHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new RangedWeaponAdapter((RangedWeaponImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	RangedWeaponServant
 */

RangedWeaponServant::RangedWeaponServant(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, bool eqp, int tp, int cat) : WeaponImplementation(oid, tempCRC, n, tempn, eqp, tp, cat) {
	_classHelper = RangedWeaponHelper::instance();
}

RangedWeaponServant::RangedWeaponServant(CreatureObject* creature, const String& temp, const UnicodeString& n, const String& tempn, bool eqp, int tp, int cat) : WeaponImplementation(creature, temp, n, tempn, eqp, tp, cat) {
	_classHelper = RangedWeaponHelper::instance();
}

RangedWeaponServant::~RangedWeaponServant() {
}

void RangedWeaponServant::_setStub(DistributedObjectStub* stub) {
	_this = (RangedWeapon*) stub;
	WeaponServant::_setStub(stub);
}

DistributedObjectStub* RangedWeaponServant::_getStub() {
	return _this;
}

