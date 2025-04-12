// FileBrowseButton.cpp : implementation file
//

#include "stdafx.h"
#include "filenameeditdemo.h"
#include "FileBrowseButton.h"

#include "FileNameEdit.h"
#include ".\filebrowsebutton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileBrowseButton

CFileBrowseButton::CFileBrowseButton()
{
	// 펜과 브러쉬 생성
	m_BkgndBrush.CreateSolidBrush(::GetSysColor(COLOR_3DFACE));
	m_LinePen.CreatePen(PS_SOLID, 1, ::GetSysColor(COLOR_3DSHADOW));
}

CFileBrowseButton::~CFileBrowseButton()
{
	// 펜과 브러쉬 소멸
	m_BkgndBrush.DeleteObject();
	m_LinePen.DeleteObject();
}


BEGIN_MESSAGE_MAP(CFileBrowseButton, CButton)
	//{{AFX_MSG_MAP(CFileBrowseButton)
	ON_WM_MOUSEMOVE()
	ON_CONTROL_REFLECT(BN_CLICKED, OnBnClicked)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileBrowseButton message handlers

// 버튼 그리기
void CFileBrowseButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);

	// 만약 버튼이 눌려진 상태면
	if(lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		// 브러쉬와 펜을 사용해 평면 모양을 출력한다
		CBrush *pOldBrush;
		CPen *pOldPen;

		pOldBrush = dc.SelectObject(&m_BkgndBrush);
		pOldPen = dc.SelectObject(&m_LinePen);

		dc.Rectangle(&lpDrawItemStruct->rcItem);

		dc.SelectObject(pOldBrush);
		dc.SelectObject(pOldPen);
	}
	else
	{
		// 활성화 상태에 따라 버튼의 모양을 출력한다
		dc.FillSolidRect(&lpDrawItemStruct->rcItem, ::GetSysColor(COLOR_3DFACE));
		dc.DrawFrameControl(&lpDrawItemStruct->rcItem, DFC_BUTTON,
			lpDrawItemStruct->itemState & ODS_DISABLED ? DFCS_INACTIVE : DFCS_BUTTONPUSH);
	}

	// "..." 텍스트를 출력한다
	dc.SetBkMode(TRANSPARENT);
	if(lpDrawItemStruct->itemState & ODS_DISABLED)
		dc.SetTextColor(GetSysColor(COLOR_GRAYTEXT));
	dc.DrawText("...", 3, &lpDrawItemStruct->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	dc.Detach();
}

void CFileBrowseButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	BOOL bCapture = FALSE, bInButton;

	// 현재 버튼이 마우스 이벤트를 캡춰하고 있는지 확인한다
	if(GetCapture())
		if(GetCapture()->m_hWnd == m_hWnd)	bCapture = TRUE;

	CPoint pt = point;
	ClientToScreen(&pt);
	GetParent()->ScreenToClient(&pt);

	// 마우스가 버튼 영역 안에 있는지 확인한다
	bInButton = ((CFileNameEdit*)GetParent())->m_rcButton.PtInRect(pt);

	// 현재 마우스 이벤트를 캡춰하고 있다면
	if(bCapture)
	{
		// 버튼 영역 밖에 있다면
		if(!bInButton)
		{
			// 마우스 이벤트 캡춰를 멈춘다
			ReleaseCapture();
			// 버튼을 감춘다
			ShowWindow(SW_HIDE);
			// 에디트 컨트롤의 편집 영역을 복원시킨다
			((CFileNameEdit*)GetParent())->RestoreArea();
		}
	}
	else
	{
		// 만약 마우스 이벤트를 캡춰하지 않고
		// 마우스가 버튼 영역 안에 있다면
		if(bInButton)
		{
			// 마우스 이벤트를 캡춰한다
			SetCapture();
		}
	}

	CButton::OnMouseMove(nFlags, point);
}

void CFileBrowseButton::OnBnClicked()
{
	// 마우스 이벤트 캡춰를 멈춘다
	ReleaseCapture();
	// 버튼을 감춘다
	ShowWindow(SW_HIDE);
	// 에디트 컨트롤의 편집 영역을 복원시킨다
	((CFileNameEdit*)GetParent())->RestoreArea();

	// 에디트 컨트롤에게 포커스를 설정한다
	GetParent()->SetFocus();

	// 파일/폴더 선택 대화상자를 출력한다
	((CFileNameEdit*)GetParent())->OnBrowse();
}
