#define _WIN32_DCOM	
#include <windows.h>
#include <objbase.h>

extern LONG g_cObjects;
extern LONG g_cLocks;
void CloseExe (void);

EXTERN_C const CLSID CLSID_Hello;