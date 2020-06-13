
// 4View.cpp : CMy4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "4.h"
#endif

#include "4Doc.h"
#include "4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy4View

IMPLEMENT_DYNCREATE(CMy4View, CView)

BEGIN_MESSAGE_MAP(CMy4View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy4View 构造/析构

CMy4View::CMy4View()
{
	// TODO: 在此处添加构造代码

}

CMy4View::~CMy4View()
{
}

BOOL CMy4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy4View 绘制

void CMy4View::OnDraw(CDC* /*pDC*/)
{
	CMy4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy4View 打印

BOOL CMy4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy4View 诊断

#ifdef _DEBUG
void CMy4View::AssertValid() const
{
	CView::AssertValid();
}

void CMy4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy4Doc* CMy4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy4Doc)));
	return (CMy4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy4View 消息处理程序


void CMy4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	CString s;
	s.Format(_T("%d+%d=%d"), pDoc->A, pDoc->B, pDoc->A + pDoc->B);
	dc.TextOutW(point.x, point.y, s);
	CView::OnLButtonDown(nFlags, point);
}
