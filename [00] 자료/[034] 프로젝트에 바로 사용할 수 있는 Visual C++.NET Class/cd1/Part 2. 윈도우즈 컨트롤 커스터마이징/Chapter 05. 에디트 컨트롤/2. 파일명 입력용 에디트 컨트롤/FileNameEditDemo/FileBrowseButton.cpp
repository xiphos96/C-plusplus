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
	// ��� �귯�� ����
	m_BkgndBrush.CreateSolidBrush(::GetSysColor(COLOR_3DFACE));
	m_LinePen.CreatePen(PS_SOLID, 1, ::GetSysColor(COLOR_3DSHADOW));
}

CFileBrowseButton::~CFileBrowseButton()
{
	// ��� �귯�� �Ҹ�
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

// ��ư �׸���
void CFileBrowseButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);

	// ���� ��ư�� ������ ���¸�
	if(lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		// �귯���� ���� ����� ��� ����� ����Ѵ�
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
		// Ȱ��ȭ ���¿� ���� ��ư�� ����� ����Ѵ�
		dc.FillSolidRect(&lpDrawItemStruct->rcItem, ::GetSysColor(COLOR_3DFACE));
		dc.DrawFrameControl(&lpDrawItemStruct->rcItem, DFC_BUTTON,
			lpDrawItemStruct->itemState & ODS_DISABLED ? DFCS_INACTIVE : DFCS_BUTTONPUSH);
	}

	// "..." �ؽ�Ʈ�� ����Ѵ�
	dc.SetBkMode(TRANSPARENT);
	if(lpDrawItemStruct->itemState & ODS_DISABLED)
		dc.SetTextColor(GetSysColor(COLOR_GRAYTEXT));
	dc.DrawText("...", 3, &lpDrawItemStruct->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	dc.Detach();
}

void CFileBrowseButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	BOOL bCapture = FALSE, bInButton;

	// ���� ��ư�� ���콺 �̺�Ʈ�� ĸ���ϰ� �ִ��� Ȯ���Ѵ�
	if(GetCapture())
		if(GetCapture()->m_hWnd == m_hWnd)	bCapture = TRUE;

	CPoint pt = point;
	ClientToScreen(&pt);
	GetParent()->ScreenToClient(&pt);

	// ���콺�� ��ư ���� �ȿ� �ִ��� Ȯ���Ѵ�
	bInButton = ((CFileNameEdit*)GetParent())->m_rcButton.PtInRect(pt);

	// ���� ���콺 �̺�Ʈ�� ĸ���ϰ� �ִٸ�
	if(bCapture)
	{
		// ��ư ���� �ۿ� �ִٸ�
		if(!bInButton)
		{
			// ���콺 �̺�Ʈ ĸ�縦 �����
			ReleaseCapture();
			// ��ư�� �����
			ShowWindow(SW_HIDE);
			// ����Ʈ ��Ʈ���� ���� ������ ������Ų��
			((CFileNameEdit*)GetParent())->RestoreArea();
		}
	}
	else
	{
		// ���� ���콺 �̺�Ʈ�� ĸ������ �ʰ�
		// ���콺�� ��ư ���� �ȿ� �ִٸ�
		if(bInButton)
		{
			// ���콺 �̺�Ʈ�� ĸ���Ѵ�
			SetCapture();
		}
	}

	CButton::OnMouseMove(nFlags, point);
}

void CFileBrowseButton::OnBnClicked()
{
	// ���콺 �̺�Ʈ ĸ�縦 �����
	ReleaseCapture();
	// ��ư�� �����
	ShowWindow(SW_HIDE);
	// ����Ʈ ��Ʈ���� ���� ������ ������Ų��
	((CFileNameEdit*)GetParent())->RestoreArea();

	// ����Ʈ ��Ʈ�ѿ��� ��Ŀ���� �����Ѵ�
	GetParent()->SetFocus();

	// ����/���� ���� ��ȭ���ڸ� ����Ѵ�
	((CFileNameEdit*)GetParent())->OnBrowse();
}
