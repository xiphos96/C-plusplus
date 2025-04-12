

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Tue Mar 23 10:29:58 2004
 */
/* Compiler settings for .\RemOutServer.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __RemOutServer_h__
#define __RemOutServer_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAddEnd_FWD_DEFINED__
#define __IAddEnd_FWD_DEFINED__
typedef interface IAddEnd IAddEnd;
#endif 	/* __IAddEnd_FWD_DEFINED__ */


#ifndef __IAdd_FWD_DEFINED__
#define __IAdd_FWD_DEFINED__
typedef interface IAdd IAdd;
#endif 	/* __IAdd_FWD_DEFINED__ */


#ifndef __RemOutServer_FWD_DEFINED__
#define __RemOutServer_FWD_DEFINED__

#ifdef __cplusplus
typedef class RemOutServer RemOutServer;
#else
typedef struct RemOutServer RemOutServer;
#endif /* __cplusplus */

#endif 	/* __RemOutServer_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IAddEnd_INTERFACE_DEFINED__
#define __IAddEnd_INTERFACE_DEFINED__

/* interface IAddEnd */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAddEnd;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6D8A8A88-F393-4CEB-B54B-7CC5C4F7ACAE")
    IAddEnd : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AddEnd( 
            /* [retval][out] */ SHORT *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_AddEnd( 
            /* [in] */ SHORT newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Sum( 
            /* [retval][out] */ SHORT *pVal) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAddEndVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAddEnd * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAddEnd * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAddEnd * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AddEnd )( 
            IAddEnd * This,
            /* [retval][out] */ SHORT *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AddEnd )( 
            IAddEnd * This,
            /* [in] */ SHORT newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Sum )( 
            IAddEnd * This,
            /* [retval][out] */ SHORT *pVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IAddEnd * This);
        
        END_INTERFACE
    } IAddEndVtbl;

    interface IAddEnd
    {
        CONST_VTBL struct IAddEndVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAddEnd_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAddEnd_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAddEnd_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAddEnd_get_AddEnd(This,pVal)	\
    (This)->lpVtbl -> get_AddEnd(This,pVal)

#define IAddEnd_put_AddEnd(This,newVal)	\
    (This)->lpVtbl -> put_AddEnd(This,newVal)

#define IAddEnd_get_Sum(This,pVal)	\
    (This)->lpVtbl -> get_Sum(This,pVal)

#define IAddEnd_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IAddEnd_get_AddEnd_Proxy( 
    IAddEnd * This,
    /* [retval][out] */ SHORT *pVal);


void __RPC_STUB IAddEnd_get_AddEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IAddEnd_put_AddEnd_Proxy( 
    IAddEnd * This,
    /* [in] */ SHORT newVal);


void __RPC_STUB IAddEnd_put_AddEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IAddEnd_get_Sum_Proxy( 
    IAddEnd * This,
    /* [retval][out] */ SHORT *pVal);


void __RPC_STUB IAddEnd_get_Sum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAddEnd_Clear_Proxy( 
    IAddEnd * This);


void __RPC_STUB IAddEnd_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAddEnd_INTERFACE_DEFINED__ */


#ifndef __IAdd_INTERFACE_DEFINED__
#define __IAdd_INTERFACE_DEFINED__

/* interface IAdd */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IAdd;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("727F03FE-D17C-4b35-8822-C411CF069D4B")
    IAdd : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Add( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddTen( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAddVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAdd * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAdd * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAdd * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IAdd * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddTen )( 
            IAdd * This);
        
        END_INTERFACE
    } IAddVtbl;

    interface IAdd
    {
        CONST_VTBL struct IAddVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAdd_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAdd_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAdd_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAdd_Add(This)	\
    (This)->lpVtbl -> Add(This)

#define IAdd_AddTen(This)	\
    (This)->lpVtbl -> AddTen(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAdd_Add_Proxy( 
    IAdd * This);


void __RPC_STUB IAdd_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IAdd_AddTen_Proxy( 
    IAdd * This);


void __RPC_STUB IAdd_AddTen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAdd_INTERFACE_DEFINED__ */



#ifndef __RemOutServerLib_LIBRARY_DEFINED__
#define __RemOutServerLib_LIBRARY_DEFINED__

/* library RemOutServerLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_RemOutServerLib;

EXTERN_C const CLSID CLSID_RemOutServer;

#ifdef __cplusplus

class DECLSPEC_UUID("1C5CC077-597A-4DAC-8FB2-C5492D4E0487")
RemOutServer;
#endif
#endif /* __RemOutServerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


