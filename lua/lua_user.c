#ifdef __linux__
#include <pthread.h>
#define SECT pthread_mutex_t
#define lock_init(x) pthread_mutex_init(x, NULL)
#define lock_free(x) pthread_mutex_destroy(x)
#define lock_lock(x) pthread_mutex_lock(x)
#define lock_unlock(x) pthread_mutex_unlock(x)
#else
#include <windows.h>
#define SECT CRITICAL_SECTION
#define lock_init(x) InitializeCriticalSection(x)
#define lock_free(x) DeleteCriticalSection(x)
#define lock_lock(x) EnterCriticalSection(x)
#define lock_unlock(x) LeaveCriticalSection(x)
#endif
#define lock_new() LockNew()
#define LSECT SECT*

inline LSECT LockNew() {
	LSECT s = (LSECT)malloc(sizeof(SECT));
	lock_init(s);
	return s;
}


#include "lua_user.h"

typedef struct {
	lua_State* L;
	struct GS* next;
	LSECT sect;
} GS;

GS* gss = NULL;

void LuaLockInitial(lua_State * L)
{
	GS *el = (struct GS *)malloc(sizeof(GS));
	el->next = gss;
	el->L = L;
	el->sect = lock_new();
	gss = el;
}

void lock_GC(lua_State * L) /* Not called by Lua. */
{
	GS* last = NULL;
	for (GS* gs = gss; gs->next != NULL; gs = gs->next) {
		if (gs->L == L) {
			lock_free(gs->sect);
			if (last == NULL)
				gss = gs->next;
			else
			last->next = gs->next;
			free(gs);
			break;
		}
		last = gs;
	}
}

  LUA_API void lua_lock(lua_State * L)
  {
	  for (GS* gs = gss; gs->next != NULL; gs = gs->next) {
		  if (gs->L == L) {
			  lock_lock(gs->sect);
			  break;
		  }
	  }
  }

LUA_API  void lua_unlock(lua_State * L)
  {
	  for (GS* gs = gss; gs->next != NULL; gs = gs->next) {
		  if (gs->L == L) {
			  lock_unlock(gs->sect);
			  break;
		  }
	  }
}
