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
		CString szMsg("AddEnd 속성이 변경되었습니다.\n");
		CString szTemp;
		szTemp.Format("AddEnd 속성 값 : %d", newVal);
		szMsg += szTemp;
		MessageBox(NULL, szMsg.GetBuffer(szMsg.GetLength()), "AddEnd 속성값 변경", MB_OK);
	}

	void OnChangedSum(SHORT newVal) {
		CString szMsg("Sum 속성이 변경되었습니다.\n");
		CString szTemp;
		szTemp.Format("Sum 속성 값 : %d", newVal);
		szMsg += szTemp;
		MessageBox(NULL, szMsg.GetBuffer(szMsg.GetLength()), "Sum 속성값 변경", MB_OK);
	}
};
