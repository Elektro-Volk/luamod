#include "lu_offset.h"

void lu_offset::init_api(lua_State *L)
{
  // Functions
  lua_register(L, "get_offset_data", lu_offset::l_get_offset_data);
  lua_register(L, "set_offset_float", lu_offset::l_set_offset_float);
}

int lu_offset::l_get_offset_data(lua_State *L)
{
    char* obj = (char*)lua_touserdata(L, 1);
    int offset = luaL_checkinteger(L, 2);
    lua_pushlightuserdata(L, obj + offset);
    return 1;
}

int lu_offset::l_set_offset_float(lua_State *L)
{
    char* obj = (char*)lua_touserdata(L, 1);
    int offset = luaL_checkinteger(L, 2);
    float value = luaL_checknumber(L, 3);
    *(float*)(obj + offset) = value;
    return 0;
}
