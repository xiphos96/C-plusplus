// Employees.cpp : CEmployees의 구현입니다.

#include "stdafx.h"
#include "Employee.h"
#include "Employees.h"


// CEmployees
STDMETHODIMP CEmployees::Add(IEmployee** retVal)
{
	CComObject<CEmployee>* pEmployee;
	HRESULT hr = CComObject<CEmployee>::CreateInstance(&pEmployee);
	CComPtr<IEmployee> pIEmployee;
	pEmployee->QueryInterface(__uuidof(IEmployee), (LPVOID*)&pIEmployee);
	m_coll.push_back(pIEmployee);
	*retVal = pIEmployee;
	(*retVal)->AddRef();
	return S_OK;
}

STDMETHODIMP CEmployees::Remove(long index)
{
	list< CAdapt< CComPtr<IEmployee> > >::iterator i;
	long loop = 0;

	for(i = m_coll.begin(); i != m_coll.end(); i++) {
		loop++;
		if(loop == index) {
			(*i).m_T.Release(); 
			m_coll.erase(i);
			break;
		}
	}
	return S_OK;
}
