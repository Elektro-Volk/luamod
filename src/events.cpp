#include <extdll.h>
#include <meta_api.h>
#include "plugins.h"
#include <string>
#include "events.h"

std::map<std::string, Event*> events;

Event *addEvent(std::string name)
{
  Event *event = new Event();
  event->name = name;
  events.insert ( std::pair<std::string, Event*>(name, event));
  return event;
}

int lSubscribe (lua_State *L)
{
    const char* str = luaL_checkstring(L, 1);
    //lua_checkfunction(L, 2);
    if (events.find(str) == events.end()) return 0;
    Event *event = events[std::string(str)];
	  lua_setfield(L, LUA_REGISTRYINDEX, str);
    event->states.push_back(L);
    ALERT(at_console, "Subscribed event %s\n", str);
    return 0;
}
