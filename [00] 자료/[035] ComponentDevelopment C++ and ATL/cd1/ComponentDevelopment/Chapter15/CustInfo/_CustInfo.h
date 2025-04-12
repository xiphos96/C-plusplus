

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Fri Mar 19 00:54:03 2004
 */
/* Compiler settings for _CustInfo.idl:
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

#ifndef ___CustInfo_h__
#define ___CustInfo_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICustomer_FWD_DEFINED__
#define __ICustomer_FWD_DEFINED__
typedef interface ICustomer ICustomer;
#endif 	/* __ICustomer_FWD_DEFINED__ */


#ifndef ___ICustomerEvents_FWD_DEFINED__
#define ___ICustomerEvents_FWD_DEFINED__
typedef interface _ICustomerEvents _ICustomerEvents;
#endif 	/* ___ICustomerEvents_FWD_DEFINED__ */


#ifndef __CCustomer_FWD_DEFINED__
#define __CCustomer_FWD_DEFINED__

#ifdef __cplusplus
typedef class CCustomer CCustomer;
#else
typedef struct CCustomer CCustomer;
#endif /* __cplusplus */

#endif 	/* __CCustomer_FWD_DEFINED__ */


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

#ifndef __ICustomer_INTERFACE_DEFINED__
#define __ICustomer_INTERFACE_DEFINED__

/* interface ICustomer */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICustomer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("49EF6A18-9E69-41F5-ABA5-127EF4AFC6AB")
    ICustomer : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CustName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CustName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CustAddr( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CustAddr( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CustTelno( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CustTelno( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICustomerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICustomer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICustomer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICustomer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICustomer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICustomer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICustomer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICustomer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustName )( 
            ICustomer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustName )( 
            ICustomer * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustAddr )( 
            ICustomer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustAddr )( 
            ICustomer * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustTelno )( 
            ICustomer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustTelno )( 
            ICustomer * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } ICustomerVtbl;

    interface ICustomer
    {
        CONST_VTBL struct ICustomerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICustomer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICustomer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICustomer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICustomer_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICustomer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICustomer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICustomer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICustomer_get_CustName(This,pVal)	\
    (This)->lpVtbl -> get_CustName(This,pVal)

#define ICustomer_put_CustName(This,newVal)	\
    (This)->lpVtbl -> put_CustName(This,newVal)

#define ICustomer_get_CustAddr(This,pVal)	\
    (This)->lpVtbl -> get_CustAddr(This,pVal)

#define ICustomer_put_CustAddr(This,newVal)	\
    (This)->lpVtbl -> put_CustAddr(This,newVal)

#define ICustomer_get_CustTelno(This,pVal)	\
    (This)->lpVtbl -> get_CustTelno(This,pVal)

#define ICustomer_put_CustTelno(This,newVal)	\
    (This)->lpVtbl -> put_CustTelno(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICustomer_get_CustName_Proxy( 
    ICustomer * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ICustomer_get_CustName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICustomer_put_CustName_Proxy( 
    ICustomer * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ICustomer_put_CustName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICustomer_get_CustAddr_Proxy( 
    ICustomer * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ICustomer_get_CustAddr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICustomer_put_CustAddr_Proxy( 
    ICustomer * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ICustomer_put_CustAddr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICustomer_get_CustTelno_Proxy( 
    ICustomer * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB ICustomer_get_CustTelno_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICustomer_put_CustTelno_Proxy( 
    ICustomer * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ICustomer_put_CustTelno_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICustomer_INTERFACE_DEFINED__ */



#ifndef __CustInfo_LIBRARY_DEFINED__
#define __CustInfo_LIBRARY_DEFINED__

/* library CustInfo */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_CustInfo;

#ifndef ___ICustomerEvents_DISPINTERFACE_DEFINED__
#define ___ICustomerEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ICustomerEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ICustomerEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B026A791-5A90-4CDB-9AD4-6B8DAE24374D")
    _ICustomerEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ICustomerEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ICustomerEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ICustomerEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ICustomerEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ICustomerEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ICustomerEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ICustomerEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ICustomerEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _ICustomerEventsVtbl;

    interface _ICustomerEvents
    {
        CONST_VTBL struct _ICustomerEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ICustomerEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ICustomerEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ICustomerEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ICustomerEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ICustomerEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ICustomerEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ICustomerEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ICustomerEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CCustomer;

#ifdef __cplusplus

class DECLSPEC_UUID("0B16B70E-AA0B-4D14-B57C-1CED7F86A581")
CCustomer;
#endif
#endif /* __CustInfo_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


