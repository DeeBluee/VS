
// 2020050401View.cpp : CMy2020050401View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2020050401.h"
#include "20200504lib.h"
#include "20200504DLL.h"
#endif

#include "2020050401Doc.h"
#include "2020050401View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020050401View

IMPLEMENT_DYNCREATE(CMy2020050401View, CView)

BEGIN_MESSAGE_MAP(CMy2020050401View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy2020050401View ����/����

CMy2020050401View::CMy2020050401View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy2020050401View::~CMy2020050401View()
{
}

BOOL CMy2020050401View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2020050401View ����

void CMy2020050401View::OnDraw(CDC* pDC)
{
	CMy2020050401Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CString ss;
	ss.Format(_T("���Ǿ�̬���ӿ�ļ���׳˺���%d"), factorial(5));
	pDC->TextOutW(600, 300, ss);
	FAC fac;
	ss.Format(_T("���Ǿ�̬���ӿ�ĽǶ�ת������%f"), fac.convert(30.0));
	pDC->TextOutW(600, 400, ss);

	ss.Format(_T("���Ƕ�̬���ӿ�ļ���׳˺���%d"), factorial_dll(5));
	pDC->TextOutW(600, 500, ss);
	FAC_dll fac_dll;
	ss.Format(_T("���Ƕ�̬���ӿ�ĽǶ�ת������%f"), fac_dll.convert_dll(30.0));
	pDC->TextOutW(600, 600, ss);


	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2020050401View ��ӡ

BOOL CMy2020050401View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2020050401View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2020050401View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy2020050401View ���

#ifdef _DEBUG
void CMy2020050401View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020050401View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020050401Doc* CMy2020050401View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020050401Doc)));
	return (CMy2020050401Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020050401View ��Ϣ�������
