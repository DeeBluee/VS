
// Text1View.cpp : CText1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Text1.h"
#endif

#include "Text1Doc.h"
#include "Text1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CText1View

IMPLEMENT_DYNCREATE(CText1View, CView)

BEGIN_MESSAGE_MAP(CText1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CText1View ����/����

CText1View::CText1View()
{
	// TODO: �ڴ˴���ӹ������

}

CText1View::~CText1View()
{
}

BOOL CText1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CText1View ����

void CText1View::OnDraw(CDC* pDC)
{
	CText1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	//CString s = _T("����***");
	//int a = 1;
	//CString A;
	//A.Format(_T("%d"), a);
	//pDC->TextOutW(200, 200, s);  //����pDC�༴�豸������ĳ�Ա����
	//pDC->TextOutW(300, 300, A);

	pDC->TextOutW(200, 200, pDoc->s);
	pDC->TextOutW(300, 300, pDoc->A);


}


// CText1View ���

#ifdef _DEBUG
void CText1View::AssertValid() const
{
	CView::AssertValid();
}

void CText1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CText1Doc* CText1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CText1Doc)));
	return (CText1Doc*)m_pDocument;
}
#endif //_DEBUG


// CText1View ��Ϣ�������


void CText1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CText1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	pDoc->count += 1;
}


void CText1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	CText1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	
	CClientDC dc(this); 
	CString ss;
	ss.Format(_T("%d"), pDoc->count);
	dc.TextOutW(500, 500, ss);
	CView::OnRButtonDown(nFlags, point);

}
