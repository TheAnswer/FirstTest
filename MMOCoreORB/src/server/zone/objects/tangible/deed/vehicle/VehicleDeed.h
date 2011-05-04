/*
 *	server/zone/objects/tangible/deed/vehicle/VehicleDeed.h generated by engine3 IDL compiler 0.60
 */

#ifndef VEHICLEDEED_H_
#define VEHICLEDEED_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class TangibleObject;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace packets {
namespace object {

class ObjectMenuResponse;

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;

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
namespace player {

class PlayerCreature;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

namespace server {
namespace zone {
namespace templates {

class SharedObjectTemplate;

} // namespace templates
} // namespace zone
} // namespace server

using namespace server::zone::templates;

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "engine/lua/LuaObject.h"

#include "server/zone/objects/tangible/deed/Deed.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace deed {
namespace vehicle {

class VehicleDeed : public Deed {
public:
	VehicleDeed();

	void initializeTransientMembers();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void fillAttributeList(AttributeListMessage* alm, PlayerCreature* object);

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player);

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	void updateCraftingValues(ManufactureSchematic* schematic);

	bool isVehicleDeedObject();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	VehicleDeed(DummyConstructorParameter* param);

	virtual ~VehicleDeed();

	friend class VehicleDeedHelper;
};

} // namespace vehicle
} // namespace deed
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::deed::vehicle;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace deed {
namespace vehicle {

class VehicleDeedImplementation : public DeedImplementation {
protected:
	int hitPoints;

	String controlDeviceObjectTemplate;

public:
	VehicleDeedImplementation();

	VehicleDeedImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void fillAttributeList(AttributeListMessage* alm, PlayerCreature* object);

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player);

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	void updateCraftingValues(ManufactureSchematic* schematic);

	bool isVehicleDeedObject();

	VehicleDeed* _this;

	operator const VehicleDeed*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~VehicleDeedImplementation();

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
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class VehicleDeed;
};

class VehicleDeedAdapter : public DeedAdapter {
public:
	VehicleDeedAdapter(VehicleDeedImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	void updateCraftingValues(ManufactureSchematic* schematic);

	bool isVehicleDeedObject();

};

class VehicleDeedHelper : public DistributedObjectClassHelper, public Singleton<VehicleDeedHelper> {
	static VehicleDeedHelper* staticInitializer;

public:
	VehicleDeedHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<VehicleDeedHelper>;
};

} // namespace vehicle
} // namespace deed
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::deed::vehicle;

#endif /*VEHICLEDEED_H_*/