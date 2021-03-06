/*
 *	server/zone/managers/resource/ResourceSpawn.cpp generated by engine3 IDL compiler 0.55
 */

#include "ResourceSpawn.h"

#include "ResourceSpawnImplementation.h"

#include "ResourceSpawn.h"

#include "SpawnLocation.h"

#include "../../objects/scene/SceneObject.h"

/*
 *	ResourceSpawnStub
 */

ResourceSpawn::ResourceSpawn(String& inType) : SceneObject(DummyConstructorParameter::instance()) {
	_impl = new ResourceSpawnImplementation(inType);
	_impl->_setStub(this);
}

ResourceSpawn::ResourceSpawn(DummyConstructorParameter* param) : SceneObject(param) {
}

ResourceSpawn::~ResourceSpawn() {
}

void ResourceSpawn::addSpawnLocation(SpawnLocation* location) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(location);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->addSpawnLocation(location);
}

SpawnLocation* ResourceSpawn::removeSpawnLocation(unsigned int oid) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addUnsignedIntParameter(oid);

		return (SpawnLocation*) method.executeWithObjectReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->removeSpawnLocation(oid);
}

SpawnLocation* ResourceSpawn::getSpawnLocation(int i) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addSignedIntParameter(i);

		return (SpawnLocation*) method.executeWithObjectReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->getSpawnLocation(i);
}

int ResourceSpawn::getSpawnLocationSize() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithSignedIntReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->getSpawnLocationSize();
}

void ResourceSpawn::setName(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setName(inString);
}

void ResourceSpawn::setClass1(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setClass1(inString);
}

void ResourceSpawn::setClass2(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setClass2(inString);
}

void ResourceSpawn::setClass3(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setClass3(inString);
}

void ResourceSpawn::setClass4(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setClass4(inString);
}

void ResourceSpawn::setClass5(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setClass5(inString);
}

void ResourceSpawn::setClass6(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setClass6(inString);
}

void ResourceSpawn::setClass7(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setClass7(inString);
}

void ResourceSpawn::setAtt1(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt1(inString);
}

void ResourceSpawn::setAtt2(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt2(inString);
}

void ResourceSpawn::setAtt3(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt3(inString);
}

void ResourceSpawn::setAtt4(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt4(inString);
}

void ResourceSpawn::setAtt5(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt5(inString);
}

void ResourceSpawn::setAtt6(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt6(inString);
}

void ResourceSpawn::setAtt7(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt7(inString);
}

void ResourceSpawn::setAtt8(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt8(inString);
}

void ResourceSpawn::setAtt9(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt9(inString);
}

void ResourceSpawn::setAtt10(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 27);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt10(inString);
}

void ResourceSpawn::setAtt11(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 28);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt11(inString);
}

void ResourceSpawn::setAtt1Stat(int inInt) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 29);
		method.addSignedIntParameter(inInt);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt1Stat(inInt);
}

void ResourceSpawn::setAtt2Stat(int inInt) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 30);
		method.addSignedIntParameter(inInt);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt2Stat(inInt);
}

void ResourceSpawn::setAtt3Stat(int inInt) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 31);
		method.addSignedIntParameter(inInt);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt3Stat(inInt);
}

void ResourceSpawn::setAtt4Stat(int inInt) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 32);
		method.addSignedIntParameter(inInt);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt4Stat(inInt);
}

void ResourceSpawn::setAtt5Stat(int inInt) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 33);
		method.addSignedIntParameter(inInt);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt5Stat(inInt);
}

void ResourceSpawn::setAtt6Stat(int inInt) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 34);
		method.addSignedIntParameter(inInt);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt6Stat(inInt);
}

void ResourceSpawn::setAtt7Stat(int inInt) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 35);
		method.addSignedIntParameter(inInt);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt7Stat(inInt);
}

void ResourceSpawn::setAtt8Stat(int inInt) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 36);
		method.addSignedIntParameter(inInt);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt8Stat(inInt);
}

void ResourceSpawn::setAtt9Stat(int inInt) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 37);
		method.addSignedIntParameter(inInt);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt9Stat(inInt);
}

void ResourceSpawn::setAtt10Stat(int inInt) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 38);
		method.addSignedIntParameter(inInt);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt10Stat(inInt);
}

void ResourceSpawn::setAtt11Stat(int inInt) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 39);
		method.addSignedIntParameter(inInt);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setAtt11Stat(inInt);
}

void ResourceSpawn::setMaxType(int inInt) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 40);
		method.addSignedIntParameter(inInt);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setMaxType(inInt);
}

void ResourceSpawn::setMinType(int inInt) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 41);
		method.addSignedIntParameter(inInt);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setMinType(inInt);
}

void ResourceSpawn::setMaxPool(int inInt) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 42);
		method.addSignedIntParameter(inInt);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setMaxPool(inInt);
}

void ResourceSpawn::setMinPool(int inInt) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 43);
		method.addSignedIntParameter(inInt);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setMinPool(inInt);
}

void ResourceSpawn::setContainerName(const String& inString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 44);
		method.addAsciiParameter(inString);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->setContainerName(inString);
}

String& ResourceSpawn::getName() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 45);

		method.executeWithAsciiReturn(_return_getName);
		return _return_getName;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getName();
}

String& ResourceSpawn::getType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 46);

		method.executeWithAsciiReturn(_return_getType);
		return _return_getType;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getType();
}

String& ResourceSpawn::getClass1() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 47);

		method.executeWithAsciiReturn(_return_getClass1);
		return _return_getClass1;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getClass1();
}

String& ResourceSpawn::getClass2() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 48);

		method.executeWithAsciiReturn(_return_getClass2);
		return _return_getClass2;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getClass2();
}

String& ResourceSpawn::getClass3() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 49);

		method.executeWithAsciiReturn(_return_getClass3);
		return _return_getClass3;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getClass3();
}

String& ResourceSpawn::getClass4() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 50);

		method.executeWithAsciiReturn(_return_getClass4);
		return _return_getClass4;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getClass4();
}

String& ResourceSpawn::getClass5() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 51);

		method.executeWithAsciiReturn(_return_getClass5);
		return _return_getClass5;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getClass5();
}

String& ResourceSpawn::getClass6() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 52);

		method.executeWithAsciiReturn(_return_getClass6);
		return _return_getClass6;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getClass6();
}

String& ResourceSpawn::getClass7() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 53);

		method.executeWithAsciiReturn(_return_getClass7);
		return _return_getClass7;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getClass7();
}

String& ResourceSpawn::getAtt1() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 54);

		method.executeWithAsciiReturn(_return_getAtt1);
		return _return_getAtt1;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt1();
}

String& ResourceSpawn::getAtt2() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 55);

		method.executeWithAsciiReturn(_return_getAtt2);
		return _return_getAtt2;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt2();
}

String& ResourceSpawn::getAtt3() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 56);

		method.executeWithAsciiReturn(_return_getAtt3);
		return _return_getAtt3;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt3();
}

String& ResourceSpawn::getAtt4() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 57);

		method.executeWithAsciiReturn(_return_getAtt4);
		return _return_getAtt4;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt4();
}

String& ResourceSpawn::getAtt5() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 58);

		method.executeWithAsciiReturn(_return_getAtt5);
		return _return_getAtt5;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt5();
}

String& ResourceSpawn::getAtt6() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 59);

		method.executeWithAsciiReturn(_return_getAtt6);
		return _return_getAtt6;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt6();
}

String& ResourceSpawn::getAtt7() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 60);

		method.executeWithAsciiReturn(_return_getAtt7);
		return _return_getAtt7;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt7();
}

String& ResourceSpawn::getAtt8() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 61);

		method.executeWithAsciiReturn(_return_getAtt8);
		return _return_getAtt8;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt8();
}

String& ResourceSpawn::getAtt9() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 62);

		method.executeWithAsciiReturn(_return_getAtt9);
		return _return_getAtt9;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt9();
}

String& ResourceSpawn::getAtt10() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 63);

		method.executeWithAsciiReturn(_return_getAtt10);
		return _return_getAtt10;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt10();
}

String& ResourceSpawn::getAtt11() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 64);

		method.executeWithAsciiReturn(_return_getAtt11);
		return _return_getAtt11;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt11();
}

int ResourceSpawn::getAtt1Stat() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 65);

		return method.executeWithSignedIntReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt1Stat();
}

int ResourceSpawn::getAtt2Stat() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 66);

		return method.executeWithSignedIntReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt2Stat();
}

int ResourceSpawn::getAtt3Stat() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 67);

		return method.executeWithSignedIntReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt3Stat();
}

int ResourceSpawn::getAtt4Stat() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 68);

		return method.executeWithSignedIntReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt4Stat();
}

int ResourceSpawn::getAtt5Stat() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 69);

		return method.executeWithSignedIntReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt5Stat();
}

int ResourceSpawn::getAtt6Stat() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 70);

		return method.executeWithSignedIntReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt6Stat();
}

int ResourceSpawn::getAtt7Stat() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 71);

		return method.executeWithSignedIntReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt7Stat();
}

int ResourceSpawn::getAtt8Stat() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 72);

		return method.executeWithSignedIntReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt8Stat();
}

int ResourceSpawn::getAtt9Stat() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 73);

		return method.executeWithSignedIntReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt9Stat();
}

int ResourceSpawn::getAtt10Stat() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 74);

		return method.executeWithSignedIntReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt10Stat();
}

int ResourceSpawn::getAtt11Stat() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 75);

		return method.executeWithSignedIntReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->getAtt11Stat();
}

int ResourceSpawn::getMaxType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 76);

		return method.executeWithSignedIntReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->getMaxType();
}

int ResourceSpawn::getMinType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 77);

		return method.executeWithSignedIntReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->getMinType();
}

int ResourceSpawn::getMaxPool() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 78);

		return method.executeWithSignedIntReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->getMaxPool();
}

int ResourceSpawn::getMinPool() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 79);

		return method.executeWithSignedIntReturn();
	} else
		return ((ResourceSpawnImplementation*) _impl)->getMinPool();
}

String& ResourceSpawn::getContainerName() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 80);

		method.executeWithAsciiReturn(_return_getContainerName);
		return _return_getContainerName;
	} else
		return ((ResourceSpawnImplementation*) _impl)->getContainerName();
}

void ResourceSpawn::toString() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 81);

		method.executeWithVoidReturn();
	} else
		((ResourceSpawnImplementation*) _impl)->toString();
}

/*
 *	ResourceSpawnAdapter
 */

ResourceSpawnAdapter::ResourceSpawnAdapter(ResourceSpawnImplementation* obj) : SceneObjectAdapter(obj) {
}

Packet* ResourceSpawnAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		addSpawnLocation((SpawnLocation*) inv->getObjectParameter());
		break;
	case 7:
		resp->insertLong(removeSpawnLocation(inv->getUnsignedIntParameter())->_getObjectID());
		break;
	case 8:
		resp->insertLong(getSpawnLocation(inv->getSignedIntParameter())->_getObjectID());
		break;
	case 9:
		resp->insertSignedInt(getSpawnLocationSize());
		break;
	case 10:
		setName(inv->getAsciiParameter(_param0_setName__String_));
		break;
	case 11:
		setClass1(inv->getAsciiParameter(_param0_setClass1__String_));
		break;
	case 12:
		setClass2(inv->getAsciiParameter(_param0_setClass2__String_));
		break;
	case 13:
		setClass3(inv->getAsciiParameter(_param0_setClass3__String_));
		break;
	case 14:
		setClass4(inv->getAsciiParameter(_param0_setClass4__String_));
		break;
	case 15:
		setClass5(inv->getAsciiParameter(_param0_setClass5__String_));
		break;
	case 16:
		setClass6(inv->getAsciiParameter(_param0_setClass6__String_));
		break;
	case 17:
		setClass7(inv->getAsciiParameter(_param0_setClass7__String_));
		break;
	case 18:
		setAtt1(inv->getAsciiParameter(_param0_setAtt1__String_));
		break;
	case 19:
		setAtt2(inv->getAsciiParameter(_param0_setAtt2__String_));
		break;
	case 20:
		setAtt3(inv->getAsciiParameter(_param0_setAtt3__String_));
		break;
	case 21:
		setAtt4(inv->getAsciiParameter(_param0_setAtt4__String_));
		break;
	case 22:
		setAtt5(inv->getAsciiParameter(_param0_setAtt5__String_));
		break;
	case 23:
		setAtt6(inv->getAsciiParameter(_param0_setAtt6__String_));
		break;
	case 24:
		setAtt7(inv->getAsciiParameter(_param0_setAtt7__String_));
		break;
	case 25:
		setAtt8(inv->getAsciiParameter(_param0_setAtt8__String_));
		break;
	case 26:
		setAtt9(inv->getAsciiParameter(_param0_setAtt9__String_));
		break;
	case 27:
		setAtt10(inv->getAsciiParameter(_param0_setAtt10__String_));
		break;
	case 28:
		setAtt11(inv->getAsciiParameter(_param0_setAtt11__String_));
		break;
	case 29:
		setAtt1Stat(inv->getSignedIntParameter());
		break;
	case 30:
		setAtt2Stat(inv->getSignedIntParameter());
		break;
	case 31:
		setAtt3Stat(inv->getSignedIntParameter());
		break;
	case 32:
		setAtt4Stat(inv->getSignedIntParameter());
		break;
	case 33:
		setAtt5Stat(inv->getSignedIntParameter());
		break;
	case 34:
		setAtt6Stat(inv->getSignedIntParameter());
		break;
	case 35:
		setAtt7Stat(inv->getSignedIntParameter());
		break;
	case 36:
		setAtt8Stat(inv->getSignedIntParameter());
		break;
	case 37:
		setAtt9Stat(inv->getSignedIntParameter());
		break;
	case 38:
		setAtt10Stat(inv->getSignedIntParameter());
		break;
	case 39:
		setAtt11Stat(inv->getSignedIntParameter());
		break;
	case 40:
		setMaxType(inv->getSignedIntParameter());
		break;
	case 41:
		setMinType(inv->getSignedIntParameter());
		break;
	case 42:
		setMaxPool(inv->getSignedIntParameter());
		break;
	case 43:
		setMinPool(inv->getSignedIntParameter());
		break;
	case 44:
		setContainerName(inv->getAsciiParameter(_param0_setContainerName__String_));
		break;
	case 45:
		resp->insertAscii(getName());
		break;
	case 46:
		resp->insertAscii(getType());
		break;
	case 47:
		resp->insertAscii(getClass1());
		break;
	case 48:
		resp->insertAscii(getClass2());
		break;
	case 49:
		resp->insertAscii(getClass3());
		break;
	case 50:
		resp->insertAscii(getClass4());
		break;
	case 51:
		resp->insertAscii(getClass5());
		break;
	case 52:
		resp->insertAscii(getClass6());
		break;
	case 53:
		resp->insertAscii(getClass7());
		break;
	case 54:
		resp->insertAscii(getAtt1());
		break;
	case 55:
		resp->insertAscii(getAtt2());
		break;
	case 56:
		resp->insertAscii(getAtt3());
		break;
	case 57:
		resp->insertAscii(getAtt4());
		break;
	case 58:
		resp->insertAscii(getAtt5());
		break;
	case 59:
		resp->insertAscii(getAtt6());
		break;
	case 60:
		resp->insertAscii(getAtt7());
		break;
	case 61:
		resp->insertAscii(getAtt8());
		break;
	case 62:
		resp->insertAscii(getAtt9());
		break;
	case 63:
		resp->insertAscii(getAtt10());
		break;
	case 64:
		resp->insertAscii(getAtt11());
		break;
	case 65:
		resp->insertSignedInt(getAtt1Stat());
		break;
	case 66:
		resp->insertSignedInt(getAtt2Stat());
		break;
	case 67:
		resp->insertSignedInt(getAtt3Stat());
		break;
	case 68:
		resp->insertSignedInt(getAtt4Stat());
		break;
	case 69:
		resp->insertSignedInt(getAtt5Stat());
		break;
	case 70:
		resp->insertSignedInt(getAtt6Stat());
		break;
	case 71:
		resp->insertSignedInt(getAtt7Stat());
		break;
	case 72:
		resp->insertSignedInt(getAtt8Stat());
		break;
	case 73:
		resp->insertSignedInt(getAtt9Stat());
		break;
	case 74:
		resp->insertSignedInt(getAtt10Stat());
		break;
	case 75:
		resp->insertSignedInt(getAtt11Stat());
		break;
	case 76:
		resp->insertSignedInt(getMaxType());
		break;
	case 77:
		resp->insertSignedInt(getMinType());
		break;
	case 78:
		resp->insertSignedInt(getMaxPool());
		break;
	case 79:
		resp->insertSignedInt(getMinPool());
		break;
	case 80:
		resp->insertAscii(getContainerName());
		break;
	case 81:
		toString();
		break;
	default:
		return NULL;
	}

	return resp;
}

void ResourceSpawnAdapter::addSpawnLocation(SpawnLocation* location) {
	return ((ResourceSpawnImplementation*) impl)->addSpawnLocation(location);
}

SpawnLocation* ResourceSpawnAdapter::removeSpawnLocation(unsigned int oid) {
	return ((ResourceSpawnImplementation*) impl)->removeSpawnLocation(oid);
}

SpawnLocation* ResourceSpawnAdapter::getSpawnLocation(int i) {
	return ((ResourceSpawnImplementation*) impl)->getSpawnLocation(i);
}

int ResourceSpawnAdapter::getSpawnLocationSize() {
	return ((ResourceSpawnImplementation*) impl)->getSpawnLocationSize();
}

void ResourceSpawnAdapter::setName(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setName(inString);
}

void ResourceSpawnAdapter::setClass1(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setClass1(inString);
}

void ResourceSpawnAdapter::setClass2(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setClass2(inString);
}

void ResourceSpawnAdapter::setClass3(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setClass3(inString);
}

void ResourceSpawnAdapter::setClass4(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setClass4(inString);
}

void ResourceSpawnAdapter::setClass5(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setClass5(inString);
}

void ResourceSpawnAdapter::setClass6(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setClass6(inString);
}

void ResourceSpawnAdapter::setClass7(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setClass7(inString);
}

void ResourceSpawnAdapter::setAtt1(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setAtt1(inString);
}

void ResourceSpawnAdapter::setAtt2(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setAtt2(inString);
}

void ResourceSpawnAdapter::setAtt3(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setAtt3(inString);
}

void ResourceSpawnAdapter::setAtt4(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setAtt4(inString);
}

void ResourceSpawnAdapter::setAtt5(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setAtt5(inString);
}

void ResourceSpawnAdapter::setAtt6(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setAtt6(inString);
}

void ResourceSpawnAdapter::setAtt7(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setAtt7(inString);
}

void ResourceSpawnAdapter::setAtt8(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setAtt8(inString);
}

void ResourceSpawnAdapter::setAtt9(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setAtt9(inString);
}

void ResourceSpawnAdapter::setAtt10(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setAtt10(inString);
}

void ResourceSpawnAdapter::setAtt11(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setAtt11(inString);
}

void ResourceSpawnAdapter::setAtt1Stat(int inInt) {
	return ((ResourceSpawnImplementation*) impl)->setAtt1Stat(inInt);
}

void ResourceSpawnAdapter::setAtt2Stat(int inInt) {
	return ((ResourceSpawnImplementation*) impl)->setAtt2Stat(inInt);
}

void ResourceSpawnAdapter::setAtt3Stat(int inInt) {
	return ((ResourceSpawnImplementation*) impl)->setAtt3Stat(inInt);
}

void ResourceSpawnAdapter::setAtt4Stat(int inInt) {
	return ((ResourceSpawnImplementation*) impl)->setAtt4Stat(inInt);
}

void ResourceSpawnAdapter::setAtt5Stat(int inInt) {
	return ((ResourceSpawnImplementation*) impl)->setAtt5Stat(inInt);
}

void ResourceSpawnAdapter::setAtt6Stat(int inInt) {
	return ((ResourceSpawnImplementation*) impl)->setAtt6Stat(inInt);
}

void ResourceSpawnAdapter::setAtt7Stat(int inInt) {
	return ((ResourceSpawnImplementation*) impl)->setAtt7Stat(inInt);
}

void ResourceSpawnAdapter::setAtt8Stat(int inInt) {
	return ((ResourceSpawnImplementation*) impl)->setAtt8Stat(inInt);
}

void ResourceSpawnAdapter::setAtt9Stat(int inInt) {
	return ((ResourceSpawnImplementation*) impl)->setAtt9Stat(inInt);
}

void ResourceSpawnAdapter::setAtt10Stat(int inInt) {
	return ((ResourceSpawnImplementation*) impl)->setAtt10Stat(inInt);
}

void ResourceSpawnAdapter::setAtt11Stat(int inInt) {
	return ((ResourceSpawnImplementation*) impl)->setAtt11Stat(inInt);
}

void ResourceSpawnAdapter::setMaxType(int inInt) {
	return ((ResourceSpawnImplementation*) impl)->setMaxType(inInt);
}

void ResourceSpawnAdapter::setMinType(int inInt) {
	return ((ResourceSpawnImplementation*) impl)->setMinType(inInt);
}

void ResourceSpawnAdapter::setMaxPool(int inInt) {
	return ((ResourceSpawnImplementation*) impl)->setMaxPool(inInt);
}

void ResourceSpawnAdapter::setMinPool(int inInt) {
	return ((ResourceSpawnImplementation*) impl)->setMinPool(inInt);
}

void ResourceSpawnAdapter::setContainerName(const String& inString) {
	return ((ResourceSpawnImplementation*) impl)->setContainerName(inString);
}

String& ResourceSpawnAdapter::getName() {
	return ((ResourceSpawnImplementation*) impl)->getName();
}

String& ResourceSpawnAdapter::getType() {
	return ((ResourceSpawnImplementation*) impl)->getType();
}

String& ResourceSpawnAdapter::getClass1() {
	return ((ResourceSpawnImplementation*) impl)->getClass1();
}

String& ResourceSpawnAdapter::getClass2() {
	return ((ResourceSpawnImplementation*) impl)->getClass2();
}

String& ResourceSpawnAdapter::getClass3() {
	return ((ResourceSpawnImplementation*) impl)->getClass3();
}

String& ResourceSpawnAdapter::getClass4() {
	return ((ResourceSpawnImplementation*) impl)->getClass4();
}

String& ResourceSpawnAdapter::getClass5() {
	return ((ResourceSpawnImplementation*) impl)->getClass5();
}

String& ResourceSpawnAdapter::getClass6() {
	return ((ResourceSpawnImplementation*) impl)->getClass6();
}

String& ResourceSpawnAdapter::getClass7() {
	return ((ResourceSpawnImplementation*) impl)->getClass7();
}

String& ResourceSpawnAdapter::getAtt1() {
	return ((ResourceSpawnImplementation*) impl)->getAtt1();
}

String& ResourceSpawnAdapter::getAtt2() {
	return ((ResourceSpawnImplementation*) impl)->getAtt2();
}

String& ResourceSpawnAdapter::getAtt3() {
	return ((ResourceSpawnImplementation*) impl)->getAtt3();
}

String& ResourceSpawnAdapter::getAtt4() {
	return ((ResourceSpawnImplementation*) impl)->getAtt4();
}

String& ResourceSpawnAdapter::getAtt5() {
	return ((ResourceSpawnImplementation*) impl)->getAtt5();
}

String& ResourceSpawnAdapter::getAtt6() {
	return ((ResourceSpawnImplementation*) impl)->getAtt6();
}

String& ResourceSpawnAdapter::getAtt7() {
	return ((ResourceSpawnImplementation*) impl)->getAtt7();
}

String& ResourceSpawnAdapter::getAtt8() {
	return ((ResourceSpawnImplementation*) impl)->getAtt8();
}

String& ResourceSpawnAdapter::getAtt9() {
	return ((ResourceSpawnImplementation*) impl)->getAtt9();
}

String& ResourceSpawnAdapter::getAtt10() {
	return ((ResourceSpawnImplementation*) impl)->getAtt10();
}

String& ResourceSpawnAdapter::getAtt11() {
	return ((ResourceSpawnImplementation*) impl)->getAtt11();
}

int ResourceSpawnAdapter::getAtt1Stat() {
	return ((ResourceSpawnImplementation*) impl)->getAtt1Stat();
}

int ResourceSpawnAdapter::getAtt2Stat() {
	return ((ResourceSpawnImplementation*) impl)->getAtt2Stat();
}

int ResourceSpawnAdapter::getAtt3Stat() {
	return ((ResourceSpawnImplementation*) impl)->getAtt3Stat();
}

int ResourceSpawnAdapter::getAtt4Stat() {
	return ((ResourceSpawnImplementation*) impl)->getAtt4Stat();
}

int ResourceSpawnAdapter::getAtt5Stat() {
	return ((ResourceSpawnImplementation*) impl)->getAtt5Stat();
}

int ResourceSpawnAdapter::getAtt6Stat() {
	return ((ResourceSpawnImplementation*) impl)->getAtt6Stat();
}

int ResourceSpawnAdapter::getAtt7Stat() {
	return ((ResourceSpawnImplementation*) impl)->getAtt7Stat();
}

int ResourceSpawnAdapter::getAtt8Stat() {
	return ((ResourceSpawnImplementation*) impl)->getAtt8Stat();
}

int ResourceSpawnAdapter::getAtt9Stat() {
	return ((ResourceSpawnImplementation*) impl)->getAtt9Stat();
}

int ResourceSpawnAdapter::getAtt10Stat() {
	return ((ResourceSpawnImplementation*) impl)->getAtt10Stat();
}

int ResourceSpawnAdapter::getAtt11Stat() {
	return ((ResourceSpawnImplementation*) impl)->getAtt11Stat();
}

int ResourceSpawnAdapter::getMaxType() {
	return ((ResourceSpawnImplementation*) impl)->getMaxType();
}

int ResourceSpawnAdapter::getMinType() {
	return ((ResourceSpawnImplementation*) impl)->getMinType();
}

int ResourceSpawnAdapter::getMaxPool() {
	return ((ResourceSpawnImplementation*) impl)->getMaxPool();
}

int ResourceSpawnAdapter::getMinPool() {
	return ((ResourceSpawnImplementation*) impl)->getMinPool();
}

String& ResourceSpawnAdapter::getContainerName() {
	return ((ResourceSpawnImplementation*) impl)->getContainerName();
}

void ResourceSpawnAdapter::toString() {
	return ((ResourceSpawnImplementation*) impl)->toString();
}

/*
 *	ResourceSpawnHelper
 */

ResourceSpawnHelper* ResourceSpawnHelper::staticInitializer = ResourceSpawnHelper::instance();

ResourceSpawnHelper::ResourceSpawnHelper() {
	className = "ResourceSpawn";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ResourceSpawnHelper::finalizeHelper() {
	ResourceSpawnHelper::finalize();
}

DistributedObject* ResourceSpawnHelper::instantiateObject() {
	return new ResourceSpawn(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ResourceSpawnHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ResourceSpawnAdapter((ResourceSpawnImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	ResourceSpawnServant
 */

ResourceSpawnServant::ResourceSpawnServant() : SceneObjectImplementation() {
	_classHelper = ResourceSpawnHelper::instance();
}

ResourceSpawnServant::~ResourceSpawnServant() {
}

void ResourceSpawnServant::_setStub(DistributedObjectStub* stub) {
	_this = (ResourceSpawn*) stub;
	SceneObjectServant::_setStub(stub);
}

DistributedObjectStub* ResourceSpawnServant::_getStub() {
	return _this;
}

