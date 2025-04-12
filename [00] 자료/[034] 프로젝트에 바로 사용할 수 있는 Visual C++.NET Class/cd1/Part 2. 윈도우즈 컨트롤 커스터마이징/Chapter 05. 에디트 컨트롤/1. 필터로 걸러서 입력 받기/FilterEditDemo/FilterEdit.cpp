// FilterEdit.cpp : implementation file
//

#include "stdafx.h"
#include "filtereditdemo.h"
#include "FilterEdit.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFilterEdit

CFilterEdit::CFilterEdit()
{
	// �ʱⰪ ����
	m_clrText	= RGB(0, 0, 0);
	m_clrBkgnd	= RGB(255, 255, 255);
	m_brsBkgnd.CreateSolidBrush(m_clrBkgnd);

	m_nType				= FILTER_NUMBER;
	m_nDecPointPos		= -1;

	m_strDateFormat		= "yyyy�� mm�� dd��";
	m_strTimeFormat		= "hh�� mm�� ss��";
	m_bTime24			= FALSE;
	m_bAmPm				= TRUE;

	// �ý����� �⺻ ȭ�� ���ڸ� ȹ���Ѵ�
	::GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SCURRENCY, m_strCurrency.GetBuffer(7), 7);
	m_strCurrency.ReleaseBuffer();
}

CFilterEdit::~CFilterEdit()
{
	m_brsBkgnd.DeleteObject();
}


BEGIN_MESSAGE_MAP(CFilterEdit, CEdit)
	//{{AFX_MSG_MAP(CFilterEdit)
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_CUT, OnCut)
	ON_MESSAGE(WM_PASTE, OnPaste)
	ON_MESSAGE(WM_CLEAR, OnClear)
	ON_MESSAGE(WM_SETTEXT, OnSetText)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFilterEdit message handlers

// �ؽ�Ʈ ���� ���� �Լ�
void CFilterEdit::SetTextColor(COLORREF clrText)
{
	m_clrText = clrText;
	if(::IsWindow(m_hWnd))	Invalidate();
}

// ��� ���� ���� �Լ�
void CFilterEdit::SetBkgndColor(COLORREF clrBkgnd)
{
	if(m_clrBkgnd == clrBkgnd)	return;

	// ���ο� ���� ���� �귯���� �����Ѵ�
	m_clrBkgnd = clrBkgnd;
	if(m_brsBkgnd.m_hObject)	m_brsBkgnd.DeleteObject();
	m_brsBkgnd.CreateSolidBrush(m_clrBkgnd);

	if(::IsWindow(m_hWnd))	Invalidate();
}

// ����Ʈ ��Ʈ�ѿ� ���� �׸��� �Ӽ� ����
HBRUSH CFilterEdit::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	pDC->SetTextColor(m_clrText);
	pDC->SetBkColor(m_clrBkgnd);

	return m_brsBkgnd;
}

// ���� ��带 �����ϴ� �Լ�
int CFilterEdit::SetFormat(int nFormat, BOOL bEraseAll)
{
	// ���� ��带 ����
	m_nType = nFormat;

	if(bEraseAll)
	{
		SetWindowText("");
		return m_nType;
	}

	// ���� �ؽ�Ʈ�� ���� ��ȿ�� �˻縦 �����Ѵ�
	CString strText, strValid;
	GetWindowText(strText);

	switch(m_nType)
	{
	case FILTER_CURRENCY:
		CheckCurrency(strText, strValid, 0);
		break;
	case FILTER_DATE:
		CheckDate(strText, strValid, 0);
		break;
	case FILTER_TIME:
		CheckTime(strText, strValid, 0);
		break;
	case FILTER_MASK:
		CheckFormat(strText, strValid, 0);
		break;
	default:
		CheckText(strText, strValid);
		break;
	}

	SetWindowText(strValid);

	return m_nType;
}

// ���� ��带 ����ũ�� �����ϰ� ����ũ ������ �����ϴ� �Լ�
int CFilterEdit::SetFormat(LPCTSTR pFormat, BOOL bEraseAll)
{
	// ���� ��带 ����ũ�� ����
	m_nType = FILTER_MASK;

	// ����ũ ���� ���ڿ��� ����
	m_strMask = pFormat;

	if(bEraseAll)
	{
		SetWindowText("");
		return m_nType;
	}

	// ���� �ؽ�Ʈ�� ���� ��ȿ�� �˻縦 �����Ѵ�
	CString strText, strValid;
	GetWindowText(strText);

	CheckFormat(strText, strValid, 0);

	SetWindowText(strValid);

	return m_nType;
}

// ���� ��带 ��¥�� �����ϰ� ��¥ ������ �����ϴ� �Լ�
int CFilterEdit::SetDateFormat(LPCTSTR pFormat, BOOL bEraseAll)
{
	// ���� ��带 ��¥�� ����
	m_nType = FILTER_DATE;

	// ��¥ ���� ���ڿ��� ����
	m_strDateFormat = pFormat;

	if(bEraseAll)
	{
		SetWindowText("");
		return m_nType;
	}

	// ���� �ؽ�Ʈ�� ���� ��ȿ�� �˻縦 �����Ѵ�
	CString strText, strValid;
	GetWindowText(strText);

	CheckDate(strText, strValid, 0);

	SetWindowText(strValid);

	return m_nType;
}

// ���� ��带 �ð����� �����ϰ� �ð� ������ �����ϴ� �Լ�
int CFilterEdit::SetTimeFormat(LPCTSTR pFormat, BOOL bTime24, BOOL bEraseAll)
{
	// ���� ��带 �ð����� ����
	m_nType = FILTER_TIME;

	// �ð� ���� ���ڿ��� ����
	m_strTimeFormat = pFormat;
	m_bTime24		= bTime24;
	m_bAmPm			= TRUE;

	if(bEraseAll)
	{
		SetWindowText("");
		return m_nType;
	}

	// ���� �ؽ�Ʈ�� ���� ��ȿ�� �˻縦 �����Ѵ�
	CString strText, strValid;
	GetWindowText(strText);

	CheckTime(strText, strValid, 0);

	SetWindowText(strValid);

	return m_nType;
}

// ȭ��/��¥/�ð�/����ũ�� ������ ���� ��忡�� �� ������ ��ȿ���� �˻��ϴ� �Լ�
inline BOOL CFilterEdit::IsValidChar(char ch, int n, int nRemain)
{
	// ���� ���Ͱ� ���ٸ� ��ȿ
	if(m_nType == FILTER_NONE)		return TRUE;

	// ���� ���Ϳ� ���ڰ� ���ԵǾ� �ִٸ�
	if(m_nType & FILTER_NUMBER)
	{
		// ������ ��� ��ȿ
		if(::isdigit(ch))			return TRUE;
	}

	// ���� ���Ϳ� ��ȣ�� ���ԵǾ� �ִٸ�
	if(m_nType & FILTER_SIGN)
	{
		// ��ȣ ������ ��� ��ȿ
		if(ch == '-')
		{
			if(n == 0)				return TRUE;
			else					return FALSE;
		}
	}

	// ���� ���Ϳ� �Ҽ����� ���ԵǾ� �ִٸ�
	if(m_nType & FILTER_DECIMALPOINT)
	{
		// �Ҽ����� ���
		if(ch == '.')
			// ���� �Ҽ����� �������� �ʾҴٸ� ��ȿ
			if(m_nDecPointPos < 0)
			{
				// �Ҽ��� ��ġ ����
				m_nDecPointPos = n;
				return TRUE;
			}
			else
				return FALSE;
	}

	// ���� ���Ϳ� ���ĺ� �빮�ڰ� ���ԵǾ� �ִٸ�
	if(m_nType & FILTER_UPPERCASE)
	{
		// �빮���� ��� ��ȿ
		if(::isupper(ch))			return TRUE;
	}

	// ���� ���Ϳ� ���ĺ� �ҹ��ڰ� ���ԵǾ� �ִٸ�
	if(m_nType & FILTER_LOWERCASE)
	{
		// �ҹ����� ��� ��ȿ
		if(::islower(ch))			return TRUE;
	}

	// ��Ÿ�� ��� ��ȿ
	return FALSE;
}

// ȭ��/��¥/�ð�/����ũ�� ������ ���� ��忡�� ���ڿ��� ��ȿ���� �˻��ϴ� �Լ�
void CFilterEdit::CheckText(CString &strInput, CString &strOutput)
{
	// �Ҽ����� ���� ������ �ʱ�ȭ
	m_nDecPointPos = -1;

	strOutput.Empty();

	int nLength = strInput.GetLength(), i;

	// ���ڿ��� ���̸�ŭ ������ ���鼭 �� ���ڸ� �˻��Ѵ�
	for(i = 0; i < nLength; i++)
	{
		if(IsValidChar(strInput.GetAt(i), i, nLength - i - 1))
			// ��ȿ�� ���ڵ鸸���� ���ڿ��� �����Ѵ�
			strOutput += strInput.GetAt(i);
	}

	// ���� �Ҽ����� ���� �� �ְ� �Ҽ����� ù��° ���ڶ��
	if((m_nType & FILTER_DECIMALPOINT) && m_nDecPointPos == 0)
		// �Ҽ��� �տ� 0�� �߰��Ѵ�
		strOutput.Insert(0, "0");
}

// ȭ�� ��忡�� ���ڿ��� ��ȿ���� �˻��ϴ� �Լ�
int CFilterEdit::CheckCurrency(CString &strInput, CString &strOutput, int nPos)
{
	// �Ҽ����� ���� ������ �ʱ�ȭ
	m_nDecPointPos = -1;

	strOutput.Empty();

	// ȭ�� ��尡 �ƴ϶�� ����
	if(!(m_nType & FILTER_CURRENCY))		return 0;

	int nLength = strInput.GetLength(), i, nTerm = 0;

	// ���ڿ��� ���̸�ŭ ������ ���鼭 �� ���ڸ� �˻��Ѵ�
	for(i = 0; i < nLength; i++)
	{
		// ���� ���ڶ��
		if(::isdigit(strInput.GetAt(i)))
			// ���ڿ��� �߰�
			strOutput += strInput.GetAt(i);
		else
			// ���ڰ� �ƴϸ� �߰����� �ʰ�
			// ���� ���� ĳ�� ��ġ���� �տ� �ִٸ� ������ ������Ų��
			if(nPos > i)	nTerm++;
	}
	// ���� ĳ�� ��ġ�� nPos�� �����Ѵ�
	nPos -= nTerm;

	// ���ڿ��� ���� �����ʺ��� ���ڸ����� ','�� �߰��Ѵ�
	nLength = strOutput.GetLength();
	for(i = nLength % 3; i < nLength; i += 3)
	{
		if(i == 0) continue;

		strOutput.Insert(i, ',');
		if(nPos >= i)	nPos += 1;
		nLength += 1;
		i += 1;
	}

	// ���ڿ��� �տ� ȭ�� ���ڸ� �߰��Ѵ�
	strOutput.Insert(0, m_strCurrency);

	// ȭ�� ���ڸ�ŭ ĳ�� ��ġ�� �����Ѵ�
	nPos += m_strCurrency.GetLength();

	return nPos;
}

// ��¥ ��忡�� ���ڿ��� ��ȿ���� �˻��ϴ� �Լ�
int CFilterEdit::CheckDate(CString &strInput, CString &strOutput, int nPos)
{
	// �Ҽ����� ���� ������ �ʱ�ȭ
	m_nDecPointPos = -1;

	strOutput.Empty();

	// ��¥ ��尡 �ƴ϶�� ����
	if(!(m_nType & FILTER_DATE))		return 0;

	int nLength = strInput.GetLength(), i;
	int nFormat = m_strDateFormat.GetLength();
	int nStart, nDate;
	CString strNum, strFormat;
	char ch;

	// ���ڿ��� ���̸�ŭ ������ ���鼭 ��¥ ���� ���ڸ� �˻��Ѵ�
	for(i = 0; i < nLength && i < nFormat; i++)
	{
		switch(m_strDateFormat.GetAt(i))
		{
		// ���� ���� �Է� �ڸ����
		case 'y':
		// ���� ���� �Է� �ڸ����
		case 'm':
		// ���� �ϼ� �Է� �ڸ����
		case 'd':
			ch = m_strDateFormat.GetAt(i);

			nStart = i;
			strNum.Empty();
			// ��¥ ���˿��� �ش� ������ ���� ã�´�
			for(; i < nLength && i < nFormat; i++)
			{
				if(m_strDateFormat.GetAt(i) != ch)	break;
				// �ش� ������ ��ġ�� �ִ� �Է� ���� ���ڿ��� ������
				strNum += strInput.GetAt(i);
			}
			// �Էµ� ���ڿ��� ���ڷ� �ٲ۴�
			nDate = ::atoi(LPCTSTR(strNum));

			switch(ch)
			{
			case 'y':
				// ������ ������� ����� �ٲ۴�
				if(nDate < 0)		nDate *= -1;
				break;
			case 'm':
				// ������ ������� ����� �ٲ۴�
				if(nDate < 0)		nDate *= -1;
				// ������ 12�� �ʰ��Ѵٸ� 12�� �ٲ۴�
				if(nDate > 12)		nDate = 12;
				// ������ 0�̰� ���ڸ� �̻��� �Է� �Ǿ��ٸ� 1�� �ٲ۴�
				if(nDate == 0 && strNum.GetLength() > 1)		nDate = 1;
				break;
			case 'd':
				// �ϼ��� ������� ����� �ٲ۴�
				if(nDate < 0)		nDate *= -1;
				// �ϼ��� 31�� �ʰ��Ѵٸ� 31�� �ٲ۴�
				if(nDate > 31)		nDate = 31;
				// �ϼ��� 0�̰� ���ڸ� �̻��� �Է� �Ǿ��ٸ� 1�� �ٲ۴�
				if(nDate == 0 && strNum.GetLength() > 1)		nDate = 1;
				break;
			}

			// ���ڿ��� ���̸�ŭ�� ���� ������ �����
			strFormat.Format("%%0%dd", i - nStart);
			// ���ڸ� ���ڿ��� �ٲ۴�
			strNum.Format(strFormat, nDate);
			// ��� ���ڿ��� �߰��Ѵ�
			strOutput += strNum;
			i -= 1;
			break;
		default:
			// ��/��/�� ���ڰ� �ƴ϶�� ���� ���ڸ� ��� ���ڿ��� �߰��Ѵ�
			strOutput += m_strDateFormat.GetAt(i);
			break;
		}
	}

	return nPos;
}

int CFilterEdit::CheckTime(CString &strInput, CString &strOutput, int nPos)
{
	// �Ҽ����� ���� ������ �ʱ�ȭ
	m_nDecPointPos = -1;

	strOutput.Empty();

	// �ð� ��尡 �ƴ϶�� ����
	if(!(m_nType & FILTER_TIME))		return 0;

	int nLength = strInput.GetLength(), i;
	int nFormat = m_strTimeFormat.GetLength();
	int nStart, nTime;
	CString strNum, strFormat;
	char ch;

	// ���ڿ��� ���̸�ŭ ������ ���鼭 �ð� ���� ���ڸ� �˻��Ѵ�
	for(i = 0; i < nLength && i < nFormat; i++)
	{
		switch(m_strTimeFormat.GetAt(i))
		{
		// ���� �ð� �Է� �ڸ����
		case 'h':
		// ���� �� �Է� �ڸ����
		case 'm':
		// ���� �� �Է� �ڸ����
		case 's':
			ch = m_strTimeFormat.GetAt(i);

			nStart = i;
			strNum.Empty();
			// �ð� ���˿��� �ش� ������ ���� ã�´�
			for(; i < nLength && i < nFormat; i++)
			{
				if(m_strTimeFormat.GetAt(i) != ch)	break;
				// �ش� ������ ��ġ�� �ִ� �Է� ���� ���ڿ��� ������
				strNum += strInput.GetAt(i);
			}
			// �Էµ� ���ڿ��� ���ڷ� �ٲ۴�
			nTime = ::atoi(LPCTSTR(strNum));

			switch(ch)
			{
			case 'h':
				// �ð��� ������� ����� �ٲ۴�
				if(nTime < 0)		nTime *= -1;
				// 24�� ǥ����
				if(m_bTime24)
				{
					// �ð��� 23�� �ʰ��ϸ� 23���� �ٲ۴�
					if(nTime > 23)	nTime = 23;
				}
				else
				{
					// �ð��� 12�� �ʰ��ϸ� 12�� �ٲ۴�
					if(nTime > 12)	nTime = 12;
					// �ð��� 0�̰� ���ڸ� �̻��� �ԷµǾ��ٸ� 1�� �ٲ۴�
					if(nTime == 0 && strNum.GetLength() > 1)	nTime = 1;
				}
				break;
			case 'm':
				// ���� ������� ����� �ٲ۴�
				if(nTime < 0)		nTime *= -1;
				// ���� 59�� �ʰ��ϸ� 59�� �ٲ۴�
				if(nTime > 59)		nTime = 59;
				break;
			case 's':
				// �ʰ� ������� ����� �ٲ۴�
				if(nTime < 0)		nTime *= -1;
				// �ʰ� 59�� �ʰ��ϸ� 59�� �ٲ۴�
				if(nTime > 59)		nTime = 59;
				break;
			}

			// ���ڿ��� ���̸�ŭ�� ���� ������ �����
			strFormat.Format("%%0%dd", i - nStart);
			// ���ڸ� ���ڿ��� �ٲ۴�
			strNum.Format(strFormat, nTime);
			// ��� ���ڿ��� �߰��Ѵ�
			strOutput += strNum;
			i -= 1;
			break;
		default:
			// ��/��/�� ���ڰ� �ƴ϶�� ���� ���ڸ� ��� ���ڿ��� �߰��Ѵ�
			strOutput += m_strTimeFormat.GetAt(i);
			break;
		}
	}

	// ���� 24�� ǥ�Ⱑ �ƴϰ�, ���˿� �´� ���ڿ��� ��� �Էµ� ���¶��
	if(!m_bTime24 && strOutput.GetLength() == m_strTimeFormat.GetLength())
	{
		// ����/���ĸ� �߰��Ѵ�
		if(m_bAmPm)		strOutput += " ����";
		else			strOutput += " ����";
	}

	return nPos;
}

int CFilterEdit::CheckFormat(CString &strInput, CString &strOutput, int nPos)
{
	// �Ҽ����� ���� ������ �ʱ�ȭ
	m_nDecPointPos = -1;

	strOutput.Empty();

	// ����ũ ��尡 �ƴ϶�� ����
	if(!(m_nType & FILTER_MASK))		return 0;

	int nLength = strInput.GetLength(), i, nTerm = 0;
	int nFormat = m_strMask.GetLength();

	// ���ڿ��� ���̸�ŭ ������ ���鼭 ����ũ ���� ���ڸ� �˻��Ѵ�
	for(i = 0; i < nLength && i < nFormat; i++)
	{
		// ���� ���� �Է� �ڸ����
		if(m_strMask.GetAt(i) == FILTER_MASK_NUMBER)
		{
			// ������ ��� ��� ���ڿ��� �߰��Ѵ�
			if(::isdigit(strInput.GetAt(i)))
				strOutput += strInput.GetAt(i);
			else
			{
				// ���ڰ� �ƴ� ���, ĳ���� ���� ���ں��� �ڿ� �ִٸ� ������ ����
				if(nPos > i)
					nTerm = strInput.GetLength() - i;
				break;
			}
			continue;
		}
		// ���� ���� �Է� �ڸ����
		if(m_strMask.GetAt(i) == FILTER_MASK_ALPHA)
		{
			// ������ ��� ��� ���ڿ��� �߰��Ѵ�
			if(::isalpha(strInput.GetAt(i)))
				strOutput += strInput.GetAt(i);
			else
			{
				// ���ڰ� �ƴ� ���, ĳ���� ���� ���ں��� �ڿ� �ִٸ� ������ ����
				if(nPos > i)
					nTerm = strInput.GetLength() - i;
				break;
			}
			continue;
		}
		// ����/���� �Է� �ڸ��� �ƴ϶�� ������ ���ڸ� ��� ���ڿ� �߰��Ѵ�
		strOutput += m_strMask.GetAt(i);
	}
	// ���ŵ� ���ڸ�ŭ ĳ�� ��ġ�� �����Ѵ�
	nPos -= nTerm;

	return nPos;
}

// ���� Ȥ�� �齺���̽� Ű�� �������� ���
void CFilterEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CString strText;
	// ���� �Է� �ؽ�Ʈ�� ��´�
	GetWindowText(strText);

	int nStart, nEnd;
	// ���� ��(ĳ�� ��ġ) ��ġ�� ��´�
	GetSel(nStart, nEnd);

	// ���� ���� ��忡 ���� ��ȿ�� �˻縦 �Ѵ�
	switch(m_nType)
	{
	case FILTER_CURRENCY:
		// ȭ�� ����� ��� ���ڿ� �齺���̽��� �ƴϸ� ��ȿ
		if(!::isdigit(nChar) && nChar != VK_BACK)
		{
			MessageBeep(MB_OK);
			return;
		}
		break;
	case FILTER_DATE:
		// ��¥ ����̸�, ĳ���� �ؽ�Ʈ�� ���� ��ġ�ϰ� ���� �ʴٸ�
		// ���� �����Ǿ� ���� �ʰ� ���˿� �°� �Է��� �Ϸ�� �����̰ų� ���ڰ� �ƴϰ� �齺���̽��� �ƴ϶�� ��ȿ
		if(strText.GetLength() != nEnd
			|| (((nStart == nEnd && nEnd >= m_strDateFormat.GetLength()) || !::isdigit(nChar)) && nChar != VK_BACK))
		{
			MessageBeep(MB_OK);
			return;
		}
		// �齺���̽���� ��ȿ
		if(nChar == VK_BACK)		break;

		// ���� ���̶�� �� �κ��� �����Ѵ�
		if(nStart != nEnd)		strText.Delete(nStart, nEnd - nStart);
		nEnd = nStart;
		// ���� ��ġ���� ��/��/�� �Է� �κб����� ���� ���ڸ� �߰��Ѵ�
		for(; nStart < m_strDateFormat.GetLength(); nStart++)
		{
			if(m_strDateFormat.GetAt(nStart) != 'y'
				&& m_strDateFormat.GetAt(nStart) != 'm'
				&& m_strDateFormat.GetAt(nStart) != 'd')
				strText += m_strDateFormat.GetAt(nStart);
			else
				break;
		}
		// ���� ���� ���ڰ� �߰��Ǿ��ٸ�
		if(nStart != nEnd)
		{
			// ĳ���� ��ġ�� ���� �ڷ� �ű�� �켱 ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����Ѵ�
			nEnd = nStart;
			SetWindowText(strText);
			SetSel(nStart, nStart);
		}
		// ���� ���˿� �°� ��� �Էµ� ���¶�� ��ȿ
		if(nStart >= m_strDateFormat.GetLength())
		{
			MessageBeep(MB_OK);
			return;
		}

		// ���� �� �Է� ��ġ���
		if(m_strDateFormat.GetAt(nStart) == 'm')
		{
			// �ٷ��� ���ڰ� ������ ���� �������� Ȯ��
			if(nStart > 0)
			{
				// �ٷ��� ���ڰ� ���� ���ڶ��
				if(m_strDateFormat.GetAt(nStart - 1) == 'm')
				{
					// ���� 10���� ���� 0�� ���� 1�� ���� ���� ��ȿ ���� �˻��Ѵ�
					if((strText.GetAt(nStart - 1) > '0' && nChar > '2')
						|| (strText.GetAt(nStart - 1) == '0' && nChar == '0'))
					{
						MessageBeep(MB_OK);
						return;
					}
				}
				else
				{
					// �ٷ��� ���ڰ� ���� ���ڰ� �ƴϰ� 2�̻��� ���� �ԷµǾ��� ���
					if(nChar > '1')
					{
						// �켱 0�� �߰��ϰ� �ٽ� ���ڸ� ó���Ѵ�
						strText.Insert(nStart, '0');
						nStart++;
						nEnd++;
						SetWindowText(strText);
						SetSel(nStart, nEnd);
					}
				}
			}
			else
			{
				// �ٷ��� ���ڰ� ���� ���ڰ� �ƴϰ� 2�̻��� ���� �ԷµǾ��� ���
				if(nChar > '1')
				{
					// �켱 0�� �߰��ϰ� �ٽ� ���ڸ� �߰��Ѵ�
					strText.Insert(nStart, '0');
					nStart++;
					nEnd++;
					SetWindowText(strText);
					SetSel(nStart, nEnd);
				}
			}
		}
		// ���� �� �Է� ��ġ���
		if(m_strDateFormat.GetAt(nStart) == 'd')
		{
			// �ٷ��� ���ڰ� �ϼ��� ���� �������� Ȯ��
			if(nStart > 0)
			{
				// �ٷ��� ���ڰ� �ϼ� ���ڶ��
				if(m_strDateFormat.GetAt(nStart - 1) == 'd')
				{
					// ���� 10���� ���� 0,1,2,3�� ���� ���� ��ȿ ���� �˻��Ѵ�
					if((strText.GetAt(nStart - 1) > '2' && nChar > '1')
						|| (strText.GetAt(nStart - 1) == '0' && nChar == '0'))
					{
						MessageBeep(MB_OK);
						return;
					}
				}
				else
				{
					// �ٷ��� ���ڰ� �ϼ� ���ڰ� �ƴϰ� 4�̻��� ���� �ԷµǾ��� ���
					if(nChar > '3')
					{
						// �켱 0�� �߰��ϰ� �ٽ� ���ڸ� ó���Ѵ�
						strText.Insert(nStart, '0');
						nStart++;
						nEnd++;
						SetWindowText(strText);
						SetSel(nStart, nEnd);
					}
				}
			}
			else
			{
				// �ٷ��� ���ڰ� �ϼ� ���ڰ� �ƴϰ� 4�̻��� ���� �ԷµǾ��� ���
				if(nChar > '3')
				{
					strText.Insert(nStart, '0');
					nStart++;
					nEnd++;
					SetWindowText(strText);
					SetSel(nStart, nEnd);
				}
			}
		}
		break;
	case FILTER_TIME:
		// �ð� ����̸�, ĳ���� �ؽ�Ʈ�� ���� ��ġ�ϰ� ���� �ʴٸ�
		// ���� �����Ǿ� ���� �ʰ� ���˿� �°� �Է��� �Ϸ�� �����̰ų� ���ڰ� �ƴϰ� �齺���̽��� �ƴ϶�� ��ȿ
		if(strText.GetLength() != nEnd
			|| (((nStart == nEnd && nEnd >= m_strTimeFormat.GetLength()) || !::isdigit(nChar)) && nChar != VK_BACK))
		{
			MessageBeep(MB_OK);
			return;
		}
		// �齺���̽���� ��ȿ
		if(nChar == VK_BACK)	break;

		// ���� ���̶�� �� �κ��� �����Ѵ�
		if(nStart != nEnd)			strText.Delete(nStart, nEnd - nStart);
		nEnd = nStart;
		// ���� ��ġ���� ��/��/�� �Է� �κб����� ���� ���ڸ� �߰��Ѵ�
		for(; nStart < m_strTimeFormat.GetLength(); nStart++)
		{
			if(m_strTimeFormat.GetAt(nStart) != 'h'
				&& m_strTimeFormat.GetAt(nStart) != 'm'
				&& m_strTimeFormat.GetAt(nStart) != 's')
				strText += m_strTimeFormat.GetAt(nStart);
			else
				break;
		}
		// ���� ���˿� �°� ��� �Է� �Ǿ��� ĳ���� ���ڿ��� ���� �ִٸ�
		if(nStart == m_strTimeFormat.GetLength()
			&& strText.GetLength() == m_strTimeFormat.GetLength())
		{
			// ����/���ĸ� �߰��Ѵ�
			if(m_bAmPm)			strText += " ����";
			else				strText += " ����";
		}
		// ���� ���� ���ڰ� �߰��Ǿ��ٸ�
		if(nStart != nEnd)
		{
			// ĳ���� ��ġ�� ���� �ڷ� �ű�� �켱 ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����Ѵ�
			nEnd = nStart;
			SetWindowText(strText);
			SetSel(nStart, nStart);
		}
		// ���� ���˿� �°� ��� �Էµ� ���¶�� ��ȿ
		if(nStart >= m_strTimeFormat.GetLength())
		{
			MessageBeep(MB_OK);
			return;
		}

		// ���� �ð� �Է� ��ġ���
		if(m_strTimeFormat.GetAt(nStart) == 'h')
		{
			// �ٷ��� ���ڰ� �ð��� ���� �������� Ȯ��
			if(nStart > 0)
			{
				// �ٷ��� ���ڰ� �ð� ���ڶ��
				if(m_strTimeFormat.GetAt(nStart - 1) == 'h')
				{
					// ���� 24�� ǥ����
					if(m_bTime24)
					{
						// �ð��� 10���� ���� 0�� ���� 1�� ���� ���� ��ȿ ���� �˻��Ѵ�
						if(strText.GetAt(nStart - 1) > '1' && nChar > '3')
						{
							MessageBeep(MB_OK);
							return;
						}
					}
					else
					{
						// 24�� ǥ�Ⱑ �ƴ϶�� �ð��� 10���� ���� 0�� ���� 1�� ���� ���� ��ȿ ���� �˻��Ѵ�
						if((strText.GetAt(nStart - 1) == '0' && nChar == '0')
							|| strText.GetAt(nStart - 1) > '0' && nChar > '2')
						{
							MessageBeep(MB_OK);
							return;
						}
					}
				}
				else
				{
					// �ٷ��� ���ڰ� ���� ���ڰ� �ƴϰ� 24�� ǥ����
					if(m_bTime24)
					{
						// 3�̻��� ���� �ԷµǾ��� ���
						if(nChar > '2')
						{
							// �켱 0�� �߰��ϰ� �ٽ� ���ڸ� ó���Ѵ�
							strText.Insert(nStart, '0');
							nStart++;
							nEnd++;
							SetWindowText(strText);
							SetSel(nStart, nEnd);
						}
					}
					else
					{
						// 24�� ǥ�Ⱑ �ƴϰ� 2�̻��� ���� �ԷµǾ��ٸ�
						if(nChar > '1')
						{
							// �켱 0�� �߰��ϰ� �ٽ� ���ڸ� ó���Ѵ�
							strText.Insert(nStart, '0');
							nStart++;
							nEnd++;
							SetWindowText(strText);
							SetSel(nStart, nEnd);
						}
					}
				}
			}
			else
			{
				// �ٷ��� ���ڰ� ���� ���ڰ� �ƴϰ� 24�� ǥ����
				if(m_bTime24)
				{
					// 3�̻��� ���� �ԷµǾ��� ���
					if(nChar > '2')
					{
						// �켱 0�� �߰��ϰ� �ٽ� ���ڸ� ó���Ѵ�
						strText.Insert(nStart, '0');
						nStart++;
						nEnd++;
						SetWindowText(strText);
						SetSel(nStart, nEnd);
					}
				}
				else
				{
					// 24�� ǥ�Ⱑ �ƴϰ� 2�̻��� ���� �ԷµǾ��ٸ�
					if(nChar > '1')
					{
						// �켱 0�� �߰��ϰ� �ٽ� ���ڸ� ó���Ѵ�
						strText.Insert(nStart, '0');
						nStart++;
						nEnd++;
						SetWindowText(strText);
						SetSel(nStart, nEnd);
					}
				}
			}
		}
		// ���� �� �Է� ��ġ���
		if(m_strTimeFormat.GetAt(nStart) == 'm')
		{
			// �ٷ��� ���ڰ� �п� ���� �������� Ȯ��
			if(nStart > 0)
			{
				// �ٷ��� ���ڰ� �� ���ڰ� �ƴ϶��
				if(m_strTimeFormat.GetAt(nStart - 1) != 'm')
				{
					// 6�̻��� ���� �ԷµǾ��� ���
					if(nChar > '5')
					{
						// �켱 0�� �߰��ϰ� �ٽ� ���ڸ� ó���Ѵ�
						strText.Insert(nStart, '0');
						nStart++;
						nEnd++;
						SetWindowText(strText);
						SetSel(nStart, nEnd);
					}
				}
			}
			else
			{
				// 6�̻��� ���� �ԷµǾ��� ���
				if(nChar > '5')
				{
					// �켱 0�� �߰��ϰ� �ٽ� ���ڸ� ó���Ѵ�
					strText.Insert(nStart, '0');
					nStart++;
					nEnd++;
					SetWindowText(strText);
					SetSel(nStart, nEnd);
				}
			}
		}
		// ���� �� �Է� ��ġ���
		if(m_strTimeFormat.GetAt(nStart) == 's')
		{
			// �ٷ��� ���ڰ� �ʿ� ���� �������� Ȯ��
			if(nStart > 0)
			{
				// �ٷ��� ���ڰ� �� ���ڰ� �ƴ϶��
				if(m_strTimeFormat.GetAt(nStart - 1) != 's')
				{
					// 6�̻��� ���� �ԷµǾ��� ���
					if(nChar > '5')
					{
						// �켱 0�� �߰��ϰ� �ٽ� ���ڸ� ó���Ѵ�
						strText.Insert(nStart, '0');
						nStart++;
						nEnd++;
						SetWindowText(strText);
						SetSel(nStart, nEnd);
					}
				}
			}
			else
			{
				// 6�̻��� ���� �ԷµǾ��� ���
				if(nChar > '5')
				{
					// �켱 0�� �߰��ϰ� �ٽ� ���ڸ� ó���Ѵ�
					strText.Insert(nStart, '0');
					nStart++;
					nEnd++;
					SetWindowText(strText);
					SetSel(nStart, nEnd);
				}
			}
		}
		break;
	case FILTER_MASK:
		// ����ũ ����̸�, ĳ���� �ؽ�Ʈ�� ���� ��ġ�ϰ� ���� �ʴٸ�
		// ���˿� �°� �Է��� �Ϸ�� �����̰� �齺���̽��� �ƴ϶�� ��ȿ
		if(strText.GetLength() != nEnd || (nEnd >= m_strMask.GetLength() && nChar != VK_BACK))
		{
			MessageBeep(MB_OK);
			return;
		}
		// �齺���̽���� ��ȿ
		if(nChar == VK_BACK)		break;

		// ���� ���̶�� �� �κ��� �����Ѵ�
		if(nStart != nEnd)			strText.Delete(nStart, nEnd - nStart);
		nEnd = nStart;
		// ���� ��ġ���� ����/���� �Է� �κб����� ���� ���ڸ� �߰��Ѵ�
		for(; nStart < m_strMask.GetLength(); nStart++)
		{
			if(m_strMask.GetAt(nStart) != FILTER_MASK_NUMBER
				&& m_strMask.GetAt(nStart) != FILTER_MASK_ALPHA)
				strText += m_strMask.GetAt(nStart);
			else
				break;
		}
		// ���� ���� ���ڰ� �߰��Ǿ��ٸ�
		if(nStart != nEnd)
		{
			// ĳ���� ��ġ�� ���� �ڷ� �ű�� �켱 ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����Ѵ�
			nEnd = nStart;
			SetWindowText(strText);
			SetSel(nStart, nStart);
		}
		// ���� ���˿� �°� ��� �Էµ� ���¶�� ��ȿ
		if(nStart >= m_strMask.GetLength())
		{
			MessageBeep(MB_OK);
			return;
		}

		// ���� ���� �Է� ��ġ�� ���ڰ� �ƴϰų�
		// ���� �Է� ��ġ�� ���ڰ� �ƴϸ� ��ȿ
		if((m_strMask.GetAt(nStart) != FILTER_MASK_NUMBER || !::isdigit(nChar))
			&& (m_strMask.GetAt(nStart) != FILTER_MASK_ALPHA || !::isalpha(nChar))
			&& nChar != VK_BACK)
		{
			MessageBeep(MB_OK);
			return;
		}
		break;
	default:
		// ���� ��Ÿ ���� ����̰� ���� �����Ǿ� �ִٸ�
		if(nStart != nEnd)
		{
			// �� �κ��� �����Ѵ�
			strText.Delete(nStart, nEnd - nStart);

			// ���� ���ŵ� ���ڵ鿡 �Ҽ����� ���ԵǾ� �ִٸ� �Ҽ����� ���� ������ �ʱ�ȭ
			if(nStart <= m_nDecPointPos && m_nDecPointPos <= nEnd)
				m_nDecPointPos = -1;
		}
		// ���� �齺���̽����
		if(nChar == VK_BACK)
		{
			// ���� �����Ǿ� ���� �ʴٸ�
			if(nStart == nEnd)
			{
				// ĳ���� ���� �տ� ���� �ʴٸ�
				if(nStart > 0)
				{
					// ĳ�� ���� ���ڰ� �Ҽ����̶��
					if(strText.GetAt(nStart - 1) == '.')
						// �Ҽ����� ���� ������ �ʱ�ȭ
						m_nDecPointPos = -1;
				}
				// ���� �Ҽ����� ���� ��ġ�� ���ʿ� �ִٸ� �Ҽ����� ��ġ�� ��ĭ ������ �̵�
				if(nStart <= m_nDecPointPos)	m_nDecPointPos -= 1;
			}
			break;
		}

		// ���� ���˿� �´� ���ڰ� �ƴ϶��
		if(!IsValidChar((char)nChar, nStart, strText.GetLength() - nStart - 1))
		{
			// ���� ��ȣ�� ���� ����̰�, �Էµ� ���ڰ� ��ȣ����('-')�̰�,
			// ���� ���� �Էµ� ���¶��
			if(nChar == '-' && strText.GetLength() > 0 && (m_nType & FILTER_SIGN))
			{
				// ���� ��ȣ�� �ִ� ���¶��
				if(strText.GetAt(0) == '-')
				{
					// ���� ��ȣ�� �����Ѵ�
					strText.Delete(0, 1);

					// ĳ���� ��ġ�� ��ĭ ������ �̵��Ѵ�
					nStart -= 1;
					if(nStart < 0)	nStart = 0;
					nEnd -= 1;
					if(nEnd < 0)	nEnd = 0;
					// �Ҽ����� ��ġ�� ��ĭ ������ �̵��Ѵ�
					if(m_nDecPointPos > 0)			m_nDecPointPos -= 1;
				}
				else
				{
					// ���� ��ȣ�� �߰��Ѵ�
					strText.Insert(0, '-');

					// ĳ���� ��ġ�� ��ĭ �ڷ� �̵��Ѵ�
					nStart += 1;
					nEnd += 1;
					// �Ҽ����� ��ġ�� ��ĭ �ڷ� �̵��Ѵ�
					if(m_nDecPointPos >= 0)			m_nDecPointPos += 1;
				}

				// ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����ϰ� ĳ�� ��ġ�� �����Ѵ�
				SetWindowText(strText);
				SetSel(nStart, nEnd);
			}
			else
				// ��ȿ ó���Ѵ�
				MessageBeep(MB_OK);
			return;
		}

		// ���� ���� �����Ǿ� ���� �ʰ� �Ҽ����� ���� ��ġ ���Ŀ� �ִٸ�
		if(nStart == nEnd && nStart <= m_nDecPointPos)
			// �Ҽ����� ��ġ�� ��ĭ �ڷ� �ű��
			m_nDecPointPos += 1;

		// ���� �Ҽ����� ǥ�õ� �� �ְ� �Ҽ����� ù ��ġ�� �ִٸ�
		if((m_nType & FILTER_DECIMALPOINT) && m_nDecPointPos == 0)
		{
			// �Ҽ����� ��ġ�� ��ĭ �ڷ� �̵��ϰ�
			m_nDecPointPos += 1;
			// �Ҽ��� �տ� 0�� �����δ�
			strText.Insert(0, "0");
			SetWindowText(strText);
			SetSel(nStart + 1, nStart + 1);
		}
		break;
	}

	// ���ڸ� �߰��Ѵ�
	CEdit::OnChar(nChar, nRepCnt, nFlags);

	// ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �ٽ� �д´�
	GetWindowText(strText);
	// ĳ���� ��ġ�� �ٽ� �д´�
	GetSel(nStart, nEnd);

	switch(m_nType)
	{
	case FILTER_CURRENCY:
		// ���� ȭ�� �����
		{
			// ','�� �ٽ� ��� ���� ���ڿ��� �ٽ� Ȯ���Ѵ�
			CString strOutput;
			int nNewStart = CheckCurrency(strText, strOutput, nStart);

			// ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����ϰ� ���� ĳ���� ��ġ�� �����Ѵ�
			SetWindowText(strOutput);
			nNewStart	-= nStart;
			nStart		+= nNewStart;
			nEnd		+= nNewStart;

			SetSel(nStart, nEnd);
		}
		break;
	case FILTER_DATE:
		// ���� ��¥ �����
		// �齺���̽��� �Էµ� ���°� �ƴ϶��
		if(nChar != VK_BACK)
		{
			// ���� ĳ�� ��ġ ���ķ� ���� ���ڵ��� �߰��Ѵ�
			for(; nStart < m_strDateFormat.GetLength() && nChar != VK_BACK; nStart++)
			{
				if(m_strDateFormat.GetAt(nStart) != 'y'
					&& m_strDateFormat.GetAt(nStart) != 'm'
					&& m_strDateFormat.GetAt(nStart) != 'd')
					strText += m_strDateFormat.GetAt(nStart);
				else
					break;
			}
			// ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����ϰ� ���� ĳ���� ��ġ�� �����Ѵ�
			SetWindowText(strText);
			SetSel(nStart, nStart);
		}
		break;
	case FILTER_TIME:
		// ���� �ð� �����
		// �齺���̽��� �Էµ� ���°� �ƴ϶��
		if(nChar != VK_BACK)
		{
			// ���� ĳ�� ��ġ ���ķ� ���� ���ڵ��� �߰��Ѵ�
			for(; nStart < m_strTimeFormat.GetLength(); nStart++)
			{
				if(m_strTimeFormat.GetAt(nStart) != 'h'
					&& m_strTimeFormat.GetAt(nStart) != 'm'
					&& m_strTimeFormat.GetAt(nStart) != 's')
					strText += m_strTimeFormat.GetAt(nStart);
				else
					break;
			}
			// ���� ���˿� ���� ��� �ԷµǾ��� ĳ���� �ؽ�Ʈ ���� �ִٸ�
			if(nStart == m_strTimeFormat.GetLength()
				&& strText.GetLength() == m_strTimeFormat.GetLength())
			{
				// ����/���ĸ� �߰��Ѵ�
				if(m_bAmPm)			strText += " ����";
				else				strText += " ����";
			}
			// ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����ϰ� ���� ĳ���� ��ġ�� �����Ѵ�
			SetWindowText(strText);
			SetSel(nStart, nStart);
		}
		break;
	case FILTER_MASK:
		// ���� ����ũ �����
		// �齺���̽��� �Էµ� ���°� �ƴ϶��
		if(nChar != VK_BACK)
		{
			// ���� ĳ�� ���ķ� ���� ���ڵ��� �߰��Ѵ�
			for(; nStart < m_strMask.GetLength(); nStart++)
			{
				if(m_strMask.GetAt(nStart) != FILTER_MASK_NUMBER
					&& m_strMask.GetAt(nStart) != FILTER_MASK_ALPHA)
					strText += m_strMask.GetAt(nStart);
				else
					break;
			}
			// ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����ϰ� ���� ĳ���� ��ġ�� �����Ѵ�
			SetWindowText(strText);
			SetSel(nStart, nStart);
		}
		break;
	}
}

// ����Ʈ ��Ʈ���� �ؽ�Ʈ�� ����� ��� ȣ��Ǵ� �Լ�
LRESULT CFilterEdit::OnSetText(UINT wParam, LONG lParam)
{
	// ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����Ѵ�
	LRESULT nReturn = CEdit::Default();

	// ���� ������ �ؽ�Ʈ�� ���� ��ȿ�� �˻縦 �Ѵ�
	CString strText, strValid;
	
	GetWindowText(strText);

	switch(m_nType)
	{
	case FILTER_CURRENCY:
		CheckCurrency(strText, strValid, 0);
		break;
	case FILTER_DATE:
		CheckDate(strText, strValid, 0);
		break;
	case FILTER_TIME:
		CheckTime(strText, strValid, 0);
		break;
	case FILTER_MASK:
		CheckFormat(strText, strValid, 0);
		break;
	default:
		CheckText(strText, strValid);
		break;
	}

	// ���� ���� ������ �ؽ�Ʈ�� ��ȿ�� ���ڿ��� Ʋ���ٸ�
	if(strText != strValid)
	{
		// ����Ʈ ��Ʈ���� �ؽ�Ʈ�� ��ȿ�� ���ڿ��� �����Ѵ�
		SetWindowText(strValid);
	}
	return nReturn;
}

void CFilterEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CString strText, strValid;
	CString strValue, strFormat;
	int nStart, nEnd, nValue;
	char ch;

	// ���� ĳ�� ��ġ�� �ؽ�Ʈ�� ��´�
	GetSel(nStart, nEnd);
	GetWindowText(strText);

	switch(nChar)
	{
	case VK_DELETE:
		// ���� DELETE Ű�� �������ٸ�
		// ��¥/�ð�/����ũ ����̰� ĳ���� �� ���ڿ� ���� �ʴٸ� ��ȿ
		if((m_nType & (FILTER_DATE | FILTER_TIME | FILTER_MASK))
			&& (nEnd < strText.GetLength() - 1))
		{
			MessageBeep(MB_OK);
			return;
		}
		break;
	case VK_UP:
		// ���� �� ����Ű�� �������ٸ�
		// ��¥ ����̸�
		if(m_nType == FILTER_DATE)
		{
			// ���� ��ġ�� ���ڿ� �����̸�
			if(nStart < m_strDateFormat.GetLength() && nStart < strText.GetLength())
			{
				// ���˿����� ���� ���ڰ� ��/��/�� ���ڶ��
				ch = m_strDateFormat.GetAt(nStart);
				if(ch == 'y' || ch == 'm' || ch == 'd')
				{
					// �ش� ������ ������ ã�´�
					for(; nStart >= 0; nStart--)
					{
						if(m_strDateFormat.GetAt(nStart) != ch)
							break;
					}
					nStart += 1;
					// �ش� ������ ���� ã�´�
					for(nEnd = nStart; nEnd < m_strDateFormat.GetLength(); nEnd++)
					{
						if(m_strDateFormat.GetAt(nEnd) != ch)
							break;
						// �ش� ������ ��ġ�� �ִ� �Է� ���� ������
						strValue += strText.GetAt(nEnd);
					}

					// �Էµ� ���� ���ڷ� �ٲ۴�
					nValue = ::atoi(strValue);
					// �Էµ� ���̿� ���� ������ �����
					strFormat.Format("%%0%dd", nEnd - nStart);
					// ���� 1 ������Ų��
					nValue += 1;

					switch(ch)
					{
					case 'y':
						// ������� 10������ �ʰ����� �ʵ��� �����Ѵ�
						nValue %= (int)pow(10, strValue.GetLength());
						break;
					case 'm':
						// �����̰� ���̰� 2�̻��̸�
						if(strValue.GetLength() > 1)
						{
							// 12�� �ʰ����� �ʵ��� �����Ѵ�
							nValue %= 13;
							// 0�̸� 1�� �����Ѵ�
							if(nValue == 0)	nValue = 1;
						}
						else
						{
							// 2�̻��̸� 0���� �����Ѵ�
							if(nValue > 1)	nValue = 0;
						}
						break;
					case 'd':
						// �ϼ��̰� ���̰� 2�̻��̸�
						if(strValue.GetLength() > 1)
						{
							// 31�� �ʰ����� �ʵ��� �����Ѵ�
							nValue %= 32;
							// 0�̸� 1�� �����Ѵ�
							if(nValue == 0) nValue = 1;
						}
						else
						{
							// 4�̻��̸� 0���� �����Ѵ�
							if(nValue > 3)	nValue = 0;
						}
						break;
					}

					// ���ڸ� ���ڿ��� �����Ѵ�
					strValue.Format(strFormat, nValue);
					// �ش� ������ �����Ѵ�
					strText.Delete(nStart, nEnd - nStart);
					// �� ���ڿ��� �����Ѵ�
					strText.Insert(nStart, strValue);

					// ���ο� �ؽ�Ʈ�� �����ϰ� ĳ�� ��ġ�� �����Ѵ�
					SetWindowText(strText);
					SetSel(nStart, nEnd);
					return;
				}
			}
		}
		// �ð� ����̸�
		if(m_nType == FILTER_TIME)
		{
			// ���� ��ġ�� ���ڿ� �����̰� 24�� ǥ�Ⱑ �ƴϸ�
			if(nStart < strText.GetLength() && !m_bTime24)
			{
				// ���� ��ġ�� ���� ���ڿ����� �ڿ� �ִٸ�
				if(nStart > m_strTimeFormat.GetLength())
				{
					// ���� ���ڿ� ���� ������ ���ڵ��� �����Ѵ�
					strText.Delete(m_strTimeFormat.GetLength(),
						strText.GetLength() - m_strTimeFormat.GetLength());
					// ����/���ĸ� �ٲٰ� ���ڿ��� �����δ�
					m_bAmPm = !m_bAmPm;
					if(m_bAmPm)		strText += " ����";
					else			strText += " ����";

					// ���ο� �ؽ�Ʈ�� �����ϰ� ĳ�� ��ġ�� �����Ѵ�
					SetWindowText(strText);
					SetSel(m_strTimeFormat.GetLength() + 1, strText.GetLength());
					return;
				}
			}
			// ���� ���ڿ� ���� �ȿ� �ִٸ�
			if(nStart < m_strTimeFormat.GetLength())
			{
				// ���˿����� ���� ���ڰ� ��/��/�� ���ڶ��
				ch = m_strTimeFormat.GetAt(nStart);
				if(ch == 'h' || ch == 'm' || ch == 's')
				{
					// �ش� ������ ������ ã�´�
					for(; nStart >= 0; nStart--)
					{
						if(m_strTimeFormat.GetAt(nStart) != ch)
							break;
					}
					nStart += 1;
					// �ش� ������ ���� ã�´�
					for(nEnd = nStart; nEnd < m_strTimeFormat.GetLength(); nEnd++)
					{
						if(m_strTimeFormat.GetAt(nEnd) != ch)
							break;
						// �ش� ������ ��ġ�� �ִ� �Է� ���� ������
						strValue += strText.GetAt(nEnd);
					}

					// �Էµ� ���� ���ڷ� �ٲ۴�
					nValue = ::atoi(strValue);
					// �Էµ� ���̿� ���� ������ �����
					strFormat.Format("%%0%dd", nEnd - nStart);
					// ���� 1 ������Ų��
					nValue += 1;

					switch(ch)
					{
					case 'h':
						// �ð� �����̰� 24�� ǥ����
						if(m_bTime24)
						{
							// ���̰� 2�̻��̸�
							if(strValue.GetLength() > 1)
							{
								// 23�� �ʰ����� �ʵ��� �����Ѵ�
								nValue %= 24;
							}
							else
							{
								// 3�̻��̸� 0���� �����Ѵ�
								if(nValue > 2) nValue = 0;
							}
						}
						else
						{
							// ���̰� 2�̻��̸�
							if(strValue.GetLength() > 1)
							{
								// 12�� �ʰ����� �ʵ��� �����Ѵ�
								nValue %= 13;
								// 0�̸� 1�� �����Ѵ�
								if(nValue == 0)	nValue = 1;
							}
							else
							{
								// 2�̻��̸� 0���� �����Ѵ�
								if(nValue > 1) nValue = 0;
							}
						}
						break;
					case 'm':
					case 's':
						// ��/�� ���ڶ��
						if(strValue.GetLength() > 1)
						{
							// 59�� �ʰ����� �ʵ��� �����Ѵ�
							nValue %= 60;
						}
						else
						{
							// 6�̻��̸� 0���� �����Ѵ�
							if(nValue > 6)	nValue = 0;
						}
						break;
					}

					// ���ڸ� ���ڿ��� �����Ѵ�
					strValue.Format(strFormat, nValue);
					// �ش� ������ �����Ѵ�
					strText.Delete(nStart, nEnd - nStart);
					// �� ���ڿ��� �����Ѵ�
					strText.Insert(nStart, strValue);

					// ���ο� �ؽ�Ʈ�� �����ϰ� ĳ�� ��ġ�� �����Ѵ�
					SetWindowText(strText);
					SetSel(nStart, nEnd);
					return;
				}
			}
		}
		// ��Ÿ�̸� ���� ����Ű�� �����Ѵ�
		nChar = VK_LEFT;
		break;
	case VK_DOWN:
		// ���� �Ʒ� ����Ű�� �������ٸ�
		// ��¥ ����̸�
		if(m_nType == FILTER_DATE)
		{
			// ���� ��ġ�� ���ڿ� �����̸�
			if(nStart < m_strDateFormat.GetLength() && nStart < strText.GetLength())
			{
				// ���˿����� ���� ���ڰ� ��/��/�� ���ڶ��
				ch = m_strDateFormat.GetAt(nStart);
				if(ch == 'y' || ch == 'm' || ch == 'd')
				{
					// �ش� ������ ������ ã�´�
					for(; nStart >= 0; nStart--)
					{
						if(m_strDateFormat.GetAt(nStart) != ch)
							break;
					}
					nStart += 1;
					// �ش� ������ ���� ã�´�
					for(nEnd = nStart; nEnd < m_strDateFormat.GetLength(); nEnd++)
					{
						if(m_strDateFormat.GetAt(nEnd) != ch)
							break;
						// �ش� ������ ��ġ�� �ִ� �Է� ���� ������
						strValue += strText.GetAt(nEnd);
					}

					// �Էµ� ���� ���ڷ� �ٲ۴�
					nValue = ::atoi(strValue);
					// �Էµ� ���̿� ���� ������ �����
					strFormat.Format("%%0%dd", nEnd - nStart);
					
					// ���� 1 ���ҽ�Ų��
					nValue -= 1;
					switch(ch)
					{
					case 'y':
						// ������� ������� ���̸�ŭ�� 9������ �����Ѵ�
						if(nValue < 0)	nValue = (int)pow(10, strValue.GetLength()) - 1;
						break;
					case 'm':
						// �����̰� ���̰� 2�̻��̸�
						if(strValue.GetLength() > 1)
						{
							// 0�̸� 12�� �����Ѵ�
							if(nValue == 0)	nValue = 12;
						}
						else
						{
							// 0���� ������ 1�� �����Ѵ�
							if(nValue < 0)	nValue = 1;
						}
						break;
					case 'd':
						// �ϼ��̰� ���̰� 2�̻��̸�
						if(strValue.GetLength() > 1)
						{
							// 0�̸� 31�� �����Ѵ�
							if(nValue == 0) nValue = 31;
						}
						else
						{
							// 0���� ������ 3���� �����Ѵ�
							if(nValue < 0)	nValue = 3;
						}
						break;
					}

					// ���ڸ� ���ڿ��� �����Ѵ�
					strValue.Format(strFormat, nValue);
					// �ش� ������ �����Ѵ�
					strText.Delete(nStart, nEnd - nStart);
					// �� ���ڿ��� �����Ѵ�
					strText.Insert(nStart, strValue);

					// ���ο� �ؽ�Ʈ�� �����ϰ� ĳ�� ��ġ�� �����Ѵ�
					SetWindowText(strText);
					SetSel(nStart, nEnd);
					return;
				}
			}
		}
		// �ð� ����̸�
		if(m_nType == FILTER_TIME)
		{
			// ���� ��ġ�� ���ڿ� �����̰� 24�� ǥ�Ⱑ �ƴϸ�
			if(nStart < strText.GetLength() && !m_bTime24)
			{
				// ���� ��ġ�� ���� ���ڿ����� �ڿ� �ִٸ�
				if(nStart > m_strTimeFormat.GetLength())
				{
					// ���� ���ڿ� ���� ������ ���ڵ��� �����Ѵ�
					strText.Delete(m_strTimeFormat.GetLength(),
						strText.GetLength() - m_strTimeFormat.GetLength());
					// ����/���ĸ� �ٲٰ� ���ڿ��� �����δ�
					m_bAmPm = !m_bAmPm;
					if(m_bAmPm)		strText += " ����";
					else			strText += " ����";

					// ���ο� �ؽ�Ʈ�� �����ϰ� ĳ�� ��ġ�� �����Ѵ�
					SetWindowText(strText);
					SetSel(m_strTimeFormat.GetLength() + 1, strText.GetLength());
					return;
				}
			}
			// ���� ���ڿ� ���� �ȿ� �ִٸ�
			if(nStart < m_strTimeFormat.GetLength())
			{
				// ���˿����� ���� ���ڰ� ��/��/�� ���ڶ��
				ch = m_strTimeFormat.GetAt(nStart);
				if(ch == 'h' || ch == 'm' || ch == 's')
				{
					// �ش� ������ ������ ã�´�
					for(; nStart >= 0; nStart--)
					{
						if(m_strTimeFormat.GetAt(nStart) != ch)
							break;
					}
					nStart += 1;
					// �ش� ������ ���� ã�´�
					for(nEnd = nStart; nEnd < m_strTimeFormat.GetLength(); nEnd++)
					{
						if(m_strTimeFormat.GetAt(nEnd) != ch)
							break;
						// �ش� ������ ��ġ�� �ִ� �Է� ���� ������
						strValue += strText.GetAt(nEnd);
					}

					// �Էµ� ���� ���ڷ� �ٲ۴�
					nValue = ::atoi(strValue);
					// �Էµ� ���̿� ���� ������ �����
					strFormat.Format("%%0%dd", nEnd - nStart);
					// ���� 1 ���ҽ�Ų��
					nValue -= 1;

					switch(ch)
					{
					case 'h':
						// �ð� �����̰� 24�� ǥ����
						if(m_bTime24)
						{
							// ���̰� 2�̻��̸�
							if(strValue.GetLength() > 1)
							{
								// 0���� �۴ٸ� 23���� �����Ѵ�
								if(nValue < 0)	nValue = 23;
							}
							else
							{
								// 0���� �۴ٸ� 2�� �����Ѵ�
								if(nValue < 0)	nValue = 2;
							}
						}
						else
						{
							// ���̰� 2�̻��̸�
							if(strValue.GetLength() > 1)
							{
								// 0�̸� 12�� �����Ѵ�
								if(nValue == 0)	nValue = 12;
							}
							else
							{
								// 0�̸� 1�� �����Ѵ�
								if(nValue == 0) nValue = 1;
							}
						}
						break;
					case 'm':
					case 's':
						// ��/�� ���ڶ��
						if(strValue.GetLength() > 1)
						{
							// 0���� �۴ٸ� 59�� �����Ѵ�
							if(nValue < 0)	nValue = 59;
						}
						else
						{
							// 0���� �۴ٸ� 5�� �����Ѵ�
							if(nValue < 0)	nValue = 5;
						}
						break;
					}

					// ���ڸ� ���ڿ��� �����Ѵ�
					strValue.Format(strFormat, nValue);
					// �ش� ������ �����Ѵ�
					strText.Delete(nStart, nEnd - nStart);
					// �� ���ڿ��� �����Ѵ�
					strText.Insert(nStart, strValue);

					// ���ο� �ؽ�Ʈ�� �����ϰ� ĳ�� ��ġ�� �����Ѵ�
					SetWindowText(strText);
					SetSel(nStart, nEnd);
					return;
				}
			}
		}
		// ��Ÿ�̸� ������ ����Ű�� �����Ѵ�
		nChar = VK_RIGHT;
		break;
	}

	// Ű�� ó���Ѵ�
	CEdit::OnKeyDown(nChar, nRepCnt, nFlags);

	// ���� DELETE Ű�� ������ ȭ�� �����
	if((nChar == VK_DELETE) && (m_nType & FILTER_CURRENCY))
	{
		// ���� ĳ�� ��ġ�� �ؽ�Ʈ�� �ٽ� ���Ѵ�
		GetSel(nStart, nEnd);
		GetWindowText(strText);

		// ','�� �ٽ� ��� ���� ���ڿ��� �ٽ� Ȯ���Ѵ�
		nStart = CheckCurrency(strText, strValid, nStart);

		// �ؽ�Ʈ�� ��ȿ ���ڿ��� Ʋ���ٸ�
		if(strText != strValid)
		{
			// ����Ʈ ��Ʈ���� �ؽ�Ʈ�� �����ϰ� ���� ĳ���� ��ġ�� �����Ѵ�
			SetWindowText(strValid);
			SetSel(nStart, nStart);
		}
	}
}

// �߶󳻱�
LONG CFilterEdit::OnCut(UINT, LONG)
{
	// ���� ���� ��ġ�� ��´�
	int nStart, nEnd;
	GetSel(nStart, nEnd);

	// ���� �����Ǿ� �ִٸ�
	if(nStart < nEnd)
	{
		// ���� ���� Ŭ�����忡 �����Ѵ�
		SendMessage(WM_COPY);
		// DELETE Ű�� ���� ��ó�� �����Ѵ�
		SendMessage(WM_KEYDOWN, VK_DELETE);
	}

	return 0;
}
	
// ����
LONG CFilterEdit::OnClear(UINT wParam, LONG lParam)
{
	// ���� ���� ��ġ�� ��´�
	int nStart, nEnd;
	GetSel(nStart, nEnd);

	// ���� �����Ǿ� �ִٸ�
	if(nStart < nEnd)
		// DELETE Ű�� ���� ��ó�� �����Ѵ�
		SendMessage(WM_KEYDOWN, VK_DELETE); // delete the selection

	return 0;
}

// �ٿ��ֱ�
LRESULT CFilterEdit::OnPaste(UINT, LONG)
{
	// ���� ���� ��ġ�� ��´�
	int nStart, nEnd;
	GetSel(nStart, nEnd);

	// �ٿ��ֱ⸦ �����Ѵ�
	LRESULT nReturn = CEdit::Default();

	// ���� ������ �ؽ�Ʈ�� ���� ��ȿ�� �˻縦 �Ѵ�
	CString strText, strValid;
	GetWindowText(strText);

	switch(m_nType)
	{
	case FILTER_CURRENCY:
		CheckCurrency(strText, strValid, 0);
		break;
	case FILTER_DATE:
		CheckDate(strText, strValid, 0);
		break;
	case FILTER_TIME:
		CheckTime(strText, strValid, 0);
		break;
	case FILTER_MASK:
		CheckFormat(strText, strValid, 0);
		break;
	default:
		CheckText(strText, strValid);
		break;
	}

	// ���� ���� ������ �ؽ�Ʈ�� ��ȿ�� ���ڿ��� Ʋ���ٸ�
	if(strText != strValid)
	{
		// ����Ʈ ��Ʈ���� �ؽ�Ʈ�� ��ȿ�� ���ڿ��� �����Ѵ�
		SetWindowText(strValid);
		SetSel(nStart, nEnd);
	}

	return nReturn;
}
