
// Lottery.ArrangeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Lottery.Arrange.h"
#include "Lottery.ArrangeDlg.h"

#define COUNTLIMIT 20
struct sort_pred {
    bool operator()(const std::pair<int,long long> &left, const std::pair<int,long long> &right) {
        return left.second > right.second;
    }
};

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CLotteryArrangeDlg 对话框




CLotteryArrangeDlg::CLotteryArrangeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLotteryArrangeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLotteryArrangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLotteryArrangeDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTONDOIT, &CLotteryArrangeDlg::OnBnClickedButtondoit)
END_MESSAGE_MAP()


// CLotteryArrangeDlg 消息处理程序

BOOL CLotteryArrangeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	// step 1: set default values

	// set spin control range
	CSpinButtonCtrl spin;
	for(int i = 0; i < 12; i++) {
		spin.Attach(GetDlgItem(i + IDC_SPIN1)->m_hWnd);
		spin.SetRange(0, COUNTLIMIT); // 100
		spin.Detach();
	}

	// set check box
	((CButton*)(GetDlgItem(IDC_CHECKSTRIPZERO)))->SetCheck(BST_CHECKED);
	((CButton*)(GetDlgItem(IDC_CHECKORDER)))->SetCheck(BST_CHECKED);
	// step 2: set control styles

	m_Font0.Detach();
	m_Font0.CreateFont(-23, 0, 0, 0, FW_NORMAL, FALSE, FALSE,0,0,0,0,0,0, _T("华文中宋"));
	for(int i=0;i<7;i++)
		GetDlgItem(IDC_STATIC1+i)->SetFont(&m_Font0);
	for(int i=0;i<12;i++)
		GetDlgItem(IDC_EDIT1+i)->SetFont(&m_Font0);
	m_Font1.Detach();
	m_Font1.CreateFont(-15, 0, 0, 0, FW_NORMAL, FALSE, FALSE,0,0,0,0,0,0, _T("Courier New"));
	GetDlgItem(IDC_EDITRESULT)->SetFont(&m_Font1);
	// step 3: set debug values

	CEdit edit;
	for(int i = 0; i < 12; i++) {
		TCHAR tempchar[128];
#ifdef _DEBUG
		_stprintf(tempchar, _T("%d"), rand() % COUNTLIMIT);
#else
		_stprintf(tempchar, _T("%d"), 1);
#endif
		edit.Attach(GetDlgItem(IDC_EDIT1 + i)->m_hWnd);
		edit.SetWindowText(tempchar);
		edit.Detach();
	}


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLotteryArrangeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLotteryArrangeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLotteryArrangeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLotteryArrangeDlg::OnBnClickedButtondoit()
{
	// TODO: Add your control notification handler code here
	int m_value[3][4]; // [百十个][奇偶小大]
	vector<pair<int,long long>> m_result; // 序号,值

	bool bStripZero = 	((((CButton*)(GetDlgItem(IDC_CHECKSTRIPZERO)))->GetCheck())==BST_CHECKED);
	bool bSort = ((((CButton*)(GetDlgItem(IDC_CHECKORDER)))->GetCheck())==BST_CHECKED);


	// step 1: get values from all controls
	CEdit edit;
	for(int i = 0; i < 12; i++) {
		CString csValue;
		edit.Attach(GetDlgItem(IDC_EDIT1 + i)->m_hWnd);
		edit.GetWindowText(csValue);
		m_value[i/4][i%4] = _tstoi(csValue); // [百十个][奇偶小大]
#ifdef _DEBUG
		CString cs0, cs1;
		switch(i/4) {
			case 0: cs0 = _T("Hundreds\t"); break;
			case 1: cs0 = _T("Tens\t"); break;
			case 2: cs0 = _T("Digits\t"); break;
			default: ASSERT(0);
		}
		switch(i%4) {
			case 0: cs1 = _T("Odd\t"); break;
			case 1: cs1 = _T("Even\t"); break;
			case 2: cs1 = _T("Small\t"); break;
			case 3: cs1 = _T("Big\t"); break;
			default: ASSERT(0);
		}
		TRACE(_T("%s %s %d\n"), cs0 , cs1, m_value[i/4][i%4]);
#endif
		edit.Detach();
	}

	long long valuetotal = 0;
	// step 2: assemble result
	for(int i=0; i<64; i++) {
		int value0 = m_value[0][i&32?0:1];            
		int value1 = m_value[0][i&16?2:3];            
		int value2 = m_value[1][i& 8?0:1];             
		int value3 = m_value[1][i& 4?2:3];             
		int value4 = m_value[2][i& 2?0:1];             
		int value5 = m_value[2][i& 1?2:3];
		long long valuecurrent = (long long)value0*value1*value2*value3*value4*value5;
		m_result.push_back(pair<int, long long>(i, valuecurrent));
		valuetotal += valuecurrent;
	}
	// step 3 sort result
	if(bSort)
		sort(m_result.begin(), m_result.end(), sort_pred());
	// step 4: generate output
	CString csResult;
	for(int i=0; i<64; i++) {	
		TCHAR tResult[128];
		if(bStripZero && m_result[i].second == 0) continue;

		int index = m_result[i].first;

		_stprintf(tResult, _T("%3d号 "), index); 
		csResult += tResult;

		csResult += _T("百 ");            
		csResult += index&32?_T("奇"):_T("偶");
		csResult += index&16?_T("小"):_T("大");
		csResult += _T(" 十 ");            
		csResult += index&8?_T("奇"):_T("偶"); 
		csResult += index&4?_T("小"):_T("大"); 
		csResult += _T(" 个 ");            
		csResult += index&2?_T("奇"):_T("偶"); 
		csResult += index&1?_T("小"):_T("大"); 
		csResult += _T(":");          

		_stprintf(tResult, _T("%6lld(%4.1f%% %6lld/%6lld)\r\n"), m_result[i].second, (double)100 * m_result[i].second / valuetotal, m_result[i].second, valuetotal);
		csResult += tResult;
	}
	CEdit edit2;
	edit2.Attach(GetDlgItem(IDC_EDITRESULT)->m_hWnd);
	edit2.SetWindowText(csResult);
	edit2.Detach();
}
