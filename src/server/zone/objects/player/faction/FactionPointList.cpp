/*
 *	server/zone/objects/player/faction/FactionPointList.cpp generated by engine3 IDL compiler 0.55
 */

#include "FactionPointList.h"

#include "FactionPointListImplementation.h"

/*
 *	FactionPointListStub
 */

FactionPointList::FactionPointList() {
	_impl = new FactionPointListImplementation();
	_impl->_setStub(this);
}

FactionPointList::FactionPointList(DummyConstructorParameter* param) {
	_impl = NULL;
}

FactionPointList::~FactionPointList() {
}

void FactionPointList::add(String& obj) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addAsciiParameter(obj);

		method.executeWithVoidReturn();
	} else
		((FactionPointListImplementation*) _impl)->add(obj);
}

String& FactionPointList::get(int index) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addSignedIntParameter(index);

		method.executeWithAsciiReturn(_return_get);
		return _return_get;
	} else
		return ((FactionPointListImplementation*) _impl)->get(index);
}

bool FactionPointList::isEmpty() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		return method.executeWithBooleanReturn();
	} else
		return ((FactionPointListImplementation*) _impl)->isEmpty();
}

int FactionPointList::size() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithSignedIntReturn();
	} else
		return ((FactionPointListImplementation*) _impl)->size();
}

/*
 *	FactionPointListAdapter
 */

FactionPointListAdapter::FactionPointListAdapter(FactionPointListImplementation* obj) : DistributedObjectAdapter((DistributedObjectServant*) obj) {
}

Packet* FactionPointListAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		add(inv->getAsciiParameter(_param0_add__String_));
		break;
	case 7:
		resp->insertAscii(get(inv->getSignedIntParameter()));
		break;
	case 8:
		resp->insertBoolean(isEmpty());
		break;
	case 9:
		resp->insertSignedInt(size());
		break;
	default:
		return NULL;
	}

	return resp;
}

void FactionPointListAdapter::add(String& obj) {
	return ((FactionPointListImplementation*) impl)->add(obj);
}

String& FactionPointListAdapter::get(int index) {
	return ((FactionPointListImplementation*) impl)->get(index);
}

bool FactionPointListAdapter::isEmpty() {
	return ((FactionPointListImplementation*) impl)->isEmpty();
}

int FactionPointListAdapter::size() {
	return ((FactionPointListImplementation*) impl)->size();
}

/*
 *	FactionPointListHelper
 */

FactionPointListHelper* FactionPointListHelper::staticInitializer = FactionPointListHelper::instance();

FactionPointListHelper::FactionPointListHelper() {
	className = "FactionPointList";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void FactionPointListHelper::finalizeHelper() {
	FactionPointListHelper::finalize();
}

DistributedObject* FactionPointListHelper::instantiateObject() {
	return new FactionPointList(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* FactionPointListHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new FactionPointListAdapter((FactionPointListImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	FactionPointListServant
 */

FactionPointListServant::FactionPointListServant() {
	_classHelper = FactionPointListHelper::instance();
}

FactionPointListServant::~FactionPointListServant() {
}

void FactionPointListServant::_setStub(DistributedObjectStub* stub) {
	_this = (FactionPointList*) stub;
}

DistributedObjectStub* FactionPointListServant::_getStub() {
	return _this;
}

