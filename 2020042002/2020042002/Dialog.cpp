// Dialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "2020042002.h"
#include "Dialog.h"
#include "afxdialogex.h"


// Dialog �Ի���

IMPLEMENT_DYNAMIC(Dialog, CDialogEx)

Dialog::Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, longaxis(0)
	, shortaxis(0)
	, x(0)
	, y(0)
{

}

Dialog::~Dialog()
{
}

void Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, longaxis);
	DDX_Text(pDX, IDC_EDIT2, shortaxis);
	DDX_Text(pDX, IDC_EDIT4, x);
	DDX_Text(pDX, IDC_EDIT5, y);
}


BEGIN_MESSAGE_MAP(Dialog, CDialogEx)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


// Dialog ��Ϣ�������


