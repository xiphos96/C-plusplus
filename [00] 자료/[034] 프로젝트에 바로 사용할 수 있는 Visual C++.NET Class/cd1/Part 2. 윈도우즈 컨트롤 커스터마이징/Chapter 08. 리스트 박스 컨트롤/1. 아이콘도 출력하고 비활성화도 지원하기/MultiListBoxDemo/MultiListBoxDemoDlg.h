// MultiListBoxDemoDlg.h : 헤더 파일
//

#pragma once

// 이미지와 비활성화 지원 리스트 박스 컨트롤 헤더
#include "MultiListBox.h"


// CMultiListBoxDemoDlg 대화 상자
class CMultiListBoxDemoDlg : public CDialog
{
// 생성
public:
	CMultiListBoxDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

	// 리스트 박스에 사용할 이미지 리스트
	CImageList		m_ImageList;

// 대화 상자 데이터
	//{{AFX_DATA(CMultiListBoxDemoDlg)
	enum { IDD = IDD_MULTILISTBOXDEMO_DIALOG };
	CMultiListBox	m_MultiList;
	CString	m_strText;
	int		m_nImage;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CMultiListBoxDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CMultiListBoxDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAddButton();
	afx_msg void OnDblclkMultiList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
