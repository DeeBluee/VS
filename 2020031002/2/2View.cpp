
// 2View.cpp : CMy2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2.h"
#endif

#include "2Doc.h"
#include "2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2View

IMPLEMENT_DYNCREATE(CMy2View, CView)

BEGIN_MESSAGE_MAP(CMy2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy2View ����/����

CMy2View::CMy2View()
{
	// TODO: �ڴ˴���ӹ������
	ca.SetSize(256);
}

CMy2View::~CMy2View()
{
}

BOOL CMy2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2View ����

void CMy2View::OnDraw(CDC* pDC)
{
	CMy2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca[i]);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2View ��ӡ

BOOL CMy2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy2View ���

#ifdef _DEBUG
void CMy2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2Doc* CMy2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2Doc)));
	return (CMy2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2View ��Ϣ�������


void CMy2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int w = rand() % 50 + 5;
	int h = rand() % 50 + 5;
	CRect cr(point.x - w, point.y - h, point.x + w, point.y + h);
	ca.Add(cr);
	this->Invalidate();

	CView::OnLButtonDown(nFlags, point);
}
