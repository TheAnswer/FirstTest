/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

#include "LoginClient.h"
#include "LoginServer.h"

LoginServer::LoginServer(ConfigManager* configMan) : DatagramServiceThread("LoginServer") {
	//setLockName("LoginServerLock");

	phand = NULL;
	phandler = NULL;

	processors = NULL;
	procThreadCount = 0;

	configManager = configMan;

	setLogging(false);
}

LoginServer::~LoginServer() {
	if (phand != NULL) {
		delete phand;
		phand = NULL;
	}

	if (phandler != NULL) {
		delete phandler;
		phandler = NULL;
	}

	if (processors != NULL) {
		free(processors);
		processors = NULL;
	}
}

void LoginServer::init() {
	phand = new BasePacketHandler("LoginServer", &messageQueue);
	phand->setLogging(false);

	phandler = new LoginPacketHandler("LoginPacketHandler", this, configManager);
	phandler->setLogging(false);

	scheduler->setLogging(false);

	procThreadCount = 1;

	processors = (LoginMessageProcessorThread**) malloc(procThreadCount * sizeof(LoginMessageProcessorThread*));

	for (int i = 0; i < procThreadCount; ++i) {
		StringBuffer name;
		name << "LoginProcessor" << i;

		processors[i] = new LoginMessageProcessorThread(name.toString(), phandler);
	}

	return;
}

void LoginServer::run() {
	scheduler->start();

	for (int i = 0; i < procThreadCount; ++i) {
		LoginMessageProcessorThread* processor = processors[i];
		processor->start(this);
	}

	// recieve messages
	receiveMessages();

	shutdown();
}

void LoginServer::shutdown() {
	// shutting down
	for (int i = 0; i < procThreadCount; ++i) {
		LoginMessageProcessorThread* processor = processors[i];

		flushMessages();
		processor->stop();

		delete processor;
	}

	scheduler->stop();
}

LoginClient* LoginServer::createConnection(Socket* sock, SocketAddress& addr) {
	LoginClient* client = new LoginClient(this, sock, addr);

	info("client connected from \'" + client->getAddress() + "\'");

	return client;
}

void LoginServer::handleMessage(ServiceClient* client, Packet* message) {
	LoginClient* lclient = (LoginClient*) client;

	try {
		if (lclient->isAvailable())
			phand->handlePacket(lclient, message);

	} catch (PacketIndexOutOfBoundsException& e) {
		System::out << e.getMessage();

		error("incorrect packet - " + message->toString());
	} catch (DatabaseException& e) {
		error(e.getMessage());
	} catch (ArrayIndexOutOfBoundsException& e) {
		error(e.getMessage());
	} catch (...) {
		System::out << "[LoginServer] unreported Exception caught\n";
	}
}

bool LoginServer::handleError(ServiceClient* client, Exception& e) {
	LoginClient* lclient = (LoginClient*) client;
	lclient->setError();

	lclient->disconnect();

	return true;
}

void LoginServer::printInfo() {
	lock();

	StringBuffer msg;
	msg << "MessageQueue - size = " << messageQueue.size();
	info(msg, true);

	StringBuffer msg2;
	msg2 << "Scheduler - size = " << scheduler->getQueueSize();
	info(msg2, true);

	unlock();
}
