// ShapeProp.cpp : CShapeProp의 구현입니다.

#include "stdafx.h"
#include "Shapec.h"
#include "ShapeProp.h"


// CShapeProp
LRESULT CShapeProp::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
	CComQIPtr<IShape, &__uuidof(IShape)> pShape(m_ppUnk[0]);
	short nShapeType;
	pShape->get_ShapeType(&nShapeType);
	m_shape.Attach(GetDlgItem(IDC_SHAPE));
	m_shape.AddString("사각형");
	m_shape.AddString("원형");
	m_shape.AddString("삼각형");
	m_shape.SetCurSel(nShapeType);
	m_bDirty = FALSE;
	return 0;
}

LRESULT CShapeProp::OnShapeTypeChange(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {
	SetDirty(TRUE);
	return 0;
}

STDMETHODIMP CShapeProp::Apply(void)
{
	USES_CONVERSION;
	ATLTRACE(_T("CShapeProp::Apply\n"));
	for (UINT i = 0; i < m_nObjects; i++)
	{
		// 여기에서 다음과 같이 해볼 수 있습니다.
		// ICircCtl* pCirc;
		// m_ppUnk[i]->QueryInterface(IID_ICircCtl, (void**)&pCirc);
		// pCirc->put_Caption(CComBSTR("something special"));
		// pCirc->Release();
		CComQIPtr<IShape, &__uuidof(IShape)> pShape(m_ppUnk[i]);
		short nShapeType = m_shape.GetCurSel();
		if(FAILED(pShape->put_ShapeType(nShapeType))) {
			CComPtr<IErrorInfo> pError;
			CComBSTR strError;
			GetErrorInfo(0, &pError);
			pError->GetDescription(&strError);
			MessageBox(OLE2T(strError), _T("에러"), MB_ICONEXCLAMATION);
			return E_FAIL;
		}
	}
	m_bDirty = FALSE;
	return S_OK;
}
