#pragma once
#include <extdll.h>
#include <meta_api.h>

void pfnClientCommand(edict_t* ed);
void pfnClientPutInServer(edict_t* ed);
void pfnServerCommand(const char* str);
