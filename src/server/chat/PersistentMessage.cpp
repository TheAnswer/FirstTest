/*
 *	server/chat/PersistentMessage.cpp generated by engine3 IDL compiler 0.60
 */

#include "PersistentMessage.h"

/*
 *	PersistentMessageStub
 */

PersistentMessage::PersistentMessage() : ManagedObject(DummyConstructorParameter::instance()) {
	ManagedObject::_setImplementation(new PersistentMessageImplementation());
	ManagedObject::_getImplementation()->_setStub(this);
}

PersistentMessage::PersistentMessage(DummyConstructorParameter* param) : ManagedObject(param) {
}

PersistentMessage::~PersistentMessage() {
}


int PersistentMessage::getMailID() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		return method.executeWithSignedIntReturn();
	} else
		return ((PersistentMessageImplementation*) _getImplementation())->getMailID();
}

unsigned long long PersistentMessage::getObjectID() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		return method.executeWithUnsignedLongReturn();
	} else
		return ((PersistentMessageImplementation*) _getImplementation())->getObjectID();
}

UnicodeString PersistentMessage::getSenderName() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		method.executeWithUnicodeReturn(_return_getSenderName);
		return _return_getSenderName;
	} else
		return ((PersistentMessageImplementation*) _getImplementation())->getSenderName();
}

unsigned long long PersistentMessage::getReceiverObjectID() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithUnsignedLongReturn();
	} else
		return ((PersistentMessageImplementation*) _getImplementation())->getReceiverObjectID();
}

byte PersistentMessage::getStatus() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return method.executeWithByteReturn();
	} else
		return ((PersistentMessageImplementation*) _getImplementation())->getStatus();
}

int PersistentMessage::getTimeStamp() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithSignedIntReturn();
	} else
		return ((PersistentMessageImplementation*) _getImplementation())->getTimeStamp();
}

UnicodeString PersistentMessage::getBody() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		method.executeWithUnicodeReturn(_return_getBody);
		return _return_getBody;
	} else
		return ((PersistentMessageImplementation*) _getImplementation())->getBody();
}

UnicodeString PersistentMessage::getSubject() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		method.executeWithUnicodeReturn(_return_getSubject);
		return _return_getSubject;
	} else
		return ((PersistentMessageImplementation*) _getImplementation())->getSubject();
}

void PersistentMessage::setSenderName(const UnicodeString& name) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addUnicodeParameter(name);

		method.executeWithVoidReturn();
	} else
		((PersistentMessageImplementation*) _getImplementation())->setSenderName(name);
}

void PersistentMessage::setReceiverObjectID(unsigned long long oid) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addUnsignedLongParameter(oid);

		method.executeWithVoidReturn();
	} else
		((PersistentMessageImplementation*) _getImplementation())->setReceiverObjectID(oid);
}

void PersistentMessage::setStatus(byte stat) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);
		method.addByteParameter(stat);

		method.executeWithVoidReturn();
	} else
		((PersistentMessageImplementation*) _getImplementation())->setStatus(stat);
}

void PersistentMessage::setTimeStamp(int stamp) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);
		method.addSignedIntParameter(stamp);

		method.executeWithVoidReturn();
	} else
		((PersistentMessageImplementation*) _getImplementation())->setTimeStamp(stamp);
}

void PersistentMessage::setBody(const UnicodeString& message) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);
		method.addUnicodeParameter(message);

		method.executeWithVoidReturn();
	} else
		((PersistentMessageImplementation*) _getImplementation())->setBody(message);
}

void PersistentMessage::setSubject(const UnicodeString& subj) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);
		method.addUnicodeParameter(subj);

		method.executeWithVoidReturn();
	} else
		((PersistentMessageImplementation*) _getImplementation())->setSubject(subj);
}

void PersistentMessage::setParameterizedBody(ParameterizedStringId& body) {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		((PersistentMessageImplementation*) _getImplementation())->setParameterizedBody(body);
}

ParameterizedStringId* PersistentMessage::getParameterizedBody() {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		return ((PersistentMessageImplementation*) _getImplementation())->getParameterizedBody();
}

/*
 *	PersistentMessageImplementation
 */

PersistentMessageImplementation::PersistentMessageImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


PersistentMessageImplementation::~PersistentMessageImplementation() {
}


void PersistentMessageImplementation::finalize() {
}

void PersistentMessageImplementation::_initializeImplementation() {
	_setClassHelper(PersistentMessageHelper::instance());

	_serializationHelperMethod();
}

void PersistentMessageImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (PersistentMessage*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* PersistentMessageImplementation::_getStub() {
	return _this;
}

PersistentMessageImplementation::operator const PersistentMessage*() {
	return _this;
}

TransactionalObject* PersistentMessageImplementation::clone() {
	return (TransactionalObject*) new PersistentMessageImplementation(*this);
}


void PersistentMessageImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void PersistentMessageImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void PersistentMessageImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void PersistentMessageImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void PersistentMessageImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void PersistentMessageImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void PersistentMessageImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void PersistentMessageImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("PersistentMessage");

	addSerializableVariable("senderName", &senderName);
	addSerializableVariable("type", &type);
	addSerializableVariable("subject", &subject);
	addSerializableVariable("body", &body);
	addSerializableVariable("timeStamp", &timeStamp);
	addSerializableVariable("status", &status);
	addSerializableVariable("stringIdBody", &stringIdBody);
	addSerializableVariable("receiverObjectID", &receiverObjectID);
}

PersistentMessageImplementation::PersistentMessageImplementation() {
	_initializeImplementation();
	// server/chat/PersistentMessage.idl(65):  		type = 0;
	type = 0;
	// server/chat/PersistentMessage.idl(67):  		timeStamp = 0;
	timeStamp = 0;
	// server/chat/PersistentMessage.idl(68):  		status = 0x4E;
	status = 0x4E;
	// server/chat/PersistentMessage.idl(70):  		receiverObjectID = 0;
	receiverObjectID = 0;
}

UnicodeString PersistentMessageImplementation::getSenderName() {
	// server/chat/PersistentMessage.idl(78):  		return senderName;
	return senderName;
}

unsigned long long PersistentMessageImplementation::getReceiverObjectID() {
	// server/chat/PersistentMessage.idl(82):  		return receiverObjectID;
	return receiverObjectID;
}

byte PersistentMessageImplementation::getStatus() {
	// server/chat/PersistentMessage.idl(86):  		return status;
	return status;
}

int PersistentMessageImplementation::getTimeStamp() {
	// server/chat/PersistentMessage.idl(90):  		return timeStamp;
	return timeStamp;
}

UnicodeString PersistentMessageImplementation::getBody() {
	// server/chat/PersistentMessage.idl(94):  		return body;
	return body;
}

UnicodeString PersistentMessageImplementation::getSubject() {
	// server/chat/PersistentMessage.idl(98):  		return subject;
	return subject;
}

void PersistentMessageImplementation::setSenderName(const UnicodeString& name) {
	// server/chat/PersistentMessage.idl(102):  		senderName = name;
	senderName = name;
}

void PersistentMessageImplementation::setReceiverObjectID(unsigned long long oid) {
	// server/chat/PersistentMessage.idl(106):  		receiverObjectID = oid;
	receiverObjectID = oid;
}

void PersistentMessageImplementation::setStatus(byte stat) {
	// server/chat/PersistentMessage.idl(110):  		status = stat;
	status = stat;
}

void PersistentMessageImplementation::setTimeStamp(int stamp) {
	// server/chat/PersistentMessage.idl(114):  		timeStamp = stamp;
	timeStamp = stamp;
}

void PersistentMessageImplementation::setBody(const UnicodeString& message) {
	// server/chat/PersistentMessage.idl(118):  		body = message;
	body = message;
}

void PersistentMessageImplementation::setSubject(const UnicodeString& subj) {
	// server/chat/PersistentMessage.idl(122):  		subject = subj;
	subject = subj;
}

ParameterizedStringId* PersistentMessageImplementation::getParameterizedBody() {
	// server/chat/PersistentMessage.idl(130):  		return stringIdBody;
	return (&stringIdBody);
}

/*
 *	PersistentMessageAdapter
 */

PersistentMessageAdapter::PersistentMessageAdapter(PersistentMessageImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* PersistentMessageAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(getMailID());
		break;
	case 7:
		resp->insertLong(getObjectID());
		break;
	case 8:
		resp->insertUnicode(getSenderName());
		break;
	case 9:
		resp->insertLong(getReceiverObjectID());
		break;
	case 10:
		resp->insertByte(getStatus());
		break;
	case 11:
		resp->insertSignedInt(getTimeStamp());
		break;
	case 12:
		resp->insertUnicode(getBody());
		break;
	case 13:
		resp->insertUnicode(getSubject());
		break;
	case 14:
		setSenderName(inv->getUnicodeParameter(_param0_setSenderName__UnicodeString_));
		break;
	case 15:
		setReceiverObjectID(inv->getUnsignedLongParameter());
		break;
	case 16:
		setStatus(inv->getByteParameter());
		break;
	case 17:
		setTimeStamp(inv->getSignedIntParameter());
		break;
	case 18:
		setBody(inv->getUnicodeParameter(_param0_setBody__UnicodeString_));
		break;
	case 19:
		setSubject(inv->getUnicodeParameter(_param0_setSubject__UnicodeString_));
		break;
	default:
		return NULL;
	}

	return resp;
}

int PersistentMessageAdapter::getMailID() {
	return ((PersistentMessageImplementation*) impl)->getMailID();
}

unsigned long long PersistentMessageAdapter::getObjectID() {
	return ((PersistentMessageImplementation*) impl)->getObjectID();
}

UnicodeString PersistentMessageAdapter::getSenderName() {
	return ((PersistentMessageImplementation*) impl)->getSenderName();
}

unsigned long long PersistentMessageAdapter::getReceiverObjectID() {
	return ((PersistentMessageImplementation*) impl)->getReceiverObjectID();
}

byte PersistentMessageAdapter::getStatus() {
	return ((PersistentMessageImplementation*) impl)->getStatus();
}

int PersistentMessageAdapter::getTimeStamp() {
	return ((PersistentMessageImplementation*) impl)->getTimeStamp();
}

UnicodeString PersistentMessageAdapter::getBody() {
	return ((PersistentMessageImplementation*) impl)->getBody();
}

UnicodeString PersistentMessageAdapter::getSubject() {
	return ((PersistentMessageImplementation*) impl)->getSubject();
}

void PersistentMessageAdapter::setSenderName(const UnicodeString& name) {
	((PersistentMessageImplementation*) impl)->setSenderName(name);
}

void PersistentMessageAdapter::setReceiverObjectID(unsigned long long oid) {
	((PersistentMessageImplementation*) impl)->setReceiverObjectID(oid);
}

void PersistentMessageAdapter::setStatus(byte stat) {
	((PersistentMessageImplementation*) impl)->setStatus(stat);
}

void PersistentMessageAdapter::setTimeStamp(int stamp) {
	((PersistentMessageImplementation*) impl)->setTimeStamp(stamp);
}

void PersistentMessageAdapter::setBody(const UnicodeString& message) {
	((PersistentMessageImplementation*) impl)->setBody(message);
}

void PersistentMessageAdapter::setSubject(const UnicodeString& subj) {
	((PersistentMessageImplementation*) impl)->setSubject(subj);
}

/*
 *	PersistentMessageHelper
 */

PersistentMessageHelper* PersistentMessageHelper::staticInitializer = PersistentMessageHelper::instance();

PersistentMessageHelper::PersistentMessageHelper() {
	className = "PersistentMessage";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void PersistentMessageHelper::finalizeHelper() {
	PersistentMessageHelper::finalize();
}

DistributedObject* PersistentMessageHelper::instantiateObject() {
	return new PersistentMessage(DummyConstructorParameter::instance());
}

DistributedObjectServant* PersistentMessageHelper::instantiateServant() {
	return new PersistentMessageImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* PersistentMessageHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new PersistentMessageAdapter((PersistentMessageImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

