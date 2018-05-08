#pragma once
#include <extdll.h>
#include <meta_api.h>
#include "plugins.h"
#include <string>
#include <map>

class Event {
public:
  std::vector<lua_State *> states;
  std::string name;
};

extern std::map<std::string, Event*> events;

extern Event *addEvent(std::string name);
