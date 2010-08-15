/*
 *	server/zone/objects/player/sui/listbox/SuiListBoxMenuItem.h generated by engine3 IDL compiler 0.60
 */

#ifndef SUILISTBOXMENUITEM_H_
#define SUILISTBOXMENUITEM_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace listbox {

class SuiListBox;

} // namespace listbox
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::listbox;

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace listbox {

class SuiListBoxMenuItem : public ManagedObject {
public:
	SuiListBoxMenuItem(const String& name, unsigned long long oid = 0);

	unsigned long long getObjectID();

	String getOptionName();

protected:
	SuiListBoxMenuItem(DummyConstructorParameter* param);

	virtual ~SuiListBoxMenuItem();

	String _return_getOptionName;

	friend class SuiListBoxMenuItemHelper;
};

} // namespace listbox
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::listbox;

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace listbox {

class SuiListBoxMenuItemImplementation : public ManagedObjectImplementation {
protected:
	String optionName;

	unsigned long long objectID;

public:
	SuiListBoxMenuItemImplementation(const String& name, unsigned long long oid = 0);

	SuiListBoxMenuItemImplementation(DummyConstructorParameter* param);

	unsigned long long getObjectID();

	String getOptionName();

	SuiListBoxMenuItem* _this;

	operator const SuiListBoxMenuItem*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~SuiListBoxMenuItemImplementation();

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

	friend class SuiListBoxMenuItem;
	friend class TransactionalObjectHandle<SuiListBoxMenuItemImplementation*>;
};

class SuiListBoxMenuItemAdapter : public ManagedObjectAdapter {
public:
	SuiListBoxMenuItemAdapter(SuiListBoxMenuItemImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	unsigned long long getObjectID();

	String getOptionName();

};

class SuiListBoxMenuItemHelper : public DistributedObjectClassHelper, public Singleton<SuiListBoxMenuItemHelper> {
	static SuiListBoxMenuItemHelper* staticInitializer;

public:
	SuiListBoxMenuItemHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<SuiListBoxMenuItemHelper>;
};

} // namespace listbox
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::listbox;

#endif /*SUILISTBOXMENUITEM_H_*/
