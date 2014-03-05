
// Lottery.ArrangeDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CLotteryArrangeDlg �Ի���




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


// CLotteryArrangeDlg ��Ϣ�������

BOOL CLotteryArrangeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
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
	m_Font0.CreateFont(-23, 0, 0, 0, FW_NORMAL, FALSE, FALSE,0,0,0,0,0,0, _T("��������"));
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


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLotteryArrangeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CLotteryArrangeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLotteryArrangeDlg::OnBnClickedButtondoit()
{
	// TODO: Add your control notification handler code here
	int m_value[3][4]; // [��ʮ��][��żС��]
	vector<pair<int,long long>> m_result; // ���,ֵ

	bool bStripZero = 	((((CButton*)(GetDlgItem(IDC_CHECKSTRIPZERO)))->GetCheck())==BST_CHECKED);
	bool bSort = ((((CButton*)(GetDlgItem(IDC_CHECKORDER)))->GetCheck())==BST_CHECKED);


	// step 1: get values from all controls
	CEdit edit;
	for(int i = 0; i < 12; i++) {
		CString csValue;
		edit.Attach(GetDlgItem(IDC_EDIT1 + i)->m_hWnd);
		edit.GetWindowText(csValue);
		m_value[i/4][i%4] = _tstoi(csValue); // [��ʮ��][��żС��]
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

		_stprintf(tResult, _T("%3d�� "), index); 
		csResult += tResult;

		csResult += _T("�� ");            
		csResult += index&32?_T("��"):_T("ż");
		csResult += index&16?_T("С"):_T("��");
		csResult += _T(" ʮ ");            
		csResult += index&8?_T("��"):_T("ż"); 
		csResult += index&4?_T("С"):_T("��"); 
		csResult += _T(" �� ");            
		csResult += index&2?_T("��"):_T("ż"); 
		csResult += index&1?_T("С"):_T("��"); 
		csResult += _T(":");          

		_stprintf(tResult, _T("%6lld(%4.1f%% %6lld/%6lld)\r\n"), m_result[i].second, (double)100 * m_result[i].second / valuetotal, m_result[i].second, valuetotal);
		csResult += tResult;
	}
	CEdit edit2;
	edit2.Attach(GetDlgItem(IDC_EDITRESULT)->m_hWnd);
	edit2.SetWindowText(csResult);
	edit2.Detach();
}
