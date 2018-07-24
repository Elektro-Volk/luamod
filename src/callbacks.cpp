#include "callbacks.h"
#include "lua/CLuaWorker.hpp"

//Event *eventClientPutInServer = addEvent("engine_client_connected");
void pfnClientPutInServer(edict_t* ed)
{
  //ALERT(at_console, "[LM] Client eventClientPutInServer\n");
  /*(auto states = eventClientPutInServer->states;
  for (int i = 0; i < states.size(); i++) {
    lua_getfield(states[i], LUA_REGISTRYINDEX, "engine_client_connected");
    lc_edict::push_edict(states[i], ed);
    lua_pcall(states[i], 1, 0, 0);
}*/
  //RETURN_META_VALUE(MRES_IGNORED, 0);
}

void pfnClientCommand(edict_t* ed)
{
    lua_State* L = g_luaworker->getToEvent("pfnClientCommand");
    if (!L) return;

    lua_pushlightuserdata(L, ed);
    // Push table
    lua_newtable(L);
    for (int i = 0; i < CMD_ARGC(); i++) {
    	lua_pushnumber(L, i+1); // Key
    	lua_pushstring(L, CMD_ARGV(i)); // Value
    	lua_settable(L, -3);
    }
    lua_pushstring(L, CMD_ARGS());
    g_luaworker->safeCall(L, 3, 0);
}


//Event *eventServerCommand = addEvent("engine_server_command");
void pfnServerCommand(const char* str)
{
  /*ALERT(at_console, "[LM] Server command %s\n", str);
  auto states = eventServerCommand->states;
  for (int i = 0; i < states.size(); i++) {
    lua_getglobal(states[i], "event");
    lua_pcall(states[i], 0, 0, 0);
}*/
  //RETURN_META_VALUE(MRES_IGNORED, 0);
}
