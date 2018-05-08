#include <extdll.h>
#include <meta_api.h>
#include "plugins.h"

int lPrint (lua_State *L)
{
    const char* str = luaL_checkstring(L, 1);
    ALERT(at_console, "%s\n", str);
    return 0;
}
