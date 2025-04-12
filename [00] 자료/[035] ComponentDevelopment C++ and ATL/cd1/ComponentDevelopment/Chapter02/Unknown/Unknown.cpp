// Unknown.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include "stdafx.h"
#include "Hello2.h"

void SayHello(IHello* pHello);
void SayGoodbye(IGoodbye* pBye);

using namespace std;

/* Hello ����

int main()
{
	IHello* pHello = CreateInstance();
	SayHello(pHello);

	// IGoodbye* pBye = (IGoodbye*)pHello;		// ����! �̷� ���� ����ɴϴ�!!!
	// ����! �̰͵� �ƴϵǿɴϴ�!!!
	// IGoodbye* pBye = dynamic_cast<IGoodbye*>(pHello);	
	// ����! �̷��ø� �����Ϸ��� �����Ͽɴϴ�!!!
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

	cout << "�̸��� �Է��ϼ��� : ";
	cin >> name;
	message = pHello->sayHello(name);
	cout << message << endl;
}

void SayGoodbye(IGoodbye* pBye)
{
	char name[256];
	char* message;

	cout << "�̸��� �Է��ϼ��� : ";
	cin >> name;
	message = pBye->sayGoodbye(name);
	cout << message << endl;
}
*/

// Hello2 ����

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

	cout << "�̸��� �Է��ϼ��� : ";
	cin >> name;
	message = pHello->sayHello(name);
	cout << message << endl;
	pHello->Release();
}

void SayGoodbye(IGoodbye* pBye)
{
	char name[256];
	char* message;

	cout << "�̸��� �Է��ϼ��� : ";
	cin >> name;
	message = pBye->sayGoodbye(name);
	cout << message << endl;
	pBye->Release();
}


