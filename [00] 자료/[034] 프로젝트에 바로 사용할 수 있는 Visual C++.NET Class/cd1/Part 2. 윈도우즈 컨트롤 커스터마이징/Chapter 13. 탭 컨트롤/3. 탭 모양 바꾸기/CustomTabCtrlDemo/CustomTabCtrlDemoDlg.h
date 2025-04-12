// CustomTabCtrlDemoDlg.h : 헤더 파일
//

#pragma once

// 사용자 정의 탭 컨트롤 헤더
#include "CustomTabCtrl.h"


// CCustomTabCtrlDemoDlg 대화 상자
class CCustomTabCtrlDemoDlg : public CDialog
{
// 생성
public:
	CCustomTabCtrlDemoDlg(CWnd* pParent = NULL);	// 표준 생성자
	virtual ~CCustomTabCtrlDemoDlg();

// 대화 상자 데이터
	//{{AFX_DATA(CCustomTabCtrlDemoDlg)
	enum { IDD = IDD_CUSTOMTABCTRLDEMO_DIALOG };
	CCustomTabCtrl	m_CustomTab;
	//}}AFX_DATA

	// 탭 컨트롤에 사용할 이미지 리스트
	CImageList		m_ImageList;

	//{{AFX_VIRTUAL(CCustomTabCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CCustomTabCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
