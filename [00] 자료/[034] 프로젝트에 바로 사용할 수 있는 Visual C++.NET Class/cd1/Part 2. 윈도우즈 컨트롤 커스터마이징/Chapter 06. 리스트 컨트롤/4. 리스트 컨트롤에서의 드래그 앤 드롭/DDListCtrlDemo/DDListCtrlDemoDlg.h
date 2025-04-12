// DDListCtrlDemoDlg.h : 헤더 파일
//

#pragma once

// 드래그 앤 드롭 리스트 컨트롤 헤더
#include "DDListCtrl.h"


// CDDListCtrlDemoDlg 대화 상자
class CDDListCtrlDemoDlg : public CDialog
{
// 생성
public:
	CDDListCtrlDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

	// 리스트 컨트롤에 사용할 32*32 크기의 이미지 리스트
	CImageList	m_BigImageList;
	// 리스트 컨트롤에 사용할 16*16 크기의 이미지 리스트
	CImageList	m_SmallImageList;


// 대화 상자 데이터
	//{{AFX_DATA(CDDListCtrlDemoDlg)
	enum { IDD = IDD_DDLISTCTRLDEMO_DIALOG };
	CDDListCtrl	m_TargetList;
	CDDListCtrl	m_AllList;
	int		m_nMode;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CDDListCtrlDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CDDListCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnIconRadio();
	afx_msg void OnSmallIconRadio();
	afx_msg void OnListRadio();
	afx_msg void OnReportRadio();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
