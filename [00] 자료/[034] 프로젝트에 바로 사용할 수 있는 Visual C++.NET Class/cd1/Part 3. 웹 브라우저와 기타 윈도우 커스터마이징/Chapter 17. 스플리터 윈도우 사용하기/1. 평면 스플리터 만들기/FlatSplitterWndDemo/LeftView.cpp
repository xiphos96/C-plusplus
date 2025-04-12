// LeftView.cpp : implementation file
//

#include "stdafx.h"
#include "flatsplitterwnddemo.h"
#include "LeftView.h"

// 메인프레임의 헤더 파일
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
	// 초기 스플리터 두께를 설정한다
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
	// 에디트 박스에 입력한 두께를 읽어온다
	UpdateData(TRUE);

	// 메인프레임의 포인터를 얻는다
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();

	// 메인프레임의 수직 스플리터에 새로운 두께를 설정한다
	pMainFrame->m_wndSplitter.SetSplitterThick(m_nCX, m_nCY);
	// 메인프레임의 수평 스플리터에 새로운 두께를 설정한다
	pMainFrame->m_wndSplitterVert.SetSplitterThick(m_nCX, m_nCY);
}
