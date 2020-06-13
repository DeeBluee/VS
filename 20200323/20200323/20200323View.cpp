
// 20200323View.cpp : CMy20200323View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "20200323.h"
#endif

#include "20200323Doc.h"
#include "20200323View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20200323View

IMPLEMENT_DYNCREATE(CMy20200323View, CView)

BEGIN_MESSAGE_MAP(CMy20200323View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SIZECHANGE, &CMy20200323View::OnSizechange)
	ON_COMMAND(ID_COLORCHANGE, &CMy20200323View::OnColorchange)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy20200323View ����/����

CMy20200323View::CMy20200323View()
{
	// TODO: �ڴ˴���ӹ������
	i = 300;
}

CMy20200323View::~CMy20200323View()
{
}

BOOL CMy20200323View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy20200323View ����

void CMy20200323View::OnDraw(CDC* pDC)
{
	CMy20200323Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy20200323View ��ӡ

BOOL CMy20200323View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy20200323View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy20200323View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy20200323View ���

#ifdef _DEBUG
void CMy20200323View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20200323View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20200323Doc* CMy20200323View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20200323Doc)));
	return (CMy20200323Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20200323View ��Ϣ�������


void CMy20200323View::OnSizechange()
{
	i = 0;
	// TODO: �ڴ���������������
	flag = 1;
	Invalidate();
	SetTimer(1, 100, NULL);
}


void CMy20200323View::OnColorchange()
{
	i = 0;
	flag = 2;
	Invalidate();
	// TODO: �ڴ���������������
	SetTimer(2, 100, NULL);
}


void CMy20200323View::OnTimer(UINT_PTR nIDEvent)
{
	CClientDC dc(this);
	//CBrush *OldBrush;
	//OldBrush = (CBrush*)dc.SelectStockObject(NULL_BRUSH);//����һ�������Ļ�ˢ
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nIDEvent) {
	case 1: {
		CRect RC, rc;
		GetClientRect(&RC);
		CPoint mid;
		mid.SetPoint((RC.right - RC.left) / 2, (RC.bottom - RC.top) / 2);
		if (i <300&&flag==1) {
			rc.SetRect(mid.x - i, mid.y - i, mid.x + i, mid.y + i);
			dc.Ellipse(rc);
			i += 1;
		}
		break;
	}
	case 2: {
		int r = rand() % 256;
		int g = rand() % 256;
		int b = rand() % 256;
		CRect RC, rc;
		GetClientRect(&RC);
		CPoint mid;

		mid.SetPoint((RC.right - RC.left) / 2, (RC.bottom - RC.top) / 2);
		if (i<300&&flag==2) {
			int color = RGB(r, g,b );
			CPen newPen(PS_SOLID, 2, color);
			CPen *oldPen = dc.SelectObject(&newPen);
			rc.SetRect(mid.x - i, mid.y - i, mid.x + i, mid.y + i);
			dc.Ellipse(rc);
			i += 1;
		}
		break;
	}
	}
	CView::OnTimer(nIDEvent);
}
