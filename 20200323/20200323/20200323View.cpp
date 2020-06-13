
// 20200323View.cpp : CMy20200323View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "20200323.h"
#endif

#include "20200323Doc.h"
#include "20200323View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20200323View

IMPLEMENT_DYNCREATE(CMy20200323View, CView)

BEGIN_MESSAGE_MAP(CMy20200323View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SIZECHANGE, &CMy20200323View::OnSizechange)
	ON_COMMAND(ID_COLORCHANGE, &CMy20200323View::OnColorchange)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy20200323View 构造/析构

CMy20200323View::CMy20200323View()
{
	// TODO: 在此处添加构造代码
	i = 300;
}

CMy20200323View::~CMy20200323View()
{
}

BOOL CMy20200323View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy20200323View 绘制

void CMy20200323View::OnDraw(CDC* pDC)
{
	CMy20200323Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy20200323View 打印

BOOL CMy20200323View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy20200323View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy20200323View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy20200323View 诊断

#ifdef _DEBUG
void CMy20200323View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20200323View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20200323Doc* CMy20200323View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20200323Doc)));
	return (CMy20200323Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20200323View 消息处理程序


void CMy20200323View::OnSizechange()
{
	i = 0;
	// TODO: 在此添加命令处理程序代码
	flag = 1;
	Invalidate();
	SetTimer(1, 100, NULL);
}


void CMy20200323View::OnColorchange()
{
	i = 0;
	flag = 2;
	Invalidate();
	// TODO: 在此添加命令处理程序代码
	SetTimer(2, 100, NULL);
}


void CMy20200323View::OnTimer(UINT_PTR nIDEvent)
{
	CClientDC dc(this);
	//CBrush *OldBrush;
	//OldBrush = (CBrush*)dc.SelectStockObject(NULL_BRUSH);//创建一个不填充的画刷
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent) {
	case 1: {
		CRect RC, rc;
		GetClientRect(&RC);
		CPoint mid;
		mid.SetPoint((RC.right - RC.left) / 2, (RC.bottom - RC.top) / 2);
		if (i <300&&flag==1) {
			rc.SetRect(mid.x - i, mid.y - i, mid.x + i, mid.y + i);
			dc.Ellipse(rc);
			i += 1;
		}
		break;
	}
	case 2: {
		int r = rand() % 256;
		int g = rand() % 256;
		int b = rand() % 256;
		CRect RC, rc;
		GetClientRect(&RC);
		CPoint mid;

		mid.SetPoint((RC.right - RC.left) / 2, (RC.bottom - RC.top) / 2);
		if (i<300&&flag==2) {
			int color = RGB(r, g,b );
			CPen newPen(PS_SOLID, 2, color);
			CPen *oldPen = dc.SelectObject(&newPen);
			rc.SetRect(mid.x - i, mid.y - i, mid.x + i, mid.y + i);
			dc.Ellipse(rc);
			i += 1;
		}
		break;
	}
	}
	CView::OnTimer(nIDEvent);
}
