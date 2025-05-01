#ifndef __IXING_DEFINE_H__
#define __IXING_DEFINE_H__

//------------------------------------------------------------------------------
// �޽��� ����
// �޽����� ID���� Connect�ÿ� ������ nStartMsgID�� ���Ͽ� ����ϸ� �ȴ�.
#define 	XM_DISCONNECT			1		// �������� ������ �������� ��� �߻�
#define 	XM_RECEIVE_DATA			3		// RequestData�� ��û�� �����Ͱ� �����κ��� �޾��� �� �߻�
#define 	XM_RECEIVE_REAL_DATA	4		// AdviseData�� ��û�� �����Ͱ� �����κ��� �޾��� �� �߻�
#define 	XM_LOGIN				5		// �����κ��� �α��� ��� �޾����� �߻�
#define 	XM_LOGOUT				6		// �����κ��� �α׾ƿ� ��� �޾����� �߻�
#define		XM_TIMEOUT_DATA			7		// RequestData�� ��û�� �����Ͱ� Timeout �� �߻�������
#define 	XM_RECEIVE_LINK_DATA	8		// HTS ���� ���� �����Ͱ� �߻����� �� : by zzin 2013.11.11  
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Receive Flag
#define		REQUEST_DATA			1
#define		MESSAGE_DATA			2
#define		SYSTEM_ERROR_DATA		3
#define		RELEASE_DATA			4
#define		LINK_DATA				10
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Structure ����
#pragma pack( push, 1 )

// ��ȸTR ���� Packet
typedef struct _RECV_PACKET
{
	_RECV_PACKET() { ZeroMemory(this, sizeof(_RECV_PACKET)); }

	int					nRqID;						// Request ID
	int					nDataLength;				// ���� ������ ũ��
	int					nTotalDataBufferSize;		// lpData�� �Ҵ�� ũ��
	int					nElapsedTime;				// ���ۿ��� ���ű��� �ɸ��ð�(1/1000��)
	int					nDataMode;					// 1:BLOCK MODE, 2:NON-BLOCK MODE
	char				szTrCode[10 + 1];			// AP Code
	char				cCont[1];			// '0' : ������ȸ ����, '1' : ������ȸ ����
	char				szContKey[18 + 1];			// ����Ű, Data Header�� B �� ��쿡�� ���
	char				szUserData[30 + 1];			// ����� ������
	char				szBlockName[17];			// Block ��, Block Mode �϶� ���
	unsigned char*		lpData;
} RECV_PACKET, *LPRECV_PACKET;

// �޽��� ���� Packet
typedef struct
{
	int					nRqID;						// Request ID
	int					nIsSystemError;				// 0:�Ϲݸ޽���, 1:System Error �޽���
	char				szMsgCode[5 + 1];				// �޽��� �ڵ�
	int					nMsgLength;					// Message ����
	unsigned char*		lpszMessageData;			// Message Data
} MSG_PACKET, *LPMSG_PACKET;

// �ǽð�TR ���� Packet
typedef struct _REAL_RECV_PACKET
{
	_REAL_RECV_PACKET() { ZeroMemory(this, sizeof(_REAL_RECV_PACKET)); }

	char				szTrCode[3 + 1];

	int					nKeyLength;
	char				szKeyData[32 + 1];
	char				szRegKey[32 + 1];

	int					nDataLength;
	char*				pszData;
} RECV_REAL_PACKET, *LPRECV_REAL_PACKET;


// HTS���� API�� �����Ǿ� ���ŵǴ� Packet
typedef struct _LINKDATA_RECV_MSG
{
	_LINKDATA_RECV_MSG() { ZeroMemory(this, sizeof(_LINKDATA_RECV_MSG)); }

	char				sLinkName[32];
	char				sLinkData[32];
	char				sFiller[64];
}LINKDATA_RECV_MSG, *LPLINKDATA_RECV_MSG;
//------------------------------------------------------------------------------

#endif