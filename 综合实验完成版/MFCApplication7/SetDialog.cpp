// SetDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication7.h"
#include "SetDialog.h"
#include "afxdialogex.h"


// SetDialog �Ի���

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


// SetDialog ��Ϣ�������
