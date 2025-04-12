// ÆÄÀÏ¸í : Hello2.cpp
#include "stdafx.h"
#include "hello2.h"

CHello::CHello(void) : m_cref(0)
{
}

bool CHello::QueryInterface(IID iid, void** ppv)
{
	*ppv = 0;
	if(iid == IID_IUnknown)
		*ppv = (IUnknown*)(IHello*)this;
	else
	if(iid == IID_IHello)
		*ppv = (IHello*)this;
	else
	if(iid == IID_IGoodbye)
		*ppv = (IGoodbye*)this;	

	if(*ppv != 0) {
		((CHello*)*ppv)->AddRef();
		return true;
	}
	return false;
}

int CHello::AddRef(void)
{
	return ++m_cref;
}

int CHello::Release(void)
{
	if(--m_cref == 0)
		delete this;
	return m_cref;
}

char* CHello::sayHello(char* name)
{
	sprintf(buf, "%s ¾¾ ¾È³çÇÏ¼¼¿ä?", name);
	return buf;
}

char* CHello::sayGoodbye(char* name)
{
	sprintf(buf, "%s ¾¾ ¾È³çÈ÷ °¡¼¼¿ä.", name);

	return buf;
}

IUnknown* CreateInstance()
{
	CHello* pHello = new CHello;
	IUnknown* pUnk = 0;
	pHello->QueryInterface(IID_IUnknown, (void**)&pUnk);
	return pUnk;
}
