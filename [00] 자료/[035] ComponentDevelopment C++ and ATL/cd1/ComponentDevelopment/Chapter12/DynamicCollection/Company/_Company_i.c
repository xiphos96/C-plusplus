

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Wed Mar 17 22:37:39 2004
 */
/* Compiler settings for _Company.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IEmployee,0xAD77D5D9,0x51A6,0x4D18,0x91,0x8F,0x8F,0xCF,0xB0,0xDF,0xC8,0xCF);


MIDL_DEFINE_GUID(IID, IID_IEmployees,0xC6783455,0x282B,0x4AB5,0xBE,0xD5,0xC8,0xD3,0xA8,0xC3,0x8E,0x72);


MIDL_DEFINE_GUID(IID, IID_ICompany,0xE261C0DF,0xC91A,0x4E10,0xAB,0xC4,0x0A,0x40,0x99,0xFC,0x8E,0x74);


MIDL_DEFINE_GUID(IID, LIBID_Company,0x600CC229,0x9F29,0x4DAF,0x8B,0x7C,0xF6,0x07,0x89,0x52,0x7F,0x32);


MIDL_DEFINE_GUID(CLSID, CLSID_CEmployee,0xBB84AD11,0x16E2,0x4196,0x88,0xDB,0xEB,0xC8,0xE5,0x18,0xDC,0x33);


MIDL_DEFINE_GUID(CLSID, CLSID_CEmployees,0x6D52EEFB,0xAEE7,0x4C46,0xA4,0x72,0x93,0x50,0xBA,0xC9,0x70,0xF0);


MIDL_DEFINE_GUID(CLSID, CLSID_CCompany,0x4BA637B8,0x6988,0x4452,0x92,0x5D,0xE3,0xE9,0x48,0x4E,0x08,0x82);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

