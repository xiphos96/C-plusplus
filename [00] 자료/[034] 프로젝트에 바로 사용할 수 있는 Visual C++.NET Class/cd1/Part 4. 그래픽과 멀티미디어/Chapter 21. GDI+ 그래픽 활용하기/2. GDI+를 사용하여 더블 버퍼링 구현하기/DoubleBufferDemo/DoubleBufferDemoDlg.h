// DoubleBufferDemoDlg.h : ��� ����
//

#pragma once


// CDoubleBufferDemoDlg ��ȭ ����
class CDoubleBufferDemoDlg : public CDialog
{
// ����
public:
	CDoubleBufferDemoDlg(CWnd* pParent = NULL);	// ǥ�� ������

	CRect		m_rcClient;			// ���̾�α� Ŭ���̾�Ʈ ����
	CString		m_strMessage;		// ��� �޽��� �ؽ�Ʈ
	CSize		m_TextSize;			// �ؽ�Ʈ ��¿� �ʿ��� ũ��
	int			m_nCurPos;			// ���� �ؽ�Ʈ ��� ��ġ

// ��ȭ ���� ������
	//{{AFX_DATA(CDoubleBufferDemoDlg)
	enum { IDD = IDD_DOUBLEBUFFERDEMO_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CDoubleBufferDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����
	//}}AFX_VIRTUAL


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	//{{AFX_MSG(CDoubleBufferDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
