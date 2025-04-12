// AddBack.cpp : Implementation of CAddBack

#include "stdafx.h"
#include "AddBack.h"


// CAddBack


STDMETHODIMP CAddBack::Add(long addend, long sum, long* result)
{
	// TODO: Add your implementation code here
	*result = sum + addend;
	IObjectContext* pIContext = NULL;
	::CoGetObjectContext(IID_IObjectContext, (LPVOID*)&pIContext);
	pIContext->SetComplete();
	return S_OK;
}
