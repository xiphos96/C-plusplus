// Employee.cpp : CEmployee�� �����Դϴ�.

#include "stdafx.h"
#include "Employee.h"
#include ".\employee.h"


// CEmployee


STDMETHODIMP CEmployee::get_Name(BSTR* pVal)
{
	*pVal = m_Name.Copy();
	return S_OK;
}

STDMETHODIMP CEmployee::get_Address(BSTR* pVal)
{
	*pVal = m_Address.Copy();
	return S_OK;
}

STDMETHODIMP CEmployee::get_Telephone(BSTR* pVal)
{
	*pVal = m_Telephone.Copy();
	return S_OK;
}
