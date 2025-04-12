// MSNNotifyDialogDlg.h : 헤더 파일
//

#pragma once

// 텍스트 색상을 입력 받기 위한 스태틱 컨트롤
#include "ColorStatic.h"

// MSN 메시지 다이얼로그로 이용할 다이얼로그
#include "MsgDlg.h"

// CMSNNotifyDialogDlg 대화 상자
class CMSNNotifyDialogDlg : public CDialog
{
// 생성
public:
	CMSNNotifyDialogDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	//{{AFX_DATA(CMSNNotifyDialogDlg)
	enum { IDD = IDD_MSNNOTIFYDIALOG_DIALOG };
	CColorStatic	m_clrText;					// 메시지 출력 색상 설정 스태틱 컨트롤
	CComboBox	m_FontCombo;					// 메시지 폰트 콤보 박스
	int		m_nFontPoint;						// 메시지 폰트 크기
	CString	m_strMessage;						// 메시지 텍스트
	int		m_nTimeShow;						// 알림 창이 나타나는 간격
	int		m_nTimeUp;							// 알림 창이 출력되는 시간
	int		m_nTimeDown;						// 알림 창이 사라지는 간격
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CMSNNotifyDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원
	//}}AFX_VIRTUAL


// 구현
protected:
	HICON m_hIcon;

	CMsgDlg		m_MsgDlg;						// MSN 메시지 다이얼로그

	// 메시지 맵 함수를 생성했습니다.
	//{{AFX_MSG(CMSNNotifyDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShowMsgButton();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
