#include "stdafx.h"
#include "smartptr.h"

template <class I> inline
CSmartPtr<I>::CSmartPtr(I* pI /*=NULL*/)
				: m_pI(pI)
{
	if (m_pI != NULL)
		m_pI->AddRef();
} 

template <class I> inline
CSmartPtr<I>::CSmartPtr(const CSmartPtr<I>& rI)
				: m_pI(rI.m_pI)
{
	if (m_pI != NULL)
		m_pI->AddRef();
}

template <class I> inline 
CSmartPtr<I>::~CSmartPtr()
{
	if (m_pI != NULL)
		m_pI->Release();
}

template <class I> inline 
CSmartPtr<I>& CSmartPtr<I>::operator=(I* pI)
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

template <class I> inline 
CSmartPtr<I>::operator I*()
{ 
	return m_pI;
} 

template <class I> inline 
I* CSmartPtr<I>::operator->()
{
	return m_pI;
}

template <class I> inline 
I** CSmartPtr<I>::operator&()
{
	return &m_pI ;
}

template <class I> inline 
BOOL CSmartPtr<I>::operator==(I* pI) const
{
	return (m_pI == pI);
}

template <class I> inline 
BOOL CSmartPtr<I>::operator!=(I* pI) const
{
	return (m_pI != pI);
}

template <class I> inline 
BOOL CSmartPtr<I>::operator!() const
{
	return !m_pI ;
}


