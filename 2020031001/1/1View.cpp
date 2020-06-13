
// 1View.cpp : CMy1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "1.h"
#endif

#include "1Doc.h"
#include "1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1View

IMPLEMENT_DYNCREATE(CMy1View, CView)

BEGIN_MESSAGE_MAP(CMy1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy1View 构造/析构

CMy1View::CMy1View()
{
	// TODO: 在此处添加构造代码

}

CMy1View::~CMy1View()
{
}

BOOL CMy1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy1View 绘制

void CMy1View::OnDraw(CDC* pDC)
{
	CMy1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag == 1) {
		CRect cr;
		CRect Cr;
		this->GetClientRect(&cr);
		if (cr.Width() > cr.Height())
			Cr.SetRect(cr.left, cr.top, cr.left + cr.Height(), cr.bottom);
		else Cr.SetRect(cr.left, cr.top, cr.right, cr.top + cr.Width());
		CClientDC dc(this);
		dc.Ellipse(Cr);
	}
	
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy1View 打印

BOOL CMy1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy1View 诊断

#ifdef _DEBUG
void CMy1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1Doc* CMy1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1Doc)));
	return (CMy1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1View 消息处理程序


void CMy1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 0)
		flag = 1;
	CRect cr;
	CRect Cr;
	this->GetClientRect(&cr);
	if (cr.Width() > cr.Height())
		Cr.SetRect(cr.left, cr.top, cr.left + cr.Height(), cr.bottom);
	else Cr.SetRect(cr.left, cr.top, cr.right, cr.top + cr.Width());
	CClientDC dc(this);
	dc.Ellipse(Cr);
	CView::OnLButtonDown(nFlags, point);
}
