
// 3View.cpp : CMy3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "3.h"
#endif

#include "3Doc.h"
#include "3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy3View

IMPLEMENT_DYNCREATE(CMy3View, CView)

BEGIN_MESSAGE_MAP(CMy3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy3View 构造/析构

CMy3View::CMy3View()
{
	// TODO: 在此处添加构造代码

}

CMy3View::~CMy3View()
{
}

BOOL CMy3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy3View 绘制

void CMy3View::OnDraw(CDC* /*pDC*/)
{
	CMy3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy3View 打印

BOOL CMy3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy3View 诊断

#ifdef _DEBUG
void CMy3View::AssertValid() const
{
	CView::AssertValid();
}

void CMy3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy3Doc* CMy3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy3Doc)));
	return (CMy3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy3View 消息处理程序


void CMy3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s;
	s = _T("左键正被按下");
	dc.TextOutW(200, 200, s);

	CView::OnLButtonDown(nFlags, point);
}


void CMy3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s;
	s = _T("左键正在抬起");
	dc.TextOutW(400, 400, s);
	CView::OnLButtonUp(nFlags, point);
}
