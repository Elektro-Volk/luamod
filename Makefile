HLSDK = include/hlsdk
METAMOD = include/metamod

NAME = luamod

COMPILER = g++

OBJECTS = \
src/public.cpp \
src/callbacks.cpp \
src/dllapi.cpp \
src/engine_api.cpp \
src/ex_rehlds_api.cpp \
src/h_export.cpp \
src/lua_functions.cpp \
src/meta_api.cpp \
src/lua/CLuaWorker.cpp \
src/lua/commands.cpp \
src/lua/lu_offset.cpp \
src/lua/lu_engfuncs.cpp \
src/lua/luaapi.cpp

LINK =-L./lua -llua

OPT_FLAGS = -O3 -msse3 -flto -funroll-loops -fomit-frame-pointer -fno-stack-protector -fPIC -m32

INCLUDE = -I. -I./src -I$(HLSDK)/common -I$(HLSDK)/dlls -I$(HLSDK)/engine \
		-I$(HLSDK)/game_shared -I$(HLSDK)/pm_shared -I$(HLSDK)/public -I$(METAMOD)

BIN_DIR = Release
CFLAGS = $(OPT_FLAGS)

CFLAGS += -g -DNDEBUG -Dlinux -D__linux__ -D__USE_GNU -std=gnu++11 -shared

OBJ_LINUX := $(OBJECTS:%.c=$(BIN_DIR)/%.o)

$(BIN_DIR)/src/%.o: %.c
	$(COMPILER) $(INCLUDE) $(CFLAGS) -o $@ -c $<

all:
	mkdir -p $(BIN_DIR)

	$(MAKE) $(NAME) && strip -x $(BIN_DIR)/$(NAME)_mm_i386.so

$(NAME): $(OBJ_LINUX)
	$(COMPILER) $(INCLUDE) $(CFLAGS) $(OBJ_LINUX) $(LINK) -o$(BIN_DIR)/$(NAME)_mm_i386.so

check:
	cppcheck $(INCLUDE) --quiet --max-configs=100 -D__linux__ -DNDEBUG .

debug:
	$(MAKE) all DEBUG=false

default: all

clean:
	rm -rf Release/*.o
	rm -rf Release/$(NAME)_mm_i386.so
