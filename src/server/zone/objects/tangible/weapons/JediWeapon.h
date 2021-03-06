/*
 *	server/zone/objects/tangible/weapons/JediWeapon.h generated by engine3 IDL compiler 0.55
 */

#ifndef JEDIWEAPON_H_
#define JEDIWEAPON_H_

#include "engine/orb/DistributedObjectBroker.h"

class CreatureObject;

class Weapon;

#include "Weapon.h"

class JediWeapon : public Weapon {
public:
	JediWeapon(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int tp, bool eqp = false);

	JediWeapon(CreatureObject* creature, const String& temp, const UnicodeString& n, const String& tempn, int tp, bool eqp = false);

protected:
	JediWeapon(DummyConstructorParameter* param);

	virtual ~JediWeapon();

	friend class JediWeaponHelper;
};

class JediWeaponImplementation;

class JediWeaponAdapter : public WeaponAdapter {
public:
	JediWeaponAdapter(JediWeaponImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

};

class JediWeaponHelper : public DistributedObjectClassHelper, public Singleton<JediWeaponHelper> {
	static JediWeaponHelper* staticInitializer;

public:
	JediWeaponHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<JediWeaponHelper>;
};

#include "WeaponImplementation.h"

class JediWeaponServant : public WeaponImplementation {
public:
	JediWeapon* _this;

public:
	JediWeaponServant(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, bool eqp, int tp, int cat);
	JediWeaponServant(CreatureObject* creature, const String& temp, const UnicodeString& n, const String& tempn, bool eqp, int tp, int cat);
	virtual ~JediWeaponServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*JEDIWEAPON_H_*/
