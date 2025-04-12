

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Thu Mar 18 14:45:47 2004
 */
/* Compiler settings for _Shape.idl:
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

MIDL_DEFINE_GUID(IID, IID_IShape,0xB11EC349,0xD82F,0x494B,0xA5,0x1C,0xB1,0xCD,0xC2,0xDF,0x0E,0xB4);


MIDL_DEFINE_GUID(IID, LIBID_Shape,0x44310390,0x1054,0x4276,0xBA,0x74,0x53,0x28,0xEA,0x23,0xF2,0x34);


MIDL_DEFINE_GUID(CLSID, CLSID_CShapeProp,0x1183C3B8,0xF389,0x42E8,0xB3,0x6D,0xC2,0xC6,0x67,0x57,0x13,0xB3);


MIDL_DEFINE_GUID(IID, DIID__IShapeEvents,0xB55B1009,0xF027,0x4C95,0xAE,0x5D,0x96,0x16,0x26,0xAC,0xEF,0x9A);


MIDL_DEFINE_GUID(CLSID, CLSID_CShape,0x2D1108CF,0x31BE,0x4CFC,0x8E,0xEA,0xF6,0xCD,0x3E,0xE3,0x63,0xBC);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

