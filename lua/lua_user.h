#include "lua.h"
 #define lua_userstateopen(L) LuaLockInitial(L)
 #define lua_userstatethread(L,L1) LuaLockInitial(L1)  // Lua 5.1

void LuaLockInitial(lua_State * L);
void lock_GC(lua_State * L);
