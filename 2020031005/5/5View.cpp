
// 5View.cpp : CMy5View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "5.h"
#endif

#include "5Doc.h"
#include "5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy5View

IMPLEMENT_DYNCREATE(CMy5View, CView)

BEGIN_MESSAGE_MAP(CMy5View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy5View 构造/析构

CMy5View::CMy5View()
{
	// TODO: 在此处添加构造代码

}

CMy5View::~CMy5View()
{
}

BOOL CMy5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy5View 绘制

void CMy5View::OnDraw(CDC* pDC)
{
	CMy5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->A);
	pDC->Rectangle(pDoc->B);
	pDC->Rectangle(pDoc->C);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy5View 打印

BOOL CMy5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy5View 诊断

#ifdef _DEBUG
void CMy5View::AssertValid() const
{
	CView::AssertValid();
}

void CMy5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy5Doc* CMy5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy5Doc)));
	return (CMy5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy5View 消息处理程序


void CMy5View::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s;
	CMy5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (point.x > pDoc->A.left&&point.x<pDoc->A.right&&point.y>pDoc->A.top&&point.y < pDoc->A.bottom) {
		pDoc->a = rand() % 50 + 5;
		s.Format(_T("%d"), pDoc->a);
		dc.TextOutW(point.x, point.y, s);
	}

	else if (point.x > pDoc->B.left&&point.x<pDoc->B.right&&point.y>pDoc->B.top&&point.y < pDoc->B.bottom) {
		pDoc->b = rand() % 50 + 5;
		s.Format(_T("%d"), pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}

	else if (point.x > pDoc->C.left&&point.x<pDoc->C.right&&point.y>pDoc->C.top&&point.y < pDoc->C.bottom) {
		s.Format(_T("%d+%d=%d"), pDoc->a, pDoc->b, pDoc->a + pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}
	else dc.TextOutW(point.x, point.y, _T("点击无效"));
	CView::OnMButtonDown(nFlags, point);
}


void CMy5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s;
	CMy5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (point.x > pDoc->A.left&&point.x<pDoc->A.right&&point.y>pDoc->A.top&&point.y < pDoc->A.bottom) {
		pDoc->a = rand() % 50 + 5;
		s.Format(_T("%d"), pDoc->a);
		dc.TextOutW(point.x, point.y, s);
	}

	else if (point.x > pDoc->B.left&&point.x<pDoc->B.right&&point.y>pDoc->B.top&&point.y < pDoc->B.bottom) {
		pDoc->b = rand() % 50 + 5;
		s.Format(_T("%d"), pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}

	else if (point.x > pDoc->C.left&&point.x<pDoc->C.right&&point.y>pDoc->C.top&&point.y < pDoc->C.bottom) {
		s.Format(_T("%d+%d=%d"), pDoc->a, pDoc->b, pDoc->a + pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}
	else dc.TextOutW(point.x, point.y, _T("点击无效"));
	CView::OnLButtonDown(nFlags, point);
}
