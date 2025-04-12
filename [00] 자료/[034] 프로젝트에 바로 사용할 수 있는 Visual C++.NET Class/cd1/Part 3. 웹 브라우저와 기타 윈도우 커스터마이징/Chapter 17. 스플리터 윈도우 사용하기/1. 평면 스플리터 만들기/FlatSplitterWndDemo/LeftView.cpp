// LeftView.cpp : implementation file
//

#include "stdafx.h"
#include "flatsplitterwnddemo.h"
#include "LeftView.h"

// ������������ ��� ����
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CFormView)

CLeftView::CLeftView()
	: CFormView(CLeftView::IDD)
{
	// �ʱ� ���ø��� �β��� �����Ѵ�
	//{{AFX_DATA_INIT(CLeftView)
	m_nCX = 8;
	m_nCY = 8;
	//}}AFX_DATA_INIT
}

CLeftView::~CLeftView()
{
}

void CLeftView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeftView)
	DDX_Text(pDX, IDC_CX_EDIT, m_nCX);
	DDX_Text(pDX, IDC_CY_EDIT, m_nCY);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLeftView, CFormView)
	//{{AFX_MSG_MAP(CLeftView)
	ON_BN_CLICKED(IDC_CHANGE_BUTTON, OnChangeButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftView diagnostics

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CFormView::AssertValid();
}

void CLeftView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftView message handlers

void CLeftView::OnChangeButton() 
{
	// ����Ʈ �ڽ��� �Է��� �β��� �о�´�
	UpdateData(TRUE);

	// ������������ �����͸� ��´�
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();

	// ������������ ���� ���ø��Ϳ� ���ο� �β��� �����Ѵ�
	pMainFrame->m_wndSplitter.SetSplitterThick(m_nCX, m_nCY);
	// ������������ ���� ���ø��Ϳ� ���ο� �β��� �����Ѵ�
	pMainFrame->m_wndSplitterVert.SetSplitterThick(m_nCX, m_nCY);
}
