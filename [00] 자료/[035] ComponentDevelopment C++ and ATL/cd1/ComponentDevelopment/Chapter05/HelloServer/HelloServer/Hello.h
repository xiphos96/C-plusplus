#include "hello_h.h"

class CHello : public IHello
{
public:
	CHello(void);
	~CHello(void);
	// IUnknown �޼���
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, LPVOID* ppv);
	ULONG STDMETHODCALLTYPE AddRef(void);
	ULONG STDMETHODCALLTYPE Release(void);

	// IHello �޼���
	HRESULT STDMETHODCALLTYPE sayHello( 
            /* [string][in] */ wchar_t *name,
            /* [string][out] */ wchar_t **message);
private:
	DWORD m_cRef;
};
