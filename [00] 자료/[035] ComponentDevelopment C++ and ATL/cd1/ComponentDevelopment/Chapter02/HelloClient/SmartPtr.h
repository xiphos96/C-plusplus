// 파일명 : SmartPtr.h

template <class I>
class CSmartPtr
{
public:
	// 생성자
    CSmartPtr(I* pI = NULL) : m_pI(pI) {
		if (m_pI != NULL)
			m_pI->AddRef();
	} 
    // 복사생성자 
    CSmartPtr(const CSmartPtr<I>& rI) : m_pI(rI.m_pI) {
		if (m_pI != NULL)
			m_pI->AddRef();
	}
	// 소멸자
	~CSmartPtr() {
		if (m_pI != NULL)
			m_pI->Release();
	}
	// 대입연산자
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
	// 변환연산자
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

