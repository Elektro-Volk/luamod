#pragma once
#include "luai.h"

class CLuaWorker {
private:
    lua_State *state;
public:
    CLuaWorker();
    lua_State *getState();
    void call (lua_State *L, int args = 0, int rets = 0);
    void safeCall (lua_State *L, int args = 0, int rets = 0);
    lua_State *getToEvent(const char* event);
    ~CLuaWorker();
protected:

};

extern CLuaWorker *g_luaworker;
