

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Tue Mar 16 14:04:28 2004
 */
/* Compiler settings for vc70.idl:
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

#ifndef __vc70_h__
#define __vc70_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAddBack_FWD_DEFINED__
#define __IAddBack_FWD_DEFINED__
typedef interface IAddBack IAddBack;
#endif 	/* __IAddBack_FWD_DEFINED__ */


#ifndef ___IAddBackEvents_FWD_DEFINED__
#define ___IAddBackEvents_FWD_DEFINED__
typedef interface _IAddBackEvents _IAddBackEvents;
#endif 	/* ___IAddBackEvents_FWD_DEFINED__ */


#ifndef ____Impl__IAddBackEvents_FWD_DEFINED__
#define ____Impl__IAddBackEvents_FWD_DEFINED__

#ifdef __cplusplus
typedef class __Impl__IAddBackEvents __Impl__IAddBackEvents;
#else
typedef struct __Impl__IAddBackEvents __Impl__IAddBackEvents;
#endif /* __cplusplus */

#endif 	/* ____Impl__IAddBackEvents_FWD_DEFINED__ */


/* header files for imported files */
#include "docobj.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_vc70_0000 */
/* [local] */ 





extern RPC_IF_HANDLE __MIDL_itf_vc70_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vc70_0000_v0_0_s_ifspec;

#ifndef __IAddBack_INTERFACE_DEFINED__
#define __IAddBack_INTERFACE_DEFINED__

/* interface IAddBack */
/* [object][dual][uuid] */ 


EXTERN_C const IID IID_IAddBack;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d3af576a-cde3-4c6b-bbe4-678deb0156b7")
    IAddBack : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddTen( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AddEnd( 
            /* [retval][out] */ short *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AddEnd( 
            /* [in] */ short pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Sum( 
            /* [retval][out] */ short *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAddBackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAddBack * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAddBack * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAddBack * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAddBack * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAddBack * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAddBack * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAddBack * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IAddBack * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddTen )( 
            IAddBack * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IAddBack * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AddEnd )( 
            IAddBack * This,
            /* [retval][out] */ short *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AddEnd )( 
            IAddBack * This,
            /* [in] */ short pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Sum )( 
            IAddBack * This,
            /* [retval][out] */ short *pVal);
        
        END_INTERFACE
    } IAddBackVtbl;

    interface IAddBack
    {
        CONST_VTBL struct IAddBackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAddBack_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAddBack_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAddBack_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAddBack_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAddBack_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAddBack_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAddBack_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAddBack_Add(This)	\
    (This)->lpVtbl -> Add(This)

#define IAddBack_AddTen(This)	\
    (This)->lpVtbl -> AddTen(This)

#define IAddBack_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#define IAddBack_get_AddEnd(This,pVal)	\
    (This)->lpVtbl -> get_AddEnd(This,pVal)

#define IAddBack_put_AddEnd(This,pVal)	\
    (This)->lpVtbl -> put_AddEnd(This,pVal)

#define IAddBack_get_Sum(This,pVal)	\
    (This)->lpVtbl -> get_Sum(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IAddBack_Add_Proxy( 
    IAddBack * This);


void __RPC_STUB IAddBack_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAddBack_AddTen_Proxy( 
    IAddBack * This);


void __RPC_STUB IAddBack_AddTen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAddBack_Clear_Proxy( 
    IAddBack * This);


void __RPC_STUB IAddBack_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IAddBack_get_AddEnd_Proxy( 
    IAddBack * This,
    /* [retval][out] */ short *pVal);


void __RPC_STUB IAddBack_get_AddEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IAddBack_put_AddEnd_Proxy( 
    IAddBack * This,
    /* [in] */ short pVal);


void __RPC_STUB IAddBack_put_AddEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IAddBack_get_Sum_Proxy( 
    IAddBack * This,
    /* [retval][out] */ short *pVal);


void __RPC_STUB IAddBack_get_Sum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAddBack_INTERFACE_DEFINED__ */



#ifndef __AddFront_LIBRARY_DEFINED__
#define __AddFront_LIBRARY_DEFINED__

/* library AddFront */
/* [uuid][version] */ 


EXTERN_C const IID LIBID_AddFront;

#ifndef ___IAddBackEvents_DISPINTERFACE_DEFINED__
#define ___IAddBackEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IAddBackEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__IAddBackEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("6b789d4f-b967-4f16-b0f2-32e2fda6e05f")
    _IAddBackEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IAddBackEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IAddBackEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IAddBackEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IAddBackEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IAddBackEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IAddBackEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IAddBackEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IAddBackEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IAddBackEventsVtbl;

    interface _IAddBackEvents
    {
        CONST_VTBL struct _IAddBackEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IAddBackEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IAddBackEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IAddBackEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IAddBackEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IAddBackEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IAddBackEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IAddBackEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IAddBackEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID___Impl__IAddBackEvents;

#ifdef __cplusplus

class DECLSPEC_UUID("718DA686-250E-37D3-8FA2-4ABC2444CDA9")
__Impl__IAddBackEvents;
#endif
#endif /* __AddFront_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


