#include "stdafx.h"
#include "ExplorerUIDemo.h"
#include "CustomControlSite.h"

#include "WebBrowser2.h"

BEGIN_INTERFACE_MAP(CCustomControlSite, COleControlSite)
	INTERFACE_PART(CCustomControlSite, IID_IDocHostUIHandler, DocHostUIHandler)
END_INTERFACE_MAP()


ULONG FAR EXPORT CCustomControlSite::XDocHostUIHandler::AddRef()
{
	// 현재 함수에서 상위 클래스인 CCustomControlSite에 대한 포인터 pThis를 계산한다
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	// CCustomControlSite의 ExternalAddRef()을 호출한다
	return pThis->ExternalAddRef();
}


ULONG FAR EXPORT CCustomControlSite::XDocHostUIHandler::Release()
{                            
	// 현재 함수에서 상위 클래스인 CCustomControlSite에 대한 포인터 pThis를 계산한다
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	// CCustomControlSite의 ExternalRelease()을 호출한다
	return pThis->ExternalRelease();
}

HRESULT CCustomControlSite::XDocHostUIHandler::QueryInterface(REFIID riid, void **ppvObj)
{
	// 현재 함수에서 상위 클래스인 CCustomControlSite에 대한 포인터 pThis를 계산한다
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	// CCustomControlSite의 ExternalQueryInterface()을 호출한다
	HRESULT hr = (HRESULT)pThis->ExternalQueryInterface(&riid, ppvObj);
	return hr;
}

HRESULT CCustomControlSite::XDocHostUIHandler::GetHostInfo(
		/* [out][in] */ DOCHOSTUIINFO			__RPC_FAR *pInfo)
{
	// 현재 함수에서 상위 클래스인 CCustomControlSite에 대한 포인터 pThis를 계산한다
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	// 컨트롤 사이트가 관리하는 컨트롤 포인터를 CWebBrowser2 클래스 포인터로 변환한 후
	// CWebBrowser2::OnGetHostInfo()를 호출한다
	return ((CWebBrowser2*)pThis->m_pWndCtrl)->OnGetHostInfo(pInfo);
}

HRESULT CCustomControlSite::XDocHostUIHandler::ShowContextMenu(
		/* [in] */		DWORD					dwID,
		/* [in] */		POINT					__RPC_FAR *ppt,
		/* [in] */		IUnknown				__RPC_FAR *pcmdtReserved,
		/* [in] */		IDispatch				__RPC_FAR *pdispReserved)
{
	// 현재 함수에서 상위 클래스인 CCustomControlSite에 대한 포인터 pThis를 계산한다
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	// 컨트롤 사이트가 관리하는 컨트롤 포인터를 CWebBrowser2 클래스 포인터로 변환한 후
	// CWebBrowser2::OnShowContextMenu()를 호출한다
	return ((CWebBrowser2*)pThis->m_pWndCtrl)->OnShowContextMenu();
}

HRESULT CCustomControlSite::XDocHostUIHandler::ShowUI(
		/* [in] */		DWORD					dwID,
		/* [in] */		IOleInPlaceActiveObject	__RPC_FAR *pActiveObject,
		/* [in] */		IOleCommandTarget		__RPC_FAR *pCommandTarget,
		/* [in] */		IOleInPlaceFrame		__RPC_FAR *pFrame,
		/* [in] */		IOleInPlaceUIWindow		__RPC_FAR *pDoc)
{
	// 구현하지 않는다
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::HideUI(void)
{
	// 구현하지 않는다
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::UpdateUI(void)
{
	// 구현하지 않는다
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::EnableModeless(
		/* [in] */		BOOL					fEnable)
{
	// 구현하지 않는다
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::ResizeBorder(
		/* [in] */		LPCRECT					prcBorder,
		/* [in] */		IOleInPlaceUIWindow		__RPC_FAR *pUIWindow,
		/* [in] */		BOOL					fRameWindow)
{
	// 구현하지 않는다
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::TranslateAccelerator(
		/* [in] */		LPMSG					lpMsg,
		/* [in] */		const GUID				__RPC_FAR *pguidCmdGroup,
		/* [in] */		DWORD					nCmdID)
{
	// 구현하지 않는다
	return E_NOTIMPL;
}
        
HRESULT CCustomControlSite::XDocHostUIHandler::TranslateUrl(
		/* [in] */		DWORD					dwTranslate,
		/* [in] */		OLECHAR					__RPC_FAR *pchURLIn,
		/* [out] */		OLECHAR					__RPC_FAR *__RPC_FAR *ppchURLOut)
{
	// 구현하지 않는다
	return E_NOTIMPL;
}

HRESULT  CCustomControlSite::XDocHostUIHandler::GetOptionKeyPath(
		/* [out] */		LPOLESTR				__RPC_FAR *pchKey,
		/* [in] */		DWORD					dw)
{
	// 구현하지 않는다
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::GetDropTarget( 
		/* [in] */		IDropTarget				__RPC_FAR *pDropTarget,
		/* [out] */		IDropTarget				__RPC_FAR *__RPC_FAR *ppDropTarget)
{
	// 구현하지 않는다
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::GetExternal(
		/* [out] */		IDispatch				__RPC_FAR *__RPC_FAR *ppDispatch)
{
	// 구현하지 않는다
	return E_NOTIMPL;
}
        
HRESULT CCustomControlSite::XDocHostUIHandler::FilterDataObject(
		/* [in] */		IDataObject				__RPC_FAR *pDO,
		/* [out] */		IDataObject				__RPC_FAR *__RPC_FAR *ppDORet)
{
	// 구현하지 않는다
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::OnDocWindowActivate(
		/* [in] */		BOOL					fEnable)
{
	// 구현하지 않는다
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::OnFrameWindowActivate(
		/* [in] */		BOOL					fEnable)
{
	// 구현하지 않는다
	return E_NOTIMPL;
}
