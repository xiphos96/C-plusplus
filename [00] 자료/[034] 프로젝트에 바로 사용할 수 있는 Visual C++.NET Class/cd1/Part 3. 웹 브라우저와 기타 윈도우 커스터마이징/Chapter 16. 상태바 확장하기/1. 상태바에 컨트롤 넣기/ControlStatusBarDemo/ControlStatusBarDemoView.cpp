// ControlStatusBarDemoView.cpp : CControlStatusBarDemoView 클래스의 구현
//

#include "stdafx.h"
#include "ControlStatusBarDemo.h"

#include "ControlStatusBarDemoDoc.h"
#include "ControlStatusBarDemoView.h"

// 메인프레임의 m_wndStatusBar에 접근하기 위해 인크루드
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CControlStatusBarDemoView 생성/소멸

CControlStatusBarDemoView::CControlStatusBarDemoView()
{
	//{{AFX_DATA_INIT(CControlStatusBarDemoView)
	//}}AFX_DATA_INIT
	// TODO: 여기에 생성 코드를 추가합니다.

}

CControlStatusBarDemoView::~CControlStatusBarDemoView()
{
}

BOOL CControlStatusBarDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	// Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CControlStatusBarDemoView 그리기

void CControlStatusBarDemoView::OnDraw(CDC* /*pDC*/)
{
	CControlStatusBarDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CControlStatusBarDemoView 인쇄

BOOL CControlStatusBarDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CControlStatusBarDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CControlStatusBarDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CControlStatusBarDemoView 진단

#ifdef _DEBUG
void CControlStatusBarDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CControlStatusBarDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CControlStatusBarDemoDoc* CControlStatusBarDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CControlStatusBarDemoDoc)));
	return (CControlStatusBarDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CControlStatusBarDemoView 메시지 처리기

// 상태바의 버튼 클릭 이벤트 핸들러
void CControlStatusBarDemoView::OnStatusButton() 
{
	// 메인프레임의 포인터를 얻는다
	CMainFrame *pMainFrame = (CMainFrame*)GetParentFrame();
	// 메인프레임의 상태바에서 ID_STATUS_EDIT 페인의 정보를 얻는다
	SControlPane *pPane = pMainFrame->GetStatusBar()->GetControlPane((UINT)ID_STATUS_EDIT);

	// 페인 정보가 정확하게 얻어졌다면
	if(pPane)
	{
		CString strTitle;
		
		// 에디트 박스에 입력된 텍스트를 얻는다
		pPane->pWnd->GetWindowText(strTitle);
		// 문서의 제목으로 설정한다
		GetDocument()->SetTitle(strTitle);
	}
}

// 상태바의 체크 박스 클릭 이벤트 핸들러
void CControlStatusBarDemoView::OnStatusCheck() 
{
	// 메인프레임의 포인터를 얻는다
	CMainFrame *pMainFrame = (CMainFrame*)GetParentFrame();
	// 메인프레임의 상태바에서 ID_STATUS_CHECK 페인의 정보를 얻는다
	SControlPane *pPane = pMainFrame->GetStatusBar()->GetControlPane((UINT)ID_STATUS_CHECK);

	// 페인 정보가 정확하게 얻어졌다면
	if(pPane)
	{
		// 페인의 윈도우를 버튼으로 변환한다
		CButton *pButton = (CButton*)pPane->pWnd;

		// 현재 체크 상태를 반전시킨다
		if(pButton->GetCheck() == 0)		pButton->SetCheck(1);
		else								pButton->SetCheck(0);
	}
}

// 상태바의 스태틱에 대한 갱신 핸들러
void CControlStatusBarDemoView::OnUpdateStatic(CCmdUI* pCmdUI)
{
	// 현재 시간을 얻는다
	COleDateTime CurTime = COleDateTime::GetCurrentTime();

	// 현재 시간을 문자열로 얻는다
	CString strTime = CurTime.Format("%Y년 %m월 %d일 %H시 %M분 %S초");

	// 메인프레임의 포인터를 얻는다
	CMainFrame *pMainFrame = (CMainFrame*)GetParentFrame();
	// 메인프레임의 상태바에서 ID_STATUS_STATIC 페인의 정보를 얻는다
	SControlPane *pPane = pMainFrame->GetStatusBar()->GetControlPane((UINT)ID_STATUS_STATIC);

	// 페인 정보가 정확하게 얻어졌다면
	if(pPane)
	{
		// 시간 문자열을 스태틱에 설정한다
		pPane->pWnd->SetWindowText(strTime);
	}
}

// 상태바의 프로그래스바에 대한 갱신 핸들러
void CControlStatusBarDemoView::OnUpdateProgress(CCmdUI* pCmdUI)
{
	// 현재 시간을 얻는다
	COleDateTime CurTime = COleDateTime::GetCurrentTime();

	// 메인프레임의 포인터를 얻는다
	CMainFrame *pMainFrame = (CMainFrame*)GetParentFrame();
	// 메인프레임의 상태바에서 ID_STATUS_PROGRESS 페인의 정보를 얻는다
	SControlPane *pPane = pMainFrame->GetStatusBar()->GetControlPane((UINT)ID_STATUS_PROGRESS);

	// 페인 정보가 정확하게 얻어졌다면
	if(pPane)
	{
		// 페인의 윈도우를 프로그래스바로 변환한다
		CProgressCtrl *pProgress = (CProgressCtrl*)pPane->pWnd;
		// 프로그래스바의 범위를 설정한다
		pProgress->SetRange(0, 59);
		// 현재 초를 프로그래스바의 위치로 설정한다
		pProgress->SetPos(CurTime.GetSecond());
	}
}
