// BitmapDialogDlg.h : 헤더 파일
//

#pragma once

#include "ImageDialog.h"

// CBitmapDialogDlg 대화 상자
class CBitmapDialogDlg : public CImageDialog
{
// 생성
public:
	CBitmapDialogDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CBitmapDialogDlg)
	enum { IDD = IDD_BITMAPDIALOG_DIALOG };
	int		m_nBkgndMode;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CBitmapDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CBitmapDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnModeRadio1();
	afx_msg void OnModeRadio2();
	afx_msg void OnModeRadio3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
