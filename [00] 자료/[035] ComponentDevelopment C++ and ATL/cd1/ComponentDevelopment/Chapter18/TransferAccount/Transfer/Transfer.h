

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Tue Mar 23 11:13:57 2004
 */
/* Compiler settings for .\Transfer.idl:
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

#ifndef __Transfer_h__
#define __Transfer_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITransfer_FWD_DEFINED__
#define __ITransfer_FWD_DEFINED__
typedef interface ITransfer ITransfer;
#endif 	/* __ITransfer_FWD_DEFINED__ */


#ifndef __Transfer_FWD_DEFINED__
#define __Transfer_FWD_DEFINED__

#ifdef __cplusplus
typedef class Transfer Transfer;
#else
typedef struct Transfer Transfer;
#endif /* __cplusplus */

#endif 	/* __Transfer_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __ITransfer_INTERFACE_DEFINED__
#define __ITransfer_INTERFACE_DEFINED__

/* interface ITransfer */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITransfer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5569DD76-9C3C-4925-8731-321845516F71")
    ITransfer : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveMoney( 
            /* [in] */ long srcAccount,
            /* [in] */ long destAccount,
            /* [in] */ long amount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITransferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITransfer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITransfer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITransfer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITransfer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITransfer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITransfer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITransfer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveMoney )( 
            ITransfer * This,
            /* [in] */ long srcAccount,
            /* [in] */ long destAccount,
            /* [in] */ long amount);
        
        END_INTERFACE
    } ITransferVtbl;

    interface ITransfer
    {
        CONST_VTBL struct ITransferVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransfer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITransfer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITransfer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITransfer_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ITransfer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ITransfer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ITransfer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ITransfer_MoveMoney(This,srcAccount,destAccount,amount)	\
    (This)->lpVtbl -> MoveMoney(This,srcAccount,destAccount,amount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITransfer_MoveMoney_Proxy( 
    ITransfer * This,
    /* [in] */ long srcAccount,
    /* [in] */ long destAccount,
    /* [in] */ long amount);


void __RPC_STUB ITransfer_MoveMoney_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITransfer_INTERFACE_DEFINED__ */



#ifndef __TransferLib_LIBRARY_DEFINED__
#define __TransferLib_LIBRARY_DEFINED__

/* library TransferLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TransferLib;

EXTERN_C const CLSID CLSID_Transfer;

#ifdef __cplusplus

class DECLSPEC_UUID("6A1F644C-67C1-4CF2-A2C7-67FEA3EE1414")
Transfer;
#endif
#endif /* __TransferLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


