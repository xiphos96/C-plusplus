// ���ϸ� : SmartQIPtr.h

template <class I, const IID* piid>
class CSmartQIPtr
{
public:
	// ������
    CSmartQIPtr(I* pI = NULL) : m_pI(pI) {
		if (m_pI != NULL)
			m_pI->AddRef();
	} 
	CSmartQIPtr(IUnknown* pUnk) {
		pUnk->QueryInterface(*piid, (void**)&m_pI);
	} 
    // ���������
    CSmartQIPtr(const CSmartQIPtr<I, piid>& rI) : m_pI(rI.m_pI) {
		if (m_pI != NULL)
			m_pI->AddRef();
	}
	// �Ҹ���
	~CSmartQIPtr() {
		if (m_pI != NULL)
			m_pI->Release();
	}
	// ���Կ�����
	CSmartQIPtr<I, piid>& operator=(I* pI) {
		if (m_pI != pI) {
			if (m_pI != NULL)
				m_pI->Release();
			m_pI = pI ;
			if (m_pI != NULL)
				m_pI->AddRef();
		}      
		return *this;
	}
	CSmartQIPtr<I, piid>& operator=(IUnknown* pUnk) {
		if (m_pI != pUnk) {
			if (m_pI != NULL)
				m_pI->Release();
			if(pUnk != NULL)
				pUnk->QueryInterface(*piid, (void**)&m_pI);
		}      
		return *this;
	}
	// ��ȯ������
	operator I*() { 
		return m_pI;
	} 
	I* operator->() {
		return m_pI;
	}
	I** operator&() {
		return &m_pI ;
	}
	BOOL operator==(I* pI) const {
		return (m_pI == pI);
	}
	BOOL operator!=(I* pI) const {
		return (m_pI != pI);
	}
	BOOL operator!() const {
		return !m_pI ;
	}
protected:
	I* m_pI;
};

