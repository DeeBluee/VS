// SetDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication7.h"
#include "SetDialog.h"
#include "afxdialogex.h"


// SetDialog 对话框

IMPLEMENT_DYNAMIC(SetDialog, CDialogEx)

SetDialog::SetDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, set(_T(""))
{

}

SetDialog::~SetDialog()
{
}

void SetDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, set);
}


BEGIN_MESSAGE_MAP(SetDialog, CDialogEx)
END_MESSAGE_MAP()


// SetDialog 消息处理程序
