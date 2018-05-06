#include <extdll.h>
#include <meta_api.h>
#include "luamod.h"

meta_globals_t *gpMetaGlobals;
DLL_FUNCTIONS g_DllFunctionTable =
{
	NULL,					// pfnGameInit
	NULL,					// pfnSpawn
	NULL,					// pfnThink
	NULL,					// pfnUse
	NULL,					// pfnTouch
	NULL,					// pfnBlocked
	NULL,					// pfnKeyValue
	NULL,					// pfnSave
	NULL,					// pfnRestore
	NULL,					// pfnSetAbsBox
	NULL,					// pfnSaveWriteFields
	NULL,					// pfnSaveReadFields
	NULL,					// pfnSaveGlobalState
	NULL,					// pfnRestoreGlobalState
	NULL,					// pfnResetGlobalState
	NULL,					// pfnClientConnect
	NULL,					// pfnClientDisconnect
	NULL,					// pfnClientKill
	NULL,					// pfnClientPutInServer
	NULL,					// pfnClientCommand
	NULL,					// pfnClientUserInfoChanged
	NULL,					// pfnServerActivate
	NULL,					// pfnServerDeactivate
	NULL,					// pfnPlayerPreThink
	NULL,					// pfnPlayerPostThink
	NULL,					// pfnStartFrame
	NULL,					// pfnParmsNewLevel
	NULL,					// pfnParmsChangeLevel
	NULL,					// pfnGetGameDescription
	NULL,					// pfnPlayerCustomization
	NULL,					// pfnSpectatorConnect
	NULL,					// pfnSpectatorDisconnect
	NULL,					// pfnSpectatorThink
	NULL,					// pfnSys_Error
	NULL,					// pfnPM_Move
	NULL,					// pfnPM_Init
	NULL,					// pfnPM_FindTextureType
	NULL,					// pfnSetupVisibility
	NULL,					// pfnUpdateClientData
	NULL,					// pfnAddToFullPack
	NULL,					// pfnCreateBaseline
	NULL,					// pfnRegisterEncoders
	NULL,					// pfnGetWeaponData
	NULL,					// pfnCmdStart
	NULL,					// pfnCmdEnd
	NULL,					// pfnConnectionlessPacket
	NULL,					// pfnGetHullBounds
	NULL,					// pfnCreateInstancedBaselines
	NULL,					// pfnInconsistentFile
	NULL,					// pfnAllowLagCompensation
};

plugin_info_t info = {
   META_INTERFACE_VERSION,            // ifvers
   "LuaMod",                  // name
   "1.00",                        // version
   "2018/05/06",                  // date
   "TheEVolk",                     // author
   "https://vk.com/elektro_volkts",            // url
   "LM",                  // logtag, all caps please
   PT_ANYTIME,                     // (when) loadable
   PT_ANYPAUSE                     // (when) unloadable
};

static META_FUNCTIONS gMetaFunctionTable =
{
   NULL,            // pfnGetEntityAPI            HL SDK; called before game DLL
   NULL,            // pfnGetEntityAPI_Post         META; called after game DLL
   GetEntityAPI2,            // pfnGetEntityAPI2            HL SDK2; called before game DLL
   NULL,            // pfnGetEntityAPI2_Post      META; called after game DLL
   NULL,            // pfnGetNewDLLFunctions      HL SDK2; called before game DLL
   NULL,            // pfnGetNewDLLFunctions_Post   META; called after game DLL
   GetEngineFunctions,   // pfnGetEngineFunctions      META; called before HL engine
   NULL            // pfnGetEngineFunctions_Post   META; called after HL engine
};

enginefuncs_t g_engfuncs;
globalvars_t  *gpGlobals;

#if defined _MSC_VER
   #pragma comment(linker, "/EXPORT:GiveFnptrsToDll=_GiveFnptrsToDll@8")
#endif

C_DLLEXPORT void WINAPI GiveFnptrsToDll(enginefuncs_t* pengfuncsFromEngine, globalvars_t *pGlobals)
{
   memcpy(&g_engfuncs, pengfuncsFromEngine, sizeof(enginefuncs_t));
   gpGlobals = pGlobals;
}

C_DLLEXPORT int GetEntityAPI2(DLL_FUNCTIONS *pFunctionTable, int *interfaceVersion)
{
	if (!pFunctionTable) {
		ALERT(at_logged, "%s called with null pFunctionTable", __FUNCTION__);
		return FALSE;
	}
	if (*interfaceVersion != INTERFACE_VERSION) {
		ALERT(at_logged, "%s version mismatch; requested=%d ours=%d", __FUNCTION__, *interfaceVersion, INTERFACE_VERSION);
		*interfaceVersion = INTERFACE_VERSION;
		return FALSE;
	}

	memcpy(pFunctionTable, &g_DllFunctionTable, sizeof(DLL_FUNCTIONS));
	return TRUE;
}

C_DLLEXPORT int Meta_Query(char *interfaceVersion, plugin_info_t **pinfo, mutil_funcs_t *pMetaUtilFuncs)
{
   *pinfo = &info;
   ALERT(at_console, "[LM]: meta_query\n");
   return(TRUE);
}

C_DLLEXPORT int Meta_Attach(PLUG_LOADTIME now, META_FUNCTIONS *pFunctionTable, meta_globals_t *pMGlobals, gamedll_funcs_t *pGamedllFuncs)
{

   if(!pFunctionTable)
   {
      return(FALSE);
   }


   memcpy(pFunctionTable, &gMetaFunctionTable, sizeof(META_FUNCTIONS));
   gpMetaGlobals = pMGlobals;
   //ALERT(at_console, "[LM]: Meta_Attach\n");
   attach();

   return(TRUE);
}

C_DLLEXPORT int Meta_Detach(PLUG_LOADTIME now, PL_UNLOAD_REASON reason)
{
   //ALERT(at_console, "[LM]: meta_detach\n");
   return(TRUE);
}

int fnPre(const char *s)
{
   //ALERT(at_console, "[LM]: model precaching\n");
   RETURN_META_VALUE(MRES_IGNORED, 0);
}

enginefuncs_t my_tracers =
{
   fnPre,                  // pfnPrecacheModel()
   NULL,                  // pfnPrecacheSound()
   NULL,                  // pfnSetModel()
   NULL,                  // pfnModelIndex()
   NULL,                  // pfnModelFrames()

   NULL,                  // pfnSetSize()
   NULL,                  // pfnChangeLevel()
   NULL,                  // pfnGetSpawnParms()
   NULL,                  // pfnSaveSpawnParms()

   NULL,                  // pfnVecToYaw()
   NULL,                  // pfnVecToAngles()
   NULL,                  // pfnMoveToOrigin()
   NULL,                  // pfnChangeYaw()
   NULL,                  // pfnChangePitch()

   NULL,                  // pfnFindEntityByString()
   NULL,                  // pfnGetEntityIllum()
   NULL,                  // pfnFindEntityInSphere()
   NULL,                  // pfnFindClientInPVS()
   NULL,                  // pfnEntitiesInPVS()

   NULL,                  // pfnMakeVectors()
   NULL,                  // pfnAngleVectors()

   NULL,                  // pfnCreateEntity()
   NULL,                  // pfnRemoveEntity()
   NULL,                  // pfnCreateNamedEntity()

   NULL,                  // pfnMakeStatic()
   NULL,                  // pfnEntIsOnFloor()
   NULL,                  // pfnDropToFloor()

   NULL,                  // pfnWalkMove()
   NULL,                  // pfnSetOrigin()

   NULL,                  // pfnEmitSound()
   NULL,                  // pfnEmitAmbientSound()

   NULL,                  // pfnTraceLine()
   NULL,                  // pfnTraceToss()
   NULL,                  // pfnTraceMonsterHull()
   NULL,                  // pfnTraceHull()
   NULL,                  // pfnTraceModel()
   NULL,                  // pfnTraceTexture()
   NULL,                  // pfnTraceSphere()
   NULL,                  // pfnGetAimVector()

   NULL,                  // pfnServerCommand()
   NULL,                  // pfnServerExecute()
   NULL,                  // pfnClientCommand()

   NULL,                  // pfnParticleEffect()
   NULL,                  // pfnLightStyle()
   NULL,                  // pfnDecalIndex()
   NULL,                  // pfnPointContents()

   NULL,                  // pfnMessageBegin()
   NULL,                  // pfnMessageEnd()

   NULL,                  // pfnWriteByte()
   NULL,                  // pfnWriteChar()
   NULL,                  // pfnWriteShort()
   NULL,                  // pfnWriteLong()
   NULL,                  // pfnWriteAngle()
   NULL,                  // pfnWriteCoord()
   NULL,                  // pfnWriteString()
   NULL,                  // pfnWriteEntity()

   NULL,                  // pfnCVarRegister()
   NULL,                  // pfnCVarGetFloat()
   NULL,                  // pfnCVarGetString()
   NULL,                  // pfnCVarSetFloat()
   NULL,                  // pfnCVarSetString()

   NULL,                  // pfnAlertMessage()
   NULL,                  // pfnEngineFprintf()

   NULL,                  // pfnPvAllocEntPrivateData()
   NULL,                  // pfnPvEntPrivateData()
   NULL,                  // pfnFreeEntPrivateData()

   NULL,                  // pfnSzFromIndex()
   NULL,                  // pfnAllocString()

   NULL,                   // pfnGetVarsOfEnt()
   NULL,                  // pfnPEntityOfEntOffset()
   NULL,                  // pfnEntOffsetOfPEntity()
   NULL,                  // pfnIndexOfEdict()
   NULL,                  // pfnPEntityOfEntIndex()
   NULL,                  // pfnFindEntityByVars()
   NULL,                  // pfnGetModelPtr()

   NULL,                  // pfnRegUserMsg()

   NULL,                  // pfnAnimationAutomove()
   NULL,                  // pfnGetBonePosition()

   NULL,                  // pfnFunctionFromName()
   NULL,                  // pfnNameForFunction()

   NULL,                  // pfnClientPrintf()
   NULL,                  // pfnServerPrint()

   NULL,                  // pfnCmd_Args()
   NULL,                  // pfnCmd_Argv()
   NULL,                  // pfnCmd_Argc()

   NULL,                  // pfnGetAttachment()

   NULL,                  // pfnCRC32_Init()
   NULL,                  // pfnCRC32_ProcessBuffer()
   NULL,                  // pfnCRC32_ProcessByte()
   NULL,                  // pfnCRC32_Final()

   NULL,                  // pfnRandomLong()
   NULL,                  // pfnRandomFloat()

   NULL,                  // pfnSetView()
   NULL,                  // pfnTime()
   NULL,                  // pfnCrosshairAngle()

   NULL,                  // pfnLoadFileForMe()
   NULL,                  // pfnFreeFile()

   NULL,                  // pfnEndSection()
   NULL,                  // pfnCompareFileTime()
   NULL,                  // pfnGetGameDir()
   NULL,                  // pfnCvar_RegisterVariable()
   NULL,                  // pfnFadeClientVolume()
   NULL,                  // pfnSetClientMaxspeed()
   NULL,                  // pfnCreateFakeClient()
   NULL,                  // pfnRunPlayerMove()
   NULL,                  // pfnNumberOfEntities()

   NULL,                  // pfnGetInfoKeyBuffer()
   NULL,                  // pfnInfoKeyValue()
   NULL,                  // pfnSetKeyValue()
   NULL,                  // pfnSetClientKeyValue()

   NULL,                  // pfnIsMapValid()
   NULL,                  // pfnStaticDecal()
   NULL,                  // pfnPrecacheGeneric()
   NULL,                   // pfnGetPlayerUserId()
   NULL,                  // pfnBuildSoundMsg()
   NULL,                  // pfnIsDedicatedServer()
   NULL,                  // pfnCVarGetPointer()
   NULL,                  // pfnGetPlayerWONId()

   NULL,                  // pfnInfo_RemoveKey()
   NULL,                  // pfnGetPhysicsKeyValue()
   NULL,                  // pfnSetPhysicsKeyValue()
   NULL,                  // pfnGetPhysicsInfoString()
   NULL,                  // pfnPrecacheEvent()
   NULL,                  // pfnPlaybackEvent()

   NULL,                  // pfnSetFatPVS()
   NULL,                  // pfnSetFatPAS()

   NULL,                  // pfnCheckVisibility()

   NULL,                  // pfnDeltaSetField()
   NULL,                  // pfnDeltaUnsetField()
   NULL,                  // pfnDeltaAddEncoder()
   NULL,                  // pfnGetCurrentPlayer()
   NULL,                  // pfnCanSkipPlayer()
   NULL,                  // pfnDeltaFindField()
   NULL,                  // pfnDeltaSetFieldByIndex()
   NULL,                  // pfnDeltaUnsetFieldByIndex()

   NULL,                  // pfnSetGroupMask()

   NULL,                  // pfnCreateInstancedBaseline()
   NULL,                  // pfnCvar_DirectSet()

   NULL,                  // pfnForceUnmodified()

   NULL,                  // pfnGetPlayerStats()

   NULL,                  // pfnAddServerCommand()

   NULL,                  // pfnVoice_GetClientListening()
   NULL,                  // pfnVoice_SetClientListening()

   NULL,                  // pfnGetPlayerAuthId()

   NULL,                  // pfnSequenceGet()
   NULL,                  // pfnSequencePickSentence()
   NULL,                  // pfnGetFileSize()
   NULL,                  // pfnGetApproxWavePlayLen()
   NULL,                  // pfnIsCareerMatch()
   NULL,                  // pfnGetLocalizedStringLength()
   NULL,                  // pfnRegisterTutorMessageShown()
   NULL,                  // pfnGetTimesTutorMessageShown()
   NULL,                  // pfnProcessTutorMessageDecayBuffer()
   NULL,                  // pfnConstructTutorMessageDecayBuffer()
   NULL,                  // pfnResetTutorMessageDecayData()
   NULL,                  // pfnQueryClientCvarValue()
   NULL,                  // pfnQueryClientCvarValue2()
};

C_DLLEXPORT int GetEngineFunctions(enginefuncs_t *pengfuncsFromEngine, int *interfaceVersion)
{
   if(!pengfuncsFromEngine)
   {
      return(FALSE);
   } else if(*interfaceVersion != ENGINE_INTERFACE_VERSION)
   {
      *interfaceVersion = ENGINE_INTERFACE_VERSION;
      return(FALSE);
   }

   memcpy(pengfuncsFromEngine, &my_tracers, sizeof(enginefuncs_t));

   return(TRUE);
}
