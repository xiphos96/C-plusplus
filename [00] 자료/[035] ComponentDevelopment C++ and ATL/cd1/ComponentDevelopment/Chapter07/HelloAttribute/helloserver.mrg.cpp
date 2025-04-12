// Created by Microsoft (R) C/C++ Compiler Version 13.10.3077
//
// c:\componentdevelopment\chapter07\helloattribute\helloserver.mrg.cpp
// compiler-generated file created 03/10/04 at 14:31:42
//
// This C++ source file is intended to be a representation of the
// source code injected by the compiler.  It may not compile or
// run exactly as the original source file.
//


//+++ Start Injected Code
[no_injected_text(true)];      // Suppress injected text, it has already been injected
#pragma warning(disable: 4543) // Suppress warnings about skipping injected text
#pragma warning(disable: 4199) // Suppress warnings from attribute providers

// M00PRAGMA("\n\nNOTE: This merged source file should be visually inspected for correctness.\n\n")
//--- End Injected Code

#pragma once
#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_ATTRIBUTES
#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE
#include <atlbase.h>
#include <atlcom.h>
#include <atlwin.h>
#include <atltypes.h>
#include <atlctl.h>
#include <atlhost.h>
using namespace ATL;

// HelloServer 모듈
[ module(dll, name = "HelloServer", 
		 helpstring = "HelloServer 1.0 형식 라이브러리") 
];

//+++ Start Injected Code For Attribute 'module'
#injected_line 18 "HelloServer.cpp"

#ifndef GUID_DEFINED
#define GUID_DEFINED
typedef struct _GUID 
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[ 8 ];
} 
GUID;
#endif

extern "C" const __declspec(selectany) GUID __LIBID_ = {0xc3c0047a,0x5622,0x33c1,{0xbb,0xcb,0x01,0xcb,0xbb,0x05,0x4f,0x5a}};
struct __declspec(uuid("c3c0047a-5622-33c1-bbcb-01cbbb054f5a")) HelloServer;

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 18 "HelloServer.cpp"

class CHelloServerModule;

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 18 "HelloServer.cpp"

extern CHelloServerModule _AtlModule;

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 18 "HelloServer.cpp"
extern "C" STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv);

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 18 "HelloServer.cpp"
extern "C" STDAPI DllRegisterServer(void);

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 18 "HelloServer.cpp"
extern "C" STDAPI DllUnregisterServer(void);

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 18 "HelloServer.cpp"
extern "C" STDAPI DllCanUnloadNow(void);

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 18 "HelloServer.cpp"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved);

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 18 "HelloServer.cpp"

class CHelloServerModule : public CAtlDllModuleT<CHelloServerModule>
    								
{
public:
    DECLARE_LIBID(__uuidof(HelloServer))
        								
};

#injected_line 18 "HelloServer.cpp"

CHelloServerModule _AtlModule;

#injected_line 18 "HelloServer.cpp"
extern "C" STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv) 
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}
#injected_line 18 "HelloServer.cpp"
extern "C" STDAPI DllRegisterServer(void) 
{
    return _AtlModule.DllRegisterServer();
}
#injected_line 18 "HelloServer.cpp"
extern "C" STDAPI DllUnregisterServer(void) 
{
    return _AtlModule.DllUnregisterServer();
}
#injected_line 18 "HelloServer.cpp"
extern "C" STDAPI DllCanUnloadNow(void) 
{
    return _AtlModule.DllCanUnloadNow();
}
#injected_line 18 "HelloServer.cpp"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved) 
{
    hInstance;
    return _AtlModule.DllMain(dwReason, lpReserved);
}
#injected_line 18 "HelloServer.cpp"

#if defined(_M_IX86)
#pragma comment(linker, "/EXPORT:DllMain=_DllMain@12,PRIVATE")
#pragma comment(linker, "/EXPORT:DllRegisterServer=_DllRegisterServer@0,PRIVATE")
#pragma comment(linker, "/EXPORT:DllUnregisterServer=_DllUnregisterServer@0,PRIVATE")
#pragma comment(linker, "/EXPORT:DllGetClassObject=_DllGetClassObject@12,PRIVATE")
#pragma comment(linker, "/EXPORT:DllCanUnloadNow=_DllCanUnloadNow@0,PRIVATE")
#elif defined(_M_IA64)
#pragma comment(linker, "/EXPORT:DllMain,PRIVATE")
#pragma comment(linker, "/EXPORT:DllRegisterServer,PRIVATE")
#pragma comment(linker, "/EXPORT:DllUnregisterServer,PRIVATE")
#pragma comment(linker, "/EXPORT:DllGetClassObject,PRIVATE")
#pragma comment(linker, "/EXPORT:DllCanUnloadNow,PRIVATE")
#endif	

//--- End Injected Code For Attribute 'module'

[ emitidl ];

// IHello 인터페이스
[
	object,
	uuid("C4646F65-6C21-4051-8DA8-E0AC06BF1CEB"),
	helpstring("IHello 인터페이스"),
	pointer_default(unique)
]
__interface IHello : IUnknown
{
	HRESULT sayHello([in]wchar_t* name, [out]wchar_t** message);
};

// CHello COM 클래스
[
	coclass,
	threading("apartment"),
	vi_progid("HelloServer.Hello"),
	progid("HelloServer.Hello.1"),
	version(1.0),
	uuid("D84CDA2F-5AF1-4e97-BE21-983E0AB93D67"),
	helpstring("Hello COM 객체")
]
class ATL_NO_VTABLE CHello : public IHello
,
    /*+++ Added Baseclass */ public CComCoClass<CHello, &__uuidof(CHello)>,
    /*+++ Added Baseclass */ public CComObjectRootEx<CComSingleThreadModel>,
    /*+++ Added Baseclass */ public IProvideClassInfoImpl<&__uuidof(CHello)>
{
public:
	CHello(){
	}
	HRESULT sayHello(wchar_t* name, wchar_t** message) {
		char * buffer = (char*)::CoTaskMemAlloc(256);
		if(buffer == NULL)
			return E_FAIL;
	
		::wsprintf(buffer, "%s 씨 안녕하세요?", name);
		*message = (wchar_t*)buffer;
	
		return S_OK;
	}
	
	DECLARE_PROTECT_FINAL_CONSTRUCT()
	HRESULT FinalConstruct() {
		return S_OK;
	}
	void FinalRelease() {
	}

	//+++ Start Injected Code For Attribute 'coclass'
#injected_line 43 "HelloServer.cpp"
    static DWORD* GetOpCodes() 
    {
        static DWORD rgOps[] = 
            					{
            						0x70000000,
            0x30004000,
            0x80000002,
            0x50000000,
            0x3000c000,
            0x80000004,
            0x60000000,
            0x30014000,
            0x80000002,
            0x50000000,
            0x3000c000,
            0x80000004,
            0x30018000,
            0x80000001,
            0x60000000,
            0x1000c000,
            0x3000c000,
            0x50000000,
            0x20010000,
            0x30010000,
            0x80000002,
            0x50000000,
            0x3001c000,
            0x80000001,
            0x30020000,
            0x80000005,
            0x20024000,
            0x30024000,
            0x30028000,
            0x8000000b,
            0x50000000,
            0x8003000d,
            0x60000000,
            0x8003800f,
            0x30040000,
            0x80000011,
            0x60000000,
            0x60000000,
            0x60000000,
            0
            					};
        return rgOps;
    }
#injected_line 43 "HelloServer.cpp"
    static RGSDWORD* GetOpcodeDWORDVals() 
    {
        static RGSDWORD rgDWORDS[] = 
            					{
            						{0, 0}
            					};
        return rgDWORDS;
    }
#injected_line 43 "HelloServer.cpp"
    static RGSBinary* GetOpcodeBinaryVals() 
    {

        static RGSBinary rgBinary[] = 
            					{
            						{0, 0}
            					};
        return rgBinary;
    }
#injected_line 43 "HelloServer.cpp"
    static RGSStrings* GetOpcodeStringVals() 
    {
        static RGSStrings rgStrings[] = 
            					{
            						{_T(""),0 }, 
            {_T("HelloServer.Hello.1"),0 }, 
            {_T("%FriendlyName%"),1 }, 
            {_T("CLSID"),0 }, 
            {_T("{D84CDA2F-5AF1-4e97-BE21-983E0AB93D67}"),0 }, 
            {_T("HelloServer.Hello"),0 }, 
            {_T("CurVer"),0 }, 
            {_T("ProgID"),0 }, 
            {_T("VersionIndependentProgID"),0 }, 
            {_T("Programmable"),0 }, 
            {_T("%MODULETYPE%"),1 }, 
            {_T("%MODULE%"),1 }, 
            {_T("ThreadingModel"),0 }, 
            {_T("apartment"),0 }, 
            {_T("AppID"),0 }, 
            {_T("%APPID%"),1 }, 
            {_T("TypeLib"),0 }, 
            {_T("%MODULEGUID%"),1 }, 
            {NULL, 0}
            					};
        return rgStrings;
    }
#injected_line 43 "HelloServer.cpp"
    static HRESULT WINAPI UpdateRegistry(BOOL bRegister) 
    {
        CRegistryVirtualMachine rvm;
        HRESULT hr;
        if (FAILED(hr = rvm.AddStandardReplacements()))
            return hr;
        rvm.AddReplacement(_T("FriendlyName"), GetObjectFriendlyName());
        return rvm.VMUpdateRegistry(GetOpCodes(), GetOpcodeStringVals(), GetOpcodeDWORDVals(), GetOpcodeBinaryVals(), bRegister);
    }
#injected_line 43 "HelloServer.cpp"
    static const TCHAR* GetObjectFriendlyName() 
    {
        return _T("CHello Object");
    }
#injected_line 43 "HelloServer.cpp"
    static const TCHAR* GetProgID() 
    {
        return _T("HelloServer.Hello.1");
    }
#injected_line 43 "HelloServer.cpp"
    static const TCHAR* GetVersionIndependentProgID() 
    {
        return _T("HelloServer.Hello");
    }
#injected_line 43 "HelloServer.cpp"
    BEGIN_COM_MAP(CHello)
        COM_INTERFACE_ENTRY(IHello)
        COM_INTERFACE_ENTRY(IProvideClassInfo)
    END_COM_MAP()

	//--- End Injected Code For Attribute 'coclass'
};

//+++ Start Injected Code For Attribute 'coclass'
#injected_line 43 "HelloServer.cpp"

				OBJECT_ENTRY_AUTO(__uuidof(CHello), CHello)
			
//--- End Injected Code For Attribute 'coclass'

