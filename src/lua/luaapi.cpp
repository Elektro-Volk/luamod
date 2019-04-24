#include <extdll.h>
#include <meta_api.h>
#include "luai.h"
#include "lu_offset.h"
#include "lu_engfuncs.hpp"

void loadLuaApi(lua_State *L)
{
    lua_createtable(L, 0, 1);
    lua_setglobal(L, "engine_events");

    luaL_openlibs(L);
    lu_offset::init_api(L);
    lu_engfuncs::init_api(L);
}
