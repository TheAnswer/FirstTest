/*
 *	server/zone/objects/tangible/terminal/cloning/CloningTerminal.cpp generated by engine3 IDL compiler 0.55
 */

#include "CloningTerminal.h"

#include "CloningTerminalImplementation.h"

#include "../../../player/Player.h"

#include "../../../tangible/TangibleObject.h"

#include "../../../structure/building/cloningfacility/CloningFacility.h"

#include "../Terminal.h"

/*
 *	CloningTerminalStub
 */

CloningTerminal::CloningTerminal(unsigned long long objid, float x, float z, float y, unsigned int cost) : Terminal(DummyConstructorParameter::instance()) {
	_impl = new CloningTerminalImplementation(objid, x, z, y, cost);
	_impl->_setStub(this);
}

CloningTerminal::CloningTerminal(DummyConstructorParameter* param) : Terminal(param) {
}

CloningTerminal::~CloningTerminal() {
}

int CloningTerminal::useObject(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		return method.executeWithSignedIntReturn();
	} else
		return ((CloningTerminalImplementation*) _impl)->useObject(player);
}

void CloningTerminal::storeData(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((CloningTerminalImplementation*) _impl)->storeData(player);
}

void CloningTerminal::setCloningFacility(CloningFacility* facility) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(facility);

		method.executeWithVoidReturn();
	} else
		((CloningTerminalImplementation*) _impl)->setCloningFacility(facility);
}

void CloningTerminal::setCost(unsigned int amount) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addUnsignedIntParameter(amount);

		method.executeWithVoidReturn();
	} else
		((CloningTerminalImplementation*) _impl)->setCost(amount);
}

CloningFacility* CloningTerminal::getCloningFacility() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return (CloningFacility*) method.executeWithObjectReturn();
	} else
		return ((CloningTerminalImplementation*) _impl)->getCloningFacility();
}

unsigned int CloningTerminal::getCost() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((CloningTerminalImplementation*) _impl)->getCost();
}

/*
 *	CloningTerminalAdapter
 */

CloningTerminalAdapter::CloningTerminalAdapter(CloningTerminalImplementation* obj) : TerminalAdapter(obj) {
}

Packet* CloningTerminalAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(useObject((Player*) inv->getObjectParameter()));
		break;
	case 7:
		storeData((Player*) inv->getObjectParameter());
		break;
	case 8:
		setCloningFacility((CloningFacility*) inv->getObjectParameter());
		break;
	case 9:
		setCost(inv->getUnsignedIntParameter());
		break;
	case 10:
		resp->insertLong(getCloningFacility()->_getObjectID());
		break;
	case 11:
		resp->insertInt(getCost());
		break;
	default:
		return NULL;
	}

	return resp;
}

int CloningTerminalAdapter::useObject(Player* player) {
	return ((CloningTerminalImplementation*) impl)->useObject(player);
}

void CloningTerminalAdapter::storeData(Player* player) {
	return ((CloningTerminalImplementation*) impl)->storeData(player);
}

void CloningTerminalAdapter::setCloningFacility(CloningFacility* facility) {
	return ((CloningTerminalImplementation*) impl)->setCloningFacility(facility);
}

void CloningTerminalAdapter::setCost(unsigned int amount) {
	return ((CloningTerminalImplementation*) impl)->setCost(amount);
}

CloningFacility* CloningTerminalAdapter::getCloningFacility() {
	return ((CloningTerminalImplementation*) impl)->getCloningFacility();
}

unsigned int CloningTerminalAdapter::getCost() {
	return ((CloningTerminalImplementation*) impl)->getCost();
}

/*
 *	CloningTerminalHelper
 */

CloningTerminalHelper* CloningTerminalHelper::staticInitializer = CloningTerminalHelper::instance();

CloningTerminalHelper::CloningTerminalHelper() {
	className = "CloningTerminal";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void CloningTerminalHelper::finalizeHelper() {
	CloningTerminalHelper::finalize();
}

DistributedObject* CloningTerminalHelper::instantiateObject() {
	return new CloningTerminal(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* CloningTerminalHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CloningTerminalAdapter((CloningTerminalImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	CloningTerminalServant
 */

CloningTerminalServant::CloningTerminalServant(unsigned int objCRC, unsigned long long objid, const UnicodeString& n, const String& tempn, float x, float z, float y, int terminalType) : TerminalImplementation(objCRC, objid, n, tempn, x, z, y, terminalType) {
	_classHelper = CloningTerminalHelper::instance();
}

CloningTerminalServant::~CloningTerminalServant() {
}

void CloningTerminalServant::_setStub(DistributedObjectStub* stub) {
	_this = (CloningTerminal*) stub;
	TerminalServant::_setStub(stub);
}

DistributedObjectStub* CloningTerminalServant::_getStub() {
	return _this;
}

