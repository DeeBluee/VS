// ADialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication7.h"
#include "ADialog.h"
#include "afxdialogex.h"


// ADialog 对话框

IMPLEMENT_DYNAMIC(ADialog, CDialogEx)

ADialog::ADialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, aname(_T(""))
	, ano(_T(""))
	, adept(_T(""))
	, asex(_T(""))
	, aage(_T(""))
	, aphone(_T(""))
	, aaddress(_T(""))
	, apic_name(_T(""))
	, apic_path(_T(""))
{

}

ADialog::~ADialog()
{
}

void ADialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, aname);
	DDX_Text(pDX, IDC_EDIT2, ano);
	DDX_Text(pDX, IDC_EDIT3, adept);
	DDX_Text(pDX, IDC_EDIT4, asex);
	DDX_Text(pDX, IDC_EDIT5, aage);
	DDX_Text(pDX, IDC_EDIT6, aphone);
	DDX_Text(pDX, IDC_EDIT7, aaddress);
	DDX_Text(pDX, IDC_EDIT8, apic_name);
	DDX_Text(pDX, IDC_EDIT9, apic_path);
}


BEGIN_MESSAGE_MAP(ADialog, CDialogEx)
END_MESSAGE_MAP()


// ADialog 消息处理程序
