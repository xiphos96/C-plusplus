#include "stdafx.h"
#include "smartqiptr.h"

template <class I, const IID* piid> inline
CSmartQIPtr<I, piid>::CSmartQIPtr(I* pI /*=NULL*/)
				: m_pI(pI)
{
	if (m_pI != NULL)
		m_pI->AddRef();
} 

template <class I, const IID* piid> inline
CSmartQIPtr<I, piid>::CSmartQIPtr(const CSmartQIPtr<I, piid>& rI)
				: m_pI(rI.m_pI)
{
	if (m_pI != NULL)
		m_pI->AddRef();
}

template <class I, const IID* piid> inline
CSmartQIPtr<I, piid>::~CSmartQIPtr()
{
	if (m_pI != NULL)
		m_pI->Release();
}

template <class I, const IID* piid> inline
CSmartQIPtr<I, piid>& CSmartQIPtr<I, piid>::operator=(I* pI)
{
	if (m_pI != pI) {
		if (m_pI != NULL)
			m_pI->Release();
		m_pI = pI ;
		if (m_pI != NULL)
			m_pI->AddRef();
   }      
   return *this;
}

template <class I, const IID* piid> inline
CSmartQIPtr<I, piid>::operator I*()
{ 
	return m_pI;
} 

template <class I, const IID* piid> inline
I* CSmartQIPtr<I, piid>::operator->()
{
	return m_pI;
}

template <class I, const IID* piid> inline
I** CSmartQIPtr<I, piid>::operator&()
{
	return &m_pI ;
}

template <class I, const IID* piid> inline
BOOL CSmartQIPtr<I, piid>::operator==(I* pI) const
{
	return (m_pI == pI);
}

template <class I, const IID* piid> inline
BOOL CSmartQIPtr<I, piid>::operator!=(I* pI) const
{
	return (m_pI != pI);
}

template <class I, const IID* piid> inline
BOOL CSmartQIPtr<I, piid>::operator!() const
{
	return !m_pI ;
}

template <class I, const IID* piid> inline
CSmartQIPtr<I, piid>::CSmartQIPtr(IUnknown* pUnk)
				: m_pI(NULL)
{
	pUnk->QueryInterface(*piid, (void**)&m_pI);
} 

template <class I, const IID* piid> inline 
CSmartQIPtr<I, piid>& CSmartQIPtr<I, piid>::operator=(IUnknown* pUnk)
{
	if (m_pI != pUnk) {
		if (m_pI != NULL)
			m_pI->Release();
		if(pUnk != NULL)
			pUnk->QueryInterface(*piid, (void**)&m_pI);
   }      
   return *this;
}
