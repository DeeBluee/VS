// Combine.cpp : 实现文件
//

#include "stdafx.h"
#include "2020041304.h"
#include "Combine.h"
#include "afxdialogex.h"


// Combine 对话框

IMPLEMENT_DYNAMIC(Combine, CDialogEx)

Combine::Combine(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, a1(_T(""))
	, a2(0)
	, a3(_T(""))
{

}

Combine::~Combine()
{
}

void Combine::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a1);
	DDX_Text(pDX, IDC_EDIT2, a2);
	DDX_Text(pDX, IDC_EDIT3, a3);
	DDX_Control(pDX, IDC_BUTTON1, show);
}


BEGIN_MESSAGE_MAP(Combine, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Combine::OnBnClickedButton1)
END_MESSAGE_MAP()


// Combine 消息处理程序


void Combine::OnBnClickedButton1()
{
	UpdateData(true);
	CString s;
	s.Format(_T("%d"), a2);
	a3 = a1 + s;
	UpdateData(false);

	// TODO: 在此添加控件通知处理程序代码
}


BOOL Combine::OnInitDialog()
{
	a1 = "a1";
	a2 = 2;
	CString s;
	s.Format(_T("%d"), a2);
	a3 = a1 + s;
	UpdateData(false);
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
