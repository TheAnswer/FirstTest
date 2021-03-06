/*
 *	server/zone/objects/tangible/terminal/Terminal.h generated by engine3 IDL compiler 0.55
 */

#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/service/Message.h"

class Player;

class TangibleObject;

#include "../TangibleObject.h"

class Terminal : public TangibleObject {
public:
	Terminal(unsigned int objCRC, unsigned long long oid, const UnicodeString& n, const String& tempn, float x, float z, float y, unsigned char terminaltype);

	int useObject(Player* player);

	unsigned char getTerminalType();

	bool isTravelTerminal();

	bool isGuildTerminal();

	bool isMissionTerminal();

	bool isCloningTerminal();

	bool isInsuranceTerminal();

	bool isBazaarTerminal();

	bool isBankTerminal();

	bool isStartingLocationTerminal();

	bool isPlayerStructureTerminal();

protected:
	Terminal(DummyConstructorParameter* param);

	virtual ~Terminal();

	friend class TerminalHelper;
};

class TerminalImplementation;

class TerminalAdapter : public TangibleObjectAdapter {
public:
	TerminalAdapter(TerminalImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int useObject(Player* player);

	unsigned char getTerminalType();

	bool isTravelTerminal();

	bool isGuildTerminal();

	bool isMissionTerminal();

	bool isCloningTerminal();

	bool isInsuranceTerminal();

	bool isBazaarTerminal();

	bool isBankTerminal();

	bool isStartingLocationTerminal();

	bool isPlayerStructureTerminal();

};

class TerminalHelper : public DistributedObjectClassHelper, public Singleton<TerminalHelper> {
	static TerminalHelper* staticInitializer;

public:
	TerminalHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<TerminalHelper>;
};

#include "../TangibleObjectImplementation.h"

class TerminalServant : public TangibleObjectImplementation {
public:
	Terminal* _this;

public:
	TerminalServant(unsigned long long oid, int tp);
	virtual ~TerminalServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*TERMINAL_H_*/
