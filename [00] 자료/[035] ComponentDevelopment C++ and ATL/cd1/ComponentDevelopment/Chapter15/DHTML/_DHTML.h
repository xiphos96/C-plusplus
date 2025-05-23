

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Fri Mar 19 02:18:48 2004
 */
/* Compiler settings for _DHTML.idl:
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

#ifndef ___DHTML_h__
#define ___DHTML_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDHTMLCtlUI_FWD_DEFINED__
#define __IDHTMLCtlUI_FWD_DEFINED__
typedef interface IDHTMLCtlUI IDHTMLCtlUI;
#endif 	/* __IDHTMLCtlUI_FWD_DEFINED__ */


#ifndef __IDHTMLCtl_FWD_DEFINED__
#define __IDHTMLCtl_FWD_DEFINED__
typedef interface IDHTMLCtl IDHTMLCtl;
#endif 	/* __IDHTMLCtl_FWD_DEFINED__ */


#ifndef __CDHTMLCtlUI_FWD_DEFINED__
#define __CDHTMLCtlUI_FWD_DEFINED__

#ifdef __cplusplus
typedef class CDHTMLCtlUI CDHTMLCtlUI;
#else
typedef struct CDHTMLCtlUI CDHTMLCtlUI;
#endif /* __cplusplus */

#endif 	/* __CDHTMLCtlUI_FWD_DEFINED__ */


#ifndef __CDHTMLCtl_FWD_DEFINED__
#define __CDHTMLCtl_FWD_DEFINED__

#ifdef __cplusplus
typedef class CDHTMLCtl CDHTMLCtl;
#else
typedef struct CDHTMLCtl CDHTMLCtl;
#endif /* __cplusplus */

#endif 	/* __CDHTMLCtl_FWD_DEFINED__ */


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

#ifndef __IDHTMLCtlUI_INTERFACE_DEFINED__
#define __IDHTMLCtlUI_INTERFACE_DEFINED__

/* interface IDHTMLCtlUI */
/* [unique][helpstring][uuid][dual][object] */ 


EXTERN_C const IID IID_IDHTMLCtlUI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CC72F349-A155-4E77-BAE6-29EEB8355AC0")
    IDHTMLCtlUI : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OnClick( 
            /* [in] */ IDispatch *pdispBody,
            /* [in] */ VARIANT varColor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GoTo( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDHTMLCtlUIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDHTMLCtlUI * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDHTMLCtlUI * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDHTMLCtlUI * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDHTMLCtlUI * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDHTMLCtlUI * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDHTMLCtlUI * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDHTMLCtlUI * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OnClick )( 
            IDHTMLCtlUI * This,
            /* [in] */ IDispatch *pdispBody,
            /* [in] */ VARIANT varColor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GoTo )( 
            IDHTMLCtlUI * This);
        
        END_INTERFACE
    } IDHTMLCtlUIVtbl;

    interface IDHTMLCtlUI
    {
        CONST_VTBL struct IDHTMLCtlUIVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDHTMLCtlUI_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDHTMLCtlUI_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDHTMLCtlUI_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDHTMLCtlUI_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDHTMLCtlUI_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDHTMLCtlUI_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDHTMLCtlUI_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDHTMLCtlUI_OnClick(This,pdispBody,varColor)	\
    (This)->lpVtbl -> OnClick(This,pdispBody,varColor)

#define IDHTMLCtlUI_GoTo(This)	\
    (This)->lpVtbl -> GoTo(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IDHTMLCtlUI_OnClick_Proxy( 
    IDHTMLCtlUI * This,
    /* [in] */ IDispatch *pdispBody,
    /* [in] */ VARIANT varColor);


void __RPC_STUB IDHTMLCtlUI_OnClick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDHTMLCtlUI_GoTo_Proxy( 
    IDHTMLCtlUI * This);


void __RPC_STUB IDHTMLCtlUI_GoTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDHTMLCtlUI_INTERFACE_DEFINED__ */


#ifndef __IDHTMLCtl_INTERFACE_DEFINED__
#define __IDHTMLCtl_INTERFACE_DEFINED__

/* interface IDHTMLCtl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDHTMLCtl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("301363E5-1A3D-45E5-9AC5-0D8596AF5F86")
    IDHTMLCtl : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UrlPath( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UrlPath( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GoToURL( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDHTMLCtlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDHTMLCtl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDHTMLCtl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDHTMLCtl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDHTMLCtl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDHTMLCtl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDHTMLCtl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDHTMLCtl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UrlPath )( 
            IDHTMLCtl * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UrlPath )( 
            IDHTMLCtl * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GoToURL )( 
            IDHTMLCtl * This);
        
        END_INTERFACE
    } IDHTMLCtlVtbl;

    interface IDHTMLCtl
    {
        CONST_VTBL struct IDHTMLCtlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDHTMLCtl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDHTMLCtl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDHTMLCtl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDHTMLCtl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDHTMLCtl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDHTMLCtl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDHTMLCtl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDHTMLCtl_get_UrlPath(This,pVal)	\
    (This)->lpVtbl -> get_UrlPath(This,pVal)

#define IDHTMLCtl_put_UrlPath(This,newVal)	\
    (This)->lpVtbl -> put_UrlPath(This,newVal)

#define IDHTMLCtl_GoToURL(This)	\
    (This)->lpVtbl -> GoToURL(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDHTMLCtl_get_UrlPath_Proxy( 
    IDHTMLCtl * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IDHTMLCtl_get_UrlPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDHTMLCtl_put_UrlPath_Proxy( 
    IDHTMLCtl * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IDHTMLCtl_put_UrlPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDHTMLCtl_GoToURL_Proxy( 
    IDHTMLCtl * This);


void __RPC_STUB IDHTMLCtl_GoToURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDHTMLCtl_INTERFACE_DEFINED__ */



#ifndef __DHTML_LIBRARY_DEFINED__
#define __DHTML_LIBRARY_DEFINED__

/* library DHTML */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_DHTML;

EXTERN_C const CLSID CLSID_CDHTMLCtlUI;

#ifdef __cplusplus

class DECLSPEC_UUID("542F7C7E-4296-4389-9A23-33196246AC1F")
CDHTMLCtlUI;
#endif

EXTERN_C const CLSID CLSID_CDHTMLCtl;

#ifdef __cplusplus

class DECLSPEC_UUID("73FED92B-DA89-4C5D-A99E-9C15E9D480E9")
CDHTMLCtl;
#endif
#endif /* __DHTML_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


