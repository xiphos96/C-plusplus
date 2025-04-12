// FlatComboBoxDemoDlg.h : 헤더 파일
//

#pragma once

// 평면 콤보 박스 컨트롤 헤더
#include "FlatComboBox.h"


// CFlatComboBoxDemoDlg 대화 상자
class CFlatComboBoxDemoDlg : public CDialog
{
// 생성
public:
	CFlatComboBoxDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CFlatComboBoxDemoDlg)
	enum { IDD = IDD_FLATCOMBOBOXDEMO_DIALOG };
	CFlatComboBox	m_DropListCombo;
	CFlatComboBox	m_DropDownCombo;
	CFlatComboBox	m_AutoComplete;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFlatComboBoxDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CFlatComboBoxDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDroplistCheck();
	afx_msg void OnDropdownCheck();
	afx_msg void OnAutocompleteCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
