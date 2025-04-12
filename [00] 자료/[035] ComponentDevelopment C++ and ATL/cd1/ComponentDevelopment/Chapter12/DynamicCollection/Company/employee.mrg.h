// Created by Microsoft (R) C/C++ Compiler Version 13.10.3077
//
// c:\componentdevelopment\chapter12\dynamiccollection\company\employee.mrg.h
// compiler-generated file created 03/17/04 at 03:05:00
//
// This C++ source file is intended to be a representation of the
// source code injected by the compiler.  It may not compile or
// run exactly as the original source file.
//


//+++ Start Injected Code
[no_injected_text(true)];      // Suppress injected text, it has already been injected
#pragma warning(disable: 4543) // Suppress warnings about skipping injected text
#pragma warning(disable: 4199) // Suppress warnings from attribute providers

// M00PRAGMA("\n\nNOTE: This merged source file should be visually inspected for correctness.\n\n")
//--- End Injected Code

// Employee.h : CEmployee狼 急攫涝聪促.

#pragma once
#include "resource.h"       // 林 扁龋涝聪促.


// IEmployee
[
	object,
	uuid("AD77D5D9-51A6-4D18-918F-8FCFB0DFC8CF"),
	dual,	helpstring("IEmployee 牢磐其捞胶"),
	pointer_default(unique)
]
__interface IEmployee : IDispatch
{
	[propget, id(1), helpstring("加己 Name")] HRESULT Name([out, retval] BSTR* pVal);
	[propput, id(1), helpstring("加己 Name")] HRESULT Name([in] BSTR newVal);
	[propget, id(2), helpstring("加己 Address")] HRESULT Address([out, retval] BSTR* pVal);
	[propput, id(2), helpstring("加己 Address")] HRESULT Address([in] BSTR newVal);
	[propget, id(3), helpstring("加己 Telephone")] HRESULT Telephone([out, retval] BSTR* pVal);
	[propput, id(3), helpstring("加己 Telephone")] HRESULT Telephone([in] BSTR newVal);
};



// CEmployee

[
	coclass,
	threading("apartment"),
	support_error_info("IEmployee"),
	aggregatable("never"),
	vi_progid("Company.Employee"),
	progid("Company.Employee.1"),
	version(1.0),
	uuid("BB84AD11-16E2-4196-88DB-EBC8E518DC33"),
	helpstring("Employee Class"),
	noncreatable
]
class ATL_NO_VTABLE CEmployee : 
	public IEmployee
,
    /*+++ Added Baseclass */ public CComObjectRootEx<CComSingleThreadModel>,
    /*+++ Added Baseclass */ public ISupportErrorInfo
{
public:
	friend class CEmployees;

	CEmployee()
	{
	}


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

public:

	STDMETHOD(get_Name)(BSTR* pVal);
	STDMETHOD(put_Name)(BSTR newVal);
	STDMETHOD(get_Address)(BSTR* pVal);
	STDMETHOD(put_Address)(BSTR newVal);
	STDMETHOD(get_Telephone)(BSTR* pVal);
	STDMETHOD(put_Telephone)(BSTR newVal);
protected:
	CComBSTR m_Name;
	CComBSTR m_Address;
	CComBSTR m_Telephone;

	//+++ Start Injected Code For Attribute 'support_error_info'
#injected_line 38 "c:\\componentdevelopment\\chapter12\\dynamiccollection\\company\\employee.h"
    virtual HRESULT STDMETHODCALLTYPE IEmployee::Invoke(
                /* [in] */ DISPID dispIdMember,
                /* [in] */ REFIID riid,
                /* [in] */ LCID lcid,
                /* [in] */ WORD wFlags,
                /* [out][in] */ DISPPARAMS *pDispParams,
                /* [out] */ VARIANT *pVarResult,
                /* [out] */ EXCEPINFO *pExcepInfo,
                /* [out] */ UINT *puArgErr) 
    {
        (void) riid;
        (void) dispIdMember;
        (void) lcid;
        (void) wFlags;
        (void) pExcepInfo;
        (void) puArgErr;
        HRESULT hr = S_OK;
        if (pDispParams == 0) {
            return DISP_E_BADVARTYPE;
        }
        if (pDispParams->cArgs > 1) {
            return DISP_E_BADPARAMCOUNT;
        }
        if (pVarResult != 0) {
            ::VariantInit(pVarResult);
        }
        VARIANT* rgpVars[1];
        UINT index = 0;
        for (; index < pDispParams->cArgs; ++index) {
            rgpVars[index] = &pDispParams->rgvarg[index];
        }
        VARIANT v0;
        VARIANT* v;
        switch (dispIdMember) {
        case 1:
            {
                if (wFlags & 2) {
                    if (pDispParams->cArgs != 0) {
                        return DISP_E_BADPARAMCOUNT;
                    }
                    BSTR i1;
                    hr = ((::IEmployee*) this)->get_Name(&i1);
                    if (pVarResult != 0) {
                        V_VT(pVarResult) = VT_BSTR;
                        V_BSTR(pVarResult) = (BSTR) i1;
                    }
                    break;
                }
                else 
        if (wFlags & 4) {
                    if (pDispParams->cArgs != 1) {
                        return DISP_E_BADPARAMCOUNT;
                    }
                    v = rgpVars[0];
                    if (v->vt != VT_BSTR && FAILED(__VariantChangeType(v, &v0, VT_BSTR))) {
                        if (puArgErr != 0) {
                            *puArgErr = 0;
                        }
                        return DISP_E_TYPEMISMATCH;
                    }
                    BSTR i1 = (BSTR) V_BSTR(v);
                    hr = ((::IEmployee*) this)->put_Name(i1);
                    break;
                }
            }
        case 2:
            {
                if (wFlags & 2) {
                    if (pDispParams->cArgs != 0) {
                        return DISP_E_BADPARAMCOUNT;
                    }
                    BSTR i1;
                    hr = ((::IEmployee*) this)->get_Address(&i1);
                    if (pVarResult != 0) {
                        V_VT(pVarResult) = VT_BSTR;
                        V_BSTR(pVarResult) = (BSTR) i1;
                    }
                    break;
                }
                else 
        if (wFlags & 4) {
                    if (pDispParams->cArgs != 1) {
                        return DISP_E_BADPARAMCOUNT;
                    }
                    v = rgpVars[0];
                    if (v->vt != VT_BSTR && FAILED(__VariantChangeType(v, &v0, VT_BSTR))) {
                        if (puArgErr != 0) {
                            *puArgErr = 0;
                        }
                        return DISP_E_TYPEMISMATCH;
                    }
                    BSTR i1 = (BSTR) V_BSTR(v);
                    hr = ((::IEmployee*) this)->put_Address(i1);
                    break;
                }
            }
        case 3:
            {
                if (wFlags & 2) {
                    if (pDispParams->cArgs != 0) {
                        return DISP_E_BADPARAMCOUNT;
                    }
                    BSTR i1;
                    hr = ((::IEmployee*) this)->get_Telephone(&i1);
                    if (pVarResult != 0) {
                        V_VT(pVarResult) = VT_BSTR;
                        V_BSTR(pVarResult) = (BSTR) i1;
                    }
                    break;
                }
                else 
        if (wFlags & 4) {
                    if (pDispParams->cArgs != 1) {
                        return DISP_E_BADPARAMCOUNT;
                    }
                    v = rgpVars[0];
                    if (v->vt != VT_BSTR && FAILED(__VariantChangeType(v, &v0, VT_BSTR))) {
                        if (puArgErr != 0) {
                            *puArgErr = 0;
                        }
                        return DISP_E_TYPEMISMATCH;
                    }
                    BSTR i1 = (BSTR) V_BSTR(v);
                    hr = ((::IEmployee*) this)->put_Telephone(i1);
                    break;
                }
            }
        default:
            return DISP_E_MEMBERNOTFOUND;
        }
        return hr;
    }
    virtual HRESULT STDMETHODCALLTYPE IEmployee::GetIDsOfNames(
                /* [in] */ REFIID riid,
                /* [size_is][in] */ LPOLESTR *rgszNames,
                /* [in] */ UINT cNames,
                /* [in] */ LCID lcid,
                /* [size_is][out] */ DISPID *rgDispId) 
    {
        (void) riid;
        (void) rgszNames;
        (void) cNames;
        (void) lcid;
        (void) rgDispId;
        static LPOLESTR names[] = { L"Name", L"pVal", L"get_Name", L"put_Name", L"Address", L"get_Address", L"put_Address", L"Telephone", L"get_Telephone", L"put_Telephone" };
        static DISPID dids[] = { 1, 0, 1, 1, 2, 2, 2, 3, 3, 3 };
        for (unsigned int i = 0; i < cNames; ++i) {
            int fFoundIt = 0;
            for (unsigned int j = 0; j < sizeof(names)/sizeof(LPOLESTR); ++j) {
                if (_wcsicmp(rgszNames[i], names[j]) == 0) {
                    fFoundIt = 1;
                    rgDispId[i] = dids[j];
                    break;
                }
            }
            if (fFoundIt == 0) {
                return DISP_E_UNKNOWNNAME;
            }
        }
        return S_OK;
    }
    HRESULT TypeInfoHelper(REFIID iidDisp, LCID /*lcid*/, ITypeInfo** ppTypeInfo) 
    {
        if (ppTypeInfo == NULL) {
            return E_POINTER;
        }
        *ppTypeInfo = NULL;
        TCHAR szModule1[_MAX_PATH];
        int nLen = ::GetModuleFileName(_AtlBaseModule.GetModuleInstance(), szModule1, _MAX_PATH);
        if (nLen == 0 || nLen == _MAX_PATH) {
            return E_FAIL;
        }
        USES_CONVERSION_EX;
        LPOLESTR pszModule = T2OLE_EX(szModule1, _ATL_SAFE_ALLOCA_DEF_THRESHOLD);
#ifndef _UNICODE
        if (pszModule == NULL) {
            return E_OUTOFMEMORY;
        }
#endif
        CComPtr<ITypeLib> spTypeLib;
        HRESULT hr = LoadTypeLib(pszModule, &spTypeLib);
        if (SUCCEEDED(hr)) {
            CComPtr<ITypeInfo> spTypeInfo;
            hr = spTypeLib->GetTypeInfoOfGuid(iidDisp, &spTypeInfo);
            if (SUCCEEDED(hr)) {
                *ppTypeInfo = spTypeInfo.Detach();
            }
        }
        return hr;
    }
    virtual HRESULT STDMETHODCALLTYPE IEmployee::GetTypeInfoCount(unsigned int*  pctinfo) 
    {
        if (pctinfo == NULL) {
            return E_POINTER;
        }
        CComPtr<ITypeInfo> spTypeInfo;
        *pctinfo = 
                       (SUCCEEDED(TypeInfoHelper(__uuidof(IEmployee), 0, &spTypeInfo))) ? 1 : 0;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE IEmployee::GetTypeInfo(unsigned int iTInfo, LCID lcid, ITypeInfo** ppTInfo) 
    {
        if (iTInfo != 0) {
            return DISP_E_BADINDEX;
        }
        return TypeInfoHelper(__uuidof(IEmployee), lcid, ppTInfo);
    }
#injected_line 38 "c:\\componentdevelopment\\chapter12\\dynamiccollection\\company\\employee.h"
    static HRESULT WINAPI UpdateRegistry(BOOL) 
    {
        return S_OK;
    }
#injected_line 38 "c:\\componentdevelopment\\chapter12\\dynamiccollection\\company\\employee.h"
    static const CLSID& WINAPI GetObjectCLSID() 
    {
        return __uuidof(CEmployee);
    }
#injected_line 38 "c:\\componentdevelopment\\chapter12\\dynamiccollection\\company\\employee.h"
    static const TCHAR* GetObjectFriendlyName() 
    {
        return _T("CEmployee Object");
    }
#injected_line 38 "c:\\componentdevelopment\\chapter12\\dynamiccollection\\company\\employee.h"

    DECLARE_NOT_AGGREGATABLE(CEmployee);

#injected_line 38 "c:\\componentdevelopment\\chapter12\\dynamiccollection\\company\\employee.h"
    static const TCHAR* GetProgID() 
    {
        return _T("Company.Employee.1");
    }
#injected_line 38 "c:\\componentdevelopment\\chapter12\\dynamiccollection\\company\\employee.h"
    static const TCHAR* GetVersionIndependentProgID() 
    {
        return _T("Company.Employee");
    }
#injected_line 38 "c:\\componentdevelopment\\chapter12\\dynamiccollection\\company\\employee.h"
    BEGIN_COM_MAP(CEmployee)
        COM_INTERFACE_ENTRY(IEmployee)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
    END_COM_MAP()
#injected_line 31 "c:\\componentdevelopment\\chapter12\\dynamiccollection\\company\\employee.h"

    STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid) 
        					
    {
        static const IID* rgErrorGuids[] = 
            						{
            							&__uuidof(IEmployee)
            						};
        for (int i=0; i < sizeof(rgErrorGuids) / sizeof(rgErrorGuids[0]); i++)
						{
            if (InlineIsEqualGUID(*rgErrorGuids[i],riid))
                return S_OK;
        }
        return S_FALSE;
    } 

	//--- End Injected Code For Attribute 'support_error_info'
};

//+++ Start Injected Code For Attribute 'support_error_info'
#injected_line 31 "c:\\componentdevelopment\\chapter12\\dynamiccollection\\company\\employee.h"

				OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO(__uuidof(CEmployee), CEmployee)
			
//--- End Injected Code For Attribute 'support_error_info'


