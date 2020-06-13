
// 2020042002View.cpp : CMy2020042002View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CMy2020042002View 构造/析构

CMy2020042002View::CMy2020042002View()
{
	// TODO: 在此处添加构造代码

}

CMy2020042002View::~CMy2020042002View()
{
}

BOOL CMy2020042002View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy2020042002View 绘制

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
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy2020042002View 打印

BOOL CMy2020042002View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2020042002View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2020042002View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy2020042002View 诊断

#ifdef _DEBUG
void CMy2020042002View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020042002View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020042002Doc* CMy2020042002View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020042002Doc)));
	return (CMy2020042002Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020042002View 消息处理程序


void CMy2020042002View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	startpoint = point;
	flag = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMy2020042002View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	endpoint = point;
	flag = 0;
	rect.SetRect(startpoint, endpoint);
	GetDC()->Ellipse(rect);
	CView::OnLButtonUp(nFlags, point);
}


void CMy2020042002View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 1) {
		endpoint = point;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


void CMy2020042002View::OnMenu()
{
	// TODO: 在此添加命令处理程序代码
	Dialog dlg;
	if (dlg.DoModal() == IDOK) {
		UpdateData(TRUE);
		rect.SetRect(dlg.x - (dlg.longaxis/2), dlg.y - (dlg.shortaxis / 2), dlg.x + (dlg.longaxis / 2), dlg.y + (dlg.shortaxis / 2));
		GetDC()->Ellipse(rect);
	}
}



void CMy2020042002View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnRButtonDown(nFlags, point);
	if (point.x <= rect.right&&point.x >= rect.left&&point.y >= rect.top&&point.y <= rect.bottom) {
		flag = 2;
		Invalidate();
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CMy2020042002View::OnColor()
{

	// TODO: 在此添加命令处理程序代码
	ColorDialog cdlg;
	if (cdlg.DoModal() == IDOK) {
		CDC* pDC = GetDC(); // 得到zhiDC
		CBrush brush(RGB(cdlg.r, cdlg.g, cdlg.b));//根据自己需要填dao充颜回色
		CBrush *oldbrush;
		oldbrush = pDC->SelectObject(&brush);//选新的画刷
		pDC->Ellipse(rect);
		pDC->SelectObject(oldbrush);//将原来的画刷选答回去
		ReleaseDC(pDC); // 释放DC
	}
}
