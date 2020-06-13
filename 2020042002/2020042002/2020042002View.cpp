
// 2020042002View.cpp : CMy2020042002View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2020042002.h"
#endif

#include "2020042002Doc.h"
#include "2020042002View.h"
#include "Dialog.h"
#include "ColorDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020042002View

IMPLEMENT_DYNCREATE(CMy2020042002View, CView)

BEGIN_MESSAGE_MAP(CMy2020042002View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_Menu, &CMy2020042002View::OnMenu)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_Color, &CMy2020042002View::OnColor)
END_MESSAGE_MAP()

// CMy2020042002View ����/����

CMy2020042002View::CMy2020042002View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy2020042002View::~CMy2020042002View()
{
}

BOOL CMy2020042002View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2020042002View ����

void CMy2020042002View::OnDraw(CDC* pDC)
{
	CMy2020042002Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag == 1) {
		rect.SetRect(startpoint, endpoint);
		pDC->Ellipse(rect);
	}
	if (flag == 2) {
		rect.SetRect(startpoint, endpoint);
		pDC->Rectangle(rect);
		pDC->Ellipse(rect);
		flag = 0;
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2020042002View ��ӡ

BOOL CMy2020042002View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2020042002View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2020042002View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy2020042002View ���

#ifdef _DEBUG
void CMy2020042002View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020042002View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020042002Doc* CMy2020042002View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020042002Doc)));
	return (CMy2020042002Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020042002View ��Ϣ�������


void CMy2020042002View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	startpoint = point;
	flag = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMy2020042002View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	endpoint = point;
	flag = 0;
	rect.SetRect(startpoint, endpoint);
	GetDC()->Ellipse(rect);
	CView::OnLButtonUp(nFlags, point);
}


void CMy2020042002View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag == 1) {
		endpoint = point;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void CMy2020042002View::OnMenu()
{
	// TODO: �ڴ���������������
	Dialog dlg;
	if (dlg.DoModal() == IDOK) {
		UpdateData(TRUE);
		rect.SetRect(dlg.x - (dlg.longaxis/2), dlg.y - (dlg.shortaxis / 2), dlg.x + (dlg.longaxis / 2), dlg.y + (dlg.shortaxis / 2));
		GetDC()->Ellipse(rect);
	}
}



void CMy2020042002View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnRButtonDown(nFlags, point);
	if (point.x <= rect.right&&point.x >= rect.left&&point.y >= rect.top&&point.y <= rect.bottom) {
		flag = 2;
		Invalidate();
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CMy2020042002View::OnColor()
{

	// TODO: �ڴ���������������
	ColorDialog cdlg;
	if (cdlg.DoModal() == IDOK) {
		CDC* pDC = GetDC(); // �õ�zhiDC
		CBrush brush(RGB(cdlg.r, cdlg.g, cdlg.b));//�����Լ���Ҫ��dao���ջ�ɫ
		CBrush *oldbrush;
		oldbrush = pDC->SelectObject(&brush);//ѡ�µĻ�ˢ
		pDC->Ellipse(rect);
		pDC->SelectObject(oldbrush);//��ԭ���Ļ�ˢѡ���ȥ
		ReleaseDC(pDC); // �ͷ�DC
	}
}
