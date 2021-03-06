/*
 *	server/zone/objects/tangible/ticketcollector/TicketCollector.h generated by engine3 IDL compiler 0.55
 */

#ifndef TICKETCOLLECTOR_H_
#define TICKETCOLLECTOR_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/service/Message.h"

class Player;

class ShuttleCreature;

class TangibleObject;

class Ticket;

#include "../TangibleObject.h"

class TicketCollector : public TangibleObject {
public:
	TicketCollector(ShuttleCreature* shutle, unsigned long long oid, const UnicodeString& n, const String& tempn, float x, float z, float y);

	int useObject(Player* player);

	void useTicket(Player* player, Ticket* ticket);

protected:
	TicketCollector(DummyConstructorParameter* param);

	virtual ~TicketCollector();

	friend class TicketCollectorHelper;
};

class TicketCollectorImplementation;

class TicketCollectorAdapter : public TangibleObjectAdapter {
public:
	TicketCollectorAdapter(TicketCollectorImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int useObject(Player* player);

	void useTicket(Player* player, Ticket* ticket);

};

class TicketCollectorHelper : public DistributedObjectClassHelper, public Singleton<TicketCollectorHelper> {
	static TicketCollectorHelper* staticInitializer;

public:
	TicketCollectorHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<TicketCollectorHelper>;
};

#include "../TangibleObjectImplementation.h"

class TicketCollectorServant : public TangibleObjectImplementation {
public:
	TicketCollector* _this;

public:
	TicketCollectorServant(unsigned long long oid, int tp);
	virtual ~TicketCollectorServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*TICKETCOLLECTOR_H_*/
