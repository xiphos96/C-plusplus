#if !defined(AFX_ANIMGIF_H__68369C47_E3B7_4ACA_AC8F_2F216012034F__INCLUDED_)
#define AFX_ANIMGIF_H__68369C47_E3B7_4ACA_AC8F_2F216012034F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AnimGIF.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAnimGIF window

// CEvent Ŭ���� ����� ���� ��� ����
#include <afxmt.h>
// _beginthreadex() �Լ� ����� ���� ��� ����
#include <process.h>


// �ִϸ��̼� GIF ��¿� Ŭ����
class CAnimGIF : public CStatic
{
// Construction
public:
	CAnimGIF();

// Attributes
public:
	Image					*m_pGIFImage;			// �ִϸ��̼� GIF ��¿� �̹��� Ŭ����
	HGLOBAL					m_hImageData;			// �ε�� �ִϸ��̼� GIF ������

	UINT					m_nFrameSize;			// �ִϸ��̼��� ������ ��
	UINT					m_nCurFrame;			// ���� ��� ������ ��ȣ
	PropertyItem			*m_pProperty;			// ������ ���� �ð� ����
	GUID					*m_pDimensionID;		// �ִϸ��̼� ���� ID

	HANDLE					m_hAnimationThread;		// �ִϸ��̼� ������ �ڵ�
	CEvent					m_RunEvent;				// ������ ���� �̺�Ʈ ��ü
	CEvent					m_ExitEvent;			// ������ ����� �̺�Ʈ ��ü

// Operations
public:
	// �ִϸ��̼� GIF ������ �ε��ϴ� �Լ�
	BOOL LoadGIF(LPCTSTR pFileName);
	// �ִϸ��̼� GIF ���ҽ��� �ε��ϴ� �Լ�
	BOOL LoadGIF(UINT nResourceID, LPCTSTR pResourceType);

	// �ε�� �����ͷκ��� �̹��� ��ü�� �����ϴ� �Լ�
	BOOL LoadGIFFromMemory(LPCTSTR pBuffer, int nSize);

	// �ִϸ��̼��� �����ϴ� �Լ�
	BOOL Play();
	// �ִϸ��̼��� �Ͻ������ϴ� �Լ�
	BOOL Pause();
	// �Ͻ������� �ִϸ��̼��� �ٽ� �����ϴ� �Լ�
	BOOL Resume();

	// �ִϸ��̼� ��¿� ������ �Լ�
	static UINT WINAPI AnimationProc(LPVOID pParam);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnimGIF)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAnimGIF();

	// Generated message map functions
protected:
	//{{AFX_MSG(CAnimGIF)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIMGIF_H__68369C47_E3B7_4ACA_AC8F_2F216012034F__INCLUDED_)
