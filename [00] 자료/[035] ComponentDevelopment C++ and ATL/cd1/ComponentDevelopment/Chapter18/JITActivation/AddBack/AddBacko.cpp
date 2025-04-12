// AddBacko.cpp : Implementation of CAddBack

#include "stdafx.h"
#include "AddBacko.h"


// CAddBack


STDMETHODIMP CAddBack::Add(long addend)
{
	// TODO: Add your implementation code here
	m_sum += addend;
	IObjectContext* pIContext = NULL;
	::CoGetObjectContext(IID_IObjectContext, (LPVOID*)&pIContext);
	pIContext->SetComplete();
	return S_OK;
}

STDMETHODIMP CAddBack::getSum(long* sum)
{
	// TODO: Add your implementation code here
	*sum = m_sum;
	IObjectContext* pIContext = NULL;
	::CoGetObjectContext(IID_IObjectContext, (LPVOID*)&pIContext);
	pIContext->SetComplete();
	return S_OK;
}
