/*
 *	server/zone/objects/installation/factory/FactoryObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef FACTORYOBJECT_H_
#define FACTORYOBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace manufactureschematic {

class ManufactureSchematic;

} // namespace manufactureschematic
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::manufactureschematic;

namespace server {
namespace zone {
namespace objects {
namespace factorycrate {

class FactoryCrate;

} // namespace factorycrate
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::factorycrate;

#include "server/zone/objects/installation/InstallationObject.h"

namespace server {
namespace zone {
namespace objects {
namespace installation {
namespace factory {

class FactoryObject : public InstallationObject {
public:
	FactoryObject();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void initializeTransientMembers();

	void fillAttributeList(AttributeListMessage* msg, PlayerCreature* object);

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player);

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	bool isFactory();

	void createChildObjects();

	void updateInstallationWork();

	void sendInsertManuSui(PlayerCreature* player);

	void sendIngredientsNeededSui(PlayerCreature* player);

	void sendIngredientHopper(PlayerCreature* player);

	void sendOutputHopper(PlayerCreature* player);

	void handleInsertFactorySchem(PlayerCreature* player, ManufactureSchematic* schematic);

	void handleRemoveFactorySchem(PlayerCreature* player);

	void handleOperateToggle(PlayerCreature* player);

	void createNewObject();

protected:
	FactoryObject(DummyConstructorParameter* param);

	virtual ~FactoryObject();

	friend class FactoryObjectHelper;
};

} // namespace factory
} // namespace installation
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::installation::factory;

namespace server {
namespace zone {
namespace objects {
namespace installation {
namespace factory {

class FactoryObjectImplementation : public InstallationObjectImplementation {
protected:
	Vector<int> craftingTabsSupported;

	int timer;

	ManagedReference<PlayerCreature* > currentUser;

	int currentRunCount;

public:
	FactoryObjectImplementation();

	FactoryObjectImplementation(DummyConstructorParameter* param);

	void loadTemplateData(SharedObjectTemplate* templateData);

	void initializeTransientMembers();

	void fillAttributeList(AttributeListMessage* msg, PlayerCreature* object);

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player);

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	bool isFactory();

	void createChildObjects();

	void updateInstallationWork();

	void sendInsertManuSui(PlayerCreature* player);

	void sendIngredientsNeededSui(PlayerCreature* player);

	void sendIngredientHopper(PlayerCreature* player);

	void sendOutputHopper(PlayerCreature* player);

	void handleInsertFactorySchem(PlayerCreature* player, ManufactureSchematic* schematic);

	void handleRemoveFactorySchem(PlayerCreature* player);

	void handleOperateToggle(PlayerCreature* player);

private:
	void startFactory();

	void stopFactory(const String& message, const String& tt, const String& to, const int di);

public:
	void createNewObject();

private:
	FactoryCrate* locateCrateInOutputHopper(TangibleObject* prototype);

	FactoryCrate* createNewFactoryCrate(unsigned int type, TangibleObject* prototype);

	bool removeIngredientsFromHopper(ManufactureSchematic* schematic);

public:
	FactoryObject* _this;

	operator const FactoryObject*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~FactoryObjectImplementation();

	TransactionalObject* clone();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();

	friend class FactoryObject;
	friend class TransactionalObjectHandle<FactoryObjectImplementation*>;
};

class FactoryObjectAdapter : public InstallationObjectAdapter {
public:
	FactoryObjectAdapter(FactoryObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	bool isFactory();

	void createChildObjects();

	void updateInstallationWork();

	void sendInsertManuSui(PlayerCreature* player);

	void sendIngredientsNeededSui(PlayerCreature* player);

	void sendIngredientHopper(PlayerCreature* player);

	void sendOutputHopper(PlayerCreature* player);

	void handleInsertFactorySchem(PlayerCreature* player, ManufactureSchematic* schematic);

	void handleRemoveFactorySchem(PlayerCreature* player);

	void handleOperateToggle(PlayerCreature* player);

	void createNewObject();

};

class FactoryObjectHelper : public DistributedObjectClassHelper, public Singleton<FactoryObjectHelper> {
	static FactoryObjectHelper* staticInitializer;

public:
	FactoryObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<FactoryObjectHelper>;
};

} // namespace factory
} // namespace installation
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::installation::factory;

#endif /*FACTORYOBJECT_H_*/
