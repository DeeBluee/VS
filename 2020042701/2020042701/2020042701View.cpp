
// 2020042701View.cpp : CMy2020042701View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2020042701.h"
#endif

#include "2020042701Doc.h"
#include "2020042701View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020042701View

IMPLEMENT_DYNCREATE(CMy2020042701View, CView)

BEGIN_MESSAGE_MAP(CMy2020042701View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_NCLBUTTONDOWN()
	ON_WM_NCLBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy2020042701View ����/����

CMy2020042701View::CMy2020042701View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy2020042701View::~CMy2020042701View()
{
}

BOOL CMy2020042701View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2020042701View ����

void CMy2020042701View::OnDraw(CDC* pDC)
{
	CMy2020042701Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (!pDoc->ca.IsEmpty()) {
		for (int i = 0; i < pDoc->ca.GetSize(); i++) {
			pDC->Ellipse(pDoc->ca[i]);
		}
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2020042701View ��ӡ

BOOL CMy2020042701View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2020042701View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2020042701View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy2020042701View ���

#ifdef _DEBUG
void CMy2020042701View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020042701View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020042701Doc* CMy2020042701View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020042701Doc)));
	return (CMy2020042701Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020042701View ��Ϣ�������






void CMy2020042701View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (state == 1) {
		Invalidate();
		end = point;
		rect.SetRect(start, end);
		GetDC()->Ellipse(rect);

	}
	CView::OnMouseMove(nFlags, point);
}


void CMy2020042701View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	start = point;
	state = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMy2020042701View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (state == 1) {
		state = 0;
		end = point;
		rect.SetRect(start, end);
		GetDC()->Ellipse(rect);
		CMy2020042701Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		pDoc->ca.Add(rect);
	}
	CView::OnLButtonUp(nFlags, point);
}
