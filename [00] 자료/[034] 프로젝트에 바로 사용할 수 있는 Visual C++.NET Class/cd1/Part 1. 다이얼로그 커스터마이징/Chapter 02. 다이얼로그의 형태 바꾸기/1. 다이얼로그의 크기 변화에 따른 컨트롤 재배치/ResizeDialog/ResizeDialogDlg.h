// ResizeDialogDlg.h : 헤더 파일
//

#pragma once


// CResizeDialogDlg 대화 상자

// 크기 변화에 따라 자식 윈도우들을 재배치하기 위해 CResizeDlg에서 상속 받는다

#include "ResizeDlg.h"

class CResizeDialogDlg : public CResizeDlg
{
// 생성
public:
	CResizeDialogDlg(CWnd* pParent = NULL);	// 표준 생성자

	// 대화 상자 데이터
	//{{AFX_DATA(CResizeDialogDlg)
	enum { IDD = IDD_RESIZEDIALOG_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CResizeDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CResizeDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
