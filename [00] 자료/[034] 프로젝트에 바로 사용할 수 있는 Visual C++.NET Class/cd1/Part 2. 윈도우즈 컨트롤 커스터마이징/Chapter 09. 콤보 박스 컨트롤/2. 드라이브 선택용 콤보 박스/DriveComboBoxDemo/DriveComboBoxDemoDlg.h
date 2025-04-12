// DriveComboBoxDemoDlg.h : 헤더 파일
//

#pragma once

// 드라이브 콤보 박스 컨트롤 헤더
#include "DriveComboBox.h"


// CDriveComboBoxDemoDlg 대화 상자
class CDriveComboBoxDemoDlg : public CDialog
{
// 생성
public:
	CDriveComboBoxDemoDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CDriveComboBoxDemoDlg)
	enum { IDD = IDD_DRIVECOMBOBOXDEMO_DIALOG };
	CDriveComboBox	m_DriveCombo;
	CString	m_strCount;
	CString	m_strCurDrive;
	int		m_nIcon;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CDriveComboBoxDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CDriveComboBoxDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBigRadio();
	afx_msg void OnSmallRadio();
	afx_msg void OnSelchangeDriveCombo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
