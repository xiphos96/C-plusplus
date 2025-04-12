

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Tue Mar 23 11:13:30 2004
 */
/* Compiler settings for .\Debit.idl:
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

#ifndef __Debit_h__
#define __Debit_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDebit_FWD_DEFINED__
#define __IDebit_FWD_DEFINED__
typedef interface IDebit IDebit;
#endif 	/* __IDebit_FWD_DEFINED__ */


#ifndef __Debit_FWD_DEFINED__
#define __Debit_FWD_DEFINED__

#ifdef __cplusplus
typedef class Debit Debit;
#else
typedef struct Debit Debit;
#endif /* __cplusplus */

#endif 	/* __Debit_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IDebit_INTERFACE_DEFINED__
#define __IDebit_INTERFACE_DEFINED__

/* interface IDebit */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDebit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29C6E783-552F-42FA-A87D-DA16D91ECF3F")
    IDebit : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeAccount( 
            /* [in] */ long accountID,
            /* [in] */ long amount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDebitVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDebit * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDebit * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDebit * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDebit * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDebit * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDebit * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDebit * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeAccount )( 
            IDebit * This,
            /* [in] */ long accountID,
            /* [in] */ long amount);
        
        END_INTERFACE
    } IDebitVtbl;

    interface IDebit
    {
        CONST_VTBL struct IDebitVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDebit_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDebit_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDebit_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDebit_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDebit_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDebit_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDebit_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDebit_ChangeAccount(This,accountID,amount)	\
    (This)->lpVtbl -> ChangeAccount(This,accountID,amount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDebit_ChangeAccount_Proxy( 
    IDebit * This,
    /* [in] */ long accountID,
    /* [in] */ long amount);


void __RPC_STUB IDebit_ChangeAccount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDebit_INTERFACE_DEFINED__ */



#ifndef __DebitLib_LIBRARY_DEFINED__
#define __DebitLib_LIBRARY_DEFINED__

/* library DebitLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_DebitLib;

EXTERN_C const CLSID CLSID_Debit;

#ifdef __cplusplus

class DECLSPEC_UUID("7238505D-8F66-47A7-A9D7-CD0B2499BBC8")
Debit;
#endif
#endif /* __DebitLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


