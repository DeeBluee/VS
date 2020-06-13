
// 1View.cpp : CMy1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "1.h"
#endif

#include "1Doc.h"
#include "1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1View

IMPLEMENT_DYNCREATE(CMy1View, CView)

BEGIN_MESSAGE_MAP(CMy1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy1View ����/����

CMy1View::CMy1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy1View::~CMy1View()
{
}

BOOL CMy1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy1View ����

void CMy1View::OnDraw(CDC* pDC)
{
	CMy1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag == 1) {
		CRect cr;
		CRect Cr;
		this->GetClientRect(&cr);
		if (cr.Width() > cr.Height())
			Cr.SetRect(cr.left, cr.top, cr.left + cr.Height(), cr.bottom);
		else Cr.SetRect(cr.left, cr.top, cr.right, cr.top + cr.Width());
		CClientDC dc(this);
		dc.Ellipse(Cr);
	}
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy1View ��ӡ

BOOL CMy1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy1View ���

#ifdef _DEBUG
void CMy1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1Doc* CMy1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1Doc)));
	return (CMy1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1View ��Ϣ�������


void CMy1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag == 0)
		flag = 1;
	CRect cr;
	CRect Cr;
	this->GetClientRect(&cr);
	if (cr.Width() > cr.Height())
		Cr.SetRect(cr.left, cr.top, cr.left + cr.Height(), cr.bottom);
	else Cr.SetRect(cr.left, cr.top, cr.right, cr.top + cr.Width());
	CClientDC dc(this);
	dc.Ellipse(Cr);
	CView::OnLButtonDown(nFlags, point);
}
