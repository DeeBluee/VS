
// 2020041302View.cpp : CMy2020041302View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2020041302.h"
#endif

#include "2020041302Doc.h"
#include "2020041302View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "Calculate.h"

// CMy2020041302View

IMPLEMENT_DYNCREATE(CMy2020041302View, CView)

BEGIN_MESSAGE_MAP(CMy2020041302View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_CALCULATE, &CMy2020041302View::OnCalculate)
END_MESSAGE_MAP()

// CMy2020041302View ����/����

CMy2020041302View::CMy2020041302View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy2020041302View::~CMy2020041302View()
{
}

BOOL CMy2020041302View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2020041302View ����

void CMy2020041302View::OnDraw(CDC* /*pDC*/)
{
	CMy2020041302Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2020041302View ��ӡ

BOOL CMy2020041302View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2020041302View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2020041302View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy2020041302View ���

#ifdef _DEBUG
void CMy2020041302View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020041302View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020041302Doc* CMy2020041302View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020041302Doc)));
	return (CMy2020041302Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020041302View ��Ϣ�������


void CMy2020041302View::OnCalculate()
{
	Calculate cal;
	int r = cal.DoModal();
	if (r == IDOK) {

	}
	// TODO: �ڴ���������������
}
