// Calculate.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "2020041302.h"
#include "Calculate.h"
#include "afxdialogex.h"


// Calculate �Ի���

IMPLEMENT_DYNAMIC(Calculate, CDialogEx)

Calculate::Calculate(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, a(0)
	, b(0)
	, d(0)
	, c(_T(""))
{

}

Calculate::~Calculate()
{
}

void Calculate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
	DDX_Text(pDX, IDC_EDIT3, d);
	DDX_Text(pDX, IDC_EDIT4, c);
	DDX_Control(pDX, IDC_LIST1, ch);
}


BEGIN_MESSAGE_MAP(Calculate, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Calculate::OnBnClickedButton1)
END_MESSAGE_MAP()


// Calculate ��Ϣ�������


BOOL Calculate::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	ch.AddString(_T("+"));
	ch.AddString(_T("-"));
	ch.AddString(_T("*"));
	ch.AddString(_T("/"));
	c = "=";
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void Calculate::OnBnClickedButton1()
{
	UpdateData(true);
	ch.GetText(ch.GetCurSel(), e);
	if (e=='+') {
		d = a + b;
	}
	if (e == '-') {
		d = a - b;
	}
	if (e == '*') {
		d = a * b;
	}
	if (e == '/'&&b!=0) {
		d = a / b;
	}
	else if(b==0)  d = -65536;
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
