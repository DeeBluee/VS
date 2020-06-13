
// 5View.cpp : CMy5View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "5.h"
#endif

#include "5Doc.h"
#include "5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy5View

IMPLEMENT_DYNCREATE(CMy5View, CView)

BEGIN_MESSAGE_MAP(CMy5View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy5View ����/����

CMy5View::CMy5View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy5View::~CMy5View()
{
}

BOOL CMy5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy5View ����

void CMy5View::OnDraw(CDC* pDC)
{
	CMy5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->A);
	pDC->Rectangle(pDoc->B);
	pDC->Rectangle(pDoc->C);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy5View ��ӡ

BOOL CMy5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy5View ���

#ifdef _DEBUG
void CMy5View::AssertValid() const
{
	CView::AssertValid();
}

void CMy5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy5Doc* CMy5View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy5Doc)));
	return (CMy5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy5View ��Ϣ�������


void CMy5View::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString s;
	CMy5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (point.x > pDoc->A.left&&point.x<pDoc->A.right&&point.y>pDoc->A.top&&point.y < pDoc->A.bottom) {
		pDoc->a = rand() % 50 + 5;
		s.Format(_T("%d"), pDoc->a);
		dc.TextOutW(point.x, point.y, s);
	}

	else if (point.x > pDoc->B.left&&point.x<pDoc->B.right&&point.y>pDoc->B.top&&point.y < pDoc->B.bottom) {
		pDoc->b = rand() % 50 + 5;
		s.Format(_T("%d"), pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}

	else if (point.x > pDoc->C.left&&point.x<pDoc->C.right&&point.y>pDoc->C.top&&point.y < pDoc->C.bottom) {
		s.Format(_T("%d+%d=%d"), pDoc->a, pDoc->b, pDoc->a + pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}
	else dc.TextOutW(point.x, point.y, _T("�����Ч"));
	CView::OnMButtonDown(nFlags, point);
}


void CMy5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString s;
	CMy5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (point.x > pDoc->A.left&&point.x<pDoc->A.right&&point.y>pDoc->A.top&&point.y < pDoc->A.bottom) {
		pDoc->a = rand() % 50 + 5;
		s.Format(_T("%d"), pDoc->a);
		dc.TextOutW(point.x, point.y, s);
	}

	else if (point.x > pDoc->B.left&&point.x<pDoc->B.right&&point.y>pDoc->B.top&&point.y < pDoc->B.bottom) {
		pDoc->b = rand() % 50 + 5;
		s.Format(_T("%d"), pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}

	else if (point.x > pDoc->C.left&&point.x<pDoc->C.right&&point.y>pDoc->C.top&&point.y < pDoc->C.bottom) {
		s.Format(_T("%d+%d=%d"), pDoc->a, pDoc->b, pDoc->a + pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}
	else dc.TextOutW(point.x, point.y, _T("�����Ч"));
	CView::OnLButtonDown(nFlags, point);
}
