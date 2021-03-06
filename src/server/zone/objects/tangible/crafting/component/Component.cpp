/*
 *	server/zone/objects/tangible/crafting/component/Component.cpp generated by engine3 IDL compiler 0.55
 */

#include "Component.h"

#include "ComponentImplementation.h"

#include "../../../player/Player.h"

#include "../../crafting/component/Component.h"

#include "../../../creature/CreatureObject.h"

#include "../../TangibleObject.h"

#include "../../../draftschematic/DraftSchematic.h"

/*
 *	ComponentStub
 */

Component::Component(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new ComponentImplementation(oid, tempCRC, n, tempn);
	_impl->_setStub(this);
}

Component::Component(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempn) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new ComponentImplementation(creature, tempCRC, n, tempn);
	_impl->_setStub(this);
}

Component::Component(DummyConstructorParameter* param) : TangibleObject(param) {
}

Component::~Component() {
}

void Component::sendTo(Player* player, bool doClose) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);
		method.addBooleanParameter(doClose);

		method.executeWithVoidReturn();
	} else
		((ComponentImplementation*) _impl)->sendTo(player, doClose);
}

void Component::generateAttributes(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ComponentImplementation*) _impl)->generateAttributes(player);
}

bool Component::compare(Component* inCmpo) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(inCmpo);

		return method.executeWithBooleanReturn();
	} else
		return ((ComponentImplementation*) _impl)->compare(inCmpo);
}

void Component::updateCraftingValues(DraftSchematic* draftSchematic) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(draftSchematic);

		method.executeWithVoidReturn();
	} else
		((ComponentImplementation*) _impl)->updateCraftingValues(draftSchematic);
}

int Component::useObject(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addObjectParameter(player);

		return method.executeWithSignedIntReturn();
	} else
		return ((ComponentImplementation*) _impl)->useObject(player);
}

float Component::getAttributeValue(String& attributeName) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addAsciiParameter(attributeName);

		return method.executeWithFloatReturn();
	} else
		return ((ComponentImplementation*) _impl)->getAttributeValue(attributeName);
}

int Component::getAttributePrecision(String& attributeName) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addAsciiParameter(attributeName);

		return method.executeWithSignedIntReturn();
	} else
		return ((ComponentImplementation*) _impl)->getAttributePrecision(attributeName);
}

String& Component::getAttributeTitle(String& attributeName) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addAsciiParameter(attributeName);

		method.executeWithAsciiReturn(_return_getAttributeTitle);
		return _return_getAttributeTitle;
	} else
		return ((ComponentImplementation*) _impl)->getAttributeTitle(attributeName);
}

bool Component::getAttributeHidden(String& attributeName) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addAsciiParameter(attributeName);

		return method.executeWithBooleanReturn();
	} else
		return ((ComponentImplementation*) _impl)->getAttributeHidden(attributeName);
}

bool Component::hasProperty(String& attributeName) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addAsciiParameter(attributeName);

		return method.executeWithBooleanReturn();
	} else
		return ((ComponentImplementation*) _impl)->hasProperty(attributeName);
}

void Component::addProperty(String& attribute, float value, int precision, String& title) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);
		method.addAsciiParameter(attribute);
		method.addFloatParameter(value);
		method.addSignedIntParameter(precision);
		method.addAsciiParameter(title);

		method.executeWithVoidReturn();
	} else
		((ComponentImplementation*) _impl)->addProperty(attribute, value, precision, title);
}

int Component::getPropertyCount() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		return method.executeWithSignedIntReturn();
	} else
		return ((ComponentImplementation*) _impl)->getPropertyCount();
}

String& Component::getProperty(const int j) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);
		method.addSignedIntParameter(j);

		method.executeWithAsciiReturn(_return_getProperty);
		return _return_getProperty;
	} else
		return ((ComponentImplementation*) _impl)->getProperty(j);
}

bool Component::changeAttributeValue(String& property, float value) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);
		method.addAsciiParameter(property);
		method.addFloatParameter(value);

		return method.executeWithBooleanReturn();
	} else
		return ((ComponentImplementation*) _impl)->changeAttributeValue(property, value);
}

/*
 *	ComponentAdapter
 */

ComponentAdapter::ComponentAdapter(ComponentImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* ComponentAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		sendTo((Player*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 7:
		generateAttributes((Player*) inv->getObjectParameter());
		break;
	case 8:
		resp->insertBoolean(compare((Component*) inv->getObjectParameter()));
		break;
	case 9:
		updateCraftingValues((DraftSchematic*) inv->getObjectParameter());
		break;
	case 10:
		resp->insertSignedInt(useObject((Player*) inv->getObjectParameter()));
		break;
	case 11:
		resp->insertFloat(getAttributeValue(inv->getAsciiParameter(_param0_getAttributeValue__String_)));
		break;
	case 12:
		resp->insertSignedInt(getAttributePrecision(inv->getAsciiParameter(_param0_getAttributePrecision__String_)));
		break;
	case 13:
		resp->insertAscii(getAttributeTitle(inv->getAsciiParameter(_param0_getAttributeTitle__String_)));
		break;
	case 14:
		resp->insertBoolean(getAttributeHidden(inv->getAsciiParameter(_param0_getAttributeHidden__String_)));
		break;
	case 15:
		resp->insertBoolean(hasProperty(inv->getAsciiParameter(_param0_hasProperty__String_)));
		break;
	case 16:
		addProperty(inv->getAsciiParameter(_param0_addProperty__String_float_int_String_), inv->getFloatParameter(), inv->getSignedIntParameter(), inv->getAsciiParameter(_param3_addProperty__String_float_int_String_));
		break;
	case 17:
		resp->insertSignedInt(getPropertyCount());
		break;
	case 18:
		resp->insertAscii(getProperty(inv->getSignedIntParameter()));
		break;
	case 19:
		resp->insertBoolean(changeAttributeValue(inv->getAsciiParameter(_param0_changeAttributeValue__String_float_), inv->getFloatParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

void ComponentAdapter::sendTo(Player* player, bool doClose) {
	return ((ComponentImplementation*) impl)->sendTo(player, doClose);
}

void ComponentAdapter::generateAttributes(Player* player) {
	return ((ComponentImplementation*) impl)->generateAttributes(player);
}

bool ComponentAdapter::compare(Component* inCmpo) {
	return ((ComponentImplementation*) impl)->compare(inCmpo);
}

void ComponentAdapter::updateCraftingValues(DraftSchematic* draftSchematic) {
	return ((ComponentImplementation*) impl)->updateCraftingValues(draftSchematic);
}

int ComponentAdapter::useObject(Player* player) {
	return ((ComponentImplementation*) impl)->useObject(player);
}

float ComponentAdapter::getAttributeValue(String& attributeName) {
	return ((ComponentImplementation*) impl)->getAttributeValue(attributeName);
}

int ComponentAdapter::getAttributePrecision(String& attributeName) {
	return ((ComponentImplementation*) impl)->getAttributePrecision(attributeName);
}

String& ComponentAdapter::getAttributeTitle(String& attributeName) {
	return ((ComponentImplementation*) impl)->getAttributeTitle(attributeName);
}

bool ComponentAdapter::getAttributeHidden(String& attributeName) {
	return ((ComponentImplementation*) impl)->getAttributeHidden(attributeName);
}

bool ComponentAdapter::hasProperty(String& attributeName) {
	return ((ComponentImplementation*) impl)->hasProperty(attributeName);
}

void ComponentAdapter::addProperty(String& attribute, float value, int precision, String& title) {
	return ((ComponentImplementation*) impl)->addProperty(attribute, value, precision, title);
}

int ComponentAdapter::getPropertyCount() {
	return ((ComponentImplementation*) impl)->getPropertyCount();
}

String& ComponentAdapter::getProperty(const int j) {
	return ((ComponentImplementation*) impl)->getProperty(j);
}

bool ComponentAdapter::changeAttributeValue(String& property, float value) {
	return ((ComponentImplementation*) impl)->changeAttributeValue(property, value);
}

/*
 *	ComponentHelper
 */

ComponentHelper* ComponentHelper::staticInitializer = ComponentHelper::instance();

ComponentHelper::ComponentHelper() {
	className = "Component";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ComponentHelper::finalizeHelper() {
	ComponentHelper::finalize();
}

DistributedObject* ComponentHelper::instantiateObject() {
	return new Component(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ComponentHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ComponentAdapter((ComponentImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	ComponentServant
 */

ComponentServant::ComponentServant(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int tp) : TangibleObjectImplementation(oid, tempCRC, n, tempn, tp) {
	_classHelper = ComponentHelper::instance();
}

ComponentServant::ComponentServant(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int tp) : TangibleObjectImplementation(creature, tempCRC, n, tempn, tp) {
	_classHelper = ComponentHelper::instance();
}

ComponentServant::~ComponentServant() {
}

void ComponentServant::_setStub(DistributedObjectStub* stub) {
	_this = (Component*) stub;
	TangibleObjectServant::_setStub(stub);
}

DistributedObjectStub* ComponentServant::_getStub() {
	return _this;
}

