#include "lu_engfuncs.hpp"
#include <extdll.h>
#include <meta_api.h>
#include "ex_rehlds_api.h"

/*
void		(*pfnMessageBegin)			(int msg_dest, int msg_type, const float *pOrigin, edict_t *ed);
void		(*pfnMessageEnd)			(void);
void		(*pfnWriteByte)				(int iValue);
void		(*pfnWriteChar)				(int iValue);
void		(*pfnWriteShort)			(int iValue);
void		(*pfnWriteLong)				(int iValue);
void		(*pfnWriteAngle)			(float flValue);
void		(*pfnWriteCoord)			(float flValue);
void		(*pfnWriteString)			(const char *sz);
void		(*pfnWriteEntity)			(int iValue);
*/

void lu_engfuncs::init_api(lua_State *L)
{
  lua_register(L, "message_begin", l_pfnMessageBegin);
  lua_register(L, "message_end", l_pfnMessageEnd);
  lua_register(L, "write_byte", l_pfnWriteByte);
  lua_register(L, "write_char", l_pfnWriteChar);
  lua_register(L, "write_short", l_pfnWriteShort);
  lua_register(L, "write_long", l_pfnWriteLong);
  lua_register(L, "write_angle", l_pfnWriteAngle);
  lua_register(L, "write_coord", l_pfnWriteCoord);
  lua_register(L, "write_string", l_pfnWriteString);
  lua_register(L, "write_entity", l_pfnWriteEntity);
}

int lu_engfuncs::l_pfnMessageBegin(lua_State *L)
{
    //luaL_checktable(L, 3); // Origin
    std::vector<float> origin;

    lua_pushnil(L);
	while (lua_next(L, 3))
	{
		lua_pushvalue(L, -1);
		origin.push_back(luaL_checknumber(L, -1));
		lua_pop(L, 2);
    }

    MESSAGE_BEGIN (
        luaL_checkinteger(L, 1), // DEST
        luaL_checkinteger(L, 2), // TYPE
        origin.data(),           // ORIGIN
        (edict_t*)lua_touserdata(L, 4)  // PLAYER
    );

    return 0;
}

int lu_engfuncs::l_pfnMessageEnd(lua_State *L)
{
    MESSAGE_END();
    return 0;
}

int lu_engfuncs::l_pfnWriteByte(lua_State *L)
{
    WRITE_BYTE(luaL_checkinteger(L, 1));
    return 0;
}

int lu_engfuncs::l_pfnWriteChar(lua_State *L)
{
    WRITE_CHAR(luaL_checkinteger(L, 1));
    return 0;
}

int lu_engfuncs::l_pfnWriteShort(lua_State *L)
{
    WRITE_SHORT(luaL_checkinteger(L, 1));
    return 0;
}

int lu_engfuncs::l_pfnWriteLong(lua_State *L)
{
    WRITE_LONG(luaL_checkinteger(L, 1));
    return 0;
}

int lu_engfuncs::l_pfnWriteAngle(lua_State *L)
{
    WRITE_ANGLE(luaL_checknumber(L, 1));
    return 0;
}

int lu_engfuncs::l_pfnWriteCoord(lua_State *L)
{
    WRITE_COORD(luaL_checknumber(L, 1));
    return 0;
}

int lu_engfuncs::l_pfnWriteString(lua_State *L)
{
    WRITE_STRING(luaL_checkstring(L, 1));
    return 0;
}

int lu_engfuncs::l_pfnWriteEntity(lua_State *L)
{
    WRITE_ENTITY(luaL_checkinteger(L, 1));
    return 0;
}
