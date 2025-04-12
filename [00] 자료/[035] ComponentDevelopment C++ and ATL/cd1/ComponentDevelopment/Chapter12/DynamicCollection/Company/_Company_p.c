

/* this ALWAYS GENERATED file contains the proxy stub code */


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


#include "_Company.h"

#define TYPE_FORMAT_STRING_SIZE   1097                              
#define PROC_FORMAT_STRING_SIZE   439                               
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


extern const MIDL_SERVER_INFO IEmployee_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IEmployee_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IEmployees_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IEmployees_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ICompany_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ICompany_ProxyInfo;


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

	/* Procedure get_Name */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 18 */	NdrFcShort( 0x1 ),	/* 1 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 24 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Name */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 52 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x1 ),	/* 1 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 60 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 68 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Address */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 74 */	NdrFcLong( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x9 ),	/* 9 */
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
/* 100 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Return value */

/* 102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Address */

/* 108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0xa ),	/* 10 */
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
/* 136 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 140 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Telephone */

/* 144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0xb ),	/* 11 */
/* 152 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 158 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 160 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 162 */	NdrFcShort( 0x1 ),	/* 1 */
/* 164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 168 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 170 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 172 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Return value */

/* 174 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 176 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Telephone */

/* 180 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0xc ),	/* 12 */
/* 188 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 192 */	NdrFcShort( 0x8 ),	/* 8 */
/* 194 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 196 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 200 */	NdrFcShort( 0x1 ),	/* 1 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 204 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 206 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 208 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 210 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 212 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Count */

/* 216 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0x7 ),	/* 7 */
/* 224 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0x24 ),	/* 36 */
/* 230 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 232 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 240 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 242 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 248 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0x8 ),	/* 8 */
/* 260 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 262 */	NdrFcShort( 0x8 ),	/* 8 */
/* 264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 266 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 268 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 276 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 278 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 282 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 284 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 286 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 288 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 290 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get__NewEnum */

/* 294 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 296 */	NdrFcLong( 0x0 ),	/* 0 */
/* 300 */	NdrFcShort( 0x9 ),	/* 9 */
/* 302 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 306 */	NdrFcShort( 0x8 ),	/* 8 */
/* 308 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 310 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 316 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 318 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 320 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 322 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 324 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 326 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Add */

/* 330 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 332 */	NdrFcLong( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0xa ),	/* 10 */
/* 338 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 342 */	NdrFcShort( 0x8 ),	/* 8 */
/* 344 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 346 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 352 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retVal */

/* 354 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 356 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 358 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 360 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 362 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Remove */

/* 366 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 372 */	NdrFcShort( 0xb ),	/* 11 */
/* 374 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 376 */	NdrFcShort( 0x8 ),	/* 8 */
/* 378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 380 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 382 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 388 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 390 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 392 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 396 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 398 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Employees */

/* 402 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 408 */	NdrFcShort( 0x7 ),	/* 7 */
/* 410 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 416 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 418 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 420 */	NdrFcShort( 0x20 ),	/* 32 */
/* 422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 424 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 426 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 428 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 430 */	NdrFcShort( 0x43e ),	/* Type Offset=1086 */

	/* Return value */

/* 432 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 434 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 436 */	0x8,		/* FC_LONG */
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
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/*  4 */	NdrFcShort( 0x1c ),	/* Offset= 28 (32) */
/*  6 */	
			0x13, 0x0,	/* FC_OP */
/*  8 */	NdrFcShort( 0xe ),	/* Offset= 14 (22) */
/* 10 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 12 */	NdrFcShort( 0x2 ),	/* 2 */
/* 14 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 16 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 18 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 20 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 22 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 24 */	NdrFcShort( 0x8 ),	/* 8 */
/* 26 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (10) */
/* 28 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 30 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 32 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 34 */	NdrFcShort( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0x4 ),	/* 4 */
/* 38 */	NdrFcShort( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0xffde ),	/* Offset= -34 (6) */
/* 42 */	
			0x12, 0x0,	/* FC_UP */
/* 44 */	NdrFcShort( 0xffea ),	/* Offset= -22 (22) */
/* 46 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x4 ),	/* 4 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */
/* 54 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (42) */
/* 56 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 58 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 60 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 62 */	NdrFcShort( 0x2 ),	/* Offset= 2 (64) */
/* 64 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 66 */	NdrFcLong( 0xad77d5d9 ),	/* -1384655399 */
/* 70 */	NdrFcShort( 0x51a6 ),	/* 20902 */
/* 72 */	NdrFcShort( 0x4d18 ),	/* 19736 */
/* 74 */	0x91,		/* 145 */
			0x8f,		/* 143 */
/* 76 */	0x8f,		/* 143 */
			0xcf,		/* 207 */
/* 78 */	0xb0,		/* 176 */
			0xdf,		/* 223 */
/* 80 */	0xc8,		/* 200 */
			0xcf,		/* 207 */
/* 82 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 84 */	NdrFcShort( 0x2 ),	/* Offset= 2 (86) */
/* 86 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 88 */	NdrFcLong( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */
/* 96 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 98 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 100 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 102 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 104 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 106 */	NdrFcShort( 0x3d4 ),	/* Offset= 980 (1086) */
/* 108 */	
			0x13, 0x0,	/* FC_OP */
/* 110 */	NdrFcShort( 0x3bc ),	/* Offset= 956 (1066) */
/* 112 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 114 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 116 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 118 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 120 */	NdrFcShort( 0x2 ),	/* Offset= 2 (122) */
/* 122 */	NdrFcShort( 0x10 ),	/* 16 */
/* 124 */	NdrFcShort( 0x2f ),	/* 47 */
/* 126 */	NdrFcLong( 0x14 ),	/* 20 */
/* 130 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 132 */	NdrFcLong( 0x3 ),	/* 3 */
/* 136 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 138 */	NdrFcLong( 0x11 ),	/* 17 */
/* 142 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 144 */	NdrFcLong( 0x2 ),	/* 2 */
/* 148 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 150 */	NdrFcLong( 0x4 ),	/* 4 */
/* 154 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 156 */	NdrFcLong( 0x5 ),	/* 5 */
/* 160 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 162 */	NdrFcLong( 0xb ),	/* 11 */
/* 166 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 168 */	NdrFcLong( 0xa ),	/* 10 */
/* 172 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 174 */	NdrFcLong( 0x6 ),	/* 6 */
/* 178 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (410) */
/* 180 */	NdrFcLong( 0x7 ),	/* 7 */
/* 184 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 186 */	NdrFcLong( 0x8 ),	/* 8 */
/* 190 */	NdrFcShort( 0xff48 ),	/* Offset= -184 (6) */
/* 192 */	NdrFcLong( 0xd ),	/* 13 */
/* 196 */	NdrFcShort( 0xff92 ),	/* Offset= -110 (86) */
/* 198 */	NdrFcLong( 0x9 ),	/* 9 */
/* 202 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (416) */
/* 204 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 208 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (434) */
/* 210 */	NdrFcLong( 0x24 ),	/* 36 */
/* 214 */	NdrFcShort( 0x30a ),	/* Offset= 778 (992) */
/* 216 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 220 */	NdrFcShort( 0x304 ),	/* Offset= 772 (992) */
/* 222 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 226 */	NdrFcShort( 0x302 ),	/* Offset= 770 (996) */
/* 228 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 232 */	NdrFcShort( 0x300 ),	/* Offset= 768 (1000) */
/* 234 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 238 */	NdrFcShort( 0x2fe ),	/* Offset= 766 (1004) */
/* 240 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 244 */	NdrFcShort( 0x2fc ),	/* Offset= 764 (1008) */
/* 246 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 250 */	NdrFcShort( 0x2fa ),	/* Offset= 762 (1012) */
/* 252 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 256 */	NdrFcShort( 0x2f8 ),	/* Offset= 760 (1016) */
/* 258 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 262 */	NdrFcShort( 0x2e2 ),	/* Offset= 738 (1000) */
/* 264 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 268 */	NdrFcShort( 0x2e0 ),	/* Offset= 736 (1004) */
/* 270 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 274 */	NdrFcShort( 0x2ea ),	/* Offset= 746 (1020) */
/* 276 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 280 */	NdrFcShort( 0x2e0 ),	/* Offset= 736 (1016) */
/* 282 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 286 */	NdrFcShort( 0x2e2 ),	/* Offset= 738 (1024) */
/* 288 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 292 */	NdrFcShort( 0x2e0 ),	/* Offset= 736 (1028) */
/* 294 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 298 */	NdrFcShort( 0x2de ),	/* Offset= 734 (1032) */
/* 300 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 304 */	NdrFcShort( 0x2dc ),	/* Offset= 732 (1036) */
/* 306 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 310 */	NdrFcShort( 0x2da ),	/* Offset= 730 (1040) */
/* 312 */	NdrFcLong( 0x10 ),	/* 16 */
/* 316 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 318 */	NdrFcLong( 0x12 ),	/* 18 */
/* 322 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 324 */	NdrFcLong( 0x13 ),	/* 19 */
/* 328 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 330 */	NdrFcLong( 0x15 ),	/* 21 */
/* 334 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 336 */	NdrFcLong( 0x16 ),	/* 22 */
/* 340 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 342 */	NdrFcLong( 0x17 ),	/* 23 */
/* 346 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 348 */	NdrFcLong( 0xe ),	/* 14 */
/* 352 */	NdrFcShort( 0x2b8 ),	/* Offset= 696 (1048) */
/* 354 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 358 */	NdrFcShort( 0x2bc ),	/* Offset= 700 (1058) */
/* 360 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 364 */	NdrFcShort( 0x2ba ),	/* Offset= 698 (1062) */
/* 366 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 370 */	NdrFcShort( 0x276 ),	/* Offset= 630 (1000) */
/* 372 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 376 */	NdrFcShort( 0x274 ),	/* Offset= 628 (1004) */
/* 378 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 382 */	NdrFcShort( 0x272 ),	/* Offset= 626 (1008) */
/* 384 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 388 */	NdrFcShort( 0x268 ),	/* Offset= 616 (1004) */
/* 390 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 394 */	NdrFcShort( 0x262 ),	/* Offset= 610 (1004) */
/* 396 */	NdrFcLong( 0x0 ),	/* 0 */
/* 400 */	NdrFcShort( 0x0 ),	/* Offset= 0 (400) */
/* 402 */	NdrFcLong( 0x1 ),	/* 1 */
/* 406 */	NdrFcShort( 0x0 ),	/* Offset= 0 (406) */
/* 408 */	NdrFcShort( 0xffff ),	/* Offset= -1 (407) */
/* 410 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 414 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 416 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 418 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 426 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 428 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 430 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 432 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 434 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 436 */	NdrFcShort( 0x2 ),	/* Offset= 2 (438) */
/* 438 */	
			0x13, 0x0,	/* FC_OP */
/* 440 */	NdrFcShort( 0x216 ),	/* Offset= 534 (974) */
/* 442 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 444 */	NdrFcShort( 0x18 ),	/* 24 */
/* 446 */	NdrFcShort( 0xa ),	/* 10 */
/* 448 */	NdrFcLong( 0x8 ),	/* 8 */
/* 452 */	NdrFcShort( 0x5a ),	/* Offset= 90 (542) */
/* 454 */	NdrFcLong( 0xd ),	/* 13 */
/* 458 */	NdrFcShort( 0x7e ),	/* Offset= 126 (584) */
/* 460 */	NdrFcLong( 0x9 ),	/* 9 */
/* 464 */	NdrFcShort( 0x9e ),	/* Offset= 158 (622) */
/* 466 */	NdrFcLong( 0xc ),	/* 12 */
/* 470 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (670) */
/* 472 */	NdrFcLong( 0x24 ),	/* 36 */
/* 476 */	NdrFcShort( 0x124 ),	/* Offset= 292 (768) */
/* 478 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 482 */	NdrFcShort( 0x140 ),	/* Offset= 320 (802) */
/* 484 */	NdrFcLong( 0x10 ),	/* 16 */
/* 488 */	NdrFcShort( 0x15a ),	/* Offset= 346 (834) */
/* 490 */	NdrFcLong( 0x2 ),	/* 2 */
/* 494 */	NdrFcShort( 0x174 ),	/* Offset= 372 (866) */
/* 496 */	NdrFcLong( 0x3 ),	/* 3 */
/* 500 */	NdrFcShort( 0x18e ),	/* Offset= 398 (898) */
/* 502 */	NdrFcLong( 0x14 ),	/* 20 */
/* 506 */	NdrFcShort( 0x1a8 ),	/* Offset= 424 (930) */
/* 508 */	NdrFcShort( 0xffff ),	/* Offset= -1 (507) */
/* 510 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 512 */	NdrFcShort( 0x4 ),	/* 4 */
/* 514 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 518 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 520 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 522 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 524 */	NdrFcShort( 0x4 ),	/* 4 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x1 ),	/* 1 */
/* 530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 534 */	0x13, 0x0,	/* FC_OP */
/* 536 */	NdrFcShort( 0xfdfe ),	/* Offset= -514 (22) */
/* 538 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 540 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 542 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 544 */	NdrFcShort( 0x8 ),	/* 8 */
/* 546 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 548 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 550 */	NdrFcShort( 0x4 ),	/* 4 */
/* 552 */	NdrFcShort( 0x4 ),	/* 4 */
/* 554 */	0x11, 0x0,	/* FC_RP */
/* 556 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (510) */
/* 558 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 560 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 562 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 566 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 570 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 572 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 576 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 578 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 580 */	NdrFcShort( 0xfe12 ),	/* Offset= -494 (86) */
/* 582 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 584 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 586 */	NdrFcShort( 0x8 ),	/* 8 */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 590 */	NdrFcShort( 0x6 ),	/* Offset= 6 (596) */
/* 592 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 594 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 596 */	
			0x11, 0x0,	/* FC_RP */
/* 598 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (562) */
/* 600 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 604 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 608 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 610 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 614 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 616 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 618 */	NdrFcShort( 0xff36 ),	/* Offset= -202 (416) */
/* 620 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 622 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 624 */	NdrFcShort( 0x8 ),	/* 8 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	NdrFcShort( 0x6 ),	/* Offset= 6 (634) */
/* 630 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 632 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 634 */	
			0x11, 0x0,	/* FC_RP */
/* 636 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (600) */
/* 638 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 640 */	NdrFcShort( 0x4 ),	/* 4 */
/* 642 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 646 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 648 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 650 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 652 */	NdrFcShort( 0x4 ),	/* 4 */
/* 654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 656 */	NdrFcShort( 0x1 ),	/* 1 */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 662 */	0x13, 0x0,	/* FC_OP */
/* 664 */	NdrFcShort( 0x192 ),	/* Offset= 402 (1066) */
/* 666 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 668 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 670 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 676 */	NdrFcShort( 0x6 ),	/* Offset= 6 (682) */
/* 678 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 680 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 682 */	
			0x11, 0x0,	/* FC_RP */
/* 684 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (638) */
/* 686 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 688 */	NdrFcLong( 0x2f ),	/* 47 */
/* 692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 696 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 698 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 700 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 702 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 704 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 706 */	NdrFcShort( 0x1 ),	/* 1 */
/* 708 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 710 */	NdrFcShort( 0x4 ),	/* 4 */
/* 712 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 714 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 716 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 718 */	NdrFcShort( 0x10 ),	/* 16 */
/* 720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 722 */	NdrFcShort( 0xa ),	/* Offset= 10 (732) */
/* 724 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 726 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 728 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (686) */
/* 730 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 732 */	
			0x13, 0x0,	/* FC_OP */
/* 734 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (704) */
/* 736 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 738 */	NdrFcShort( 0x4 ),	/* 4 */
/* 740 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 744 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 746 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 748 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 750 */	NdrFcShort( 0x4 ),	/* 4 */
/* 752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 754 */	NdrFcShort( 0x1 ),	/* 1 */
/* 756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 760 */	0x13, 0x0,	/* FC_OP */
/* 762 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (716) */
/* 764 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 766 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 768 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 770 */	NdrFcShort( 0x8 ),	/* 8 */
/* 772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 774 */	NdrFcShort( 0x6 ),	/* Offset= 6 (780) */
/* 776 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 778 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 780 */	
			0x11, 0x0,	/* FC_RP */
/* 782 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (736) */
/* 784 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 786 */	NdrFcShort( 0x8 ),	/* 8 */
/* 788 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 790 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 792 */	NdrFcShort( 0x10 ),	/* 16 */
/* 794 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 796 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 798 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (784) */
			0x5b,		/* FC_END */
/* 802 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 804 */	NdrFcShort( 0x18 ),	/* 24 */
/* 806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 808 */	NdrFcShort( 0xa ),	/* Offset= 10 (818) */
/* 810 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 812 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 814 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (790) */
/* 816 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 818 */	
			0x11, 0x0,	/* FC_RP */
/* 820 */	NdrFcShort( 0xfefe ),	/* Offset= -258 (562) */
/* 822 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 824 */	NdrFcShort( 0x1 ),	/* 1 */
/* 826 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 830 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 832 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 834 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 836 */	NdrFcShort( 0x8 ),	/* 8 */
/* 838 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 840 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 842 */	NdrFcShort( 0x4 ),	/* 4 */
/* 844 */	NdrFcShort( 0x4 ),	/* 4 */
/* 846 */	0x13, 0x0,	/* FC_OP */
/* 848 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (822) */
/* 850 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 852 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 854 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 856 */	NdrFcShort( 0x2 ),	/* 2 */
/* 858 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 862 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 864 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 866 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 868 */	NdrFcShort( 0x8 ),	/* 8 */
/* 870 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 872 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 874 */	NdrFcShort( 0x4 ),	/* 4 */
/* 876 */	NdrFcShort( 0x4 ),	/* 4 */
/* 878 */	0x13, 0x0,	/* FC_OP */
/* 880 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (854) */
/* 882 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 884 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 886 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 888 */	NdrFcShort( 0x4 ),	/* 4 */
/* 890 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 894 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 896 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 898 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 900 */	NdrFcShort( 0x8 ),	/* 8 */
/* 902 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 904 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 906 */	NdrFcShort( 0x4 ),	/* 4 */
/* 908 */	NdrFcShort( 0x4 ),	/* 4 */
/* 910 */	0x13, 0x0,	/* FC_OP */
/* 912 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (886) */
/* 914 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 916 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 918 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 920 */	NdrFcShort( 0x8 ),	/* 8 */
/* 922 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 926 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 928 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 930 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 932 */	NdrFcShort( 0x8 ),	/* 8 */
/* 934 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 936 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 938 */	NdrFcShort( 0x4 ),	/* 4 */
/* 940 */	NdrFcShort( 0x4 ),	/* 4 */
/* 942 */	0x13, 0x0,	/* FC_OP */
/* 944 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (918) */
/* 946 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 948 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 950 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 952 */	NdrFcShort( 0x8 ),	/* 8 */
/* 954 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 956 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 958 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 960 */	NdrFcShort( 0x8 ),	/* 8 */
/* 962 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 964 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 966 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 968 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 970 */	NdrFcShort( 0xffec ),	/* Offset= -20 (950) */
/* 972 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 974 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 976 */	NdrFcShort( 0x28 ),	/* 40 */
/* 978 */	NdrFcShort( 0xffec ),	/* Offset= -20 (958) */
/* 980 */	NdrFcShort( 0x0 ),	/* Offset= 0 (980) */
/* 982 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 984 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 986 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 988 */	NdrFcShort( 0xfdde ),	/* Offset= -546 (442) */
/* 990 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 992 */	
			0x13, 0x0,	/* FC_OP */
/* 994 */	NdrFcShort( 0xfeea ),	/* Offset= -278 (716) */
/* 996 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 998 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 1000 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1002 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1004 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1006 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1008 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1010 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 1012 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1014 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 1016 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1018 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1020 */	
			0x13, 0x0,	/* FC_OP */
/* 1022 */	NdrFcShort( 0xfd9c ),	/* Offset= -612 (410) */
/* 1024 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1026 */	NdrFcShort( 0xfc04 ),	/* Offset= -1020 (6) */
/* 1028 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1030 */	NdrFcShort( 0xfc50 ),	/* Offset= -944 (86) */
/* 1032 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1034 */	NdrFcShort( 0xfd96 ),	/* Offset= -618 (416) */
/* 1036 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1038 */	NdrFcShort( 0xfda4 ),	/* Offset= -604 (434) */
/* 1040 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1042 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1044) */
/* 1044 */	
			0x13, 0x0,	/* FC_OP */
/* 1046 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1066) */
/* 1048 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1050 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1052 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 1054 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 1056 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1058 */	
			0x13, 0x0,	/* FC_OP */
/* 1060 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1048) */
/* 1062 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1064 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1066 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1068 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1072 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1072) */
/* 1074 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1076 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1078 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1080 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1082 */	NdrFcShort( 0xfc36 ),	/* Offset= -970 (112) */
/* 1084 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1086 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1088 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1090 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1094 */	NdrFcShort( 0xfc26 ),	/* Offset= -986 (108) */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IEmployee, ver. 0.0,
   GUID={0xAD77D5D9,0x51A6,0x4D18,{0x91,0x8F,0x8F,0xCF,0xB0,0xDF,0xC8,0xCF}} */

#pragma code_seg(".orpc")
static const unsigned short IEmployee_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36,
    72,
    108,
    144,
    180
    };

static const MIDL_STUBLESS_PROXY_INFO IEmployee_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IEmployee_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IEmployee_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IEmployee_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IEmployeeProxyVtbl = 
{
    &IEmployee_ProxyInfo,
    &IID_IEmployee,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IEmployee::get_Name */ ,
    (void *) (INT_PTR) -1 /* IEmployee::put_Name */ ,
    (void *) (INT_PTR) -1 /* IEmployee::get_Address */ ,
    (void *) (INT_PTR) -1 /* IEmployee::put_Address */ ,
    (void *) (INT_PTR) -1 /* IEmployee::get_Telephone */ ,
    (void *) (INT_PTR) -1 /* IEmployee::put_Telephone */
};


static const PRPC_STUB_FUNCTION IEmployee_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IEmployeeStubVtbl =
{
    &IID_IEmployee,
    &IEmployee_ServerInfo,
    13,
    &IEmployee_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IEmployees, ver. 0.0,
   GUID={0xC6783455,0x282B,0x4AB5,{0xBE,0xD5,0xC8,0xD3,0xA8,0xC3,0x8E,0x72}} */

#pragma code_seg(".orpc")
static const unsigned short IEmployees_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    216,
    252,
    294,
    330,
    366
    };

static const MIDL_STUBLESS_PROXY_INFO IEmployees_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IEmployees_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IEmployees_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IEmployees_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IEmployeesProxyVtbl = 
{
    &IEmployees_ProxyInfo,
    &IID_IEmployees,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IEmployees::get_Count */ ,
    (void *) (INT_PTR) -1 /* IEmployees::get_Item */ ,
    (void *) (INT_PTR) -1 /* IEmployees::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* IEmployees::Add */ ,
    (void *) (INT_PTR) -1 /* IEmployees::Remove */
};


static const PRPC_STUB_FUNCTION IEmployees_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IEmployeesStubVtbl =
{
    &IID_IEmployees,
    &IEmployees_ServerInfo,
    12,
    &IEmployees_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ICompany, ver. 0.0,
   GUID={0xE261C0DF,0xC91A,0x4E10,{0xAB,0xC4,0x0A,0x40,0x99,0xFC,0x8E,0x74}} */

#pragma code_seg(".orpc")
static const unsigned short ICompany_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    402
    };

static const MIDL_STUBLESS_PROXY_INFO ICompany_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ICompany_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ICompany_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ICompany_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _ICompanyProxyVtbl = 
{
    &ICompany_ProxyInfo,
    &IID_ICompany,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* ICompany::get_Employees */
};


static const PRPC_STUB_FUNCTION ICompany_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _ICompanyStubVtbl =
{
    &IID_ICompany,
    &ICompany_ServerInfo,
    8,
    &ICompany_table[-3],
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

const CInterfaceProxyVtbl * __Company_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IEmployeesProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IEmployeeProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ICompanyProxyVtbl,
    0
};

const CInterfaceStubVtbl * __Company_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IEmployeesStubVtbl,
    ( CInterfaceStubVtbl *) &_IEmployeeStubVtbl,
    ( CInterfaceStubVtbl *) &_ICompanyStubVtbl,
    0
};

PCInterfaceName const __Company_InterfaceNamesList[] = 
{
    "IEmployees",
    "IEmployee",
    "ICompany",
    0
};

const IID *  __Company_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define __Company_CHECK_IID(n)	IID_GENERIC_CHECK_IID( __Company, pIID, n)

int __stdcall __Company_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( __Company, 3, 2 )
    IID_BS_LOOKUP_NEXT_TEST( __Company, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( __Company, 3, *pIndex )
    
}

const ExtendedProxyFileInfo _Company_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & __Company_ProxyVtblList,
    (PCInterfaceStubVtblList *) & __Company_StubVtblList,
    (const PCInterfaceName * ) & __Company_InterfaceNamesList,
    (const IID ** ) & __Company_BaseIIDList,
    & __Company_IID_Lookup, 
    3,
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

