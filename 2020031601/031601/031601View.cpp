
// 031601View.cpp : CMy031601View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "031601.h"
#endif

#include "031601Doc.h"
#include "031601View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy031601View

IMPLEMENT_DYNCREATE(CMy031601View, CView)

BEGIN_MESSAGE_MAP(CMy031601View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy031601View 构造/析构

CMy031601View::CMy031601View()
{
	// TODO: 在此处添加构造代码

}

CMy031601View::~CMy031601View()
{
}

BOOL CMy031601View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy031601View 绘制

void CMy031601View::OnDraw(CDC* /*pDC*/)
{
	CMy031601Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy031601View 打印

BOOL CMy031601View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy031601View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy031601View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy031601View 诊断

#ifdef _DEBUG
void CMy031601View::AssertValid() const
{
	CView::AssertValid();
}

void CMy031601View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy031601Doc* CMy031601View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy031601Doc)));
	return (CMy031601Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy031601View 消息处理程序


void CMy031601View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy031601Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->x1 = point.x;
	pDoc->y1 = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMy031601View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy031601Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->x2 = point.x;
	pDoc->y2 = point.y;
	CRect rc;
	rc.SetRect(pDoc->x1, pDoc->y1, pDoc->x2, pDoc->y2);
	CClientDC dc(this);
	dc.Rectangle(rc);
	CView::OnLButtonUp(nFlags, point);
}


void CMy031601View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString ss;
	ss.Format(_T("X=%d  Y=%d"), point.x, point.y);
	dc.TextOutW(100, 100, ss);

	CView::OnMouseMove(nFlags, point);
}
