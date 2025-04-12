// FontEffectDemoDlg.h : ��� ����
//

#pragma once

#include "FontEffect.h"


// CFontEffectDemoDlg ��ȭ ����
class CFontEffectDemoDlg : public CDialog
{
// ����
public:
	CFontEffectDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	//{{AFX_DATA(CFontEffectDemoDlg)
	enum { IDD = IDD_FONTEFFECTDEMO_DIALOG };
	CFontEffect	m_FontEffect;
	CButton	m_btnShape3;
	CButton	m_btnShape2;
	CButton	m_btnShape1;
	BOOL	m_bOutLine;
	int		m_nShapeType;
	CString	m_strText;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CFontEffectDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL

	static void ShapeFunc1(int nSize, CPoint *pPoint, CSize TextSize);
	static void ShapeFunc2(int nSize, CPoint *pPoint, CSize TextSize);
	static void ShapeFunc3(int nSize, CPoint *pPoint, CSize TextSize);


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CFontEffectDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShapeButton1();
	afx_msg void OnShapeButton2();
	afx_msg void OnShapeButton3();
	afx_msg void OnOutlineCheck();
	afx_msg void OnRefreshButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
