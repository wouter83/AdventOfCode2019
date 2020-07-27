
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
#include "CrossedWires.h"

#include "Password.h"

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
	ON_BN_CLICKED(IDC_BUTTON1, &CAdventOfCode2019Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAdventOfCode2019Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAdventOfCode2019Dlg::OnBnClickedButton3)
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
	unsigned int size = SIZEOF_UINT(Intcode_D2), toFind = 19690720, noun, verb, result;
	std::vector<int> tmp;
	bool found = false;

	for (noun = 0; noun < 100; ++noun)
	{
		for (verb = 0; verb < 100; ++verb)
		{
			tmp.clear();
			for (unsigned int k = 0; k < size; ++k)
				tmp.push_back(Intcode_D2[k]);
			tmp[1] = noun;
			tmp[2] = verb;
			std::vector<int> output;
			int procres = Process::process(tmp, output);
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


void CAdventOfCode2019Dlg::OnBnClickedButton1()
{
	std::string wire1 = "R1003,D430,L108,D570,R459,U7,L68,D232,L130,U93,R238,U951,L821,U723,L370,U873,L680,U749,R110,U17,R185,U484,R550,U356,L212,U350,L239,D208,R666,U70,L369,U448,R54,D402,R165,D375,L468,U886,L303,U779,L752,U664,L120,U643,R405,D288,L220,U727,L764,D615,R630,U688,R961,U499,L782,D852,L743,U443,R355,U856,L795,U235,L876,D511,L108,U637,R427,D338,L699,D911,L506,D607,L539,U977,R654,D634,L196,U944,R922,D774,R358,U828,L970,D386,R795,U602,R249,U793,L171,D217,L476,D123,L179,U820,R895,D239,R363,D629,L226,D811,R962,D848,R218,D581,R369,D872,L653,D281,R304,D302,R780,U636,L413,D712,L642,D886,R613,U736,L968,D82,R953,U408,L130,U654,R312,U74,L610,D798,R242,D586,L808,D664,L764,U455,R264,U384,L154,D484,R883,D276,L423,U11,L145,U156,L268,U46,R202,U641,R920,D483,R859,U94,L173,D796,R11,D328,R48,D161,L615,D396,R350,D48,R946,D233,R385,D294,R640,D301,R810,D824,L969,D469,R34,U995,R750,D827,R52,U606,R143,U868,L973,U863,L17,U995,L236,U994,R403,D312,R49,U143,L399,U821,R974,U119,R410,D233,R228,D326,R112,D512,L950,D103,L590,U80,R7,U441,L744,U643,L80,D631,L576,U680,R369,U741,L87,D748,R773,U145,R464,U546,R80,D251,L972,U414,L390,U148,L84,D481,L425,U293,L564,U880,R535,U703,R981,U944,R224,D366,R29,U517,R342,U686,L384,D650,R983,D287,L108,U713,L523,U695,R881,D126,R151,U153,R161,D791,L599,D936,L816,U387,R411,U637,L434,D22,L720,U579,L661,D644,L220,U325,R753,D392,L503,U617,R1,D956,L607,U602,L800,D749,L193,U215,L91,U733,L606,U510,L124,D550,R303,D835,R19,D326,R577,U265,L156,D924,L122,D186,R803,U3,R879 ";
	std::string wire2 = "L1003,U603,L675,U828,R671,U925,R466,D707,L39,U1,R686,U946,L438,U626,R714,D365,L336,D624,R673,U672,L729,D965,R824,D533,R513,D914,R829,U275,L424,U10,L244,U158,R779,D590,R116,U714,R662,D989,R869,D547,R817,U315,R439,D29,L599,D870,L645,U656,R845,U19,R960,U669,L632,D567,L340,U856,R955,D314,R452,D896,R574,D162,R240,U302,R668,U706,R394,D24,L422,U884,R804,U576,L802,U400,R405,U676,L344,D628,R672,U580,R710,U536,L712,U738,L266,D212,R552,D229,R265,U835,R152,U784,L478,D87,L783,D327,R728,U590,R408,D397,R363,D654,R501,D583,R445,U897,R888,D480,R455,U593,R906,D506,R985,D361,R361,D619,L462,D873,L248,D348,R540,D578,L274,D472,R254,U647,R54,U681,L33,U343,R913,U120,L64,D849,L953,U407,L64,U744,L482,U240,L82,U69,R480,D796,L137,U527,R428,U67,R123,U688,L985,D944,R583,D804,R331,U328,R906,U376,L966,U433,R863,D931,L315,D9,L77,D141,L738,D661,R742,D44,R383,U78,R106,D301,L186,U907,L304,U786,L256,U718,R861,D145,R694,D721,R607,D418,R358,U600,R228,D139,R476,D451,L49,U616,L491,U8,R371,D735,R669,U388,L905,D282,L430,U491,L775,U891,L831,U350,L247,D609,R489,U266,R468,D748,R134,U187,R882,D315,R344,D363,R349,U525,R831,U644,R207,D563,L1,D946,L559,U789,L187,U370,L284,D910,L394,D560,L705,U661,R272,U109,L12,D554,L670,D169,L375,D100,R382,D491,L53,D916,R152,U82,L236,U845,L860,U732,R327,D190,R888,U722,R770,U993,R509,D970,L225,D756,R444,D992,L746,D35,R329,D452,R728,U575,L325,U414,L709,D844,R692,D575,R132,D520,L506,D384,L581,U36,L336,U849,L944,U450,R138,D186,L613,U805,R32,U763,R210,U556,R125,D499,R729";	
	CrossedWires wire;
	wire.LoadWires(wire1, wire2);

	CStringW t;
	int nearestCross;
	int shortestCross;

	wire.RunWires(nearestCross, shortestCross);
	t.Format(L"%d", shortestCross);
	SetDlgItemTextW(txtCalcWires, t);

	t.Format(L"%d", nearestCross);
	SetDlgItemTextW(txtCalcWires2, t);

}

void CAdventOfCode2019Dlg::OnBnClickedButton2()
{
	int lowBoundary = 171309;
	int highBoundary = 643603;
	int count = 0;
	for (int i = lowBoundary; i < highBoundary; ++i)
	{
		Password p;
		if (p.Verify(std::to_string(i))) 
			++count;
	}
	CStringW t;
	t.Format(L"%d", count);
	SetDlgItemTextW(txtPasswordRetries, t);

}


void CAdventOfCode2019Dlg::OnBnClickedButton3()
{
	unsigned int size = SIZEOF_UINT(Intcode_D5);
	std::vector<int> tmp;
	for (unsigned int k = 0; k < size; ++k)
		tmp.push_back(Intcode_D5[k]);
	int input = 1;
	std::vector<int> output;
	int procres = Process::process(tmp, output, input);
	if (procres == 0)
	{
		CStringW t;
		t.Format(L"%d", output[output.size()-1]);
		SetDlgItemTextW(txtIntcode2, t);
	}
}
