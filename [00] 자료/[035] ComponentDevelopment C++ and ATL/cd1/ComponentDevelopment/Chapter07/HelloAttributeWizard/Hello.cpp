// Hello.cpp : CHello의 구현입니다.

#include "stdafx.h"
#include "Hello.h"
#include ".\hello.h"


// CHello


STDMETHODIMP CHello::sayHello(wchar_t* name, wchar_t** message)
{
	// TODO: 여기에 구현 코드를 추가합니다.
	char * buffer = (char*)::CoTaskMemAlloc(256);
	if(buffer == NULL)
		return E_FAIL;
	
	::wsprintf(buffer, "%s 씨 안녕하세요?", name);
	*message = (wchar_t*)buffer;

	return S_OK;
}
