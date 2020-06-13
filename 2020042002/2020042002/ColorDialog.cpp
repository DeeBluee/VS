// ColorDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "2020042002.h"
#include "ColorDialog.h"
#include "afxdialogex.h"


// ColorDialog 对话框

IMPLEMENT_DYNAMIC(ColorDialog, CDialogEx)

ColorDialog::ColorDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, r(0)
	, g(0)
	, b(0)
{

}

ColorDialog::~ColorDialog()
{
}

void ColorDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, r);
	DDX_Text(pDX, IDC_EDIT2, g);
	DDX_Text(pDX, IDC_EDIT3, b);
}


BEGIN_MESSAGE_MAP(ColorDialog, CDialogEx)
END_MESSAGE_MAP()


// ColorDialog 消息处理程序
