
// 20200427Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "20200427.h"
#include "20200427Dlg.h"
#include "afxdialogex.h"
#include "fstream"
#include "string"
#include "iostream"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMy20200427Dlg �Ի���



CMy20200427Dlg::CMy20200427Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY20200427_DIALOG, pParent)
	, data(_T(""))
	
{

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy20200427Dlg::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, LBox);
	DDX_Text(pDX, IDC_EDIT1, data);
}

BEGIN_MESSAGE_MAP(CMy20200427Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_LBN_SELCHANGE(IDC_LIST1, &CMy20200427Dlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy20200427Dlg::OnBnClickedButton1)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CMy20200427Dlg ��Ϣ�������

BOOL CMy20200427Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	
	CFileDialog cfd(true);
	
	if (cfd.DoModal() == IDOK) {
		filename = cfd.GetPathName();
	}
	ifstream ifs(filename);
	string s;
	CString ss;
	while (ifs >> s) {
		ss = s.c_str();
		LBox.AddString(ss);
	}
	
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy20200427Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy20200427Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��


CMy20200427Dlg::~CMy20200427Dlg()
{
	
	ofstream ofs(filename);
	ofs << CT2A(save_data.GetString());

}
//void CMy20200427Dlg::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	
//		
//	
//	
//	CDialogEx::OnLButtonDown(nFlags, point);
//}





void CMy20200427Dlg::OnLbnSelchangeList1()
{
	if (LBox.GetCurSel() != -1) {
		LBox.GetText(LBox.GetCurSel(), data);
		UpdateData(false);
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy20200427Dlg::OnBnClickedButton1()
{
	UpdateData(true);
	int r = LBox.GetCurSel();
	LBox.DeleteString(r);
	LBox.InsertString(r, data);

	int total = LBox.GetCount();
	int i = 0;
	for (; i < total; i++) {
	CString s;
	LBox.GetText(i, s);
	save_data += s;
	save_data += "\r";
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy20200427Dlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnClose();
}
