
// AdventOfCode2019Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "AdventOfCode2019.h"
#include "AdventOfCode2019Dlg.h"
#include "afxdialogex.h"

#include "MassConstant.h"
#include "CounterUpper.h"
#include "Module.h"

#include "Intcode.h"
#include "IntcodeProcessor.h"

#include "Generic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define SIZEOF_UINT(x) sizeof(x)/sizeof(unsigned int)

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAdventOfCode2019Dlg dialog



CAdventOfCode2019Dlg::CAdventOfCode2019Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADVENTOFCODE2019_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAdventOfCode2019Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAdventOfCode2019Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CAdventOfCode2019Dlg::OnBnClickedOk)
	ON_BN_CLICKED(btn_ProcessIntcode, &CAdventOfCode2019Dlg::OnBnClickedProcessintcode)
END_MESSAGE_MAP()


// CAdventOfCode2019Dlg message handlers

BOOL CAdventOfCode2019Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAdventOfCode2019Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAdventOfCode2019Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAdventOfCode2019Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAdventOfCode2019Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CounterUpper cu;

	for (int i = 0; i < SIZEOF_UINT(MassConstants); ++i)
	{
		cu.AddModule(Module(MassConstants[i]));
	}
	CStringW t;

	t.Format(L"%d", cu.GetTotalFuel());
	SetDlgItemTextW(txtCUFuel, t);
}


void CAdventOfCode2019Dlg::OnBnClickedProcessintcode()
{
	unsigned int size = SIZEOF_UINT(Intcode), toFind = 19690720, noun, verb, result;
	std::vector<unsigned int> tmp;
	bool found = false;

	for (noun = 0; noun < 100; ++noun)
	{
		for (verb = 0; verb < 100; ++verb)
		{
			tmp.clear();
			for (unsigned int k = 0; k < size; ++k)
				tmp.push_back(Intcode[k]);
			tmp[1] = noun;
			tmp[2] = verb;
			int procres = Process::process(tmp);
			if (procres < 0) {
				continue;
			}
			if (tmp[0] == toFind) {
				found = true;
				break;
			}
		}
		if (found) break;
	}
	
	result = (100 * noun) + verb;

	CStringW t;
	t.Format(L"%d", result);
	SetDlgItemTextW(txtIntcode, t);
}
