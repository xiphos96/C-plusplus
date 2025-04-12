// DDTreeCtrlDemoDlg.h : 헤더 파일
//

#pragma once

// 드래그 앤 드롭 트리 컨트롤 헤더 파일
#include "DDTreeCtrl.h"


// CDDTreeCtrlDemoDlg 대화 상자
class CDDTreeCtrlDemoDlg : public CDialog
{
// 생성
public:
	CDDTreeCtrlDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

	// 트리에 사용할 이미지 리스트
	CImageList		m_TreeImageList;

// 대화 상자 데이터
	//{{AFX_DATA(CDDTreeCtrlDemoDlg)
	enum { IDD = IDD_DDTREECTRLDEMO_DIALOG };
	CDDTreeCtrl	m_TargetTree;
	CDDTreeCtrl	m_AllTree;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CDDTreeCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CDDTreeCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
