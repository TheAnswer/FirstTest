/*
 *	server/zone/objects/tangible/weapons/jedi/OneHandedJediWeapon.h generated by engine3 IDL compiler 0.55
 */

#ifndef ONEHANDEDJEDIWEAPON_H_
#define ONEHANDEDJEDIWEAPON_H_

#include "engine/orb/DistributedObjectBroker.h"

class CreatureObject;

class JediWeapon;

#include "../JediWeapon.h"

class OneHandedJediWeapon : public JediWeapon {
public:
	OneHandedJediWeapon(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, bool eqp = false);

	OneHandedJediWeapon(CreatureObject* creature, const String& temp, const UnicodeString& n, const String& tempn, bool eqp = false);

protected:
	OneHandedJediWeapon(DummyConstructorParameter* param);

	virtual ~OneHandedJediWeapon();

	friend class OneHandedJediWeaponHelper;
};

class OneHandedJediWeaponImplementation;

class OneHandedJediWeaponAdapter : public JediWeaponAdapter {
public:
	OneHandedJediWeaponAdapter(OneHandedJediWeaponImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

};

class OneHandedJediWeaponHelper : public DistributedObjectClassHelper, public Singleton<OneHandedJediWeaponHelper> {
	static OneHandedJediWeaponHelper* staticInitializer;

public:
	OneHandedJediWeaponHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<OneHandedJediWeaponHelper>;
};

#include "../JediWeaponImplementation.h"

class OneHandedJediWeaponServant : public JediWeaponImplementation {
public:
	OneHandedJediWeapon* _this;

public:
	OneHandedJediWeaponServant(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int tp, bool eqp);
	OneHandedJediWeaponServant(CreatureObject* creature, const String& temp, const UnicodeString& n, const String& tempn, int tp, bool eqp);
	virtual ~OneHandedJediWeaponServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*ONEHANDEDJEDIWEAPON_H_*/
