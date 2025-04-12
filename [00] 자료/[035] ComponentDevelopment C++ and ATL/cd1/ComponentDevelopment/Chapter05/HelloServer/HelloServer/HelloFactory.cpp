#include "stdafx.h"
#include "hellofactory.h"
#include "hello.h"


CHelloFactory::CHelloFactory(void)
{
	m_cRef = 0;
}

CHelloFactory::~CHelloFactory(void)
{
}

HRESULT STDMETHODCALLTYPE 
CHelloFactory::QueryInterface(REFIID riid, LPVOID* ppv)
{
	HRESULT hr = E_NOINTERFACE;
	*ppv = NULL;

	if(riid == IID_IUnknown || riid == IID_IClassFactory)
		*ppv = this;

	if(*ppv != NULL) {
		AddRef();
		hr = NO_ERROR;
	}

	return hr;
}

ULONG STDMETHODCALLTYPE 
CHelloFactory::AddRef(void)
{
	return ++m_cRef;
}

ULONG STDMETHODCALLTYPE 
CHelloFactory::Release(void)
{
	if(--m_cRef == 0)
		delete this;
	return m_cRef;
}

HRESULT STDMETHODCALLTYPE 
CHelloFactory::CreateInstance(
				LPUNKNOWN pUnkOuter, 
				REFIID riid, 
				LPVOID* ppv)
{
	HRESULT hr = E_FAIL;
	CHello* pHello = NULL;
	*ppv = NULL;

	if(pUnkOuter != NULL)
		hr = CLASS_E_NOAGGREGATION;
	else {
		
		pHello = new CHello;
		if(pHello != NULL) {
		    // COM 객체 카운터를 증가시킨다
			++g_cObjects;
			hr = pHello->QueryInterface(riid, ppv);
			if(FAILED(hr)) {
        	    // COM 객체 카운터를 감소시킨다
				--g_cObjects;
				delete pHello;
				// 가능하다면 종료시킨다	
				CloseExe();		
			}
		}
		else
			hr = E_OUTOFMEMORY;
	}
	return hr;
}

HRESULT STDMETHODCALLTYPE 
CHelloFactory::LockServer(BOOL bLock)
{
	if(bLock)
		++g_cLocks;
	else
		--g_cLocks;
	return S_OK;
}
