
// 2020030302View.cpp : CMy2020030302View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2020030302.h"
#endif

#include "2020030302Doc.h"
#include "2020030302View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020030302View

IMPLEMENT_DYNCREATE(CMy2020030302View, CView)

BEGIN_MESSAGE_MAP(CMy2020030302View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy2020030302View ����/����

CMy2020030302View::CMy2020030302View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy2020030302View::~CMy2020030302View()
{
}

BOOL CMy2020030302View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2020030302View ����

void CMy2020030302View::OnDraw(CDC* /*pDC*/)
{
	CMy2020030302Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2020030302View ��ӡ

BOOL CMy2020030302View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2020030302View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2020030302View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy2020030302View ���

#ifdef _DEBUG
void CMy2020030302View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020030302View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020030302Doc* CMy2020030302View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020030302Doc)));
	return (CMy2020030302Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020030302View ��Ϣ�������


void CMy2020030302View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy2020030302Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->count++;
	CView::OnLButtonDown(nFlags, point);
}



void CMy2020030302View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy2020030302Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString ss;
	ss.Format(_T("%d"), pDoc->count);
	GetDC()->TextOutW(600, 600, ss);
	CView::OnRButtonDown(nFlags, point);
}
