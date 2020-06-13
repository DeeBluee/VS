
// 20200330View.cpp : CMy20200330View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "20200330.h"
#endif

#include "20200330Doc.h"
#include "20200330View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20200330View

IMPLEMENT_DYNCREATE(CMy20200330View, CView)

BEGIN_MESSAGE_MAP(CMy20200330View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CMy20200330View::OnFileOpen)
END_MESSAGE_MAP()

// CMy20200330View ����/����

CMy20200330View::CMy20200330View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy20200330View::~CMy20200330View()
{
}

BOOL CMy20200330View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy20200330View ����

void CMy20200330View::OnDraw(CDC* /*pDC*/)
{
	CMy20200330Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy20200330View ��ӡ

BOOL CMy20200330View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy20200330View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy20200330View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy20200330View ���

#ifdef _DEBUG
void CMy20200330View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20200330View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20200330Doc* CMy20200330View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20200330Doc)));
	return (CMy20200330Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20200330View ��Ϣ�������


void CMy20200330View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		CImage image;
		image.Load(filename);
		image.Draw(dc.m_hDC, 0, 0, image.GetWidth(), image.GetHeight());
	}

}
