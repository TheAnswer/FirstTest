/*
 *	server/zone/managers/resource/ResourceManager.cpp generated by engine3 IDL compiler 0.55
 */

#include "ResourceManager.h"

#include "ResourceManagerImplementation.h"

#include "../../objects/player/Player.h"

#include "../../objects/tangible/resource/ResourceContainer.h"

#include "../../objects/creature/Creature.h"

#include "ResourceList.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/ZoneProcessServerImplementation.h"

#include "../../objects/player/sui/listbox/SuiListBox.h"

#include "../../objects/player/sui/listbox/SuiListBoxVector.h"

/*
 *	ResourceManagerStub
 */

ResourceManager::ResourceManager(ZoneServer* server, ZoneProcessServerImplementation* processor) {
	_impl = new ResourceManagerImplementation(server, processor);
	_impl->_setStub(this);
}

ResourceManager::ResourceManager(DummyConstructorParameter* param) {
	_impl = NULL;
}

ResourceManager::~ResourceManager() {
}

void ResourceManager::theShift() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((ResourceManagerImplementation*) _impl)->theShift();
}

void ResourceManager::stop() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		((ResourceManagerImplementation*) _impl)->stop();
}

void ResourceManager::clearResources() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		method.executeWithVoidReturn();
	} else
		((ResourceManagerImplementation*) _impl)->clearResources();
}

bool ResourceManager::checkResource(Player* player, String& resourcename, int SurveyToolType) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(player);
		method.addAsciiParameter(resourcename);
		method.addSignedIntParameter(SurveyToolType);

		return method.executeWithBooleanReturn();
	} else
		return ((ResourceManagerImplementation*) _impl)->checkResource(player, resourcename, SurveyToolType);
}

void ResourceManager::sendSurveyMessage(Player* player, String& resourcename) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addObjectParameter(player);
		method.addAsciiParameter(resourcename);

		method.executeWithVoidReturn();
	} else
		((ResourceManagerImplementation*) _impl)->sendSurveyMessage(player, resourcename);
}

void ResourceManager::sendSampleMessage(Player* player, String& resourcename) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addObjectParameter(player);
		method.addAsciiParameter(resourcename);

		method.executeWithVoidReturn();
	} else
		((ResourceManagerImplementation*) _impl)->sendSampleMessage(player, resourcename);
}

void ResourceManager::setResourceData(ResourceContainer* resContainer, bool lock) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addObjectParameter(resContainer);
		method.addBooleanParameter(lock);

		method.executeWithVoidReturn();
	} else
		((ResourceManagerImplementation*) _impl)->setResourceData(resContainer, lock);
}

bool ResourceManager::sendSurveyResources(Player* player, int SurveyToolType) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addObjectParameter(player);
		method.addSignedIntParameter(SurveyToolType);

		return method.executeWithBooleanReturn();
	} else
		return ((ResourceManagerImplementation*) _impl)->sendSurveyResources(player, SurveyToolType);
}

void ResourceManager::getClassSeven(const String& str, String& clas) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addAsciiParameter(str);
		method.addAsciiParameter(clas);

		method.executeWithVoidReturn();
	} else
		((ResourceManagerImplementation*) _impl)->getClassSeven(str, clas);
}

void ResourceManager::getResourceContainerName(const String& str, String& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addAsciiParameter(str);
		method.addAsciiParameter(name);

		method.executeWithVoidReturn();
	} else
		((ResourceManagerImplementation*) _impl)->getResourceContainerName(str, name);
}

void ResourceManager::printResource(String& resname) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);
		method.addAsciiParameter(resname);

		method.executeWithVoidReturn();
	} else
		((ResourceManagerImplementation*) _impl)->printResource(resname);
}

void ResourceManager::harvestOrganics(Player* player, Creature* creature, int type) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);
		method.addObjectParameter(player);
		method.addObjectParameter(creature);
		method.addSignedIntParameter(type);

		method.executeWithVoidReturn();
	} else
		((ResourceManagerImplementation*) _impl)->harvestOrganics(player, creature, type);
}

ResourceList* ResourceManager::getResourceListAtLocation(int zone, float x, float y, int type) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);
		method.addSignedIntParameter(zone);
		method.addFloatParameter(x);
		method.addFloatParameter(y);
		method.addSignedIntParameter(type);

		return (ResourceList*) method.executeWithObjectReturn();
	} else
		return ((ResourceManagerImplementation*) _impl)->getResourceListAtLocation(zone, x, y, type);
}

String& ResourceManager::getResourceNameByID(unsigned long long rID) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);
		method.addUnsignedLongParameter(rID);

		method.executeWithAsciiReturn(_return_getResourceNameByID);
		return _return_getResourceNameByID;
	} else
		return ((ResourceManagerImplementation*) _impl)->getResourceNameByID(rID);
}

void ResourceManager::generateSUI(Player* player, SuiListBox* sui) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);
		method.addObjectParameter(player);
		method.addObjectParameter(sui);

		method.executeWithVoidReturn();
	} else
		((ResourceManagerImplementation*) _impl)->generateSUI(player, sui);
}

bool ResourceManager::useResourceDeed(Player* player, String& resourceName, int resourceQuantity) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);
		method.addObjectParameter(player);
		method.addAsciiParameter(resourceName);
		method.addSignedIntParameter(resourceQuantity);

		return method.executeWithBooleanReturn();
	} else
		return ((ResourceManagerImplementation*) _impl)->useResourceDeed(player, resourceName, resourceQuantity);
}

bool ResourceManager::containsResource(String& resourceName) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);
		method.addAsciiParameter(resourceName);

		return method.executeWithBooleanReturn();
	} else
		return ((ResourceManagerImplementation*) _impl)->containsResource(resourceName);
}

void ResourceManager::giveForageResource(Player* player, float foragex, float foragey, int forageplanet) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);
		method.addObjectParameter(player);
		method.addFloatParameter(foragex);
		method.addFloatParameter(foragey);
		method.addSignedIntParameter(forageplanet);

		method.executeWithVoidReturn();
	} else
		((ResourceManagerImplementation*) _impl)->giveForageResource(player, foragex, foragey, forageplanet);
}

/*
 *	ResourceManagerAdapter
 */

ResourceManagerAdapter::ResourceManagerAdapter(ResourceManagerImplementation* obj) : DistributedObjectAdapter((DistributedObjectServant*) obj) {
}

Packet* ResourceManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		theShift();
		break;
	case 7:
		stop();
		break;
	case 8:
		clearResources();
		break;
	case 9:
		resp->insertBoolean(checkResource((Player*) inv->getObjectParameter(), inv->getAsciiParameter(_param1_checkResource__Player_String_int_), inv->getSignedIntParameter()));
		break;
	case 10:
		sendSurveyMessage((Player*) inv->getObjectParameter(), inv->getAsciiParameter(_param1_sendSurveyMessage__Player_String_));
		break;
	case 11:
		sendSampleMessage((Player*) inv->getObjectParameter(), inv->getAsciiParameter(_param1_sendSampleMessage__Player_String_));
		break;
	case 12:
		setResourceData((ResourceContainer*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 13:
		resp->insertBoolean(sendSurveyResources((Player*) inv->getObjectParameter(), inv->getSignedIntParameter()));
		break;
	case 14:
		getClassSeven(inv->getAsciiParameter(_param0_getClassSeven__String_String_), inv->getAsciiParameter(_param1_getClassSeven__String_String_));
		break;
	case 15:
		getResourceContainerName(inv->getAsciiParameter(_param0_getResourceContainerName__String_String_), inv->getAsciiParameter(_param1_getResourceContainerName__String_String_));
		break;
	case 16:
		printResource(inv->getAsciiParameter(_param0_printResource__String_));
		break;
	case 17:
		harvestOrganics((Player*) inv->getObjectParameter(), (Creature*) inv->getObjectParameter(), inv->getSignedIntParameter());
		break;
	case 18:
		resp->insertLong(getResourceListAtLocation(inv->getSignedIntParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getSignedIntParameter())->_getObjectID());
		break;
	case 19:
		resp->insertAscii(getResourceNameByID(inv->getUnsignedLongParameter()));
		break;
	case 20:
		generateSUI((Player*) inv->getObjectParameter(), (SuiListBox*) inv->getObjectParameter());
		break;
	case 21:
		resp->insertBoolean(useResourceDeed((Player*) inv->getObjectParameter(), inv->getAsciiParameter(_param1_useResourceDeed__Player_String_int_), inv->getSignedIntParameter()));
		break;
	case 22:
		resp->insertBoolean(containsResource(inv->getAsciiParameter(_param0_containsResource__String_)));
		break;
	case 23:
		giveForageResource((Player*) inv->getObjectParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getSignedIntParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ResourceManagerAdapter::theShift() {
	return ((ResourceManagerImplementation*) impl)->theShift();
}

void ResourceManagerAdapter::stop() {
	return ((ResourceManagerImplementation*) impl)->stop();
}

void ResourceManagerAdapter::clearResources() {
	return ((ResourceManagerImplementation*) impl)->clearResources();
}

bool ResourceManagerAdapter::checkResource(Player* player, String& resourcename, int SurveyToolType) {
	return ((ResourceManagerImplementation*) impl)->checkResource(player, resourcename, SurveyToolType);
}

void ResourceManagerAdapter::sendSurveyMessage(Player* player, String& resourcename) {
	return ((ResourceManagerImplementation*) impl)->sendSurveyMessage(player, resourcename);
}

void ResourceManagerAdapter::sendSampleMessage(Player* player, String& resourcename) {
	return ((ResourceManagerImplementation*) impl)->sendSampleMessage(player, resourcename);
}

void ResourceManagerAdapter::setResourceData(ResourceContainer* resContainer, bool lock) {
	return ((ResourceManagerImplementation*) impl)->setResourceData(resContainer, lock);
}

bool ResourceManagerAdapter::sendSurveyResources(Player* player, int SurveyToolType) {
	return ((ResourceManagerImplementation*) impl)->sendSurveyResources(player, SurveyToolType);
}

void ResourceManagerAdapter::getClassSeven(const String& str, String& clas) {
	return ((ResourceManagerImplementation*) impl)->getClassSeven(str, clas);
}

void ResourceManagerAdapter::getResourceContainerName(const String& str, String& name) {
	return ((ResourceManagerImplementation*) impl)->getResourceContainerName(str, name);
}

void ResourceManagerAdapter::printResource(String& resname) {
	return ((ResourceManagerImplementation*) impl)->printResource(resname);
}

void ResourceManagerAdapter::harvestOrganics(Player* player, Creature* creature, int type) {
	return ((ResourceManagerImplementation*) impl)->harvestOrganics(player, creature, type);
}

ResourceList* ResourceManagerAdapter::getResourceListAtLocation(int zone, float x, float y, int type) {
	return ((ResourceManagerImplementation*) impl)->getResourceListAtLocation(zone, x, y, type);
}

String& ResourceManagerAdapter::getResourceNameByID(unsigned long long rID) {
	return ((ResourceManagerImplementation*) impl)->getResourceNameByID(rID);
}

void ResourceManagerAdapter::generateSUI(Player* player, SuiListBox* sui) {
	return ((ResourceManagerImplementation*) impl)->generateSUI(player, sui);
}

bool ResourceManagerAdapter::useResourceDeed(Player* player, String& resourceName, int resourceQuantity) {
	return ((ResourceManagerImplementation*) impl)->useResourceDeed(player, resourceName, resourceQuantity);
}

bool ResourceManagerAdapter::containsResource(String& resourceName) {
	return ((ResourceManagerImplementation*) impl)->containsResource(resourceName);
}

void ResourceManagerAdapter::giveForageResource(Player* player, float foragex, float foragey, int forageplanet) {
	return ((ResourceManagerImplementation*) impl)->giveForageResource(player, foragex, foragey, forageplanet);
}

/*
 *	ResourceManagerHelper
 */

ResourceManagerHelper* ResourceManagerHelper::staticInitializer = ResourceManagerHelper::instance();

ResourceManagerHelper::ResourceManagerHelper() {
	className = "ResourceManager";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ResourceManagerHelper::finalizeHelper() {
	ResourceManagerHelper::finalize();
}

DistributedObject* ResourceManagerHelper::instantiateObject() {
	return new ResourceManager(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ResourceManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ResourceManagerAdapter((ResourceManagerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	ResourceManagerServant
 */

ResourceManagerServant::ResourceManagerServant() {
	_classHelper = ResourceManagerHelper::instance();
}

ResourceManagerServant::~ResourceManagerServant() {
}

void ResourceManagerServant::_setStub(DistributedObjectStub* stub) {
	_this = (ResourceManager*) stub;
}

DistributedObjectStub* ResourceManagerServant::_getStub() {
	return _this;
}

