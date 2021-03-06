/*
 *	server/zone/objects/tangible/weapons/melee/UnarmedMeleeWeapon.h generated by engine3 IDL compiler 0.55
 */

#ifndef UNARMEDMELEEWEAPON_H_
#define UNARMEDMELEEWEAPON_H_

#include "engine/orb/DistributedObjectBroker.h"

class CreatureObject;

class MeleeWeapon;

#include "../MeleeWeapon.h"

class UnarmedMeleeWeapon : public MeleeWeapon {
public:
	UnarmedMeleeWeapon(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, bool eqp = false);

	UnarmedMeleeWeapon(CreatureObject* creature, const String& temp, const UnicodeString& n, const String& tempn, bool eqp = false);

protected:
	UnarmedMeleeWeapon(DummyConstructorParameter* param);

	virtual ~UnarmedMeleeWeapon();

	friend class UnarmedMeleeWeaponHelper;
};

class UnarmedMeleeWeaponImplementation;

class UnarmedMeleeWeaponAdapter : public MeleeWeaponAdapter {
public:
	UnarmedMeleeWeaponAdapter(UnarmedMeleeWeaponImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

};

class UnarmedMeleeWeaponHelper : public DistributedObjectClassHelper, public Singleton<UnarmedMeleeWeaponHelper> {
	static UnarmedMeleeWeaponHelper* staticInitializer;

public:
	UnarmedMeleeWeaponHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<UnarmedMeleeWeaponHelper>;
};

#include "../MeleeWeaponImplementation.h"

class UnarmedMeleeWeaponServant : public MeleeWeaponImplementation {
public:
	UnarmedMeleeWeapon* _this;

public:
	UnarmedMeleeWeaponServant(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int tp, bool eqp);
	UnarmedMeleeWeaponServant(CreatureObject* creature, const String& temp, const UnicodeString& n, const String& tempn, int tp, bool eqp);
	virtual ~UnarmedMeleeWeaponServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*UNARMEDMELEEWEAPON_H_*/
