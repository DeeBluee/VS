// SDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication7.h"
#include "SDialog.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "MFCApplication7View.h"

// SDialog �Ի���

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


// SDialog ��Ϣ�������


void SDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()

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
