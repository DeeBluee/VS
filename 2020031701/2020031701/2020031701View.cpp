
// 2020031701View.cpp : CMy2020031701View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2020031701.h"
#endif

#include "2020031701Doc.h"
#include "2020031701View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020031701View

IMPLEMENT_DYNCREATE(CMy2020031701View, CView)

BEGIN_MESSAGE_MAP(CMy2020031701View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy2020031701View ����/����

CMy2020031701View::CMy2020031701View()
{
	// TODO: �ڴ˴���ӹ������
}

CMy2020031701View::~CMy2020031701View()
{
}

BOOL CMy2020031701View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2020031701View ����

void CMy2020031701View::OnDraw(CDC* /*pDC*/)
{
	CMy2020031701Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2020031701View ��ӡ

BOOL CMy2020031701View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2020031701View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2020031701View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy2020031701View ���

#ifdef _DEBUG
void CMy2020031701View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020031701View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020031701Doc* CMy2020031701View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020031701Doc)));
	return (CMy2020031701Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020031701View ��Ϣ�������


void CMy2020031701View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	num += 1;
	CView::OnMouseMove(nFlags, point);
}


void CMy2020031701View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	num = 0;
	start = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMy2020031701View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	end = point;
	CString s;
	s.Format(_T("MouseMove������%d�Σ������ƶ�%d�����ط���һ��"), num, abs(start.x - end.x) / num);
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonUp(nFlags, point);
}
