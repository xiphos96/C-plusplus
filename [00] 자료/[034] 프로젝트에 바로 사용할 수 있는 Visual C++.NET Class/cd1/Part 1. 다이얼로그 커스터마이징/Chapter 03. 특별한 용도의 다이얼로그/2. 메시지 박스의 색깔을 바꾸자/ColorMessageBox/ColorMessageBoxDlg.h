// ColorMessageBoxDlg.h : 헤더 파일
//

#pragma once

// 컬러 출력 및 선택을 위해 사용되는 스태틱 컨트롤
#include "ColorStatic.h"

// CColorMessageBoxDlg 대화 상자
class CColorMessageBoxDlg : public CDialog
{
// 생성
public:
	CColorMessageBoxDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CColorMessageBoxDlg)
	enum { IDD = IDD_COLORMESSAGEBOX_DIALOG };
	CColorStatic	m_clrBkgnd;					// 배경 색상 설정 컨트롤
	CColorStatic	m_clrText;					// 텍스트 색상 설정 컨트롤
	int		m_nUse;								// 컬러를 사용할 것인지 여부
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CColorMessageBoxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CColorMessageBoxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAfxmessageboxButton();
	afx_msg void OnMessageboxButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
