/*
 *	server/zone/objects/draftschematic/DraftSchematicIngredient.cpp generated by engine3 IDL compiler 0.55
 */

#include "DraftSchematicIngredient.h"

#include "DraftSchematicIngredientImplementation.h"

#include "../../packets/object/ObjectControllerMessage.h"

/*
 *	DraftSchematicIngredientStub
 */

DraftSchematicIngredient::DraftSchematicIngredient(const String& ingredientTemplateName, const String& ingredientTitleName, const int slotoption, const String& resourceType, unsigned int resourceQuantity, unsigned int combineType, float contribution) {
	_impl = new DraftSchematicIngredientImplementation(ingredientTemplateName, ingredientTitleName, slotoption, resourceType, resourceQuantity, combineType, contribution);
	_impl->_setStub(this);
}

DraftSchematicIngredient::DraftSchematicIngredient(DraftSchematicIngredient* ingredient) {
	_impl = new DraftSchematicIngredientImplementation(ingredient);
	_impl->_setStub(this);
}

DraftSchematicIngredient::DraftSchematicIngredient(DummyConstructorParameter* param) {
	_impl = NULL;
}

DraftSchematicIngredient::~DraftSchematicIngredient() {
}

void DraftSchematicIngredient::helperSendToPlayer(ObjectControllerMessage* msg) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(msg);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicIngredientImplementation*) _impl)->helperSendToPlayer(msg);
}

String& DraftSchematicIngredient::getTemplateName() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithAsciiReturn(_return_getTemplateName);
		return _return_getTemplateName;
	} else
		return ((DraftSchematicIngredientImplementation*) _impl)->getTemplateName();
}

String& DraftSchematicIngredient::getTitleName() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		method.executeWithAsciiReturn(_return_getTitleName);
		return _return_getTitleName;
	} else
		return ((DraftSchematicIngredientImplementation*) _impl)->getTitleName();
}

String& DraftSchematicIngredient::getResourceType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		method.executeWithAsciiReturn(_return_getResourceType);
		return _return_getResourceType;
	} else
		return ((DraftSchematicIngredientImplementation*) _impl)->getResourceType();
}

unsigned int DraftSchematicIngredient::getResourceQuantity() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicIngredientImplementation*) _impl)->getResourceQuantity();
}

unsigned int DraftSchematicIngredient::getCombineType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicIngredientImplementation*) _impl)->getCombineType();
}

int DraftSchematicIngredient::getSlotType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicIngredientImplementation*) _impl)->getSlotType();
}

bool DraftSchematicIngredient::isOptionalSlot() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		return method.executeWithBooleanReturn();
	} else
		return ((DraftSchematicIngredientImplementation*) _impl)->isOptionalSlot();
}

bool DraftSchematicIngredient::isIdenticalSlot() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		return method.executeWithBooleanReturn();
	} else
		return ((DraftSchematicIngredientImplementation*) _impl)->isIdenticalSlot();
}

bool DraftSchematicIngredient::isResourceSlot() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		return method.executeWithBooleanReturn();
	} else
		return ((DraftSchematicIngredientImplementation*) _impl)->isResourceSlot();
}

bool DraftSchematicIngredient::isMixedSlot() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		return method.executeWithBooleanReturn();
	} else
		return ((DraftSchematicIngredientImplementation*) _impl)->isMixedSlot();
}

float DraftSchematicIngredient::getContribution() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		return method.executeWithFloatReturn();
	} else
		return ((DraftSchematicIngredientImplementation*) _impl)->getContribution();
}

/*
 *	DraftSchematicIngredientAdapter
 */

DraftSchematicIngredientAdapter::DraftSchematicIngredientAdapter(DraftSchematicIngredientImplementation* obj) : DistributedObjectAdapter((DistributedObjectServant*) obj) {
}

Packet* DraftSchematicIngredientAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		helperSendToPlayer((ObjectControllerMessage*) inv->getObjectParameter());
		break;
	case 7:
		resp->insertAscii(getTemplateName());
		break;
	case 8:
		resp->insertAscii(getTitleName());
		break;
	case 9:
		resp->insertAscii(getResourceType());
		break;
	case 10:
		resp->insertInt(getResourceQuantity());
		break;
	case 11:
		resp->insertInt(getCombineType());
		break;
	case 12:
		resp->insertSignedInt(getSlotType());
		break;
	case 13:
		resp->insertBoolean(isOptionalSlot());
		break;
	case 14:
		resp->insertBoolean(isIdenticalSlot());
		break;
	case 15:
		resp->insertBoolean(isResourceSlot());
		break;
	case 16:
		resp->insertBoolean(isMixedSlot());
		break;
	case 17:
		resp->insertFloat(getContribution());
		break;
	default:
		return NULL;
	}

	return resp;
}

void DraftSchematicIngredientAdapter::helperSendToPlayer(ObjectControllerMessage* msg) {
	return ((DraftSchematicIngredientImplementation*) impl)->helperSendToPlayer(msg);
}

String& DraftSchematicIngredientAdapter::getTemplateName() {
	return ((DraftSchematicIngredientImplementation*) impl)->getTemplateName();
}

String& DraftSchematicIngredientAdapter::getTitleName() {
	return ((DraftSchematicIngredientImplementation*) impl)->getTitleName();
}

String& DraftSchematicIngredientAdapter::getResourceType() {
	return ((DraftSchematicIngredientImplementation*) impl)->getResourceType();
}

unsigned int DraftSchematicIngredientAdapter::getResourceQuantity() {
	return ((DraftSchematicIngredientImplementation*) impl)->getResourceQuantity();
}

unsigned int DraftSchematicIngredientAdapter::getCombineType() {
	return ((DraftSchematicIngredientImplementation*) impl)->getCombineType();
}

int DraftSchematicIngredientAdapter::getSlotType() {
	return ((DraftSchematicIngredientImplementation*) impl)->getSlotType();
}

bool DraftSchematicIngredientAdapter::isOptionalSlot() {
	return ((DraftSchematicIngredientImplementation*) impl)->isOptionalSlot();
}

bool DraftSchematicIngredientAdapter::isIdenticalSlot() {
	return ((DraftSchematicIngredientImplementation*) impl)->isIdenticalSlot();
}

bool DraftSchematicIngredientAdapter::isResourceSlot() {
	return ((DraftSchematicIngredientImplementation*) impl)->isResourceSlot();
}

bool DraftSchematicIngredientAdapter::isMixedSlot() {
	return ((DraftSchematicIngredientImplementation*) impl)->isMixedSlot();
}

float DraftSchematicIngredientAdapter::getContribution() {
	return ((DraftSchematicIngredientImplementation*) impl)->getContribution();
}

/*
 *	DraftSchematicIngredientHelper
 */

DraftSchematicIngredientHelper* DraftSchematicIngredientHelper::staticInitializer = DraftSchematicIngredientHelper::instance();

DraftSchematicIngredientHelper::DraftSchematicIngredientHelper() {
	className = "DraftSchematicIngredient";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void DraftSchematicIngredientHelper::finalizeHelper() {
	DraftSchematicIngredientHelper::finalize();
}

DistributedObject* DraftSchematicIngredientHelper::instantiateObject() {
	return new DraftSchematicIngredient(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* DraftSchematicIngredientHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DraftSchematicIngredientAdapter((DraftSchematicIngredientImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	DraftSchematicIngredientServant
 */

DraftSchematicIngredientServant::DraftSchematicIngredientServant() {
	_classHelper = DraftSchematicIngredientHelper::instance();
}

DraftSchematicIngredientServant::~DraftSchematicIngredientServant() {
}

void DraftSchematicIngredientServant::_setStub(DistributedObjectStub* stub) {
	_this = (DraftSchematicIngredient*) stub;
}

DistributedObjectStub* DraftSchematicIngredientServant::_getStub() {
	return _this;
}

