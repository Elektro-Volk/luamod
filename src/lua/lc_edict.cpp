#include "lc_edict.h"

void lc_edict::init_api(lua_State *L)
{
  // Functions
  lua_register(L, "set_offset_float", l_set_offset_float);

  // edict
	luaL_newmetatable(L, "edict_t");
	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");

	//lua_pushstring(L, "__call");
	//lua_pushcfunction(L, mysqlwork::execute);
	//lua_settable(L, -3);

  lua_pop(L, 1);
}

void lc_edict::push_edict(lua_State *L, edict_t* obj)
{
	lua_pushlightuserdata(L, obj);
  luaL_getmetatable(L, "edict_t");
  lua_setmetatable(L, -2);
}

int lc_edict::l_set_offset_float(lua_State *L)
{
  edict_t* obj = (edict_t*)luaL_checkudata(L, 1, "edict_t");
  int offset = luaL_checkinteger(L, 2);
  float value = luaL_checknumber(L, 3);
  (int*)((char*)obj + offset) =
  obj->v.health = health;
  return 0;
}
