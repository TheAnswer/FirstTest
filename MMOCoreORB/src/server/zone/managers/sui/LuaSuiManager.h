/*
 * LuaSuiManager.h
 *
 *  Created on: Jan 28, 2012
 *      Author: xyborn
 */

#ifndef LUASUIMANAGER_H_
#define LUASUIMANAGER_H_

#include "engine/engine.h"

namespace server {
namespace zone {
namespace managers {
namespace sui {
	class SuiManager;

	class LuaSuiManager {
	public:
		static const char className[];
		static Luna<LuaSuiManager>::RegType Register[];

		LuaSuiManager(lua_State *L);
		~LuaSuiManager();

		int sendKeypadSui(lua_State* L);

	private:
		Reference<SuiManager*> realObject;
	};
}
}
}
}

using namespace server::zone::managers::sui;

#endif /* LUASUIMANAGER_H_ */