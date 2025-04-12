// ���ϸ� : SmartPtr.h

template <class I>
class CSmartPtr
{
public:
	// ������
    CSmartPtr(I* pI = NULL) : m_pI(pI) {
		if (m_pI != NULL)
			m_pI->AddRef();
	} 
    // ��������� 
    CSmartPtr(const CSmartPtr<I>& rI) : m_pI(rI.m_pI) {
		if (m_pI != NULL)
			m_pI->AddRef();
	}
	// �Ҹ���
	~CSmartPtr() {
		if (m_pI != NULL)
			m_pI->Release();
	}
	// ���Կ�����
	CSmartPtr<I>& operator=(I* pI) {
		if (m_pI != pI) {
			if (m_pI != NULL)
				m_pI->Release();
			m_pI = pI ;
			if (m_pI != NULL)
				m_pI->AddRef();
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

