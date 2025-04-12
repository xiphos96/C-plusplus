// HTMLCollector.cpp : implementation file
//

#include "stdafx.h"
#include "htmlcollectordemo.h"
#include "HTMLCollector.h"

// ObjectFromLresult()를 사용하기 위한 헤더 파일
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
	// OLE를 초기화한다
	AfxOleInit();

	// 멤버 변수들의 값을 초기화한다
	m_bmpFinder.LoadBitmap(IDB_FINDER);
	m_bmpFinderButton.LoadBitmap(IDB_FINDER_BUTTON);

	m_hFinderCursor = AfxGetApp()->LoadCursor(IDC_FINDER_CURSOR);
	m_hLastHWND		= NULL;
}

CHTMLCollector::~CHTMLCollector()
{
	// GDI 리소스들을 해제한다
	m_bmpFinder.DeleteObject();
	m_bmpFinderButton.DeleteObject();

	::DeleteObject(m_hFinderCursor);

	// 검색된 웹브라우저 배열의 정보 구조체들을 제거한다
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
	// 스태틱 컨트롤의 메시지를 수신하기 위해 SS_NOTIFY 속성을 설정한다
	ModifyStyle(0, SS_NOTIFY);

	// 초기 비트맵을 설정한다
	SetBitmap(m_bmpFinder); 
	
	CStatic::PreSubclassWindow();
}

// 검색된 웹브라우저 중에서 특정 웹브라우저의 소스를 획득하여 리턴 하는 함수
LPCTSTR CHTMLCollector::GetSource(int nIndex)
{
	// 인덱스 번호가 배열의 크기보다 크다면 리턴
	if(nIndex >= m_IEWndArray.GetSize())		return NULL;

	// 해당 웹브라우저의 윈도우 핸들을 사용하여 소스를 획득하고 리턴한다
	return GetSource(m_IEWndArray.GetAt(nIndex)->hExplorer);
}

// 특정 웹브라우저의 소스를 획득하여 리턴하는 함수
LPCTSTR CHTMLCollector::GetSource(HWND hWnd)
{
	DWORD lRes;

	// IHTMLDocument2 인터페이스를 얻기 위한 메시지를 등록한다
	UINT MSG = ::RegisterWindowMessage("WM_HTML_GETOBJECT");
	// 웹브라우저에게 메시지를 보낸다
	if(!SendMessageTimeout(hWnd, MSG, 0, 0, SMTO_ABORTIFHUNG, 1000, &lRes))
		return NULL;

	IHTMLDocument2 *pIDocument2;
	HRESULT hr;
	// WM_HTML_GETOBJECT 메시지를 보낸 결과로 IHTMLDocument2 인터페이스를 얻는다
	hr = ObjectFromLresult(lRes, IID_IHTMLDocument2, 0, (LPVOID*)&pIDocument2);

	// IHTMLDocument2 인터페이스를 얻지 못하였다면 NULL을 리턴한다
	if(FAILED(hr) || pIDocument2 == NULL)		return NULL;

	// 시계모양 커서를 설정한다
	BeginWaitCursor();

	// 소스 저장 변수를 초기화한다
	m_strSource.Empty();
	// IHTMLDocument2 인터페이스를 통해 소스를 획득한다
	CheckDocument(pIDocument2);

	// IHTMLDocument2 인터페이스의 참조 횟수를 줄인다
	pIDocument2->Release();

	// 시계모양 커서를 종료한다
	EndWaitCursor();

	// 소스를 리턴한다
	return m_strSource;
}

// 웹브라우저의 IHTMLDocument2 인터페이스로 소스를 획득하는 함수
void CHTMLCollector::CheckDocument(IHTMLDocument2 *pIDocument2)
{
	USES_CONVERSION;
	BSTR bstrUrl;
	// 웹문서의 주소를 얻는다
	pIDocument2->get_URL(&bstrUrl);

	// 주소를 변수에 저장한다
	CString strUrl = OLE2T(bstrUrl);
	::SysFreeString(bstrUrl);

	// 소스 저장 변수에 주소를 추가한다
	m_strSource += "\r\n\r\n=====================================================\r\n";
	m_strSource += strUrl;
	m_strSource += "\r\n=====================================================\r\n\r\n";

	IHTMLElementCollection *pICol;
	// 웹문서를 구성하는 구성 요소 집합 인터페이스를 얻는다
	pIDocument2->get_all(&pICol);

	long nCount, i;
	VARIANT varIndex;
	IHTMLElement *pIElement;
	IHTMLElement *pIParentElement;
	IDispatch *pIDispatch;
	BSTR bstrHtml;
	HRESULT hr;

	// 구성 요소의 갯수를 얻는다
	pICol->get_length(&nCount);

	// 모든 구성요소에 대해
	for(i = 0; i < nCount; i++)
	{
		// 인덱스를 VARIANT 타입으로 만든다
		varIndex.vt		= VT_I4;
		varIndex.lVal	= i;

		// 해당 인덱스의 항목에 대한 IDispatch 인터페이스를 얻는다
		hr = pICol->item(varIndex, varIndex, &pIDispatch);
		// 실패하면 다음 구성요소로 넘어간다
		if(FAILED(hr) || pIDispatch == NULL)
			continue;

		// 구성 요소의 IDispatch 인터페이스에서 IHTMLElement 인터페이스를 얻는다
		hr = pIDispatch->QueryInterface(IID_IHTMLElement, (void**)&pIElement);
		// 실패하면 다음 구성요소로 넘어간다
		if(FAILED(hr) || pIElement == NULL)
		{
			pIDispatch->Release();
			continue;
		}

		// 구성 요소의 부모 항목의 인터페이스를 얻는다
		hr = pIElement->get_parentElement(&pIParentElement);
		// 만약 성공하였다면 다음 구성요소로 넘어간다
		if(SUCCEEDED(hr) && pIParentElement != NULL)
		{
			pIParentElement->Release();
			pIElement->Release();
			pIDispatch->Release();
			continue;
		}

		// 구성요소의 HTML 소스를 얻는다
		// 이때 이 구성요소의 모든 하위 항목들을 포함하는 HTML이 얻어진다
		hr = pIElement->get_outerHTML(&bstrHtml);
		// 소스 저장 변수에 추가한다
		m_strSource += bstrHtml;
		m_strSource += "\r\n";

		::SysFreeString(bstrHtml);

		pIElement->Release();
		pIDispatch->Release();
	}

	// 구성 요소 집합 인터페이스의 참조 횟수를 줄인다
	pICol->Release();

	// 프레임이 있다면 프레임이 갖고 있는 문서에 대한 소스도 획득한다
	IHTMLWindow2 *pIWindow2;
	// 문서의 부모 윈도우에 대한 인터페이스를 얻는다
	hr = pIDocument2->get_parentWindow(&pIWindow2);

	// 만약 성공하였다면
	if(SUCCEEDED(hr) && pIWindow2)
	{
		IHTMLFramesCollection2 *pIFrameCol;
		// 윈도우가 갖고 있는 프레임에 대한 프레임 집합 인터페이스를 얻는다
		hr = pIWindow2->get_frames(&pIFrameCol);
		// 만약 성공하였다면
		if(SUCCEEDED(hr) && pIFrameCol)
		{
			long nFrames;
			VARIANT varFrame;

			IHTMLWindow2 *pIFrameWnd;
			IHTMLDocument2 *pIFrameDoc;

			// 프레임의 갯수를 얻는다
			pIFrameCol->get_length(&nFrames);

			// 모든 프레임에 대해
			for(i = 0; i < nFrames; i++)
			{
				// 인덱스를 VARIANT 타입으로 만든다
				varIndex.vt		= VT_I4;
				varIndex.lVal	= i;

				// 해당 인덱스의 프레임에 대한 정보를 얻는다
				if(FAILED(pIFrameCol->item(&varIndex, &varFrame)))
					// 실패하면 다음 프레임으로 넘어간다
					continue;

				// 프레임의 윈도우 인터페이스를 얻는다
				hr = varFrame.pdispVal->QueryInterface(IID_IHTMLWindow2, (void**)&pIFrameWnd);
				// 실패하면 다음 프레임으로 넘어간다
				if(FAILED(hr) || pIFrameWnd == NULL)
				{
					varFrame.pdispVal->Release();
					continue;
				}

				// 윈도우의 문서 인터페이스를 얻는다
				hr = pIFrameWnd->get_document(&pIFrameDoc);
				// 실패하면 다음 프레임으로 넘어간다
				if(FAILED(hr) || pIFrameDoc == NULL)
				{
					pIFrameWnd->Release();
					varFrame.pdispVal->Release();
					continue;
				}

				// 문서 인터페이스의 소스를 획득한다
				CheckDocument(pIFrameDoc);

				pIFrameDoc->Release();
				pIFrameWnd->Release();
				varFrame.pdispVal->Release();
			}

			// 프레임 집합 인터페이스의 참조 횟수를 줄인다
			pIFrameCol->Release();
		}

		// 윈도우 인터페이스의 참조 횟수를 줄인다
		pIWindow2->Release();
	}
}

void CHTMLCollector::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// 마지막 마우스가 위치한 윈도우의 핸들을 저장하는 변수를 초기화한다
	m_hLastHWND = NULL;

	// 부모 윈도우에게 웹브라우저 선택이 시작됨을 알린다
	CWnd *pParent = GetParent();
	if(pParent)		pParent->SendMessage(WM_IE_FINDER_START, 0, (LPARAM)this);

	// 웹브라우저 선택 상태의 비트맵을 설정한다
	SetBitmap(m_bmpFinderButton);

	// 마우스 커서의 모양을 바꾼다
	::SetCursor(m_hFinderCursor);
	// 마우스의 이벤트를 캡춰한다
	SetCapture();
	
	CStatic::OnLButtonDown(nFlags, point);
}

void CHTMLCollector::OnMouseMove(UINT nFlags, CPoint point) 
{
	// 현재 HTML 소스 획득 클래스가 마우스를 캡춰하는 중이라면
	if(GetCapture() == this)
	{
		// 마우스의 위치를 저장한다
		CPoint ptScreen = point;

		// 윈도우 좌표계로 변경한다
		ClientToScreen(&ptScreen);

		// 해당 좌표의 윈도우 핸들을 구한다
		HWND hWnd = ::WindowFromPoint(ptScreen);
		if(hWnd)
		{
			HWND hParent;

			// 해당 윈도우의 최상위 윈도우를 구한다
			for(hParent = hWnd; hParent != NULL;)
			{
				hWnd = hParent;
				hParent = ::GetParent(hWnd);
			}

			// 마지막 마우스가 위치했던 윈도우가 아니라면
			if(hWnd != m_hLastHWND)
			{ 
				// 이전 윈도우의 테두리 표시를 지운다
				if(m_hLastHWND)		InvertWindowEdge(m_hLastHWND);

				// 마지막 위치한 윈도우로 저장한다
				m_hLastHWND = hWnd; 

				// 윈도우의 외곽에 테두리를 그린다
				InvertWindowEdge(m_hLastHWND);
			} 
		}
	}
	
	CStatic::OnMouseMove(nFlags, point);
}

// 특정 윈도우의 외곽에 테두리를 그리는 함수
void CHTMLCollector::InvertWindowEdge(HWND hWnd)
{
	RECT stRect;

	// 해당 윈도우의 위치를 구한다
	::GetWindowRect(hWnd, &stRect);

	// 해당 윈도우의 윈도우 DC를 구한다
	HDC hDC = ::GetWindowDC(hWnd);

	// 역상 출력 속성을 설정한다
	SetROP2(hDC, R2_NOT);

	// 시스템의 테두리 두께의 5배 굵기로 검은색 펜을 생성한다
	HPEN hPen = CreatePen(PS_INSIDEFRAME, 5 * GetSystemMetrics(SM_CXBORDER), RGB(0,0,0));

	// 생성한 펜을 설정한다
	HPEN   hOldPen   = (HPEN)SelectObject(hDC, hPen);
	// 투명 브러쉬를 설정한다
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, GetStockObject(NULL_BRUSH));

	// 윈도우의 외곽에 사각 테두리를 출력한다
	Rectangle(hDC, 0, 0, stRect.right - stRect.left, stRect.bottom - stRect.top);

	// 이전 객체들을 되돌린다
	SelectObject(hDC, hOldBrush);
	SelectObject(hDC, hOldPen);

	// DC를 반환한다
	::ReleaseDC(hWnd, hDC);

	// 펜을 제거한다
	DeleteObject(hPen);
}

// 선택된 윈도우의 하위 윈도우를 검색하여 웹브라우저의 윈도우 핸들을 저장하기 위한 전역 변수
HWND	g_hWndExplorer = NULL;

void CHTMLCollector::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// 현재 HTML 소스 획득 클래스가 마우스를 캡춰하는 중이라면
	if(GetCapture() == this)
	{
		// 마우스 이벤트 캡춰를 종료한다
		ReleaseCapture(); 

		// 마지막 마우스가 위치했던 윈도우의 테두리를 지운다
		if(m_hLastHWND)		InvertWindowEdge(m_hLastHWND);

		// 웹브라우저 선택 전 상태의 비트맵을 설정한다
		SetBitmap(m_bmpFinder); 
		
		// 전체 스크린을 다시 그린다
		::InvalidateRect(NULL, NULL, TRUE);

		// 부모 윈도우에게 웹브라우저 선택이 끝났음을 알린다
		CWnd *pParent = GetParent();
		if(pParent)		pParent->SendMessage(WM_IE_FINDER_END, 0, (LPARAM)this);

		// 웹브라우저 윈도우 핸들을 초기화한다
		g_hWndExplorer = NULL;

		// 선택된 윈도우의 하위 윈도우에서 웹브라우저를 찾는다
		CHTMLCollector::EnumWindowCallBack(m_hLastHWND, NULL);

		m_hLastHWND = NULL; 

		// 만약 찾아진 웹브라우저가 없다면 메시지 박스를 출력한다
		if(g_hWndExplorer == NULL)
		{
			MessageBox("선택한 프로그램은 웹브라우저가 아닙니다.\n\n선택 버튼을 웹브라우저 위에 올려 놓으세요.");
		}
		else
		{
			// 찾아진 웹브라우저 핸들을 사용하여 소스를 획득한다
			LPCTSTR pSource = GetSource(g_hWndExplorer);

			// 소스를 획득하지 못하였다면 메시지 박스를 출력한다
			if(pSource == NULL)
			{
				MessageBox("웹브라우저에서 홈페이지 소스를 얻어오지 못하였습니다.");
			}
			else
			{
				// 부모 윈도우에게 웹브라우 선택 후 소스를 획득하였음을 알린다
				if(pParent)
					pParent->SendMessage(WM_IE_FINDER_SELECT, (WPARAM)g_hWndExplorer, (LPARAM)this);
			}
		}
	}
	
	CStatic::OnLButtonUp(nFlags, point);
}

// 검색된 웹브라우저 배열을 지우고 현재 실행중인 웹브라우저들을 검색하는 함수
int CHTMLCollector::RefreshIEArray()
{
	// 검색된 웹브라우저 배열의 정보 구조체들을 제거한다
	int i, nSize = m_IEWndArray.GetSize();
	for(i = 0; i < nSize; i++)
	{
		delete m_IEWndArray.GetAt(i);
	}
	m_IEWndArray.RemoveAll();

	// 현재 열려있는 모든 윈도우들에 대해 웹브라우저를 검색한다
	::EnumWindows(EnumWindowCallBack, (LPARAM)&m_IEWndArray);

	// 검색된 웹브라우저 배열의 크기를 리턴한다
	return m_IEWndArray.GetSize();
}

// 검색된 웹브라우저 배열의 크기를 리턴하는 함수
int CHTMLCollector::GetIEArrayCount()
{
	return m_IEWndArray.GetSize();
}

// 검색된 웹브라우저 배열에서 특정 항목을 리턴하는 함수
SIEWnd* CHTMLCollector::GetIEWnd(int nIndex)
{
	// 인덱스가 웹브라우저 배열의 크기보다 크다면 NULL을 리턴한다
	if(m_IEWndArray.GetSize() <= nIndex)		return NULL;

	// 해당 항목의 웹브라우저 정보 구조체를 리턴한다
	return m_IEWndArray.GetAt(nIndex);
}

// 윈도우 검색시 호출되는 콜백 함수
BOOL CALLBACK CHTMLCollector::EnumWindowCallBack(HWND hWnd, LPARAM lParam)
{ 
	// 인자로 넘어오는 값을 웹브라우저 배열 포인터로 변환한다
	CArray<SIEWnd*, SIEWnd*>  *pArray = (CArray<SIEWnd*, SIEWnd*>*)lParam;

	// 찾아진 윈도우의 하위 윈도우들에 대해 웹브라우저를 검색한다
	EnumChildWindows(hWnd, EnumWindowCallBack, lParam);

	CString strClassName;

	// 찾아진 윈도우의 클래스 이름을 얻는다
	::GetClassName(hWnd, strClassName.GetBuffer(1024), 1024);
	strClassName.ReleaseBuffer();
	strClassName.MakeLower();

	// 만약 클래스 이름에 익스플로러 이름이 포함되어 있다면
	if(strClassName.Find("explorer_server") >= 0)
	{
		CString strProcessName;
		DWORD nProcessID;
		
		// 찾아진 윈도우의 프로세스 ID를 얻는다
		::GetWindowThreadProcessId(hWnd, &nProcessID);
		// 프로세스 ID를 통해 실행파일 이름을 얻는다
		strProcessName = CHTMLCollector::GetProcessName(nProcessID);

		// 만약 실행 파일 이름이 익스플로러가 아니라면 계속해서 다음 윈도우를 검색한다
		if(strProcessName.CompareNoCase("iexplore.exe") != 0)		return TRUE;

		// 만약 인자로 넘어온 값이 NULL이라면
		if(pArray == NULL)
		{
			// 마우스로 선택한 웹브라우저이므로 윈도우 핸들을 전역 변수에 저장한다
			g_hWndExplorer = hWnd;
			// 다음 윈도우를 검색한다
			return TRUE;
		}

		int i;

		// 이전에 배열에 저장한 웹브라우저 중에 겹치는 것이 있는지 확인한다
		for(i = 0; i < pArray->GetSize(); i++)
		{
			if((HWND)pArray->GetAt(i)->hExplorer == hWnd) break;
		}

		// 만약 동일한 웹브라우저를 찾지 못하였다면
		if(i >= pArray->GetSize())
		{
			DWORD lRes;
			// IHTMLDocument2 인터페이스를 얻기 위한 메시지를 등록한다
			UINT MSG = ::RegisterWindowMessage("WM_HTML_GETOBJECT");

			// 웹브라우저에게 메시지를 보낸다
			if(!SendMessageTimeout(hWnd, MSG, 0, 0, SMTO_ABORTIFHUNG, 1000, &lRes))
				return TRUE;

			IHTMLDocument2 *pIDocument;
			HRESULT hr;
			// WM_HTML_GETOBJECT 메시지를 보낸 결과로 IHTMLDocument2 인터페이스를 얻는다
			hr = ObjectFromLresult(lRes, IID_IHTMLDocument2, 0, (LPVOID*)&pIDocument);

			// IHTMLDocument2 인터페이스를 얻지 못하였다면 다음 윈도우를 검색한다
			if(hr != S_OK || pIDocument == NULL)
			{
				return TRUE;
			}

			BSTR bstrUrl, bstrTitle;
			// 해당 웹브라우저의 주소를 구한다
			hr = pIDocument->get_URL(&bstrUrl);
			// 해당 웹브라우저의 제목을 구한다
			hr = pIDocument->get_title(&bstrTitle);

			// 새로운 웹브라우저 정보 구조체를 생성한다
			SIEWnd *pIEWnd = new SIEWnd;
			// 웹브라우저 윈도우 핸들을 저장한다
			pIEWnd->hExplorer	= hWnd;
			// 웹브라우저의 주소를 저장한다
			pIEWnd->strAddress	= bstrUrl;
			// 웹브라우저의 제목을 저장한다
			pIEWnd->strTitle	= bstrTitle;

			// 웹브라우저 배열에 추가한다
			pArray->Add(pIEWnd);

			// 문자열 버퍼를 해제한다
			::SysFreeString(bstrUrl);
			::SysFreeString(bstrTitle);

			// 문서의 인터페이스 참조 횟수를 줄인다
			pIDocument->Release();
		}
	}

	return TRUE;
}  

// 특정 프로세스의 실행 파일 이름을 리턴하는 함수
CString CHTMLCollector::GetProcessName(DWORD pid)
{
	// PSAPI.DLL에서 제공하는 함수들에 대한 타입을 정의한다
	typedef DWORD (WINAPI *PEnumProcessModules)(HANDLE, HMODULE*, UINT, DWORD*);
	typedef DWORD (WINAPI *PGetModuleBaseName)(HANDLE, HMODULE, LPTSTR, UINT);
	
	CString strFileName;

	// PSAPI.DLL을 로드한다
	HINSTANCE hPsApi = ::LoadLibrary("PSAPI.DLL");
	// 만약 DLL을 로드하지 못하였다면 리턴
	if(hPsApi == NULL)		return strFileName;
	
	// 프로세스의 모듈에 대한 정보를 얻는 함수의 포인터를 얻는다
	PEnumProcessModules EnumProcessModules = (PEnumProcessModules)::GetProcAddress(hPsApi, "EnumProcessModules");
	// 모듈의 파일 이름을 얻는 함수의 포인터를 얻는다
	PGetModuleBaseName GetModuleBaseName = (PGetModuleBaseName)::GetProcAddress(hPsApi, "GetModuleBaseNameA");
	// 만약 함수 포인터를 얻지 못하였다면 리턴
	if(EnumProcessModules == NULL || GetModuleBaseName == NULL)		return strFileName;
	
	// 프로세스 ID를 사용하여 프로세스를 열고 핸들을 구한다
	HANDLE hProcess = ::OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);

	// 프로세스 핸들이 구해졌다면
	if(hProcess)
	{
		HMODULE hModule;
		DWORD nNeeded;

		// 모듈의 핸들을 구한다
		if(EnumProcessModules(hProcess, &hModule, sizeof(hModule), &nNeeded))
		{
			// 모듈 핸들을 사용하여 실행 파일 이름을 얻는다
			GetModuleBaseName(hProcess, hModule, strFileName.GetBuffer(MAX_PATH), MAX_PATH);
			strFileName.ReleaseBuffer();
		}
	}
	// 프로세스를 닫는다
	CloseHandle(hProcess);
	// DLL을 닫는다
	::FreeLibrary(hPsApi);

	// 실행 파일 이름을 리턴한다
	return strFileName;
}
