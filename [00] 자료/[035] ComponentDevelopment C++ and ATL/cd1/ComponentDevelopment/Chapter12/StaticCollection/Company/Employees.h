// Employees.h : CEmployees�� �����Դϴ�.

#pragma once
#include "resource.h"       // �� ��ȣ�Դϴ�.
#include "Employee.h"


// IEmployees
[
	object,
	uuid("C6783455-282B-4AB5-BED5-C8D3A8C38E72"),
	dual,	helpstring("IEmployees �������̽�"),
	pointer_default(unique)
]
__interface IEmployees : IDispatch
{
	[propget, id(1), helpstring("�Ӽ� Count")] HRESULT Count([out, retval] long* pVal);
	[propget, id(DISPID_VALUE), helpstring("�Ӽ� Item")] HRESULT Item([in] long index, [out, retval] VARIANT* pVal);
	[propget, id(DISPID_NEWENUM), helpstring("�Ӽ� _NewEnum")] HRESULT _NewEnum([out, retval] IUnknown** pVal);
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
					"����", "����", "���", "���", "���",
					"����", "��ĥ", "����", "�豸", "���"};
		static char* addrs[] = {
					"�ּ�1", "�ּ�2", "�ּ�3", "�ּ�4", "�ּ�5",
					"�ּ�6", "�ּ�7", "�ּ�8", "�ּ�9", "�ּ�10"};
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
				MessageBox(NULL, "Employe ��ü�� ������ �� �����ϴ�.", NULL, MB_OK);
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

