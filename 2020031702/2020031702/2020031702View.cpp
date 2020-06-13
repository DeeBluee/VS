
// 2020031702View.cpp : CMy2020031702View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2020031702.h"
#endif

#include "2020031702Doc.h"
#include "2020031702View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020031702View

IMPLEMENT_DYNCREATE(CMy2020031702View, CView)

BEGIN_MESSAGE_MAP(CMy2020031702View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMy2020031702View ����/����

CMy2020031702View::CMy2020031702View()
{
	// TODO: �ڴ˴���ӹ������
	width = 100;
	height = 50;
	flag = 1;
}

CMy2020031702View::~CMy2020031702View()
{
}

BOOL CMy2020031702View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2020031702View ����

void CMy2020031702View::OnDraw(CDC* pDC)
{
	CMy2020031702Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag==1) {
		flag = 0;
		GetClientRect(&pDoc->CR);
		mx = (pDoc->CR.right - pDoc->CR.left) / 2;
		my = (pDoc->CR.bottom - pDoc->CR.top) / 2;
		x = mx;
		y = my;
		pDoc->cr.SetRect(mx - width, my - height, mx + width, my + height);
		pDC->Rectangle(pDoc->cr);
	}
	else
		pDC->Rectangle(pDoc->cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2020031702View ��ӡ

BOOL CMy2020031702View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2020031702View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2020031702View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy2020031702View ���

#ifdef _DEBUG
void CMy2020031702View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020031702View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020031702Doc* CMy2020031702View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020031702Doc)));
	return (CMy2020031702Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020031702View ��Ϣ�������


void CMy2020031702View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CMy2020031702Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->cr.SetRect(x - 100, y - 50, x + 100, y + 50);
	height = 50, width = 100;
	mx = x, my = y;
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}


void CMy2020031702View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CMy2020031702Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	switch (nChar)
	{
	case VK_LEFT:
	{
		mx -= 50;
		pDoc->cr.SetRect(mx - width, my - height, mx + width, my + height);
		break;
	}
	case VK_RIGHT:
	{
		
		mx += 50;
		pDoc->cr.SetRect(mx - width, my - height, mx + width, my + height);
		break;
	}
	case VK_DOWN:
	{
		
		my += 50;
		pDoc->cr.SetRect(mx - width, my - height, mx + width, my + height);
		break;
	}
	case VK_UP:
	{
		
		my -= 50;
		pDoc->cr.SetRect(mx - width ,my - height, mx + width, my + height);
		break;
	}
	case VK_HOME:
	{
		mx -= width , my -= height;
		width += width;
		height += height;
		
		pDoc->cr.SetRect(mx - width, my - height, mx + width, my + height);
		break;
	}
	case VK_END:
	{
		mx += width / 2, my += height / 2;
		width -= width/2;
		height -= height/2;
		pDoc->cr.SetRect(mx - width, my - height, mx + width, my + height);
		break;
	}
	}
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
