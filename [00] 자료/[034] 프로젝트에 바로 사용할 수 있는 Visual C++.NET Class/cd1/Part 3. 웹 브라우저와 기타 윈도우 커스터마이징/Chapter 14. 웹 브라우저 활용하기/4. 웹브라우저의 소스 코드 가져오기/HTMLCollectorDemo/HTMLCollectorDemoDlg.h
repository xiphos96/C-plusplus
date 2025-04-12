// HTMLCollectorDemoDlg.h : ��� ����
//

#pragma once

// HTML �ҽ� ȹ�� Ŭ���� ���
#include "HTMLCollector.h"


// CHTMLCollectorDemoDlg ��ȭ ����
class CHTMLCollectorDemoDlg : public CDialog
{
// ����
public:
	CHTMLCollectorDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������
	virtual ~CHTMLCollectorDemoDlg();

// ��ȭ ���� ������
	//{{AFX_DATA(CHTMLCollectorDemoDlg)
	enum { IDD = IDD_HTMLCOLLECTORDEMO_DIALOG };
	CListCtrl	m_IEList;
	CHTMLCollector	m_HTMLCollector;
	CString	m_strSource;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CHTMLCollectorDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL

	// �������� ����Ʈ ��¿� �̹��� ����Ʈ
	CImageList			m_ImageList;


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CHTMLCollectorDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRefreshButton();
	afx_msg void OnSaveButton();
	afx_msg void OnDblclkIeList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	afx_msg LRESULT OnIEFinderStart(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnIEFinderEnd(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnIEFinderSelect(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
