
// 2020041304View.cpp : CMy2020041304View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2020041304.h"
#endif

#include "2020041304Doc.h"
#include "2020041304View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "Combine.h"

// CMy2020041304View

IMPLEMENT_DYNCREATE(CMy2020041304View, CView)

BEGIN_MESSAGE_MAP(CMy2020041304View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy2020041304View 构造/析构

CMy2020041304View::CMy2020041304View()
{
	// TODO: 在此处添加构造代码

}

CMy2020041304View::~CMy2020041304View()
{
}

BOOL CMy2020041304View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy2020041304View 绘制

void CMy2020041304View::OnDraw(CDC* /*pDC*/)
{
	CMy2020041304Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	Combine c;
	int r = c.DoModal();
	if (r == IDOK) {

	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy2020041304View 打印

BOOL CMy2020041304View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2020041304View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2020041304View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy2020041304View 诊断

#ifdef _DEBUG
void CMy2020041304View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020041304View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020041304Doc* CMy2020041304View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020041304Doc)));
	return (CMy2020041304Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020041304View 消息处理程序
