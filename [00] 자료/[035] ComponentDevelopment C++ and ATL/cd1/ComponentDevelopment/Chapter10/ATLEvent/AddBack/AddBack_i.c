

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Mon Mar 15 23:13:04 2004
 */
/* Compiler settings for .\AddBack.idl:
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

MIDL_DEFINE_GUID(IID, IID_IAddBack,0xB714A149,0xC4F8,0x4B50,0x8B,0xEE,0x92,0x6C,0x84,0xF9,0x9F,0xB2);


MIDL_DEFINE_GUID(IID, IID_IAddBackEvents,0xD90D5240,0xACD0,0x11d1,0x91,0x3A,0x00,0x20,0xAF,0x71,0x5A,0xF0);


MIDL_DEFINE_GUID(IID, LIBID_AddBackLib,0x4E1E8D00,0x91CE,0x497B,0x87,0x84,0x5D,0x72,0xDA,0xE6,0xE9,0x6D);


MIDL_DEFINE_GUID(IID, DIID__IAddBackEvents,0x6F80FA9C,0xAB06,0x47E4,0x84,0xE1,0xB7,0x11,0x51,0x76,0x0B,0xDA);


MIDL_DEFINE_GUID(CLSID, CLSID_AddBack,0xCB30E04C,0xA741,0x4E83,0xB2,0x1F,0x09,0x6D,0xED,0x83,0x51,0xD5);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

