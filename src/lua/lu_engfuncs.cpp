#include "lu_engfuncs.hpp"
#include <extdll.h>
#include <meta_api.h>
#include "ex_rehlds_api.h"
#include <vector>

/*
int			(*pfnPrecacheModel)			(char* s);
int			(*pfnPrecacheSound)			(char* s);
int			(*pfnPrecacheGeneric)		(char* s);
*/

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

/*
void		(*pfnCVarRegister)			(cvar_t *pCvar);
float		(*pfnCVarGetFloat)			(const char *szVarName);
const char*	(*pfnCVarGetString)			(const char *szVarName);
void		(*pfnCVarSetFloat)			(const char *szVarName, float flValue);
void		(*pfnCVarSetString)			(const char *szVarName, const char *szValue);
cvar_t		(*pfnCVarGetPointer)		(const char *szVarName);
*/

void lu_engfuncs::init_api(lua_State *L)
{
  lua_register(L, "precache_model", l_pfnPrecacheModel);
  lua_register(L, "precache_sound", l_pfnPrecacheSound);
  lua_register(L, "precache_generic", l_pfnPrecacheGeneric);
  //
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
  //
  lua_register(L, "cvar_register", l_pfnRegister_Cvar);
  lua_register(L, "cvar_get_float", l_pfnCVarGetFloat);
  lua_register(L, "cvar_get_string", l_pfnCVarGetString);
  lua_register(L, "cvar_set_float", l_pfnCVarSetFloat);
  lua_register(L, "cvar_set_string", l_pfnCVarSetString);
}

int lu_engfuncs::l_pfnPrecacheModel(lua_State *L)
{
	PRECACHE_MODEL(luaL_checkstring(L, 1));
	return 1;
}

int lu_engfuncs::l_pfnPrecacheSound(lua_State *L)
{
	PRECACHE_SOUND(luaL_checkstring(L, 1));
	return 1;
}

int lu_engfuncs::l_pfnPrecacheGeneric(lua_State *L)
{
	PRECACHE_GENERIC(luaL_checkstring(L, 1));
	return 1;
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

int lu_engfuncs::l_pfnRegister_Cvar(lua_State *L)
{
        cvar_t cvar_lua_mod = { luaL_checkstring(L, 1), (char*)luaL_checkstring(L, 2) };
        CVAR_REGISTER(&cvar_lua_mod);
        return 0;
}

int lu_engfuncs::l_pfnCVarGetFloat(lua_State *L)
{
	lua_pushnumber(L, CVAR_GET_FLOAT(luaL_checkstring(L, 1)));
	return 1;
}

int lu_engfuncs::l_pfnCVarGetString(lua_State *L)
{
	lua_pushstring(L, CVAR_GET_STRING(luaL_checkstring(L, 1)));
	return 1;
}

int lu_engfuncs::l_pfnCVarSetFloat(lua_State *L)
{
	CVAR_SET_FLOAT(luaL_checkstring(L, 1), luaL_checknumber(L, 2));
	return 1;
}

int lu_engfuncs::l_pfnCVarSetString(lua_State *L)
{
	CVAR_SET_STRING(luaL_checkstring(L, 1), luaL_checkstring(L, 2));
	return 1;
}
