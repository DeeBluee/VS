
// 2020041304View.cpp : CMy2020041304View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2020041304.h"
#endif

#include "2020041304Doc.h"
#include "2020041304View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "Combine.h"

// CMy2020041304View

IMPLEMENT_DYNCREATE(CMy2020041304View, CView)

BEGIN_MESSAGE_MAP(CMy2020041304View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy2020041304View ����/����

CMy2020041304View::CMy2020041304View()
{
	// TODO: �ڴ˴����ӹ������

}

CMy2020041304View::~CMy2020041304View()
{
}

BOOL CMy2020041304View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2020041304View ����

void CMy2020041304View::OnDraw(CDC* /*pDC*/)
{
	CMy2020041304Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	Combine c;
	int r = c.DoModal();
	if (r == IDOK) {

	}
	// TODO: �ڴ˴�Ϊ�����������ӻ��ƴ���
}


// CMy2020041304View ��ӡ

BOOL CMy2020041304View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2020041304View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ���Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2020041304View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ���Ӵ�ӡ����е���������
}


// CMy2020041304View ���

#ifdef _DEBUG
void CMy2020041304View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020041304View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020041304Doc* CMy2020041304View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020041304Doc)));
	return (CMy2020041304Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020041304View ��Ϣ��������