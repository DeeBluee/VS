
// 2020042701View.cpp : CMy2020042701View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2020042701.h"
#endif

#include "2020042701Doc.h"
#include "2020042701View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020042701View

IMPLEMENT_DYNCREATE(CMy2020042701View, CView)

BEGIN_MESSAGE_MAP(CMy2020042701View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_NCLBUTTONDOWN()
	ON_WM_NCLBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy2020042701View 构造/析构

CMy2020042701View::CMy2020042701View()
{
	// TODO: 在此处添加构造代码

}

CMy2020042701View::~CMy2020042701View()
{
}

BOOL CMy2020042701View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy2020042701View 绘制

void CMy2020042701View::OnDraw(CDC* pDC)
{
	CMy2020042701Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (!pDoc->ca.IsEmpty()) {
		for (int i = 0; i < pDoc->ca.GetSize(); i++) {
			pDC->Ellipse(pDoc->ca[i]);
		}
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy2020042701View 打印

BOOL CMy2020042701View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2020042701View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2020042701View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy2020042701View 诊断

#ifdef _DEBUG
void CMy2020042701View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020042701View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020042701Doc* CMy2020042701View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020042701Doc)));
	return (CMy2020042701Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020042701View 消息处理程序






void CMy2020042701View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (state == 1) {
		Invalidate();
		end = point;
		rect.SetRect(start, end);
		GetDC()->Ellipse(rect);

	}
	CView::OnMouseMove(nFlags, point);
}


void CMy2020042701View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	start = point;
	state = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMy2020042701View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (state == 1) {
		state = 0;
		end = point;
		rect.SetRect(start, end);
		GetDC()->Ellipse(rect);
		CMy2020042701Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		pDoc->ca.Add(rect);
	}
	CView::OnLButtonUp(nFlags, point);
}
