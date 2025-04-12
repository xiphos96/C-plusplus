#include "stdafx.h"
#include "ExplorerUIDemo.h"
#include "CustomControlSite.h"

#include "WebBrowser2.h"

BEGIN_INTERFACE_MAP(CCustomControlSite, COleControlSite)
	INTERFACE_PART(CCustomControlSite, IID_IDocHostUIHandler, DocHostUIHandler)
END_INTERFACE_MAP()


ULONG FAR EXPORT CCustomControlSite::XDocHostUIHandler::AddRef()
{
	// ���� �Լ����� ���� Ŭ������ CCustomControlSite�� ���� ������ pThis�� ����Ѵ�
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	// CCustomControlSite�� ExternalAddRef()�� ȣ���Ѵ�
	return pThis->ExternalAddRef();
}


ULONG FAR EXPORT CCustomControlSite::XDocHostUIHandler::Release()
{                            
	// ���� �Լ����� ���� Ŭ������ CCustomControlSite�� ���� ������ pThis�� ����Ѵ�
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	// CCustomControlSite�� ExternalRelease()�� ȣ���Ѵ�
	return pThis->ExternalRelease();
}

HRESULT CCustomControlSite::XDocHostUIHandler::QueryInterface(REFIID riid, void **ppvObj)
{
	// ���� �Լ����� ���� Ŭ������ CCustomControlSite�� ���� ������ pThis�� ����Ѵ�
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	// CCustomControlSite�� ExternalQueryInterface()�� ȣ���Ѵ�
	HRESULT hr = (HRESULT)pThis->ExternalQueryInterface(&riid, ppvObj);
	return hr;
}

HRESULT CCustomControlSite::XDocHostUIHandler::GetHostInfo(
		/* [out][in] */ DOCHOSTUIINFO			__RPC_FAR *pInfo)
{
	// ���� �Լ����� ���� Ŭ������ CCustomControlSite�� ���� ������ pThis�� ����Ѵ�
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	// ��Ʈ�� ����Ʈ�� �����ϴ� ��Ʈ�� �����͸� CWebBrowser2 Ŭ���� �����ͷ� ��ȯ�� ��
	// CWebBrowser2::OnGetHostInfo()�� ȣ���Ѵ�
	return ((CWebBrowser2*)pThis->m_pWndCtrl)->OnGetHostInfo(pInfo);
}

HRESULT CCustomControlSite::XDocHostUIHandler::ShowContextMenu(
		/* [in] */		DWORD					dwID,
		/* [in] */		POINT					__RPC_FAR *ppt,
		/* [in] */		IUnknown				__RPC_FAR *pcmdtReserved,
		/* [in] */		IDispatch				__RPC_FAR *pdispReserved)
{
	// ���� �Լ����� ���� Ŭ������ CCustomControlSite�� ���� ������ pThis�� ����Ѵ�
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	// ��Ʈ�� ����Ʈ�� �����ϴ� ��Ʈ�� �����͸� CWebBrowser2 Ŭ���� �����ͷ� ��ȯ�� ��
	// CWebBrowser2::OnShowContextMenu()�� ȣ���Ѵ�
	return ((CWebBrowser2*)pThis->m_pWndCtrl)->OnShowContextMenu();
}

HRESULT CCustomControlSite::XDocHostUIHandler::ShowUI(
		/* [in] */		DWORD					dwID,
		/* [in] */		IOleInPlaceActiveObject	__RPC_FAR *pActiveObject,
		/* [in] */		IOleCommandTarget		__RPC_FAR *pCommandTarget,
		/* [in] */		IOleInPlaceFrame		__RPC_FAR *pFrame,
		/* [in] */		IOleInPlaceUIWindow		__RPC_FAR *pDoc)
{
	// �������� �ʴ´�
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::HideUI(void)
{
	// �������� �ʴ´�
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::UpdateUI(void)
{
	// �������� �ʴ´�
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::EnableModeless(
		/* [in] */		BOOL					fEnable)
{
	// �������� �ʴ´�
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::ResizeBorder(
		/* [in] */		LPCRECT					prcBorder,
		/* [in] */		IOleInPlaceUIWindow		__RPC_FAR *pUIWindow,
		/* [in] */		BOOL					fRameWindow)
{
	// �������� �ʴ´�
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::TranslateAccelerator(
		/* [in] */		LPMSG					lpMsg,
		/* [in] */		const GUID				__RPC_FAR *pguidCmdGroup,
		/* [in] */		DWORD					nCmdID)
{
	// �������� �ʴ´�
	return E_NOTIMPL;
}
        
HRESULT CCustomControlSite::XDocHostUIHandler::TranslateUrl(
		/* [in] */		DWORD					dwTranslate,
		/* [in] */		OLECHAR					__RPC_FAR *pchURLIn,
		/* [out] */		OLECHAR					__RPC_FAR *__RPC_FAR *ppchURLOut)
{
	// �������� �ʴ´�
	return E_NOTIMPL;
}

HRESULT  CCustomControlSite::XDocHostUIHandler::GetOptionKeyPath(
		/* [out] */		LPOLESTR				__RPC_FAR *pchKey,
		/* [in] */		DWORD					dw)
{
	// �������� �ʴ´�
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::GetDropTarget( 
		/* [in] */		IDropTarget				__RPC_FAR *pDropTarget,
		/* [out] */		IDropTarget				__RPC_FAR *__RPC_FAR *ppDropTarget)
{
	// �������� �ʴ´�
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::GetExternal(
		/* [out] */		IDispatch				__RPC_FAR *__RPC_FAR *ppDispatch)
{
	// �������� �ʴ´�
	return E_NOTIMPL;
}
        
HRESULT CCustomControlSite::XDocHostUIHandler::FilterDataObject(
		/* [in] */		IDataObject				__RPC_FAR *pDO,
		/* [out] */		IDataObject				__RPC_FAR *__RPC_FAR *ppDORet)
{
	// �������� �ʴ´�
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::OnDocWindowActivate(
		/* [in] */		BOOL					fEnable)
{
	// �������� �ʴ´�
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::OnFrameWindowActivate(
		/* [in] */		BOOL					fEnable)
{
	// �������� �ʴ´�
	return E_NOTIMPL;
}
