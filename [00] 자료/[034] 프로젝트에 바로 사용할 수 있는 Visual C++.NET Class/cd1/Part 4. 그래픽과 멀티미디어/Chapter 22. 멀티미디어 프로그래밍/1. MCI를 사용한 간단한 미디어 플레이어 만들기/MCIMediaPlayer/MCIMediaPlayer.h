#if !defined(AFX_MCIMEDIAPLAYER_H__05850C33_BD73_477A_BA8B_D26F087B2487__INCLUDED_)
#define AFX_MCIMEDIAPLAYER_H__05850C33_BD73_477A_BA8B_D26F087B2487__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MCIMediaPlayer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMCIMediaPlayer window


// Video for Windows ��� ���� ��ũ���
#include "vfw.h"


// �̵�� ���� ��ȭ�� ���� �˸� �޽���
#define WM_MMP_CHANGE_STATUS		(WM_USER + 500)
// �̵�� ��ġ ��ȭ�� ���� �˸� �޽���
#define WM_MMP_CHANGE_POSITION		(WM_USER + 501)


class CMCIMediaPlayer : public CStatic
{
// Construction
public:
	CMCIMediaPlayer();

// Attributes
public:
	HWND		m_hMCIWnd;			// MCI ������ �ڵ�

	CString		m_strFileName;		// �̵�� ���� ���
	LONG		m_nMediaTime;		// ��ü �̵�� �ð�
	LONG		m_nCurPos;			// ���� ��� ��ġ
	BOOL		m_bSeek;			// ���� ��ġ �̵� ������ ����

// Operations
public:
	// �̵�� ������ �ε��ϴ� �Լ�
	BOOL LoadMedia(LPCTSTR pFileName);
	// �̵�� ������ �ݴ� �Լ�
	BOOL CloseMedia();

	// ��� �Լ�
	void Play();
	// ���� �Լ�
	void Stop();
	// �Ͻ� ���� �Լ�
	void Pause();
	// ����� �Լ�
	void Resume();

	// �̵���� ��ü ��� �ð��� �����ϴ� �Լ�
	LONG GetMediaTime();
	// �̵���� ���� ��� ��ġ�� �����ϴ� �Լ�
	LONG GetCurPos();
	// �̵���� ��� ��ġ�� �ű�� �Լ�
	BOOL SetCurPos(LONG nPos);

	// ���� �ε�� �������� �����ϴ� �Լ�
	BOOL IsLoaded()					{ return (BOOL)m_hMCIWnd; }
	// ���� ��� ���¸� �����ϴ� �Լ�
	LONG GetStatus();

	// ���� ������ �����ϴ� �Լ�
	LONG GetVolume();
	// ������ �����ϴ� �Լ�
	void SetVolume(LONG nVolume);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMCIMediaPlayer)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMCIMediaPlayer();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMCIMediaPlayer)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnNcPaint();
	//}}AFX_MSG
	afx_msg LRESULT OnChangeStatus(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnChangePos(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MCIMEDIAPLAYER_H__05850C33_BD73_477A_BA8B_D26F087B2487__INCLUDED_)
