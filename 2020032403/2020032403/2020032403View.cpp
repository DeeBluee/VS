
// 2020032403View.cpp : CMy2020032403View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2020032403.h"
#endif

#include "2020032403Doc.h"
#include "2020032403View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020032403View

IMPLEMENT_DYNCREATE(CMy2020032403View, CView)

BEGIN_MESSAGE_MAP(CMy2020032403View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_PAINTLINE, &CMy2020032403View::OnPaintline)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_PAINTRECTANGLE, &CMy2020032403View::OnPaintrectangle)
	ON_COMMAND(ID_PAINTOVAL, &CMy2020032403View::OnPaintoval)
END_MESSAGE_MAP()

// CMy2020032403View 构造/析构

CMy2020032403View::CMy2020032403View()
{
	// TODO: 在此处添加构造代码
	flag = 0; //设置开关默认为0,1为画线，2为画矩形，3为画椭圆；
	set = 0;//控制是否开启鼠标移动监控
}

CMy2020032403View::~CMy2020032403View()
{
}

BOOL CMy2020032403View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy2020032403View 绘制

void CMy2020032403View::OnDraw(CDC* pDC)
{
	CMy2020032403Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag == 1 && set == 1) {
		pDC->MoveTo(start);
		pDC->LineTo(mid);
	}
	if (flag == 2 && set == 1) {
		cr.SetRect(start, end);
		pDC->Rectangle(cr);
	}
	if (flag == 3 && set == 1) {
		cr.SetRect(start, end);
		pDC->Ellipse(cr);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy2020032403View 打印

BOOL CMy2020032403View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2020032403View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2020032403View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy2020032403View 诊断

#ifdef _DEBUG
void CMy2020032403View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020032403View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020032403Doc* CMy2020032403View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020032403Doc)));
	return (CMy2020032403Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020032403View 消息处理程序


void CMy2020032403View::OnPaintline()
{
	flag = 1;
	// TODO: 在此添加命令处理程序代码
}


void CMy2020032403View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 1||2||3) {
		set = 1;
		start = point;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy2020032403View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	if (flag == 1 && set == 1) {
		set = 0;
		end = point;
		dc.MoveTo(start);
		dc.LineTo(end);
	}
	if (flag == 2 && set == 1) {
		set = 0;
		end = point;
		cr.SetRect(start, end);
		dc.Rectangle(cr);
	}
	if (flag == 3 && set == 1) {
		set = 0;
		end = point;
		cr.SetRect(start, end);
		dc.Ellipse(cr);
	}
	CView::OnLButtonUp(nFlags, point);
}


void CMy2020032403View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 1 && set == 1) {
		mid = point;
		Invalidate();
	}
	if (flag == 2 && set == 1) {
		end = point;
		Invalidate();
	}
	if (flag == 3 && set == 1) {
		end = point;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void CMy2020032403View::OnPaintrectangle()
{
	flag = 2;
	// TODO: 在此添加命令处理程序代码
}


void CMy2020032403View::OnPaintoval()
{
	flag = 3;
	// TODO: 在此添加命令处理程序代码
}
