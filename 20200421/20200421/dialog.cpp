// dialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "20200421.h"
#include "dialog.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "20200421View.h"

// dialog �Ի���

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


// dialog ��Ϣ�������


void dialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20200421View* pView = (CMy20200421View*)pFrame->GetActiveView();
	CString path = pView->path;
	CImage img;
	img.Load(path);
	CWnd *pWnd = GetDlgItem(IDC_STATIC);
	CDC* pDC = pWnd->GetDC();
	CRect rect;
	pWnd->GetClientRect(&rect);  //��ȡ��С
	SetStretchBltMode(pDC->m_hDC, HALFTONE); //ͼƬ��ʧ��
	img.StretchBlt(pDC->m_hDC, rect);
}
