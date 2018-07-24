#pragma once
#include "luai.h"

namespace lu_engfuncs {
    void init_api(lua_State *L);
    int l_pfnMessageBegin(lua_State *L);
    int l_pfnMessageEnd(lua_State *L);
    int l_pfnWriteByte(lua_State *L);
    int l_pfnWriteChar(lua_State *L);
    int l_pfnWriteShort(lua_State *L);
    int l_pfnWriteLong(lua_State *L);
    int l_pfnWriteAngle(lua_State *L);
    int l_pfnWriteCoord(lua_State *L);
    int l_pfnWriteString(lua_State *L);
    int l_pfnWriteEntity(lua_State *L);
}
