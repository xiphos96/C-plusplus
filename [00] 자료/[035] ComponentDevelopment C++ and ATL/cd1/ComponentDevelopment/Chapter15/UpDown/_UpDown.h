

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Fri Mar 19 01:26:01 2004
 */
/* Compiler settings for _UpDown.idl:
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

#ifndef ___UpDown_h__
#define ___UpDown_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IUpDownCtl_FWD_DEFINED__
#define __IUpDownCtl_FWD_DEFINED__
typedef interface IUpDownCtl IUpDownCtl;
#endif 	/* __IUpDownCtl_FWD_DEFINED__ */


#ifndef ___IUpDownCtlEvents_FWD_DEFINED__
#define ___IUpDownCtlEvents_FWD_DEFINED__
typedef interface _IUpDownCtlEvents _IUpDownCtlEvents;
#endif 	/* ___IUpDownCtlEvents_FWD_DEFINED__ */


#ifndef __CUpDownCtl_FWD_DEFINED__
#define __CUpDownCtl_FWD_DEFINED__

#ifdef __cplusplus
typedef class CUpDownCtl CUpDownCtl;
#else
typedef struct CUpDownCtl CUpDownCtl;
#endif /* __cplusplus */

#endif 	/* __CUpDownCtl_FWD_DEFINED__ */


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

#ifndef __IUpDownCtl_INTERFACE_DEFINED__
#define __IUpDownCtl_INTERFACE_DEFINED__

/* interface IUpDownCtl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUpDownCtl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E110287D-B638-4CB4-9AD1-E502664EEBBA")
    IUpDownCtl : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MinValue( 
            /* [retval][out] */ short *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MinValue( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxValue( 
            /* [retval][out] */ short *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxValue( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ short *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ short newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUpDownCtlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUpDownCtl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUpDownCtl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUpDownCtl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUpDownCtl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUpDownCtl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUpDownCtl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUpDownCtl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinValue )( 
            IUpDownCtl * This,
            /* [retval][out] */ short *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MinValue )( 
            IUpDownCtl * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxValue )( 
            IUpDownCtl * This,
            /* [retval][out] */ short *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxValue )( 
            IUpDownCtl * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IUpDownCtl * This,
            /* [retval][out] */ short *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IUpDownCtl * This,
            /* [in] */ short newVal);
        
        END_INTERFACE
    } IUpDownCtlVtbl;

    interface IUpDownCtl
    {
        CONST_VTBL struct IUpDownCtlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUpDownCtl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUpDownCtl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUpDownCtl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUpDownCtl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUpDownCtl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUpDownCtl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUpDownCtl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IUpDownCtl_get_MinValue(This,pVal)	\
    (This)->lpVtbl -> get_MinValue(This,pVal)

#define IUpDownCtl_put_MinValue(This,newVal)	\
    (This)->lpVtbl -> put_MinValue(This,newVal)

#define IUpDownCtl_get_MaxValue(This,pVal)	\
    (This)->lpVtbl -> get_MaxValue(This,pVal)

#define IUpDownCtl_put_MaxValue(This,newVal)	\
    (This)->lpVtbl -> put_MaxValue(This,newVal)

#define IUpDownCtl_get_Value(This,pVal)	\
    (This)->lpVtbl -> get_Value(This,pVal)

#define IUpDownCtl_put_Value(This,newVal)	\
    (This)->lpVtbl -> put_Value(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUpDownCtl_get_MinValue_Proxy( 
    IUpDownCtl * This,
    /* [retval][out] */ short *pVal);


void __RPC_STUB IUpDownCtl_get_MinValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUpDownCtl_put_MinValue_Proxy( 
    IUpDownCtl * This,
    /* [in] */ short newVal);


void __RPC_STUB IUpDownCtl_put_MinValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUpDownCtl_get_MaxValue_Proxy( 
    IUpDownCtl * This,
    /* [retval][out] */ short *pVal);


void __RPC_STUB IUpDownCtl_get_MaxValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUpDownCtl_put_MaxValue_Proxy( 
    IUpDownCtl * This,
    /* [in] */ short newVal);


void __RPC_STUB IUpDownCtl_put_MaxValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUpDownCtl_get_Value_Proxy( 
    IUpDownCtl * This,
    /* [retval][out] */ short *pVal);


void __RPC_STUB IUpDownCtl_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUpDownCtl_put_Value_Proxy( 
    IUpDownCtl * This,
    /* [in] */ short newVal);


void __RPC_STUB IUpDownCtl_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUpDownCtl_INTERFACE_DEFINED__ */



#ifndef __UpDown_LIBRARY_DEFINED__
#define __UpDown_LIBRARY_DEFINED__

/* library UpDown */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_UpDown;

#ifndef ___IUpDownCtlEvents_DISPINTERFACE_DEFINED__
#define ___IUpDownCtlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IUpDownCtlEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IUpDownCtlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("98E0E6DC-6884-4D03-A873-10FC84488C8B")
    _IUpDownCtlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IUpDownCtlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IUpDownCtlEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IUpDownCtlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IUpDownCtlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IUpDownCtlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IUpDownCtlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IUpDownCtlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IUpDownCtlEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IUpDownCtlEventsVtbl;

    interface _IUpDownCtlEvents
    {
        CONST_VTBL struct _IUpDownCtlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IUpDownCtlEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IUpDownCtlEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IUpDownCtlEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IUpDownCtlEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IUpDownCtlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IUpDownCtlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IUpDownCtlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IUpDownCtlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CUpDownCtl;

#ifdef __cplusplus

class DECLSPEC_UUID("7B8BA776-730A-47D6-9462-EB68C2F8CC2D")
CUpDownCtl;
#endif
#endif /* __UpDown_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


