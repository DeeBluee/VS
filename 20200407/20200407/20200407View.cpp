
// 20200407View.cpp : CMy20200407View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "20200407.h"
#endif
#include "MyDialog.h"
#include "20200407Doc.h"
#include "20200407View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20200407View

IMPLEMENT_DYNCREATE(CMy20200407View, CView)

BEGIN_MESSAGE_MAP(CMy20200407View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_PopDialog, &CMy20200407View::OnPopdialog)
END_MESSAGE_MAP()

// CMy20200407View ����/����

CMy20200407View::CMy20200407View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy20200407View::~CMy20200407View()
{
}

BOOL CMy20200407View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy20200407View ����

void CMy20200407View::OnDraw(CDC* /*pDC*/)
{
	CMy20200407Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy20200407View ��ӡ

BOOL CMy20200407View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy20200407View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy20200407View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy20200407View ���

#ifdef _DEBUG
void CMy20200407View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20200407View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20200407Doc* CMy20200407View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20200407Doc)));
	return (CMy20200407Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20200407View ��Ϣ�������


void CMy20200407View::OnPopdialog()
{
	MyDialog myDialog;
	int r = myDialog.DoModal();
	if (r == IDOK) {
		CString s = _T("�����˳��Ի���");
		GetDC()->TextOutW(500, 500, s);
	}
	
	// TODO: �ڴ���������������
}
