/*
 *	server/zone/objects/tangible/crafting/component/armorcomponent/ArmorComponent.cpp generated by engine3 IDL compiler 0.55
 */

#include "ArmorComponent.h"

#include "ArmorComponentImplementation.h"

#include "../../../TangibleObject.h"

#include "../../../../draftschematic/DraftSchematic.h"

#include "../../../../creature/CreatureObject.h"

#include "../Component.h"

/*
 *	ArmorComponentStub
 */

ArmorComponent::ArmorComponent(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn) : Component(DummyConstructorParameter::instance()) {
	_impl = new ArmorComponentImplementation(oid, tempCRC, n, tempn);
	_impl->_setStub(this);
}

ArmorComponent::ArmorComponent(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempn) : Component(DummyConstructorParameter::instance()) {
	_impl = new ArmorComponentImplementation(creature, tempCRC, n, tempn);
	_impl->_setStub(this);
}

ArmorComponent::ArmorComponent(DummyConstructorParameter* param) : Component(param) {
}

ArmorComponent::~ArmorComponent() {
}

void ArmorComponent::updateCraftingValues(DraftSchematic* draftSchematic) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(draftSchematic);

		method.executeWithVoidReturn();
	} else
		((ArmorComponentImplementation*) _impl)->updateCraftingValues(draftSchematic);
}

String& ArmorComponent::getSpecialResist(int i) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addSignedIntParameter(i);

		method.executeWithAsciiReturn(_return_getSpecialResist);
		return _return_getSpecialResist;
	} else
		return ((ArmorComponentImplementation*) _impl)->getSpecialResist(i);
}

int ArmorComponent::getSpecialResistCount() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		return method.executeWithSignedIntReturn();
	} else
		return ((ArmorComponentImplementation*) _impl)->getSpecialResistCount();
}

/*
 *	ArmorComponentAdapter
 */

ArmorComponentAdapter::ArmorComponentAdapter(ArmorComponentImplementation* obj) : ComponentAdapter(obj) {
}

Packet* ArmorComponentAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		updateCraftingValues((DraftSchematic*) inv->getObjectParameter());
		break;
	case 7:
		resp->insertAscii(getSpecialResist(inv->getSignedIntParameter()));
		break;
	case 8:
		resp->insertSignedInt(getSpecialResistCount());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ArmorComponentAdapter::updateCraftingValues(DraftSchematic* draftSchematic) {
	return ((ArmorComponentImplementation*) impl)->updateCraftingValues(draftSchematic);
}

String& ArmorComponentAdapter::getSpecialResist(int i) {
	return ((ArmorComponentImplementation*) impl)->getSpecialResist(i);
}

int ArmorComponentAdapter::getSpecialResistCount() {
	return ((ArmorComponentImplementation*) impl)->getSpecialResistCount();
}

/*
 *	ArmorComponentHelper
 */

ArmorComponentHelper* ArmorComponentHelper::staticInitializer = ArmorComponentHelper::instance();

ArmorComponentHelper::ArmorComponentHelper() {
	className = "ArmorComponent";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ArmorComponentHelper::finalizeHelper() {
	ArmorComponentHelper::finalize();
}

DistributedObject* ArmorComponentHelper::instantiateObject() {
	return new ArmorComponent(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ArmorComponentHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ArmorComponentAdapter((ArmorComponentImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	ArmorComponentServant
 */

ArmorComponentServant::ArmorComponentServant(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn) : ComponentImplementation(oid, tempCRC, n, tempn) {
	_classHelper = ArmorComponentHelper::instance();
}

ArmorComponentServant::ArmorComponentServant(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempn) : ComponentImplementation(creature, tempCRC, n, tempn) {
	_classHelper = ArmorComponentHelper::instance();
}

ArmorComponentServant::~ArmorComponentServant() {
}

void ArmorComponentServant::_setStub(DistributedObjectStub* stub) {
	_this = (ArmorComponent*) stub;
	ComponentServant::_setStub(stub);
}

DistributedObjectStub* ArmorComponentServant::_getStub() {
	return _this;
}

