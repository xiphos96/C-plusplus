#ifndef __COLLECTIONSTL_H_
#define __COLLECTIONSTL_H_

#include <list>
using namespace std;

template <typename T>
struct _CopyVariantFromAdapt {
	static HRESULT copy(VARIANT* p1, CAdapt< CComPtr<T> >* p2) {
		HRESULT hr = p2->m_T->QueryInterface(IID_IDispatch, (void**)&p1->pdispVal);
		if( SUCCEEDED(hr) ) {
			p1->vt = VT_DISPATCH;
		}
		else {
			hr = p2->m_T->QueryInterface(IID_IUnknown, (void**)&p1->punkVal);
			if( SUCCEEDED(hr) ) {
				p1->vt = VT_UNKNOWN;
			}
		}
		return hr;
	}
	
	static void init(VARIANT* p)    { VariantInit(p); }
	static void destroy(VARIANT* p) { VariantClear(p); }
};

template <typename T>
struct _CopyInterfaceFromAdapt {
	static HRESULT copy(T** p1, CAdapt< CComPtr<T> >* p2) {
		if( *p1 = p2->m_T ) 
			return (*p1)->AddRef(), S_OK;
		return E_POINTER;
	}
		
	static void init(T** p)    {}
	static void destroy(T** p) { if( *p ) (*p)->Release(); }
};

template <class T, class CollType, class ItemType, class CopyItem, class EnumType>
class ICollectionOnSTLImpl2 : public T
{
public:
	STDMETHOD(get_Count)(long* pcount)
	{
		if (pcount == NULL)
			return E_POINTER;
		*pcount = m_coll.size();
		return S_OK;
	}
	STDMETHOD(get_Item)(VARIANT Index, ItemType* pvar)
	{
		//Index is 1-based
		if (pvar == NULL)
			return E_POINTER;
		HRESULT hr = S_FALSE;
		long index;
		CComBSTR key;

		if (Index.vt == VT_I2)
			index = Index.iVal;
		else if (Index.vt == VT_I4)
			index = Index.lVal;
		else if (Index.vt == VT_BSTR) {
			index = m_coll.size()+1;
			key = Index.bstrVal;
			key.ToUpper();
		}
		else
			return hr;
		
		index--;
		CollType::iterator iter = m_coll.begin();
		while (iter != m_coll.end() && index > 0)
		{
			if (Index.vt == VT_BSTR) {
				CComBSTR name;
				(*iter).m_T->get_Name(&name);
				name.ToUpper();
				if (key == name)
					break;
			}
			iter++;
			index--;
		}
		if (iter != m_coll.end())
			hr = CopyItem::copy(pvar, &*iter);
		return hr;
	}
	STDMETHOD(get__NewEnum)(IUnknown** ppUnk)
	{
		if (ppUnk == NULL)
			return E_POINTER;
		*ppUnk = NULL;
		HRESULT hRes = S_OK;
		CComObject<EnumType>* p;
		hRes = CComObject<EnumType>::CreateInstance(&p);
		if (SUCCEEDED(hRes))
		{
			hRes = p->Init(this, m_coll);
			if (hRes == S_OK)
				hRes = p->QueryInterface(IID_IUnknown, (void**)ppUnk);
		}
		if (hRes != S_OK)
			delete p;
		return hRes;
	}
	CollType m_coll;
};

#endif //__COLLECTIONSTL_H_