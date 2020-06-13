
// 2020030302View.cpp : CMy2020030302View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2020030302.h"
#endif

#include "2020030302Doc.h"
#include "2020030302View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020030302View

IMPLEMENT_DYNCREATE(CMy2020030302View, CView)

BEGIN_MESSAGE_MAP(CMy2020030302View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy2020030302View 构造/析构

CMy2020030302View::CMy2020030302View()
{
	// TODO: 在此处添加构造代码

}

CMy2020030302View::~CMy2020030302View()
{
}

BOOL CMy2020030302View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy2020030302View 绘制

void CMy2020030302View::OnDraw(CDC* /*pDC*/)
{
	CMy2020030302Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy2020030302View 打印

BOOL CMy2020030302View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2020030302View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2020030302View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy2020030302View 诊断

#ifdef _DEBUG
void CMy2020030302View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020030302View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020030302Doc* CMy2020030302View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020030302Doc)));
	return (CMy2020030302Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020030302View 消息处理程序


void CMy2020030302View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy2020030302Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->count++;
	CView::OnLButtonDown(nFlags, point);
}



void CMy2020030302View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy2020030302Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString ss;
	ss.Format(_T("%d"), pDoc->count);
	GetDC()->TextOutW(600, 600, ss);
	CView::OnRButtonDown(nFlags, point);
}
