
// 2020031702View.cpp : CMy2020031702View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2020031702.h"
#endif

#include "2020031702Doc.h"
#include "2020031702View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020031702View

IMPLEMENT_DYNCREATE(CMy2020031702View, CView)

BEGIN_MESSAGE_MAP(CMy2020031702View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMy2020031702View 构造/析构

CMy2020031702View::CMy2020031702View()
{
	// TODO: 在此处添加构造代码
	width = 100;
	height = 50;
	flag = 1;
}

CMy2020031702View::~CMy2020031702View()
{
}

BOOL CMy2020031702View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy2020031702View 绘制

void CMy2020031702View::OnDraw(CDC* pDC)
{
	CMy2020031702Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag==1) {
		flag = 0;
		GetClientRect(&pDoc->CR);
		mx = (pDoc->CR.right - pDoc->CR.left) / 2;
		my = (pDoc->CR.bottom - pDoc->CR.top) / 2;
		x = mx;
		y = my;
		pDoc->cr.SetRect(mx - width, my - height, mx + width, my + height);
		pDC->Rectangle(pDoc->cr);
	}
	else
		pDC->Rectangle(pDoc->cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy2020031702View 打印

BOOL CMy2020031702View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2020031702View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2020031702View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy2020031702View 诊断

#ifdef _DEBUG
void CMy2020031702View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020031702View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020031702Doc* CMy2020031702View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020031702Doc)));
	return (CMy2020031702Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020031702View 消息处理程序


void CMy2020031702View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CMy2020031702Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->cr.SetRect(x - 100, y - 50, x + 100, y + 50);
	height = 50, width = 100;
	mx = x, my = y;
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}


void CMy2020031702View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CMy2020031702Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	switch (nChar)
	{
	case VK_LEFT:
	{
		mx -= 50;
		pDoc->cr.SetRect(mx - width, my - height, mx + width, my + height);
		break;
	}
	case VK_RIGHT:
	{
		
		mx += 50;
		pDoc->cr.SetRect(mx - width, my - height, mx + width, my + height);
		break;
	}
	case VK_DOWN:
	{
		
		my += 50;
		pDoc->cr.SetRect(mx - width, my - height, mx + width, my + height);
		break;
	}
	case VK_UP:
	{
		
		my -= 50;
		pDoc->cr.SetRect(mx - width ,my - height, mx + width, my + height);
		break;
	}
	case VK_HOME:
	{
		mx -= width , my -= height;
		width += width;
		height += height;
		
		pDoc->cr.SetRect(mx - width, my - height, mx + width, my + height);
		break;
	}
	case VK_END:
	{
		mx += width / 2, my += height / 2;
		width -= width/2;
		height -= height/2;
		pDoc->cr.SetRect(mx - width, my - height, mx + width, my + height);
		break;
	}
	}
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
