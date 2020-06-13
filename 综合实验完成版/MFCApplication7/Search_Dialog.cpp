// Search_Dialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication7.h"
#include "Search_Dialog.h"
#include "afxdialogex.h"


// Search_Dialog 对话框

IMPLEMENT_DYNAMIC(Search_Dialog, CDialogEx)

Search_Dialog::Search_Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Search, pParent)
	, search(_T(""))
{

}

Search_Dialog::~Search_Dialog()
{
}

void Search_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, search);
}


BEGIN_MESSAGE_MAP(Search_Dialog, CDialogEx)
END_MESSAGE_MAP()


// Search_Dialog 消息处理程序
