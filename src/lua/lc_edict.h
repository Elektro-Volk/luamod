#pragma once
#include <extdll.h>
#include <meta_api.h>
#include "luai.h"

namespace lc_edict {
  void init_api(lua_State *L);
  void push_edict(lua_State *L, edict_t* obj);
  int l_setHealth(lua_State *L);
};
