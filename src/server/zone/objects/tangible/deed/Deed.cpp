/*
 *	server/zone/objects/tangible/deed/Deed.cpp generated by engine3 IDL compiler 0.60
 */

#include "Deed.h"

#include "server/zone/Zone.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/templates/SharedObjectTemplate.h"

/*
 *	DeedStub
 */

Deed::Deed() : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new DeedImplementation();
	_impl->_setStub(this);
}

Deed::Deed(DummyConstructorParameter* param) : TangibleObject(param) {
}

Deed::~Deed() {
}


void Deed::initializeTransientMembers() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((DeedImplementation*) _impl)->initializeTransientMembers();
}

void Deed::loadTemplateData(SharedObjectTemplate* templateData) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((DeedImplementation*) _impl)->loadTemplateData(templateData);
}

void Deed::fillAttributeList(AttributeListMessage* alm, PlayerCreature* object) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((DeedImplementation*) _impl)->fillAttributeList(alm, object);
}

void Deed::setGeneratedObjectTemplate(const String& templ) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addAsciiParameter(templ);

		method.executeWithVoidReturn();
	} else
		((DeedImplementation*) _impl)->setGeneratedObjectTemplate(templ);
}

String Deed::getGeneratedObjectTemplate() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		method.executeWithAsciiReturn(_return_getGeneratedObjectTemplate);
		return _return_getGeneratedObjectTemplate;
	} else
		return ((DeedImplementation*) _impl)->getGeneratedObjectTemplate();
}

bool Deed::isDeedObject() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithBooleanReturn();
	} else
		return ((DeedImplementation*) _impl)->isDeedObject();
}

/*
 *	DeedImplementation
 */

DeedImplementation::DeedImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}

DeedImplementation::~DeedImplementation() {
}


void DeedImplementation::finalize() {
}

void DeedImplementation::_initializeImplementation() {
	_setClassHelper(DeedHelper::instance());

	_serializationHelperMethod();
}

void DeedImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (Deed*) stub;
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* DeedImplementation::_getStub() {
	return _this;
}

DeedImplementation::operator const Deed*() {
	return _this;
}

void DeedImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void DeedImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void DeedImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void DeedImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void DeedImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void DeedImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void DeedImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void DeedImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("Deed");

	addSerializableVariable("generatedObjectTemplate", &generatedObjectTemplate);
}

DeedImplementation::DeedImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/deed/Deed.idl(58):  		Logger.setLoggingName("Deed");
	Logger::setLoggingName("Deed");
}

void DeedImplementation::setGeneratedObjectTemplate(const String& templ) {
	// server/zone/objects/tangible/deed/Deed.idl(80):  		generatedObjectTemplate = templ;
	generatedObjectTemplate = templ;
}

String DeedImplementation::getGeneratedObjectTemplate() {
	// server/zone/objects/tangible/deed/Deed.idl(87):  		return generatedObjectTemplate;
	return generatedObjectTemplate;
}

bool DeedImplementation::isDeedObject() {
	// server/zone/objects/tangible/deed/Deed.idl(91):  		return true;
	return true;
}

/*
 *	DeedAdapter
 */

DeedAdapter::DeedAdapter(DeedImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* DeedAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	case 7:
		setGeneratedObjectTemplate(inv->getAsciiParameter(_param0_setGeneratedObjectTemplate__String_));
		break;
	case 8:
		resp->insertAscii(getGeneratedObjectTemplate());
		break;
	case 9:
		resp->insertBoolean(isDeedObject());
		break;
	default:
		return NULL;
	}

	return resp;
}

void DeedAdapter::initializeTransientMembers() {
	((DeedImplementation*) impl)->initializeTransientMembers();
}

void DeedAdapter::setGeneratedObjectTemplate(const String& templ) {
	((DeedImplementation*) impl)->setGeneratedObjectTemplate(templ);
}

String DeedAdapter::getGeneratedObjectTemplate() {
	return ((DeedImplementation*) impl)->getGeneratedObjectTemplate();
}

bool DeedAdapter::isDeedObject() {
	return ((DeedImplementation*) impl)->isDeedObject();
}

/*
 *	DeedHelper
 */

DeedHelper* DeedHelper::staticInitializer = DeedHelper::instance();

DeedHelper::DeedHelper() {
	className = "Deed";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void DeedHelper::finalizeHelper() {
	DeedHelper::finalize();
}

DistributedObject* DeedHelper::instantiateObject() {
	return new Deed(DummyConstructorParameter::instance());
}

DistributedObjectServant* DeedHelper::instantiateServant() {
	return new DeedImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* DeedHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DeedAdapter((DeedImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

