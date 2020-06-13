// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "20200415.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, a(_T(""))
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Control(pDX, IDC_LIST1, b);
	DDX_Text(pDX, IDC_EDIT1, a);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
END_MESSAGE_MAP()


// MyDialog 消息处理程序


BOOL MyDialog::OnInitDialog()
{

	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	pChild = (CMDIChildWnd*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveFrame();
	pView = (CMy20200415View*)pChild->GetActiveView();
	a = pView->strFile;
	b.AddString(pView->strFile);
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
