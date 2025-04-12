

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Tue Mar 23 12:18:55 2004
 */
/* Compiler settings for .\RoleSecurity.idl:
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

#ifndef __RoleSecurity_h__
#define __RoleSecurity_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IRoleCheck_FWD_DEFINED__
#define __IRoleCheck_FWD_DEFINED__
typedef interface IRoleCheck IRoleCheck;
#endif 	/* __IRoleCheck_FWD_DEFINED__ */


#ifndef __RoleCheck_FWD_DEFINED__
#define __RoleCheck_FWD_DEFINED__

#ifdef __cplusplus
typedef class RoleCheck RoleCheck;
#else
typedef struct RoleCheck RoleCheck;
#endif /* __cplusplus */

#endif 	/* __RoleCheck_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IRoleCheck_INTERFACE_DEFINED__
#define __IRoleCheck_INTERFACE_DEFINED__

/* interface IRoleCheck */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IRoleCheck;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1C7D46AA-2001-43B5-85EE-297D71E05A75")
    IRoleCheck : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SecurityCheck( 
            /* [retval][out] */ BSTR *result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRoleCheckVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRoleCheck * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRoleCheck * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRoleCheck * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRoleCheck * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRoleCheck * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRoleCheck * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRoleCheck * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SecurityCheck )( 
            IRoleCheck * This,
            /* [retval][out] */ BSTR *result);
        
        END_INTERFACE
    } IRoleCheckVtbl;

    interface IRoleCheck
    {
        CONST_VTBL struct IRoleCheckVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRoleCheck_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRoleCheck_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRoleCheck_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRoleCheck_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRoleCheck_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRoleCheck_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRoleCheck_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRoleCheck_SecurityCheck(This,result)	\
    (This)->lpVtbl -> SecurityCheck(This,result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRoleCheck_SecurityCheck_Proxy( 
    IRoleCheck * This,
    /* [retval][out] */ BSTR *result);


void __RPC_STUB IRoleCheck_SecurityCheck_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRoleCheck_INTERFACE_DEFINED__ */



#ifndef __RoleSecurityLib_LIBRARY_DEFINED__
#define __RoleSecurityLib_LIBRARY_DEFINED__

/* library RoleSecurityLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_RoleSecurityLib;

EXTERN_C const CLSID CLSID_RoleCheck;

#ifdef __cplusplus

class DECLSPEC_UUID("33C25248-D36C-4F25-B9B8-D01453B9DF4A")
RoleCheck;
#endif
#endif /* __RoleSecurityLib_LIBRARY_DEFINED__ */

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


