#include <extdll.h>
#include <meta_api.h>
#include "luamod.h"
#include "plugins.h"

void attach()
{
  luaPlugins::loadPlugins();
}
