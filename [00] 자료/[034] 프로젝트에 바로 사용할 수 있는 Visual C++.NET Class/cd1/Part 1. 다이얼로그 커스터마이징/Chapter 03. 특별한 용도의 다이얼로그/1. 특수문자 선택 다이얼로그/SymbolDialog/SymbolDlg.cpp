// SymbolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "SymbolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSymbolDlg dialog


CSymbolDlg::CSymbolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSymbolDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSymbolDlg)
	m_CodeString = _T("");
	//}}AFX_DATA_INIT
}


void CSymbolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSymbolDlg)
	DDX_Control(pDX, IDC_PREVIEW_STATIC, m_CodePreview);
	DDX_Control(pDX, IDC_CODE_EDIT, m_CodeEdit);
	DDX_Control(pDX, IDC_CODE_STATIC, m_CodeChart);
	DDX_Text(pDX, IDC_CODE_EDIT, m_CodeString);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSymbolDlg, CDialog)
	//{{AFX_MSG_MAP(CSymbolDlg)
	ON_BN_CLICKED(IDC_PAGE_UP_BUTTON, OnPageUpButton)
	ON_BN_CLICKED(IDC_PAGE_DOWN_BUTTON, OnPageDownButton)
	ON_BN_CLICKED(IDC_GO_BUTTON, OnGoButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSymbolDlg message handlers

BOOL CSymbolDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// ����ǥ ��Ʈ�ѿ� �� ����
	m_CodeChart.m_pEdit				= &m_CodeEdit;
	m_CodeChart.m_pPreview			= &m_CodePreview;

	// ����ǥ �ʱ�ȭ
	m_CodeChart.InitCodeChart();
	m_CodeChart.UpdateCodeEdit();

	// �̸����� ��Ʈ�� �ʱ�ȭ
	m_CodePreview.InitPreview();

	// ��ư Ȱ��ȭ
	UpdateButton();

	// �ƽ�Ű �ڵ� ����ǥ������ ������ �̵��� �� �� ���� �Ѵ�
	if(!m_CodeChart.m_bIsUnicode)
	{
		GetDlgItem(IDC_PAGE_UP_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_PAGE_DOWN_BUTTON)->EnableWindow(FALSE);
		GetDlgItem(IDC_GO_BUTTON)->ShowWindow(SW_HIDE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

// ���� ���������� �̵� �Լ�
void CSymbolDlg::OnPageUpButton() 
{
	if(!m_CodeChart.m_bIsUnicode)			return;

	if(!m_CodeChart.m_bIsUpper)				m_CodeChart.m_bIsUpper = TRUE;
	else
		if(m_CodeChart.m_cHighByte > 0x00)
		{
			m_CodeChart.m_cHighByte -= 1;
			m_CodeChart.m_bIsUpper = FALSE;
		}

	m_CodeChart.Invalidate(FALSE);
	m_CodeChart.UpdateCodeEdit();

	m_CodePreview.RefreshCode(m_CodeChart.m_cHighByte, m_CodeChart.GetSelectedLowCode());

	UpdateButton();
}

// ���� ���������� �̵� �Լ�
void CSymbolDlg::OnPageDownButton() 
{
	if(!m_CodeChart.m_bIsUnicode)			return;

	if(m_CodeChart.m_bIsUpper)				m_CodeChart.m_bIsUpper = FALSE;
	else
		if(m_CodeChart.m_cHighByte < 0xff)
		{
			m_CodeChart.m_cHighByte += 1;
			m_CodeChart.m_bIsUpper	= TRUE;
		}

	m_CodeChart.Invalidate(FALSE);
	m_CodeChart.UpdateCodeEdit();

	m_CodePreview.RefreshCode(m_CodeChart.m_cHighByte, m_CodeChart.GetSelectedLowCode());

	UpdateButton();
}

// ���� ���ڷ� �̵� �Լ�
void CSymbolDlg::OnLeft()
{
	if(m_CodeChart.m_SelectedCode == 0)
	{
		if(m_CodeChart.m_bIsUpper && m_CodeChart.m_bIsUnicode)
		{
			if(m_CodeChart.m_cHighByte > 0)
			{
				m_CodeChart.m_cHighByte		-= 1;
				m_CodeChart.m_SelectedCode	= 127;
				m_CodeChart.m_bIsUpper		= FALSE;
			}
		}
		else
		{
			m_CodeChart.m_SelectedCode	= 127;
			m_CodeChart.m_bIsUpper		= TRUE;
		}
	}
	else
	{
		m_CodeChart.m_SelectedCode -= 1;
	}

	m_CodeChart.Invalidate(FALSE);
	m_CodeChart.UpdateCodeEdit();

	m_CodePreview.RefreshCode(m_CodeChart.m_cHighByte, m_CodeChart.GetSelectedLowCode());

	UpdateButton();
}

// ������ ���ڷ� �̵� �Լ�
void CSymbolDlg::OnRight()
{
	if(m_CodeChart.m_SelectedCode == 127)
	{
		if(m_CodeChart.m_bIsUpper && m_CodeChart.m_bIsUnicode)
		{
			m_CodeChart.m_SelectedCode	= 0;
			m_CodeChart.m_bIsUpper		= FALSE;
		}
		else
		{
			if(m_CodeChart.m_cHighByte < 0xff)
			{
				if(m_CodeChart.m_bIsUnicode)
					m_CodeChart.m_cHighByte		+= 1;
				m_CodeChart.m_SelectedCode	= 0;
				m_CodeChart.m_bIsUpper		= TRUE;
			}
		}
	}
	else
	{
		m_CodeChart.m_SelectedCode += 1;
	}

	m_CodeChart.Invalidate(FALSE);
	m_CodeChart.UpdateCodeEdit();

	m_CodePreview.RefreshCode(m_CodeChart.m_cHighByte, m_CodeChart.GetSelectedLowCode());

	UpdateButton();
}

// ���ٷ� �̵� �Լ�
void CSymbolDlg::OnUp()
{
	if(m_CodeChart.m_SelectedCode - 16 < 0)
	{
		if(m_CodeChart.m_bIsUpper && m_CodeChart.m_bIsUnicode)
		{
			if(m_CodeChart.m_cHighByte > 0)
			{
				m_CodeChart.m_cHighByte		-= 1;
				m_CodeChart.m_SelectedCode	-= 16;
				m_CodeChart.m_SelectedCode	+= (char)128;
				m_CodeChart.m_bIsUpper		= FALSE;
			}
		}
		else
		{
			m_CodeChart.m_SelectedCode	-= 16;
			m_CodeChart.m_SelectedCode	+= (char)128;
			m_CodeChart.m_bIsUpper		= TRUE;
		}
	}
	else
	{
		m_CodeChart.m_SelectedCode -= 16;
	}

	m_CodeChart.Invalidate(FALSE);
	m_CodeChart.UpdateCodeEdit();

	m_CodePreview.RefreshCode(m_CodeChart.m_cHighByte, m_CodeChart.GetSelectedLowCode());

	UpdateButton();
}

// �Ʒ� �ٷ� �̵� �Լ�
void CSymbolDlg::OnDown()
{
	if(m_CodeChart.m_SelectedCode + 16 > 127)
	{
		if(m_CodeChart.m_bIsUpper && m_CodeChart.m_bIsUnicode)
		{
			m_CodeChart.m_SelectedCode	+= 16;
			m_CodeChart.m_SelectedCode	-= (char)128;
			m_CodeChart.m_bIsUpper		= FALSE;
		}
		else
		{
			if(m_CodeChart.m_cHighByte < 0xff)
			{
				if(m_CodeChart.m_bIsUnicode)
					m_CodeChart.m_cHighByte		+= 1;
				m_CodeChart.m_SelectedCode	+= 16;
				m_CodeChart.m_SelectedCode	-= (char)128;
				m_CodeChart.m_bIsUpper		= TRUE;
			}
		}
	}
	else
	{
		m_CodeChart.m_SelectedCode += 16;
	}

	m_CodeChart.Invalidate(FALSE);
	m_CodeChart.UpdateCodeEdit();

	m_CodePreview.RefreshCode(m_CodeChart.m_cHighByte, m_CodeChart.GetSelectedLowCode());

	UpdateButton();
}

// Ű���� �Է��� ó���ϴ� �Լ�
BOOL CSymbolDlg::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message == WM_KEYUP)
	{
		switch(pMsg->wParam)
		{
		case VK_PRIOR:
			OnPageUpButton();
			break;
		case VK_NEXT:
			OnPageDownButton();
			break;
		case VK_LEFT:
			OnLeft();
			break;
		case VK_RIGHT:
			OnRight();
			break;
		case VK_UP:
			OnUp();
			break;
		case VK_DOWN:
			OnDown();
			break;
		}
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

// Ư�� ����ǥ�� ����� ��Ʈ ���� �Լ�
void CSymbolDlg::SetFontName(LPCTSTR pFontName)
{
	m_CodeChart.m_FontName		= pFontName;
	m_CodePreview.m_FontName	= pFontName;
}

// Ư�� ����ǥ�� ����� ���� �ڵ� ���� �Լ�
void CSymbolDlg::SetCodeType(BOOL bUnicode)
{
	m_CodeChart.m_bIsUnicode	= bUnicode;
	m_CodePreview.m_bIsUnicode	= bUnicode;
}

// ���� ���õ� ������ ���� ����Ʈ�� �����ϴ� �Լ�
CString CSymbolDlg::GetSelectedChar()
{
	CString strChar;
	unsigned char cHighByte, cLowByte;

	cHighByte	= m_CodeChart.m_cHighByte;
	cLowByte	= m_CodeChart.GetSelectedLowCode();

	strChar.Format("%04x", MAKEWORD(cLowByte, cHighByte));

	return strChar;
}

// ���� �ڵ� ������ ���� ��ư���� Ȱ��ȭ ��Ű�� �Լ�
void CSymbolDlg::UpdateButton()
{
	if(m_CodeChart.m_cHighByte == 0)
		GetDlgItem(IDC_PAGE_UP_BUTTON)->EnableWindow(FALSE);
	else
		GetDlgItem(IDC_PAGE_UP_BUTTON)->EnableWindow(TRUE);

	if(m_CodeChart.m_cHighByte == 0xff)
		GetDlgItem(IDC_PAGE_DOWN_BUTTON)->EnableWindow(FALSE);
	else
		GetDlgItem(IDC_PAGE_DOWN_BUTTON)->EnableWindow(TRUE);
}

// ���� �ڵ�� �������� �̵��ϴ� �Լ�
void CSymbolDlg::OnGoButton() 
{
	UpdateData(TRUE);

	m_CodeString.MakeUpper();

	int i, nCode = 0;
	char ch;

	for(i = 0; i < 4; i++)
	{
		if(i >= m_CodeString.GetLength())
			ch = '0';
		else
			ch = m_CodeString.GetAt(i);

		if('0' <= ch && ch <= '9')		ch -= '0';
		else
			if('A' <= ch && ch <= 'F')	ch -= 'A' - 10;
			else						ch = 15;

		nCode |= (ch << (4 * (3 - i)));
	}

	m_CodeChart.m_cHighByte = 0xff & (nCode >> 8);
	if(nCode & 0x80)	m_CodeChart.m_bIsUpper = FALSE;
	else				m_CodeChart.m_bIsUpper = TRUE;
	m_CodeChart.m_SelectedCode = (0x7f & nCode);

	m_CodeChart.Invalidate(FALSE);
	m_CodeChart.UpdateCodeEdit();

	m_CodePreview.RefreshCode(m_CodeChart.m_cHighByte, m_CodeChart.GetSelectedLowCode());

	UpdateButton();

	UpdateData(FALSE);
}

void CSymbolDlg::OnOK() 
{
	CDialog::OnOK();
}
