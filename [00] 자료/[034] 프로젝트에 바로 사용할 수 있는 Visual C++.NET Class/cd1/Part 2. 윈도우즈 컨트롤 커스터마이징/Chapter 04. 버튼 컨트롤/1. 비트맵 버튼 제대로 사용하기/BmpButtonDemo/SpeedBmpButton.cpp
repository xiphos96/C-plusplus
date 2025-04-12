// SpeedBmpButton.cpp : implementation file
//

#include "stdafx.h"
#include "bmpbuttondemo.h"
#include "SpeedBmpButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpeedBmpButton

CSpeedBmpButton::CSpeedBmpButton()
{
}

CSpeedBmpButton::~CSpeedBmpButton()
{
}


BEGIN_MESSAGE_MAP(CSpeedBmpButton, CBitmapButton)
	//{{AFX_MSG_MAP(CSpeedBmpButton)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpeedBmpButton message handlers

// ���콺 ���� ��ư ���� �̺�Ʈ�� �������� ��ư Ŭ�� �̺�Ʈ�� �߻�
void CSpeedBmpButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// ��ư�� �������� ���� ���·� ����
	SendMessage(BM_SETSTATE, FALSE, 0);

	CWnd* pParent = GetParent();
	if(NULL != pParent)
	{
		// �������� Ŭ�� �̺�Ʈ �߻�
		::SendMessage(pParent->m_hWnd, WM_COMMAND, MAKEWPARAM(GetDlgCtrlID(), BN_CLICKED), (LPARAM)m_hWnd);
	}
	
	CBitmapButton::OnLButtonUp(nFlags, point);
}

void CSpeedBmpButton::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// ��ư�� ������ ���·� ����
	SendMessage(BM_SETSTATE, TRUE, 0);
	
	CBitmapButton::OnLButtonDblClk(nFlags, point);
}
