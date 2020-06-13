// SDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication7.h"
#include "SDialog.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "MFCApplication7View.h"

// SDialog 对话框

IMPLEMENT_DYNAMIC(SDialog, CDialogEx)

SDialog::SDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

SDialog::~SDialog()
{
}

void SDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SDialog, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// SDialog 消息处理程序


void SDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()

	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCApplication7View* pView = (CMFCApplication7View*)pMainFrame->GetActiveView();
	CString path = pView->path;
	CImage img;
	img.Load(path);
	CWnd* pWnd = GetDlgItem(IDC_2);
	CDC* pDC = pWnd->GetDC();
	CRect rect;
	pWnd->GetClientRect(&rect);
	SetStretchBltMode(pDC->m_hDC, HALFTONE);
	img.StretchBlt(pDC->m_hDC, rect);




}
