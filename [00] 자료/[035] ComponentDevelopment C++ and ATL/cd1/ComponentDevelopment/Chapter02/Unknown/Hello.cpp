// ÆÄÀÏ¸í : Hello.cpp
#include "stdafx.h"
#include "hello.h"

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
/*
IHello* CreateInstance()
{
	return (IHello*)new CHello;
}
*/
IHello* pHello = 0;
IHello* CreateInstance()
{
	if(pHello == 0)
		pHello = (IHello*)new CHello;
	return pHello;
}


IGoodbye* QueryInterface(IHello* p)
{
	CHello* pHello = (CHello*)p;
	return dynamic_cast<IGoodbye*>(pHello);
} 
