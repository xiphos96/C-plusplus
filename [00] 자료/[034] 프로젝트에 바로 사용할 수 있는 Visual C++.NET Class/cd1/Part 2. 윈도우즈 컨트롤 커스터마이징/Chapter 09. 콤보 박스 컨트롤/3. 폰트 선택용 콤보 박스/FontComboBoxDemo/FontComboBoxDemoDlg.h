// FontComboBoxDemoDlg.h : 헤더 파일
//

#pragma once

// 폰트 콤보 박스 컨트롤 헤더
#include "FontComboBox.h"


// CFontComboBoxDemoDlg 대화 상자
class CFontComboBoxDemoDlg : public CDialog
{
// 생성
public:
	CFontComboBoxDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CFontComboBoxDemoDlg)
	enum { IDD = IDD_FONTCOMBOBOXDEMO_DIALOG };
	CFontComboBox	m_FontCombo;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFontComboBoxDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CFontComboBoxDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeFontCombo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
