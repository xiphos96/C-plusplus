// ControlStatusBarDemoView.cpp : CControlStatusBarDemoView Ŭ������ ����
//

#include "stdafx.h"
#include "ControlStatusBarDemo.h"

#include "ControlStatusBarDemoDoc.h"
#include "ControlStatusBarDemoView.h"

// ������������ m_wndStatusBar�� �����ϱ� ���� ��ũ���
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CControlStatusBarDemoView

IMPLEMENT_DYNCREATE(CControlStatusBarDemoView, CView)

BEGIN_MESSAGE_MAP(CControlStatusBarDemoView, CView)
	//{{AFX_MSG_MAP(CControlStatusBarDemoView)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_STATUS_BUTTON, OnStatusButton)
	ON_COMMAND(ID_STATUS_CHECK, OnStatusCheck)
	ON_UPDATE_COMMAND_UI(ID_STATUS_STATIC, OnUpdateStatic)
	ON_UPDATE_COMMAND_UI(ID_STATUS_PROGRESS, OnUpdateProgress)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CControlStatusBarDemoView ����/�Ҹ�

CControlStatusBarDemoView::CControlStatusBarDemoView()
{
	//{{AFX_DATA_INIT(CControlStatusBarDemoView)
	//}}AFX_DATA_INIT
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CControlStatusBarDemoView::~CControlStatusBarDemoView()
{
}

BOOL CControlStatusBarDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	// Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CControlStatusBarDemoView �׸���

void CControlStatusBarDemoView::OnDraw(CDC* /*pDC*/)
{
	CControlStatusBarDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CControlStatusBarDemoView �μ�

BOOL CControlStatusBarDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CControlStatusBarDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CControlStatusBarDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CControlStatusBarDemoView ����

#ifdef _DEBUG
void CControlStatusBarDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CControlStatusBarDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CControlStatusBarDemoDoc* CControlStatusBarDemoView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CControlStatusBarDemoDoc)));
	return (CControlStatusBarDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CControlStatusBarDemoView �޽��� ó����

// ���¹��� ��ư Ŭ�� �̺�Ʈ �ڵ鷯
void CControlStatusBarDemoView::OnStatusButton() 
{
	// ������������ �����͸� ��´�
	CMainFrame *pMainFrame = (CMainFrame*)GetParentFrame();
	// ������������ ���¹ٿ��� ID_STATUS_EDIT ������ ������ ��´�
	SControlPane *pPane = pMainFrame->GetStatusBar()->GetControlPane((UINT)ID_STATUS_EDIT);

	// ���� ������ ��Ȯ�ϰ� ������ٸ�
	if(pPane)
	{
		CString strTitle;
		
		// ����Ʈ �ڽ��� �Էµ� �ؽ�Ʈ�� ��´�
		pPane->pWnd->GetWindowText(strTitle);
		// ������ �������� �����Ѵ�
		GetDocument()->SetTitle(strTitle);
	}
}

// ���¹��� üũ �ڽ� Ŭ�� �̺�Ʈ �ڵ鷯
void CControlStatusBarDemoView::OnStatusCheck() 
{
	// ������������ �����͸� ��´�
	CMainFrame *pMainFrame = (CMainFrame*)GetParentFrame();
	// ������������ ���¹ٿ��� ID_STATUS_CHECK ������ ������ ��´�
	SControlPane *pPane = pMainFrame->GetStatusBar()->GetControlPane((UINT)ID_STATUS_CHECK);

	// ���� ������ ��Ȯ�ϰ� ������ٸ�
	if(pPane)
	{
		// ������ �����츦 ��ư���� ��ȯ�Ѵ�
		CButton *pButton = (CButton*)pPane->pWnd;

		// ���� üũ ���¸� ������Ų��
		if(pButton->GetCheck() == 0)		pButton->SetCheck(1);
		else								pButton->SetCheck(0);
	}
}

// ���¹��� ����ƽ�� ���� ���� �ڵ鷯
void CControlStatusBarDemoView::OnUpdateStatic(CCmdUI* pCmdUI)
{
	// ���� �ð��� ��´�
	COleDateTime CurTime = COleDateTime::GetCurrentTime();

	// ���� �ð��� ���ڿ��� ��´�
	CString strTime = CurTime.Format("%Y�� %m�� %d�� %H�� %M�� %S��");

	// ������������ �����͸� ��´�
	CMainFrame *pMainFrame = (CMainFrame*)GetParentFrame();
	// ������������ ���¹ٿ��� ID_STATUS_STATIC ������ ������ ��´�
	SControlPane *pPane = pMainFrame->GetStatusBar()->GetControlPane((UINT)ID_STATUS_STATIC);

	// ���� ������ ��Ȯ�ϰ� ������ٸ�
	if(pPane)
	{
		// �ð� ���ڿ��� ����ƽ�� �����Ѵ�
		pPane->pWnd->SetWindowText(strTime);
	}
}

// ���¹��� ���α׷����ٿ� ���� ���� �ڵ鷯
void CControlStatusBarDemoView::OnUpdateProgress(CCmdUI* pCmdUI)
{
	// ���� �ð��� ��´�
	COleDateTime CurTime = COleDateTime::GetCurrentTime();

	// ������������ �����͸� ��´�
	CMainFrame *pMainFrame = (CMainFrame*)GetParentFrame();
	// ������������ ���¹ٿ��� ID_STATUS_PROGRESS ������ ������ ��´�
	SControlPane *pPane = pMainFrame->GetStatusBar()->GetControlPane((UINT)ID_STATUS_PROGRESS);

	// ���� ������ ��Ȯ�ϰ� ������ٸ�
	if(pPane)
	{
		// ������ �����츦 ���α׷����ٷ� ��ȯ�Ѵ�
		CProgressCtrl *pProgress = (CProgressCtrl*)pPane->pWnd;
		// ���α׷������� ������ �����Ѵ�
		pProgress->SetRange(0, 59);
		// ���� �ʸ� ���α׷������� ��ġ�� �����Ѵ�
		pProgress->SetPos(CurTime.GetSecond());
	}
}
