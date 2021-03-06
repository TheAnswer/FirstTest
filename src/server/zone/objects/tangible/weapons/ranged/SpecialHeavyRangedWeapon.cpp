/*
 *	server/zone/objects/tangible/weapons/ranged/SpecialHeavyRangedWeapon.cpp generated by engine3 IDL compiler 0.55
 */

#include "SpecialHeavyRangedWeapon.h"

#include "SpecialHeavyRangedWeaponImplementation.h"

#include "../../../creature/CreatureObject.h"

#include "../RangedWeapon.h"

/*
 *	SpecialHeavyRangedWeaponStub
 */

SpecialHeavyRangedWeapon::SpecialHeavyRangedWeapon(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, bool eqp) : RangedWeapon(DummyConstructorParameter::instance()) {
	_impl = new SpecialHeavyRangedWeaponImplementation(oid, tempCRC, n, tempn, eqp);
	_impl->_setStub(this);
}

SpecialHeavyRangedWeapon::SpecialHeavyRangedWeapon(CreatureObject* creature, const String& temp, const UnicodeString& n, const String& tempn, bool eqp) : RangedWeapon(DummyConstructorParameter::instance()) {
	_impl = new SpecialHeavyRangedWeaponImplementation(creature, temp, n, tempn, eqp);
	_impl->_setStub(this);
}

SpecialHeavyRangedWeapon::SpecialHeavyRangedWeapon(DummyConstructorParameter* param) : RangedWeapon(param) {
}

SpecialHeavyRangedWeapon::~SpecialHeavyRangedWeapon() {
}

/*
 *	SpecialHeavyRangedWeaponAdapter
 */

SpecialHeavyRangedWeaponAdapter::SpecialHeavyRangedWeaponAdapter(SpecialHeavyRangedWeaponImplementation* obj) : RangedWeaponAdapter(obj) {
}

Packet* SpecialHeavyRangedWeaponAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	default:
		return NULL;
	}

	return resp;
}

/*
 *	SpecialHeavyRangedWeaponHelper
 */

SpecialHeavyRangedWeaponHelper* SpecialHeavyRangedWeaponHelper::staticInitializer = SpecialHeavyRangedWeaponHelper::instance();

SpecialHeavyRangedWeaponHelper::SpecialHeavyRangedWeaponHelper() {
	className = "SpecialHeavyRangedWeapon";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void SpecialHeavyRangedWeaponHelper::finalizeHelper() {
	SpecialHeavyRangedWeaponHelper::finalize();
}

DistributedObject* SpecialHeavyRangedWeaponHelper::instantiateObject() {
	return new SpecialHeavyRangedWeapon(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SpecialHeavyRangedWeaponHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SpecialHeavyRangedWeaponAdapter((SpecialHeavyRangedWeaponImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	SpecialHeavyRangedWeaponServant
 */

SpecialHeavyRangedWeaponServant::SpecialHeavyRangedWeaponServant(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int tp, bool eqp) : RangedWeaponImplementation(oid, tempCRC, n, tempn, tp, eqp) {
	_classHelper = SpecialHeavyRangedWeaponHelper::instance();
}

SpecialHeavyRangedWeaponServant::SpecialHeavyRangedWeaponServant(CreatureObject* creature, const String& temp, const UnicodeString& n, const String& tempn, int tp, bool eqp) : RangedWeaponImplementation(creature, temp, n, tempn, tp, eqp) {
	_classHelper = SpecialHeavyRangedWeaponHelper::instance();
}

SpecialHeavyRangedWeaponServant::~SpecialHeavyRangedWeaponServant() {
}

void SpecialHeavyRangedWeaponServant::_setStub(DistributedObjectStub* stub) {
	_this = (SpecialHeavyRangedWeapon*) stub;
	RangedWeaponServant::_setStub(stub);
}

DistributedObjectStub* SpecialHeavyRangedWeaponServant::_getStub() {
	return _this;
}

