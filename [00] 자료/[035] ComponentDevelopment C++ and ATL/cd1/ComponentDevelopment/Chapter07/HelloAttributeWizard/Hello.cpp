// Hello.cpp : CHello�� �����Դϴ�.

#include "stdafx.h"
#include "Hello.h"
#include ".\hello.h"


// CHello


STDMETHODIMP CHello::sayHello(wchar_t* name, wchar_t** message)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	char * buffer = (char*)::CoTaskMemAlloc(256);
	if(buffer == NULL)
		return E_FAIL;
	
	::wsprintf(buffer, "%s �� �ȳ��ϼ���?", name);
	*message = (wchar_t*)buffer;

	return S_OK;
}
