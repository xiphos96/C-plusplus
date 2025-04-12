// SlidingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "slidingdialog.h"
#include "SlidingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSlidingDlg dialog

// 미닫이 효과를 위한 타이머
#define CONST_SLIDING_TIMER		1
// 미닫이 효과를 위한 타이머 속도
#define CONST_SLIDING_TERM		30


CSlidingDlg::CSlidingDlg(UINT nResourceID, CWnd* pParent /*=NULL*/)
	: CDialog(nResourceID, pParent)
{
	//{{AFX_DATA_INIT(CSlidingDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_bIsShow = FALSE;
}


void CSlidingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSlidingDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSlidingDlg, CDialog)
	//{{AFX_MSG_MAP(CSlidingDlg)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSlidingDlg message handlers

BOOL CSlidingDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// 초기 다이얼로그의 크기를 저장한다
	GetWindowRect(&m_rcWindow);
	m_rcWindow.OffsetRect(m_rcWindow.left * -1, m_rcWindow.top * -1);

	// 초기에는 보이지 않도록 한다
	ShowWindow(SW_HIDE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

// 현재 보이는 상태를 리턴하는 함수
BOOL CSlidingDlg::IsVisible()
{
	return m_bIsShow;
}

// 밀어 열거나 혹은 닫는 함수
BOOL CSlidingDlg::StartSliding()
{
	// 현재 상태를 반전 한다.
	m_bIsShow = !m_bIsShow;
	
	CWnd *pParent = GetParent();
	if(pParent)
	{
		CRect rcParent;
		pParent->GetWindowRect(&rcParent);
		rcParent.top += ::GetSystemMetrics(SM_CYCAPTION);

		// 미닫이 다이얼로그의 초기 위치 값을 설정한다
		if(m_bIsShow)
		{
			m_rcLastPos.right = rcParent.right;
			if(m_rcWindow.Width() > rcParent.Width())
				m_rcLastPos.left = rcParent.left;
			else
				m_rcLastPos.left = m_rcLastPos.right - m_rcWindow.Width();
			m_rcLastPos.top = rcParent.top;
			if(m_rcWindow.Height() > rcParent.Height())
				m_rcLastPos.bottom = rcParent.bottom;
			else
				m_rcLastPos.bottom = m_rcLastPos.top + m_rcWindow.Height();
		}
		else
		{
			GetWindowRect(&m_rcLastPos);
			if(m_rcLastPos.Height() > rcParent.Height())
				m_rcLastPos.bottom = m_rcLastPos.top + rcParent.Height();
		}
	}

	// 미닫이 효과 타이머를 시작한다
	SetTimer(CONST_SLIDING_TIMER, CONST_SLIDING_TERM, NULL);

	return m_bIsShow;
}

void CSlidingDlg::OnTimer(UINT nIDEvent) 
{
	CWnd *pParent = GetParent();
	if(pParent)
	{
		CRect rcParent, rcCurrent;
		UINT nShow = SWP_SHOWWINDOW;

		pParent->GetWindowRect(&rcParent);
		GetWindowRect(&rcCurrent);

		// 여는 중인지 닫는 중인지에 따른 처리
		if(m_bIsShow)
		{
			if(m_rcLastPos.Width() < m_rcWindow.Width())
			{
				m_rcLastPos.right += m_rcWindow.Width() / 20;

				if(m_rcLastPos.Width() > m_rcWindow.Width())
					m_rcLastPos.right = m_rcLastPos.left + m_rcWindow.Width();
			}
			else
			{
				m_rcLastPos.OffsetRect(m_rcWindow.Width() / 20, 0);

				if(m_rcLastPos.left > rcParent.right)
				{
					m_rcLastPos.OffsetRect(rcParent.right - m_rcLastPos.left, 0);
					if(m_rcLastPos.Height() != m_rcWindow.Height())
						m_rcLastPos.bottom = m_rcLastPos.top + m_rcWindow.Height();

					KillTimer(CONST_SLIDING_TIMER);
				}
			}
		}
		else
		{
			m_rcLastPos.OffsetRect(m_rcWindow.Width() / -20, 0);

			if(m_rcLastPos.left < rcParent.left)
				m_rcLastPos.left = rcParent.left;
			if(m_rcLastPos.right <= rcParent.right)
			{
				KillTimer(CONST_SLIDING_TIMER);
				nShow = SWP_HIDEWINDOW;
			}
		}

		SetWindowPos(pParent, m_rcLastPos.left, m_rcLastPos.top,
			m_rcLastPos.Width(), m_rcLastPos.Height(), nShow | SWP_NOOWNERZORDER | SWP_NOACTIVATE);
	}
	else
		KillTimer(CONST_SLIDING_TIMER);
	
	CDialog::OnTimer(nIDEvent);
}
