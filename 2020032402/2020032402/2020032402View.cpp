
// 2020032402View.cpp : CMy2020032402View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2020032402.h"
#endif

#include "2020032402Doc.h"
#include "2020032402View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020032402View

IMPLEMENT_DYNCREATE(CMy2020032402View, CView)

BEGIN_MESSAGE_MAP(CMy2020032402View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy2020032402View 构造/析构

CMy2020032402View::CMy2020032402View()
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	bm.LoadBitmap(IDB_BITMAP1);
	bm.GetBitmap(&BM);
	bm_width = BM.bmWidth;
	bm_height = BM.bmHeight;
}

CMy2020032402View::~CMy2020032402View()
{
}

BOOL CMy2020032402View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy2020032402View 绘制

void CMy2020032402View::OnDraw(CDC* pDC)
{
	CMy2020032402Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CDC bmCDC;
	bmCDC.CreateCompatibleDC(NULL);
	bmCDC.SelectObject(bm);
	pDC->BitBlt(0, 0, bm_width, bm_height, &bmCDC, 0, 0, SRCCOPY);

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy2020032402View 打印

BOOL CMy2020032402View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2020032402View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2020032402View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy2020032402View 诊断

#ifdef _DEBUG
void CMy2020032402View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020032402View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020032402Doc* CMy2020032402View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020032402Doc)));
	return (CMy2020032402Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020032402View 消息处理程序
