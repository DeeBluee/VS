
// 20200415View.cpp : CMy20200415View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "20200415.h"
#endif

#include "20200415Doc.h"
#include "20200415View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MyDialog.h"

// CMy20200415View

IMPLEMENT_DYNCREATE(CMy20200415View, CView)

BEGIN_MESSAGE_MAP(CMy20200415View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_DIALOG, &CMy20200415View::OnDialog)
END_MESSAGE_MAP()

// CMy20200415View ����/����

CMy20200415View::CMy20200415View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy20200415View::~CMy20200415View()
{
}

BOOL CMy20200415View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy20200415View ����

void CMy20200415View::OnDraw(CDC* /*pDC*/)
{
	CMy20200415Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy20200415View ��ӡ

BOOL CMy20200415View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy20200415View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy20200415View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy20200415View ���

#ifdef _DEBUG
void CMy20200415View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20200415View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20200415Doc* CMy20200415View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20200415Doc)));
	return (CMy20200415Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20200415View ��Ϣ�������


void CMy20200415View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	

	CFileDialog    dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Describe Files (*.jpg)|*.jpg|All Files (*.*)|*.*||"), NULL);

	if (dlgFile.DoModal())
	{
		strFile = dlgFile.GetFileName();
	}
	GetDC()->TextOutW(500, 500, strFile);
	CView::OnLButtonDblClk(nFlags, point);
}


void CMy20200415View::OnDialog()
{
	MyDialog dlg;
	int r = dlg.DoModal();
	if (r == IDOK) {

	}
	// TODO: �ڴ���������������
}
