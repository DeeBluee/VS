
// 2020041301View.cpp : CMy2020041301View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2020041301.h"
#endif

#include "2020041301Doc.h"
#include "2020041301View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020041301View

IMPLEMENT_DYNCREATE(CMy2020041301View, CView)

BEGIN_MESSAGE_MAP(CMy2020041301View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy2020041301View ����/����

CMy2020041301View::CMy2020041301View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy2020041301View::~CMy2020041301View()
{
}

BOOL CMy2020041301View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2020041301View ����

void CMy2020041301View::OnDraw(CDC* pDC)
{
	CMy2020041301Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag == 1) {
		cr.SetRect(500, 300, 700, 400);
		h_height = 50;
		h_width = 100;
		p.SetPoint(600, 350);
		flag = 0;
		pDC->Rectangle(cr);
	}
	else {
		pDC->Rectangle(p.x - h_width, p.y - h_height, p.x + h_width, p.y + h_height);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2020041301View ��ӡ

BOOL CMy2020041301View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2020041301View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2020041301View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy2020041301View ���

#ifdef _DEBUG
void CMy2020041301View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020041301View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020041301Doc* CMy2020041301View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020041301Doc)));
	return (CMy2020041301Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020041301View ��Ϣ�������


void CMy2020041301View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 2;
	CView::OnLButtonDown(nFlags, point);
}


void CMy2020041301View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 3;
	CView::OnLButtonUp(nFlags, point);
}


void CMy2020041301View::OnMouseMove(UINT nFlags, CPoint point)
{

	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag == 2) {
		
		p = point;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}
