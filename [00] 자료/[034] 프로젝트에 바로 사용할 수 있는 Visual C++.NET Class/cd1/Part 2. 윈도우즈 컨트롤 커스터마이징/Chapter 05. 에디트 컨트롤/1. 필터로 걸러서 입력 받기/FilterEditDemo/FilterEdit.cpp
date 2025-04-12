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
	// 초기값 설정
	m_clrText	= RGB(0, 0, 0);
	m_clrBkgnd	= RGB(255, 255, 255);
	m_brsBkgnd.CreateSolidBrush(m_clrBkgnd);

	m_nType				= FILTER_NUMBER;
	m_nDecPointPos		= -1;

	m_strDateFormat		= "yyyy년 mm월 dd일";
	m_strTimeFormat		= "hh시 mm분 ss초";
	m_bTime24			= FALSE;
	m_bAmPm				= TRUE;

	// 시스템의 기본 화폐 문자를 획득한다
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

// 텍스트 색상 설정 함수
void CFilterEdit::SetTextColor(COLORREF clrText)
{
	m_clrText = clrText;
	if(::IsWindow(m_hWnd))	Invalidate();
}

// 배경 색상 설정 함수
void CFilterEdit::SetBkgndColor(COLORREF clrBkgnd)
{
	if(m_clrBkgnd == clrBkgnd)	return;

	// 새로운 색상에 대한 브러쉬를 생성한다
	m_clrBkgnd = clrBkgnd;
	if(m_brsBkgnd.m_hObject)	m_brsBkgnd.DeleteObject();
	m_brsBkgnd.CreateSolidBrush(m_clrBkgnd);

	if(::IsWindow(m_hWnd))	Invalidate();
}

// 에디트 컨트롤에 대한 그리기 속성 설정
HBRUSH CFilterEdit::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	pDC->SetTextColor(m_clrText);
	pDC->SetBkColor(m_clrBkgnd);

	return m_brsBkgnd;
}

// 필터 모드를 설정하는 함수
int CFilterEdit::SetFormat(int nFormat, BOOL bEraseAll)
{
	// 필터 모드를 설정
	m_nType = nFormat;

	if(bEraseAll)
	{
		SetWindowText("");
		return m_nType;
	}

	// 현재 텍스트에 대해 유효성 검사를 실행한다
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

// 필터 모드를 마스크로 설정하고 마스크 포맷을 설정하는 함수
int CFilterEdit::SetFormat(LPCTSTR pFormat, BOOL bEraseAll)
{
	// 필터 모드를 마스크로 설정
	m_nType = FILTER_MASK;

	// 마스크 포맷 문자열을 저장
	m_strMask = pFormat;

	if(bEraseAll)
	{
		SetWindowText("");
		return m_nType;
	}

	// 현재 텍스트에 대해 유효성 검사를 실행한다
	CString strText, strValid;
	GetWindowText(strText);

	CheckFormat(strText, strValid, 0);

	SetWindowText(strValid);

	return m_nType;
}

// 필터 모드를 날짜로 설정하고 날짜 포맷을 설정하는 함수
int CFilterEdit::SetDateFormat(LPCTSTR pFormat, BOOL bEraseAll)
{
	// 필터 모드를 날짜로 설정
	m_nType = FILTER_DATE;

	// 날짜 포맷 문자열을 저장
	m_strDateFormat = pFormat;

	if(bEraseAll)
	{
		SetWindowText("");
		return m_nType;
	}

	// 현재 텍스트에 대해 유효성 검사를 실행한다
	CString strText, strValid;
	GetWindowText(strText);

	CheckDate(strText, strValid, 0);

	SetWindowText(strValid);

	return m_nType;
}

// 필터 모드를 시간으로 설정하고 시간 포맷을 설정하는 함수
int CFilterEdit::SetTimeFormat(LPCTSTR pFormat, BOOL bTime24, BOOL bEraseAll)
{
	// 필터 모드를 시간으로 설정
	m_nType = FILTER_TIME;

	// 시간 포맷 문자열을 저장
	m_strTimeFormat = pFormat;
	m_bTime24		= bTime24;
	m_bAmPm			= TRUE;

	if(bEraseAll)
	{
		SetWindowText("");
		return m_nType;
	}

	// 현재 텍스트에 대해 유효성 검사를 실행한다
	CString strText, strValid;
	GetWindowText(strText);

	CheckTime(strText, strValid, 0);

	SetWindowText(strValid);

	return m_nType;
}

// 화폐/날짜/시간/마스크를 제외한 필터 모드에서 한 문자의 유효성을 검사하는 함수
inline BOOL CFilterEdit::IsValidChar(char ch, int n, int nRemain)
{
	// 만약 필터가 없다면 유효
	if(m_nType == FILTER_NONE)		return TRUE;

	// 만약 필터에 숫자가 포함되어 있다면
	if(m_nType & FILTER_NUMBER)
	{
		// 숫자일 경우 유효
		if(::isdigit(ch))			return TRUE;
	}

	// 만약 필터에 부호가 포함되어 있다면
	if(m_nType & FILTER_SIGN)
	{
		// 부호 문자일 경우 유효
		if(ch == '-')
		{
			if(n == 0)				return TRUE;
			else					return FALSE;
		}
	}

	// 만약 필터에 소수점이 포함되어 있다면
	if(m_nType & FILTER_DECIMALPOINT)
	{
		// 소수점일 경우
		if(ch == '.')
			// 아직 소수점이 설정되지 않았다면 유효
			if(m_nDecPointPos < 0)
			{
				// 소수점 위치 저장
				m_nDecPointPos = n;
				return TRUE;
			}
			else
				return FALSE;
	}

	// 만약 필터에 알파벳 대문자가 포함되어 있다면
	if(m_nType & FILTER_UPPERCASE)
	{
		// 대문자일 경우 유효
		if(::isupper(ch))			return TRUE;
	}

	// 만약 필터에 알파벳 소문자가 포함되어 있다면
	if(m_nType & FILTER_LOWERCASE)
	{
		// 소문자일 경우 유효
		if(::islower(ch))			return TRUE;
	}

	// 기타의 경우 무효
	return FALSE;
}

// 화폐/날짜/시간/마스크를 제외한 필터 모드에서 문자열의 유효성을 검사하는 함수
void CFilterEdit::CheckText(CString &strInput, CString &strOutput)
{
	// 소수점은 없는 것으로 초기화
	m_nDecPointPos = -1;

	strOutput.Empty();

	int nLength = strInput.GetLength(), i;

	// 문자열의 길이만큼 루프를 돌면서 각 문자를 검사한다
	for(i = 0; i < nLength; i++)
	{
		if(IsValidChar(strInput.GetAt(i), i, nLength - i - 1))
			// 유효한 문자들만으로 문자열을 구성한다
			strOutput += strInput.GetAt(i);
	}

	// 만약 소수점을 가질 수 있고 소수점이 첫번째 문자라면
	if((m_nType & FILTER_DECIMALPOINT) && m_nDecPointPos == 0)
		// 소수점 앞에 0을 추가한다
		strOutput.Insert(0, "0");
}

// 화폐 모드에서 문자열의 유효성을 검사하는 함수
int CFilterEdit::CheckCurrency(CString &strInput, CString &strOutput, int nPos)
{
	// 소수점은 없는 것으로 초기화
	m_nDecPointPos = -1;

	strOutput.Empty();

	// 화폐 모드가 아니라면 리턴
	if(!(m_nType & FILTER_CURRENCY))		return 0;

	int nLength = strInput.GetLength(), i, nTerm = 0;

	// 문자열의 길이만큼 루프를 돌면서 각 문자를 검사한다
	for(i = 0; i < nLength; i++)
	{
		// 만약 숫자라면
		if(::isdigit(strInput.GetAt(i)))
			// 문자열에 추가
			strOutput += strInput.GetAt(i);
		else
			// 숫자가 아니면 추가하지 않고
			// 만약 현재 캐럿 위치보다 앞에 있다면 갯수를 증가시킨다
			if(nPos > i)	nTerm++;
	}
	// 현재 캐럿 위치인 nPos를 조정한다
	nPos -= nTerm;

	// 문자열에 대해 오른쪽부터 세자리마다 ','를 추가한다
	nLength = strOutput.GetLength();
	for(i = nLength % 3; i < nLength; i += 3)
	{
		if(i == 0) continue;

		strOutput.Insert(i, ',');
		if(nPos >= i)	nPos += 1;
		nLength += 1;
		i += 1;
	}

	// 문자열의 앞에 화폐 문자를 추가한다
	strOutput.Insert(0, m_strCurrency);

	// 화폐 문자만큼 캐럿 위치를 조정한다
	nPos += m_strCurrency.GetLength();

	return nPos;
}

// 날짜 모드에서 문자열의 유효성을 검사하는 함수
int CFilterEdit::CheckDate(CString &strInput, CString &strOutput, int nPos)
{
	// 소수점은 없는 것으로 초기화
	m_nDecPointPos = -1;

	strOutput.Empty();

	// 날짜 모드가 아니라면 리턴
	if(!(m_nType & FILTER_DATE))		return 0;

	int nLength = strInput.GetLength(), i;
	int nFormat = m_strDateFormat.GetLength();
	int nStart, nDate;
	CString strNum, strFormat;
	char ch;

	// 문자열의 길이만큼 루프를 돌면서 날짜 포맷 문자를 검사한다
	for(i = 0; i < nLength && i < nFormat; i++)
	{
		switch(m_strDateFormat.GetAt(i))
		{
		// 만약 연수 입력 자리라면
		case 'y':
		// 만약 월수 입력 자리라면
		case 'm':
		// 만약 일수 입력 자리라면
		case 'd':
			ch = m_strDateFormat.GetAt(i);

			nStart = i;
			strNum.Empty();
			// 날짜 포맷에서 해당 문자의 끝을 찾는다
			for(; i < nLength && i < nFormat; i++)
			{
				if(m_strDateFormat.GetAt(i) != ch)	break;
				// 해당 문자의 위치에 있는 입력 값을 문자열에 모은다
				strNum += strInput.GetAt(i);
			}
			// 입력된 문자열을 숫자로 바꾼다
			nDate = ::atoi(LPCTSTR(strNum));

			switch(ch)
			{
			case 'y':
				// 연수가 음수라면 양수로 바꾼다
				if(nDate < 0)		nDate *= -1;
				break;
			case 'm':
				// 월수가 음수라면 양수로 바꾼다
				if(nDate < 0)		nDate *= -1;
				// 월수가 12를 초과한다면 12로 바꾼다
				if(nDate > 12)		nDate = 12;
				// 월수가 0이고 두자리 이상이 입력 되었다면 1로 바꾼다
				if(nDate == 0 && strNum.GetLength() > 1)		nDate = 1;
				break;
			case 'd':
				// 일수가 음수라면 양수로 바꾼다
				if(nDate < 0)		nDate *= -1;
				// 일수가 31을 초과한다면 31로 바꾼다
				if(nDate > 31)		nDate = 31;
				// 일수가 0이고 두자리 이상이 입력 되었다면 1로 바꾼다
				if(nDate == 0 && strNum.GetLength() > 1)		nDate = 1;
				break;
			}

			// 문자열의 길이만큼의 숫자 포맷을 만든다
			strFormat.Format("%%0%dd", i - nStart);
			// 숫자를 문자열로 바꾼다
			strNum.Format(strFormat, nDate);
			// 출력 문자열에 추가한다
			strOutput += strNum;
			i -= 1;
			break;
		default:
			// 연/월/일 문자가 아니라면 포맷 문자를 출력 문자열에 추가한다
			strOutput += m_strDateFormat.GetAt(i);
			break;
		}
	}

	return nPos;
}

int CFilterEdit::CheckTime(CString &strInput, CString &strOutput, int nPos)
{
	// 소수점은 없는 것으로 초기화
	m_nDecPointPos = -1;

	strOutput.Empty();

	// 시간 모드가 아니라면 리턴
	if(!(m_nType & FILTER_TIME))		return 0;

	int nLength = strInput.GetLength(), i;
	int nFormat = m_strTimeFormat.GetLength();
	int nStart, nTime;
	CString strNum, strFormat;
	char ch;

	// 문자열의 길이만큼 루프를 돌면서 시간 포맷 문자를 검사한다
	for(i = 0; i < nLength && i < nFormat; i++)
	{
		switch(m_strTimeFormat.GetAt(i))
		{
		// 만약 시간 입력 자리라면
		case 'h':
		// 만약 분 입력 자리라면
		case 'm':
		// 만약 초 입력 자리라면
		case 's':
			ch = m_strTimeFormat.GetAt(i);

			nStart = i;
			strNum.Empty();
			// 시간 포맷에서 해당 문자의 끝을 찾는다
			for(; i < nLength && i < nFormat; i++)
			{
				if(m_strTimeFormat.GetAt(i) != ch)	break;
				// 해당 문자의 위치에 있는 입력 값을 문자열에 모은다
				strNum += strInput.GetAt(i);
			}
			// 입력된 문자열을 숫자로 바꾼다
			nTime = ::atoi(LPCTSTR(strNum));

			switch(ch)
			{
			case 'h':
				// 시간이 음수라면 양수로 바꾼다
				if(nTime < 0)		nTime *= -1;
				// 24시 표기라면
				if(m_bTime24)
				{
					// 시간이 23을 초과하면 23으로 바꾼다
					if(nTime > 23)	nTime = 23;
				}
				else
				{
					// 시간이 12를 초과하면 12로 바꾼다
					if(nTime > 12)	nTime = 12;
					// 시간이 0이고 두자리 이상이 입력되었다면 1로 바꾼다
					if(nTime == 0 && strNum.GetLength() > 1)	nTime = 1;
				}
				break;
			case 'm':
				// 분이 음수라면 양수로 바꾼다
				if(nTime < 0)		nTime *= -1;
				// 분이 59를 초과하면 59로 바꾼다
				if(nTime > 59)		nTime = 59;
				break;
			case 's':
				// 초가 음수라면 양수로 바꾼다
				if(nTime < 0)		nTime *= -1;
				// 초가 59를 초과하면 59로 바꾼다
				if(nTime > 59)		nTime = 59;
				break;
			}

			// 문자열의 길이만큼의 숫자 포맷을 만든다
			strFormat.Format("%%0%dd", i - nStart);
			// 숫자를 문자열로 바꾼다
			strNum.Format(strFormat, nTime);
			// 출력 문자열에 추가한다
			strOutput += strNum;
			i -= 1;
			break;
		default:
			// 시/분/초 문자가 아니라면 포맷 문자를 출력 문자열에 추가한다
			strOutput += m_strTimeFormat.GetAt(i);
			break;
		}
	}

	// 만약 24시 표기가 아니고, 포맷에 맞는 문자열이 모두 입력된 상태라면
	if(!m_bTime24 && strOutput.GetLength() == m_strTimeFormat.GetLength())
	{
		// 오전/오후를 추가한다
		if(m_bAmPm)		strOutput += " 오전";
		else			strOutput += " 오후";
	}

	return nPos;
}

int CFilterEdit::CheckFormat(CString &strInput, CString &strOutput, int nPos)
{
	// 소수점은 없는 것으로 초기화
	m_nDecPointPos = -1;

	strOutput.Empty();

	// 마스크 모드가 아니라면 리턴
	if(!(m_nType & FILTER_MASK))		return 0;

	int nLength = strInput.GetLength(), i, nTerm = 0;
	int nFormat = m_strMask.GetLength();

	// 문자열의 길이만큼 루프를 돌면서 마스크 포맷 문자를 검사한다
	for(i = 0; i < nLength && i < nFormat; i++)
	{
		// 만약 숫자 입력 자리라면
		if(m_strMask.GetAt(i) == FILTER_MASK_NUMBER)
		{
			// 숫자일 경우 출력 문자열에 추가한다
			if(::isdigit(strInput.GetAt(i)))
				strOutput += strInput.GetAt(i);
			else
			{
				// 숫자가 아닐 경우, 캐럿이 현재 문자보다 뒤에 있다면 갯수를 센다
				if(nPos > i)
					nTerm = strInput.GetLength() - i;
				break;
			}
			continue;
		}
		// 만약 문자 입력 자리라면
		if(m_strMask.GetAt(i) == FILTER_MASK_ALPHA)
		{
			// 문자일 경우 출력 문자열에 추가한다
			if(::isalpha(strInput.GetAt(i)))
				strOutput += strInput.GetAt(i);
			else
			{
				// 문자가 아닐 경우, 캐럿이 현재 문자보다 뒤에 있다면 갯수를 센다
				if(nPos > i)
					nTerm = strInput.GetLength() - i;
				break;
			}
			continue;
		}
		// 문자/숫자 입력 자리가 아니라면 포맷의 문자를 출력 문자에 추가한다
		strOutput += m_strMask.GetAt(i);
	}
	// 제거된 문자만큼 캐럿 위치를 조정한다
	nPos -= nTerm;

	return nPos;
}

// 문자 혹은 백스페이스 키가 눌려졌을 경우
void CFilterEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	CString strText;
	// 현재 입력 텍스트를 얻는다
	GetWindowText(strText);

	int nStart, nEnd;
	// 현재 블럭(캐럿 위치) 위치를 얻는다
	GetSel(nStart, nEnd);

	// 현재 필터 모드에 따라 유효성 검사를 한다
	switch(m_nType)
	{
	case FILTER_CURRENCY:
		// 화폐 모드일 경우 숫자와 백스페이스가 아니면 무효
		if(!::isdigit(nChar) && nChar != VK_BACK)
		{
			MessageBeep(MB_OK);
			return;
		}
		break;
	case FILTER_DATE:
		// 날짜 모드이면, 캐럿이 텍스트의 끝에 위치하고 있지 않다면
		// 블럭이 설정되어 있지 않고 포맷에 맞게 입력이 완료된 상태이거나 숫자가 아니고 백스페이스가 아니라면 무효
		if(strText.GetLength() != nEnd
			|| (((nStart == nEnd && nEnd >= m_strDateFormat.GetLength()) || !::isdigit(nChar)) && nChar != VK_BACK))
		{
			MessageBeep(MB_OK);
			return;
		}
		// 백스페이스라면 유효
		if(nChar == VK_BACK)		break;

		// 만약 블럭이라면 블럭 부분을 제거한다
		if(nStart != nEnd)		strText.Delete(nStart, nEnd - nStart);
		nEnd = nStart;
		// 현재 위치부터 연/월/일 입력 부분까지의 포맷 문자를 추가한다
		for(; nStart < m_strDateFormat.GetLength(); nStart++)
		{
			if(m_strDateFormat.GetAt(nStart) != 'y'
				&& m_strDateFormat.GetAt(nStart) != 'm'
				&& m_strDateFormat.GetAt(nStart) != 'd')
				strText += m_strDateFormat.GetAt(nStart);
			else
				break;
		}
		// 만약 포맷 문자가 추가되었다면
		if(nStart != nEnd)
		{
			// 캐럿의 위치를 제일 뒤로 옮기고 우선 에디트 컨트롤의 텍스트를 변경한다
			nEnd = nStart;
			SetWindowText(strText);
			SetSel(nStart, nStart);
		}
		// 만약 포맷에 맞게 모두 입력된 상태라면 무효
		if(nStart >= m_strDateFormat.GetLength())
		{
			MessageBeep(MB_OK);
			return;
		}

		// 만약 월 입력 위치라면
		if(m_strDateFormat.GetAt(nStart) == 'm')
		{
			// 바로전 문자가 월수에 대한 문자인지 확인
			if(nStart > 0)
			{
				// 바로전 문자가 월수 문자라면
				if(m_strDateFormat.GetAt(nStart - 1) == 'm')
				{
					// 월의 10단위 값이 0일 때와 1일 때에 따라 유효 값을 검사한다
					if((strText.GetAt(nStart - 1) > '0' && nChar > '2')
						|| (strText.GetAt(nStart - 1) == '0' && nChar == '0'))
					{
						MessageBeep(MB_OK);
						return;
					}
				}
				else
				{
					// 바로전 문자가 월수 문자가 아니고 2이상의 값이 입력되었을 경우
					if(nChar > '1')
					{
						// 우선 0을 추가하고 다시 문자를 처리한다
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
				// 바로전 문자가 월수 문자가 아니고 2이상의 값이 입력되었을 경우
				if(nChar > '1')
				{
					// 우선 0을 추가하고 다시 문자를 추가한다
					strText.Insert(nStart, '0');
					nStart++;
					nEnd++;
					SetWindowText(strText);
					SetSel(nStart, nEnd);
				}
			}
		}
		// 만약 일 입력 위치라면
		if(m_strDateFormat.GetAt(nStart) == 'd')
		{
			// 바로전 문자가 일수에 대한 문자인지 확인
			if(nStart > 0)
			{
				// 바로전 문자가 일수 문자라면
				if(m_strDateFormat.GetAt(nStart - 1) == 'd')
				{
					// 일의 10단위 값이 0,1,2,3일 때에 따라 유효 값을 검사한다
					if((strText.GetAt(nStart - 1) > '2' && nChar > '1')
						|| (strText.GetAt(nStart - 1) == '0' && nChar == '0'))
					{
						MessageBeep(MB_OK);
						return;
					}
				}
				else
				{
					// 바로전 문자가 일수 문자가 아니고 4이상의 값이 입력되었을 경우
					if(nChar > '3')
					{
						// 우선 0을 추가하고 다시 문자를 처리한다
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
				// 바로전 문자가 일수 문자가 아니고 4이상의 값이 입력되었을 경우
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
		// 시간 모드이면, 캐럿이 텍스트의 끝에 위치하고 있지 않다면
		// 블럭이 설정되어 있지 않고 포맷에 맞게 입력이 완료된 상태이거나 숫자가 아니고 백스페이스가 아니라면 무효
		if(strText.GetLength() != nEnd
			|| (((nStart == nEnd && nEnd >= m_strTimeFormat.GetLength()) || !::isdigit(nChar)) && nChar != VK_BACK))
		{
			MessageBeep(MB_OK);
			return;
		}
		// 백스페이스라면 유효
		if(nChar == VK_BACK)	break;

		// 만약 블럭이라면 블럭 부분을 제거한다
		if(nStart != nEnd)			strText.Delete(nStart, nEnd - nStart);
		nEnd = nStart;
		// 현재 위치부터 시/분/초 입력 부분까지의 포맷 문자를 추가한다
		for(; nStart < m_strTimeFormat.GetLength(); nStart++)
		{
			if(m_strTimeFormat.GetAt(nStart) != 'h'
				&& m_strTimeFormat.GetAt(nStart) != 'm'
				&& m_strTimeFormat.GetAt(nStart) != 's')
				strText += m_strTimeFormat.GetAt(nStart);
			else
				break;
		}
		// 만약 포맷에 맞게 모두 입력 되었고 캐럿이 문자열의 끝에 있다면
		if(nStart == m_strTimeFormat.GetLength()
			&& strText.GetLength() == m_strTimeFormat.GetLength())
		{
			// 오전/오후를 추가한다
			if(m_bAmPm)			strText += " 오전";
			else				strText += " 오후";
		}
		// 만약 포맷 문자가 추가되었다면
		if(nStart != nEnd)
		{
			// 캐럿의 위치를 제일 뒤로 옮기고 우선 에디트 컨트롤의 텍스트를 변경한다
			nEnd = nStart;
			SetWindowText(strText);
			SetSel(nStart, nStart);
		}
		// 만약 포맷에 맞게 모두 입력된 상태라면 무효
		if(nStart >= m_strTimeFormat.GetLength())
		{
			MessageBeep(MB_OK);
			return;
		}

		// 만약 시간 입력 위치라면
		if(m_strTimeFormat.GetAt(nStart) == 'h')
		{
			// 바로전 문자가 시간에 대한 문자인지 확인
			if(nStart > 0)
			{
				// 바로전 문자가 시간 문자라면
				if(m_strTimeFormat.GetAt(nStart - 1) == 'h')
				{
					// 만약 24시 표기라면
					if(m_bTime24)
					{
						// 시간의 10단위 값이 0일 때와 1일 때에 따라 유효 값을 검사한다
						if(strText.GetAt(nStart - 1) > '1' && nChar > '3')
						{
							MessageBeep(MB_OK);
							return;
						}
					}
					else
					{
						// 24시 표기가 아니라면 시간의 10단위 값이 0일 때와 1일 때에 따라 유효 값을 검사한다
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
					// 바로전 문자가 월수 문자가 아니고 24시 표기라면
					if(m_bTime24)
					{
						// 3이상의 값이 입력되었을 경우
						if(nChar > '2')
						{
							// 우선 0을 추가하고 다시 문자를 처리한다
							strText.Insert(nStart, '0');
							nStart++;
							nEnd++;
							SetWindowText(strText);
							SetSel(nStart, nEnd);
						}
					}
					else
					{
						// 24시 표기가 아니고 2이상의 값이 입력되었다면
						if(nChar > '1')
						{
							// 우선 0을 추가하고 다시 문자를 처리한다
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
				// 바로전 문자가 월수 문자가 아니고 24시 표기라면
				if(m_bTime24)
				{
					// 3이상의 값이 입력되었을 경우
					if(nChar > '2')
					{
						// 우선 0을 추가하고 다시 문자를 처리한다
						strText.Insert(nStart, '0');
						nStart++;
						nEnd++;
						SetWindowText(strText);
						SetSel(nStart, nEnd);
					}
				}
				else
				{
					// 24시 표기가 아니고 2이상의 값이 입력되었다면
					if(nChar > '1')
					{
						// 우선 0을 추가하고 다시 문자를 처리한다
						strText.Insert(nStart, '0');
						nStart++;
						nEnd++;
						SetWindowText(strText);
						SetSel(nStart, nEnd);
					}
				}
			}
		}
		// 만약 분 입력 위치라면
		if(m_strTimeFormat.GetAt(nStart) == 'm')
		{
			// 바로전 문자가 분에 대한 문자인지 확인
			if(nStart > 0)
			{
				// 바로전 문자가 분 문자가 아니라면
				if(m_strTimeFormat.GetAt(nStart - 1) != 'm')
				{
					// 6이상의 값이 입력되었을 경우
					if(nChar > '5')
					{
						// 우선 0을 추가하고 다시 문자를 처리한다
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
				// 6이상의 값이 입력되었을 경우
				if(nChar > '5')
				{
					// 우선 0을 추가하고 다시 문자를 처리한다
					strText.Insert(nStart, '0');
					nStart++;
					nEnd++;
					SetWindowText(strText);
					SetSel(nStart, nEnd);
				}
			}
		}
		// 만약 초 입력 위치라면
		if(m_strTimeFormat.GetAt(nStart) == 's')
		{
			// 바로전 문자가 초에 대한 문자인지 확인
			if(nStart > 0)
			{
				// 바로전 문자가 초 문자가 아니라면
				if(m_strTimeFormat.GetAt(nStart - 1) != 's')
				{
					// 6이상의 값이 입력되었을 경우
					if(nChar > '5')
					{
						// 우선 0을 추가하고 다시 문자를 처리한다
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
				// 6이상의 값이 입력되었을 경우
				if(nChar > '5')
				{
					// 우선 0을 추가하고 다시 문자를 처리한다
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
		// 마스크 모드이면, 캐럿이 텍스트의 끝에 위치하고 있지 않다면
		// 포맷에 맞게 입력이 완료된 상태이고 백스페이스가 아니라면 무효
		if(strText.GetLength() != nEnd || (nEnd >= m_strMask.GetLength() && nChar != VK_BACK))
		{
			MessageBeep(MB_OK);
			return;
		}
		// 백스페이스라면 유효
		if(nChar == VK_BACK)		break;

		// 만약 블럭이라면 블럭 부분을 제거한다
		if(nStart != nEnd)			strText.Delete(nStart, nEnd - nStart);
		nEnd = nStart;
		// 현재 위치부터 숫자/문자 입력 부분까지의 포맷 문자를 추가한다
		for(; nStart < m_strMask.GetLength(); nStart++)
		{
			if(m_strMask.GetAt(nStart) != FILTER_MASK_NUMBER
				&& m_strMask.GetAt(nStart) != FILTER_MASK_ALPHA)
				strText += m_strMask.GetAt(nStart);
			else
				break;
		}
		// 만약 포맷 문자가 추가되었다면
		if(nStart != nEnd)
		{
			// 캐럿의 위치를 제일 뒤로 옮기고 우선 에디트 컨트롤의 텍스트를 변경한다
			nEnd = nStart;
			SetWindowText(strText);
			SetSel(nStart, nStart);
		}
		// 만약 포맷에 맞게 모두 입력된 상태라면 무효
		if(nStart >= m_strMask.GetLength())
		{
			MessageBeep(MB_OK);
			return;
		}

		// 만약 숫자 입력 위치에 숫자가 아니거나
		// 문자 입력 위치에 문자가 아니면 무효
		if((m_strMask.GetAt(nStart) != FILTER_MASK_NUMBER || !::isdigit(nChar))
			&& (m_strMask.GetAt(nStart) != FILTER_MASK_ALPHA || !::isalpha(nChar))
			&& nChar != VK_BACK)
		{
			MessageBeep(MB_OK);
			return;
		}
		break;
	default:
		// 만약 기타 필터 모드이고 블럭이 지정되어 있다면
		if(nStart != nEnd)
		{
			// 블럭 부분을 제거한다
			strText.Delete(nStart, nEnd - nStart);

			// 만약 제거된 문자들에 소숫점이 포함되어 있다면 소수점이 없는 것으로 초기화
			if(nStart <= m_nDecPointPos && m_nDecPointPos <= nEnd)
				m_nDecPointPos = -1;
		}
		// 만약 백스페이스라면
		if(nChar == VK_BACK)
		{
			// 블럭이 지정되어 있지 않다면
			if(nStart == nEnd)
			{
				// 캐럿이 제일 앞에 있지 않다면
				if(nStart > 0)
				{
					// 캐럿 앞의 문자가 소수점이라면
					if(strText.GetAt(nStart - 1) == '.')
						// 소수점이 없는 것으로 초기화
						m_nDecPointPos = -1;
				}
				// 만약 소수점이 현재 위치의 뒤쪽에 있다면 소수점의 위치를 한칸 앞으로 이동
				if(nStart <= m_nDecPointPos)	m_nDecPointPos -= 1;
			}
			break;
		}

		// 만약 포맷에 맞는 문자가 아니라면
		if(!IsValidChar((char)nChar, nStart, strText.GetLength() - nStart - 1))
		{
			// 만약 부호를 갖는 모드이고, 입력된 문자가 부호문자('-')이고,
			// 현재 값이 입력된 상태라면
			if(nChar == '-' && strText.GetLength() > 0 && (m_nType & FILTER_SIGN))
			{
				// 음수 부호가 있는 상태라면
				if(strText.GetAt(0) == '-')
				{
					// 음수 부호를 제거한다
					strText.Delete(0, 1);

					// 캐럿의 위치를 한칸 앞으로 이동한다
					nStart -= 1;
					if(nStart < 0)	nStart = 0;
					nEnd -= 1;
					if(nEnd < 0)	nEnd = 0;
					// 소수점의 위치를 한칸 앞으로 이동한다
					if(m_nDecPointPos > 0)			m_nDecPointPos -= 1;
				}
				else
				{
					// 음수 부호를 추가한다
					strText.Insert(0, '-');

					// 캐럿의 위치를 한칸 뒤로 이동한다
					nStart += 1;
					nEnd += 1;
					// 소수점의 위치를 한칸 뒤로 이동한다
					if(m_nDecPointPos >= 0)			m_nDecPointPos += 1;
				}

				// 에디트 컨트롤의 텍스트를 변경하고 캐럿 위치를 설정한다
				SetWindowText(strText);
				SetSel(nStart, nEnd);
			}
			else
				// 무효 처리한다
				MessageBeep(MB_OK);
			return;
		}

		// 만약 블럭이 설정되어 있지 않고 소수점이 현재 위치 이후에 있다면
		if(nStart == nEnd && nStart <= m_nDecPointPos)
			// 소수점의 위치를 한칸 뒤로 옮긴다
			m_nDecPointPos += 1;

		// 만약 소수점이 표시될 수 있고 소수점이 첫 위치에 있다면
		if((m_nType & FILTER_DECIMALPOINT) && m_nDecPointPos == 0)
		{
			// 소수점의 위치를 한칸 뒤로 이동하고
			m_nDecPointPos += 1;
			// 소수점 앞에 0을 덧붙인다
			strText.Insert(0, "0");
			SetWindowText(strText);
			SetSel(nStart + 1, nStart + 1);
		}
		break;
	}

	// 문자를 추가한다
	CEdit::OnChar(nChar, nRepCnt, nFlags);

	// 에디트 컨트롤의 텍스트를 다시 읽는다
	GetWindowText(strText);
	// 캐럿의 위치를 다시 읽는다
	GetSel(nStart, nEnd);

	switch(m_nType)
	{
	case FILTER_CURRENCY:
		// 만약 화폐 모드라면
		{
			// ','를 다시 찍기 위해 문자열을 다시 확인한다
			CString strOutput;
			int nNewStart = CheckCurrency(strText, strOutput, nStart);

			// 에디트 컨트롤의 텍스트를 변경하고 블럭과 캐럿의 위치를 보정한다
			SetWindowText(strOutput);
			nNewStart	-= nStart;
			nStart		+= nNewStart;
			nEnd		+= nNewStart;

			SetSel(nStart, nEnd);
		}
		break;
	case FILTER_DATE:
		// 만약 날짜 모드라면
		// 백스페이스가 입력된 상태가 아니라면
		if(nChar != VK_BACK)
		{
			// 현재 캐럿 위치 이후로 포맷 문자들을 추가한다
			for(; nStart < m_strDateFormat.GetLength() && nChar != VK_BACK; nStart++)
			{
				if(m_strDateFormat.GetAt(nStart) != 'y'
					&& m_strDateFormat.GetAt(nStart) != 'm'
					&& m_strDateFormat.GetAt(nStart) != 'd')
					strText += m_strDateFormat.GetAt(nStart);
				else
					break;
			}
			// 에디트 컨트롤의 텍스트를 변경하고 블럭과 캐럿의 위치를 보정한다
			SetWindowText(strText);
			SetSel(nStart, nStart);
		}
		break;
	case FILTER_TIME:
		// 만약 시간 모드라면
		// 백스페이스가 입력된 상태가 아니라면
		if(nChar != VK_BACK)
		{
			// 현재 캐럿 위치 이후로 포맷 문자들을 추가한다
			for(; nStart < m_strTimeFormat.GetLength(); nStart++)
			{
				if(m_strTimeFormat.GetAt(nStart) != 'h'
					&& m_strTimeFormat.GetAt(nStart) != 'm'
					&& m_strTimeFormat.GetAt(nStart) != 's')
					strText += m_strTimeFormat.GetAt(nStart);
				else
					break;
			}
			// 만약 포맷에 따라 모두 입력되었고 캐럿이 텍스트 끝에 있다면
			if(nStart == m_strTimeFormat.GetLength()
				&& strText.GetLength() == m_strTimeFormat.GetLength())
			{
				// 오전/오후를 추가한다
				if(m_bAmPm)			strText += " 오전";
				else				strText += " 오후";
			}
			// 에디트 컨트롤의 텍스트를 변경하고 블럭과 캐럿의 위치를 보정한다
			SetWindowText(strText);
			SetSel(nStart, nStart);
		}
		break;
	case FILTER_MASK:
		// 만약 마스크 모드라면
		// 백스페이스가 입력된 상태가 아니라면
		if(nChar != VK_BACK)
		{
			// 현재 캐럿 이후로 포맷 문자들을 추가한다
			for(; nStart < m_strMask.GetLength(); nStart++)
			{
				if(m_strMask.GetAt(nStart) != FILTER_MASK_NUMBER
					&& m_strMask.GetAt(nStart) != FILTER_MASK_ALPHA)
					strText += m_strMask.GetAt(nStart);
				else
					break;
			}
			// 에디트 컨트롤의 텍스트를 변경하고 블럭과 캐럿의 위치를 보정한다
			SetWindowText(strText);
			SetSel(nStart, nStart);
		}
		break;
	}
}

// 에디트 컨트롤의 텍스트가 변경될 경우 호출되는 함수
LRESULT CFilterEdit::OnSetText(UINT wParam, LONG lParam)
{
	// 에디트 컨트롤의 텍스트를 변경한다
	LRESULT nReturn = CEdit::Default();

	// 새로 설정된 텍스트에 대해 유효성 검사를 한다
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

	// 만약 새로 설정된 텍스트와 유효한 문자열이 틀리다면
	if(strText != strValid)
	{
		// 에디트 컨트롤의 텍스트를 유효한 문자열로 변경한다
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

	// 현재 캐럿 위치와 텍스트를 얻는다
	GetSel(nStart, nEnd);
	GetWindowText(strText);

	switch(nChar)
	{
	case VK_DELETE:
		// 만약 DELETE 키가 눌러졌다면
		// 날짜/시간/마스크 모드이고 캐럿이 끝 문자에 있지 않다면 무효
		if((m_nType & (FILTER_DATE | FILTER_TIME | FILTER_MASK))
			&& (nEnd < strText.GetLength() - 1))
		{
			MessageBeep(MB_OK);
			return;
		}
		break;
	case VK_UP:
		// 만약 위 방향키가 눌러졌다면
		// 날짜 모드이면
		if(m_nType == FILTER_DATE)
		{
			// 현재 위치가 문자열 안쪽이면
			if(nStart < m_strDateFormat.GetLength() && nStart < strText.GetLength())
			{
				// 포맷에서의 현재 문자가 연/월/일 문자라면
				ch = m_strDateFormat.GetAt(nStart);
				if(ch == 'y' || ch == 'm' || ch == 'd')
				{
					// 해당 문자의 시작을 찾는다
					for(; nStart >= 0; nStart--)
					{
						if(m_strDateFormat.GetAt(nStart) != ch)
							break;
					}
					nStart += 1;
					// 해당 문자의 끝을 찾는다
					for(nEnd = nStart; nEnd < m_strDateFormat.GetLength(); nEnd++)
					{
						if(m_strDateFormat.GetAt(nEnd) != ch)
							break;
						// 해당 문자의 위치에 있는 입력 값을 모은다
						strValue += strText.GetAt(nEnd);
					}

					// 입력된 값을 숫자로 바꾼다
					nValue = ::atoi(strValue);
					// 입력된 길이에 따른 포맷을 만든다
					strFormat.Format("%%0%dd", nEnd - nStart);
					// 값을 1 증가시킨다
					nValue += 1;

					switch(ch)
					{
					case 'y':
						// 연수라면 10단위가 초과되지 않도록 조정한다
						nValue %= (int)pow(10, strValue.GetLength());
						break;
					case 'm':
						// 월수이고 길이가 2이상이면
						if(strValue.GetLength() > 1)
						{
							// 12를 초과하지 않도록 조정한다
							nValue %= 13;
							// 0이면 1로 조정한다
							if(nValue == 0)	nValue = 1;
						}
						else
						{
							// 2이상이면 0으로 조정한다
							if(nValue > 1)	nValue = 0;
						}
						break;
					case 'd':
						// 일수이고 길이가 2이상이면
						if(strValue.GetLength() > 1)
						{
							// 31을 초과하지 않도록 조정한다
							nValue %= 32;
							// 0이면 1로 조정한다
							if(nValue == 0) nValue = 1;
						}
						else
						{
							// 4이상이면 0으로 조정한다
							if(nValue > 3)	nValue = 0;
						}
						break;
					}

					// 숫자를 문자열로 변경한다
					strValue.Format(strFormat, nValue);
					// 해당 영역을 삭제한다
					strText.Delete(nStart, nEnd - nStart);
					// 새 문자열을 삽입한다
					strText.Insert(nStart, strValue);

					// 새로운 텍스트를 설정하고 캐럿 위치를 보정한다
					SetWindowText(strText);
					SetSel(nStart, nEnd);
					return;
				}
			}
		}
		// 시간 모드이면
		if(m_nType == FILTER_TIME)
		{
			// 현재 위치가 문자열 안쪽이고 24시 표기가 아니면
			if(nStart < strText.GetLength() && !m_bTime24)
			{
				// 현재 위치가 포맷 문자열보다 뒤에 있다면
				if(nStart > m_strTimeFormat.GetLength())
				{
					// 포맷 문자열 길이 이후의 문자들을 삭제한다
					strText.Delete(m_strTimeFormat.GetLength(),
						strText.GetLength() - m_strTimeFormat.GetLength());
					// 오전/오후를 바꾸고 문자열을 덧붙인다
					m_bAmPm = !m_bAmPm;
					if(m_bAmPm)		strText += " 오전";
					else			strText += " 오후";

					// 새로운 텍스트를 설정하고 캐럿 위치를 보정한다
					SetWindowText(strText);
					SetSel(m_strTimeFormat.GetLength() + 1, strText.GetLength());
					return;
				}
			}
			// 포맷 문자열 길이 안에 있다면
			if(nStart < m_strTimeFormat.GetLength())
			{
				// 포맷에서의 현재 문자가 시/분/초 문자라면
				ch = m_strTimeFormat.GetAt(nStart);
				if(ch == 'h' || ch == 'm' || ch == 's')
				{
					// 해당 문자의 시작을 찾는다
					for(; nStart >= 0; nStart--)
					{
						if(m_strTimeFormat.GetAt(nStart) != ch)
							break;
					}
					nStart += 1;
					// 해당 문자의 끝을 찾는다
					for(nEnd = nStart; nEnd < m_strTimeFormat.GetLength(); nEnd++)
					{
						if(m_strTimeFormat.GetAt(nEnd) != ch)
							break;
						// 해당 문자의 위치에 있는 입력 값을 모은다
						strValue += strText.GetAt(nEnd);
					}

					// 입력된 값을 숫자로 바꾼다
					nValue = ::atoi(strValue);
					// 입력된 길이에 따른 포맷을 만든다
					strFormat.Format("%%0%dd", nEnd - nStart);
					// 값을 1 증가시킨다
					nValue += 1;

					switch(ch)
					{
					case 'h':
						// 시간 문자이고 24시 표기라면
						if(m_bTime24)
						{
							// 길이가 2이상이면
							if(strValue.GetLength() > 1)
							{
								// 23을 초과하지 않도록 조정한다
								nValue %= 24;
							}
							else
							{
								// 3이상이면 0으로 조정한다
								if(nValue > 2) nValue = 0;
							}
						}
						else
						{
							// 길이가 2이상이면
							if(strValue.GetLength() > 1)
							{
								// 12를 초과하지 않도록 조정한다
								nValue %= 13;
								// 0이면 1로 조정한다
								if(nValue == 0)	nValue = 1;
							}
							else
							{
								// 2이상이면 0으로 조정한다
								if(nValue > 1) nValue = 0;
							}
						}
						break;
					case 'm':
					case 's':
						// 분/초 문자라면
						if(strValue.GetLength() > 1)
						{
							// 59를 초과하지 않도록 조정한다
							nValue %= 60;
						}
						else
						{
							// 6이상이면 0으로 조정한다
							if(nValue > 6)	nValue = 0;
						}
						break;
					}

					// 숫자를 문자열로 변경한다
					strValue.Format(strFormat, nValue);
					// 해당 영역을 삭제한다
					strText.Delete(nStart, nEnd - nStart);
					// 새 문자열을 삽입한다
					strText.Insert(nStart, strValue);

					// 새로운 텍스트를 설정하고 캐럿 위치를 보정한다
					SetWindowText(strText);
					SetSel(nStart, nEnd);
					return;
				}
			}
		}
		// 기타이면 왼쪽 방향키로 변경한다
		nChar = VK_LEFT;
		break;
	case VK_DOWN:
		// 만약 아래 방향키가 눌러졌다면
		// 날짜 모드이면
		if(m_nType == FILTER_DATE)
		{
			// 현재 위치가 문자열 안쪽이면
			if(nStart < m_strDateFormat.GetLength() && nStart < strText.GetLength())
			{
				// 포맷에서의 현재 문자가 연/월/일 문자라면
				ch = m_strDateFormat.GetAt(nStart);
				if(ch == 'y' || ch == 'm' || ch == 'd')
				{
					// 해당 문자의 시작을 찾는다
					for(; nStart >= 0; nStart--)
					{
						if(m_strDateFormat.GetAt(nStart) != ch)
							break;
					}
					nStart += 1;
					// 해당 문자의 끝을 찾는다
					for(nEnd = nStart; nEnd < m_strDateFormat.GetLength(); nEnd++)
					{
						if(m_strDateFormat.GetAt(nEnd) != ch)
							break;
						// 해당 문자의 위치에 있는 입력 값을 모은다
						strValue += strText.GetAt(nEnd);
					}

					// 입력된 값을 숫자로 바꾼다
					nValue = ::atoi(strValue);
					// 입력된 길이에 따른 포맷을 만든다
					strFormat.Format("%%0%dd", nEnd - nStart);
					
					// 값을 1 감소시킨다
					nValue -= 1;
					switch(ch)
					{
					case 'y':
						// 연수라면 음수라면 길이만큼의 9단위로 조정한다
						if(nValue < 0)	nValue = (int)pow(10, strValue.GetLength()) - 1;
						break;
					case 'm':
						// 월수이고 길이가 2이상이면
						if(strValue.GetLength() > 1)
						{
							// 0이면 12로 조정한다
							if(nValue == 0)	nValue = 12;
						}
						else
						{
							// 0보다 작으면 1로 조정한다
							if(nValue < 0)	nValue = 1;
						}
						break;
					case 'd':
						// 일수이고 길이가 2이상이면
						if(strValue.GetLength() > 1)
						{
							// 0이면 31로 조정한다
							if(nValue == 0) nValue = 31;
						}
						else
						{
							// 0보다 작으면 3으로 조정한다
							if(nValue < 0)	nValue = 3;
						}
						break;
					}

					// 숫자를 문자열로 변경한다
					strValue.Format(strFormat, nValue);
					// 해당 영역을 삭제한다
					strText.Delete(nStart, nEnd - nStart);
					// 새 문자열을 삽입한다
					strText.Insert(nStart, strValue);

					// 새로운 텍스트를 설정하고 캐럿 위치를 보정한다
					SetWindowText(strText);
					SetSel(nStart, nEnd);
					return;
				}
			}
		}
		// 시간 모드이면
		if(m_nType == FILTER_TIME)
		{
			// 현재 위치가 문자열 안쪽이고 24시 표기가 아니면
			if(nStart < strText.GetLength() && !m_bTime24)
			{
				// 현재 위치가 포맷 문자열보다 뒤에 있다면
				if(nStart > m_strTimeFormat.GetLength())
				{
					// 포맷 문자열 길이 이후의 문자들을 삭제한다
					strText.Delete(m_strTimeFormat.GetLength(),
						strText.GetLength() - m_strTimeFormat.GetLength());
					// 오전/오후를 바꾸고 문자열을 덧붙인다
					m_bAmPm = !m_bAmPm;
					if(m_bAmPm)		strText += " 오전";
					else			strText += " 오후";

					// 새로운 텍스트를 설정하고 캐럿 위치를 보정한다
					SetWindowText(strText);
					SetSel(m_strTimeFormat.GetLength() + 1, strText.GetLength());
					return;
				}
			}
			// 포맷 문자열 길이 안에 있다면
			if(nStart < m_strTimeFormat.GetLength())
			{
				// 포맷에서의 현재 문자가 시/분/초 문자라면
				ch = m_strTimeFormat.GetAt(nStart);
				if(ch == 'h' || ch == 'm' || ch == 's')
				{
					// 해당 문자의 시작을 찾는다
					for(; nStart >= 0; nStart--)
					{
						if(m_strTimeFormat.GetAt(nStart) != ch)
							break;
					}
					nStart += 1;
					// 해당 문자의 끝을 찾는다
					for(nEnd = nStart; nEnd < m_strTimeFormat.GetLength(); nEnd++)
					{
						if(m_strTimeFormat.GetAt(nEnd) != ch)
							break;
						// 해당 문자의 위치에 있는 입력 값을 모은다
						strValue += strText.GetAt(nEnd);
					}

					// 입력된 값을 숫자로 바꾼다
					nValue = ::atoi(strValue);
					// 입력된 길이에 따른 포맷을 만든다
					strFormat.Format("%%0%dd", nEnd - nStart);
					// 값을 1 감소시킨다
					nValue -= 1;

					switch(ch)
					{
					case 'h':
						// 시간 문자이고 24시 표기라면
						if(m_bTime24)
						{
							// 길이가 2이상이면
							if(strValue.GetLength() > 1)
							{
								// 0보다 작다면 23으로 조정한다
								if(nValue < 0)	nValue = 23;
							}
							else
							{
								// 0보다 작다면 2로 조정한다
								if(nValue < 0)	nValue = 2;
							}
						}
						else
						{
							// 길이가 2이상이면
							if(strValue.GetLength() > 1)
							{
								// 0이면 12로 조정한다
								if(nValue == 0)	nValue = 12;
							}
							else
							{
								// 0이면 1로 조정한다
								if(nValue == 0) nValue = 1;
							}
						}
						break;
					case 'm':
					case 's':
						// 분/초 문자라면
						if(strValue.GetLength() > 1)
						{
							// 0보다 작다면 59로 조정한다
							if(nValue < 0)	nValue = 59;
						}
						else
						{
							// 0보다 작다면 5로 조정한다
							if(nValue < 0)	nValue = 5;
						}
						break;
					}

					// 숫자를 문자열로 변경한다
					strValue.Format(strFormat, nValue);
					// 해당 영역을 삭제한다
					strText.Delete(nStart, nEnd - nStart);
					// 새 문자열을 삽입한다
					strText.Insert(nStart, strValue);

					// 새로운 텍스트를 설정하고 캐럿 위치를 보정한다
					SetWindowText(strText);
					SetSel(nStart, nEnd);
					return;
				}
			}
		}
		// 기타이면 오른쪽 방향키로 변경한다
		nChar = VK_RIGHT;
		break;
	}

	// 키를 처리한다
	CEdit::OnKeyDown(nChar, nRepCnt, nFlags);

	// 만약 DELETE 키를 눌렀고 화폐 모드라면
	if((nChar == VK_DELETE) && (m_nType & FILTER_CURRENCY))
	{
		// 현재 캐럿 위치와 텍스트를 다시 구한다
		GetSel(nStart, nEnd);
		GetWindowText(strText);

		// ','를 다시 찍기 위해 문자열을 다시 확인한다
		nStart = CheckCurrency(strText, strValid, nStart);

		// 텍스트와 유효 문자열이 틀리다면
		if(strText != strValid)
		{
			// 에디트 컨트롤의 텍스트를 변경하고 블럭과 캐럿의 위치를 보정한다
			SetWindowText(strValid);
			SetSel(nStart, nStart);
		}
	}
}

// 잘라내기
LONG CFilterEdit::OnCut(UINT, LONG)
{
	// 현재 블럭의 위치를 얻는다
	int nStart, nEnd;
	GetSel(nStart, nEnd);

	// 블럭이 설정되어 있다면
	if(nStart < nEnd)
	{
		// 현재 블럭을 클립보드에 복사한다
		SendMessage(WM_COPY);
		// DELETE 키가 눌린 것처럼 실행한다
		SendMessage(WM_KEYDOWN, VK_DELETE);
	}

	return 0;
}
	
// 삭제
LONG CFilterEdit::OnClear(UINT wParam, LONG lParam)
{
	// 현재 블럭의 위치를 얻는다
	int nStart, nEnd;
	GetSel(nStart, nEnd);

	// 블럭이 설정되어 있다면
	if(nStart < nEnd)
		// DELETE 키가 눌린 것처러 실행한다
		SendMessage(WM_KEYDOWN, VK_DELETE); // delete the selection

	return 0;
}

// 붙여넣기
LRESULT CFilterEdit::OnPaste(UINT, LONG)
{
	// 현재 블럭의 위치를 얻는다
	int nStart, nEnd;
	GetSel(nStart, nEnd);

	// 붙여넣기를 실행한다
	LRESULT nReturn = CEdit::Default();

	// 새로 설정된 텍스트에 대해 유효성 검사를 한다
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

	// 만약 새로 설정된 텍스트와 유효한 문자열이 틀리다면
	if(strText != strValid)
	{
		// 에디트 컨트롤의 텍스트를 유효한 문자열로 변경한다
		SetWindowText(strValid);
		SetSel(nStart, nEnd);
	}

	return nReturn;
}
