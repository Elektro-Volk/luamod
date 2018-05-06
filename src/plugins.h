#include "luai.h"
#include <vector>

class Plugin {
public:
  lua_State *state;

  bool load(const char *path);
};

namespace luaPlugins {
  extern std::vector<Plugin*> plugins;

  void loadPlugins();
};
