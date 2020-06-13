
// 3View.cpp : CMy3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.h"
#endif

#include "3Doc.h"
#include "3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3View

IMPLEMENT_DYNCREATE(CMy3View, CView)

BEGIN_MESSAGE_MAP(CMy3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy3View ����/����

CMy3View::CMy3View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy3View::~CMy3View()
{
}

BOOL CMy3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy3View ����

void CMy3View::OnDraw(CDC* /*pDC*/)
{
	CMy3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy3View ��ӡ

BOOL CMy3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy3View ���

#ifdef _DEBUG
void CMy3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3Doc* CMy3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3Doc)));
	return (CMy3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3View ��Ϣ�������


void CMy3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString s;
	s = _T("�����������");
	dc.TextOutW(200, 200, s);

	CView::OnLButtonDown(nFlags, point);
}


void CMy3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString s;
	s = _T("�������̧��");
	dc.TextOutW(400, 400, s);
	CView::OnLButtonUp(nFlags, point);
}
