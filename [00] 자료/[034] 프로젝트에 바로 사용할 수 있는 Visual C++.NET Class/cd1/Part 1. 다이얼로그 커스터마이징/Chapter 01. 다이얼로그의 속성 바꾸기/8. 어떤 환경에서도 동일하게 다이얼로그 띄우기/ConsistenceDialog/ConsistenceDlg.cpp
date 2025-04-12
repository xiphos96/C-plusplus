// ConsistenceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "consistencedialog.h"
#include "ConsistenceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConsistenceDlg dialog

// ȭ�� �ػ� 96 DPI������ ���� 9����Ʈ ��Ʈ ũ��
#define BASE_HORZ_UNIT		7				// ���� �ȼ� ũ��
#define BASE_VERT_UNIT		12				// ���� �ȼ� ũ��

// �ڽ� ������鿡 ���� ũ�� ���� ��Ʈ ����ü
struct SResizeHint 
{ 
	CWnd *pParent;							// ���̾�α׿� ���� ������ ������
	CFont *pFont;							// ���� ��Ʈ ������
	int nHorz;								// ���� ���̾�α� ��Ʈ�� ��� ��
	int nVert;								// ���� ���̾�α� ��Ʈ�� ����
}; 


CConsistenceDlg::CConsistenceDlg(UINT nResourceID, CWnd* pParent /*=NULL*/)
	: CDialog(nResourceID, pParent)
{
	//{{AFX_DATA_INIT(CConsistenceDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	// ���� ��Ʈ�� �����Ѵ�
	// ���� ��Ʈ�� ���� 9����Ʈ ��Ʈ�̴�
	HDC hDC = ::GetDC(NULL);
	m_BaseFont.CreateFont(-MulDiv(9, ::GetDeviceCaps(hDC, LOGPIXELSX), 72), 0, 0, 0, 0, 0, 0, 0,
		DEFAULT_CHARSET, 0, 0, 0, 0, _T("����"));
	::ReleaseDC(NULL, hDC);
}


void CConsistenceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConsistenceDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConsistenceDlg, CDialog)
	//{{AFX_MSG_MAP(CConsistenceDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConsistenceDlg message handlers

// �ڽ� ��������� ũ��� ��ġ�� �����ϴ� �Լ�
BOOL CALLBACK EnumChildProc(HWND hWndChild, LPARAM lParam) 
{ 
	SResizeHint *pHint = (SResizeHint*)lParam; 
	CRect rcItem; 

	CWnd wndChild;
	wndChild.Attach(hWndChild);

	// �ڽ� �������� Ŭ���̾�Ʈ ���������� ��ġ�� ũ�⸦ ��´�
	wndChild.GetWindowRect(&rcItem);
	pHint->pParent->ScreenToClient(&rcItem); 

	// ��Ʈ ���뿡 ���� ��ǥ�� ũ�⸦ �����Ѵ�
	rcItem.left = (4 * rcItem.left + 2) / pHint->nHorz;
	rcItem.left = (rcItem.left * BASE_HORZ_UNIT + 2) / 4;

	rcItem.top = (8 * rcItem.top + 4) / pHint->nVert;
	rcItem.top = (rcItem.top * BASE_VERT_UNIT + 4) / 8;

	rcItem.right = (4 * rcItem.right + 2) / pHint->nHorz;
	rcItem.right = (rcItem.right * BASE_HORZ_UNIT + 2) / 4;

	rcItem.bottom = (8 * rcItem.bottom + 4) / pHint->nVert;
	rcItem.bottom = (rcItem.bottom * BASE_VERT_UNIT + 4) / 8;

	// �ڽ� �������� ��ġ�� ũ�⸦ �����ϰ� ��Ʈ�� ���� ��Ʈ�� �����Ѵ�
	wndChild.MoveWindow(&rcItem, TRUE); 
	wndChild.SetFont(pHint->pFont);

	wndChild.Detach();

	return TRUE; 
} 

BOOL CConsistenceDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// ���� ���̾�α��� ���� ��Ʈ�� ����,
	// ���� ���̾�α��� DLU�� ���� ����/���� �ȼ� ũ�⸦ ���Ѵ�
	CDC *pDC = GetDC();
	CFont *pFont = GetFont();
	CFont *pFontOld = pDC->SelectObject(pFont);

	CSize size;
	GetTextExtentPoint(pDC->GetSafeHdc(),
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",
		52, &size);

	int nHorz = (size.cx / 26 + 1) / 2;		// ���� ���̾�α� ��Ʈ�� ��� ��
	int nVert = size.cy;					// ���� ���̾�α� ��Ʈ�� ����

	pDC->SelectObject(pFontOld);
	ReleaseDC(pDC);

	CRect rcWindow, rcClient; 
	int nWidth, nHeight; 
	int nFrameHorz, nFrameVert; 

	GetWindowRect(&rcWindow); 
	GetClientRect(&rcClient); 

	// ������ ������ Ŭ���̾�Ʈ ������ ���̰��� ����Ͽ� �������� ����/���� �β��� ���Ѵ�
	nFrameHorz = rcWindow.Width() - rcClient.Width(); 
	nFrameVert = rcWindow.Height() - rcClient.Height(); 

	// ���� Ŭ���̾�Ʈ ������ �ȼ� ���� DLU �ȼ� ������ ������,
	// Ŭ���̾�Ʈ�� DLU ���� ũ�⸦ ���Ѵ�
	nWidth = rcClient.Width(); 
	nHeight = rcClient.Height(); 

	nWidth = (4 * nWidth + 2) / nHorz;
	nHeight = (8 * nHeight + 4) / nVert;

	// Ŭ���̾�Ʈ DLU ũ�⸦ 96DPI ���� 9����Ʈ������ DLU �ȼ� ������ ���Ͽ�,
	// 96DPI ���� 9����Ʈ�� ���� Ŭ���̾�Ʈ ũ�⸦ ���Ѵ�
	nWidth = (nWidth * BASE_HORZ_UNIT + 2) / 4;
	nHeight = (nHeight * BASE_VERT_UNIT + 4) / 8;

	// ������ �β��� ���Ѵ�
	nWidth += nFrameHorz;
	nHeight += nFrameVert;

	// ���ο� �ȼ� ũ��� ���̾�α��� ũ�⸦ �����Ѵ�
	SetWindowPos(NULL, 0, 0, nWidth, nHeight, SWP_NOMOVE | SWP_NOZORDER); 

	// ���� ��Ʈ�� ���̾�α׿��� �����Ѵ�
	SetFont(&m_BaseFont);

	// �ڽ� ��������� ũ��� ��ġ�� ���� ������� �����ϵ��� �Ѵ�
	SResizeHint Hint; 
	Hint.pParent = this;
	Hint.pFont = &m_BaseFont;
	Hint.nHorz = nHorz;
	Hint.nVert = nVert;

	EnumChildWindows(m_hWnd, EnumChildProc, (LPARAM)&Hint); 
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
