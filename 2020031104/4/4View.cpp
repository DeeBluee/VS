
// 4View.cpp : CMy4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "4.h"
#endif

#include "4Doc.h"
#include "4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy4View

IMPLEMENT_DYNCREATE(CMy4View, CView)

BEGIN_MESSAGE_MAP(CMy4View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy4View ����/����

CMy4View::CMy4View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy4View::~CMy4View()
{
}

BOOL CMy4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy4View ����

void CMy4View::OnDraw(CDC* /*pDC*/)
{
	CMy4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy4View ��ӡ

BOOL CMy4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy4View ���

#ifdef _DEBUG
void CMy4View::AssertValid() const
{
	CView::AssertValid();
}

void CMy4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy4Doc* CMy4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy4Doc)));
	return (CMy4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy4View ��Ϣ�������


void CMy4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	CString s;
	s.Format(_T("%d+%d=%d"), pDoc->A, pDoc->B, pDoc->A + pDoc->B);
	dc.TextOutW(point.x, point.y, s);
	CView::OnLButtonDown(nFlags, point);
}
