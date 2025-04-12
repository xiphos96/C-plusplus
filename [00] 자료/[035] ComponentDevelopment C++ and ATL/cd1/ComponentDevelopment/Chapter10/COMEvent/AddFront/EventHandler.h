[event_receiver(com)]
class CEventHandler
{
public:
	void HookEvent(IUnknown* pSource) {
		__hook(&_IAddBackEvents::ChangedAddEnd, pSource, &CEventHandler::OnChangedAddEnd);
		__hook(&_IAddBackEvents::ChangedSum, pSource, &CEventHandler::OnChangedSum);
	}
	void UnhookEvent(IUnknown* pSource) {
		__unhook(&_IAddBackEvents::ChangedAddEnd, pSource, &CEventHandler::OnChangedAddEnd);
		__unhook(&_IAddBackEvents::ChangedSum, pSource, &CEventHandler::OnChangedSum);
	}
		
	void OnChangedAddEnd(SHORT newVal) {
		CString szMsg("AddEnd �Ӽ��� ����Ǿ����ϴ�.\n");
		CString szTemp;
		szTemp.Format("AddEnd �Ӽ� �� : %d", newVal);
		szMsg += szTemp;
		MessageBox(NULL, szMsg.GetBuffer(szMsg.GetLength()), "AddEnd �Ӽ��� ����", MB_OK);
	}

	void OnChangedSum(SHORT newVal) {
		CString szMsg("Sum �Ӽ��� ����Ǿ����ϴ�.\n");
		CString szTemp;
		szTemp.Format("Sum �Ӽ� �� : %d", newVal);
		szMsg += szTemp;
		MessageBox(NULL, szMsg.GetBuffer(szMsg.GetLength()), "Sum �Ӽ��� ����", MB_OK);
	}
};
