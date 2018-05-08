#include "callbacks.h"
#include "events.h"

Event *eventClientPutInServer = addEvent("engine_client_connected");
void pfnClientPutInServer(edict_t* ed)
{
  ALERT(at_console, "[LM] Client eventClientPutInServer\n");
  auto states = eventClientPutInServer->states;
  for (int i = 0; i < states.size(); i++) {
    lua_getfield(states[i], LUA_REGISTRYINDEX, "engine_client_connected");
    lua_pcall(states[i], 0, 0, 0);
  }
  //RETURN_META_VALUE(MRES_IGNORED, 0);
}

Event *eventClientCommand = addEvent("engine_client_command");
void pfnClientCommand(edict_t* ed)
{
  ALERT(at_console, "[LM] Client command\n");
  auto states = eventClientCommand->states;
  for (int i = 0; i < states.size(); i++) {
    lua_getfield(states[i], LUA_REGISTRYINDEX, "engine_client_command");
    lua_pcall(states[i], 0, 0, 0);
  }
  //RETURN_META_VALUE(MRES_IGNORED, 0);
}


Event *eventServerCommand = addEvent("engine_server_command");
void pfnServerCommand(const char* str)
{
  ALERT(at_console, "[LM] Server command %s\n", str);
  auto states = eventServerCommand->states;
  for (int i = 0; i < states.size(); i++) {
    lua_getglobal(states[i], "event");
    lua_pcall(states[i], 0, 0, 0);
  }
  //RETURN_META_VALUE(MRES_IGNORED, 0);
}
