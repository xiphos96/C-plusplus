

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Tue Mar 23 11:05:40 2004
 */
/* Compiler settings for .\Credit.idl:
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

#ifndef __Credit_h__
#define __Credit_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICredit_FWD_DEFINED__
#define __ICredit_FWD_DEFINED__
typedef interface ICredit ICredit;
#endif 	/* __ICredit_FWD_DEFINED__ */


#ifndef __Credit_FWD_DEFINED__
#define __Credit_FWD_DEFINED__

#ifdef __cplusplus
typedef class Credit Credit;
#else
typedef struct Credit Credit;
#endif /* __cplusplus */

#endif 	/* __Credit_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __ICredit_INTERFACE_DEFINED__
#define __ICredit_INTERFACE_DEFINED__

/* interface ICredit */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICredit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("454FADB8-BFCB-4572-95DD-0F28D9F40180")
    ICredit : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeAccount( 
            /* [in] */ long accountID,
            /* [in] */ long amount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICreditVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICredit * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICredit * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICredit * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICredit * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICredit * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICredit * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICredit * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeAccount )( 
            ICredit * This,
            /* [in] */ long accountID,
            /* [in] */ long amount);
        
        END_INTERFACE
    } ICreditVtbl;

    interface ICredit
    {
        CONST_VTBL struct ICreditVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICredit_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICredit_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICredit_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICredit_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICredit_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICredit_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICredit_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICredit_ChangeAccount(This,accountID,amount)	\
    (This)->lpVtbl -> ChangeAccount(This,accountID,amount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICredit_ChangeAccount_Proxy( 
    ICredit * This,
    /* [in] */ long accountID,
    /* [in] */ long amount);


void __RPC_STUB ICredit_ChangeAccount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICredit_INTERFACE_DEFINED__ */



#ifndef __CreditLib_LIBRARY_DEFINED__
#define __CreditLib_LIBRARY_DEFINED__

/* library CreditLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_CreditLib;

EXTERN_C const CLSID CLSID_Credit;

#ifdef __cplusplus

class DECLSPEC_UUID("EBE71C3A-E151-4420-9FBD-23EC0BA7DC55")
Credit;
#endif
#endif /* __CreditLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


