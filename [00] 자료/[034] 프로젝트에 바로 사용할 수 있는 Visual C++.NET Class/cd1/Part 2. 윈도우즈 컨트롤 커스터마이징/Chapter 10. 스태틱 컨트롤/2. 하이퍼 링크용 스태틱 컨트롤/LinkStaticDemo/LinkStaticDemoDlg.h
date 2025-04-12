// LinkStaticDemoDlg.h : 헤더 파일
//

#pragma once

// 하이퍼 링크 스태틱 컨트롤 헤더
#include "LinkStatic.h"


// CLinkStaticDemoDlg 대화 상자
class CLinkStaticDemoDlg : public CDialog
{
// 생성
public:
	CLinkStaticDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CLinkStaticDemoDlg)
	enum { IDD = IDD_LINKSTATICDEMO_DIALOG };
	CLinkStatic	m_MailStatic;
	CLinkStatic	m_LinkStatic;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CLinkStaticDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CLinkStaticDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
