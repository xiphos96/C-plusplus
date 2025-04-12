class ATL_NO_VTABLE CEventHandler : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IAddBackEvents, &IID_IAddBackEvents, &LIBID_AddBackLib>
{
public:
	BEGIN_COM_MAP(CEventHandler)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IAddBackEvents)
	END_COM_MAP()

	STDMETHOD(raw_ChangedAddEnd) (SHORT newVal) {
		CString szMsg("AddEnd �Ӽ��� ����Ǿ����ϴ�.\n");
		CString szTemp;
		szTemp.Format("AddEnd �Ӽ� �� : %d", newVal);
		szMsg += szTemp;
		MessageBox(NULL, szMsg.GetBuffer(szMsg.GetLength()), "AddEnd �Ӽ��� ����", MB_OK);
		return S_OK;
	}

	STDMETHOD(raw_ChangedSum) (SHORT newVal) {
		CString szMsg("Sum �Ӽ��� ����Ǿ����ϴ�.\n");
		CString szTemp;
		szTemp.Format("Sum �Ӽ� �� : %d", newVal);
		szMsg += szTemp;
		MessageBox(NULL, szMsg.GetBuffer(szMsg.GetLength()), "Sum �Ӽ��� ����", MB_OK);
		return S_OK;
	}
};
