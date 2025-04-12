// DialogSplitterWndDemoDlg.h : 헤더 파일
//

#pragma once


// 다이얼로그용 스플리터 클래스 헤더
#include "DialogSplitterWnd.h"


// CDialogSplitterWndDemoDlg 대화 상자
class CDialogSplitterWndDemoDlg : public CDialog
{
// 생성
public:
	CDialogSplitterWndDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CDialogSplitterWndDemoDlg)
	enum { IDD = IDD_DIALOGSPLITTERWNDDEMO_DIALOG };
	CDialogSplitterWnd	m_wndSplitter2;
	CDialogSplitterWnd	m_wndSplitter;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CDialogSplitterWndDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CDialogSplitterWndDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
