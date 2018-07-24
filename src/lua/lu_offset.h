#pragma once
#include <extdll.h>
#include <meta_api.h>
#include "luai.h"

namespace lu_offset {
  void init_api(lua_State *L);
  int l_get_offset_data(lua_State *L);
  int l_set_offset_float(lua_State *L);
  int l_set_offset_integer(lua_State *L);
  int l_set_offset_boolean(lua_State *L);
};
