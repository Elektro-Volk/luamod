#pragma once
#include <extdll.h>
#include <meta_api.h>

void pfnMessageBegin(int msg_dest, int msg_type, const float *pOrigin, edict_t *ed);
void pfnMessageEnd();
void pfnWriteByte(int iValue);
void pfnWriteChar(int iValue);
void pfnWriteShort(int iValue);
void pfnWriteLong(int iValue);
void pfnWriteAngle(float fValue);
void pfnWriteCoord(float fValue);
void pfnWriteString(const char* sValue);
void pfnWriteEntity(int iValue);
void pfnClientCommand(edict_t* ed);
void pfnClientPutInServer(edict_t* ed);
void pfnServerCommand(const char* str);
