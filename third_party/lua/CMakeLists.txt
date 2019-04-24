project ( lua C )
cmake_minimum_required ( VERSION 2.8 )
SET(CMAKE_C_FLAGS "-fPIC -m32 -DLUA_USE_DLOPEN")

include_directories ( src ${CMAKE_CURRENT_BINARY_DIR} )
set ( SRC_CORE src/lapi.c src/lcode.c src/lctype.c src/ldebug.c src/ldo.c src/ldump.c src/lfunc.c src/lgc.c src/llex.c
  src/lmem.c src/lobject.c src/lopcodes.c src/lparser.c src/lstate.c src/lstring.c src/ltable.c
src/ltm.c src/lundump.c src/lvm.c src/lzio.c )
set ( SRC_LIB src/lauxlib.c src/lbaselib.c src/lbitlib.c src/lcorolib.c src/ldblib.c src/liolib.c
  src/lmathlib.c src/loslib.c src/lstrlib.c src/ltablib.c src/lutf8lib.c src/loadlib.c src/linit.c )

add_library ( lua ${SRC_CORE} ${SRC_LIB} )
set_target_properties ( lua PROPERTIES OUTPUT_NAME lua )
