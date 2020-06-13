
// 2020041303View.cpp : CMy2020041303View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2020041303.h"
#endif

#include "2020041303Doc.h"
#include "2020041303View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020041303View

IMPLEMENT_DYNCREATE(CMy2020041303View, CView)

BEGIN_MESSAGE_MAP(CMy2020041303View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy2020041303View ����/����

CMy2020041303View::CMy2020041303View()
{
	// TODO: �ڴ˴���ӹ������
	p.SetPoint(150, 150);
	x = 50;
	
}

CMy2020041303View::~CMy2020041303View()
{
}

BOOL CMy2020041303View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2020041303View ����

void CMy2020041303View::OnDraw(CDC* pDC)
{
	CMy2020041303Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag == -1) {
		cr.SetRect(p.x - x, p.y - x, p.x + x, p.y + x);
		pDC->Ellipse(cr);
	}
	else {
		cr.SetRect(p.x - x, p.y - x, p.x + x, p.y + x);
		pDC->Ellipse(cr);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2020041303View ��ӡ

BOOL CMy2020041303View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2020041303View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2020041303View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy2020041303View ���

#ifdef _DEBUG
void CMy2020041303View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020041303View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020041303Doc* CMy2020041303View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020041303Doc)));
	return (CMy2020041303Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020041303View ��Ϣ�������


void CMy2020041303View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	f = flag;
	flag = 0;
	KillTimer(1);
	CView::OnLButtonDblClk(nFlags, point);
}


void CMy2020041303View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	GetClientRect(&CR);
	if (flag == 0) { //��ʾ��ͣ���ָ�����һ�ε�״̬
		flag = f;
	}
	else if(flag==-1){
		f = flag;
		flag = 2;
	}
		

	SetTimer(1, 500, NULL);
	CView::OnLButtonDown(nFlags, point);
}


void CMy2020041303View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag == 1) {
		
		if (p.x - x <= 0) {
			f = flag;
			flag = 2;
		}
		else
			p.x -= x;
	}
	else  if (flag == 2) {
		if (p.x + x >= CR.Width()) {
			f = flag;
			flag = 1;
		}
		else
			p.x += x;
	}
	Invalidate();
	
	CView::OnTimer(nIDEvent);
}
