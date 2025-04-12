

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Wed Mar 10 14:31:42 2004
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

#ifndef __IHello_FWD_DEFINED__
#define __IHello_FWD_DEFINED__
typedef interface IHello IHello;
#endif 	/* __IHello_FWD_DEFINED__ */


#ifndef __CHello_FWD_DEFINED__
#define __CHello_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHello CHello;
#else
typedef struct CHello CHello;
#endif /* __cplusplus */

#endif 	/* __CHello_FWD_DEFINED__ */


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

#ifndef __IHello_INTERFACE_DEFINED__
#define __IHello_INTERFACE_DEFINED__

/* interface IHello */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHello;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4646F65-6C21-4051-8DA8-E0AC06BF1CEB")
    IHello : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE sayHello( 
            /* [in] */ wchar_t *name,
            /* [out] */ wchar_t **message) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHelloVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHello * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHello * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHello * This);
        
        HRESULT ( STDMETHODCALLTYPE *sayHello )( 
            IHello * This,
            /* [in] */ wchar_t *name,
            /* [out] */ wchar_t **message);
        
        END_INTERFACE
    } IHelloVtbl;

    interface IHello
    {
        CONST_VTBL struct IHelloVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHello_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHello_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHello_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHello_sayHello(This,name,message)	\
    (This)->lpVtbl -> sayHello(This,name,message)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHello_sayHello_Proxy( 
    IHello * This,
    /* [in] */ wchar_t *name,
    /* [out] */ wchar_t **message);


void __RPC_STUB IHello_sayHello_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHello_INTERFACE_DEFINED__ */



#ifndef __HelloServer_LIBRARY_DEFINED__
#define __HelloServer_LIBRARY_DEFINED__

/* library HelloServer */
/* [uuid][helpstring][version] */ 


EXTERN_C const IID LIBID_HelloServer;

EXTERN_C const CLSID CLSID_CHello;

#ifdef __cplusplus

class DECLSPEC_UUID("D84CDA2F-5AF1-4e97-BE21-983E0AB93D67")
CHello;
#endif
#endif /* __HelloServer_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


