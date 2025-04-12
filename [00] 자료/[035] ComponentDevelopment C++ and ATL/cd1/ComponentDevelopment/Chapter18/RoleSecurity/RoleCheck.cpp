// RoleCheck.cpp : Implementation of CRoleCheck

#include "stdafx.h"
#include "RoleCheck.h"


// CRoleCheck


STDMETHODIMP CRoleCheck::SecurityCheck(BSTR* result)
{
	// TODO: Add your implementation code here
	CComBSTR bstrResult;

	ISecurityCallContext* pISecurity;
	VARIANT_BOOL bIsInManagerRole;
	::CoGetCallContext(IID_ISecurityCallContext, (LPVOID*)&pISecurity);

	pISecurity->IsCallerInRole(L"������", &bIsInManagerRole);
	if(bIsInManagerRole == VARIANT_TRUE)
		bstrResult = "������ ���ҷ� �޼��带 �����߽��ϴ�.";
	else
		bstrResult = "�Ϲ� ����� ���ҷ� �޼��带 �����߽��ϴ�.";

    bstrResult.CopyTo(result);

	return S_OK;
}
