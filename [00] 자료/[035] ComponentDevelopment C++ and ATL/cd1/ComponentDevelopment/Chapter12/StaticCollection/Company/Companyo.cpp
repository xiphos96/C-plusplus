// Companyo.cpp : CCompany�� �����Դϴ�.

#include "stdafx.h"
#include "Companyo.h"
#include ".\companyo.h"


// CCompany


STDMETHODIMP CCompany::get_Employees(VARIANT* pVal)
{
	VariantInit(pVal);
	IDispatch* pDisp;
	m_pEmployees->QueryInterface(IID_IDispatch, (LPVOID*)&pDisp);
	pVal->vt = VT_DISPATCH;
	pVal->pdispVal = pDisp;

	return S_OK;
}
