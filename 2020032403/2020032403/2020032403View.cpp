
// 2020032403View.cpp : CMy2020032403View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2020032403.h"
#endif

#include "2020032403Doc.h"
#include "2020032403View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020032403View

IMPLEMENT_DYNCREATE(CMy2020032403View, CView)

BEGIN_MESSAGE_MAP(CMy2020032403View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_PAINTLINE, &CMy2020032403View::OnPaintline)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_PAINTRECTANGLE, &CMy2020032403View::OnPaintrectangle)
	ON_COMMAND(ID_PAINTOVAL, &CMy2020032403View::OnPaintoval)
END_MESSAGE_MAP()

// CMy2020032403View ����/����

CMy2020032403View::CMy2020032403View()
{
	// TODO: �ڴ˴���ӹ������
	flag = 0; //���ÿ���Ĭ��Ϊ0,1Ϊ���ߣ�2Ϊ�����Σ�3Ϊ����Բ��
	set = 0;//�����Ƿ�������ƶ����
}

CMy2020032403View::~CMy2020032403View()
{
}

BOOL CMy2020032403View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2020032403View ����

void CMy2020032403View::OnDraw(CDC* pDC)
{
	CMy2020032403Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag == 1 && set == 1) {
		pDC->MoveTo(start);
		pDC->LineTo(mid);
	}
	if (flag == 2 && set == 1) {
		cr.SetRect(start, end);
		pDC->Rectangle(cr);
	}
	if (flag == 3 && set == 1) {
		cr.SetRect(start, end);
		pDC->Ellipse(cr);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2020032403View ��ӡ

BOOL CMy2020032403View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2020032403View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2020032403View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy2020032403View ���

#ifdef _DEBUG
void CMy2020032403View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020032403View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020032403Doc* CMy2020032403View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020032403Doc)));
	return (CMy2020032403Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020032403View ��Ϣ�������


void CMy2020032403View::OnPaintline()
{
	flag = 1;
	// TODO: �ڴ���������������
}


void CMy2020032403View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag == 1||2||3) {
		set = 1;
		start = point;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy2020032403View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	if (flag == 1 && set == 1) {
		set = 0;
		end = point;
		dc.MoveTo(start);
		dc.LineTo(end);
	}
	if (flag == 2 && set == 1) {
		set = 0;
		end = point;
		cr.SetRect(start, end);
		dc.Rectangle(cr);
	}
	if (flag == 3 && set == 1) {
		set = 0;
		end = point;
		cr.SetRect(start, end);
		dc.Ellipse(cr);
	}
	CView::OnLButtonUp(nFlags, point);
}


void CMy2020032403View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag == 1 && set == 1) {
		mid = point;
		Invalidate();
	}
	if (flag == 2 && set == 1) {
		end = point;
		Invalidate();
	}
	if (flag == 3 && set == 1) {
		end = point;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void CMy2020032403View::OnPaintrectangle()
{
	flag = 2;
	// TODO: �ڴ���������������
}


void CMy2020032403View::OnPaintoval()
{
	flag = 3;
	// TODO: �ڴ���������������
}
