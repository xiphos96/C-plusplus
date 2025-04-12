// ���ϸ� : Hello2.h
#include "IHello2.h"

class CHello : public IHello,
			   public IGoodbye
{
public:
	CHello(void);
	// IUnknown �������̽� �޼���
	bool QueryInterface(IID iid, void** ppv);
	int AddRef(void);
	int Release(void);
	// IHello �� IGoodbye �������̽� �޼���
	char* sayHello(char* name);
	char* sayGoodbye(char* name);
private:
	char buf[256];
	int m_cref;		// ���� ī����
};
