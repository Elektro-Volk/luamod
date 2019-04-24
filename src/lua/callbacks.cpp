#include "callbacks.h"
#include "lua/CLuaWorker.hpp"

void pfnMessageBegin(int msg_dest, int msg_type, const float *pOrigin, edict_t *ed)
{
    lua_State* L = g_luaworker->getToEvent("pfnMessageBegin");
    if (!L) return;

    lua_pushinteger(L, msg_dest);
    lua_pushinteger(L, msg_type);
    lua_pushlightuserdata(L, NULL);//TODO //const_cast<void*>(pOrigin));
    lua_pushlightuserdata(L, ed);
    g_luaworker->safeCall(L, 4, 0);
}

void pfnMessageEnd()
{
    lua_State* L = g_luaworker->getToEvent("pfnMessageEnd");
    if (!L) return;
    g_luaworker->safeCall(L, 0, 0);
}

void pfnWriteByte(int iValue)
{
    lua_State* L = g_luaworker->getToEvent("pfnWriteByte");
    if (!L) return;

    lua_pushinteger(L, iValue);
    g_luaworker->safeCall(L, 1, 0);
}

void pfnWriteChar(int iValue)
{
    lua_State* L = g_luaworker->getToEvent("pfnWriteChar");
    if (!L) return;

    lua_pushinteger(L, iValue);
    g_luaworker->safeCall(L, 1, 0);
}

void pfnWriteShort(int iValue)
{
    lua_State* L = g_luaworker->getToEvent("pfnWriteShort");
    if (!L) return;

    lua_pushinteger(L, iValue);
    g_luaworker->safeCall(L, 1, 0);
}

void pfnWriteLong(int iValue)
{
    lua_State* L = g_luaworker->getToEvent("pfnWriteLong");
    if (!L) return;

    lua_pushinteger(L, iValue);
    g_luaworker->safeCall(L, 1, 0);
}

void pfnWriteAngle(float fValue)
{
    lua_State* L = g_luaworker->getToEvent("pfnWriteAngle");
    if (!L) return;

    lua_pushnumber(L, fValue);
    g_luaworker->safeCall(L, 1, 0);
}

void pfnWriteCoord(float fValue)
{
    lua_State* L = g_luaworker->getToEvent("pfnWriteCoord");
    if (!L) return;

    lua_pushnumber(L, fValue);
    g_luaworker->safeCall(L, 1, 0);
}

void pfnWriteString(const char* sValue)
{
    lua_State* L = g_luaworker->getToEvent("pfnWriteString");
    if (!L) return;

    lua_pushstring(L, sValue);
    g_luaworker->safeCall(L, 1, 0);
}

void pfnWriteEntity(int iValue)
{
    lua_State* L = g_luaworker->getToEvent("pfnWriteEntity");
    if (!L) return;

    lua_pushinteger(L, iValue);
    g_luaworker->safeCall(L, 1, 0);
}

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
