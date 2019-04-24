cmake_minimum_required(VERSION 2.8)
project(luamod)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
SET(CMAKE_CXX_FLAGS "-std=c++11 -m32")
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set ( CMAKE_PREFIX_PATH /usr/lib/x86_64-linux-gnu/cmake/ )

# Lua library
add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/third_party/lua )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/third_party/lua/src )

# Ravi Lua library
#set(LLVM_TARGETS_TO_BUILD "X86")
#set(LLVM_JIT "ON")
#set(STATIC_BUILD "ON")
#add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/third_party/ravi )
#include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/third_party/ravi/include )
#link_directories( ${CMAKE_CURRENT_SOURCE_DIR}/third_party/ravi/build )
# liblibravillvm.a

# HlSdk
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/third_party/hlsdk/common )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/third_party/hlsdk/dlls )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/third_party/hlsdk/engine )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/third_party/hlsdk/game_shared )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/third_party/hlsdk/pm_shared )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/third_party/hlsdk/public )

# Metamod
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/third_party/metamod )

# Engine source files
include_directories( src/ )
include( Sources.cmake )

add_library(luamod SHARED ${S_SOURCES})
target_link_libraries(luamod dl pthread lua )
