
// 2020032402View.cpp : CMy2020032402View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2020032402.h"
#endif

#include "2020032402Doc.h"
#include "2020032402View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020032402View

IMPLEMENT_DYNCREATE(CMy2020032402View, CView)

BEGIN_MESSAGE_MAP(CMy2020032402View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy2020032402View ����/����

CMy2020032402View::CMy2020032402View()
{
	// TODO: �ڴ˴���ӹ������
	BITMAP BM;
	bm.LoadBitmap(IDB_BITMAP1);
	bm.GetBitmap(&BM);
	bm_width = BM.bmWidth;
	bm_height = BM.bmHeight;
}

CMy2020032402View::~CMy2020032402View()
{
}

BOOL CMy2020032402View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2020032402View ����

void CMy2020032402View::OnDraw(CDC* pDC)
{
	CMy2020032402Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CDC bmCDC;
	bmCDC.CreateCompatibleDC(NULL);
	bmCDC.SelectObject(bm);
	pDC->BitBlt(0, 0, bm_width, bm_height, &bmCDC, 0, 0, SRCCOPY);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2020032402View ��ӡ

BOOL CMy2020032402View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2020032402View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2020032402View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy2020032402View ���

#ifdef _DEBUG
void CMy2020032402View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020032402View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020032402Doc* CMy2020032402View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020032402Doc)));
	return (CMy2020032402Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020032402View ��Ϣ�������
