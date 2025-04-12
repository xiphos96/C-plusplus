// Employees.cpp : CEmployees의 구현입니다.

#include "stdafx.h"
#include "Employees.h"
#include ".\employees.h"


// CEmployees


STDMETHODIMP CEmployees::get_Count(long* pVal)
{
	*pVal = m_Count;
	return S_OK;
}

STDMETHODIMP CEmployees::get_Item(long index, VARIANT* pVal)
{
	if (NULL == pVal) 
		return E_POINTER;
 
	// 인덱스는 1에서 시작(VB용)
	if ((index < 1) || (index > m_Count))
		return E_INVALIDARG;
	
	VariantInit(pVal);
	pVal->vt = VT_UNKNOWN;
	pVal->punkVal = NULL;
 
	// 0 에서 시작하는 인덱스로 변경
	HRESULT hr = VariantCopy(pVal, &m_pEmployees[index-1]);
	if(FAILED(hr))
		MessageBox(NULL, "Can't get the Item.", NULL, MB_OK);

	return hr;
}

STDMETHODIMP CEmployees::get__NewEnum(IUnknown** pVal)
{
	if (NULL == pVal) 
		return E_POINTER;
	*pVal = NULL;
 
	typedef CComObject<
		CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, 
		 _Copy<VARIANT> > > EnumVar;
	EnumVar* p = new EnumVar;
 
	HRESULT hr = p->Init(&m_pEmployees[0], 
						 &m_pEmployees[m_Count], 
						 NULL, AtlFlagCopy);
 
	if (SUCCEEDED(hr))
		hr = p->QueryInterface(IID_IEnumVARIANT, (LPVOID*)pVal);
	if (FAILED(hr))
		delete p;
 
	return hr;
}
