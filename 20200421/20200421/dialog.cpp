// dialog.cpp : 实现文件
//

#include "stdafx.h"
#include "20200421.h"
#include "dialog.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "20200421View.h"

// dialog 对话框

IMPLEMENT_DYNAMIC(dialog, CDialogEx)

dialog::dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

dialog::~dialog()
{
}

void dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(dialog, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// dialog 消息处理程序


void dialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20200421View* pView = (CMy20200421View*)pFrame->GetActiveView();
	CString path = pView->path;
	CImage img;
	img.Load(path);
	CWnd *pWnd = GetDlgItem(IDC_STATIC);
	CDC* pDC = pWnd->GetDC();
	CRect rect;
	pWnd->GetClientRect(&rect);  //获取大小
	SetStretchBltMode(pDC->m_hDC, HALFTONE); //图片不失真
	img.StretchBlt(pDC->m_hDC, rect);
}
