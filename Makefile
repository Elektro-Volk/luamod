CC=g++ -g -m32
CFLAGS=-std=c++11 -c -fPIC -m32
LDFLAGS=-Wl,-rpath,. -shared -m32 -L./lua -llua
INCLUDES=-I./src -I./hlsdk/dlls -I./hlsdk/common -I./hlsdk/engine -I./metamod/metamod/src -I./
SOURCES=	\
	src/main.cpp \
	src/plugins.cpp \
	src/luamod.cpp \
	src/luaapi.cpp \
	src/lua_functions.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=LuaMod

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o lib$(EXECUTABLE).so
	ar rc lib$(EXECUTABLE).a $(OBJECTS)
	ranlib lib$(EXECUTABLE).a
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@
clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
