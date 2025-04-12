// DialogSplitterWnd.cpp : implementation file
//

#include "stdafx.h"
#include "dialogsplitterwnddemo.h"
#include "DialogSplitterWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogSplitterWnd

// ���ø��Ϳ� ��Ʈ��, ���̾�α��� �� ������ ����
#define CONST_SPLITTER_MARGIN	3


CDialogSplitterWnd::CDialogSplitterWnd()
{
	// ��� �������� ���� �ʱ�ȭ�Ѵ�
	m_nDirection	= DIR_HORZ;
	m_bCapture		= FALSE;

	m_nLeftRange	= -1;
	m_nRightRange	= -1;

	m_clrSplitter	= ::GetSysColor(COLOR_3DFACE);

	m_hHorzCursor	= NULL;
	m_hVertCursor	= NULL;
}

CDialogSplitterWnd::~CDialogSplitterWnd()
{
	int i, nSize;
	SControlInfo *pControl;

	// ���ø��� ���� Ȥ�� ��� ��Ʈ�ѵ鿡 ���� ���� ����ü�� �����Ѵ�
	nSize = m_LeftControls.GetSize();
	for(i = 0; i < nSize; i++)
	{
		pControl = m_LeftControls.GetAt(i);
		delete pControl;
	}
	m_LeftControls.RemoveAll();

	// �������� ���� Ȥ�� �ϴ� ��Ʈ�ѵ鿡 ���� ���� ����ü�� �����Ѵ�
	nSize = m_RightControls.GetSize();
	for(i = 0; i < nSize; i++)
	{
		pControl = m_RightControls.GetAt(i);
		delete pControl;
	}
	m_RightControls.RemoveAll();

	// ���ø����� Ŀ������ �����Ѵ�
	if(m_hHorzCursor)		::DeleteObject(m_hHorzCursor);
	if(m_hVertCursor)		::DeleteObject(m_hVertCursor);
}


BEGIN_MESSAGE_MAP(CDialogSplitterWnd, CStatic)
	//{{AFX_MSG_MAP(CDialogSplitterWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_SETCURSOR()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogSplitterWnd message handlers

void CDialogSplitterWnd::PreSubclassWindow() 
{
	// ����ƽ ��Ʈ���� �˸� �޽��� �Ӽ��� �����Ѵ�
	ModifyStyle(0, SS_NOTIFY);

	// ���� ���ø��͸� ���� Ŀ���� �ε��Ѵ�
	m_hHorzCursor = ::LoadCursor(NULL, IDC_SIZENS);
	// ���� ���ø��͸� ���� Ŀ���� �ε��Ѵ�
	m_hVertCursor = ::LoadCursor(NULL, IDC_SIZEWE);

	CStatic::PreSubclassWindow();
}

// ���ø����� ������ �����ϴ� �Լ�
void CDialogSplitterWnd::SetDirection(SPLITTER_DIR nDir)
{
	// ������ �����Ѵ�
	m_nDirection = nDir;

	CWnd *pParent = GetParent();

	// ���ø����� ������ ��ǥ�� ���Ѵ�
	CRect rcSplitter;
	GetWindowRect(&rcSplitter);
	// �θ� ���̾�α� ������ ��ǥ�� ��ȯ�Ѵ�
	pParent->ScreenToClient(&rcSplitter);

	// ���� ���� ���ø��Ͷ�� top ��ǥ�� �ʱ� ��ġ�� �����Ѵ�
	if(m_nDirection == DIR_HORZ)	m_nInitPos = rcSplitter.top;
	// ���� ���� ���ø��Ͷ�� left ��ǥ�� �ʱ� ��ġ�� �����Ѵ�
	else							m_nInitPos = rcSplitter.left;
}

// ���ø����� �̵� ������ �����ϴ� �Լ�
void CDialogSplitterWnd::SetRange(int nLeft, int nRight)
{
	// ���ø����� �̵� ���� ������ �����Ѵ�
	m_nLeftRange = nLeft;
	m_nRightRange = nRight;
}

// ���ø��Ϳ� ��Ʈ���� �߰��ϴ� �Լ�
int CDialogSplitterWnd::AddControl(CONTROL_POS nPos, CWnd *pControl, BOOL bStretch)
{
	// �θ� ���̾�α��� �����͸� ��´�
	CWnd *pParent = GetParent();

	// ���ø����� ���̾�α� ���� ��ǥ�� ���Ѵ�
	CRect rcSplitter;
	GetWindowRect(&rcSplitter);
	pParent->ScreenToClient(&rcSplitter);

	// ��Ʈ���� ���̾�α� ���� ��ǥ�� ���Ѵ�
	CRect rcControl;
	pControl->GetWindowRect(&rcControl);
	pParent->ScreenToClient(&rcControl);

	// ���ο� ��Ʈ�� ���� ����ü�� �����Ѵ�
	SControlInfo *pNewControl = new SControlInfo;
	// ��Ʈ���� ������ �����Ϳ� ũ�� �ø� ���θ� �����Ѵ�
	pNewControl->pWnd		= pControl;
	pNewControl->bStretch	= bStretch;

	int nSize; 

	// ���� ���� Ȥ�� ����� ��Ʈ���̶��
	if(nPos == POS_LEFT || nPos == POS_TOP)
	{
		// ���� Ȥ�� ��� ��Ʈ�� �迭�� ��Ʈ�� ������ �߰��Ѵ�
		nSize = m_LeftControls.Add(pNewControl);

		// ���� ���ø��Ͱ� �����̶��
		if(m_nDirection == DIR_HORZ)
		{
			// ��Ʈ���� bottom ��ǥ�� �����Ѵ�
			pNewControl->nPos = rcControl.bottom;

			// ���� ��Ʈ���� ���ø��ͺ��� �Ʒ��� �ִٸ� ��Ʈ���� �����
			if(rcControl.top > rcSplitter.top)			pControl->ShowWindow(SW_HIDE);
			else
				// ���� ��Ʈ���� �Ʒ����� ���ø��͸� �Ѿ��
				if(rcControl.bottom > rcSplitter.top)
				{
					// ��Ʈ���� �Ʒ����� ���ø��͸� ���� �ʵ��� �����Ѵ�
					rcControl.bottom = rcSplitter.top - CONST_SPLITTER_MARGIN;
					pControl->MoveWindow(&rcControl);
				}
		}
		else
		{
			// ���� ���ø��Ͱ� �����̶��
			// ��Ʈ���� right ��ǥ�� �����Ѵ�
			pNewControl->nPos = rcControl.right;

			// ���� ��Ʈ���� ���ø��ͺ��� �����ʿ� �ִٸ� ��Ʈ���� �����
			if(rcControl.left > rcSplitter.left)		pControl->ShowWindow(SW_HIDE);
			else
				// ���� ��Ʈ���� �������� ���ø��͸� �Ѿ��
				if(rcControl.right > rcSplitter.left)
				{
					// ��Ʈ���� �������� ���ø��͸� ���� �ʵ��� �����Ѵ�
					rcControl.right = rcSplitter.left - CONST_SPLITTER_MARGIN;
					pControl->MoveWindow(&rcControl);
				}
		}
	}
	// ���� ���� Ȥ�� �ϴ��� ��Ʈ���̶��
	if(nPos == POS_RIGHT || nPos == POS_BOTTOM)
	{
		// ���� Ȥ�� �ϴ� ��Ʈ�� �迭�� ��Ʈ�� ������ �߰��Ѵ�
		nSize = m_RightControls.Add(pNewControl);

		// ���� ���ø��Ͱ� �����̶��
		if(m_nDirection == DIR_HORZ)
		{
			// ��Ʈ���� top ��ǥ�� �����Ѵ�
			pNewControl->nPos = rcControl.top;

			// ���� ��Ʈ���� ���ø��ͺ��� ���ʿ� �ִٸ� ��Ʈ���� �����
			if(rcControl.bottom < rcSplitter.bottom)	pControl->ShowWindow(SW_HIDE);
			else
				// ���� ��Ʈ���� ���ʸ��� ���ø��͸� �Ѿ��
				if(rcControl.top < rcSplitter.bottom)
				{
					// ��Ʈ���� ���ʸ��� ���ø��͸� ���� �ʵ��� �����Ѵ�
					rcControl.top = rcSplitter.bottom + CONST_SPLITTER_MARGIN;
					pControl->MoveWindow(&rcControl);
				}
		}
		else
		{
			// ���� ���ø��Ͱ� �����̶��
			// ��Ʈ���� left ��ǥ�� �����Ѵ�
			pNewControl->nPos = rcControl.left;

			// ���� ��Ʈ���� ���ø��ͺ��� ���ʿ� �ִٸ� ��Ʈ���� �����
			if(rcControl.right < rcSplitter.right)		pControl->ShowWindow(SW_HIDE);
			else
				// ���� ��Ʈ���� ���ʸ��� ���ø��͸� �Ѿ��
				if(rcControl.left < rcSplitter.right)
				{
					// ��Ʈ���� ���ʸ��� ���ø��͸� ���� �ʵ��� �����Ѵ�
					rcControl.left = rcSplitter.right + CONST_SPLITTER_MARGIN;
					pControl->MoveWindow(&rcControl);
				}
		}
	}

	return nSize;
}

void CDialogSplitterWnd::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// ���ø����� Ŭ���̾�Ʈ ������ ���Ѵ�
	CRect rcSplitter;
	GetClientRect(&rcSplitter);

	// Ŭ���̾�Ʈ�� �������� ĥ�Ѵ�
	dc.FillSolidRect(rcSplitter, m_clrSplitter);

	// ���ø����� �ܰ��� ��ư ��� �׵θ��� ����Ѵ�
	dc.DrawEdge(rcSplitter, EDGE_RAISED, BF_RECT);
}

BOOL CDialogSplitterWnd::OnEraseBkgnd(CDC* pDC) 
{
	// ���ø����� ����� ������ �ʴ´�
	return TRUE;
//	return CStatic::OnEraseBkgnd(pDC);
}

void CDialogSplitterWnd::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// ���콺 �̺�Ʈ�� ĸ���Ѵ�
	SetCapture();
	m_bCapture = TRUE;
	
	CStatic::OnLButtonDown(nFlags, point);
}

void CDialogSplitterWnd::OnMouseMove(UINT nFlags, CPoint point) 
{
	//���� ���콺 ���� ��ư�� ���� ���·� �̵��̰� ���콺 �̺�Ʈ�� ĸ���ϰ� �ִٸ�
	if(m_bCapture && nFlags == MK_LBUTTON)
	{
		CPoint ptCursor = point;
		CWnd *pParent = GetParent();

		// �θ� ���̾�α��� Ŭ���̾�Ʈ ������ ���Ѵ�
		CRect rcParent;
		pParent->GetClientRect(&rcParent);

		// ���� Ŀ�� ��ġ�� ���̾�α� ���� ��ǥ�� ��ȯ�Ѵ�
		ClientToScreen(&ptCursor);
		pParent->ScreenToClient(&ptCursor);

		// ���ø����� ��ǥ�� ��� ���̾�α� ���� ��ǥ�� ��ȯ�Ѵ�
		CRect rcSplitter, rcOldSplitter;
		GetWindowRect(&rcSplitter);
		pParent->ScreenToClient(&rcSplitter);
		rcOldSplitter = rcSplitter;

		// ���� ���� ���ø��Ͷ��
		if(m_nDirection == DIR_HORZ)
		{
			// ���ø����� ���̸� ���Ѵ�
			int nHeight = rcSplitter.Height();

			// ���� ���콺 ��ġ�� ���� �߾����� �ϴ� ���ø��� ��ǥ�� ����Ѵ�
			rcSplitter.top = ptCursor.y - (nHeight / 2);
			rcSplitter.bottom = rcSplitter.top + nHeight;

			// ���� ��� �̵� ������ �����Ǿ� �ִٸ�
			if(m_nLeftRange >= 0)
			{
				// �ʱ� ��ġ���� �̵� ������ �ʰ��Ͽ����� �˻��Ѵ�
				if(m_nInitPos - m_nLeftRange > rcSplitter.top)
				{
					// �̵� ���� ��ŭ�� ��ǥ�� �����Ѵ�
					rcSplitter.top = m_nInitPos - m_nLeftRange;
					rcSplitter.bottom = rcSplitter.top + nHeight;
				}
			}
			// ���� �ϴ� �̵� ������ �����Ǿ� �ִٸ�
			if(m_nRightRange >= 0)
			{
				// �ʱ� ��ġ���� �̵� ������ �ʰ��Ͽ����� �˻��Ѵ�
				if(m_nInitPos + m_nRightRange < rcSplitter.top)
				{
					// �̵� ���� ��ŭ�� ��ǥ�� �����Ѵ�
					rcSplitter.top = m_nInitPos + m_nRightRange;
					rcSplitter.bottom = rcSplitter.top + nHeight;
				}
			}

			// ���� ���̾�α��� ���� ���� ���ø��Ͱ� �Ѿ��
			if(rcParent.top + CONST_SPLITTER_MARGIN > rcSplitter.top)
			{
				// ���̾�α��� ��� ������� ��ǥ�� �����Ѵ�
				rcSplitter.top = rcParent.top + CONST_SPLITTER_MARGIN;
				rcSplitter.bottom = rcSplitter.top + nHeight;
			}
			// ���� ���̾�α��� �Ʒ��� ���� ���ø��Ͱ� �Ѿ��
			if(rcParent.bottom - CONST_SPLITTER_MARGIN < rcSplitter.bottom)
			{
				// ���̾�α��� �ϴ� ������� ��ǥ�� �����Ѵ�
				rcSplitter.bottom = rcParent.bottom - CONST_SPLITTER_MARGIN;
				rcSplitter.top = rcSplitter.bottom - nHeight;
			}
		}
		else
		{
			// ���� ���� ���ø��Ͷ�� ���ø����� ���� ���Ѵ�
			int nWidth = rcSplitter.Width();

			// ���� ���콺 ��ġ�� ���� �߾����� �ϴ� ���ø��� ��ǥ�� ����Ѵ�
			rcSplitter.left = ptCursor.x - (nWidth / 2);
			rcSplitter.right = rcSplitter.left + nWidth;

			// ���� ���� �̵� ������ �����Ǿ� �ִٸ�
			if(m_nLeftRange >= 0)
			{
				// �߱� ��ġ���� �̵� ������ �ʰ��Ͽ����� �˻��Ѵ�
				if(m_nInitPos - m_nLeftRange > rcSplitter.left)
				{
					// �̵� ���� ��ŭ�� ��ǥ�� �����Ѵ�
					rcSplitter.left = m_nInitPos - m_nLeftRange;
					rcSplitter.right = rcSplitter.top + nWidth;
				}
			}
			// ���� ���� �̵� ������ �����Ǿ� �ִٸ�
			if(m_nRightRange >= 0)
			{
				// �ʱ� ��ġ���� �̵� ������ �ʰ��Ͽ����� �˻��Ѵ�
				if(m_nInitPos + m_nRightRange < rcSplitter.left)
				{
					// �̵� ���� ��ŭ�� ��ǥ�� �����Ѵ�
					rcSplitter.left = m_nInitPos + m_nRightRange;
					rcSplitter.right = rcSplitter.left + nWidth;
				}
			}

			// ���� ���̾�α��� ���� ���� ���ø��Ͱ� �Ѿ��
			if(rcParent.left + CONST_SPLITTER_MARGIN > rcSplitter.left)
			{
				// ���̾�α��� ���� ������� ��ǥ�� �����Ѵ�
				rcSplitter.left = rcParent.left + CONST_SPLITTER_MARGIN;
				rcSplitter.right = rcSplitter.left + nWidth;
			}
			// ���� ���̾�α��� ������ ���� ���ø��Ͱ� �Ѿ��
			if(rcParent.right - CONST_SPLITTER_MARGIN < rcSplitter.right)
			{
				// ���̾�α��� ���� ������� ��ǥ�� �����Ѵ�
				rcSplitter.right = rcParent.right - CONST_SPLITTER_MARGIN;
				rcSplitter.left = rcSplitter.right - CONST_SPLITTER_MARGIN;
			}
		}

		if(rcSplitter.EqualRect(&rcOldSplitter))
		{
			CStatic::OnMouseMove(nFlags, point);
			return;
		}

		// ���̾�αװ� ���ŵǴ� ���� �����Ѵ�
		pParent->LockWindowUpdate();

		// ���ø��͸� �̵���Ų��
		MoveWindow(rcSplitter);

		CRect rcControl;
		int i, nSize, nGap;
		SControlInfo *pControl;

		// ��� ���� Ȥ�� ��� ��Ʈ�ѵ鿡 ����
		nSize = m_LeftControls.GetSize();
		for(i = 0; i < nSize; i++)
		{
			// ���� Ȥ�� ��� ��Ʈ�ѿ� ���� ���� ����ü�� ��´�
			pControl = m_LeftControls.GetAt(i);

			// ��Ʈ���� ���̾�α� ���� ��ǥ�� ���Ѵ�
			pControl->pWnd->GetWindowRect(&rcControl);
			pParent->ScreenToClient(&rcControl);

			// ���ø��Ϳ� ��Ʈ�� ������ ������ ���Ѵ�
			if(pControl->bStretch)		nGap = m_nInitPos - pControl->nPos;
			else						nGap = CONST_SPLITTER_MARGIN;

			// ���� ���� ���ø��Ͷ��
			if(m_nDirection == DIR_HORZ)
			{
				// ��Ʈ���� bottom ��ǥ�� �ʱ� bottom ��ǥ�� �����Ѵ�
				rcControl.bottom = pControl->nPos;

				// ���� ��Ʈ���� �Ʒ��� ���� ���ø��͸� �Ѿ�ٸ�
				if(rcControl.bottom + nGap > rcSplitter.top)
				{
					// ���� ��Ʈ���� ���� �鵵 ���ø��͸� �Ѿ�ٸ�
					if(rcControl.top + nGap > rcSplitter.top)
						// ��Ʈ���� �����
						pControl->pWnd->ShowWindow(SW_HIDE);
					else
					{
						// ��Ʈ���� �Ʒ��� ���� ���ø��͸� �Ѿ�� �ʵ��� ��ǥ�� �����Ѵ�
						rcControl.bottom = rcSplitter.top - nGap;
						// ���� �Ʒ��ʸ��� ���ʸ麸�� ���� �ȴٸ� �����Ѵ�
						if(rcControl.bottom < rcControl.top)	rcControl.bottom = rcControl.top;
						// ��Ʈ���� �̵���Ų��
						pControl->pWnd->MoveWindow(&rcControl);
						pControl->pWnd->ShowWindow(SW_SHOW);
					}
				}
				else
				{
					// ���� ��Ʈ���� ũ�Ⱑ �÷��� �� �ִٸ�
					if(pControl->bStretch)
					{
						// ���ø��Ϳ� ��Ʈ�� ������ ������ �ʱ� ���ݺ��� Ŀ���ٸ�
						if(rcControl.bottom + nGap < rcSplitter.top)
						{
							// �ʱ� ������ �����ϵ��� ��Ʈ���� ũ�⸦ �ø���
							rcControl.bottom = rcSplitter.top - nGap;
							pControl->pWnd->MoveWindow(&rcControl);
							pControl->pWnd->ShowWindow(SW_SHOW);
						}
					}
				}
			}
			else
			{
				// ���� ���� ���ø��Ͷ�� ��Ʈ���� right ��ǥ�� �ʱ� right ��ǥ�� �����Ѵ�
				rcControl.right = pControl->nPos;

				// ���� ��Ʈ���� ������ ���� ���ø��͸� �Ѿ�ٸ�
				if(rcControl.right + nGap > rcSplitter.left)
				{
					// ���� ��Ʈ���� ���� �鵵 ���ø��͸� �Ѿ�ٸ�
					if(rcControl.left + nGap > rcSplitter.left)
						// ��Ʈ���� �����
						pControl->pWnd->ShowWindow(SW_HIDE);
					else
					{
						// ��Ʈ���� ������ ���� ���ø��͸� �Ѿ�� �ʵ��� ��ǥ�� �����Ѵ�
						rcControl.right = rcSplitter.left - nGap;
						// ���� �����ʸ��� ���ʸ麸�� ���ʿ� �ִٸ� �����Ѵ�
						if(rcControl.right < rcControl.left)	rcControl.right = rcControl.left;
						// ��Ʈ���� �̵���Ų��
						pControl->pWnd->MoveWindow(&rcControl);
						pControl->pWnd->ShowWindow(SW_SHOW);
					}
				}
				else
				{
					// ���� ��Ʈ���� ũ�Ⱑ �÷��� �� �ִٸ�
					if(pControl->bStretch)
					{
						// ���ø��Ϳ� ��Ʈ�� ������ ������ �ʱ� ���ݺ��� Ŀ���ٸ�
						if(rcControl.right + nGap < rcSplitter.left)
						{
							// �ʱ� ������ �����ϵ��� ��Ʈ���� ũ�⸦ �ø���
							rcControl.right = rcSplitter.left - nGap;
							pControl->pWnd->MoveWindow(&rcControl);
							pControl->pWnd->ShowWindow(SW_SHOW);
						}
					}
				}
			}
		}

		// ��� ���� Ȥ�� �ϴ� ��Ʈ�ѵ鿡 ����
		nSize = m_RightControls.GetSize();
		for(i = 0; i < nSize; i++)
		{
			// ���� Ȥ�� �ϴ� ��Ʈ�ѿ� ���� ���� ����ü�� ��´�
			pControl = m_RightControls.GetAt(i);

			// ��Ʈ���� ���̾�α� ���� ��ǥ�� ���Ѵ�
			pControl->pWnd->GetWindowRect(&rcControl);
			pParent->ScreenToClient(&rcControl);

			// ���ø��Ϳ� ��Ʈ�� ������ ������ ���Ѵ�
			if(pControl->bStretch)		nGap = pControl->nPos - m_nInitPos;
			else						nGap = CONST_SPLITTER_MARGIN;

			// ���� ���� ���ø��Ͷ��
			if(m_nDirection == DIR_HORZ)
			{
				// ��Ʈ���� top ��ǥ�� �ʱ� top ��ǥ�� �����Ѵ�
				rcControl.top = pControl->nPos;

				// ���� ��Ʈ���� ���� ���� ���ø��͸� �Ѿ�ٸ�
				if(rcControl.top - nGap < rcSplitter.bottom)
				{
					// ���� ��Ʈ���� �Ʒ��� �鵵 ���ø��͸� �Ѿ�ٸ�
					if(rcControl.bottom - nGap < rcSplitter.bottom)
						// ��Ʈ���� �����
						pControl->pWnd->ShowWindow(SW_HIDE);
					else
					{
						// ��Ʈ���� ���� ���� ���ø��͸� �Ѿ�� �ʵ��� ��ǥ�� �����Ѵ�
						rcControl.top = rcSplitter.bottom + nGap;
						// ���� ���ʸ��� �Ʒ��ʸ麸�� �Ʒ��� �ȴٸ� �����Ѵ�
						if(rcControl.top > rcControl.bottom)	rcControl.top = rcControl.bottom;
						// ��Ʈ���� �̵���Ų��
						pControl->pWnd->MoveWindow(&rcControl);
						pControl->pWnd->ShowWindow(SW_SHOW);
					}
				}
				else
				{
					// ���� ��Ʈ���� ũ�Ⱑ �÷��� �� �ִٸ�
					if(pControl->bStretch)
					{
						// ���ø��Ϳ� ��Ʈ�� ������ ������ �ʱ� ���ݺ��� Ŀ���ٸ�
						if(rcControl.top - nGap > rcSplitter.top)
						{
							// �ʱ� ������ �����ϵ��� ��Ʈ���� ũ�⸦ �ø���
							rcControl.top = rcSplitter.top + nGap;
							pControl->pWnd->MoveWindow(&rcControl);
							pControl->pWnd->ShowWindow(SW_SHOW);
						}
					}
				}
			}
			else
			{
				// ���� ���� ���ø��Ͷ�� ��Ʈ���� left ��ǥ�� �ʱ� left ��ǥ�� �����Ѵ�
				rcControl.left = pControl->nPos;

				// ���� ��Ʈ���� ���� ���� ���ø��͸� �Ѿ�ٸ�
				if(rcControl.left - nGap < rcSplitter.right)
				{
					// ���� ��Ʈ���� ������ �鵵 ���ø��͸� �Ѿ�ٸ�
					if(rcControl.right - nGap < rcSplitter.right)
						// ��Ʈ���� �����
						pControl->pWnd->ShowWindow(SW_HIDE);
					else
					{
						// ��Ʈ���� ���� ���� ���ø��͸� �Ѿ�� �ʵ��� ��ǥ�� �����Ѵ�
						rcControl.left = rcSplitter.right + nGap;
						// ���� ���ʸ��� �����ʸ麸�� �����ʿ� �ִٸ� �����Ѵ�
						if(rcControl.left > rcControl.right)		rcControl.left = rcControl.right;
						// ��Ʈ���� �̵���Ų��
						pControl->pWnd->MoveWindow(&rcControl);
						pControl->pWnd->ShowWindow(SW_SHOW);
					}
				}
				else
				{
					// ���� ��Ʈ���� ũ�Ⱑ �÷��� �� �ִٸ�
					if(pControl->bStretch)
					{
						// ���ø��Ϳ� ��Ʈ�� ������ ������ �ʱ� ���ݺ��� Ŀ���ٸ�
						if(rcControl.left - nGap > rcSplitter.left)
						{
							// �ʱ� ������ �����ϵ��� ��Ʈ���� ũ�⸦ �ø���
							rcControl.left = rcSplitter.left + nGap;
							pControl->pWnd->MoveWindow(&rcControl);
							pControl->pWnd->ShowWindow(SW_SHOW);
						}
					}
				}
			}
		}

		// ���̾�αװ� ���ŵ� �� �ֵ��� �ϰ� ���� �׸���
		pParent->UnlockWindowUpdate();
		pParent->RedrawWindow(NULL, NULL, 
			RDW_INVALIDATE | RDW_NOERASE | RDW_UPDATENOW | RDW_ALLCHILDREN);
	}
	
	CStatic::OnMouseMove(nFlags, point);
}

void CDialogSplitterWnd::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// ���� ���� ���콺 �̺�Ʈ ĸ�� ���̶�� ĸ�縦 �����
	if(m_bCapture)
	{
		ReleaseCapture();
		m_bCapture = FALSE;
	}
	
	CStatic::OnLButtonUp(nFlags, point);
}

BOOL CDialogSplitterWnd::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// ���ø����� ���⿡ ���� Ŀ���� �����Ѵ�
	if(m_nDirection == DIR_HORZ)	::SetCursor(m_hHorzCursor);
	else							::SetCursor(m_hVertCursor);

	return FALSE;
}

void CDialogSplitterWnd::OnSize(UINT nType, int cx, int cy) 
{
	CStatic::OnSize(nType, cx, cy);

	// ���ø����� ũ�Ⱑ ����Ǿ��� ��� ���ø��͸� �ٽ� �׸���
	Invalidate(FALSE);
}
