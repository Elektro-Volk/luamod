# The project sources
set( SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src )
set( S_SOURCES
    ${SRC_PATH}/lib/dllapi.cpp
    ${SRC_PATH}/lib/engine_api.cpp
    ${SRC_PATH}/lib/ex_rehlds_api.cpp
    ${SRC_PATH}/lib/h_export.cpp
    ${SRC_PATH}/lib/meta_api.cpp
    ${SRC_PATH}/lib/public.cpp

    ${SRC_PATH}/lua/callbacks.cpp
    ${SRC_PATH}/lua/CLuaWorker.cpp
    ${SRC_PATH}/lua/commands.cpp
    ${SRC_PATH}/lua/lu_engfuncs.cpp
    ${SRC_PATH}/lua/lu_offset.cpp
    ${SRC_PATH}/lua/luaapi.cpp
)
