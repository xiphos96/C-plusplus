

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Fri Mar 19 02:18:48 2004
 */
/* Compiler settings for _DHTML.idl:
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
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */
#pragma warning( disable: 4211 )  /* redefine extent to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "_DHTML.h"

#define TYPE_FORMAT_STRING_SIZE   1063                              
#define PROC_FORMAT_STRING_SIZE   175                               
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDHTMLCtlUI_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDHTMLCtlUI_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDHTMLCtl_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDHTMLCtl_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure OnClick */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 16 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x20 ),	/* 32 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pdispBody */

/* 24 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter varColor */

/* 30 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	NdrFcShort( 0x400 ),	/* Type Offset=1024 */

	/* Return value */

/* 36 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 38 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 40 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GoTo */

/* 42 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 44 */	NdrFcLong( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */
/* 54 */	NdrFcShort( 0x8 ),	/* 8 */
/* 56 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 58 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */
/* 64 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 68 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_UrlPath */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 74 */	NdrFcLong( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x7 ),	/* 7 */
/* 80 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 82 */	NdrFcShort( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0x8 ),	/* 8 */
/* 86 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 88 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 90 */	NdrFcShort( 0x1 ),	/* 1 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 96 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 98 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 100 */	NdrFcShort( 0x412 ),	/* Type Offset=1042 */

	/* Return value */

/* 102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_UrlPath */

/* 108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 116 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 122 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 124 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 128 */	NdrFcShort( 0x1 ),	/* 1 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 132 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 134 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 136 */	NdrFcShort( 0x41c ),	/* Type Offset=1052 */

	/* Return value */

/* 138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 140 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GoToURL */

/* 144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x9 ),	/* 9 */
/* 152 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 158 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 160 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 168 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 170 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/*  4 */	NdrFcLong( 0x20400 ),	/* 132096 */
/*  8 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 14 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 16 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 18 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 20 */	
			0x12, 0x0,	/* FC_UP */
/* 22 */	NdrFcShort( 0x3d6 ),	/* Offset= 982 (1004) */
/* 24 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 26 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 28 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 30 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 32 */	NdrFcShort( 0x2 ),	/* Offset= 2 (34) */
/* 34 */	NdrFcShort( 0x10 ),	/* 16 */
/* 36 */	NdrFcShort( 0x2f ),	/* 47 */
/* 38 */	NdrFcLong( 0x14 ),	/* 20 */
/* 42 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 44 */	NdrFcLong( 0x3 ),	/* 3 */
/* 48 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 50 */	NdrFcLong( 0x11 ),	/* 17 */
/* 54 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 56 */	NdrFcLong( 0x2 ),	/* 2 */
/* 60 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 62 */	NdrFcLong( 0x4 ),	/* 4 */
/* 66 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 68 */	NdrFcLong( 0x5 ),	/* 5 */
/* 72 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 74 */	NdrFcLong( 0xb ),	/* 11 */
/* 78 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 80 */	NdrFcLong( 0xa ),	/* 10 */
/* 84 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 86 */	NdrFcLong( 0x6 ),	/* 6 */
/* 90 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (322) */
/* 92 */	NdrFcLong( 0x7 ),	/* 7 */
/* 96 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 98 */	NdrFcLong( 0x8 ),	/* 8 */
/* 102 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (328) */
/* 104 */	NdrFcLong( 0xd ),	/* 13 */
/* 108 */	NdrFcShort( 0xf6 ),	/* Offset= 246 (354) */
/* 110 */	NdrFcLong( 0x9 ),	/* 9 */
/* 114 */	NdrFcShort( 0xff90 ),	/* Offset= -112 (2) */
/* 116 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 120 */	NdrFcShort( 0xfc ),	/* Offset= 252 (372) */
/* 122 */	NdrFcLong( 0x24 ),	/* 36 */
/* 126 */	NdrFcShort( 0x324 ),	/* Offset= 804 (930) */
/* 128 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 132 */	NdrFcShort( 0x31e ),	/* Offset= 798 (930) */
/* 134 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 138 */	NdrFcShort( 0x31c ),	/* Offset= 796 (934) */
/* 140 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 144 */	NdrFcShort( 0x31a ),	/* Offset= 794 (938) */
/* 146 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 150 */	NdrFcShort( 0x318 ),	/* Offset= 792 (942) */
/* 152 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 156 */	NdrFcShort( 0x316 ),	/* Offset= 790 (946) */
/* 158 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 162 */	NdrFcShort( 0x314 ),	/* Offset= 788 (950) */
/* 164 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 168 */	NdrFcShort( 0x312 ),	/* Offset= 786 (954) */
/* 170 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 174 */	NdrFcShort( 0x2fc ),	/* Offset= 764 (938) */
/* 176 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 180 */	NdrFcShort( 0x2fa ),	/* Offset= 762 (942) */
/* 182 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 186 */	NdrFcShort( 0x304 ),	/* Offset= 772 (958) */
/* 188 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 192 */	NdrFcShort( 0x2fa ),	/* Offset= 762 (954) */
/* 194 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 198 */	NdrFcShort( 0x2fc ),	/* Offset= 764 (962) */
/* 200 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 204 */	NdrFcShort( 0x2fa ),	/* Offset= 762 (966) */
/* 206 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 210 */	NdrFcShort( 0x2f8 ),	/* Offset= 760 (970) */
/* 212 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 216 */	NdrFcShort( 0x2f6 ),	/* Offset= 758 (974) */
/* 218 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 222 */	NdrFcShort( 0x2f4 ),	/* Offset= 756 (978) */
/* 224 */	NdrFcLong( 0x10 ),	/* 16 */
/* 228 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 230 */	NdrFcLong( 0x12 ),	/* 18 */
/* 234 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 236 */	NdrFcLong( 0x13 ),	/* 19 */
/* 240 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 242 */	NdrFcLong( 0x15 ),	/* 21 */
/* 246 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 248 */	NdrFcLong( 0x16 ),	/* 22 */
/* 252 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 254 */	NdrFcLong( 0x17 ),	/* 23 */
/* 258 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 260 */	NdrFcLong( 0xe ),	/* 14 */
/* 264 */	NdrFcShort( 0x2d2 ),	/* Offset= 722 (986) */
/* 266 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 270 */	NdrFcShort( 0x2d6 ),	/* Offset= 726 (996) */
/* 272 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 276 */	NdrFcShort( 0x2d4 ),	/* Offset= 724 (1000) */
/* 278 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 282 */	NdrFcShort( 0x290 ),	/* Offset= 656 (938) */
/* 284 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 288 */	NdrFcShort( 0x28e ),	/* Offset= 654 (942) */
/* 290 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 294 */	NdrFcShort( 0x28c ),	/* Offset= 652 (946) */
/* 296 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 300 */	NdrFcShort( 0x282 ),	/* Offset= 642 (942) */
/* 302 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 306 */	NdrFcShort( 0x27c ),	/* Offset= 636 (942) */
/* 308 */	NdrFcLong( 0x0 ),	/* 0 */
/* 312 */	NdrFcShort( 0x0 ),	/* Offset= 0 (312) */
/* 314 */	NdrFcLong( 0x1 ),	/* 1 */
/* 318 */	NdrFcShort( 0x0 ),	/* Offset= 0 (318) */
/* 320 */	NdrFcShort( 0xffff ),	/* Offset= -1 (319) */
/* 322 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 324 */	NdrFcShort( 0x8 ),	/* 8 */
/* 326 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 328 */	
			0x12, 0x0,	/* FC_UP */
/* 330 */	NdrFcShort( 0xe ),	/* Offset= 14 (344) */
/* 332 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 334 */	NdrFcShort( 0x2 ),	/* 2 */
/* 336 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 338 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 340 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 342 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 344 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 346 */	NdrFcShort( 0x8 ),	/* 8 */
/* 348 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (332) */
/* 350 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 352 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 354 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 356 */	NdrFcLong( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 364 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 366 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 368 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 370 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 372 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 374 */	NdrFcShort( 0x2 ),	/* Offset= 2 (376) */
/* 376 */	
			0x12, 0x0,	/* FC_UP */
/* 378 */	NdrFcShort( 0x216 ),	/* Offset= 534 (912) */
/* 380 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 382 */	NdrFcShort( 0x18 ),	/* 24 */
/* 384 */	NdrFcShort( 0xa ),	/* 10 */
/* 386 */	NdrFcLong( 0x8 ),	/* 8 */
/* 390 */	NdrFcShort( 0x5a ),	/* Offset= 90 (480) */
/* 392 */	NdrFcLong( 0xd ),	/* 13 */
/* 396 */	NdrFcShort( 0x7e ),	/* Offset= 126 (522) */
/* 398 */	NdrFcLong( 0x9 ),	/* 9 */
/* 402 */	NdrFcShort( 0x9e ),	/* Offset= 158 (560) */
/* 404 */	NdrFcLong( 0xc ),	/* 12 */
/* 408 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (608) */
/* 410 */	NdrFcLong( 0x24 ),	/* 36 */
/* 414 */	NdrFcShort( 0x124 ),	/* Offset= 292 (706) */
/* 416 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 420 */	NdrFcShort( 0x140 ),	/* Offset= 320 (740) */
/* 422 */	NdrFcLong( 0x10 ),	/* 16 */
/* 426 */	NdrFcShort( 0x15a ),	/* Offset= 346 (772) */
/* 428 */	NdrFcLong( 0x2 ),	/* 2 */
/* 432 */	NdrFcShort( 0x174 ),	/* Offset= 372 (804) */
/* 434 */	NdrFcLong( 0x3 ),	/* 3 */
/* 438 */	NdrFcShort( 0x18e ),	/* Offset= 398 (836) */
/* 440 */	NdrFcLong( 0x14 ),	/* 20 */
/* 444 */	NdrFcShort( 0x1a8 ),	/* Offset= 424 (868) */
/* 446 */	NdrFcShort( 0xffff ),	/* Offset= -1 (445) */
/* 448 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 450 */	NdrFcShort( 0x4 ),	/* 4 */
/* 452 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 458 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 460 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 462 */	NdrFcShort( 0x4 ),	/* 4 */
/* 464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 466 */	NdrFcShort( 0x1 ),	/* 1 */
/* 468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 472 */	0x12, 0x0,	/* FC_UP */
/* 474 */	NdrFcShort( 0xff7e ),	/* Offset= -130 (344) */
/* 476 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 478 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 480 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 482 */	NdrFcShort( 0x8 ),	/* 8 */
/* 484 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 486 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 488 */	NdrFcShort( 0x4 ),	/* 4 */
/* 490 */	NdrFcShort( 0x4 ),	/* 4 */
/* 492 */	0x11, 0x0,	/* FC_RP */
/* 494 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (448) */
/* 496 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 498 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 500 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 504 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 508 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 510 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 514 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 516 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 518 */	NdrFcShort( 0xff5c ),	/* Offset= -164 (354) */
/* 520 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 522 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 524 */	NdrFcShort( 0x8 ),	/* 8 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x6 ),	/* Offset= 6 (534) */
/* 530 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 532 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 534 */	
			0x11, 0x0,	/* FC_RP */
/* 536 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (500) */
/* 538 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 542 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 546 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 548 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 552 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 554 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 556 */	NdrFcShort( 0xfdd6 ),	/* Offset= -554 (2) */
/* 558 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 560 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 562 */	NdrFcShort( 0x8 ),	/* 8 */
/* 564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 566 */	NdrFcShort( 0x6 ),	/* Offset= 6 (572) */
/* 568 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 570 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 572 */	
			0x11, 0x0,	/* FC_RP */
/* 574 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (538) */
/* 576 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 578 */	NdrFcShort( 0x4 ),	/* 4 */
/* 580 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 584 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 586 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 588 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 590 */	NdrFcShort( 0x4 ),	/* 4 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x1 ),	/* 1 */
/* 596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 600 */	0x12, 0x0,	/* FC_UP */
/* 602 */	NdrFcShort( 0x192 ),	/* Offset= 402 (1004) */
/* 604 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 606 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 608 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 610 */	NdrFcShort( 0x8 ),	/* 8 */
/* 612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 614 */	NdrFcShort( 0x6 ),	/* Offset= 6 (620) */
/* 616 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 618 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 620 */	
			0x11, 0x0,	/* FC_RP */
/* 622 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (576) */
/* 624 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 626 */	NdrFcLong( 0x2f ),	/* 47 */
/* 630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 634 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 636 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 638 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 640 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 642 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 644 */	NdrFcShort( 0x1 ),	/* 1 */
/* 646 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 648 */	NdrFcShort( 0x4 ),	/* 4 */
/* 650 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 652 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 654 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 656 */	NdrFcShort( 0x10 ),	/* 16 */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 660 */	NdrFcShort( 0xa ),	/* Offset= 10 (670) */
/* 662 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 664 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 666 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (624) */
/* 668 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 670 */	
			0x12, 0x0,	/* FC_UP */
/* 672 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (642) */
/* 674 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 676 */	NdrFcShort( 0x4 ),	/* 4 */
/* 678 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 682 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 684 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 686 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 688 */	NdrFcShort( 0x4 ),	/* 4 */
/* 690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 692 */	NdrFcShort( 0x1 ),	/* 1 */
/* 694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 698 */	0x12, 0x0,	/* FC_UP */
/* 700 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (654) */
/* 702 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 704 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 706 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 708 */	NdrFcShort( 0x8 ),	/* 8 */
/* 710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 712 */	NdrFcShort( 0x6 ),	/* Offset= 6 (718) */
/* 714 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 716 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 718 */	
			0x11, 0x0,	/* FC_RP */
/* 720 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (674) */
/* 722 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 724 */	NdrFcShort( 0x8 ),	/* 8 */
/* 726 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 728 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 730 */	NdrFcShort( 0x10 ),	/* 16 */
/* 732 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 734 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 736 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (722) */
			0x5b,		/* FC_END */
/* 740 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 742 */	NdrFcShort( 0x18 ),	/* 24 */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	NdrFcShort( 0xa ),	/* Offset= 10 (756) */
/* 748 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 750 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 752 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (728) */
/* 754 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 756 */	
			0x11, 0x0,	/* FC_RP */
/* 758 */	NdrFcShort( 0xfefe ),	/* Offset= -258 (500) */
/* 760 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 762 */	NdrFcShort( 0x1 ),	/* 1 */
/* 764 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 768 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 770 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 772 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 774 */	NdrFcShort( 0x8 ),	/* 8 */
/* 776 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 778 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 780 */	NdrFcShort( 0x4 ),	/* 4 */
/* 782 */	NdrFcShort( 0x4 ),	/* 4 */
/* 784 */	0x12, 0x0,	/* FC_UP */
/* 786 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (760) */
/* 788 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 790 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 792 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 794 */	NdrFcShort( 0x2 ),	/* 2 */
/* 796 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 800 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 802 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 804 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 806 */	NdrFcShort( 0x8 ),	/* 8 */
/* 808 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 810 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 812 */	NdrFcShort( 0x4 ),	/* 4 */
/* 814 */	NdrFcShort( 0x4 ),	/* 4 */
/* 816 */	0x12, 0x0,	/* FC_UP */
/* 818 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (792) */
/* 820 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 822 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 824 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 826 */	NdrFcShort( 0x4 ),	/* 4 */
/* 828 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 832 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 834 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 836 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 838 */	NdrFcShort( 0x8 ),	/* 8 */
/* 840 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 842 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 844 */	NdrFcShort( 0x4 ),	/* 4 */
/* 846 */	NdrFcShort( 0x4 ),	/* 4 */
/* 848 */	0x12, 0x0,	/* FC_UP */
/* 850 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (824) */
/* 852 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 854 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 856 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 858 */	NdrFcShort( 0x8 ),	/* 8 */
/* 860 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 864 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 866 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 868 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 870 */	NdrFcShort( 0x8 ),	/* 8 */
/* 872 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 874 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 876 */	NdrFcShort( 0x4 ),	/* 4 */
/* 878 */	NdrFcShort( 0x4 ),	/* 4 */
/* 880 */	0x12, 0x0,	/* FC_UP */
/* 882 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (856) */
/* 884 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 886 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 888 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 890 */	NdrFcShort( 0x8 ),	/* 8 */
/* 892 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 894 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 896 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 900 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 902 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 904 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 906 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 908 */	NdrFcShort( 0xffec ),	/* Offset= -20 (888) */
/* 910 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 912 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 914 */	NdrFcShort( 0x28 ),	/* 40 */
/* 916 */	NdrFcShort( 0xffec ),	/* Offset= -20 (896) */
/* 918 */	NdrFcShort( 0x0 ),	/* Offset= 0 (918) */
/* 920 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 922 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 924 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 926 */	NdrFcShort( 0xfdde ),	/* Offset= -546 (380) */
/* 928 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 930 */	
			0x12, 0x0,	/* FC_UP */
/* 932 */	NdrFcShort( 0xfeea ),	/* Offset= -278 (654) */
/* 934 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 936 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 938 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 940 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 942 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 944 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 946 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 948 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 950 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 952 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 954 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 956 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 958 */	
			0x12, 0x0,	/* FC_UP */
/* 960 */	NdrFcShort( 0xfd82 ),	/* Offset= -638 (322) */
/* 962 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 964 */	NdrFcShort( 0xfd84 ),	/* Offset= -636 (328) */
/* 966 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 968 */	NdrFcShort( 0xfd9a ),	/* Offset= -614 (354) */
/* 970 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 972 */	NdrFcShort( 0xfc36 ),	/* Offset= -970 (2) */
/* 974 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 976 */	NdrFcShort( 0xfda4 ),	/* Offset= -604 (372) */
/* 978 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 980 */	NdrFcShort( 0x2 ),	/* Offset= 2 (982) */
/* 982 */	
			0x12, 0x0,	/* FC_UP */
/* 984 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1004) */
/* 986 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 988 */	NdrFcShort( 0x10 ),	/* 16 */
/* 990 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 992 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 994 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 996 */	
			0x12, 0x0,	/* FC_UP */
/* 998 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (986) */
/* 1000 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1002 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1004 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1006 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1010 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1010) */
/* 1012 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1014 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1016 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1018 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1020 */	NdrFcShort( 0xfc1c ),	/* Offset= -996 (24) */
/* 1022 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1024 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1026 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1028 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0xfc0c ),	/* Offset= -1012 (20) */
/* 1034 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1036 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1042) */
/* 1038 */	
			0x13, 0x0,	/* FC_OP */
/* 1040 */	NdrFcShort( 0xfd48 ),	/* Offset= -696 (344) */
/* 1042 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1044 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1046 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1038) */
/* 1052 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1054 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1056 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1060 */	NdrFcShort( 0xfd24 ),	/* Offset= -732 (328) */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            },
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDHTMLCtlUI, ver. 0.0,
   GUID={0xCC72F349,0xA155,0x4E77,{0xBA,0xE6,0x29,0xEE,0xB8,0x35,0x5A,0xC0}} */

#pragma code_seg(".orpc")
static const unsigned short IDHTMLCtlUI_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    42
    };

static const MIDL_STUBLESS_PROXY_INFO IDHTMLCtlUI_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IDHTMLCtlUI_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDHTMLCtlUI_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IDHTMLCtlUI_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IDHTMLCtlUIProxyVtbl = 
{
    &IDHTMLCtlUI_ProxyInfo,
    &IID_IDHTMLCtlUI,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDHTMLCtlUI::OnClick */ ,
    (void *) (INT_PTR) -1 /* IDHTMLCtlUI::GoTo */
};


static const PRPC_STUB_FUNCTION IDHTMLCtlUI_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IDHTMLCtlUIStubVtbl =
{
    &IID_IDHTMLCtlUI,
    &IDHTMLCtlUI_ServerInfo,
    9,
    &IDHTMLCtlUI_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IDHTMLCtl, ver. 0.0,
   GUID={0x301363E5,0x1A3D,0x45E5,{0x9A,0xC5,0x0D,0x85,0x96,0xAF,0x5F,0x86}} */

#pragma code_seg(".orpc")
static const unsigned short IDHTMLCtl_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    72,
    108,
    144
    };

static const MIDL_STUBLESS_PROXY_INFO IDHTMLCtl_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IDHTMLCtl_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDHTMLCtl_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IDHTMLCtl_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IDHTMLCtlProxyVtbl = 
{
    &IDHTMLCtl_ProxyInfo,
    &IID_IDHTMLCtl,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDHTMLCtl::get_UrlPath */ ,
    (void *) (INT_PTR) -1 /* IDHTMLCtl::put_UrlPath */ ,
    (void *) (INT_PTR) -1 /* IDHTMLCtl::GoToURL */
};


static const PRPC_STUB_FUNCTION IDHTMLCtl_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IDHTMLCtlStubVtbl =
{
    &IID_IDHTMLCtl,
    &IDHTMLCtl_ServerInfo,
    10,
    &IDHTMLCtl_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x6000169, /* MIDL Version 6.0.361 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * __DHTML_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IDHTMLCtlUIProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDHTMLCtlProxyVtbl,
    0
};

const CInterfaceStubVtbl * __DHTML_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IDHTMLCtlUIStubVtbl,
    ( CInterfaceStubVtbl *) &_IDHTMLCtlStubVtbl,
    0
};

PCInterfaceName const __DHTML_InterfaceNamesList[] = 
{
    "IDHTMLCtlUI",
    "IDHTMLCtl",
    0
};

const IID *  __DHTML_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define __DHTML_CHECK_IID(n)	IID_GENERIC_CHECK_IID( __DHTML, pIID, n)

int __stdcall __DHTML_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( __DHTML, 2, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( __DHTML, 2, *pIndex )
    
}

const ExtendedProxyFileInfo _DHTML_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & __DHTML_ProxyVtblList,
    (PCInterfaceStubVtblList *) & __DHTML_StubVtblList,
    (const PCInterfaceName * ) & __DHTML_InterfaceNamesList,
    (const IID ** ) & __DHTML_BaseIIDList,
    & __DHTML_IID_Lookup, 
    2,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

