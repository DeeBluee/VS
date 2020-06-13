
// 20200330View.cpp : CMy20200330View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "20200330.h"
#endif

#include "20200330Doc.h"
#include "20200330View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20200330View

IMPLEMENT_DYNCREATE(CMy20200330View, CView)

BEGIN_MESSAGE_MAP(CMy20200330View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CMy20200330View::OnFileOpen)
END_MESSAGE_MAP()

// CMy20200330View 构造/析构

CMy20200330View::CMy20200330View()
{
	// TODO: 在此处添加构造代码

}

CMy20200330View::~CMy20200330View()
{
}

BOOL CMy20200330View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy20200330View 绘制

void CMy20200330View::OnDraw(CDC* /*pDC*/)
{
	CMy20200330Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy20200330View 打印

BOOL CMy20200330View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy20200330View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy20200330View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy20200330View 诊断

#ifdef _DEBUG
void CMy20200330View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20200330View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20200330Doc* CMy20200330View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20200330Doc)));
	return (CMy20200330Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20200330View 消息处理程序


void CMy20200330View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		CImage image;
		image.Load(filename);
		image.Draw(dc.m_hDC, 0, 0, image.GetWidth(), image.GetHeight());
	}

}
