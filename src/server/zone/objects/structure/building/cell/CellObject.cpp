/*
 *	server/zone/objects/structure/building/cell/CellObject.cpp generated by engine3 IDL compiler 0.55
 */

#include "CellObject.h"

#include "CellObjectImplementation.h"

#include "../../../scene/SceneObject.h"

#include "../../../player/Player.h"

#include "../BuildingObject.h"

/*
 *	CellObjectStub
 */

CellObject::CellObject(unsigned long long oid, BuildingObject* buio) : SceneObject(DummyConstructorParameter::instance()) {
	_impl = new CellObjectImplementation(oid, buio);
	_impl->_setStub(this);
}

CellObject::CellObject(unsigned long long oid, BuildingObject* buio, int number) : SceneObject(DummyConstructorParameter::instance()) {
	_impl = new CellObjectImplementation(oid, buio, number);
	_impl->_setStub(this);
}

CellObject::CellObject(DummyConstructorParameter* param) : SceneObject(param) {
}

CellObject::~CellObject() {
}

int CellObject::getChildrenSize() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		return method.executeWithSignedIntReturn();
	} else
		return ((CellObjectImplementation*) _impl)->getChildrenSize();
}

void CellObject::addChild(SceneObject* object, bool doLock) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(object);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else
		((CellObjectImplementation*) _impl)->addChild(object, doLock);
}

void CellObject::removeChild(SceneObject* object, bool doLock) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(object);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else
		((CellObjectImplementation*) _impl)->removeChild(object, doLock);
}

SceneObject* CellObject::getChild(int idx) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addSignedIntParameter(idx);

		return (SceneObject*) method.executeWithObjectReturn();
	} else
		return ((CellObjectImplementation*) _impl)->getChild(idx);
}

void CellObject::setCellNumber(int i) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addSignedIntParameter(i);

		method.executeWithVoidReturn();
	} else
		((CellObjectImplementation*) _impl)->setCellNumber(i);
}

int CellObject::getCellNumber() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithSignedIntReturn();
	} else
		return ((CellObjectImplementation*) _impl)->getCellNumber();
}

void CellObject::setAttributes(String& attributeString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addAsciiParameter(attributeString);

		method.executeWithVoidReturn();
	} else
		((CellObjectImplementation*) _impl)->setAttributes(attributeString);
}

String& CellObject::getAttributes() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		method.executeWithAsciiReturn(_return_getAttributes);
		return _return_getAttributes;
	} else
		return ((CellObjectImplementation*) _impl)->getAttributes();
}

void CellObject::parseItemAttributes() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		method.executeWithVoidReturn();
	} else
		((CellObjectImplementation*) _impl)->parseItemAttributes();
}

String& CellObject::getTemplateName() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		method.executeWithAsciiReturn(_return_getTemplateName);
		return _return_getTemplateName;
	} else
		return ((CellObjectImplementation*) _impl)->getTemplateName();
}

/*
 *	CellObjectAdapter
 */

CellObjectAdapter::CellObjectAdapter(CellObjectImplementation* obj) : SceneObjectAdapter(obj) {
}

Packet* CellObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(getChildrenSize());
		break;
	case 7:
		addChild((SceneObject*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 8:
		removeChild((SceneObject*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 9:
		resp->insertLong(getChild(inv->getSignedIntParameter())->_getObjectID());
		break;
	case 10:
		setCellNumber(inv->getSignedIntParameter());
		break;
	case 11:
		resp->insertSignedInt(getCellNumber());
		break;
	case 12:
		setAttributes(inv->getAsciiParameter(_param0_setAttributes__String_));
		break;
	case 13:
		resp->insertAscii(getAttributes());
		break;
	case 14:
		parseItemAttributes();
		break;
	case 15:
		resp->insertAscii(getTemplateName());
		break;
	default:
		return NULL;
	}

	return resp;
}

int CellObjectAdapter::getChildrenSize() {
	return ((CellObjectImplementation*) impl)->getChildrenSize();
}

void CellObjectAdapter::addChild(SceneObject* object, bool doLock) {
	return ((CellObjectImplementation*) impl)->addChild(object, doLock);
}

void CellObjectAdapter::removeChild(SceneObject* object, bool doLock) {
	return ((CellObjectImplementation*) impl)->removeChild(object, doLock);
}

SceneObject* CellObjectAdapter::getChild(int idx) {
	return ((CellObjectImplementation*) impl)->getChild(idx);
}

void CellObjectAdapter::setCellNumber(int i) {
	return ((CellObjectImplementation*) impl)->setCellNumber(i);
}

int CellObjectAdapter::getCellNumber() {
	return ((CellObjectImplementation*) impl)->getCellNumber();
}

void CellObjectAdapter::setAttributes(String& attributeString) {
	return ((CellObjectImplementation*) impl)->setAttributes(attributeString);
}

String& CellObjectAdapter::getAttributes() {
	return ((CellObjectImplementation*) impl)->getAttributes();
}

void CellObjectAdapter::parseItemAttributes() {
	return ((CellObjectImplementation*) impl)->parseItemAttributes();
}

String& CellObjectAdapter::getTemplateName() {
	return ((CellObjectImplementation*) impl)->getTemplateName();
}

/*
 *	CellObjectHelper
 */

CellObjectHelper* CellObjectHelper::staticInitializer = CellObjectHelper::instance();

CellObjectHelper::CellObjectHelper() {
	className = "CellObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void CellObjectHelper::finalizeHelper() {
	CellObjectHelper::finalize();
}

DistributedObject* CellObjectHelper::instantiateObject() {
	return new CellObject(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* CellObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CellObjectAdapter((CellObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	CellObjectServant
 */

CellObjectServant::CellObjectServant(unsigned long long oid, int type) : SceneObjectImplementation(oid, type) {
	_classHelper = CellObjectHelper::instance();
}

CellObjectServant::~CellObjectServant() {
}

void CellObjectServant::_setStub(DistributedObjectStub* stub) {
	_this = (CellObject*) stub;
	SceneObjectServant::_setStub(stub);
}

DistributedObjectStub* CellObjectServant::_getStub() {
	return _this;
}

