// Employees.h : CEmployees狼 急攫涝聪促.

#pragma once
#include "resource.h"       // 林 扁龋涝聪促.
#include "Employee.h"


// IEmployees
[
	object,
	uuid("C6783455-282B-4AB5-BED5-C8D3A8C38E72"),
	dual,	helpstring("IEmployees 牢磐其捞胶"),
	pointer_default(unique)
]
__interface IEmployees : IDispatch
{
	[propget, id(1), helpstring("加己 Count")] HRESULT Count([out, retval] long* pVal);
	[propget, id(DISPID_VALUE), helpstring("加己 Item")] HRESULT Item([in] long index, [out, retval] VARIANT* pVal);
	[propget, id(DISPID_NEWENUM), helpstring("加己 _NewEnum")] HRESULT _NewEnum([out, retval] IUnknown** pVal);
};



// CEmployees

[
	coclass,
	threading("apartment"),
	support_error_info("IEmployees"),
	aggregatable("never"),
	vi_progid("Company.Employees"),
	progid("Company.Employees.1"),
	version(1.0),
	uuid("6D52EEFB-AEE7-4C46-A472-9350BAC970F0"),
	helpstring("Employees Class"),
	noncreatable
]
class ATL_NO_VTABLE CEmployees : 
	public IEmployees
{
public:
	CEmployees()
	{
		m_pEmployees = NULL;
		m_Count = 0;
	}
	~CEmployees() {
		delete [] m_pEmployees;
	}


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

public:

	STDMETHOD(get_Count)(long* pVal);
	STDMETHOD(get_Item)(long index, VARIANT* pVal);
	STDMETHOD(get__NewEnum)(IUnknown** pVal);


	void Init () {
		static char* names[] = {
					"辫老", "辫捞", "辫伙", "辫荤", "辫坷",
					"辫腊", "辫磨", "辫迫", "辫备", "辫绞"};
		static char* addrs[] = {
					"林家1", "林家2", "林家3", "林家4", "林家5",
					"林家6", "林家7", "林家8", "林家9", "林家10"};
		static char* telnos[] = {
					"111-1111", "222-2222", "333-3333",
					"444-4444", "555-5555", "666-6666",
					"777-7777", "888-8888", "999-9999",
					"000-0000"};

		if (m_pEmployees != NULL)
			delete [] m_pEmployees;
		m_Count = 10;
	 
		m_pEmployees = new CComVariant[m_Count];
	 
		CComObject<CEmployee>* pEmployee;
		LPDISPATCH lpDisp = NULL;
	 
		for (int i = 0; i < m_Count; i++) {
			HRESULT hr = CComObject<CEmployee>::CreateInstance(&pEmployee);
			if(FAILED(hr)) {
				MessageBox(NULL, "Employe 按眉甫 积己且 荐 绝嚼聪促.", NULL, MB_OK);
				return;
			}
			pEmployee->m_Name = names[i];
			pEmployee->m_Address = addrs[i];
			pEmployee->m_Telephone = telnos[i];
			pEmployee->QueryInterface(IID_IDispatch, (void**)&lpDisp);
			CComVariant& var = m_pEmployees[i];
			var.vt = VT_DISPATCH;
			var.pdispVal = lpDisp;
		}
	}
protected:
	long m_Count;
	CComVariant* m_pEmployees;
};

