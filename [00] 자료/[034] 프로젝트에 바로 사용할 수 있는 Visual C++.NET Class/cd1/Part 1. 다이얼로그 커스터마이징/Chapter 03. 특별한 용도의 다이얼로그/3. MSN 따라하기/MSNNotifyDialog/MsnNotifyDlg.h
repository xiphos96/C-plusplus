#if !defined(AFX_MSNNOTIFYDLG_H__6D46E770_2E08_4EA0_9224_30EC6C53FBE8__INCLUDED_)
#define AFX_MSNNOTIFYDLG_H__6D46E770_2E08_4EA0_9224_30EC6C53FBE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MsnNotifyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMsnNotifyDlg dialog

// MSN 알림 창의 메시지를 클릭했을 경우 부모 윈도우에게 보낼 메시지
#define WM_NOTIFY_CLICKED		(WM_USER + 1)

// 알림 창이 나타나거나, 보이거나, 사라질 때 사용할 타이머 ID
#define CONST_TIMER_UP			1			// 알림 창 나타남
#define CONST_TIMER_SHOW		2			// 알림 창 보임
#define CONST_TIMER_DOWN		3			// 알림 창 사라짐

#define CONST_INCREMENT			2			// 알림 창의 위치 이동 간격(픽셀)


// MSN 알림 창의 기본 클래스
class CMsnNotifyDlg : public CDialog
{
// Construction
public:
	CMsnNotifyDlg(UINT nResourceID, CWnd* pParent = NULL);   // standard constructor
	virtual ~CMsnNotifyDlg();

// Dialog Data
	//{{AFX_DATA(CMsnNotifyDlg)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	HCURSOR		m_hCursor;					// 메시지 위에서의 마우스 커서
	
	CBitmap		m_bmpBkgnd;					// 알림 창의 배경 이미지
	BITMAP		m_bmpInfo;					// 배경 이미지에 대한 정보

	CFont		m_MessageFont;				// 메시지 출력용 폰트
	CFont		m_HotFont;					// 마우스가 위로 올라갔을 때의 메시지 출력 폰트
	COLORREF	m_clrText;					// 메시지 출력 색상
	CString		m_strMessage;				// 메시지 텍스트
	CRect		m_rcMessage;				// 메시지 출력 영역

 	int			m_nTimeUp;					// 알림 창이 나타나는 간격
	int			m_nTimeShow;				// 알림 창이 보여지는 시간
	int			m_nTimeDown;				// 알림 창이 사라지는 간격

	int			m_nTimerID;					// 현재 동작 중인 타이머 ID
	BOOL		m_bHover;					// 마우스가 현재 알림 창 위에 있는지 여부

	CPoint		m_ptStart;					// 작업표시줄의 위치에 따른 알림 창 좌상단 위치
	CPoint		m_ptEnd;					// 작업표시줄의 위치에 따른 알림 창이 다 보이는 위치
	CSize		m_szTerm;					// 작업표시줄의 위치에 따른 알림 창 이동 간격

	void SetBitmap(UINT nBitmap);			// 배경 이미지 설정 함수
	void SetBitmap(LPCTSTR pFileName);		// 배경 이미지 설정 함수
	void InitPosition();					// 배경 이미지에 따른 영역 설정 함수

	// 메시지 텍스트 리턴/설정 함수
	LPCTSTR GetMessage()					{ return m_strMessage; }
	void SetMessage(LPCTSTR pMessage)		{ m_strMessage = pMessage; }
	// 메시지 텍스트 출력용 색상 리턴/설정 함수
	COLORREF GetTextColor()					{ return m_clrText; }
	void SetTextColor(COLORREF clrText)		{ m_clrText = clrText; }
	// 메시지 텍스트 출력용 폰트 설정 함수
	void SetTextFont(LPCTSTR pFontName, int nPoint);
	// 메시지 출력 영역 리턴/설정 함수
	CRect* GetMessageRect()					{ return &m_rcMessage; }
	void SetMessageRect(CRect *pRect)		{ m_rcMessage.CopyRect(pRect); }

	// 알림 창 출력 시간 간격 설정 함수
	void SetTime(int nUp, int nShow, int nDown)
	{
		m_nTimeUp	= nUp;
		m_nTimeShow	= nShow;
		m_nTimeDown	= nDown;
	}

	void Show();							// 알림 창 출력 함수
	void Hide();							// 알림 창 감추는 함수

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMsnNotifyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMsnNotifyDlg)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseHover(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSNNOTIFYDLG_H__6D46E770_2E08_4EA0_9224_30EC6C53FBE8__INCLUDED_)
