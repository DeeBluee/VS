
// 2020031703View.cpp : CMy2020031703View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2020031703.h"
#endif

#include "2020031703Doc.h"
#include "2020031703View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020031703View

IMPLEMENT_DYNCREATE(CMy2020031703View, CView)

BEGIN_MESSAGE_MAP(CMy2020031703View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy2020031703View ����/����

CMy2020031703View::CMy2020031703View()
{
	// TODO: �ڴ˴���ӹ������
	cr.SetRect(0, 0, 200, 200);
}

CMy2020031703View::~CMy2020031703View()
{
}

BOOL CMy2020031703View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2020031703View ����

void CMy2020031703View::OnDraw(CDC* pDC)
{
	CMy2020031703Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	if (set==1) {
		SetTimer(1, rand() & 100 + 1, NULL);
	}

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2020031703View ��ӡ

BOOL CMy2020031703View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2020031703View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2020031703View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy2020031703View ���

#ifdef _DEBUG
void CMy2020031703View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020031703View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020031703Doc* CMy2020031703View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020031703Doc)));
	return (CMy2020031703Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020031703View ��Ϣ�������


void CMy2020031703View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CRect CR;
	GetClientRect(&CR);
	if (nIDEvent == 1) {
		cr.top += 10*f;
		cr.bottom += 10*f;
		if (cr.bottom > CR.bottom)
			f = -1;
		if (cr.top < CR.top)
		set = 0;
		Invalidate();
	}
	
	CView::OnTimer(nIDEvent);
}
