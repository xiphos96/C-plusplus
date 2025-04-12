

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Tue Mar 16 16:53:13 2004
 */
/* Compiler settings for _AddBackCon.idl:
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

#ifndef ___AddBackCon_h__
#define ___AddBackCon_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAddBack_FWD_DEFINED__
#define __IAddBack_FWD_DEFINED__
typedef interface IAddBack IAddBack;
#endif 	/* __IAddBack_FWD_DEFINED__ */


#ifndef __IAddEnd_FWD_DEFINED__
#define __IAddEnd_FWD_DEFINED__
typedef interface IAddEnd IAddEnd;
#endif 	/* __IAddEnd_FWD_DEFINED__ */


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
    
    MIDL_INTERFACE("13D21EF3-5A50-4FCD-90B7-5984B97718E0")
    IAddBack : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddTen( void) = 0;
        
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



#endif 	/* __IAddBack_INTERFACE_DEFINED__ */


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


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAddEnd_Clear_Proxy( 
    IAddEnd * This);


void __RPC_STUB IAddEnd_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAddEnd_INTERFACE_DEFINED__ */



#ifndef __AddBackCon_LIBRARY_DEFINED__
#define __AddBackCon_LIBRARY_DEFINED__

/* library AddBackCon */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_AddBackCon;

EXTERN_C const CLSID CLSID_CAddBack;

#ifdef __cplusplus

class DECLSPEC_UUID("05EFD227-B94B-4F18-B5AD-39037697EFF3")
CAddBack;
#endif
#endif /* __AddBackCon_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


