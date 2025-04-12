

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Wed Mar 17 22:37:39 2004
 */
/* Compiler settings for _Company.idl:
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

#ifndef ___Company_h__
#define ___Company_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IEmployee_FWD_DEFINED__
#define __IEmployee_FWD_DEFINED__
typedef interface IEmployee IEmployee;
#endif 	/* __IEmployee_FWD_DEFINED__ */


#ifndef __IEmployees_FWD_DEFINED__
#define __IEmployees_FWD_DEFINED__
typedef interface IEmployees IEmployees;
#endif 	/* __IEmployees_FWD_DEFINED__ */


#ifndef __ICompany_FWD_DEFINED__
#define __ICompany_FWD_DEFINED__
typedef interface ICompany ICompany;
#endif 	/* __ICompany_FWD_DEFINED__ */


#ifndef __CEmployee_FWD_DEFINED__
#define __CEmployee_FWD_DEFINED__

#ifdef __cplusplus
typedef class CEmployee CEmployee;
#else
typedef struct CEmployee CEmployee;
#endif /* __cplusplus */

#endif 	/* __CEmployee_FWD_DEFINED__ */


#ifndef __CEmployees_FWD_DEFINED__
#define __CEmployees_FWD_DEFINED__

#ifdef __cplusplus
typedef class CEmployees CEmployees;
#else
typedef struct CEmployees CEmployees;
#endif /* __cplusplus */

#endif 	/* __CEmployees_FWD_DEFINED__ */


#ifndef __CCompany_FWD_DEFINED__
#define __CCompany_FWD_DEFINED__

#ifdef __cplusplus
typedef class CCompany CCompany;
#else
typedef struct CCompany CCompany;
#endif /* __cplusplus */

#endif 	/* __CCompany_FWD_DEFINED__ */


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

#ifndef __IEmployee_INTERFACE_DEFINED__
#define __IEmployee_INTERFACE_DEFINED__

/* interface IEmployee */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IEmployee;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AD77D5D9-51A6-4D18-918F-8FCFB0DFC8CF")
    IEmployee : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Address( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Address( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Telephone( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Telephone( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEmployeeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEmployee * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEmployee * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEmployee * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEmployee * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEmployee * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEmployee * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEmployee * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IEmployee * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IEmployee * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Address )( 
            IEmployee * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Address )( 
            IEmployee * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Telephone )( 
            IEmployee * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Telephone )( 
            IEmployee * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IEmployeeVtbl;

    interface IEmployee
    {
        CONST_VTBL struct IEmployeeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEmployee_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEmployee_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEmployee_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEmployee_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEmployee_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEmployee_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEmployee_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IEmployee_get_Name(This,pVal)	\
    (This)->lpVtbl -> get_Name(This,pVal)

#define IEmployee_put_Name(This,newVal)	\
    (This)->lpVtbl -> put_Name(This,newVal)

#define IEmployee_get_Address(This,pVal)	\
    (This)->lpVtbl -> get_Address(This,pVal)

#define IEmployee_put_Address(This,newVal)	\
    (This)->lpVtbl -> put_Address(This,newVal)

#define IEmployee_get_Telephone(This,pVal)	\
    (This)->lpVtbl -> get_Telephone(This,pVal)

#define IEmployee_put_Telephone(This,newVal)	\
    (This)->lpVtbl -> put_Telephone(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IEmployee_get_Name_Proxy( 
    IEmployee * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IEmployee_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IEmployee_put_Name_Proxy( 
    IEmployee * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IEmployee_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IEmployee_get_Address_Proxy( 
    IEmployee * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IEmployee_get_Address_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IEmployee_put_Address_Proxy( 
    IEmployee * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IEmployee_put_Address_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IEmployee_get_Telephone_Proxy( 
    IEmployee * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IEmployee_get_Telephone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IEmployee_put_Telephone_Proxy( 
    IEmployee * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IEmployee_put_Telephone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEmployee_INTERFACE_DEFINED__ */


#ifndef __IEmployees_INTERFACE_DEFINED__
#define __IEmployees_INTERFACE_DEFINED__

/* interface IEmployees */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IEmployees;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C6783455-282B-4AB5-BED5-C8D3A8C38E72")
    IEmployees : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long index,
            /* [retval][out] */ IEmployee **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IEmployee **retVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ long index) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEmployeesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEmployees * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEmployees * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEmployees * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEmployees * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEmployees * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEmployees * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEmployees * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IEmployees * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IEmployees * This,
            /* [in] */ long index,
            /* [retval][out] */ IEmployee **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IEmployees * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IEmployees * This,
            /* [retval][out] */ IEmployee **retVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IEmployees * This,
            /* [in] */ long index);
        
        END_INTERFACE
    } IEmployeesVtbl;

    interface IEmployees
    {
        CONST_VTBL struct IEmployeesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEmployees_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEmployees_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEmployees_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEmployees_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEmployees_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEmployees_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEmployees_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IEmployees_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define IEmployees_get_Item(This,index,pVal)	\
    (This)->lpVtbl -> get_Item(This,index,pVal)

#define IEmployees_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#define IEmployees_Add(This,retVal)	\
    (This)->lpVtbl -> Add(This,retVal)

#define IEmployees_Remove(This,index)	\
    (This)->lpVtbl -> Remove(This,index)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IEmployees_get_Count_Proxy( 
    IEmployees * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IEmployees_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IEmployees_get_Item_Proxy( 
    IEmployees * This,
    /* [in] */ long index,
    /* [retval][out] */ IEmployee **pVal);


void __RPC_STUB IEmployees_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IEmployees_get__NewEnum_Proxy( 
    IEmployees * This,
    /* [retval][out] */ IUnknown **pVal);


void __RPC_STUB IEmployees_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEmployees_Add_Proxy( 
    IEmployees * This,
    /* [retval][out] */ IEmployee **retVal);


void __RPC_STUB IEmployees_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IEmployees_Remove_Proxy( 
    IEmployees * This,
    /* [in] */ long index);


void __RPC_STUB IEmployees_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEmployees_INTERFACE_DEFINED__ */


#ifndef __ICompany_INTERFACE_DEFINED__
#define __ICompany_INTERFACE_DEFINED__

/* interface ICompany */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICompany;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E261C0DF-C91A-4E10-ABC4-0A4099FC8E74")
    ICompany : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Employees( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICompanyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICompany * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICompany * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICompany * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICompany * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICompany * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICompany * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICompany * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Employees )( 
            ICompany * This,
            /* [retval][out] */ VARIANT *pVal);
        
        END_INTERFACE
    } ICompanyVtbl;

    interface ICompany
    {
        CONST_VTBL struct ICompanyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICompany_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICompany_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICompany_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICompany_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICompany_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICompany_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICompany_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICompany_get_Employees(This,pVal)	\
    (This)->lpVtbl -> get_Employees(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICompany_get_Employees_Proxy( 
    ICompany * This,
    /* [retval][out] */ VARIANT *pVal);


void __RPC_STUB ICompany_get_Employees_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICompany_INTERFACE_DEFINED__ */



#ifndef __Company_LIBRARY_DEFINED__
#define __Company_LIBRARY_DEFINED__

/* library Company */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_Company;

EXTERN_C const CLSID CLSID_CEmployee;

#ifdef __cplusplus

class DECLSPEC_UUID("BB84AD11-16E2-4196-88DB-EBC8E518DC33")
CEmployee;
#endif

EXTERN_C const CLSID CLSID_CEmployees;

#ifdef __cplusplus

class DECLSPEC_UUID("6D52EEFB-AEE7-4C46-A472-9350BAC970F0")
CEmployees;
#endif

EXTERN_C const CLSID CLSID_CCompany;

#ifdef __cplusplus

class DECLSPEC_UUID("4BA637B8-6988-4452-925D-E3E9484E0882")
CCompany;
#endif
#endif /* __Company_LIBRARY_DEFINED__ */

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


