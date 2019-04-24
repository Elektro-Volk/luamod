#include "lu_engfuncs.hpp"
#include <extdll.h>
#include <meta_api.h>
#include <vector>

const float* mlua_tovec3(lua_State* L, int index)
{
    std::vector<float> origin;
    origin.reserve(3);

    lua_pushnil(L);
	while (lua_next(L, index))
	{
		lua_pushvalue(L, -1);
		origin.push_back(luaL_checknumber(L, -1));
		lua_pop(L, 2);
    }

    return origin.data();
}

void lu_engfuncs::init_api(lua_State *L)
{
    lua_register(L, "pfn_precache_model", l_pfnPrecacheModel);
    lua_register(L, "pfn_precache_sound", l_pfnPrecacheSound);
    lua_register(L, "pfn_set_model", l_pfnSetModel);
    lua_register(L, "pfn_model_index", l_pfnModelIndex);
    lua_register(L, "pfn_model_frames", l_pfnModelFrames);
    lua_register(L, "pfn_set_size", l_pfnSetSize);
    lua_register(L, "pfn_change_level", l_pfnChangeLevel);
    lua_register(L, "pfn_get_spawn_parms", l_pfnGetSpawnParms);
    lua_register(L, "pfn_save_spawn_parms", l_pfnSaveSpawnParms);
    lua_register(L, "pfn_vec_to_yaw", l_pfnVecToYaw);
    lua_register(L, "pfn_vec_to_angles", l_pfnVecToAngles);
    lua_register(L, "pfn_move_to_origin", l_pfnMoveToOrigin);
    lua_register(L, "pfn_change_yaw", l_pfnChangeYaw);
    lua_register(L, "pfn_change_pitch", l_pfnChangePitch);
    lua_register(L, "pfn_find_entity_by_string", l_pfnFindEntityByString);
    lua_register(L, "pfn_get_entity_illum", l_pfnGetEntityIllum);
    lua_register(L, "pfn_find_entity_in_sphere", l_pfnFindEntityInSphere);
    lua_register(L, "pfn_find_client_in_pvs", l_pfnFindClientInPVS);
    lua_register(L, "pfn_entities_in_pvs", l_pfnEntitiesInPVS);
    lua_register(L, "pfn_make_vectors", l_pfnMakeVectors);
    lua_register(L, "pfn_angle_vectors", l_pfnAngleVectors);
    lua_register(L, "pfn_create_entity", l_pfnCreateEntity);
    lua_register(L, "pfn_remove_entity", l_pfnRemoveEntity);
    lua_register(L, "pfn_create_named_entity", l_pfnCreateNamedEntity);
    lua_register(L, "pfn_make_static", l_pfnMakeStatic);
    lua_register(L, "pfn_ent_is_on_floor", l_pfnEntIsOnFloor);
    lua_register(L, "pfn_drop_to_floor", l_pfnDropToFloor);
    lua_register(L, "pfn_walk_move", l_pfnWalkMove);
    lua_register(L, "pfn_set_origin", l_pfnSetOrigin);
    lua_register(L, "pfn_emit_sound", l_pfnEmitSound);
    lua_register(L, "pfn_emit_ambient_sound", l_pfnEmitAmbientSound);
    lua_register(L, "pfn_trace_line", l_pfnTraceLine);
    lua_register(L, "pfn_trace_toss", l_pfnTraceToss);
    lua_register(L, "pfn_trace_monster_hull", l_pfnTraceMonsterHull);
    lua_register(L, "pfn_trace_hull", l_pfnTraceHull);
    lua_register(L, "pfn_trace_model", l_pfnTraceModel);
    lua_register(L, "pfn_trace_texture", l_pfnTraceTexture);
    lua_register(L, "pfn_trace_sphere", l_pfnTraceSphere);
    lua_register(L, "pfn_get_aim_vector", l_pfnGetAimVector);
    lua_register(L, "pfn_server_command", l_pfnServerCommand);
    lua_register(L, "pfn_server_execute", l_pfnServerExecute);
    lua_register(L, "pfn_client_command", l_pfnClientCommand);
    lua_register(L, "pfn_particle_effect", l_pfnParticleEffect);
    lua_register(L, "pfn_light_style", l_pfnLightStyle);
    lua_register(L, "pfn_decal_index", l_pfnDecalIndex);
    lua_register(L, "pfn_point_contents", l_pfnPointContents);
    lua_register(L, "pfn_message_begin", l_pfnMessageBegin);
    lua_register(L, "pfn_message_end", l_pfnMessageEnd);
    lua_register(L, "pfn_write_byte", l_pfnWriteByte);
    lua_register(L, "pfn_write_char", l_pfnWriteChar);
    lua_register(L, "pfn_write_short", l_pfnWriteShort);
    lua_register(L, "pfn_write_long", l_pfnWriteLong);
    lua_register(L, "pfn_write_angle", l_pfnWriteAngle);
    lua_register(L, "pfn_write_coord", l_pfnWriteCoord);
    lua_register(L, "pfn_write_string", l_pfnWriteString);
    lua_register(L, "pfn_write_entity", l_pfnWriteEntity);
    lua_register(L, "pfn_cvar_register", l_pfnCVarRegister);
    lua_register(L, "pfn_cvar_get_float", l_pfnCVarGetFloat);
    lua_register(L, "pfn_cvar_get_string", l_pfnCVarGetString);
    lua_register(L, "pfn_cvar_set_float", l_pfnCVarSetFloat);
    lua_register(L, "pfn_cvar_set_string", l_pfnCVarSetString);
    lua_register(L, "pfn_alert_message", l_pfnAlertMessage);
    lua_register(L, "pfn_engine_fprintf", l_pfnEngineFprintf);
    lua_register(L, "pfn_pv_alloc_ent_private_data", l_pfnPvAllocEntPrivateData);
    lua_register(L, "pfn_pv_ent_private_data", l_pfnPvEntPrivateData);
    lua_register(L, "pfn_free_ent_private_data", l_pfnFreeEntPrivateData);
    lua_register(L, "pfn_sz_from_index", l_pfnSzFromIndex);
    lua_register(L, "pfn_alloc_string", l_pfnAllocString);
    lua_register(L, "pfn_get_vars_of_ent", l_pfnGetVarsOfEnt);
    lua_register(L, "pfn_p_entity_of_ent_offset", l_pfnPEntityOfEntOffset);
    lua_register(L, "pfn_ent_offset_of_p_entity", l_pfnEntOffsetOfPEntity);
    lua_register(L, "pfn_index_of_edict", l_pfnIndexOfEdict);
    lua_register(L, "pfn_pentity_of_ent_index", l_pfnPEntityOfEntIndex);
    lua_register(L, "pfn_find_entity_by_vars", l_pfnFindEntityByVars);
    lua_register(L, "pfn_get_model_ptr", l_pfnGetModelPtr);
    lua_register(L, "pfn_reg_user_msg", l_pfnRegUserMsg);
    lua_register(L, "pfn_animation_automove", l_pfnAnimationAutomove);
    lua_register(L, "pfn_get_bone_position", l_pfnGetBonePosition);
    lua_register(L, "pfn_function_from_name", l_pfnFunctionFromName);
    lua_register(L, "pfn_name_for_function", l_pfnNameForFunction);
    lua_register(L, "pfn_client_printf", l_pfnClientPrintf);
    lua_register(L, "pfn_server_print", l_pfnServerPrint);
    lua_register(L, "pfn_cmd__args", l_pfnCmd_Args);
    lua_register(L, "pfn_cmd__argv", l_pfnCmd_Argv);
    lua_register(L, "pfn_cmd__argc", l_pfnCmd_Argc);
    lua_register(L, "pfn_get_attachment", l_pfnGetAttachment);
    /*lua_register(L, "pfn_crc32__init", l_pfnCRC32_Init);
    lua_register(L, "pfn_crc32__process_buffer", l_pfnCRC32_ProcessBuffer);
    lua_register(L, "pfn_crc32__process_byte", l_pfnCRC32_ProcessByte);
    lua_register(L, "pfn_crc32__final", l_pfnCRC32_Final);*/
    lua_register(L, "pfn_random_long", l_pfnRandomLong);
    lua_register(L, "pfn_random_float", l_pfnRandomFloat);
    lua_register(L, "pfn_set_view", l_pfnSetView);
    lua_register(L, "pfn_time", l_pfnTime);
    lua_register(L, "pfn_crosshair_angle", l_pfnCrosshairAngle);
    lua_register(L, "pfn_load_file_for_me", l_pfnLoadFileForMe);
    lua_register(L, "pfn_free_file", l_pfnFreeFile);
    lua_register(L, "pfn_end_section", l_pfnEndSection);
    lua_register(L, "pfn_compare_file_time", l_pfnCompareFileTime);
    lua_register(L, "pfn_get_game_dir", l_pfnGetGameDir);
    lua_register(L, "pfn_cvar__register_variable", l_pfnCvar_RegisterVariable);
    lua_register(L, "pfn_fade_client_volume", l_pfnFadeClientVolume);
    lua_register(L, "pfn_set_client_maxspeed", l_pfnSetClientMaxspeed);
    lua_register(L, "pfn_create_fake_client", l_pfnCreateFakeClient);
    lua_register(L, "pfn_run_player_move", l_pfnRunPlayerMove);
    lua_register(L, "pfn_number_of_entities", l_pfnNumberOfEntities);
    lua_register(L, "pfn_get_info_key_buffer", l_pfnGetInfoKeyBuffer);
    lua_register(L, "pfn_info_key_value", l_pfnInfoKeyValue);
    lua_register(L, "pfn_set_key_value", l_pfnSetKeyValue);
    lua_register(L, "pfn_set_client_key_value", l_pfnSetClientKeyValue);
    lua_register(L, "pfn_is_map_valid", l_pfnIsMapValid);
    lua_register(L, "pfn_static_decal", l_pfnStaticDecal);
    lua_register(L, "pfn_precache_generic", l_pfnPrecacheGeneric);
    lua_register(L, "pfn_get_player_user_id", l_pfnGetPlayerUserId);
    lua_register(L, "pfn_build_sound_msg", l_pfnBuildSoundMsg);
    lua_register(L, "pfn_is_dedicated_server", l_pfnIsDedicatedServer);
    lua_register(L, "pfn_cvar_get_pointer", l_pfnCVarGetPointer);
    lua_register(L, "pfn_get_player_won_id", l_pfnGetPlayerWONId);
    lua_register(L, "pfn_info__remove_key", l_pfnInfo_RemoveKey);
    lua_register(L, "pfn_get_physics_key_value", l_pfnGetPhysicsKeyValue);
    lua_register(L, "pfn_set_physics_key_value", l_pfnSetPhysicsKeyValue);
    lua_register(L, "pfn_get_physics_info_string", l_pfnGetPhysicsInfoString);
    lua_register(L, "pfn_precache_event", l_pfnPrecacheEvent);
    lua_register(L, "pfn_playback_event", l_pfnPlaybackEvent);
    lua_register(L, "pfn_set_fat_pvs", l_pfnSetFatPVS);
    lua_register(L, "pfn_set_fat_pas", l_pfnSetFatPAS);
    lua_register(L, "pfn_check_visibility ", l_pfnCheckVisibility );
    lua_register(L, "pfn_delta_set_field", l_pfnDeltaSetField);
    lua_register(L, "pfn_delta_unset_field", l_pfnDeltaUnsetField);
    lua_register(L, "pfn_delta_add_encoder", l_pfnDeltaAddEncoder);
    lua_register(L, "pfn_get_current_player", l_pfnGetCurrentPlayer);
    lua_register(L, "pfn_can_skip_player", l_pfnCanSkipPlayer);
    lua_register(L, "pfn_delta_find_field", l_pfnDeltaFindField);
    lua_register(L, "pfn_delta_set_field_by_index", l_pfnDeltaSetFieldByIndex);
    lua_register(L, "pfn_delta_unset_field_by_index", l_pfnDeltaUnsetFieldByIndex);
    lua_register(L, "pfn_set_group_mask", l_pfnSetGroupMask);
    lua_register(L, "pfn_create_instanced_baseline", l_pfnCreateInstancedBaseline);
    lua_register(L, "pfn_cvar__direct_set", l_pfnCvar_DirectSet);
    lua_register(L, "pfn_force_unmodified", l_pfnForceUnmodified);
    lua_register(L, "pfn_get_player_stats", l_pfnGetPlayerStats);
    lua_register(L, "pfn_add_server_command", l_pfnAddServerCommand);
    lua_register(L, "pfn_voice__get_client_listening", l_pfnVoice_GetClientListening);
    lua_register(L, "pfn_voice__set_client_listening", l_pfnVoice_SetClientListening);
    lua_register(L, "pfn_get_player_auth_id", l_pfnGetPlayerAuthId);
    lua_register(L, "pfn_sequence_get", l_pfnSequenceGet);
    lua_register(L, "pfn_sequence_pick_sentence", l_pfnSequencePickSentence);
    lua_register(L, "pfn_get_file_size", l_pfnGetFileSize);
    lua_register(L, "pfn_get_approx_wave_play_len", l_pfnGetApproxWavePlayLen);
    lua_register(L, "pfn_is_career_match", l_pfnIsCareerMatch);
    lua_register(L, "pfn_get_localized_string_length", l_pfnGetLocalizedStringLength);
    lua_register(L, "pfn_register_tutor_message_shown", l_pfnRegisterTutorMessageShown);
    lua_register(L, "pfn_get_times_tutor_message_shown", l_pfnGetTimesTutorMessageShown);
    lua_register(L, "pfn_process_tutor_message_decay_buffer", l_pfnProcessTutorMessageDecayBuffer);
    lua_register(L, "pfn_construct_tutor_message_decay_buffer", l_pfnConstructTutorMessageDecayBuffer);
    lua_register(L, "pfn_reset_tutor_message_decay_data", l_pfnResetTutorMessageDecayData);
    lua_register(L, "pfn_query_client_cvar_value", l_pfnQueryClientCvarValue);
    lua_register(L, "pfn_query_client_cvar_value2", l_pfnQueryClientCvarValue2);
    //lua_register(L, "check_parm", l_CheckParm);

    // TODO: move to dllfuncs
    lua_register(L, "spawn", l_pfnSpawn);
}

int lu_engfuncs::l_pfnSpawn(lua_State *L)
{
    gpGamedllFuncs->dllapi_table->pfnSpawn((edict_t*)lua_touserdata(L, 1));
	return 0;
}

// int(*pfnPrecacheModel)( char* s );
int lu_engfuncs::l_pfnPrecacheModel(lua_State *L)
{
    char* l_s = const_cast<char*>(lua_tostring(L, 1));
    lua_pushinteger(L, (*g_engfuncs.pfnPrecacheModel)(l_s));
    return 1;
}

// int(*pfnPrecacheSound)( char* s );
int lu_engfuncs::l_pfnPrecacheSound(lua_State *L)
{
    char* l_s = const_cast<char*>(lua_tostring(L, 1));
    lua_pushinteger(L, (*g_engfuncs.pfnPrecacheSound)(l_s));
    return 1;
}

// void(*pfnSetModel)( edict_t *e, const char *m );
int lu_engfuncs::l_pfnSetModel(lua_State *L)
{
    edict_t *l_e = (edict_t*)lua_touserdata(L, 1);
    const char *l_m = lua_tostring(L, 2);
    (*g_engfuncs.pfnSetModel)(l_e, l_m);
    return 0;
}

// int(*pfnModelIndex)( const char *m );
int lu_engfuncs::l_pfnModelIndex(lua_State *L)
{
    const char *l_m = lua_tostring(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnModelIndex)(l_m));
    return 1;
}

// int(*pfnModelFrames)( int modelIndex );
int lu_engfuncs::l_pfnModelFrames(lua_State *L)
{
    int l_modelIndex = lua_tointeger(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnModelFrames)(l_modelIndex));
    return 1;
}

// void(*pfnSetSize)( edict_t *e, const float *rgflMin, const float *rgflMax );
int lu_engfuncs::l_pfnSetSize(lua_State *L)
{
    edict_t *l_e = (edict_t*)lua_touserdata(L, 1);
    const float *l_rgflMin = mlua_tovec3(L, 2);
    const float *l_rgflMax = mlua_tovec3(L, 3);
    (*g_engfuncs.pfnSetSize)(l_e, l_rgflMin, l_rgflMax);
    return 0;
}

// void(*pfnChangeLevel)( char* s1, char* s2 );
int lu_engfuncs::l_pfnChangeLevel(lua_State *L)
{
    char* l_s1 = const_cast<char*>(lua_tostring(L, 1));
    char* l_s2 = const_cast<char*>(lua_tostring(L, 2));
    (*g_engfuncs.pfnChangeLevel)(l_s1, l_s2);
    return 0;
}

// void(*pfnGetSpawnParms)( edict_t *ent );
int lu_engfuncs::l_pfnGetSpawnParms(lua_State *L)
{
    edict_t *l_ent = (edict_t*)lua_touserdata(L, 1);
    (*g_engfuncs.pfnGetSpawnParms)(l_ent);
    return 0;
}

// void(*pfnSaveSpawnParms)( edict_t *ent );
int lu_engfuncs::l_pfnSaveSpawnParms(lua_State *L)
{
    edict_t *l_ent = (edict_t*)lua_touserdata(L, 1);
    (*g_engfuncs.pfnSaveSpawnParms)(l_ent);
    return 0;
}

// float(*pfnVecToYaw)( const float *rgflVector );
int lu_engfuncs::l_pfnVecToYaw(lua_State *L)
{
    const float *l_rgflVector = mlua_tovec3(L, 1);
    lua_pushnumber(L, (*g_engfuncs.pfnVecToYaw)(l_rgflVector));
    return 1;
}

// void(*pfnVecToAngles)( const float *rgflVectorIn, float *rgflVectorOut );
int lu_engfuncs::l_pfnVecToAngles(lua_State *L)
{
    /*const float *l_rgflVectorIn = mlua_tovec3(L, 1);
    float *l_rgflVectorOut = lua_tonumber(L, 2);
    (*g_engfuncs.pfnVecToAngles)(l_rgflVectorIn, *l_rgflVectorOut);
    return 0;*/

    return 0; // TODO
}

// void(*pfnMoveToOrigin)( edict_t *ent, const float *pflGoal, float dist, int iMoveType );
int lu_engfuncs::l_pfnMoveToOrigin(lua_State *L)
{
    edict_t *l_ent = (edict_t*)lua_touserdata(L, 1);
    const float *l_pflGoal = mlua_tovec3(L, 2);
    float l_dist = lua_tonumber(L, 3);
    int l_iMoveType = lua_tointeger(L, 4);
    (*g_engfuncs.pfnMoveToOrigin)(l_ent, l_pflGoal, l_dist, l_iMoveType);
    return 0;
}

// void(*pfnChangeYaw)( edict_t* ent );
int lu_engfuncs::l_pfnChangeYaw(lua_State *L)
{
    edict_t* l_ent = (edict_t*)lua_touserdata(L, 1);
    (*g_engfuncs.pfnChangeYaw)(l_ent);
    return 0;
}

// void(*pfnChangePitch)( edict_t* ent );
int lu_engfuncs::l_pfnChangePitch(lua_State *L)
{
    edict_t* l_ent = (edict_t*)lua_touserdata(L, 1);
    (*g_engfuncs.pfnChangePitch)(l_ent);
    return 0;
}

// edict_t*(*pfnFindEntityByString)( edict_t *pEdictStartSearchAfter, const char *pszField, const char *pszValue );
int lu_engfuncs::l_pfnFindEntityByString(lua_State *L)
{
    edict_t *l_pEdictStartSearchAfter = (edict_t*)lua_touserdata(L, 1);
    const char *l_pszField = lua_tostring(L, 2);
    const char *l_pszValue = lua_tostring(L, 3);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnFindEntityByString)(l_pEdictStartSearchAfter, l_pszField, l_pszValue));
    return 1;
}

// int(*pfnGetEntityIllum)( edict_t* pEnt );
int lu_engfuncs::l_pfnGetEntityIllum(lua_State *L)
{
    edict_t* l_pEnt = (edict_t*)lua_touserdata(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnGetEntityIllum)(l_pEnt));
    return 1;
}

// edict_t*(*pfnFindEntityInSphere)( edict_t *pEdictStartSearchAfter, const float *org, float rad );
int lu_engfuncs::l_pfnFindEntityInSphere(lua_State *L)
{
    edict_t *l_pEdictStartSearchAfter = (edict_t*)lua_touserdata(L, 1);
    const float *l_org = mlua_tovec3(L, 2);
    float l_rad = lua_tonumber(L, 3);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnFindEntityInSphere)(l_pEdictStartSearchAfter, l_org, l_rad));
    return 1;
}

// edict_t*(*pfnFindClientInPVS)( edict_t *pEdict );
int lu_engfuncs::l_pfnFindClientInPVS(lua_State *L)
{
    edict_t *l_pEdict = (edict_t*)lua_touserdata(L, 1);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnFindClientInPVS)(l_pEdict));
    return 1;
}

// edict_t*(*pfnEntitiesInPVS)( edict_t *pplayer );
int lu_engfuncs::l_pfnEntitiesInPVS(lua_State *L)
{
    edict_t *l_pplayer = (edict_t*)lua_touserdata(L, 1);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnEntitiesInPVS)(l_pplayer));
    return 1;
}

// void(*pfnMakeVectors)( const float *rgflVector );
int lu_engfuncs::l_pfnMakeVectors(lua_State *L)
{
    const float *l_rgflVector = mlua_tovec3(L, 1);
    (*g_engfuncs.pfnMakeVectors)(l_rgflVector);
    return 0;
}

// void(*pfnAngleVectors)( const float *rgflVector, float *forward, float *right, float *up );
int lu_engfuncs::l_pfnAngleVectors(lua_State *L)
{
    /*const float *l_rgflVector = mlua_tovec3(L, 1);
    float *l_forward = lua_tonumber(L, 2);
    float *l_right = lua_tonumber(L, 3);
    float *l_up = lua_tonumber(L, 4);
    (*g_engfuncs.pfnAngleVectors)(l_rgflVector, *l_forward, *l_right, *l_up);
    return 0;*/

    return 0; // TODO
}

// edict_t*(*pfnCreateEntity)( void );
int lu_engfuncs::l_pfnCreateEntity(lua_State *L)
{
    lua_pushlightuserdata(L, (*g_engfuncs.pfnCreateEntity)());
    return 1;
}

// void(*pfnRemoveEntity)( edict_t* e );
int lu_engfuncs::l_pfnRemoveEntity(lua_State *L)
{
    edict_t* l_e = (edict_t*)lua_touserdata(L, 1);
    (*g_engfuncs.pfnRemoveEntity)(l_e);
    return 0;
}

// edict_t*(*pfnCreateNamedEntity)( int className );
int lu_engfuncs::l_pfnCreateNamedEntity(lua_State *L)
{
    int l_className = lua_tointeger(L, 1);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnCreateNamedEntity)(l_className));
    return 1;
}

// void(*pfnMakeStatic)( edict_t *ent );
int lu_engfuncs::l_pfnMakeStatic(lua_State *L)
{
    edict_t *l_ent = (edict_t*)lua_touserdata(L, 1);
    (*g_engfuncs.pfnMakeStatic)(l_ent);
    return 0;
}

// int(*pfnEntIsOnFloor)( edict_t *e );
int lu_engfuncs::l_pfnEntIsOnFloor(lua_State *L)
{
    edict_t *l_e = (edict_t*)lua_touserdata(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnEntIsOnFloor)(l_e));
    return 1;
}

// int(*pfnDropToFloor)( edict_t* e );
int lu_engfuncs::l_pfnDropToFloor(lua_State *L)
{
    edict_t* l_e = (edict_t*)lua_touserdata(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnDropToFloor)(l_e));
    return 1;
}

// int(*pfnWalkMove)( edict_t *ent, float yaw, float dist, int iMode );
int lu_engfuncs::l_pfnWalkMove(lua_State *L)
{
    edict_t *l_ent = (edict_t*)lua_touserdata(L, 1);
    float l_yaw = lua_tonumber(L, 2);
    float l_dist = lua_tonumber(L, 3);
    int l_iMode = lua_tointeger(L, 4);
    lua_pushinteger(L, (*g_engfuncs.pfnWalkMove)(l_ent, l_yaw, l_dist, l_iMode));
    return 1;
}

// void(*pfnSetOrigin)( edict_t *e, const float *rgflOrigin );
int lu_engfuncs::l_pfnSetOrigin(lua_State *L)
{
    edict_t *l_e = (edict_t*)lua_touserdata(L, 1);
    const float *l_rgflOrigin = mlua_tovec3(L, 2);
    (*g_engfuncs.pfnSetOrigin)(l_e, l_rgflOrigin);
    return 0;
}

// void(*pfnEmitSound)( edict_t *entity, int channel, const char *sample, float volume, float attenuation, int fFlags, int pitch );
int lu_engfuncs::l_pfnEmitSound(lua_State *L)
{
    edict_t *l_entity = (edict_t*)lua_touserdata(L, 1);
    int l_channel = lua_tointeger(L, 2);
    const char *l_sample = lua_tostring(L, 3);
    float l_volume = lua_tonumber(L, 4);
    float l_attenuation = lua_tonumber(L, 5);
    int l_fFlags = lua_tointeger(L, 6);
    int l_pitch = lua_tointeger(L, 7);
    (*g_engfuncs.pfnEmitSound)(l_entity, l_channel, l_sample, l_volume, l_attenuation, l_fFlags, l_pitch);
    return 0;
}

// void(*pfnEmitAmbientSound)( edict_t *entity, float *pos, const char *samp, float vol, float attenuation, int fFlags, int pitch );
int lu_engfuncs::l_pfnEmitAmbientSound(lua_State *L)
{
    /*edict_t *l_entity = (edict_t*)lua_touserdata(L, 1);
    float *l_pos = lua_tonumber(L, 2);
    const char *l_samp = lua_tostring(L, 3);
    float l_vol = lua_tonumber(L, 4);
    float l_attenuation = lua_tonumber(L, 5);
    int l_fFlags = lua_tointeger(L, 6);
    int l_pitch = lua_tointeger(L, 7);
    (*g_engfuncs.pfnEmitAmbientSound)(l_entity, *l_pos, l_samp, l_vol, l_attenuation, l_fFlags, l_pitch);
    return 0;*/

    return 0; //TODO
}

// void(*pfnTraceLine)( const float *v1, const float *v2, int fNoMonsters, edict_t *pentToSkip, TraceResult *ptr );
int lu_engfuncs::l_pfnTraceLine(lua_State *L)
{
    const float *l_v1 = mlua_tovec3(L, 1);
    const float *l_v2 = mlua_tovec3(L, 2);
    int l_fNoMonsters = lua_tointeger(L, 3);
    edict_t *l_pentToSkip = (edict_t*)lua_touserdata(L, 4);
    TraceResult *l_ptr = (TraceResult*)lua_touserdata(L, 5);
    (*g_engfuncs.pfnTraceLine)(l_v1, l_v2, l_fNoMonsters, l_pentToSkip, l_ptr);
    return 0;
}

// void(*pfnTraceToss)( edict_t* pent, edict_t* pentToIgnore, TraceResult *ptr );
int lu_engfuncs::l_pfnTraceToss(lua_State *L)
{
    edict_t* l_pent = (edict_t*)lua_touserdata(L, 1);
    edict_t* l_pentToIgnore = (edict_t*)lua_touserdata(L, 2);
    TraceResult *l_ptr = (TraceResult*)lua_touserdata(L, 3);
    (*g_engfuncs.pfnTraceToss)(l_pent, l_pentToIgnore, l_ptr);
    return 0;
}

// int(*pfnTraceMonsterHull)( edict_t *pEdict, const float *v1, const float *v2, int fNoMonsters, edict_t *pentToSkip, TraceResult *ptr );
int lu_engfuncs::l_pfnTraceMonsterHull(lua_State *L)
{
    edict_t *l_pEdict = (edict_t*)lua_touserdata(L, 1);
    const float *l_v1 = mlua_tovec3(L, 2);
    const float *l_v2 = mlua_tovec3(L, 3);
    int l_fNoMonsters = lua_tointeger(L, 4);
    edict_t *l_pentToSkip = (edict_t*)lua_touserdata(L, 5);
    TraceResult *l_ptr = (TraceResult*)lua_touserdata(L, 6);
    lua_pushinteger(L, (*g_engfuncs.pfnTraceMonsterHull)(l_pEdict, l_v1, l_v2, l_fNoMonsters, l_pentToSkip, l_ptr));
    return 1;
}

// void(*pfnTraceHull)( const float *v1, const float *v2, int fNoMonsters, int hullNumber, edict_t *pentToSkip, TraceResult *ptr );
int lu_engfuncs::l_pfnTraceHull(lua_State *L)
{
    const float *l_v1 = mlua_tovec3(L, 1);
    const float *l_v2 = mlua_tovec3(L, 2);
    int l_fNoMonsters = lua_tointeger(L, 3);
    int l_hullNumber = lua_tointeger(L, 4);
    edict_t *l_pentToSkip = (edict_t*)lua_touserdata(L, 5);
    TraceResult *l_ptr = (TraceResult*)lua_touserdata(L, 6);
    (*g_engfuncs.pfnTraceHull)(l_v1, l_v2, l_fNoMonsters, l_hullNumber, l_pentToSkip, l_ptr);
    return 0;
}

// void(*pfnTraceModel)( const float *v1, const float *v2, int hullNumber, edict_t *pent, TraceResult *ptr );
int lu_engfuncs::l_pfnTraceModel(lua_State *L)
{
    const float *l_v1 = mlua_tovec3(L, 1);
    const float *l_v2 = mlua_tovec3(L, 2);
    int l_hullNumber = lua_tointeger(L, 3);
    edict_t *l_pent = (edict_t*)lua_touserdata(L, 4);
    TraceResult *l_ptr = (TraceResult*)lua_touserdata(L, 5);
    (*g_engfuncs.pfnTraceModel)(l_v1, l_v2, l_hullNumber, l_pent, l_ptr);
    return 0;
}

// const char *(*pfnTraceTexture)( edict_t *pTextureEntity, const float *v1, const float *v2 );
int lu_engfuncs::l_pfnTraceTexture(lua_State *L)
{
    edict_t *l_pTextureEntity = (edict_t*)lua_touserdata(L, 1);
    const float *l_v1 = mlua_tovec3(L, 2);
    const float *l_v2 = mlua_tovec3(L, 3);
    lua_pushstring(L, (*g_engfuncs.pfnTraceTexture)(l_pTextureEntity, l_v1, l_v2));
    return 1;
}

// void(*pfnTraceSphere)( const float *v1, const float *v2, int fNoMonsters, float radius, edict_t *pentToSkip, TraceResult *ptr );
int lu_engfuncs::l_pfnTraceSphere(lua_State *L)
{
    const float *l_v1 = mlua_tovec3(L, 1);
    const float *l_v2 = mlua_tovec3(L, 2);
    int l_fNoMonsters = lua_tointeger(L, 3);
    float l_radius = lua_tonumber(L, 4);
    edict_t *l_pentToSkip = (edict_t*)lua_touserdata(L, 5);
    TraceResult *l_ptr = (TraceResult*)lua_touserdata(L, 6);
    (*g_engfuncs.pfnTraceSphere)(l_v1, l_v2, l_fNoMonsters, l_radius, l_pentToSkip, l_ptr);
    return 0;
}

// void(*pfnGetAimVector)( edict_t* ent, float speed, float *rgflReturn );
int lu_engfuncs::l_pfnGetAimVector(lua_State *L)
{
    /*edict_t* l_ent = (edict_t*)lua_touserdata(L, 1);
    float l_speed = lua_tonumber(L, 2);
    float *l_rgflReturn = lua_tonumber(L, 3);
    (*g_engfuncs.pfnGetAimVector)(l_ent, l_speed, *l_rgflReturn);*/
    return 0; // TODO
}

// void(*pfnServerCommand)( char* str );
int lu_engfuncs::l_pfnServerCommand(lua_State *L)
{
    char* l_str = const_cast<char*>(lua_tostring(L, 1));
    (*g_engfuncs.pfnServerCommand)(l_str);
    return 0;
}

// void(*pfnServerExecute)( void );
int lu_engfuncs::l_pfnServerExecute(lua_State *L)
{
    (*g_engfuncs.pfnServerExecute)();
    return 0;
}

// void(*pfnClientCommand)( edict_t* pEdict, char* szFmt, ... );
int lu_engfuncs::l_pfnClientCommand(lua_State *L)
{
    edict_t* l_pEdict = (edict_t*)lua_touserdata(L, 1);
    char* l_szFmt = const_cast<char*>(lua_tostring(L, 2));
    //...l_ = TODOARGS
    (*g_engfuncs.pfnClientCommand)(l_pEdict, l_szFmt);//, l_);
    return 0;
}

// void(*pfnParticleEffect)( const float *org, const float *dir, float color, float count );
int lu_engfuncs::l_pfnParticleEffect(lua_State *L)
{
    const float *l_org = mlua_tovec3(L, 1);
    const float *l_dir = mlua_tovec3(L, 2);
    float l_color = lua_tonumber(L, 3);
    float l_count = lua_tonumber(L, 4);
    (*g_engfuncs.pfnParticleEffect)(l_org, l_dir, l_color, l_count);
    return 0;
}

// void(*pfnLightStyle)( int style, char* val );
int lu_engfuncs::l_pfnLightStyle(lua_State *L)
{
    int l_style = lua_tointeger(L, 1);
    char* l_val = const_cast<char*>(lua_tostring(L, 2));
    (*g_engfuncs.pfnLightStyle)(l_style, l_val);
    return 0;
}

// int(*pfnDecalIndex)( const char *name );
int lu_engfuncs::l_pfnDecalIndex(lua_State *L)
{
    const char *l_name = lua_tostring(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnDecalIndex)(l_name));
    return 1;
}

// int(*pfnPointContents)( const float *rgflVector );
int lu_engfuncs::l_pfnPointContents(lua_State *L)
{
    const float *l_rgflVector = mlua_tovec3(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnPointContents)(l_rgflVector));
    return 1;
}

// void(*pfnMessageBegin)( int msg_dest, int msg_type, const float *pOrigin, edict_t *ed );
int lu_engfuncs::l_pfnMessageBegin(lua_State *L)
{
    int l_msg_dest = lua_tointeger(L, 1);
    int l_msg_type = lua_tointeger(L, 2);
    const float *l_pOrigin = mlua_tovec3(L, 3);
    edict_t *l_ed = (edict_t*)lua_touserdata(L, 4);
    (*g_engfuncs.pfnMessageBegin)(l_msg_dest, l_msg_type, l_pOrigin, l_ed);
    return 0;
}

// void(*pfnMessageEnd)( void );
int lu_engfuncs::l_pfnMessageEnd(lua_State *L)
{
    (*g_engfuncs.pfnMessageEnd)();
    return 0;
}

// void(*pfnWriteByte)( int iValue );
int lu_engfuncs::l_pfnWriteByte(lua_State *L)
{
    int l_iValue = lua_tointeger(L, 1);
    (*g_engfuncs.pfnWriteByte)(l_iValue);
    return 0;
}

// void(*pfnWriteChar)( int iValue );
int lu_engfuncs::l_pfnWriteChar(lua_State *L)
{
    int l_iValue = lua_tointeger(L, 1);
    (*g_engfuncs.pfnWriteChar)(l_iValue);
    return 0;
}

// void(*pfnWriteShort)( int iValue );
int lu_engfuncs::l_pfnWriteShort(lua_State *L)
{
    int l_iValue = lua_tointeger(L, 1);
    (*g_engfuncs.pfnWriteShort)(l_iValue);
    return 0;
}

// void(*pfnWriteLong)( int iValue );
int lu_engfuncs::l_pfnWriteLong(lua_State *L)
{
    int l_iValue = lua_tointeger(L, 1);
    (*g_engfuncs.pfnWriteLong)(l_iValue);
    return 0;
}

// void(*pfnWriteAngle)( float flValue );
int lu_engfuncs::l_pfnWriteAngle(lua_State *L)
{
    float l_flValue = lua_tonumber(L, 1);
    (*g_engfuncs.pfnWriteAngle)(l_flValue);
    return 0;
}

// void(*pfnWriteCoord)( float flValue );
int lu_engfuncs::l_pfnWriteCoord(lua_State *L)
{
    float l_flValue = lua_tonumber(L, 1);
    (*g_engfuncs.pfnWriteCoord)(l_flValue);
    return 0;
}

// void(*pfnWriteString)( const char *sz );
int lu_engfuncs::l_pfnWriteString(lua_State *L)
{
    const char *l_sz = lua_tostring(L, 1);
    (*g_engfuncs.pfnWriteString)(l_sz);
    return 0;
}

// void(*pfnWriteEntity)( int iValue );
int lu_engfuncs::l_pfnWriteEntity(lua_State *L)
{
    int l_iValue = lua_tointeger(L, 1);
    (*g_engfuncs.pfnWriteEntity)(l_iValue);
    return 0;
}

// void(*pfnCVarRegister)( cvar_t *pCvar );
int lu_engfuncs::l_pfnCVarRegister(lua_State *L)
{
    cvar_t *l_pCvar = new cvar_t({ luaL_checkstring(L, 1), (char*)luaL_checkstring(L, 2) });
    (*g_engfuncs.pfnCVarRegister)(l_pCvar);
    return 0;
}

// float(*pfnCVarGetFloat)( const char *szVarName );
int lu_engfuncs::l_pfnCVarGetFloat(lua_State *L)
{
    const char *l_szVarName = lua_tostring(L, 1);
    lua_pushnumber(L, (*g_engfuncs.pfnCVarGetFloat)(l_szVarName));
    return 1;
}

// const char* (*pfnCVarGetString)( const char *szVarName );
int lu_engfuncs::l_pfnCVarGetString(lua_State *L)
{
    const char *l_szVarName = lua_tostring(L, 1);
    lua_pushstring(L, (*g_engfuncs.pfnCVarGetString)(l_szVarName));
    return 1;
}

// void(*pfnCVarSetFloat)( const char *szVarName, float flValue );
int lu_engfuncs::l_pfnCVarSetFloat(lua_State *L)
{
    const char *l_szVarName = lua_tostring(L, 1);
    float l_flValue = lua_tonumber(L, 2);
    (*g_engfuncs.pfnCVarSetFloat)(l_szVarName, l_flValue);
    return 0;
}

// void(*pfnCVarSetString)( const char *szVarName, const char *szValue );
int lu_engfuncs::l_pfnCVarSetString(lua_State *L)
{
    const char *l_szVarName = lua_tostring(L, 1);
    const char *l_szValue = lua_tostring(L, 2);
    (*g_engfuncs.pfnCVarSetString)(l_szVarName, l_szValue);
    return 0;
}


// void(*pfnAlertMessage)( ALERT_TYPE atype, char *szFmt, ... );
int lu_engfuncs::l_pfnAlertMessage(lua_State *L)
{
    ALERT_TYPE  l_atype = (ALERT_TYPE)lua_tointeger(L, 1);
    char * l_szFmt = const_cast<char*>(lua_tostring(L, 2));
    //... l_ = TODOARGS
    (*g_engfuncs.pfnAlertMessage)(l_atype, l_szFmt);//, l_);
    return 0;
}

// void(*pfnEngineFprintf)( FILE *pfile, char *szFmt, ... );
int lu_engfuncs::l_pfnEngineFprintf(lua_State *L)
{
    /*FILE * l_pfile = (FILE*)lua_touserdata(L, 1);
    char * l_szFmt = lua_tostring(L, 2);
    ... l_ = TODOARGS
    (*g_engfuncs.pfnEngineFprintf)(l_pfile, l_szFmt, l_);
    return 0;*/

    return 0; // TODO
}

// void*(*pfnPvAllocEntPrivateData)( edict_t *pEdict, long cb );
int lu_engfuncs::l_pfnPvAllocEntPrivateData(lua_State *L)
{
    edict_t * l_pEdict = (edict_t*)lua_touserdata(L, 1);
    long  l_cb = lua_tointeger(L, 2);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnPvAllocEntPrivateData)(l_pEdict, l_cb));
    return 1;
}

// void*(*pfnPvEntPrivateData)( edict_t *pEdict );
int lu_engfuncs::l_pfnPvEntPrivateData(lua_State *L)
{
    edict_t * l_pEdict = (edict_t*)lua_touserdata(L, 1);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnPvEntPrivateData)(l_pEdict));
    return 1;
}

// void(*pfnFreeEntPrivateData)( edict_t *pEdict );
int lu_engfuncs::l_pfnFreeEntPrivateData(lua_State *L)
{
    edict_t * l_pEdict = (edict_t*)lua_touserdata(L, 1);
    (*g_engfuncs.pfnFreeEntPrivateData)(l_pEdict);
    return 0;
}

// const char *(*pfnSzFromIndex)( int iString );
int lu_engfuncs::l_pfnSzFromIndex(lua_State *L)
{
    int  l_iString = lua_tointeger(L, 1);
    lua_pushstring(L, (*g_engfuncs.pfnSzFromIndex)(l_iString));
    return 1;
}

// int(*pfnAllocString)( const char *szValue );
int lu_engfuncs::l_pfnAllocString(lua_State *L)
{
    const char * l_szValue = lua_tostring(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnAllocString)(l_szValue));
    return 1;
}

// struct entvars_s *(*pfnGetVarsOfEnt)( edict_t *pEdict );
int lu_engfuncs::l_pfnGetVarsOfEnt(lua_State *L)
{
    edict_t * l_pEdict = (edict_t*)lua_touserdata(L, 1);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnGetVarsOfEnt)(l_pEdict));
    return 1;
}

// edict_t*(*pfnPEntityOfEntOffset)( int iEntOffset );
int lu_engfuncs::l_pfnPEntityOfEntOffset(lua_State *L)
{
    int  l_iEntOffset = lua_tointeger(L, 1);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnPEntityOfEntOffset)(l_iEntOffset));
    return 1;
}

// int(*pfnEntOffsetOfPEntity)( const edict_t *pEdict );
int lu_engfuncs::l_pfnEntOffsetOfPEntity(lua_State *L)
{
    const edict_t * l_pEdict = (edict_t*)lua_touserdata(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnEntOffsetOfPEntity)(l_pEdict));
    return 1;
}

// int(*pfnIndexOfEdict)( const edict_t *pEdict );
int lu_engfuncs::l_pfnIndexOfEdict(lua_State *L)
{
    const edict_t * l_pEdict = (edict_t*)lua_touserdata(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnIndexOfEdict)(l_pEdict));
    return 1;
}

// edict_t*(*pfnPEntityOfEntIndex)( int iEntIndex );
int lu_engfuncs::l_pfnPEntityOfEntIndex(lua_State *L)
{
    int  l_iEntIndex = lua_tointeger(L, 1);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnPEntityOfEntIndex)(l_iEntIndex));
    return 1;
}

// edict_t*(*pfnFindEntityByVars)( struct entvars_s* pvars );
int lu_engfuncs::l_pfnFindEntityByVars(lua_State *L)
{
    struct entvars_s*  l_pvars = (entvars_s*)lua_touserdata(L, 1);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnFindEntityByVars)(l_pvars));
    return 1;
}

// void*(*pfnGetModelPtr)( edict_t* pEdict );
int lu_engfuncs::l_pfnGetModelPtr(lua_State *L)
{
    edict_t*  l_pEdict = (edict_t*)lua_touserdata(L, 1);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnGetModelPtr)(l_pEdict));
    return 1;
}

// int(*pfnRegUserMsg)( const char *pszName, int iSize );
int lu_engfuncs::l_pfnRegUserMsg(lua_State *L)
{
    const char * l_pszName = lua_tostring(L, 1);
    int  l_iSize = lua_tointeger(L, 2);
    lua_pushinteger(L, (*g_engfuncs.pfnRegUserMsg)(l_pszName, l_iSize));
    return 1;
}

// void(*pfnAnimationAutomove)( const edict_t* pEdict, float flTime );
int lu_engfuncs::l_pfnAnimationAutomove(lua_State *L)
{
    const edict_t*  l_pEdict = (edict_t*)lua_touserdata(L, 1);
    float  l_flTime = lua_tonumber(L, 2);
    (*g_engfuncs.pfnAnimationAutomove)(l_pEdict, l_flTime);
    return 0;
}

// void(*pfnGetBonePosition)( const edict_t* pEdict, int iBone, float *rgflOrigin, float *rgflAngles );
int lu_engfuncs::l_pfnGetBonePosition(lua_State *L)
{
    /*const edict_t*  l_pEdict = (edict_t*)lua_touserdata(L, 1);
    int  l_iBone = lua_tointeger(L, 2);
    float  *l_rgflOrigin = lua_tonumber(L, 3);
    float  *l_rgflAngles = lua_tonumber(L, 4);
    (*g_engfuncs.pfnGetBonePosition)(l_pEdict, l_iBone, *l_rgflOrigin, *l_rgflAngles);
    return 0;*/

    return 0; // TODO
}

// unsigned long (*pfnFunctionFromName)( const char *pName );
int lu_engfuncs::l_pfnFunctionFromName(lua_State *L)
{
    const char * l_pName = lua_tostring(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnFunctionFromName)(l_pName));
    return 1;
}

// const char *(*pfnNameForFunction)( unsigned long function );
int lu_engfuncs::l_pfnNameForFunction(lua_State *L)
{
    unsigned long  l_function = lua_tointeger(L, 1);
    lua_pushstring(L, (*g_engfuncs.pfnNameForFunction)(l_function));
    return 1;
}

// void(*pfnClientPrintf)( edict_t* pEdict, PRINT_TYPE ptype, const char *szMsg ); // JOHN: engine callbacks so game DLL can print messages to individual clients
int lu_engfuncs::l_pfnClientPrintf(lua_State *L)
{
    edict_t*  l_pEdict = (edict_t*)lua_touserdata(L, 1);
    PRINT_TYPE  l_ptype = (PRINT_TYPE)lua_tointeger(L, 2);
    const char * l_szMsg = lua_tostring(L, 3);
    (*g_engfuncs.pfnClientPrintf)(l_pEdict, l_ptype, l_szMsg);
    return 0;
}

// void(*pfnServerPrint)( const char *szMsg );
int lu_engfuncs::l_pfnServerPrint(lua_State *L)
{
    const char * l_szMsg = lua_tostring(L, 1);
    (*g_engfuncs.pfnServerPrint)(l_szMsg);
    return 0;
}

// const char *(*pfnCmd_Args)( void );// these 3 added
int lu_engfuncs::l_pfnCmd_Args(lua_State *L)
{
    lua_pushstring(L, (*g_engfuncs.pfnCmd_Args)());
    return 1;
}

// const char *(*pfnCmd_Argv)( int argc );// so game DLL can easily
int lu_engfuncs::l_pfnCmd_Argv(lua_State *L)
{
    int  l_argc = lua_tointeger(L, 1);
    lua_pushstring(L, (*g_engfuncs.pfnCmd_Argv)(l_argc));
    return 1;
}

// int(*pfnCmd_Argc)( void );// access client 'cmd' strings
int lu_engfuncs::l_pfnCmd_Argc(lua_State *L)
{
    lua_pushinteger(L, (*g_engfuncs.pfnCmd_Argc)());
    return 1;
}

// void(*pfnGetAttachment)( const edict_t *pEdict, int iAttachment, float *rgflOrigin, float *rgflAngles );
int lu_engfuncs::l_pfnGetAttachment(lua_State *L)
{
    /*const edict_t * l_pEdict = (edict_t*)lua_touserdata(L, 1);
    int  l_iAttachment = lua_tointeger(L, 2);
    float  *l_rgflOrigin = lua_tonumber(L, 3);
    float  *l_rgflAngles = lua_tonumber(L, 4);
    (*g_engfuncs.pfnGetAttachment)(l_pEdict, l_iAttachment, *l_rgflOrigin, *l_rgflAngles);
    return 0;*/

    return 0; // TODO
}

// long(*pfnRandomLong)( long lLow, long lHigh );
int lu_engfuncs::l_pfnRandomLong(lua_State *L)
{
    long  l_lLow = lua_tointeger(L, 1);
    long  l_lHigh = lua_tointeger(L, 2);
    lua_pushinteger(L, (*g_engfuncs.pfnRandomLong)(l_lLow, l_lHigh));
    return 1;
}

// float(*pfnRandomFloat)( float flLow, float flHigh );
int lu_engfuncs::l_pfnRandomFloat(lua_State *L)
{
    float  l_flLow = lua_tonumber(L, 1);
    float  l_flHigh = lua_tonumber(L, 2);
    lua_pushnumber(L, (*g_engfuncs.pfnRandomFloat)(l_flLow, l_flHigh));
    return 1;
}

// void(*pfnSetView)( const edict_t *pClient, const edict_t *pViewent );
int lu_engfuncs::l_pfnSetView(lua_State *L)
{
    const edict_t * l_pClient = (edict_t*)lua_touserdata(L, 1);
    const edict_t * l_pViewent = (edict_t*)lua_touserdata(L, 2);
    (*g_engfuncs.pfnSetView)(l_pClient, l_pViewent);
    return 0;
}

// float(*pfnTime)( void );
int lu_engfuncs::l_pfnTime(lua_State *L)
{
    lua_pushnumber(L, (*g_engfuncs.pfnTime)());
    return 1;
}

// void(*pfnCrosshairAngle)( const edict_t *pClient, float pitch, float yaw );
int lu_engfuncs::l_pfnCrosshairAngle(lua_State *L)
{
    const edict_t * l_pClient = (edict_t*)lua_touserdata(L, 1);
    float  l_pitch = lua_tonumber(L, 2);
    float  l_yaw = lua_tonumber(L, 3);
    (*g_engfuncs.pfnCrosshairAngle)(l_pClient, l_pitch, l_yaw);
    return 0;
}

// byte*(*pfnLoadFileForMe)( char *filename, int *pLength );
int lu_engfuncs::l_pfnLoadFileForMe(lua_State *L)
{
    /*char * l_filename = lua_tostring(L, 1);
    int  *l_pLength = lua_tointeger(L, 2);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnLoadFileForMe)(l_filename, *l_pLength));
    return 1;*/

    return 0; // TODO
}

// void(*pfnFreeFile)( void *buffer );
int lu_engfuncs::l_pfnFreeFile(lua_State *L)
{
    void * l_buffer = lua_touserdata(L, 1);
    (*g_engfuncs.pfnFreeFile)(l_buffer);
    return 0;
}

// void(*pfnEndSection)( const char *pszSectionName ); // trigger_endsection
int lu_engfuncs::l_pfnEndSection(lua_State *L)
{
    const char * l_pszSectionName = lua_tostring(L, 1);
    (*g_engfuncs.pfnEndSection)(l_pszSectionName);
    return 0;
}

// int(*pfnCompareFileTime)( char *filename1, char *filename2, int *iCompare );
int lu_engfuncs::l_pfnCompareFileTime(lua_State *L)
{
    /*char * l_filename1 = lua_tostring(L, 1);
    char * l_filename2 = lua_tostring(L, 2);
    int  *l_iCompare = lua_tointeger(L, 3);
    lua_pushinteger(L, (*g_engfuncs.pfnCompareFileTime)(l_filename1, l_filename2, *l_iCompare));
    return 1;*/

    return 0; // TODO
}

// void(*pfnGetGameDir)( char *szGetGameDir );
int lu_engfuncs::l_pfnGetGameDir(lua_State *L)
{
    char * l_szGetGameDir = const_cast<char*>(lua_tostring(L, 1));
    (*g_engfuncs.pfnGetGameDir)(l_szGetGameDir);
    return 0;
}

// void(*pfnCvar_RegisterVariable)( cvar_t *variable );
int lu_engfuncs::l_pfnCvar_RegisterVariable(lua_State *L)
{
    cvar_t * l_variable = new cvar_t({ lua_tostring(L, 1), (char*)lua_tostring(L, 2) });
    (*g_engfuncs.pfnCvar_RegisterVariable)(l_variable);
    return 0;
}

// void(*pfnFadeClientVolume)( const edict_t *pEdict, int fadePercent, int fadeOutSeconds, int holdTime, int fadeInSeconds );
int lu_engfuncs::l_pfnFadeClientVolume(lua_State *L)
{
    const edict_t * l_pEdict = (edict_t*)lua_touserdata(L, 1);
    int  l_fadePercent = lua_tointeger(L, 2);
    int  l_fadeOutSeconds = lua_tointeger(L, 3);
    int  l_holdTime = lua_tointeger(L, 4);
    int  l_fadeInSeconds = lua_tointeger(L, 5);
    (*g_engfuncs.pfnFadeClientVolume)(l_pEdict, l_fadePercent, l_fadeOutSeconds, l_holdTime, l_fadeInSeconds);
    return 0;
}

// void(*pfnSetClientMaxspeed)( edict_t *pEdict, float fNewMaxspeed );
int lu_engfuncs::l_pfnSetClientMaxspeed(lua_State *L)
{
    edict_t * l_pEdict = (edict_t*)lua_touserdata(L, 1);
    float  l_fNewMaxspeed = lua_tonumber(L, 2);
    (*g_engfuncs.pfnSetClientMaxspeed)(l_pEdict, l_fNewMaxspeed);
    return 0;
}

// edict_t*(*pfnCreateFakeClient)( const char *netname ); // returns NULL if fake client can't be created
int lu_engfuncs::l_pfnCreateFakeClient(lua_State *L)
{
    const char * l_netname = lua_tostring(L, 1);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnCreateFakeClient)(l_netname));
    return 1;
}

// void(*pfnRunPlayerMove)( edict_t *fakeclient, const float *viewangles, float forwardmove, float sidemove, float upmove, unsigned short buttons, byte impulse, byte msec );
int lu_engfuncs::l_pfnRunPlayerMove(lua_State *L)
{
    edict_t * l_fakeclient = (edict_t*)lua_touserdata(L, 1);
    const float * l_viewangles = mlua_tovec3(L, 2);
    float  l_forwardmove = lua_tonumber(L, 3);
    float  l_sidemove = lua_tonumber(L, 4);
    float  l_upmove = lua_tonumber(L, 5);
    unsigned short  l_buttons = lua_tointeger(L, 6);
    byte  l_impulse = lua_tointeger(L, 7);
    byte  l_msec = lua_tointeger(L, 8);
    (*g_engfuncs.pfnRunPlayerMove)(l_fakeclient, l_viewangles, l_forwardmove, l_sidemove, l_upmove, l_buttons, l_impulse, l_msec);
    return 0;
}

// int(*pfnNumberOfEntities)( void );
int lu_engfuncs::l_pfnNumberOfEntities(lua_State *L)
{
    lua_pushinteger(L, (*g_engfuncs.pfnNumberOfEntities)());
    return 1;
}

// char*(*pfnGetInfoKeyBuffer)( edict_t *e );// passing in NULL gets the serverinfo
int lu_engfuncs::l_pfnGetInfoKeyBuffer(lua_State *L)
{
    edict_t * l_e = (edict_t*)lua_touserdata(L, 1);
    lua_pushstring(L, (*g_engfuncs.pfnGetInfoKeyBuffer)(l_e));
    return 1;
}

// char*(*pfnInfoKeyValue)( char *infobuffer, char *key );
int lu_engfuncs::l_pfnInfoKeyValue(lua_State *L)
{
    char * l_infobuffer = const_cast<char*>(lua_tostring(L, 1));
    char * l_key = const_cast<char*>(lua_tostring(L, 2));
    lua_pushstring(L, (*g_engfuncs.pfnInfoKeyValue)(l_infobuffer, l_key));
    return 1;
}

// void(*pfnSetKeyValue)( char *infobuffer, char *key, char *value );
int lu_engfuncs::l_pfnSetKeyValue(lua_State *L)
{
    char * l_infobuffer = const_cast<char*>(lua_tostring(L, 1));
    char * l_key = const_cast<char*>(lua_tostring(L, 2));
    char * l_value = const_cast<char*>(lua_tostring(L, 3));
    (*g_engfuncs.pfnSetKeyValue)(l_infobuffer, l_key, l_value);
    return 0;
}

// void(*pfnSetClientKeyValue)( int clientIndex, char *infobuffer, char *key, char *value );
int lu_engfuncs::l_pfnSetClientKeyValue(lua_State *L)
{
    int  l_clientIndex = lua_tointeger(L, 1);
    char * l_infobuffer = const_cast<char*>(lua_tostring(L, 2));
    char * l_key = const_cast<char*>(lua_tostring(L, 3));
    char * l_value = const_cast<char*>(lua_tostring(L, 4));
    (*g_engfuncs.pfnSetClientKeyValue)(l_clientIndex, l_infobuffer, l_key, l_value);
    return 0;
}

// int(*pfnIsMapValid)( const char *filename );
int lu_engfuncs::l_pfnIsMapValid(lua_State *L)
{
    const char * l_filename = lua_tostring(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnIsMapValid)(l_filename));
    return 1;
}

// void(*pfnStaticDecal)( const float *origin, int decalIndex, int entityIndex, int modelIndex );
int lu_engfuncs::l_pfnStaticDecal(lua_State *L)
{
    const float * l_origin = mlua_tovec3(L, 1);
    int  l_decalIndex = lua_tointeger(L, 2);
    int  l_entityIndex = lua_tointeger(L, 3);
    int  l_modelIndex = lua_tointeger(L, 4);
    (*g_engfuncs.pfnStaticDecal)(l_origin, l_decalIndex, l_entityIndex, l_modelIndex);
    return 0;
}

// int(*pfnPrecacheGeneric)( char *s );
int lu_engfuncs::l_pfnPrecacheGeneric(lua_State *L)
{
    char * l_s = const_cast<char*>(lua_tostring(L, 1));
    lua_pushinteger(L, (*g_engfuncs.pfnPrecacheGeneric)(l_s));
    return 1;
}

// int(*pfnGetPlayerUserId)( edict_t *e ); // returns the server assigned userid for this player.  useful for logging frags, etc.  returns -1 if the edict couldn't be found in the list of clients
int lu_engfuncs::l_pfnGetPlayerUserId(lua_State *L)
{
    edict_t * l_e = (edict_t*)lua_touserdata(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnGetPlayerUserId)(l_e));
    return 1;
}

// void(*pfnBuildSoundMsg)( edict_t *entity, int channel, const char *sample, float volume, float attenuation, int fFlags, int pitch, int msg_dest, int msg_type, const float *pOrigin, edict_t *ed );
int lu_engfuncs::l_pfnBuildSoundMsg(lua_State *L)
{
    edict_t * l_entity = (edict_t*)lua_touserdata(L, 1);
    int  l_channel = lua_tointeger(L, 2);
    const char * l_sample = lua_tostring(L, 3);
    float  l_volume = lua_tonumber(L, 4);
    float  l_attenuation = lua_tonumber(L, 5);
    int  l_fFlags = lua_tointeger(L, 6);
    int  l_pitch = lua_tointeger(L, 7);
    int  l_msg_dest = lua_tointeger(L, 8);
    int  l_msg_type = lua_tointeger(L, 9);
    const float * l_pOrigin = mlua_tovec3(L, 10);
    edict_t * l_ed = (edict_t*)lua_touserdata(L, 11);
    (*g_engfuncs.pfnBuildSoundMsg)(l_entity, l_channel, l_sample, l_volume, l_attenuation, l_fFlags, l_pitch, l_msg_dest, l_msg_type, l_pOrigin, l_ed);
    return 0;
}

// int(*pfnIsDedicatedServer)( void );
int lu_engfuncs::l_pfnIsDedicatedServer(lua_State *L)
{
    lua_pushinteger(L, (*g_engfuncs.pfnIsDedicatedServer)());
    return 1;
}

// cvar_t*(*pfnCVarGetPointer)( const char *szVarName );
int lu_engfuncs::l_pfnCVarGetPointer(lua_State *L)
{
    const char * l_szVarName = lua_tostring(L, 1);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnCVarGetPointer)(l_szVarName));
    return 1;
}

// unsigned int (*pfnGetPlayerWONId)( edict_t *e );
int lu_engfuncs::l_pfnGetPlayerWONId(lua_State *L)
{
    edict_t * l_e = (edict_t*)lua_touserdata(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnGetPlayerWONId)(l_e));
    return 1;
}

// void(*pfnInfo_RemoveKey)( char *s, const char *key );
int lu_engfuncs::l_pfnInfo_RemoveKey(lua_State *L)
{
    char * l_s = const_cast<char*>(lua_tostring(L, 1));
    const char * l_key = lua_tostring(L, 2);
    (*g_engfuncs.pfnInfo_RemoveKey)(l_s, l_key);
    return 0;
}

// const char *(*pfnGetPhysicsKeyValue)( const edict_t *pClient, const char *key );
int lu_engfuncs::l_pfnGetPhysicsKeyValue(lua_State *L)
{
    const edict_t * l_pClient = (edict_t*)lua_touserdata(L, 1);
    const char * l_key = lua_tostring(L, 2);
    lua_pushstring(L, (*g_engfuncs.pfnGetPhysicsKeyValue)(l_pClient, l_key));
    return 1;
}

// void(*pfnSetPhysicsKeyValue)( const edict_t *pClient, const char *key, const char *value );
int lu_engfuncs::l_pfnSetPhysicsKeyValue(lua_State *L)
{
    const edict_t * l_pClient = (edict_t*)lua_touserdata(L, 1);
    const char * l_key = lua_tostring(L, 2);
    const char * l_value = lua_tostring(L, 3);
    (*g_engfuncs.pfnSetPhysicsKeyValue)(l_pClient, l_key, l_value);
    return 0;
}

// const char *(*pfnGetPhysicsInfoString)( const edict_t *pClient );
int lu_engfuncs::l_pfnGetPhysicsInfoString(lua_State *L)
{
    const edict_t * l_pClient = (edict_t*)lua_touserdata(L, 1);
    lua_pushstring(L, (*g_engfuncs.pfnGetPhysicsInfoString)(l_pClient));
    return 1;
}

// unsigned short (*pfnPrecacheEvent)( int type, const char*psz );
int lu_engfuncs::l_pfnPrecacheEvent(lua_State *L)
{
    int  l_type = lua_tointeger(L, 1);
    const char* l_psz = lua_tostring(L, 2);
    lua_pushinteger(L, (*g_engfuncs.pfnPrecacheEvent)(l_type, l_psz));
    return 1;
}

// void(*pfnPlaybackEvent)( int flags, const edict_t *pInvoker, unsigned short eventindex, float delay, float *origin, float *angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2 );
int lu_engfuncs::l_pfnPlaybackEvent(lua_State *L)
{
    /*int  l_flags = lua_tointeger(L, 1);
    const edict_t * l_pInvoker = (edict_t*)lua_touserdata(L, 2);
    unsigned short  l_eventindex = lua_tointeger(L, 3);
    float  l_delay = lua_tonumber(L, 4);
    float  *l_origin = lua_tonumber(L, 5);
    float  *l_angles = lua_tonumber(L, 6);
    float  l_fparam1 = lua_tonumber(L, 7);
    float  l_fparam2 = lua_tonumber(L, 8);
    int  l_iparam1 = lua_tointeger(L, 9);
    int  l_iparam2 = lua_tointeger(L, 10);
    int  l_bparam1 = lua_tointeger(L, 11);
    int  l_bparam2 = lua_tointeger(L, 12);
    (*g_engfuncs.pfnPlaybackEvent)(l_flags, l_pInvoker, l_eventindex, l_delay, *l_origin, *l_angles, l_fparam1, l_fparam2, l_iparam1, l_iparam2, l_bparam1, l_bparam2);
    return 0;*/
    return 0; // TODO
}

// unsigned char *(*pfnSetFatPVS)( float *org );
int lu_engfuncs::l_pfnSetFatPVS(lua_State *L)
{
    /*float  *l_org = lua_tonumber(L, 1);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnSetFatPVS)(*l_org));
    return 1;*/

    return 0; // TODO
}

// unsigned char *(*pfnSetFatPAS)( float *org );
int lu_engfuncs::l_pfnSetFatPAS(lua_State *L)
{
    /*float *l_org = (float*)lua_touserdata(L, 1);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnSetFatPAS)(l_org));
    return 1;*/

    return 0; //TODO
}

// int(*pfnCheckVisibility )( edict_t *entity, unsigned char *pset );
int lu_engfuncs::l_pfnCheckVisibility (lua_State *L)
{
    edict_t * l_entity = (edict_t*)lua_touserdata(L, 1);
    unsigned char* l_pset = (unsigned char*)lua_touserdata(L, 2);
    lua_pushinteger(L, (*g_engfuncs.pfnCheckVisibility )(l_entity, l_pset));
    return 1;
}

// void(*pfnDeltaSetField)( struct delta_s *pFields, const char *fieldname );
int lu_engfuncs::l_pfnDeltaSetField(lua_State *L)
{
    struct delta_s * l_pFields = (struct delta_s *)lua_touserdata(L, 1);
    const char * l_fieldname = lua_tostring(L, 2);
    (*g_engfuncs.pfnDeltaSetField)(l_pFields, l_fieldname);
    return 0;
}

// void(*pfnDeltaUnsetField)( struct delta_s *pFields, const char *fieldname );
int lu_engfuncs::l_pfnDeltaUnsetField(lua_State *L)
{
    struct delta_s * l_pFields = (struct delta_s *)lua_touserdata(L, 1);
    const char * l_fieldname = lua_tostring(L, 2);
    (*g_engfuncs.pfnDeltaUnsetField)(l_pFields, l_fieldname);
    return 0;
}

// void(*pfnDeltaAddEncoder)( char *name, void (*conditionalencode)( struct delta_s *pFields, const unsigned char *from, const unsigned char *to ) );
int lu_engfuncs::l_pfnDeltaAddEncoder(lua_State *L)
{
    /*char * l_name = lua_tostring(L, 1);
    void * l_conditionalencode struct delta_s *pFields = lua_touserdata(L, 2);
    const unsigned char * l_from = (const unsigned char *)lua_touserdata(L, 3);
    const unsigned char * l_to  = (const unsigned char *)lua_touserdata(L, 4);
    (*g_engfuncs.pfnDeltaAddEncoder)(l_name, l_conditionalencode struct delta_s *pFields, l_from, l_to );*/
    return 0;
}

// int(*pfnGetCurrentPlayer)( void );
int lu_engfuncs::l_pfnGetCurrentPlayer(lua_State *L)
{
    lua_pushinteger(L, (*g_engfuncs.pfnGetCurrentPlayer)());
    return 1;
}

// int(*pfnCanSkipPlayer)( const edict_t *player );
int lu_engfuncs::l_pfnCanSkipPlayer(lua_State *L)
{
    const edict_t * l_player = (edict_t*)lua_touserdata(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnCanSkipPlayer)(l_player));
    return 1;
}

// int(*pfnDeltaFindField)( struct delta_s *pFields, const char *fieldname );
int lu_engfuncs::l_pfnDeltaFindField(lua_State *L)
{
    struct delta_s * l_pFields = (struct delta_s *)lua_touserdata(L, 1);
    const char * l_fieldname = lua_tostring(L, 2);
    lua_pushinteger(L, (*g_engfuncs.pfnDeltaFindField)(l_pFields, l_fieldname));
    return 1;
}

// void(*pfnDeltaSetFieldByIndex)( struct delta_s *pFields, int fieldNumber );
int lu_engfuncs::l_pfnDeltaSetFieldByIndex(lua_State *L)
{
    struct delta_s * l_pFields = (struct delta_s *)lua_touserdata(L, 1);
    int  l_fieldNumber = lua_tointeger(L, 2);
    (*g_engfuncs.pfnDeltaSetFieldByIndex)(l_pFields, l_fieldNumber);
    return 0;
}

// void(*pfnDeltaUnsetFieldByIndex)( struct delta_s *pFields, int fieldNumber );
int lu_engfuncs::l_pfnDeltaUnsetFieldByIndex(lua_State *L)
{
    struct delta_s * l_pFields = (struct delta_s *)lua_touserdata(L, 1);
    int  l_fieldNumber = lua_tointeger(L, 2);
    (*g_engfuncs.pfnDeltaUnsetFieldByIndex)(l_pFields, l_fieldNumber);
    return 0;
}

// void(*pfnSetGroupMask)( int mask, int op );
int lu_engfuncs::l_pfnSetGroupMask(lua_State *L)
{
    int  l_mask = lua_tointeger(L, 1);
    int  l_op = lua_tointeger(L, 2);
    (*g_engfuncs.pfnSetGroupMask)(l_mask, l_op);
    return 0;
}

// int(*pfnCreateInstancedBaseline)( int classname, struct entity_state_s *baseline );
int lu_engfuncs::l_pfnCreateInstancedBaseline(lua_State *L)
{
    int  l_classname = lua_tointeger(L, 1);
    struct entity_state_s * l_baseline = (struct entity_state_s *)lua_touserdata(L, 2);
    lua_pushinteger(L, (*g_engfuncs.pfnCreateInstancedBaseline)(l_classname, l_baseline));
    return 1;
}

// void(*pfnCvar_DirectSet)( struct cvar_s *var, char *value );
int lu_engfuncs::l_pfnCvar_DirectSet(lua_State *L)
{
    struct cvar_s * l_var = (struct cvar_s *)lua_touserdata(L, 1);
    char * l_value = const_cast<char*>(lua_tostring(L, 2));
    (*g_engfuncs.pfnCvar_DirectSet)(l_var, l_value);
    return 0;
}

// void(*pfnForceUnmodified)( FORCE_TYPE type, float *mins, float *maxs, const char *filename );
int lu_engfuncs::l_pfnForceUnmodified(lua_State *L)
{
    /*FORCE_TYPE l_type = lua_tointeger(L, 1);
    float l_mins = (int*)lua_touserdata(L, 2);
    float l_maxs = (int*)lua_touserdata(L, 3);
    const char * l_filename = lua_tostring(L, 4);
    (*g_engfuncs.pfnForceUnmodified)(l_type, l_mins, l_maxs, l_filename);
    return 0;*/

    return 0; // TODO
}

// void(*pfnGetPlayerStats)( const edict_t *pClient, int *ping, int *packet_loss );
int lu_engfuncs::l_pfnGetPlayerStats(lua_State *L)
{
    /*const edict_t * l_pClient = (edict_t*)lua_touserdata(L, 1);
    int *l_ping = (int*)lua_touserdata(L, 2);
    int *l_packet_loss = (int*)lua_touserdata(L, 3);
    (*g_engfuncs.pfnGetPlayerStats)(l_pClient, *l_ping, *l_packet_loss);
    return 0;*/

    return 0; // TODO
}

// void(*pfnAddServerCommand)( char *cmd_name, void (*function) (void) );
int lu_engfuncs::l_pfnAddServerCommand(lua_State *L)
{
    /*char *l_cmd_name = lua_tostring(L, 1);
    void *l_function void = lua_touserdata(L, 2);
    (*g_engfuncs.pfnAddServerCommand)(l_cmd_name, l_function void);
    return 0;*/

    return 0; // TODO
}

// qboolean(*pfnVoice_GetClientListening)(int iReceiver, int iSender);
int lu_engfuncs::l_pfnVoice_GetClientListening(lua_State *L)
{
    int l_iReceiver = lua_tointeger(L, 1);
    int l_iSender = lua_tointeger(L, 2);
    lua_pushboolean(L, (*g_engfuncs.pfnVoice_GetClientListening)(l_iReceiver, l_iSender));
    return 1;
}

// qboolean(*pfnVoice_SetClientListening)(int iReceiver, int iSender, qboolean bListen);
int lu_engfuncs::l_pfnVoice_SetClientListening(lua_State *L)
{
    int l_iReceiver = lua_tointeger(L, 1);
    int l_iSender = lua_tointeger(L, 2);
    qboolean l_bListen = lua_toboolean(L, 3);
    lua_pushboolean(L, (*g_engfuncs.pfnVoice_SetClientListening)(l_iReceiver, l_iSender, l_bListen));
    return 1;
}

// const char *(*pfnGetPlayerAuthId)( edict_t *e );
int lu_engfuncs::l_pfnGetPlayerAuthId(lua_State *L)
{
    edict_t *l_e = (edict_t*)lua_touserdata(L, 1);
    lua_pushstring(L, (*g_engfuncs.pfnGetPlayerAuthId)(l_e));
    return 1;
}

// void*(*pfnSequenceGet)( const char *fileName, const char *entryName );
int lu_engfuncs::l_pfnSequenceGet(lua_State *L)
{
    const char *l_fileName = lua_tostring(L, 1);
    const char *l_entryName = lua_tostring(L, 2);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnSequenceGet)(l_fileName, l_entryName));
    return 1;
}

// void*(*pfnSequencePickSentence)( const char *groupName, int pickMethod, int *picked );
int lu_engfuncs::l_pfnSequencePickSentence(lua_State *L)
{
    /*const char *l_groupName = lua_tostring(L, 1);
    int  l_pickMethod = lua_tointeger(L, 2);
    int  l_picked = (int*)lua_touserdata(L, 3);
    lua_pushlightuserdata(L, (*g_engfuncs.pfnSequencePickSentence)(l_groupName, l_pickMethod, l_picked));
    return 1;*/

    return 0; // TODO
}

// int(*pfnGetFileSize)( char *filename );
int lu_engfuncs::l_pfnGetFileSize(lua_State *L)
{
    char *l_filename = const_cast<char*>(lua_tostring(L, 1));
    lua_pushinteger(L, (*g_engfuncs.pfnGetFileSize)(l_filename));
    return 1;
}

// unsigned int (*pfnGetApproxWavePlayLen)( const char *filepath );
int lu_engfuncs::l_pfnGetApproxWavePlayLen(lua_State *L)
{
    const char *l_filepath = lua_tostring(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnGetApproxWavePlayLen)(l_filepath));
    return 1;
}

// int(*pfnIsCareerMatch)( void );
int lu_engfuncs::l_pfnIsCareerMatch(lua_State *L)
{
    lua_pushinteger(L, (*g_engfuncs.pfnIsCareerMatch)());
    return 1;
}

// int(*pfnGetLocalizedStringLength)( const char *label );
int lu_engfuncs::l_pfnGetLocalizedStringLength(lua_State *L)
{
    const char *l_label = lua_tostring(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnGetLocalizedStringLength)(l_label));
    return 1;
}

// void(*pfnRegisterTutorMessageShown)( int mid );
int lu_engfuncs::l_pfnRegisterTutorMessageShown(lua_State *L)
{
    int l_mid = lua_tointeger(L, 1);
    (*g_engfuncs.pfnRegisterTutorMessageShown)(l_mid);
    return 0;
}

// int(*pfnGetTimesTutorMessageShown)( int mid );
int lu_engfuncs::l_pfnGetTimesTutorMessageShown(lua_State *L)
{
    int l_mid = lua_tointeger(L, 1);
    lua_pushinteger(L, (*g_engfuncs.pfnGetTimesTutorMessageShown)(l_mid));
    return 1;
}

// void(*pfnProcessTutorMessageDecayBuffer)( int *buffer, int bufferLength );
int lu_engfuncs::l_pfnProcessTutorMessageDecayBuffer(lua_State *L)
{
    /*int  l_buffer = (int*)lua_touserdata(L, 1);
    int  l_bufferLength = lua_tointeger(L, 2);
    (*g_engfuncs.pfnProcessTutorMessageDecayBuffer)(l_buffer, l_bufferLength);
    return 0;*/

    return 0; // TODO
}

// void(*pfnConstructTutorMessageDecayBuffer)( int *buffer, int bufferLength );
int lu_engfuncs::l_pfnConstructTutorMessageDecayBuffer(lua_State *L)
{
    int  *l_buffer = (int*)lua_touserdata(L, 1);
    int  l_bufferLength = lua_tointeger(L, 2);
    (*g_engfuncs.pfnConstructTutorMessageDecayBuffer)(l_buffer, l_bufferLength);
    return 0;
}

// void(*pfnResetTutorMessageDecayData)( void );
int lu_engfuncs::l_pfnResetTutorMessageDecayData(lua_State *L)
{
    (*g_engfuncs.pfnResetTutorMessageDecayData)();
    return 0;
}

// void(*pfnQueryClientCvarValue)( const edict_t *player, const char *cvarName );
int lu_engfuncs::l_pfnQueryClientCvarValue(lua_State *L)
{
    const edict_t * l_player = (edict_t*)lua_touserdata(L, 1);
    const char * l_cvarName = lua_tostring(L, 2);
    (*g_engfuncs.pfnQueryClientCvarValue)(l_player, l_cvarName);
    return 0;
}

// void(*pfnQueryClientCvarValue2)( const edict_t *player, const char *cvarName, int requestID );
int lu_engfuncs::l_pfnQueryClientCvarValue2(lua_State *L)
{
    const edict_t * l_player = (edict_t*)lua_touserdata(L, 1);
    const char * l_cvarName = lua_tostring(L, 2);
    int  l_requestID = lua_tointeger(L, 3);
    (*g_engfuncs.pfnQueryClientCvarValue2)(l_player, l_cvarName, l_requestID);
    return 0;
}

// int(*CheckParm)( char *parm, char **ppnext );
int lu_engfuncs::l_CheckParm(lua_State *L)
{
    /*char * l_parm = lua_tostring(L, 1);
    char **l_ppnext = (char **)lua_touserdata(L, 2);
    lua_pushinteger(L, (*g_engfuncs.CheckParm)(l_parm, l_ppnext));
    return 1;*/

    return 0; // TODO
}
