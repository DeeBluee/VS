
// 2View.cpp : CMy2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2.h"
#endif

#include "2Doc.h"
#include "2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2View

IMPLEMENT_DYNCREATE(CMy2View, CView)

BEGIN_MESSAGE_MAP(CMy2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy2View 构造/析构

CMy2View::CMy2View()
{
	// TODO: 在此处添加构造代码
	ca.SetSize(256);
}

CMy2View::~CMy2View()
{
}

BOOL CMy2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy2View 绘制

void CMy2View::OnDraw(CDC* pDC)
{
	CMy2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca[i]);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy2View 打印

BOOL CMy2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy2View 诊断

#ifdef _DEBUG
void CMy2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2Doc* CMy2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2Doc)));
	return (CMy2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2View 消息处理程序


void CMy2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int w = rand() % 50 + 5;
	int h = rand() % 50 + 5;
	CRect cr(point.x - w, point.y - h, point.x + w, point.y + h);
	ca.Add(cr);
	this->Invalidate();

	CView::OnLButtonDown(nFlags, point);
}
