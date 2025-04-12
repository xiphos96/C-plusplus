// Companyo.cpp : CCompany의 구현입니다.

#include "stdafx.h"
#include "Employee.h"
#include "Employees.h"
#include "Companyo.h"


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
