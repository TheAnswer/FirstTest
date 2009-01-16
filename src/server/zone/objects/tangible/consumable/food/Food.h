/*
 *	server/zone/objects/tangible/consumable/food/Food.h generated by engine3 IDL compiler 0.55
 */

#ifndef FOOD_H_
#define FOOD_H_

#include "engine/orb/DistributedObjectBroker.h"

class SceneObject;

class CreatureObject;

class Player;

class TangibleObject;

class Consumable;

#include "../Consumable.h"

class Food : public Consumable {
public:
	Food(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn);

	Food(CreatureObject* creature, unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn);

	int useObject(Player* player);

	void generateAttributes(SceneObject* obj);

	void setNutrition(int n);

	void setFlavor(int f);

	void setQuantity(int q);

	void setFilling(int f);

	int getNutrition();

	int getFlavor();

	int getQuantity();

	int getFilling();

protected:
	Food(DummyConstructorParameter* param);

	virtual ~Food();

	friend class FoodHelper;
};

class FoodImplementation;

class FoodAdapter : public ConsumableAdapter {
public:
	FoodAdapter(FoodImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int useObject(Player* player);

	void generateAttributes(SceneObject* obj);

	void setNutrition(int n);

	void setFlavor(int f);

	void setQuantity(int q);

	void setFilling(int f);

	int getNutrition();

	int getFlavor();

	int getQuantity();

	int getFilling();

};

class FoodHelper : public DistributedObjectClassHelper, public Singleton<FoodHelper> {
	static FoodHelper* staticInitializer;

public:
	FoodHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<FoodHelper>;
};

#include "../ConsumableImplementation.h"

class FoodServant : public ConsumableImplementation {
public:
	Food* _this;

public:
	FoodServant(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int type);
	FoodServant(CreatureObject* creature, unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int type);
	virtual ~FoodServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*FOOD_H_*/
