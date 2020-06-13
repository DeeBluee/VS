
// 031601View.cpp : CMy031601View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "031601.h"
#endif

#include "031601Doc.h"
#include "031601View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy031601View

IMPLEMENT_DYNCREATE(CMy031601View, CView)

BEGIN_MESSAGE_MAP(CMy031601View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy031601View ����/����

CMy031601View::CMy031601View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy031601View::~CMy031601View()
{
}

BOOL CMy031601View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy031601View ����

void CMy031601View::OnDraw(CDC* /*pDC*/)
{
	CMy031601Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy031601View ��ӡ

BOOL CMy031601View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy031601View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy031601View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy031601View ���

#ifdef _DEBUG
void CMy031601View::AssertValid() const
{
	CView::AssertValid();
}

void CMy031601View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy031601Doc* CMy031601View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy031601Doc)));
	return (CMy031601Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy031601View ��Ϣ�������


void CMy031601View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy031601Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->x1 = point.x;
	pDoc->y1 = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMy031601View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy031601Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->x2 = point.x;
	pDoc->y2 = point.y;
	CRect rc;
	rc.SetRect(pDoc->x1, pDoc->y1, pDoc->x2, pDoc->y2);
	CClientDC dc(this);
	dc.Rectangle(rc);
	CView::OnLButtonUp(nFlags, point);
}


void CMy031601View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString ss;
	ss.Format(_T("X=%d  Y=%d"), point.x, point.y);
	dc.TextOutW(100, 100, ss);

	CView::OnMouseMove(nFlags, point);
}
