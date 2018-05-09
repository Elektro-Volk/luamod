#include <extdll.h>
#include <meta_api.h>
#include "plugins.h"
#include "lc_edict.h"
#include "lu_output.h"

int lPrint (lua_State *L);
int lLoad (lua_State *L);
int lSubscribe (lua_State *L);
void loadLuaApi(lua_State *L)
{
    luaL_openlibs(L);
    lc_edict::init_api(L);
    lu_output::init_api(L);
    lua_register(L, "print", lPrint);
    lua_register(L, "load", lLoad);
    lua_register(L, "subscribe", lSubscribe);
}
