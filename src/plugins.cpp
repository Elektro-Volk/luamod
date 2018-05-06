#include <extdll.h>
#include <meta_api.h>
#include "luamod.h"
#include "plugins.h"
#include <string>

std::vector<Plugin*> luaPlugins::plugins;

extern void loadLuaApi(lua_State *state);

bool Plugin::load(const char* path)
{
  lua_State *state = luaL_newstate();
  loadLuaApi(state);
  std::string filename = "./valve/addons/luamod/plugins/" + std::string(path) + "/main.lua";
  if(luaL_loadfile(state, filename.c_str())) {
    ALERT(at_console, "[LM] %s\n", lua_tostring(state, -1));
    return false;
  }
  if(lua_pcall(state, 0, LUA_MULTRET, 0)) {
    ALERT(at_console, "[LM] %s\n", lua_tostring(state, -1));
    return false;
  }

  return true;
}


void luaPlugins::loadPlugins()
{
  ALERT(at_console, "[LM]: Loading lua plugins...\n");
  lua_State *state = luaL_newstate();
  loadLuaApi(state);
  if(luaL_loadfile(state, "./valve/addons/luamod/plugins.lua")) ALERT(at_console, "[LM] %s\n", lua_tostring(state, -1));
  if(lua_pcall(state, 0, LUA_MULTRET, 0)) ALERT(at_console, "[LM] %s\n", lua_tostring(state, -1));
}

int lLoad (lua_State *L)
{
  const char* path = luaL_checkstring(L, 1);
  ALERT(at_console, "Loading %s...\n", path);
  Plugin *p = new Plugin();
  if(!p->load(path)) {
    return 0;
  }
  luaPlugins::plugins.push_back(p);

  return 0;
}
