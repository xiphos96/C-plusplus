

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Tue Mar 16 17:36:22 2004
 */
/* Compiler settings for _AddEnd.idl:
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

#ifndef ___AddEnd_h__
#define ___AddEnd_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAddEnd_FWD_DEFINED__
#define __IAddEnd_FWD_DEFINED__
typedef interface IAddEnd IAddEnd;
#endif 	/* __IAddEnd_FWD_DEFINED__ */


#ifndef __CAddEnd_FWD_DEFINED__
#define __CAddEnd_FWD_DEFINED__

#ifdef __cplusplus
typedef class CAddEnd CAddEnd;
#else
typedef struct CAddEnd CAddEnd;
#endif /* __cplusplus */

#endif 	/* __CAddEnd_FWD_DEFINED__ */


/* header files for imported files */
#include "prsht.h"
#include "mshtml.h"
#include "mshtmhst.h"
#include "exdisp.h"
#include "objsafe.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IAddEnd_INTERFACE_DEFINED__
#define __IAddEnd_INTERFACE_DEFINED__

/* interface IAddEnd */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAddEnd;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B60724AA-9874-4C9A-B53F-ED2FFD36738F")
    IAddEnd : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AddEnd( 
            /* [retval][out] */ SHORT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AddEnd( 
            /* [in] */ SHORT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Sum( 
            /* [retval][out] */ SHORT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Sum( 
            /* [in] */ SHORT newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
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
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAddEnd * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAddEnd * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAddEnd * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAddEnd * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AddEnd )( 
            IAddEnd * This,
            /* [retval][out] */ SHORT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AddEnd )( 
            IAddEnd * This,
            /* [in] */ SHORT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Sum )( 
            IAddEnd * This,
            /* [retval][out] */ SHORT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Sum )( 
            IAddEnd * This,
            /* [in] */ SHORT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
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


#define IAddEnd_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAddEnd_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAddEnd_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAddEnd_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAddEnd_get_AddEnd(This,pVal)	\
    (This)->lpVtbl -> get_AddEnd(This,pVal)

#define IAddEnd_put_AddEnd(This,newVal)	\
    (This)->lpVtbl -> put_AddEnd(This,newVal)

#define IAddEnd_get_Sum(This,pVal)	\
    (This)->lpVtbl -> get_Sum(This,pVal)

#define IAddEnd_put_Sum(This,newVal)	\
    (This)->lpVtbl -> put_Sum(This,newVal)

#define IAddEnd_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAddEnd_get_AddEnd_Proxy( 
    IAddEnd * This,
    /* [retval][out] */ SHORT *pVal);


void __RPC_STUB IAddEnd_get_AddEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAddEnd_put_AddEnd_Proxy( 
    IAddEnd * This,
    /* [in] */ SHORT newVal);


void __RPC_STUB IAddEnd_put_AddEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAddEnd_get_Sum_Proxy( 
    IAddEnd * This,
    /* [retval][out] */ SHORT *pVal);


void __RPC_STUB IAddEnd_get_Sum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAddEnd_put_Sum_Proxy( 
    IAddEnd * This,
    /* [in] */ SHORT newVal);


void __RPC_STUB IAddEnd_put_Sum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAddEnd_Clear_Proxy( 
    IAddEnd * This);


void __RPC_STUB IAddEnd_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAddEnd_INTERFACE_DEFINED__ */



#ifndef __AddEnd_LIBRARY_DEFINED__
#define __AddEnd_LIBRARY_DEFINED__

/* library AddEnd */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_AddEnd;

EXTERN_C const CLSID CLSID_CAddEnd;

#ifdef __cplusplus

class DECLSPEC_UUID("74FD8F48-4B50-4DB3-B195-B74A4B79393F")
CAddEnd;
#endif
#endif /* __AddEnd_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


