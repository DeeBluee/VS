
// 2020032401View.cpp : CMy2020032401View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2020032401.h"
#endif

#include "2020032401Doc.h"
#include "2020032401View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020032401View

IMPLEMENT_DYNCREATE(CMy2020032401View, CView)

BEGIN_MESSAGE_MAP(CMy2020032401View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHOWNAME, &CMy2020032401View::OnShowname)
END_MESSAGE_MAP()

// CMy2020032401View ����/����

CMy2020032401View::CMy2020032401View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy2020032401View::~CMy2020032401View()
{
}

BOOL CMy2020032401View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2020032401View ����

void CMy2020032401View::OnDraw(CDC* /*pDC*/)
{
	CMy2020032401Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2020032401View ��ӡ

BOOL CMy2020032401View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2020032401View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2020032401View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy2020032401View ���

#ifdef _DEBUG
void CMy2020032401View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020032401View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020032401Doc* CMy2020032401View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020032401Doc)));
	return (CMy2020032401Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020032401View ��Ϣ�������


void CMy2020032401View::OnShowname()
{
	CClientDC dc(this);
	dc.TextOutW(500, 500, _T("����"));
	// TODO: �ڴ���������������
}
