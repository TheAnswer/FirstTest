/*
 *	server/zone/objects/mission/BountyMissionObjective.h generated by engine3 IDL compiler 0.60
 */

#ifndef BOUNTYMISSIONOBJECTIVE_H_
#define BOUNTYMISSIONOBJECTIVE_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace mission {

class MissionObject;

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

namespace server {
namespace zone {
namespace objects {
namespace mission {

class MissionObserver;

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class AiAgent;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace templates {

class SharedObjectTemplate;

} // namespace templates
} // namespace zone
} // namespace server

using namespace server::zone::templates;

#include "server/zone/templates/TemplateReference.h"

#include "engine/util/Observer.h"

#include "engine/util/Observable.h"

#include "server/zone/objects/mission/MissionObjective.h"

namespace server {
namespace zone {
namespace objects {
namespace mission {

class BountyMissionObjective : public MissionObjective {
public:
	BountyMissionObjective(MissionObject* mission);

	void initializeTransientMembers();

	void activate();

	void abort();

	void complete();

	void spawnTarget(const String& terrainName);

	int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void setNpcTemplateToSpawn(SharedObjectTemplate* sp);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	BountyMissionObjective(DummyConstructorParameter* param);

	virtual ~BountyMissionObjective();

	friend class BountyMissionObjectiveHelper;
};

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

namespace server {
namespace zone {
namespace objects {
namespace mission {

class BountyMissionObjectiveImplementation : public MissionObjectiveImplementation {
protected:
	TemplateReference<SharedObjectTemplate*> npcTemplateToSpawn;

	ManagedReference<AiAgent* > npcTarget;

public:
	BountyMissionObjectiveImplementation(MissionObject* mission);

	BountyMissionObjectiveImplementation(DummyConstructorParameter* param);

	void finalize();

	void initializeTransientMembers();

	void activate();

	void abort();

	void complete();

	void spawnTarget(const String& terrainName);

	int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void setNpcTemplateToSpawn(SharedObjectTemplate* sp);

	BountyMissionObjective* _this;

	operator const BountyMissionObjective*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~BountyMissionObjectiveImplementation();

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

	friend class BountyMissionObjective;
};

class BountyMissionObjectiveAdapter : public MissionObjectiveAdapter {
public:
	BountyMissionObjectiveAdapter(BountyMissionObjectiveImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void finalize();

	void initializeTransientMembers();

	void activate();

	void abort();

	void complete();

	void spawnTarget(const String& terrainName);

	int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

protected:
	String _param0_spawnTarget__String_;
};

class BountyMissionObjectiveHelper : public DistributedObjectClassHelper, public Singleton<BountyMissionObjectiveHelper> {
	static BountyMissionObjectiveHelper* staticInitializer;

public:
	BountyMissionObjectiveHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<BountyMissionObjectiveHelper>;
};

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

#endif /*BOUNTYMISSIONOBJECTIVE_H_*/