// GDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication7.h"
#include "GDialog.h"
#include "afxdialogex.h"


// GDialog 对话框

IMPLEMENT_DYNAMIC(GDialog, CDialogEx)

GDialog::GDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, gname(_T(""))
	, gno(_T(""))
	, gdept(_T(""))
	, gsex(_T(""))
	, gage(_T(""))
	, gphone(_T(""))
	, gaddress(_T(""))
	, gpic_name(_T(""))
	, gpic_path(_T(""))
{

}

GDialog::~GDialog()
{
}

void GDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, gname);
	DDX_Text(pDX, IDC_EDIT2, gno);
	DDX_Text(pDX, IDC_EDIT3, gdept);
	DDX_Text(pDX, IDC_EDIT4, gsex);
	DDX_Text(pDX, IDC_EDIT5, gage);
	DDX_Text(pDX, IDC_EDIT6, gphone);
	DDX_Text(pDX, IDC_EDIT7, gaddress);
	DDX_Text(pDX, IDC_EDIT8, gpic_name);
	DDX_Text(pDX, IDC_EDIT9, gpic_path);
}


BEGIN_MESSAGE_MAP(GDialog, CDialogEx)
END_MESSAGE_MAP()


// GDialog 消息处理程序
