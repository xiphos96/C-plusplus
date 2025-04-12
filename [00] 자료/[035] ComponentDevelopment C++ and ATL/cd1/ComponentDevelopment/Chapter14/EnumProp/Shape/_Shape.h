

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Thu Mar 18 14:45:47 2004
 */
/* Compiler settings for _Shape.idl:
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

#ifndef ___Shape_h__
#define ___Shape_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IShape_FWD_DEFINED__
#define __IShape_FWD_DEFINED__
typedef interface IShape IShape;
#endif 	/* __IShape_FWD_DEFINED__ */


#ifndef __CShapeProp_FWD_DEFINED__
#define __CShapeProp_FWD_DEFINED__

#ifdef __cplusplus
typedef class CShapeProp CShapeProp;
#else
typedef struct CShapeProp CShapeProp;
#endif /* __cplusplus */

#endif 	/* __CShapeProp_FWD_DEFINED__ */


#ifndef ___IShapeEvents_FWD_DEFINED__
#define ___IShapeEvents_FWD_DEFINED__
typedef interface _IShapeEvents _IShapeEvents;
#endif 	/* ___IShapeEvents_FWD_DEFINED__ */


#ifndef __CShape_FWD_DEFINED__
#define __CShape_FWD_DEFINED__

#ifdef __cplusplus
typedef class CShape CShape;
#else
typedef struct CShape CShape;
#endif /* __cplusplus */

#endif 	/* __CShape_FWD_DEFINED__ */


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

#ifndef __IShape_INTERFACE_DEFINED__
#define __IShape_INTERFACE_DEFINED__

/* interface IShape */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IShape;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B11EC349-D82F-494B-A51C-B1CDC2DF0EB4")
    IShape : public IDispatch
    {
    public:
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_FillColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_FillColor( 
            /* [retval][out] */ OLE_COLOR *pclr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShapeType( 
            /* [retval][out] */ short *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShapeType( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeShape( 
            /* [in] */ short shpType) = 0;
        
        virtual /* [id][requestedit][bindable][propputref] */ HRESULT STDMETHODCALLTYPE putref_Font( 
            /* [in] */ IFontDisp *pFont) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Font( 
            /* [in] */ IFontDisp *pFont) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Font( 
            /* [retval][out] */ IFontDisp **ppFont) = 0;
        
        virtual /* [id][requestedit][bindable][propputref] */ HRESULT STDMETHODCALLTYPE putref_Picture( 
            /* [in] */ IPictureDisp *pPicture) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Picture( 
            /* [in] */ IPictureDisp *pPicture) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Picture( 
            /* [retval][out] */ IPictureDisp **ppPicture) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShapeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShape * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShape * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShape * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IShape * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IShape * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IShape * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IShape * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FillColor )( 
            IShape * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FillColor )( 
            IShape * This,
            /* [retval][out] */ OLE_COLOR *pclr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShapeType )( 
            IShape * This,
            /* [retval][out] */ short *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShapeType )( 
            IShape * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeShape )( 
            IShape * This,
            /* [in] */ short shpType);
        
        /* [id][requestedit][bindable][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Font )( 
            IShape * This,
            /* [in] */ IFontDisp *pFont);
        
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Font )( 
            IShape * This,
            /* [in] */ IFontDisp *pFont);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Font )( 
            IShape * This,
            /* [retval][out] */ IFontDisp **ppFont);
        
        /* [id][requestedit][bindable][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Picture )( 
            IShape * This,
            /* [in] */ IPictureDisp *pPicture);
        
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Picture )( 
            IShape * This,
            /* [in] */ IPictureDisp *pPicture);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Picture )( 
            IShape * This,
            /* [retval][out] */ IPictureDisp **ppPicture);
        
        END_INTERFACE
    } IShapeVtbl;

    interface IShape
    {
        CONST_VTBL struct IShapeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShape_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IShape_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IShape_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IShape_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IShape_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IShape_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IShape_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IShape_put_FillColor(This,clr)	\
    (This)->lpVtbl -> put_FillColor(This,clr)

#define IShape_get_FillColor(This,pclr)	\
    (This)->lpVtbl -> get_FillColor(This,pclr)

#define IShape_get_ShapeType(This,pVal)	\
    (This)->lpVtbl -> get_ShapeType(This,pVal)

#define IShape_put_ShapeType(This,newVal)	\
    (This)->lpVtbl -> put_ShapeType(This,newVal)

#define IShape_ChangeShape(This,shpType)	\
    (This)->lpVtbl -> ChangeShape(This,shpType)

#define IShape_putref_Font(This,pFont)	\
    (This)->lpVtbl -> putref_Font(This,pFont)

#define IShape_put_Font(This,pFont)	\
    (This)->lpVtbl -> put_Font(This,pFont)

#define IShape_get_Font(This,ppFont)	\
    (This)->lpVtbl -> get_Font(This,ppFont)

#define IShape_putref_Picture(This,pPicture)	\
    (This)->lpVtbl -> putref_Picture(This,pPicture)

#define IShape_put_Picture(This,pPicture)	\
    (This)->lpVtbl -> put_Picture(This,pPicture)

#define IShape_get_Picture(This,ppPicture)	\
    (This)->lpVtbl -> get_Picture(This,ppPicture)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE IShape_put_FillColor_Proxy( 
    IShape * This,
    /* [in] */ OLE_COLOR clr);


void __RPC_STUB IShape_put_FillColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE IShape_get_FillColor_Proxy( 
    IShape * This,
    /* [retval][out] */ OLE_COLOR *pclr);


void __RPC_STUB IShape_get_FillColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IShape_get_ShapeType_Proxy( 
    IShape * This,
    /* [retval][out] */ short *pVal);


void __RPC_STUB IShape_get_ShapeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IShape_put_ShapeType_Proxy( 
    IShape * This,
    /* [in] */ short newVal);


void __RPC_STUB IShape_put_ShapeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShape_ChangeShape_Proxy( 
    IShape * This,
    /* [in] */ short shpType);


void __RPC_STUB IShape_ChangeShape_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][requestedit][bindable][propputref] */ HRESULT STDMETHODCALLTYPE IShape_putref_Font_Proxy( 
    IShape * This,
    /* [in] */ IFontDisp *pFont);


void __RPC_STUB IShape_putref_Font_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE IShape_put_Font_Proxy( 
    IShape * This,
    /* [in] */ IFontDisp *pFont);


void __RPC_STUB IShape_put_Font_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE IShape_get_Font_Proxy( 
    IShape * This,
    /* [retval][out] */ IFontDisp **ppFont);


void __RPC_STUB IShape_get_Font_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][requestedit][bindable][propputref] */ HRESULT STDMETHODCALLTYPE IShape_putref_Picture_Proxy( 
    IShape * This,
    /* [in] */ IPictureDisp *pPicture);


void __RPC_STUB IShape_putref_Picture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE IShape_put_Picture_Proxy( 
    IShape * This,
    /* [in] */ IPictureDisp *pPicture);


void __RPC_STUB IShape_put_Picture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE IShape_get_Picture_Proxy( 
    IShape * This,
    /* [retval][out] */ IPictureDisp **ppPicture);


void __RPC_STUB IShape_get_Picture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IShape_INTERFACE_DEFINED__ */



#ifndef __Shape_LIBRARY_DEFINED__
#define __Shape_LIBRARY_DEFINED__

/* library Shape */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_Shape;

EXTERN_C const CLSID CLSID_CShapeProp;

#ifdef __cplusplus

class DECLSPEC_UUID("1183C3B8-F389-42E8-B36D-C2C6675713B3")
CShapeProp;
#endif

#ifndef ___IShapeEvents_DISPINTERFACE_DEFINED__
#define ___IShapeEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IShapeEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IShapeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B55B1009-F027-4C95-AE5D-961626ACEF9A")
    _IShapeEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IShapeEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IShapeEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IShapeEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IShapeEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IShapeEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IShapeEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IShapeEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IShapeEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IShapeEventsVtbl;

    interface _IShapeEvents
    {
        CONST_VTBL struct _IShapeEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IShapeEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IShapeEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IShapeEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IShapeEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IShapeEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IShapeEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IShapeEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IShapeEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CShape;

#ifdef __cplusplus

class DECLSPEC_UUID("2D1108CF-31BE-4CFC-8EEA-F6CD3EE363BC")
CShape;
#endif
#endif /* __Shape_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


