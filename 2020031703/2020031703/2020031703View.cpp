
// 2020031703View.cpp : CMy2020031703View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2020031703.h"
#endif

#include "2020031703Doc.h"
#include "2020031703View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020031703View

IMPLEMENT_DYNCREATE(CMy2020031703View, CView)

BEGIN_MESSAGE_MAP(CMy2020031703View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy2020031703View 构造/析构

CMy2020031703View::CMy2020031703View()
{
	// TODO: 在此处添加构造代码
	cr.SetRect(0, 0, 200, 200);
}

CMy2020031703View::~CMy2020031703View()
{
}

BOOL CMy2020031703View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy2020031703View 绘制

void CMy2020031703View::OnDraw(CDC* pDC)
{
	CMy2020031703Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	if (set==1) {
		SetTimer(1, rand() & 100 + 1, NULL);
	}

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy2020031703View 打印

BOOL CMy2020031703View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2020031703View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2020031703View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy2020031703View 诊断

#ifdef _DEBUG
void CMy2020031703View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020031703View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020031703Doc* CMy2020031703View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020031703Doc)));
	return (CMy2020031703Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020031703View 消息处理程序


void CMy2020031703View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CRect CR;
	GetClientRect(&CR);
	if (nIDEvent == 1) {
		cr.top += 10*f;
		cr.bottom += 10*f;
		if (cr.bottom > CR.bottom)
			f = -1;
		if (cr.top < CR.top)
		set = 0;
		Invalidate();
	}
	
	CView::OnTimer(nIDEvent);
}
