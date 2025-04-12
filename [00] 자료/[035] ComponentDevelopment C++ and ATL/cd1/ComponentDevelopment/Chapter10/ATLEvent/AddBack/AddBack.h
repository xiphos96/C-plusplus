

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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

#ifndef __AddBack_h__
#define __AddBack_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAddBack_FWD_DEFINED__
#define __IAddBack_FWD_DEFINED__
typedef interface IAddBack IAddBack;
#endif 	/* __IAddBack_FWD_DEFINED__ */


#ifndef __IAddBackEvents_FWD_DEFINED__
#define __IAddBackEvents_FWD_DEFINED__
typedef interface IAddBackEvents IAddBackEvents;
#endif 	/* __IAddBackEvents_FWD_DEFINED__ */


#ifndef ___IAddBackEvents_FWD_DEFINED__
#define ___IAddBackEvents_FWD_DEFINED__
typedef interface _IAddBackEvents _IAddBackEvents;
#endif 	/* ___IAddBackEvents_FWD_DEFINED__ */


#ifndef __AddBack_FWD_DEFINED__
#define __AddBack_FWD_DEFINED__

#ifdef __cplusplus
typedef class AddBack AddBack;
#else
typedef struct AddBack AddBack;
#endif /* __cplusplus */

#endif 	/* __AddBack_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IAddBack_INTERFACE_DEFINED__
#define __IAddBack_INTERFACE_DEFINED__

/* interface IAddBack */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAddBack;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B714A149-C4F8-4B50-8BEE-926C84F99FB2")
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


#ifndef __IAddBackEvents_INTERFACE_DEFINED__
#define __IAddBackEvents_INTERFACE_DEFINED__

/* interface IAddBackEvents */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAddBackEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D90D5240-ACD0-11d1-913A-0020AF715AF0")
    IAddBackEvents : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangedAddEnd( 
            /* [in] */ SHORT newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangedSum( 
            /* [in] */ SHORT newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAddBackEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAddBackEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAddBackEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAddBackEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAddBackEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAddBackEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAddBackEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAddBackEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangedAddEnd )( 
            IAddBackEvents * This,
            /* [in] */ SHORT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangedSum )( 
            IAddBackEvents * This,
            /* [in] */ SHORT newVal);
        
        END_INTERFACE
    } IAddBackEventsVtbl;

    interface IAddBackEvents
    {
        CONST_VTBL struct IAddBackEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAddBackEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAddBackEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAddBackEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAddBackEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAddBackEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAddBackEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAddBackEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAddBackEvents_ChangedAddEnd(This,newVal)	\
    (This)->lpVtbl -> ChangedAddEnd(This,newVal)

#define IAddBackEvents_ChangedSum(This,newVal)	\
    (This)->lpVtbl -> ChangedSum(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAddBackEvents_ChangedAddEnd_Proxy( 
    IAddBackEvents * This,
    /* [in] */ SHORT newVal);


void __RPC_STUB IAddBackEvents_ChangedAddEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IAddBackEvents_ChangedSum_Proxy( 
    IAddBackEvents * This,
    /* [in] */ SHORT newVal);


void __RPC_STUB IAddBackEvents_ChangedSum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAddBackEvents_INTERFACE_DEFINED__ */



#ifndef __AddBackLib_LIBRARY_DEFINED__
#define __AddBackLib_LIBRARY_DEFINED__

/* library AddBackLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_AddBackLib;

#ifndef ___IAddBackEvents_DISPINTERFACE_DEFINED__
#define ___IAddBackEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IAddBackEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IAddBackEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("6F80FA9C-AB06-47E4-84E1-B71151760BDA")
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


EXTERN_C const CLSID CLSID_AddBack;

#ifdef __cplusplus

class DECLSPEC_UUID("CB30E04C-A741-4E83-B21F-096DED8351D5")
AddBack;
#endif
#endif /* __AddBackLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


