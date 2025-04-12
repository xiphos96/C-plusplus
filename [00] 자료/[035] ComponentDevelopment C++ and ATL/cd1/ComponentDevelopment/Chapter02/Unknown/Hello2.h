// 파일명 : Hello2.h
#include "IHello2.h"

class CHello : public IHello,
			   public IGoodbye
{
public:
	CHello(void);
	// IUnknown 인터페이스 메서드
	bool QueryInterface(IID iid, void** ppv);
	int AddRef(void);
	int Release(void);
	// IHello 및 IGoodbye 인터페이스 메서드
	char* sayHello(char* name);
	char* sayGoodbye(char* name);
private:
	char buf[256];
	int m_cref;		// 참조 카운터
};
