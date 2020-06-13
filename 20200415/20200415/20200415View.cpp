
// 20200415View.cpp : CMy20200415View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "20200415.h"
#endif

#include "20200415Doc.h"
#include "20200415View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MyDialog.h"

// CMy20200415View

IMPLEMENT_DYNCREATE(CMy20200415View, CView)

BEGIN_MESSAGE_MAP(CMy20200415View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_DIALOG, &CMy20200415View::OnDialog)
END_MESSAGE_MAP()

// CMy20200415View 构造/析构

CMy20200415View::CMy20200415View()
{
	// TODO: 在此处添加构造代码

}

CMy20200415View::~CMy20200415View()
{
}

BOOL CMy20200415View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy20200415View 绘制

void CMy20200415View::OnDraw(CDC* /*pDC*/)
{
	CMy20200415Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy20200415View 打印

BOOL CMy20200415View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy20200415View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy20200415View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy20200415View 诊断

#ifdef _DEBUG
void CMy20200415View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20200415View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20200415Doc* CMy20200415View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20200415Doc)));
	return (CMy20200415Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20200415View 消息处理程序


void CMy20200415View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	

	CFileDialog    dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Describe Files (*.jpg)|*.jpg|All Files (*.*)|*.*||"), NULL);

	if (dlgFile.DoModal())
	{
		strFile = dlgFile.GetFileName();
	}
	GetDC()->TextOutW(500, 500, strFile);
	CView::OnLButtonDblClk(nFlags, point);
}


void CMy20200415View::OnDialog()
{
	MyDialog dlg;
	int r = dlg.DoModal();
	if (r == IDOK) {

	}
	// TODO: 在此添加命令处理程序代码
}
