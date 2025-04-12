// CaptureWindow.cpp : implementation file
//

#include "stdafx.h"
#include "CaptureWindowdemo.h"
#include "CaptureWindow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCaptureWindow

CCaptureWindow::CCaptureWindow()
{
	// ��� �������� ���� �ʱ�ȭ�Ѵ�
	m_bmpSelector.LoadBitmap(IDB_SELECT);
	m_bmpSelectorButton.LoadBitmap(IDB_SELECT_BUTTON);

	m_hSelectorCursor = AfxGetApp()->LoadCursor(IDC_SELECT_CURSOR);
	m_hLastHWND		= NULL;
}

CCaptureWindow::~CCaptureWindow()
{
	// GDI ���ҽ����� �����Ѵ�
	m_bmpSelector.DeleteObject();
	m_bmpSelectorButton.DeleteObject();

	::DeleteObject(m_hSelectorCursor);

	if(m_bmpCapture.m_hObject)	m_bmpCapture.DeleteObject();
}


BEGIN_MESSAGE_MAP(CCaptureWindow, CStatic)
	//{{AFX_MSG_MAP(CCaptureWindow)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCaptureWindow message handlers

void CCaptureWindow::PreSubclassWindow() 
{
	// ����ƽ ��Ʈ���� �޽����� �����ϱ� ���� SS_NOTIFY �Ӽ��� �����Ѵ�
	ModifyStyle(0, SS_NOTIFY);

	// �ʱ� ��Ʈ���� �����Ѵ�
	SetBitmap(m_bmpSelector); 
	
	CStatic::PreSubclassWindow();
}

void CCaptureWindow::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// ������ ���콺�� ��ġ�� �������� �ڵ��� �����ϴ� ������ �ʱ�ȭ�Ѵ�
	m_hLastHWND = NULL;

	// �θ� �����쿡�� ������ ������ ���۵��� �˸���
	CWnd *pParent = GetParent();
	if(pParent)		pParent->SendMessage(WM_SELECT_START, 0, (LPARAM)this);

	// ���ø����̼��� �ּ�ȭ �Ѵ�
	AfxGetMainWnd()->ShowWindow(SW_SHOWMINNOACTIVE);

	// ������ ���� ������ ��Ʈ���� �����Ѵ�
	SetBitmap(m_bmpSelectorButton);

	// ���콺 Ŀ���� ����� �ٲ۴�
	::SetCursor(m_hSelectorCursor);
	// ���콺�� �̺�Ʈ�� ĸ���Ѵ�
	SetCapture();
	
	CStatic::OnLButtonDown(nFlags, point);
}

void CCaptureWindow::OnMouseMove(UINT nFlags, CPoint point) 
{
	// ���� ���콺�� ĸ���ϴ� ���̶��
	if(GetCapture() == this)
	{
		// ���콺�� ��ġ�� �����Ѵ�
		CPoint ptScreen = point;

		// ������ ��ǥ��� �����Ѵ�
		ClientToScreen(&ptScreen);

		// �ش� ��ǥ�� ������ �ڵ��� ���Ѵ�
		HWND hWnd = ::WindowFromPoint(ptScreen);
		if(hWnd)
		{
			// ������ ���콺�� ��ġ�ߴ� �����찡 �ƴ϶��
			if(hWnd != m_hLastHWND)
			{ 
				// ���� �������� �׵θ� ǥ�ø� �����
				if(m_hLastHWND)		InvertWindowEdge(m_hLastHWND);

				// ������ ��ġ�� ������� �����Ѵ�
				m_hLastHWND = hWnd; 

				// �������� �ܰ��� �׵θ��� �׸���
				InvertWindowEdge(m_hLastHWND);
			} 
		}
	}
	
	CStatic::OnMouseMove(nFlags, point);
}

// Ư�� �������� �ܰ��� �׵θ��� �׸��� �Լ�
void CCaptureWindow::InvertWindowEdge(HWND hWnd)
{
	RECT stRect;

	// �ش� �������� ��ġ�� ���Ѵ�
	::GetWindowRect(hWnd, &stRect);

	// �ش� �������� ������ DC�� ���Ѵ�
	HDC hDC = ::GetWindowDC(hWnd);

	// ���� ��� �Ӽ��� �����Ѵ�
	SetROP2(hDC, R2_NOT);

	// �ý����� �׵θ� �β��� 5�� ����� ������ ���� �����Ѵ�
	HPEN hPen = CreatePen(PS_INSIDEFRAME, 5 * GetSystemMetrics(SM_CXBORDER), RGB(0,0,0));

	// ������ ���� �����Ѵ�
	HPEN   hOldPen   = (HPEN)SelectObject(hDC, hPen);
	// ���� �귯���� �����Ѵ�
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, GetStockObject(NULL_BRUSH));

	// �������� �ܰ��� �簢 �׵θ��� ����Ѵ�
	Rectangle(hDC, 0, 0, stRect.right - stRect.left, stRect.bottom - stRect.top);

	// ���� ��ü���� �ǵ�����
	SelectObject(hDC, hOldBrush);
	SelectObject(hDC, hOldPen);

	// DC�� ��ȯ�Ѵ�
	::ReleaseDC(hWnd, hDC);

	// ���� �����Ѵ�
	DeleteObject(hPen);
}

void CCaptureWindow::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// ���� ���콺�� ĸ���ϴ� ���̶��
	if(GetCapture() == this)
	{
		// ���콺 �̺�Ʈ ĸ�縦 �����Ѵ�
		ReleaseCapture(); 

		// ������ ���콺�� ��ġ�ߴ� �������� �׵θ��� �����
		if(m_hLastHWND)		InvertWindowEdge(m_hLastHWND);

		// ������ ���� �� ������ ��Ʈ���� �����Ѵ�
		SetBitmap(m_bmpSelector); 
		
		// �θ� �����쿡�� ������ ������ �������� �˸���
		CWnd *pParent = GetParent();
		if(pParent)		pParent->SendMessage(WM_SELECT_END, 0, (LPARAM)this);

		// ���� ã���� �����찡 ���ٸ� �޽��� �ڽ��� ����Ѵ�
		if(m_hLastHWND == NULL)
		{
			MessageBox("������ �����찡 �����ϴ�.\n\n���� ��ư�� �������� �����츦 �����ϼ���.");
		}
		else
		{
			// ������ ĸ��� ��Ʈ���� �����Ѵ�
			if(m_bmpCapture.m_hObject)
				m_bmpCapture.DeleteObject();

			// ���õ� �������� ������ ���Ѵ�
			CRect rcWindow;
			::GetWindowRect(m_hLastHWND, &rcWindow);

			// ���õ� �������� DC�� ���Ѵ�
			HDC hDC = ::GetWindowDC(m_hLastHWND);
			CDC dc, MemDC;

			// �޸� DC�� �����Ѵ�
			dc.Attach(hDC);
			MemDC.CreateCompatibleDC(&dc);

			// ĸ��Ǵ� ȭ���� ������ ��Ʈ���� �����Ѵ�
			m_bmpCapture.CreateCompatibleBitmap(&dc, rcWindow.Width(), rcWindow.Height());
			CBitmap *pOldBmp = MemDC.SelectObject(&m_bmpCapture);

			// �������� ������ ��Ʈ�ʿ� �����Ѵ�
			MemDC.BitBlt(0, 0, rcWindow.Width(), rcWindow.Height(),
				&dc, 0, 0, SRCCOPY);

			// ���ҼҸ� ��ȯ�Ѵ�
			MemDC.SelectObject(pOldBmp);
			MemDC.DeleteDC();
			dc.Detach();
		}

		m_hLastHWND = NULL; 

		// ���ø����̼��� ũ�⸦ ������� �ǵ�����
		AfxGetMainWnd()->ShowWindow(SW_SHOWNORMAL);

		// �θ� �����쿡�� ĸ�縦 �Ϸ��Ͽ����� �˸���
		if(pParent)
			pParent->SendMessage(WM_CAPTURE_FINISH, (WPARAM)m_hLastHWND, (LPARAM)this);
	}
	
	CStatic::OnLButtonUp(nFlags, point);
}
