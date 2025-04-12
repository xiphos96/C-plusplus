// Employee.cpp : CEmployee의 구현입니다.

#include "stdafx.h"
#include "Employee.h"


// CEmployee


STDMETHODIMP CEmployee::get_Name(BSTR* pVal)
{
	*pVal = m_Name.Copy();
	return S_OK;
}

STDMETHODIMP CEmployee::put_Name(BSTR newVal)
{
	m_Name = newVal;
	return S_OK;
}


STDMETHODIMP CEmployee::get_Address(BSTR* pVal)
{
	*pVal = m_Address.Copy();
	return S_OK;
}

STDMETHODIMP CEmployee::put_Address(BSTR newVal)
{
	m_Address = newVal;
	return S_OK;
}


STDMETHODIMP CEmployee::get_Telephone(BSTR* pVal)
{
	*pVal = m_Telephone.Copy();
	return S_OK;
}

STDMETHODIMP CEmployee::put_Telephone(BSTR newVal)
{
	m_Telephone = newVal;
	return S_OK;
}

