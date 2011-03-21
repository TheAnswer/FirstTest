/*
 *	server/zone/objects/tangible/terminal/bazaar/AuctionItem.h generated by engine3 IDL compiler 0.60
 */

#ifndef AUCTIONITEM_H_
#define AUCTIONITEM_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace bazaar {

class BazaarTerminal;

} // namespace bazaar
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::bazaar;

#include "server/zone/objects/scene/variables/StringId.h"

#include "system/util/VectorMap.h"

#include "engine/core/ManagedObject.h"

#include "system/lang/StringBuffer.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace bazaar {

class AuctionItem : public ManagedObject {
public:
	AuctionItem(unsigned long long objectid);

	void setLocation(const String& planet, const String& header, unsigned long long vendorid, int x, int z, bool vendor);

	void setItemName(const String& name);

	void setItemDescription(const String& descr);

	void setPrice(int newPrice);

	void setAuctionedItemObjectID(unsigned long long objectID);

	void setItemType(int type);

	void setOwnerID(unsigned long long ownerObjectID);

	void setBidderName(const String& name);

	void setPlanet(unsigned short planetid);

	void setOwnerName(const String& name);

	void setBazaarTerminal(BazaarTerminal* term);

	void setAuction(bool isAuction);

	void setSold(bool isSold);

	void setRemovedByOwner(bool isRemovedByOwner);

	void setExpireTime(int time);

	void setBuyerID(unsigned long long id);

	BazaarTerminal* getBazaarTerminal();

	bool isSold();

	bool isAuction();

	bool isRemovedByOwner();

	unsigned long long getAuctionedItemObjectID();

	unsigned long long getOwnerID();

	String getTerminalTitle();

	String getOwnerName();

	String getItemName();

	int getExpireTime();

	int getPrice();

	int getItemType();

	unsigned long long getBuyerID();

	String getBidderName();

	String getItemDescription();

	String getLocation();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	AuctionItem(DummyConstructorParameter* param);

	virtual ~AuctionItem();

	String _return_getBidderName;
	String _return_getItemDescription;
	String _return_getItemName;
	String _return_getLocation;
	String _return_getOwnerName;
	String _return_getTerminalTitle;

	friend class AuctionItemHelper;
};

} // namespace bazaar
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::bazaar;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace bazaar {

class AuctionItemImplementation : public ManagedObjectImplementation {
protected:
	ManagedWeakReference<BazaarTerminal* > bazaarTerminal;

	unsigned long long auctionedItemObjectID;

	int itemType;

	unsigned long long ownerID;

	String ownerName;

	String bidderName;

	unsigned short planet;

	String region;

	String location;

	String terminalTitle;

	String itemName;

	String itemDescription;

	int price;

	bool auction;

	bool sold;

	bool ownerRemove;

	unsigned long long buyerID;

	unsigned int expireTime;

	int remainingTime;

	bool updated;

public:
	AuctionItemImplementation(unsigned long long objectid);

	AuctionItemImplementation(DummyConstructorParameter* param);

	void setLocation(const String& planet, const String& header, unsigned long long vendorid, int x, int z, bool vendor);

	void setItemName(const String& name);

	void setItemDescription(const String& descr);

	void setPrice(int newPrice);

	void setAuctionedItemObjectID(unsigned long long objectID);

	void setItemType(int type);

	void setOwnerID(unsigned long long ownerObjectID);

	void setBidderName(const String& name);

	void setPlanet(unsigned short planetid);

	void setOwnerName(const String& name);

	void setBazaarTerminal(BazaarTerminal* term);

	void setAuction(bool isAuction);

	void setSold(bool isSold);

	void setRemovedByOwner(bool isRemovedByOwner);

	void setExpireTime(int time);

	void setBuyerID(unsigned long long id);

	BazaarTerminal* getBazaarTerminal();

	bool isSold();

	bool isAuction();

	bool isRemovedByOwner();

	unsigned long long getAuctionedItemObjectID();

	unsigned long long getOwnerID();

	String getTerminalTitle();

	String getOwnerName();

	String getItemName();

	int getExpireTime();

	int getPrice();

	int getItemType();

	unsigned long long getBuyerID();

	String getBidderName();

	String getItemDescription();

	String getLocation();

	AuctionItem* _this;

	operator const AuctionItem*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~AuctionItemImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class AuctionItem;
};

class AuctionItemAdapter : public ManagedObjectAdapter {
public:
	AuctionItemAdapter(AuctionItemImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void setLocation(const String& planet, const String& header, unsigned long long vendorid, int x, int z, bool vendor);

	void setItemName(const String& name);

	void setItemDescription(const String& descr);

	void setPrice(int newPrice);

	void setAuctionedItemObjectID(unsigned long long objectID);

	void setItemType(int type);

	void setOwnerID(unsigned long long ownerObjectID);

	void setBidderName(const String& name);

	void setOwnerName(const String& name);

	void setBazaarTerminal(BazaarTerminal* term);

	void setAuction(bool isAuction);

	void setSold(bool isSold);

	void setRemovedByOwner(bool isRemovedByOwner);

	void setExpireTime(int time);

	void setBuyerID(unsigned long long id);

	BazaarTerminal* getBazaarTerminal();

	bool isSold();

	bool isAuction();

	bool isRemovedByOwner();

	unsigned long long getAuctionedItemObjectID();

	unsigned long long getOwnerID();

	String getTerminalTitle();

	String getOwnerName();

	String getItemName();

	int getExpireTime();

	int getPrice();

	int getItemType();

	unsigned long long getBuyerID();

	String getBidderName();

	String getItemDescription();

	String getLocation();

protected:
	String _param0_setLocation__String_String_long_int_int_bool_;
	String _param1_setLocation__String_String_long_int_int_bool_;
	String _param0_setItemName__String_;
	String _param0_setItemDescription__String_;
	String _param0_setBidderName__String_;
	String _param0_setOwnerName__String_;
};

class AuctionItemHelper : public DistributedObjectClassHelper, public Singleton<AuctionItemHelper> {
	static AuctionItemHelper* staticInitializer;

public:
	AuctionItemHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<AuctionItemHelper>;
};

} // namespace bazaar
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::bazaar;

#endif /*AUCTIONITEM_H_*/