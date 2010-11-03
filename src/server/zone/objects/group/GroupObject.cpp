/*
 *	server/zone/objects/group/GroupObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "GroupObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/chat/room/ChatRoom.h"

#include "server/zone/Zone.h"

/*
 *	GroupObjectStub
 */

GroupObject::GroupObject() : SceneObject(DummyConstructorParameter::instance()) {
	GroupObjectImplementation* _implementation = new GroupObjectImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

GroupObject::GroupObject(DummyConstructorParameter* param) : SceneObject(param) {
}

GroupObject::~GroupObject() {
}


void GroupObject::sendBaselinesTo(SceneObject* player) {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendBaselinesTo(player);
}

void GroupObject::broadcastMessage(BaseMessage* msg) {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(msg);

		method.executeWithVoidReturn();
	} else
		_implementation->broadcastMessage(msg);
}

void GroupObject::broadcastMessage(PlayerCreature* player, BaseMessage* msg, bool sendSelf) {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);
		method.addObjectParameter(msg);
		method.addBooleanParameter(sendSelf);

		method.executeWithVoidReturn();
	} else
		_implementation->broadcastMessage(player, msg, sendSelf);
}

void GroupObject::addMember(SceneObject* player) {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->addMember(player);
}

void GroupObject::removeMember(SceneObject* player) {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->removeMember(player);
}

void GroupObject::disband() {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		method.executeWithVoidReturn();
	} else
		_implementation->disband();
}

void GroupObject::makeLeader(SceneObject* player) {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->makeLeader(player);
}

bool GroupObject::hasMember(SceneObject* player) {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addObjectParameter(player);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->hasMember(player);
}

void GroupObject::startChatRoom() {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		method.executeWithVoidReturn();
	} else
		_implementation->startChatRoom();
}

void GroupObject::destroyChatRoom() {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		method.executeWithVoidReturn();
	} else
		_implementation->destroyChatRoom();
}

float GroupObject::getGroupHarvestModifier(PlayerCreature* player) {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);
		method.addObjectParameter(player);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getGroupHarvestModifier(player);
}

int GroupObject::getGroupLevel() {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getGroupLevel();
}

ChatRoom* GroupObject::getGroupChannel() {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		return (ChatRoom*) method.executeWithObjectReturn();
	} else
		return _implementation->getGroupChannel();
}

int GroupObject::getGroupSize() {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getGroupSize();
}

SceneObject* GroupObject::getGroupMember(int index) {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);
		method.addSignedIntParameter(index);

		return (SceneObject*) method.executeWithObjectReturn();
	} else
		return _implementation->getGroupMember(index);
}

void GroupObject::initializeLeader(SceneObject* player) {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeLeader(player);
}

SceneObject* GroupObject::getLeader() {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);

		return (SceneObject*) method.executeWithObjectReturn();
	} else
		return _implementation->getLeader();
}

GroupList* GroupObject::getGroupList() {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getGroupList();
}

bool GroupObject::isGroupObject() {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isGroupObject();
}

bool GroupObject::hasSquadLeader() {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->hasSquadLeader();
}

void GroupObject::addGroupModifiers() {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);

		method.executeWithVoidReturn();
	} else
		_implementation->addGroupModifiers();
}

void GroupObject::removeGroupModifiers() {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);

		method.executeWithVoidReturn();
	} else
		_implementation->removeGroupModifiers();
}

void GroupObject::addGroupModifiers(PlayerCreature* player) {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 27);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->addGroupModifiers(player);
}

void GroupObject::removeGroupModifiers(PlayerCreature* player) {
	GroupObjectImplementation* _implementation = (GroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 28);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->removeGroupModifiers(player);
}

DistributedObjectServant* GroupObject::_getImplementation() {
	return _impl;}

void GroupObject::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;}

/*
 *	GroupObjectImplementation
 */

GroupObjectImplementation::GroupObjectImplementation(DummyConstructorParameter* param) : SceneObjectImplementation(param) {
	_initializeImplementation();
}


GroupObjectImplementation::~GroupObjectImplementation() {
}


void GroupObjectImplementation::finalize() {
}

void GroupObjectImplementation::_initializeImplementation() {
	_setClassHelper(GroupObjectHelper::instance());

	_serializationHelperMethod();
}

void GroupObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (GroupObject*) stub;
	SceneObjectImplementation::_setStub(stub);
}

DistributedObjectStub* GroupObjectImplementation::_getStub() {
	return _this;
}

GroupObjectImplementation::operator const GroupObject*() {
	return _this;
}

void GroupObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void GroupObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void GroupObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void GroupObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void GroupObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void GroupObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void GroupObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void GroupObjectImplementation::_serializationHelperMethod() {
	SceneObjectImplementation::_serializationHelperMethod();

	_setClassName("GroupObject");

	addSerializableVariable("groupMembers", &groupMembers);
	addSerializableVariable("chatRoom", &chatRoom);
	addSerializableVariable("groupLevel", &groupLevel);
}

GroupObjectImplementation::GroupObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/group/GroupObject.idl(66):  		groupLevel = 0;
	groupLevel = 0;
	// server/zone/objects/group/GroupObject.idl(68):  		Logger.setLoggingName("GroupObject");
	Logger::setLoggingName("GroupObject");
	// server/zone/objects/group/GroupObject.idl(70):  		chatRoom = null;
	chatRoom = NULL;
}

int GroupObjectImplementation::getGroupLevel() {
	// server/zone/objects/group/GroupObject.idl(101):  		return groupLevel;
	return groupLevel;
}

ChatRoom* GroupObjectImplementation::getGroupChannel() {
	// server/zone/objects/group/GroupObject.idl(105):  		return chatRoom;
	return chatRoom;
}

int GroupObjectImplementation::getGroupSize() {
	// server/zone/objects/group/GroupObject.idl(109):  		return groupMembers.size();
	return (&groupMembers)->size();
}

SceneObject* GroupObjectImplementation::getGroupMember(int index) {
	// server/zone/objects/group/GroupObject.idl(113):  		return groupMembers.get(index);
	return (&groupMembers)->get(index);
}

void GroupObjectImplementation::initializeLeader(SceneObject* player) {
	// server/zone/objects/group/GroupObject.idl(117):  		groupMembers.add(player);
	(&groupMembers)->add(player);
}

SceneObject* GroupObjectImplementation::getLeader() {
	// server/zone/objects/group/GroupObject.idl(121):  		return groupMembers.get(0);
	return (&groupMembers)->get(0);
}

GroupList* GroupObjectImplementation::getGroupList() {
	// server/zone/objects/group/GroupObject.idl(126):  		return groupMembers;
	return (&groupMembers);
}

bool GroupObjectImplementation::isGroupObject() {
	// server/zone/objects/group/GroupObject.idl(130):  		return true;
	return true;
}

/*
 *	GroupObjectAdapter
 */

GroupObjectAdapter::GroupObjectAdapter(GroupObjectImplementation* obj) : SceneObjectAdapter(obj) {
}

Packet* GroupObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		sendBaselinesTo((SceneObject*) inv->getObjectParameter());
		break;
	case 7:
		broadcastMessage((BaseMessage*) inv->getObjectParameter());
		break;
	case 8:
		broadcastMessage((PlayerCreature*) inv->getObjectParameter(), (BaseMessage*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 9:
		addMember((SceneObject*) inv->getObjectParameter());
		break;
	case 10:
		removeMember((SceneObject*) inv->getObjectParameter());
		break;
	case 11:
		disband();
		break;
	case 12:
		makeLeader((SceneObject*) inv->getObjectParameter());
		break;
	case 13:
		resp->insertBoolean(hasMember((SceneObject*) inv->getObjectParameter()));
		break;
	case 14:
		startChatRoom();
		break;
	case 15:
		destroyChatRoom();
		break;
	case 16:
		resp->insertFloat(getGroupHarvestModifier((PlayerCreature*) inv->getObjectParameter()));
		break;
	case 17:
		resp->insertSignedInt(getGroupLevel());
		break;
	case 18:
		resp->insertLong(getGroupChannel()->_getObjectID());
		break;
	case 19:
		resp->insertSignedInt(getGroupSize());
		break;
	case 20:
		resp->insertLong(getGroupMember(inv->getSignedIntParameter())->_getObjectID());
		break;
	case 21:
		initializeLeader((SceneObject*) inv->getObjectParameter());
		break;
	case 22:
		resp->insertLong(getLeader()->_getObjectID());
		break;
	case 23:
		resp->insertBoolean(isGroupObject());
		break;
	case 24:
		resp->insertBoolean(hasSquadLeader());
		break;
	case 25:
		addGroupModifiers();
		break;
	case 26:
		removeGroupModifiers();
		break;
	case 27:
		addGroupModifiers((PlayerCreature*) inv->getObjectParameter());
		break;
	case 28:
		removeGroupModifiers((PlayerCreature*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void GroupObjectAdapter::sendBaselinesTo(SceneObject* player) {
	((GroupObjectImplementation*) impl)->sendBaselinesTo(player);
}

void GroupObjectAdapter::broadcastMessage(BaseMessage* msg) {
	((GroupObjectImplementation*) impl)->broadcastMessage(msg);
}

void GroupObjectAdapter::broadcastMessage(PlayerCreature* player, BaseMessage* msg, bool sendSelf) {
	((GroupObjectImplementation*) impl)->broadcastMessage(player, msg, sendSelf);
}

void GroupObjectAdapter::addMember(SceneObject* player) {
	((GroupObjectImplementation*) impl)->addMember(player);
}

void GroupObjectAdapter::removeMember(SceneObject* player) {
	((GroupObjectImplementation*) impl)->removeMember(player);
}

void GroupObjectAdapter::disband() {
	((GroupObjectImplementation*) impl)->disband();
}

void GroupObjectAdapter::makeLeader(SceneObject* player) {
	((GroupObjectImplementation*) impl)->makeLeader(player);
}

bool GroupObjectAdapter::hasMember(SceneObject* player) {
	return ((GroupObjectImplementation*) impl)->hasMember(player);
}

void GroupObjectAdapter::startChatRoom() {
	((GroupObjectImplementation*) impl)->startChatRoom();
}

void GroupObjectAdapter::destroyChatRoom() {
	((GroupObjectImplementation*) impl)->destroyChatRoom();
}

float GroupObjectAdapter::getGroupHarvestModifier(PlayerCreature* player) {
	return ((GroupObjectImplementation*) impl)->getGroupHarvestModifier(player);
}

int GroupObjectAdapter::getGroupLevel() {
	return ((GroupObjectImplementation*) impl)->getGroupLevel();
}

ChatRoom* GroupObjectAdapter::getGroupChannel() {
	return ((GroupObjectImplementation*) impl)->getGroupChannel();
}

int GroupObjectAdapter::getGroupSize() {
	return ((GroupObjectImplementation*) impl)->getGroupSize();
}

SceneObject* GroupObjectAdapter::getGroupMember(int index) {
	return ((GroupObjectImplementation*) impl)->getGroupMember(index);
}

void GroupObjectAdapter::initializeLeader(SceneObject* player) {
	((GroupObjectImplementation*) impl)->initializeLeader(player);
}

SceneObject* GroupObjectAdapter::getLeader() {
	return ((GroupObjectImplementation*) impl)->getLeader();
}

bool GroupObjectAdapter::isGroupObject() {
	return ((GroupObjectImplementation*) impl)->isGroupObject();
}

bool GroupObjectAdapter::hasSquadLeader() {
	return ((GroupObjectImplementation*) impl)->hasSquadLeader();
}

void GroupObjectAdapter::addGroupModifiers() {
	((GroupObjectImplementation*) impl)->addGroupModifiers();
}

void GroupObjectAdapter::removeGroupModifiers() {
	((GroupObjectImplementation*) impl)->removeGroupModifiers();
}

void GroupObjectAdapter::addGroupModifiers(PlayerCreature* player) {
	((GroupObjectImplementation*) impl)->addGroupModifiers(player);
}

void GroupObjectAdapter::removeGroupModifiers(PlayerCreature* player) {
	((GroupObjectImplementation*) impl)->removeGroupModifiers(player);
}

/*
 *	GroupObjectHelper
 */

GroupObjectHelper* GroupObjectHelper::staticInitializer = GroupObjectHelper::instance();

GroupObjectHelper::GroupObjectHelper() {
	className = "GroupObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void GroupObjectHelper::finalizeHelper() {
	GroupObjectHelper::finalize();
}

DistributedObject* GroupObjectHelper::instantiateObject() {
	return new GroupObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* GroupObjectHelper::instantiateServant() {
	return new GroupObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* GroupObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new GroupObjectAdapter((GroupObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

