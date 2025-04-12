// MultiEditDemoDlg.h : 헤더 파일
//

#pragma once

// CMultiEdit 사용을 위한 헤더 파일
#include "MultiEdit.h"

// CMultiEditDemoDlg 대화 상자
class CMultiEditDemoDlg : public CDialog
{
// 생성
public:
	CMultiEditDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CMultiEditDemoDlg)
	enum { IDD = IDD_MULTIEDITDEMO_DIALOG };
	CEdit	m_NormalEdit;
	CMultiEdit	m_MultiEdit;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CMultiEditDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CMultiEditDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
