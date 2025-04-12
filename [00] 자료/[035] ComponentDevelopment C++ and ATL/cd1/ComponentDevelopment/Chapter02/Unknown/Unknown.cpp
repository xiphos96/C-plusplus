// Unknown.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include "Hello2.h"

void SayHello(IHello* pHello);
void SayGoodbye(IGoodbye* pBye);

using namespace std;

/* Hello 버전

int main()
{
	IHello* pHello = CreateInstance();
	SayHello(pHello);

	// IGoodbye* pBye = (IGoodbye*)pHello;		// 마마! 이럴 수는 없사옵니다!!!
	// 마마! 이것도 아니되옵니다!!!
	// IGoodbye* pBye = dynamic_cast<IGoodbye*>(pHello);	
	// 마마! 이러시면 컴파일러가 불평하옵니다!!!
	// IGoodbye* pBye = static_cast<IGoodbye*>(pHello);	
	IGoodbye* pBye = QueryInterface(pHello);
	SayGoodbye(pBye);

	delete pHello;
	return 0;
}

void SayHello(IHello* pHello)
{
	char name[256];
	char* message;

	cout << "이름을 입력하세요 : ";
	cin >> name;
	message = pHello->sayHello(name);
	cout << message << endl;
}

void SayGoodbye(IGoodbye* pBye)
{
	char name[256];
	char* message;

	cout << "이름을 입력하세요 : ";
	cin >> name;
	message = pBye->sayGoodbye(name);
	cout << message << endl;
}
*/

// Hello2 버전

int main()
{
	IUnknown* pUnk = CreateInstance();
	IHello* pHello;
	pUnk->QueryInterface(IID_IHello, (void**)&pHello);
	SayHello(pHello);

	IGoodbye* pBye;
	pHello->QueryInterface(IID_IGoodbye, (void**)&pBye);
	SayGoodbye(pBye);
	return 0;
}

void SayHello(IHello* pHello)
{
	char name[256];
	char* message;

	cout << "이름을 입력하세요 : ";
	cin >> name;
	message = pHello->sayHello(name);
	cout << message << endl;
	pHello->Release();
}

void SayGoodbye(IGoodbye* pBye)
{
	char name[256];
	char* message;

	cout << "이름을 입력하세요 : ";
	cin >> name;
	message = pBye->sayGoodbye(name);
	cout << message << endl;
	pBye->Release();
}


