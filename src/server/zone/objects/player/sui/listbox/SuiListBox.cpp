/*
 *	server/zone/objects/player/sui/listbox/SuiListBox.cpp generated by engine3 IDL compiler 0.55
 */

#include "SuiListBox.h"

#include "SuiListBoxImplementation.h"

#include "../SuiBox.h"

#include "../../Player.h"

/*
 *	SuiListBoxStub
 */

SuiListBox::SuiListBox(Player* player, unsigned int windowType, unsigned int listBoxType) : SuiBox(DummyConstructorParameter::instance()) {
	_impl = new SuiListBoxImplementation(player, windowType, listBoxType);
	_impl->_setStub(this);
}

SuiListBox::SuiListBox(DummyConstructorParameter* param) : SuiBox(param) {
}

SuiListBox::~SuiListBox() {
}

void SuiListBox::addMenuItem(const String& item, unsigned long long objectID) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addAsciiParameter(item);
		method.addUnsignedLongParameter(objectID);

		method.executeWithVoidReturn();
	} else
		((SuiListBoxImplementation*) _impl)->addMenuItem(item, objectID);
}

String& SuiListBox::getMenuItemName(int index) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addSignedIntParameter(index);

		method.executeWithAsciiReturn(_return_getMenuItemName);
		return _return_getMenuItemName;
	} else
		return ((SuiListBoxImplementation*) _impl)->getMenuItemName(index);
}

void SuiListBox::removeAllMenuItems() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		method.executeWithVoidReturn();
	} else
		((SuiListBoxImplementation*) _impl)->removeAllMenuItems();
}

int SuiListBox::getMenuSize() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithSignedIntReturn();
	} else
		return ((SuiListBoxImplementation*) _impl)->getMenuSize();
}

unsigned long long SuiListBox::getMenuObjectID(int idx) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addSignedIntParameter(idx);

		return method.executeWithUnsignedLongReturn();
	} else
		return ((SuiListBoxImplementation*) _impl)->getMenuObjectID(idx);
}

BaseMessage* SuiListBox::generateMessage() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return (BaseMessage*) method.executeWithObjectReturn();
	} else
		return ((SuiListBoxImplementation*) _impl)->generateMessage();
}

void SuiListBox::setNextBox(unsigned long long boxID) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addUnsignedLongParameter(boxID);

		method.executeWithVoidReturn();
	} else
		((SuiListBoxImplementation*) _impl)->setNextBox(boxID);
}

void SuiListBox::setPreviousBox(unsigned long long boxID) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addUnsignedLongParameter(boxID);

		method.executeWithVoidReturn();
	} else
		((SuiListBoxImplementation*) _impl)->setPreviousBox(boxID);
}

unsigned long long SuiListBox::getNextBox() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		return method.executeWithUnsignedLongReturn();
	} else
		return ((SuiListBoxImplementation*) _impl)->getNextBox();
}

unsigned long long SuiListBox::getPreviousBox() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		return method.executeWithUnsignedLongReturn();
	} else
		return ((SuiListBoxImplementation*) _impl)->getPreviousBox();
}

/*
 *	SuiListBoxAdapter
 */

SuiListBoxAdapter::SuiListBoxAdapter(SuiListBoxImplementation* obj) : SuiBoxAdapter(obj) {
}

Packet* SuiListBoxAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		addMenuItem(inv->getAsciiParameter(_param0_addMenuItem__String_long_), inv->getUnsignedLongParameter());
		break;
	case 7:
		resp->insertAscii(getMenuItemName(inv->getSignedIntParameter()));
		break;
	case 8:
		removeAllMenuItems();
		break;
	case 9:
		resp->insertSignedInt(getMenuSize());
		break;
	case 10:
		resp->insertLong(getMenuObjectID(inv->getSignedIntParameter()));
		break;
	case 11:
		resp->insertLong(generateMessage()->_getObjectID());
		break;
	case 12:
		setNextBox(inv->getUnsignedLongParameter());
		break;
	case 13:
		setPreviousBox(inv->getUnsignedLongParameter());
		break;
	case 14:
		resp->insertLong(getNextBox());
		break;
	case 15:
		resp->insertLong(getPreviousBox());
		break;
	default:
		return NULL;
	}

	return resp;
}

void SuiListBoxAdapter::addMenuItem(const String& item, unsigned long long objectID) {
	return ((SuiListBoxImplementation*) impl)->addMenuItem(item, objectID);
}

String& SuiListBoxAdapter::getMenuItemName(int index) {
	return ((SuiListBoxImplementation*) impl)->getMenuItemName(index);
}

void SuiListBoxAdapter::removeAllMenuItems() {
	return ((SuiListBoxImplementation*) impl)->removeAllMenuItems();
}

int SuiListBoxAdapter::getMenuSize() {
	return ((SuiListBoxImplementation*) impl)->getMenuSize();
}

unsigned long long SuiListBoxAdapter::getMenuObjectID(int idx) {
	return ((SuiListBoxImplementation*) impl)->getMenuObjectID(idx);
}

BaseMessage* SuiListBoxAdapter::generateMessage() {
	return ((SuiListBoxImplementation*) impl)->generateMessage();
}

void SuiListBoxAdapter::setNextBox(unsigned long long boxID) {
	return ((SuiListBoxImplementation*) impl)->setNextBox(boxID);
}

void SuiListBoxAdapter::setPreviousBox(unsigned long long boxID) {
	return ((SuiListBoxImplementation*) impl)->setPreviousBox(boxID);
}

unsigned long long SuiListBoxAdapter::getNextBox() {
	return ((SuiListBoxImplementation*) impl)->getNextBox();
}

unsigned long long SuiListBoxAdapter::getPreviousBox() {
	return ((SuiListBoxImplementation*) impl)->getPreviousBox();
}

/*
 *	SuiListBoxHelper
 */

SuiListBoxHelper* SuiListBoxHelper::staticInitializer = SuiListBoxHelper::instance();

SuiListBoxHelper::SuiListBoxHelper() {
	className = "SuiListBox";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void SuiListBoxHelper::finalizeHelper() {
	SuiListBoxHelper::finalize();
}

DistributedObject* SuiListBoxHelper::instantiateObject() {
	return new SuiListBox(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SuiListBoxHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SuiListBoxAdapter((SuiListBoxImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	SuiListBoxServant
 */

SuiListBoxServant::SuiListBoxServant(Player* player, unsigned int windowType, unsigned int boxType) : SuiBoxImplementation(player, windowType, boxType) {
	_classHelper = SuiListBoxHelper::instance();
}

SuiListBoxServant::~SuiListBoxServant() {
}

void SuiListBoxServant::_setStub(DistributedObjectStub* stub) {
	_this = (SuiListBox*) stub;
	SuiBoxServant::_setStub(stub);
}

DistributedObjectStub* SuiListBoxServant::_getStub() {
	return _this;
}

