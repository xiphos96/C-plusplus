#include "StdAfx.h"
#include ".\clientview.h"
#include "atlmisc.h"


LRESULT CClientView::OnBnClickedButton2(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	IEmployeePtr pEmployee;
	_bstr_t name;
	_bstr_t address;
	_bstr_t telephone;
	CString str;
	
	while(m_list.GetCount())
		m_list.DeleteString(0);
	m_list.AddString("Cout/Item 속성");
	for(int i = 0; i < m_pEmployees->Count; ++i) {
		pEmployee = m_pEmployees->Item[i+1];
		name = pEmployee->Name;
		address = pEmployee->Address;
		telephone = pEmployee->Telephone;
		str.Format("이름 : %s  주소 : %s  전화번호 : %s",
					(char*)name, (char*)address, (char*)telephone);
		m_list.AddString(str);
		pEmployee = 0;
	}
	return 0;
}

LRESULT CClientView::OnBnClickedButton3(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	IEmployeePtr pEmployee;
	IEnumVARIANTPtr pEnum;
	_bstr_t name;
	_bstr_t address;
	_bstr_t telephone;
	VARIANT var[10];
	ULONG count, i;
	CString str;
	
	pEnum = m_pEmployees->_NewEnum;
	for(i = 0; i < 10; ++i)
		VariantInit(&var[i]);
	pEnum->Next(10, var, &count);

	while(m_list.GetCount())
		m_list.DeleteString(0);
	m_list.AddString("_NewEnum 속성");
	for(i = 0; i < count; ++i) {
		pEmployee = var[i].punkVal;
		name = pEmployee->Name;
		address = pEmployee->Address;
		telephone = pEmployee->Telephone;
		str.Format("이름 : %s  주소 : %s  전화번호 : %s",
					(char*)name, (char*)address, (char*)telephone);
		m_list.AddString(str);
		pEmployee = 0;
	}
	return 0;
}
