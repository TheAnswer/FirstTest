/*
 *	server/zone/objects/tangible/wearables/Wearable.cpp generated by engine3 IDL compiler 0.55
 */

#include "Wearable.h"

#include "WearableImplementation.h"

#include "../../creature/CreatureObject.h"

#include "../../player/Player.h"

#include "../../scene/SceneObject.h"

#include "../TangibleObject.h"

#include "../attachment/Attachment.h"

/*
 *	WearableStub
 */

Wearable::Wearable(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, bool eqp) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new WearableImplementation(oid, tempCRC, n, tempn, eqp);
	_impl->_setStub(this);
}

Wearable::Wearable(CreatureObject* creature, unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, bool eqp) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new WearableImplementation(creature, oid, tempCRC, n, tempn, eqp);
	_impl->_setStub(this);
}

Wearable::Wearable(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempn, bool eqp) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new WearableImplementation(creature, tempCRC, n, tempn, eqp);
	_impl->_setStub(this);
}

Wearable::Wearable(DummyConstructorParameter* param) : TangibleObject(param) {
}

Wearable::~Wearable() {
}

void Wearable::parseItemAttributes() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((WearableImplementation*) _impl)->parseItemAttributes();
}

void Wearable::init() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		((WearableImplementation*) _impl)->init();
}

void Wearable::generateAttributes(SceneObject* obj) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		((WearableImplementation*) _impl)->generateAttributes(obj);
}

void Wearable::sendTo(Player* player, bool doClose) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(player);
		method.addBooleanParameter(doClose);

		method.executeWithVoidReturn();
	} else
		((WearableImplementation*) _impl)->sendTo(player, doClose);
}

bool Wearable::hasSkillMod(String& skillModName) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addAsciiParameter(skillModName);

		return method.executeWithBooleanReturn();
	} else
		return ((WearableImplementation*) _impl)->hasSkillMod(skillModName);
}

void Wearable::setMaxSockets(int socket) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addSignedIntParameter(socket);

		method.executeWithVoidReturn();
	} else
		((WearableImplementation*) _impl)->setMaxSockets(socket);
}

void Wearable::setHealthEncumbrance(int healthEnc) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addSignedIntParameter(healthEnc);

		method.executeWithVoidReturn();
	} else
		((WearableImplementation*) _impl)->setHealthEncumbrance(healthEnc);
}

void Wearable::setActionEncumbrance(int actionEnc) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addSignedIntParameter(actionEnc);

		method.executeWithVoidReturn();
	} else
		((WearableImplementation*) _impl)->setActionEncumbrance(actionEnc);
}

void Wearable::setMindEncumbrance(int mindEnc) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addSignedIntParameter(mindEnc);

		method.executeWithVoidReturn();
	} else
		((WearableImplementation*) _impl)->setMindEncumbrance(mindEnc);
}

String& Wearable::getSkillModType(int i) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addSignedIntParameter(i);

		method.executeWithAsciiReturn(_return_getSkillModType);
		return _return_getSkillModType;
	} else
		return ((WearableImplementation*) _impl)->getSkillModType(i);
}

int Wearable::getSkillModValue(String& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);
		method.addAsciiParameter(name);

		return method.executeWithSignedIntReturn();
	} else
		return ((WearableImplementation*) _impl)->getSkillModValue(name);
}

int Wearable::getMaxSockets() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		return method.executeWithSignedIntReturn();
	} else
		return ((WearableImplementation*) _impl)->getMaxSockets();
}

int Wearable::socketsUsed() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		return method.executeWithSignedIntReturn();
	} else
		return ((WearableImplementation*) _impl)->socketsUsed();
}

int Wearable::getHealthEncumbrance() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);

		return method.executeWithSignedIntReturn();
	} else
		return ((WearableImplementation*) _impl)->getHealthEncumbrance();
}

int Wearable::getActionEncumbrance() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);

		return method.executeWithSignedIntReturn();
	} else
		return ((WearableImplementation*) _impl)->getActionEncumbrance();
}

int Wearable::getMindEncumbrance() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);

		return method.executeWithSignedIntReturn();
	} else
		return ((WearableImplementation*) _impl)->getMindEncumbrance();
}

void Wearable::applyAttachment(Player* player, Attachment* attachment) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);
		method.addObjectParameter(player);
		method.addObjectParameter(attachment);

		method.executeWithVoidReturn();
	} else
		((WearableImplementation*) _impl)->applyAttachment(player, attachment);
}

void Wearable::reclaimAttachments(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((WearableImplementation*) _impl)->reclaimAttachments(player);
}

void Wearable::conditionReduction(float damage) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);
		method.addFloatParameter(damage);

		method.executeWithVoidReturn();
	} else
		((WearableImplementation*) _impl)->conditionReduction(damage);
}

/*
 *	WearableAdapter
 */

WearableAdapter::WearableAdapter(WearableImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* WearableAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		parseItemAttributes();
		break;
	case 7:
		init();
		break;
	case 8:
		generateAttributes((SceneObject*) inv->getObjectParameter());
		break;
	case 9:
		sendTo((Player*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 10:
		resp->insertBoolean(hasSkillMod(inv->getAsciiParameter(_param0_hasSkillMod__String_)));
		break;
	case 11:
		setMaxSockets(inv->getSignedIntParameter());
		break;
	case 12:
		setHealthEncumbrance(inv->getSignedIntParameter());
		break;
	case 13:
		setActionEncumbrance(inv->getSignedIntParameter());
		break;
	case 14:
		setMindEncumbrance(inv->getSignedIntParameter());
		break;
	case 15:
		resp->insertAscii(getSkillModType(inv->getSignedIntParameter()));
		break;
	case 16:
		resp->insertSignedInt(getSkillModValue(inv->getAsciiParameter(_param0_getSkillModValue__String_)));
		break;
	case 17:
		resp->insertSignedInt(getMaxSockets());
		break;
	case 18:
		resp->insertSignedInt(socketsUsed());
		break;
	case 19:
		resp->insertSignedInt(getHealthEncumbrance());
		break;
	case 20:
		resp->insertSignedInt(getActionEncumbrance());
		break;
	case 21:
		resp->insertSignedInt(getMindEncumbrance());
		break;
	case 22:
		applyAttachment((Player*) inv->getObjectParameter(), (Attachment*) inv->getObjectParameter());
		break;
	case 23:
		reclaimAttachments((Player*) inv->getObjectParameter());
		break;
	case 24:
		conditionReduction(inv->getFloatParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void WearableAdapter::parseItemAttributes() {
	return ((WearableImplementation*) impl)->parseItemAttributes();
}

void WearableAdapter::init() {
	return ((WearableImplementation*) impl)->init();
}

void WearableAdapter::generateAttributes(SceneObject* obj) {
	return ((WearableImplementation*) impl)->generateAttributes(obj);
}

void WearableAdapter::sendTo(Player* player, bool doClose) {
	return ((WearableImplementation*) impl)->sendTo(player, doClose);
}

bool WearableAdapter::hasSkillMod(String& skillModName) {
	return ((WearableImplementation*) impl)->hasSkillMod(skillModName);
}

void WearableAdapter::setMaxSockets(int socket) {
	return ((WearableImplementation*) impl)->setMaxSockets(socket);
}

void WearableAdapter::setHealthEncumbrance(int healthEnc) {
	return ((WearableImplementation*) impl)->setHealthEncumbrance(healthEnc);
}

void WearableAdapter::setActionEncumbrance(int actionEnc) {
	return ((WearableImplementation*) impl)->setActionEncumbrance(actionEnc);
}

void WearableAdapter::setMindEncumbrance(int mindEnc) {
	return ((WearableImplementation*) impl)->setMindEncumbrance(mindEnc);
}

String& WearableAdapter::getSkillModType(int i) {
	return ((WearableImplementation*) impl)->getSkillModType(i);
}

int WearableAdapter::getSkillModValue(String& name) {
	return ((WearableImplementation*) impl)->getSkillModValue(name);
}

int WearableAdapter::getMaxSockets() {
	return ((WearableImplementation*) impl)->getMaxSockets();
}

int WearableAdapter::socketsUsed() {
	return ((WearableImplementation*) impl)->socketsUsed();
}

int WearableAdapter::getHealthEncumbrance() {
	return ((WearableImplementation*) impl)->getHealthEncumbrance();
}

int WearableAdapter::getActionEncumbrance() {
	return ((WearableImplementation*) impl)->getActionEncumbrance();
}

int WearableAdapter::getMindEncumbrance() {
	return ((WearableImplementation*) impl)->getMindEncumbrance();
}

void WearableAdapter::applyAttachment(Player* player, Attachment* attachment) {
	return ((WearableImplementation*) impl)->applyAttachment(player, attachment);
}

void WearableAdapter::reclaimAttachments(Player* player) {
	return ((WearableImplementation*) impl)->reclaimAttachments(player);
}

void WearableAdapter::conditionReduction(float damage) {
	return ((WearableImplementation*) impl)->conditionReduction(damage);
}

/*
 *	WearableHelper
 */

WearableHelper* WearableHelper::staticInitializer = WearableHelper::instance();

WearableHelper::WearableHelper() {
	className = "Wearable";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void WearableHelper::finalizeHelper() {
	WearableHelper::finalize();
}

DistributedObject* WearableHelper::instantiateObject() {
	return new Wearable(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* WearableHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new WearableAdapter((WearableImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	WearableServant
 */

WearableServant::WearableServant(unsigned long long oid, int tp) : TangibleObjectImplementation(oid, tp) {
	_classHelper = WearableHelper::instance();
}

WearableServant::~WearableServant() {
}

void WearableServant::_setStub(DistributedObjectStub* stub) {
	_this = (Wearable*) stub;
	TangibleObjectServant::_setStub(stub);
}

DistributedObjectStub* WearableServant::_getStub() {
	return _this;
}

