// Order_Dialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication7.h"
#include "Order_Dialog.h"
#include "afxdialogex.h"


// Order_Dialog �Ի���

IMPLEMENT_DYNAMIC(Order_Dialog, CDialogEx)

Order_Dialog::Order_Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Order, pParent)
	, order_by(_T(""))
{

}

Order_Dialog::~Order_Dialog()
{
}

void Order_Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, order_by);
}


BEGIN_MESSAGE_MAP(Order_Dialog, CDialogEx)
END_MESSAGE_MAP()


// Order_Dialog ��Ϣ�������
