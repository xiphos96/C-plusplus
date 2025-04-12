class CHelloFactory : public IClassFactory
{
public:
	CHelloFactory(void);
	~CHelloFactory(void);
	// IUnknown �޼���
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, LPVOID* ppv);
	ULONG STDMETHODCALLTYPE AddRef(void);
	ULONG STDMETHODCALLTYPE Release(void);

	// IClassFactory �޼���
	HRESULT STDMETHODCALLTYPE CreateInstance(
								LPUNKNOWN pUnkOuter, 
								REFIID riid, 
								LPVOID* ppv);
	HRESULT STDMETHODCALLTYPE LockServer(BOOL bLock);

private:
	DWORD m_cRef;
};
