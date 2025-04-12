// ProgressBar.cpp : implementation file

	
#include "stdafx.h"
#include "ProgressBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CProgressBar, CProgressCtrl)

BEGIN_MESSAGE_MAP(CProgressBar, CProgressCtrl)
	//{{AFX_MSG_MAP(CProgressBar)
    ON_WM_ERASEBKGND()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

CProgressBar::CProgressBar()
{
	m_Rect.SetRect(0,0,0,0);
}

CProgressBar::CProgressBar(LPCTSTR strMessage, int nSize, int MaxValue)
{
    Create(strMessage, nSize, MaxValue);
}

CProgressBar::~CProgressBar()
{
    Clear();
}

CStatusBar* CProgressBar::GetStatusBar()
{
    CFrameWnd *pFrame = (CFrameWnd*)AfxGetMainWnd();
    if (!pFrame || !pFrame->IsKindOf(RUNTIME_CLASS(CFrameWnd))) 
        return NULL;

    CStatusBar* pBar = (CStatusBar*) pFrame->GetMessageBar();
    if (!pBar || !pBar->IsKindOf(RUNTIME_CLASS(CStatusBar))) 
        return NULL;

    return pBar;
}

BOOL CProgressBar::Create(LPCTSTR strMessage, int nSize, int MaxValue)
{
	// ���¹ٸ� ����
	CStatusBar *pStatusBar = GetStatusBar();
	if (!pStatusBar) return FALSE;

	// ���¹� ���� ���α׷��� ��Ʈ�� ����
	if(!CProgressCtrl::Create(WS_CHILD|WS_VISIBLE, CRect(0,0,0,0),
	pStatusBar, 1)) return FALSE;

	// ���α׷��� ��Ʈ���� ������ ���� ����
	SetRange(0, MaxValue);
	SetStep(1);

	m_strMessage 	= strMessage;
	m_nSize  	= nSize;

	// ��ġ�� ũ�� ����
	Resize();
	return TRUE;
}

void CProgressBar::Clear()
{
    ModifyStyle(WS_VISIBLE, 0);

    CString str;
    str.LoadString(AFX_IDS_IDLEMESSAGE);

    CStatusBar *pStatusBar = GetStatusBar();
    if (pStatusBar) pStatusBar->SetWindowText(str);
}

void CProgressBar::SetText(LPCTSTR strMessage)
{ 
	m_strMessage = strMessage; 
	Resize(); 
}

void CProgressBar::Resize() 
{	
    CStatusBar *pStatusBar = GetStatusBar();
    if (!pStatusBar) return;

    // �ؽ�Ʈ ���
    if (::IsWindow(m_hWnd) && IsWindowVisible()) {
        pStatusBar->SetWindowText(m_strMessage);
        pStatusBar->UpdateWindow();
    }

    // �ؽ�Ʈ�� �����ϴ� ���� ���
    CClientDC dc(pStatusBar);
    CFont *pOldFont = dc.SelectObject(pStatusBar->GetFont());
    CSize size = dc.GetTextExtent(m_strMessage);	
    int margin = dc.GetTextExtent(_T(" ")).cx * 2;
    dc.SelectObject(pOldFont);

    // ���α׷��� ��Ʈ���� �׷��� ���� ���
    CRect rc;
    pStatusBar->GetItemRect (0, rc);
	rc.left = 125;
    //rc.left = size.cx + 2*margin;
    rc.right = rc.left + (rc.right - rc.left);
    if (rc.right < rc.left) rc.right = rc.left;
    
    // ���¹� ���Ϸ� 10%�� ������ ��
    int Height = rc.bottom - rc.top;
    rc.bottom -= Height/10;
    rc.top    += Height/10;

    // ���α׷��� ��Ʈ���� ��ġ�� ũ�⸦ ������
    if (::IsWindow(m_hWnd) && (rc != m_Rect))
        MoveWindow(&rc);
    m_Rect = rc;
}


BOOL CProgressBar::OnEraseBkgnd(CDC* pDC) 
{
    Resize();
    return CProgressCtrl::OnEraseBkgnd(pDC);
}