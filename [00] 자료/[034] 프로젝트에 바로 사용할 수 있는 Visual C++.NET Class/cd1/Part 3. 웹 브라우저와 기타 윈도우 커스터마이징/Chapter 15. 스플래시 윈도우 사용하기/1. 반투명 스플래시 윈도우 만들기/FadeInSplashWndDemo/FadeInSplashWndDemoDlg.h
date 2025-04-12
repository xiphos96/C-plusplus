// FadeInSplashWndDemoDlg.h : 헤더 파일
//

#pragma once


// CFadeInSplashWndDemoDlg 대화 상자
class CFadeInSplashWndDemoDlg : public CDialog
{
// 생성
public:
	CFadeInSplashWndDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CFadeInSplashWndDemoDlg)
	enum { IDD = IDD_FADEINSPLASHWNDDEMO_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFadeInSplashWndDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CFadeInSplashWndDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShowButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
