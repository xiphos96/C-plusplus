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

	pISecurity->IsCallerInRole(L"관리자", &bIsInManagerRole);
	if(bIsInManagerRole == VARIANT_TRUE)
		bstrResult = "관리자 역할로 메서드를 수행했습니다.";
	else
		bstrResult = "일반 사용자 역할로 메서드를 수행했습니다.";

    bstrResult.CopyTo(result);

	return S_OK;
}
