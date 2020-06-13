
// 2020041302View.cpp : CMy2020041302View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2020041302.h"
#endif

#include "2020041302Doc.h"
#include "2020041302View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "Calculate.h"

// CMy2020041302View

IMPLEMENT_DYNCREATE(CMy2020041302View, CView)

BEGIN_MESSAGE_MAP(CMy2020041302View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_CALCULATE, &CMy2020041302View::OnCalculate)
END_MESSAGE_MAP()

// CMy2020041302View 构造/析构

CMy2020041302View::CMy2020041302View()
{
	// TODO: 在此处添加构造代码

}

CMy2020041302View::~CMy2020041302View()
{
}

BOOL CMy2020041302View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy2020041302View 绘制

void CMy2020041302View::OnDraw(CDC* /*pDC*/)
{
	CMy2020041302Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy2020041302View 打印

BOOL CMy2020041302View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2020041302View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2020041302View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy2020041302View 诊断

#ifdef _DEBUG
void CMy2020041302View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020041302View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020041302Doc* CMy2020041302View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020041302Doc)));
	return (CMy2020041302Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020041302View 消息处理程序


void CMy2020041302View::OnCalculate()
{
	Calculate cal;
	int r = cal.DoModal();
	if (r == IDOK) {

	}
	// TODO: 在此添加命令处理程序代码
}
