

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Tue Mar 16 14:03:20 2004
 */
/* Compiler settings for _AddBack.idl:
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

#ifndef ___AddBack_h__
#define ___AddBack_h__

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


#ifndef __CAddBack_FWD_DEFINED__
#define __CAddBack_FWD_DEFINED__

#ifdef __cplusplus
typedef class CAddBack CAddBack;
#else
typedef struct CAddBack CAddBack;
#endif /* __cplusplus */

#endif 	/* __CAddBack_FWD_DEFINED__ */


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

#ifndef __IAddBack_INTERFACE_DEFINED__
#define __IAddBack_INTERFACE_DEFINED__

/* interface IAddBack */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAddBack;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D3AF576A-CDE3-4C6B-BBE4-678DEB0156B7")
    IAddBack : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddTen( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AddEnd( 
            /* [retval][out] */ SHORT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AddEnd( 
            /* [in] */ SHORT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Sum( 
            /* [retval][out] */ SHORT *pVal) = 0;
        
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IAddBack * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddTen )( 
            IAddBack * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IAddBack * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AddEnd )( 
            IAddBack * This,
            /* [retval][out] */ SHORT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AddEnd )( 
            IAddBack * This,
            /* [in] */ SHORT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Sum )( 
            IAddBack * This,
            /* [retval][out] */ SHORT *pVal);
        
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

#define IAddBack_put_AddEnd(This,newVal)	\
    (This)->lpVtbl -> put_AddEnd(This,newVal)

#define IAddBack_get_Sum(This,pVal)	\
    (This)->lpVtbl -> get_Sum(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAddBack_Add_Proxy( 
    IAddBack * This);


void __RPC_STUB IAddBack_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAddBack_AddTen_Proxy( 
    IAddBack * This);


void __RPC_STUB IAddBack_AddTen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAddBack_Clear_Proxy( 
    IAddBack * This);


void __RPC_STUB IAddBack_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAddBack_get_AddEnd_Proxy( 
    IAddBack * This,
    /* [retval][out] */ SHORT *pVal);


void __RPC_STUB IAddBack_get_AddEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAddBack_put_AddEnd_Proxy( 
    IAddBack * This,
    /* [in] */ SHORT newVal);


void __RPC_STUB IAddBack_put_AddEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAddBack_get_Sum_Proxy( 
    IAddBack * This,
    /* [retval][out] */ SHORT *pVal);


void __RPC_STUB IAddBack_get_Sum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAddBack_INTERFACE_DEFINED__ */



#ifndef __AddBack_LIBRARY_DEFINED__
#define __AddBack_LIBRARY_DEFINED__

/* library AddBack */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_AddBack;

#ifndef ___IAddBackEvents_DISPINTERFACE_DEFINED__
#define ___IAddBackEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IAddBackEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IAddBackEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("6B789D4F-B967-4F16-B0F2-32E2FDA6E05F")
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


EXTERN_C const CLSID CLSID_CAddBack;

#ifdef __cplusplus

class DECLSPEC_UUID("F792F6D3-7005-4CB8-9C7F-35313B3ADE5B")
CAddBack;
#endif
#endif /* __AddBack_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


