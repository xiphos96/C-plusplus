// HTMLCollector.cpp : implementation file
//

#include "stdafx.h"
#include "htmlcollectordemo.h"
#include "HTMLCollector.h"

// ObjectFromLresult()�� ����ϱ� ���� ��� ����
#include <Oleacc.h>
#include <afxpriv.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHTMLCollector

CHTMLCollector::CHTMLCollector()
{
	// OLE�� �ʱ�ȭ�Ѵ�
	AfxOleInit();

	// ��� �������� ���� �ʱ�ȭ�Ѵ�
	m_bmpFinder.LoadBitmap(IDB_FINDER);
	m_bmpFinderButton.LoadBitmap(IDB_FINDER_BUTTON);

	m_hFinderCursor = AfxGetApp()->LoadCursor(IDC_FINDER_CURSOR);
	m_hLastHWND		= NULL;
}

CHTMLCollector::~CHTMLCollector()
{
	// GDI ���ҽ����� �����Ѵ�
	m_bmpFinder.DeleteObject();
	m_bmpFinderButton.DeleteObject();

	::DeleteObject(m_hFinderCursor);

	// �˻��� �������� �迭�� ���� ����ü���� �����Ѵ�
	int i, nSize = m_IEWndArray.GetSize();
	for(i = 0; i < nSize; i++)
	{
		delete m_IEWndArray.GetAt(i);
	}
	m_IEWndArray.RemoveAll();
}


BEGIN_MESSAGE_MAP(CHTMLCollector, CStatic)
	//{{AFX_MSG_MAP(CHTMLCollector)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHTMLCollector message handlers

void CHTMLCollector::PreSubclassWindow() 
{
	// ����ƽ ��Ʈ���� �޽����� �����ϱ� ���� SS_NOTIFY �Ӽ��� �����Ѵ�
	ModifyStyle(0, SS_NOTIFY);

	// �ʱ� ��Ʈ���� �����Ѵ�
	SetBitmap(m_bmpFinder); 
	
	CStatic::PreSubclassWindow();
}

// �˻��� �������� �߿��� Ư�� ���������� �ҽ��� ȹ���Ͽ� ���� �ϴ� �Լ�
LPCTSTR CHTMLCollector::GetSource(int nIndex)
{
	// �ε��� ��ȣ�� �迭�� ũ�⺸�� ũ�ٸ� ����
	if(nIndex >= m_IEWndArray.GetSize())		return NULL;

	// �ش� ���������� ������ �ڵ��� ����Ͽ� �ҽ��� ȹ���ϰ� �����Ѵ�
	return GetSource(m_IEWndArray.GetAt(nIndex)->hExplorer);
}

// Ư�� ���������� �ҽ��� ȹ���Ͽ� �����ϴ� �Լ�
LPCTSTR CHTMLCollector::GetSource(HWND hWnd)
{
	DWORD lRes;

	// IHTMLDocument2 �������̽��� ��� ���� �޽����� ����Ѵ�
	UINT MSG = ::RegisterWindowMessage("WM_HTML_GETOBJECT");
	// ������������ �޽����� ������
	if(!SendMessageTimeout(hWnd, MSG, 0, 0, SMTO_ABORTIFHUNG, 1000, &lRes))
		return NULL;

	IHTMLDocument2 *pIDocument2;
	HRESULT hr;
	// WM_HTML_GETOBJECT �޽����� ���� ����� IHTMLDocument2 �������̽��� ��´�
	hr = ObjectFromLresult(lRes, IID_IHTMLDocument2, 0, (LPVOID*)&pIDocument2);

	// IHTMLDocument2 �������̽��� ���� ���Ͽ��ٸ� NULL�� �����Ѵ�
	if(FAILED(hr) || pIDocument2 == NULL)		return NULL;

	// �ð��� Ŀ���� �����Ѵ�
	BeginWaitCursor();

	// �ҽ� ���� ������ �ʱ�ȭ�Ѵ�
	m_strSource.Empty();
	// IHTMLDocument2 �������̽��� ���� �ҽ��� ȹ���Ѵ�
	CheckDocument(pIDocument2);

	// IHTMLDocument2 �������̽��� ���� Ƚ���� ���δ�
	pIDocument2->Release();

	// �ð��� Ŀ���� �����Ѵ�
	EndWaitCursor();

	// �ҽ��� �����Ѵ�
	return m_strSource;
}

// ���������� IHTMLDocument2 �������̽��� �ҽ��� ȹ���ϴ� �Լ�
void CHTMLCollector::CheckDocument(IHTMLDocument2 *pIDocument2)
{
	USES_CONVERSION;
	BSTR bstrUrl;
	// �������� �ּҸ� ��´�
	pIDocument2->get_URL(&bstrUrl);

	// �ּҸ� ������ �����Ѵ�
	CString strUrl = OLE2T(bstrUrl);
	::SysFreeString(bstrUrl);

	// �ҽ� ���� ������ �ּҸ� �߰��Ѵ�
	m_strSource += "\r\n\r\n=====================================================\r\n";
	m_strSource += strUrl;
	m_strSource += "\r\n=====================================================\r\n\r\n";

	IHTMLElementCollection *pICol;
	// �������� �����ϴ� ���� ��� ���� �������̽��� ��´�
	pIDocument2->get_all(&pICol);

	long nCount, i;
	VARIANT varIndex;
	IHTMLElement *pIElement;
	IHTMLElement *pIParentElement;
	IDispatch *pIDispatch;
	BSTR bstrHtml;
	HRESULT hr;

	// ���� ����� ������ ��´�
	pICol->get_length(&nCount);

	// ��� ������ҿ� ����
	for(i = 0; i < nCount; i++)
	{
		// �ε����� VARIANT Ÿ������ �����
		varIndex.vt		= VT_I4;
		varIndex.lVal	= i;

		// �ش� �ε����� �׸� ���� IDispatch �������̽��� ��´�
		hr = pICol->item(varIndex, varIndex, &pIDispatch);
		// �����ϸ� ���� ������ҷ� �Ѿ��
		if(FAILED(hr) || pIDispatch == NULL)
			continue;

		// ���� ����� IDispatch �������̽����� IHTMLElement �������̽��� ��´�
		hr = pIDispatch->QueryInterface(IID_IHTMLElement, (void**)&pIElement);
		// �����ϸ� ���� ������ҷ� �Ѿ��
		if(FAILED(hr) || pIElement == NULL)
		{
			pIDispatch->Release();
			continue;
		}

		// ���� ����� �θ� �׸��� �������̽��� ��´�
		hr = pIElement->get_parentElement(&pIParentElement);
		// ���� �����Ͽ��ٸ� ���� ������ҷ� �Ѿ��
		if(SUCCEEDED(hr) && pIParentElement != NULL)
		{
			pIParentElement->Release();
			pIElement->Release();
			pIDispatch->Release();
			continue;
		}

		// ��������� HTML �ҽ��� ��´�
		// �̶� �� ��������� ��� ���� �׸���� �����ϴ� HTML�� �������
		hr = pIElement->get_outerHTML(&bstrHtml);
		// �ҽ� ���� ������ �߰��Ѵ�
		m_strSource += bstrHtml;
		m_strSource += "\r\n";

		::SysFreeString(bstrHtml);

		pIElement->Release();
		pIDispatch->Release();
	}

	// ���� ��� ���� �������̽��� ���� Ƚ���� ���δ�
	pICol->Release();

	// �������� �ִٸ� �������� ���� �ִ� ������ ���� �ҽ��� ȹ���Ѵ�
	IHTMLWindow2 *pIWindow2;
	// ������ �θ� �����쿡 ���� �������̽��� ��´�
	hr = pIDocument2->get_parentWindow(&pIWindow2);

	// ���� �����Ͽ��ٸ�
	if(SUCCEEDED(hr) && pIWindow2)
	{
		IHTMLFramesCollection2 *pIFrameCol;
		// �����찡 ���� �ִ� �����ӿ� ���� ������ ���� �������̽��� ��´�
		hr = pIWindow2->get_frames(&pIFrameCol);
		// ���� �����Ͽ��ٸ�
		if(SUCCEEDED(hr) && pIFrameCol)
		{
			long nFrames;
			VARIANT varFrame;

			IHTMLWindow2 *pIFrameWnd;
			IHTMLDocument2 *pIFrameDoc;

			// �������� ������ ��´�
			pIFrameCol->get_length(&nFrames);

			// ��� �����ӿ� ����
			for(i = 0; i < nFrames; i++)
			{
				// �ε����� VARIANT Ÿ������ �����
				varIndex.vt		= VT_I4;
				varIndex.lVal	= i;

				// �ش� �ε����� �����ӿ� ���� ������ ��´�
				if(FAILED(pIFrameCol->item(&varIndex, &varFrame)))
					// �����ϸ� ���� ���������� �Ѿ��
					continue;

				// �������� ������ �������̽��� ��´�
				hr = varFrame.pdispVal->QueryInterface(IID_IHTMLWindow2, (void**)&pIFrameWnd);
				// �����ϸ� ���� ���������� �Ѿ��
				if(FAILED(hr) || pIFrameWnd == NULL)
				{
					varFrame.pdispVal->Release();
					continue;
				}

				// �������� ���� �������̽��� ��´�
				hr = pIFrameWnd->get_document(&pIFrameDoc);
				// �����ϸ� ���� ���������� �Ѿ��
				if(FAILED(hr) || pIFrameDoc == NULL)
				{
					pIFrameWnd->Release();
					varFrame.pdispVal->Release();
					continue;
				}

				// ���� �������̽��� �ҽ��� ȹ���Ѵ�
				CheckDocument(pIFrameDoc);

				pIFrameDoc->Release();
				pIFrameWnd->Release();
				varFrame.pdispVal->Release();
			}

			// ������ ���� �������̽��� ���� Ƚ���� ���δ�
			pIFrameCol->Release();
		}

		// ������ �������̽��� ���� Ƚ���� ���δ�
		pIWindow2->Release();
	}
}

void CHTMLCollector::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// ������ ���콺�� ��ġ�� �������� �ڵ��� �����ϴ� ������ �ʱ�ȭ�Ѵ�
	m_hLastHWND = NULL;

	// �θ� �����쿡�� �������� ������ ���۵��� �˸���
	CWnd *pParent = GetParent();
	if(pParent)		pParent->SendMessage(WM_IE_FINDER_START, 0, (LPARAM)this);

	// �������� ���� ������ ��Ʈ���� �����Ѵ�
	SetBitmap(m_bmpFinderButton);

	// ���콺 Ŀ���� ����� �ٲ۴�
	::SetCursor(m_hFinderCursor);
	// ���콺�� �̺�Ʈ�� ĸ���Ѵ�
	SetCapture();
	
	CStatic::OnLButtonDown(nFlags, point);
}

void CHTMLCollector::OnMouseMove(UINT nFlags, CPoint point) 
{
	// ���� HTML �ҽ� ȹ�� Ŭ������ ���콺�� ĸ���ϴ� ���̶��
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
			HWND hParent;

			// �ش� �������� �ֻ��� �����츦 ���Ѵ�
			for(hParent = hWnd; hParent != NULL;)
			{
				hWnd = hParent;
				hParent = ::GetParent(hWnd);
			}

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
void CHTMLCollector::InvertWindowEdge(HWND hWnd)
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

// ���õ� �������� ���� �����츦 �˻��Ͽ� ���������� ������ �ڵ��� �����ϱ� ���� ���� ����
HWND	g_hWndExplorer = NULL;

void CHTMLCollector::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// ���� HTML �ҽ� ȹ�� Ŭ������ ���콺�� ĸ���ϴ� ���̶��
	if(GetCapture() == this)
	{
		// ���콺 �̺�Ʈ ĸ�縦 �����Ѵ�
		ReleaseCapture(); 

		// ������ ���콺�� ��ġ�ߴ� �������� �׵θ��� �����
		if(m_hLastHWND)		InvertWindowEdge(m_hLastHWND);

		// �������� ���� �� ������ ��Ʈ���� �����Ѵ�
		SetBitmap(m_bmpFinder); 
		
		// ��ü ��ũ���� �ٽ� �׸���
		::InvalidateRect(NULL, NULL, TRUE);

		// �θ� �����쿡�� �������� ������ �������� �˸���
		CWnd *pParent = GetParent();
		if(pParent)		pParent->SendMessage(WM_IE_FINDER_END, 0, (LPARAM)this);

		// �������� ������ �ڵ��� �ʱ�ȭ�Ѵ�
		g_hWndExplorer = NULL;

		// ���õ� �������� ���� �����쿡�� ���������� ã�´�
		CHTMLCollector::EnumWindowCallBack(m_hLastHWND, NULL);

		m_hLastHWND = NULL; 

		// ���� ã���� ���������� ���ٸ� �޽��� �ڽ��� ����Ѵ�
		if(g_hWndExplorer == NULL)
		{
			MessageBox("������ ���α׷��� ���������� �ƴմϴ�.\n\n���� ��ư�� �������� ���� �÷� ��������.");
		}
		else
		{
			// ã���� �������� �ڵ��� ����Ͽ� �ҽ��� ȹ���Ѵ�
			LPCTSTR pSource = GetSource(g_hWndExplorer);

			// �ҽ��� ȹ������ ���Ͽ��ٸ� �޽��� �ڽ��� ����Ѵ�
			if(pSource == NULL)
			{
				MessageBox("������������ Ȩ������ �ҽ��� ������ ���Ͽ����ϴ�.");
			}
			else
			{
				// �θ� �����쿡�� ������ ���� �� �ҽ��� ȹ���Ͽ����� �˸���
				if(pParent)
					pParent->SendMessage(WM_IE_FINDER_SELECT, (WPARAM)g_hWndExplorer, (LPARAM)this);
			}
		}
	}
	
	CStatic::OnLButtonUp(nFlags, point);
}

// �˻��� �������� �迭�� ����� ���� �������� ������������ �˻��ϴ� �Լ�
int CHTMLCollector::RefreshIEArray()
{
	// �˻��� �������� �迭�� ���� ����ü���� �����Ѵ�
	int i, nSize = m_IEWndArray.GetSize();
	for(i = 0; i < nSize; i++)
	{
		delete m_IEWndArray.GetAt(i);
	}
	m_IEWndArray.RemoveAll();

	// ���� �����ִ� ��� ������鿡 ���� ���������� �˻��Ѵ�
	::EnumWindows(EnumWindowCallBack, (LPARAM)&m_IEWndArray);

	// �˻��� �������� �迭�� ũ�⸦ �����Ѵ�
	return m_IEWndArray.GetSize();
}

// �˻��� �������� �迭�� ũ�⸦ �����ϴ� �Լ�
int CHTMLCollector::GetIEArrayCount()
{
	return m_IEWndArray.GetSize();
}

// �˻��� �������� �迭���� Ư�� �׸��� �����ϴ� �Լ�
SIEWnd* CHTMLCollector::GetIEWnd(int nIndex)
{
	// �ε����� �������� �迭�� ũ�⺸�� ũ�ٸ� NULL�� �����Ѵ�
	if(m_IEWndArray.GetSize() <= nIndex)		return NULL;

	// �ش� �׸��� �������� ���� ����ü�� �����Ѵ�
	return m_IEWndArray.GetAt(nIndex);
}

// ������ �˻��� ȣ��Ǵ� �ݹ� �Լ�
BOOL CALLBACK CHTMLCollector::EnumWindowCallBack(HWND hWnd, LPARAM lParam)
{ 
	// ���ڷ� �Ѿ���� ���� �������� �迭 �����ͷ� ��ȯ�Ѵ�
	CArray<SIEWnd*, SIEWnd*>  *pArray = (CArray<SIEWnd*, SIEWnd*>*)lParam;

	// ã���� �������� ���� ������鿡 ���� ���������� �˻��Ѵ�
	EnumChildWindows(hWnd, EnumWindowCallBack, lParam);

	CString strClassName;

	// ã���� �������� Ŭ���� �̸��� ��´�
	::GetClassName(hWnd, strClassName.GetBuffer(1024), 1024);
	strClassName.ReleaseBuffer();
	strClassName.MakeLower();

	// ���� Ŭ���� �̸��� �ͽ��÷η� �̸��� ���ԵǾ� �ִٸ�
	if(strClassName.Find("explorer_server") >= 0)
	{
		CString strProcessName;
		DWORD nProcessID;
		
		// ã���� �������� ���μ��� ID�� ��´�
		::GetWindowThreadProcessId(hWnd, &nProcessID);
		// ���μ��� ID�� ���� �������� �̸��� ��´�
		strProcessName = CHTMLCollector::GetProcessName(nProcessID);

		// ���� ���� ���� �̸��� �ͽ��÷η��� �ƴ϶�� ����ؼ� ���� �����츦 �˻��Ѵ�
		if(strProcessName.CompareNoCase("iexplore.exe") != 0)		return TRUE;

		// ���� ���ڷ� �Ѿ�� ���� NULL�̶��
		if(pArray == NULL)
		{
			// ���콺�� ������ ���������̹Ƿ� ������ �ڵ��� ���� ������ �����Ѵ�
			g_hWndExplorer = hWnd;
			// ���� �����츦 �˻��Ѵ�
			return TRUE;
		}

		int i;

		// ������ �迭�� ������ �������� �߿� ��ġ�� ���� �ִ��� Ȯ���Ѵ�
		for(i = 0; i < pArray->GetSize(); i++)
		{
			if((HWND)pArray->GetAt(i)->hExplorer == hWnd) break;
		}

		// ���� ������ ���������� ã�� ���Ͽ��ٸ�
		if(i >= pArray->GetSize())
		{
			DWORD lRes;
			// IHTMLDocument2 �������̽��� ��� ���� �޽����� ����Ѵ�
			UINT MSG = ::RegisterWindowMessage("WM_HTML_GETOBJECT");

			// ������������ �޽����� ������
			if(!SendMessageTimeout(hWnd, MSG, 0, 0, SMTO_ABORTIFHUNG, 1000, &lRes))
				return TRUE;

			IHTMLDocument2 *pIDocument;
			HRESULT hr;
			// WM_HTML_GETOBJECT �޽����� ���� ����� IHTMLDocument2 �������̽��� ��´�
			hr = ObjectFromLresult(lRes, IID_IHTMLDocument2, 0, (LPVOID*)&pIDocument);

			// IHTMLDocument2 �������̽��� ���� ���Ͽ��ٸ� ���� �����츦 �˻��Ѵ�
			if(hr != S_OK || pIDocument == NULL)
			{
				return TRUE;
			}

			BSTR bstrUrl, bstrTitle;
			// �ش� ���������� �ּҸ� ���Ѵ�
			hr = pIDocument->get_URL(&bstrUrl);
			// �ش� ���������� ������ ���Ѵ�
			hr = pIDocument->get_title(&bstrTitle);

			// ���ο� �������� ���� ����ü�� �����Ѵ�
			SIEWnd *pIEWnd = new SIEWnd;
			// �������� ������ �ڵ��� �����Ѵ�
			pIEWnd->hExplorer	= hWnd;
			// ���������� �ּҸ� �����Ѵ�
			pIEWnd->strAddress	= bstrUrl;
			// ���������� ������ �����Ѵ�
			pIEWnd->strTitle	= bstrTitle;

			// �������� �迭�� �߰��Ѵ�
			pArray->Add(pIEWnd);

			// ���ڿ� ���۸� �����Ѵ�
			::SysFreeString(bstrUrl);
			::SysFreeString(bstrTitle);

			// ������ �������̽� ���� Ƚ���� ���δ�
			pIDocument->Release();
		}
	}

	return TRUE;
}  

// Ư�� ���μ����� ���� ���� �̸��� �����ϴ� �Լ�
CString CHTMLCollector::GetProcessName(DWORD pid)
{
	// PSAPI.DLL���� �����ϴ� �Լ��鿡 ���� Ÿ���� �����Ѵ�
	typedef DWORD (WINAPI *PEnumProcessModules)(HANDLE, HMODULE*, UINT, DWORD*);
	typedef DWORD (WINAPI *PGetModuleBaseName)(HANDLE, HMODULE, LPTSTR, UINT);
	
	CString strFileName;

	// PSAPI.DLL�� �ε��Ѵ�
	HINSTANCE hPsApi = ::LoadLibrary("PSAPI.DLL");
	// ���� DLL�� �ε����� ���Ͽ��ٸ� ����
	if(hPsApi == NULL)		return strFileName;
	
	// ���μ����� ��⿡ ���� ������ ��� �Լ��� �����͸� ��´�
	PEnumProcessModules EnumProcessModules = (PEnumProcessModules)::GetProcAddress(hPsApi, "EnumProcessModules");
	// ����� ���� �̸��� ��� �Լ��� �����͸� ��´�
	PGetModuleBaseName GetModuleBaseName = (PGetModuleBaseName)::GetProcAddress(hPsApi, "GetModuleBaseNameA");
	// ���� �Լ� �����͸� ���� ���Ͽ��ٸ� ����
	if(EnumProcessModules == NULL || GetModuleBaseName == NULL)		return strFileName;
	
	// ���μ��� ID�� ����Ͽ� ���μ����� ���� �ڵ��� ���Ѵ�
	HANDLE hProcess = ::OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);

	// ���μ��� �ڵ��� �������ٸ�
	if(hProcess)
	{
		HMODULE hModule;
		DWORD nNeeded;

		// ����� �ڵ��� ���Ѵ�
		if(EnumProcessModules(hProcess, &hModule, sizeof(hModule), &nNeeded))
		{
			// ��� �ڵ��� ����Ͽ� ���� ���� �̸��� ��´�
			GetModuleBaseName(hProcess, hModule, strFileName.GetBuffer(MAX_PATH), MAX_PATH);
			strFileName.ReleaseBuffer();
		}
	}
	// ���μ����� �ݴ´�
	CloseHandle(hProcess);
	// DLL�� �ݴ´�
	::FreeLibrary(hPsApi);

	// ���� ���� �̸��� �����Ѵ�
	return strFileName;
}
