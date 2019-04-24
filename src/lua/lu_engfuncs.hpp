#pragma once
#include "luai.h"

namespace lu_engfuncs {
    void init_api(lua_State *L);
    int l_pfnPrecacheModel(lua_State *L);
    int l_pfnPrecacheSound(lua_State *L);
    int l_pfnSetModel(lua_State *L);
    int l_pfnModelIndex(lua_State *L);
    int l_pfnModelFrames(lua_State *L);
    int l_pfnSetSize(lua_State *L);
    int l_pfnChangeLevel(lua_State *L);
    int l_pfnGetSpawnParms(lua_State *L);
    int l_pfnSaveSpawnParms(lua_State *L);
    int l_pfnVecToYaw(lua_State *L);
    int l_pfnVecToAngles(lua_State *L);
    int l_pfnMoveToOrigin(lua_State *L);
    int l_pfnChangeYaw(lua_State *L);
    int l_pfnChangePitch(lua_State *L);
    int l_pfnFindEntityByString(lua_State *L);
    int l_pfnGetEntityIllum(lua_State *L);
    int l_pfnFindEntityInSphere(lua_State *L);
    int l_pfnFindClientInPVS(lua_State *L);
    int l_pfnEntitiesInPVS(lua_State *L);
    int l_pfnMakeVectors(lua_State *L);
    int l_pfnAngleVectors(lua_State *L);
    int l_pfnCreateEntity(lua_State *L);
    int l_pfnRemoveEntity(lua_State *L);
    int l_pfnCreateNamedEntity(lua_State *L);
    int l_pfnMakeStatic(lua_State *L);
    int l_pfnEntIsOnFloor(lua_State *L);
    int l_pfnDropToFloor(lua_State *L);
    int l_pfnWalkMove(lua_State *L);
    int l_pfnSetOrigin(lua_State *L);
    int l_pfnEmitSound(lua_State *L);
    int l_pfnEmitAmbientSound(lua_State *L);
    int l_pfnTraceLine(lua_State *L);
    int l_pfnTraceToss(lua_State *L);
    int l_pfnTraceMonsterHull(lua_State *L);
    int l_pfnTraceHull(lua_State *L);
    int l_pfnTraceModel(lua_State *L);
    int l_pfnTraceTexture(lua_State *L);
    int l_pfnTraceSphere(lua_State *L);
    int l_pfnGetAimVector(lua_State *L);
    int l_pfnServerCommand(lua_State *L);
    int l_pfnServerExecute(lua_State *L);
    int l_pfnClientCommand(lua_State *L);
    int l_pfnParticleEffect(lua_State *L);
    int l_pfnLightStyle(lua_State *L);
    int l_pfnDecalIndex(lua_State *L);
    int l_pfnPointContents(lua_State *L);
    int l_pfnMessageBegin(lua_State *L);
    int l_pfnMessageEnd(lua_State *L);
    int l_pfnWriteByte(lua_State *L);
    int l_pfnWriteChar(lua_State *L);
    int l_pfnWriteShort(lua_State *L);
    int l_pfnWriteLong(lua_State *L);
    int l_pfnWriteAngle(lua_State *L);
    int l_pfnWriteCoord(lua_State *L);
    int l_pfnWriteString(lua_State *L);
    int l_pfnWriteEntity(lua_State *L);
    int l_pfnCVarRegister(lua_State *L);
    int l_pfnCVarGetFloat(lua_State *L);
    int l_pfnCVarGetString (lua_State *L);
    int l_pfnCVarSetFloat(lua_State *L);
    int l_pfnCVarSetString(lua_State *L);
    int l_pfnAlertMessage(lua_State *L);
    int l_pfnEngineFprintf(lua_State *L);
    int l_pfnPvAllocEntPrivateData(lua_State *L);
    int l_pfnPvEntPrivateData(lua_State *L);
    int l_pfnFreeEntPrivateData(lua_State *L);
    int l_pfnSzFromIndex(lua_State *L);
    int l_pfnAllocString(lua_State *L);
    int l_pfnGetVarsOfEnt(lua_State *L);
    int l_pfnPEntityOfEntOffset(lua_State *L);
    int l_pfnEntOffsetOfPEntity(lua_State *L);
    int l_pfnIndexOfEdict(lua_State *L);
    int l_pfnPEntityOfEntIndex(lua_State *L);
    int l_pfnFindEntityByVars(lua_State *L);
    int l_pfnGetModelPtr(lua_State *L);
    int l_pfnRegUserMsg(lua_State *L);
    int l_pfnAnimationAutomove(lua_State *L);
    int l_pfnGetBonePosition(lua_State *L);
    int l_pfnFunctionFromName(lua_State *L);
    int l_pfnNameForFunction(lua_State *L);
    int l_pfnClientPrintf(lua_State *L);
    int l_pfnServerPrint(lua_State *L);
    int l_pfnCmd_Args(lua_State *L);
    int l_pfnCmd_Argv(lua_State *L);
    int l_pfnCmd_Argc(lua_State *L);
    int l_pfnGetAttachment(lua_State *L);
    /*
    int l_pfnCRC32_Init(lua_State *L);
    int l_pfnCRC32_ProcessBuffer(lua_State *L);
    int l_pfnCRC32_ProcessByte(lua_State *L);
    int l_pfnCRC32_Final(lua_State *L);
    */
    int l_pfnRandomLong(lua_State *L);
    int l_pfnRandomFloat(lua_State *L);
    int l_pfnSetView(lua_State *L);
    int l_pfnTime(lua_State *L);
    int l_pfnCrosshairAngle(lua_State *L);
    int l_pfnLoadFileForMe(lua_State *L);
    int l_pfnFreeFile(lua_State *L);
    int l_pfnEndSection(lua_State *L);
    int l_pfnCompareFileTime(lua_State *L);
    int l_pfnGetGameDir(lua_State *L);
    int l_pfnCvar_RegisterVariable(lua_State *L);
    int l_pfnFadeClientVolume(lua_State *L);
    int l_pfnSetClientMaxspeed(lua_State *L);
    int l_pfnCreateFakeClient(lua_State *L);
    int l_pfnRunPlayerMove(lua_State *L);
    int l_pfnNumberOfEntities(lua_State *L);
    int l_pfnGetInfoKeyBuffer(lua_State *L);
    int l_pfnInfoKeyValue(lua_State *L);
    int l_pfnSetKeyValue(lua_State *L);
    int l_pfnSetClientKeyValue(lua_State *L);
    int l_pfnIsMapValid(lua_State *L);
    int l_pfnStaticDecal(lua_State *L);
    int l_pfnPrecacheGeneric(lua_State *L);
    int l_pfnGetPlayerUserId(lua_State *L);
    int l_pfnBuildSoundMsg(lua_State *L);
    int l_pfnIsDedicatedServer(lua_State *L);
    int l_pfnCVarGetPointer(lua_State *L);
    int l_pfnGetPlayerWONId(lua_State *L);
    int l_pfnInfo_RemoveKey(lua_State *L);
    int l_pfnGetPhysicsKeyValue(lua_State *L);
    int l_pfnSetPhysicsKeyValue(lua_State *L);
    int l_pfnGetPhysicsInfoString(lua_State *L);
    int l_pfnPrecacheEvent(lua_State *L);
    int l_pfnPlaybackEvent(lua_State *L);
    int l_pfnSetFatPVS(lua_State *L);
    int l_pfnSetFatPAS(lua_State *L);
    int l_pfnCheckVisibility (lua_State *L);
    int l_pfnDeltaSetField(lua_State *L);
    int l_pfnDeltaUnsetField(lua_State *L);
    int l_pfnDeltaAddEncoder(lua_State *L);
    int l_pfnGetCurrentPlayer(lua_State *L);
    int l_pfnCanSkipPlayer(lua_State *L);
    int l_pfnDeltaFindField(lua_State *L);
    int l_pfnDeltaSetFieldByIndex(lua_State *L);
    int l_pfnDeltaUnsetFieldByIndex(lua_State *L);
    int l_pfnSetGroupMask(lua_State *L);
    int l_pfnCreateInstancedBaseline(lua_State *L);
    int l_pfnCvar_DirectSet(lua_State *L);
    int l_pfnForceUnmodified(lua_State *L);
    int l_pfnGetPlayerStats(lua_State *L);
    int l_pfnAddServerCommand(lua_State *L);
    int l_pfnVoice_GetClientListening(lua_State *L);
    int l_pfnVoice_SetClientListening(lua_State *L);
    int l_pfnGetPlayerAuthId(lua_State *L);
    int l_pfnSequenceGet(lua_State *L);
    int l_pfnSequencePickSentence(lua_State *L);
    int l_pfnGetFileSize(lua_State *L);
    int l_pfnGetApproxWavePlayLen(lua_State *L);
    int l_pfnIsCareerMatch(lua_State *L);
    int l_pfnGetLocalizedStringLength(lua_State *L);
    int l_pfnRegisterTutorMessageShown(lua_State *L);
    int l_pfnGetTimesTutorMessageShown(lua_State *L);
    int l_pfnProcessTutorMessageDecayBuffer(lua_State *L);
    int l_pfnConstructTutorMessageDecayBuffer(lua_State *L);
    int l_pfnResetTutorMessageDecayData(lua_State *L);
    int l_pfnQueryClientCvarValue(lua_State *L);
    int l_pfnQueryClientCvarValue2(lua_State *L);
    int l_CheckParm(lua_State *L);

    int	l_pfnSpawn(lua_State *L); // TODO: Move to entityInterface
}

/* TODO */
/*

// Engine hands this to DLLs for functionality callbacks
typedef struct enginefuncs_s
{
	int			(*pfnPrecacheModel)			(char* s);
	int			(*pfnPrecacheSound)			(char* s);
	void		(*pfnSetModel)				(edict_t *e, const char *m);
	int			(*pfnModelIndex)			(const char *m);
	int			(*pfnModelFrames)			(int modelIndex);
	void		(*pfnSetSize)				(edict_t *e, const float *rgflMin, const float *rgflMax);
	void		(*pfnChangeLevel)			(char* s1, char* s2);
	void		(*pfnGetSpawnParms)			(edict_t *ent);
	void		(*pfnSaveSpawnParms)		(edict_t *ent);
	float		(*pfnVecToYaw)				(const float *rgflVector);
	void		(*pfnVecToAngles)			(const float *rgflVectorIn, float *rgflVectorOut);
	void		(*pfnMoveToOrigin)			(edict_t *ent, const float *pflGoal, float dist, int iMoveType);
	void		(*pfnChangeYaw)				(edict_t* ent);
	void		(*pfnChangePitch)			(edict_t* ent);
	edict_t*	(*pfnFindEntityByString)	(edict_t *pEdictStartSearchAfter, const char *pszField, const char *pszValue);
	int			(*pfnGetEntityIllum)		(edict_t* pEnt);
	edict_t*	(*pfnFindEntityInSphere)	(edict_t *pEdictStartSearchAfter, const float *org, float rad);
	edict_t*	(*pfnFindClientInPVS)		(edict_t *pEdict);
	edict_t* (*pfnEntitiesInPVS)			(edict_t *pplayer);
	void		(*pfnMakeVectors)			(const float *rgflVector);
	void		(*pfnAngleVectors)			(const float *rgflVector, float *forward, float *right, float *up);

	void		(*pfnMakeStatic)			(edict_t *ent);
	int			(*pfnEntIsOnFloor)			(edict_t *e);
	int			(*pfnDropToFloor)			(edict_t* e);
	int			(*pfnWalkMove)				(edict_t *ent, float yaw, float dist, int iMode);
	void		(*pfnSetOrigin)				(edict_t *e, const float *rgflOrigin);
	void		(*pfnEmitSound)				(edict_t *entity, int channel, const char *sample, /*int*///float volume, float attenuation, int fFlags, int pitch);
/*	void		(*pfnEmitAmbientSound)		(edict_t *entity, float *pos, const char *samp, float vol, float attenuation, int fFlags, int pitch);
	void		(*pfnTraceLine)				(const float *v1, const float *v2, int fNoMonsters, edict_t *pentToSkip, TraceResult *ptr);
	void		(*pfnTraceToss)				(edict_t* pent, edict_t* pentToIgnore, TraceResult *ptr);
	int			(*pfnTraceMonsterHull)		(edict_t *pEdict, const float *v1, const float *v2, int fNoMonsters, edict_t *pentToSkip, TraceResult *ptr);
	void		(*pfnTraceHull)				(const float *v1, const float *v2, int fNoMonsters, int hullNumber, edict_t *pentToSkip, TraceResult *ptr);
	void		(*pfnTraceModel)			(const float *v1, const float *v2, int hullNumber, edict_t *pent, TraceResult *ptr);
	const char *(*pfnTraceTexture)			(edict_t *pTextureEntity, const float *v1, const float *v2 );
	void		(*pfnTraceSphere)			(const float *v1, const float *v2, int fNoMonsters, float radius, edict_t *pentToSkip, TraceResult *ptr);
	void		(*pfnGetAimVector)			(edict_t* ent, float speed, float *rgflReturn);
	void		(*pfnServerCommand)			(char* str);
	void		(*pfnServerExecute)			(void);
	void		(*pfnClientCommand)			(edict_t* pEdict, char* szFmt, ...);
	void		(*pfnParticleEffect)		(const float *org, const float *dir, float color, float count);
	void		(*pfnLightStyle)			(int style, char* val);
	int			(*pfnDecalIndex)			(const char *name);
	int			(*pfnPointContents)			(const float *rgflVector);
	void		(*pfnMessageBegin)			(int msg_dest, int msg_type, const float *pOrigin, edict_t *ed);
	void		(*pfnMessageEnd)			(void);
	void		(*pfnWriteByte)				(int iValue);
	void		(*pfnWriteChar)				(int iValue);
	void		(*pfnWriteShort)			(int iValue);
	void		(*pfnWriteLong)				(int iValue);
	void		(*pfnWriteAngle)			(float flValue);
	void		(*pfnWriteCoord)			(float flValue);
	void		(*pfnWriteString)			(const char *sz);
	void		(*pfnWriteEntity)			(int iValue);
	void		(*pfnCVarRegister)			(cvar_t *pCvar);
	float		(*pfnCVarGetFloat)			(const char *szVarName);
	const char*	(*pfnCVarGetString)			(const char *szVarName);
	void		(*pfnCVarSetFloat)			(const char *szVarName, float flValue);
	void		(*pfnCVarSetString)			(const char *szVarName, const char *szValue);
	void		(*pfnAlertMessage)			(ALERT_TYPE atype, char *szFmt, ...);
	void		(*pfnEngineFprintf)			(void *pfile, char *szFmt, ...);
	void*		(*pfnPvAllocEntPrivateData)	(edict_t *pEdict, int32 cb);
	void*		(*pfnPvEntPrivateData)		(edict_t *pEdict);
	void		(*pfnFreeEntPrivateData)	(edict_t *pEdict);
	const char*	(*pfnSzFromIndex)			(int iString);
	int			(*pfnAllocString)			(const char *szValue);
	struct entvars_s*	(*pfnGetVarsOfEnt)			(edict_t *pEdict);
	edict_t*	(*pfnPEntityOfEntOffset)	(int iEntOffset);
	int			(*pfnEntOffsetOfPEntity)	(const edict_t *pEdict);
	int			(*pfnIndexOfEdict)			(const edict_t *pEdict);
	edict_t*	(*pfnPEntityOfEntIndex)		(int iEntIndex);
	edict_t*	(*pfnFindEntityByVars)		(struct entvars_s* pvars);
	void*		(*pfnGetModelPtr)			(edict_t* pEdict);
	int			(*pfnRegUserMsg)			(const char *pszName, int iSize);
	void		(*pfnAnimationAutomove)		(const edict_t* pEdict, float flTime);
	void		(*pfnGetBonePosition)		(const edict_t* pEdict, int iBone, float *rgflOrigin, float *rgflAngles );
	uint32 (*pfnFunctionFromName)	( const char *pName );
	const char *(*pfnNameForFunction)		( uint32 function );
	void		(*pfnClientPrintf)			( edict_t* pEdict, PRINT_TYPE ptype, const char *szMsg ); // JOHN: engine callbacks so game DLL can print messages to individual clients
	void		(*pfnServerPrint)			( const char *szMsg );
	const char *(*pfnCmd_Args)				( void );		// these 3 added
	const char *(*pfnCmd_Argv)				( int argc );	// so game DLL can easily
	int			(*pfnCmd_Argc)				( void );		// access client 'cmd' strings
	void		(*pfnGetAttachment)			(const edict_t *pEdict, int iAttachment, float *rgflOrigin, float *rgflAngles );
	void		(*pfnCRC32_Init)			(CRC32_t *pulCRC);
	void        (*pfnCRC32_ProcessBuffer)   (CRC32_t *pulCRC, void *p, int len);
	void		(*pfnCRC32_ProcessByte)     (CRC32_t *pulCRC, unsigned char ch);
	CRC32_t		(*pfnCRC32_Final)			(CRC32_t pulCRC);
	int32		(*pfnRandomLong)			(int32  lLow,  int32  lHigh);
	float		(*pfnRandomFloat)			(float flLow, float flHigh);
	void		(*pfnSetView)				(const edict_t *pClient, const edict_t *pViewent );
	float		(*pfnTime)					( void );
	void		(*pfnCrosshairAngle)		(const edict_t *pClient, float pitch, float yaw);
	byte *      (*pfnLoadFileForMe)         (char *filename, int *pLength);
	void        (*pfnFreeFile)              (void *buffer);
	void        (*pfnEndSection)            (const char *pszSectionName); // trigger_endsection
	int 		(*pfnCompareFileTime)       (char *filename1, char *filename2, int *iCompare);
	void        (*pfnGetGameDir)            (char *szGetGameDir);
	void		(*pfnCvar_RegisterVariable) (cvar_t *variable);
	void        (*pfnFadeClientVolume)      (const edict_t *pEdict, int fadePercent, int fadeOutSeconds, int holdTime, int fadeInSeconds);
	void        (*pfnSetClientMaxspeed)     (const edict_t *pEdict, float fNewMaxspeed);
	edict_t *	(*pfnCreateFakeClient)		(const char *netname);	// returns NULL if fake client can't be created
	void		(*pfnRunPlayerMove)			(edict_t *fakeclient, const float *viewangles, float forwardmove, float sidemove, float upmove, unsigned short buttons, byte impulse, byte msec );
	int			(*pfnNumberOfEntities)		(void);
	char*		(*pfnGetInfoKeyBuffer)		(edict_t *e);	// passing in NULL gets the serverinfo
	char*		(*pfnInfoKeyValue)			(char *infobuffer, char *key);
	void		(*pfnSetKeyValue)			(char *infobuffer, char *key, char *value);
	void		(*pfnSetClientKeyValue)		(int clientIndex, char *infobuffer, char *key, char *value);
	int			(*pfnIsMapValid)			(char *filename);
	void		(*pfnStaticDecal)			( const float *origin, int decalIndex, int entityIndex, int modelIndex );
	int			(*pfnPrecacheGeneric)		(char* s);
	int			(*pfnGetPlayerUserId)		(edict_t *e ); // returns the server assigned userid for this player.  useful for logging frags, etc.  returns -1 if the edict couldn't be found in the list of clients
	void		(*pfnBuildSoundMsg)			(edict_t *entity, int channel, const char *sample, /*int*///float volume, float attenuation, int fFlags, int pitch, int msg_dest, int msg_type, const float *pOrigin, edict_t *ed);
	//int			(*pfnIsDedicatedServer)		(void);// is this a dedicated server?
	//cvar_t		*(*pfnCVarGetPointer)		(const char *szVarName);
	//unsigned int (*pfnGetPlayerWONId)		(edict_t *e); // returns the server assigned WONid for this player.  useful for logging frags, etc.  returns -1 if the edict couldn't be found in the list of clients

	// YWB 8/1/99 TFF Physics additions
	/*void		(*pfnInfo_RemoveKey)		( char *s, const char *key );
	const char *(*pfnGetPhysicsKeyValue)	( const edict_t *pClient, const char *key );
	void		(*pfnSetPhysicsKeyValue)	( const edict_t *pClient, const char *key, const char *value );
	const char *(*pfnGetPhysicsInfoString)	( const edict_t *pClient );
	unsigned short (*pfnPrecacheEvent)		( int type, const char*psz );
	void		(*pfnPlaybackEvent)			( int flags, const edict_t *pInvoker, unsigned short eventindex, float delay, float *origin, float *angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2 );

	unsigned char *(*pfnSetFatPVS)			( float *org );
	unsigned char *(*pfnSetFatPAS)			( float *org );

	int			(*pfnCheckVisibility )		( const edict_t *entity, unsigned char *pset );

	void		(*pfnDeltaSetField)			( struct delta_s *pFields, const char *fieldname );
	void		(*pfnDeltaUnsetField)		( struct delta_s *pFields, const char *fieldname );
	void		(*pfnDeltaAddEncoder)		( char *name, void (*conditionalencode)( struct delta_s *pFields, const unsigned char *from, const unsigned char *to ) );
	int			(*pfnGetCurrentPlayer)		( void );
	int			(*pfnCanSkipPlayer)			( const edict_t *player );
	int			(*pfnDeltaFindField)		( struct delta_s *pFields, const char *fieldname );
	void		(*pfnDeltaSetFieldByIndex)	( struct delta_s *pFields, int fieldNumber );
	void		(*pfnDeltaUnsetFieldByIndex)( struct delta_s *pFields, int fieldNumber );

	void		(*pfnSetGroupMask)			( int mask, int op );

	int			(*pfnCreateInstancedBaseline) ( int classname, struct entity_state_s *baseline );
	void		(*pfnCvar_DirectSet)		( struct cvar_s *var, char *value );

	// Forces the client and server to be running with the same version of the specified file
	//  ( e.g., a player model ).
	// Calling this has no effect in single player
	void		(*pfnForceUnmodified)		( FORCE_TYPE type, float *mins, float *maxs, const char *filename );

	void		(*pfnGetPlayerStats)		( const edict_t *pClient, int *ping, int *packet_loss );

	void		(*pfnAddServerCommand)		( char *cmd_name, void (*function) (void) );

	// For voice communications, set which clients hear eachother.
	// NOTE: these functions take player entity indices (starting at 1).
	qboolean	(*pfnVoice_GetClientListening)(int iReceiver, int iSender);
	qboolean	(*pfnVoice_SetClientListening)(int iReceiver, int iSender, qboolean bListen);

	const char *(*pfnGetPlayerAuthId)		( edict_t *e );

	// PSV: Added for CZ training map
//	const char *(*pfnKeyNameForBinding)		( const char* pBinding );

	sequenceEntry_s*	(*pfnSequenceGet)			( const char* fileName, const char* entryName );
	sentenceEntry_s*	(*pfnSequencePickSentence)	( const char* groupName, int pickMethod, int *picked );

	// LH: Give access to filesize via filesystem
	int			(*pfnGetFileSize)			( char *filename );

	unsigned int (*pfnGetApproxWavePlayLen) (const char *filepath);
	// MDC: Added for CZ career-mode
	int			(*pfnIsCareerMatch)			( void );

	// BGC: return the number of characters of the localized string referenced by using "label"
	int			(*pfnGetLocalizedStringLength)(const char *label);

	// BGC: added to facilitate persistent storage of tutor message decay values for
	// different career game profiles.  Also needs to persist regardless of mp.dll being
	// destroyed and recreated.
	void (*pfnRegisterTutorMessageShown)(int mid);
	int (*pfnGetTimesTutorMessageShown)(int mid);
	void (*ProcessTutorMessageDecayBuffer)(int *buffer, int bufferLength);
	void (*ConstructTutorMessageDecayBuffer)(int *buffer, int bufferLength);
	void (*ResetTutorMessageDecayData)( void );

	void (*pfnQueryClientCvarValue)( const edict_t *player, const char *cvarName );
	void (*pfnQueryClientCvarValue2)( const edict_t *player, const char *cvarName, int requestID );
	int (*pfnCheckParm)( const char *pchCmdLineToken, char **ppnext );
} enginefuncs_t;
*/
