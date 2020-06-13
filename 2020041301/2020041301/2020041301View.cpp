
// 2020041301View.cpp : CMy2020041301View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2020041301.h"
#endif

#include "2020041301Doc.h"
#include "2020041301View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020041301View

IMPLEMENT_DYNCREATE(CMy2020041301View, CView)

BEGIN_MESSAGE_MAP(CMy2020041301View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy2020041301View 构造/析构

CMy2020041301View::CMy2020041301View()
{
	// TODO: 在此处添加构造代码

}

CMy2020041301View::~CMy2020041301View()
{
}

BOOL CMy2020041301View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy2020041301View 绘制

void CMy2020041301View::OnDraw(CDC* pDC)
{
	CMy2020041301Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag == 1) {
		cr.SetRect(500, 300, 700, 400);
		h_height = 50;
		h_width = 100;
		p.SetPoint(600, 350);
		flag = 0;
		pDC->Rectangle(cr);
	}
	else {
		pDC->Rectangle(p.x - h_width, p.y - h_height, p.x + h_width, p.y + h_height);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy2020041301View 打印

BOOL CMy2020041301View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2020041301View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2020041301View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy2020041301View 诊断

#ifdef _DEBUG
void CMy2020041301View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020041301View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020041301Doc* CMy2020041301View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020041301Doc)));
	return (CMy2020041301Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020041301View 消息处理程序


void CMy2020041301View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 2;
	CView::OnLButtonDown(nFlags, point);
}


void CMy2020041301View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 3;
	CView::OnLButtonUp(nFlags, point);
}


void CMy2020041301View::OnMouseMove(UINT nFlags, CPoint point)
{

	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 2) {
		
		p = point;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}
