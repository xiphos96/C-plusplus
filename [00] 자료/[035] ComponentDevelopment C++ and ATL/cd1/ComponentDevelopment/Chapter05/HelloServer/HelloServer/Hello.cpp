#include "stdafx.h"
#include "hello.h"

CHello::CHello(void)
{
	m_cRef = 0;
}

CHello::~CHello(void)
{
}

HRESULT STDMETHODCALLTYPE 
CHello::QueryInterface(REFIID riid, LPVOID* ppv)
{
	HRESULT hr = E_NOINTERFACE;
	*ppv = NULL;

	if(riid == IID_IUnknown || riid == IID_IHello)
		*ppv = static_cast<IHello*>(this);

	if(*ppv != NULL) {
		AddRef();
		hr = S_OK;
	}

	return hr;
}

ULONG STDMETHODCALLTYPE CHello::AddRef(void)
{
	return ++m_cRef;
}

ULONG STDMETHODCALLTYPE CHello::Release(void)
{
	if(--m_cRef == 0) {
		// COM 객체 카운터를 감소시킨다.
		--g_cObjects;
		delete this;
		// 가능하다면 종료한다.
		CloseExe();
	}
	return m_cRef;
}

HRESULT STDMETHODCALLTYPE CHello::sayHello( 
            /* [string][in] */ wchar_t *name,
            /* [string][out] */ wchar_t **message)
{
	char * buffer = (char*)::CoTaskMemAlloc(256);
	if(buffer == NULL)
		return E_FAIL;

	::wsprintf(buffer, "%s 씨 안녕하세요?", name);
	*message = (wchar_t*)buffer;
	
	return S_OK;
}
