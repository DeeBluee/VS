
// 2020050401View.cpp : CMy2020050401View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2020050401.h"
#include "20200504lib.h"
#include "20200504DLL.h"
#endif

#include "2020050401Doc.h"
#include "2020050401View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020050401View

IMPLEMENT_DYNCREATE(CMy2020050401View, CView)

BEGIN_MESSAGE_MAP(CMy2020050401View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy2020050401View 构造/析构

CMy2020050401View::CMy2020050401View()
{
	// TODO: 在此处添加构造代码

}

CMy2020050401View::~CMy2020050401View()
{
}

BOOL CMy2020050401View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy2020050401View 绘制

void CMy2020050401View::OnDraw(CDC* pDC)
{
	CMy2020050401Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CString ss;
	ss.Format(_T("这是静态链接库的计算阶乘函数%d"), factorial(5));
	pDC->TextOutW(600, 300, ss);
	FAC fac;
	ss.Format(_T("这是静态链接库的角度转换函数%f"), fac.convert(30.0));
	pDC->TextOutW(600, 400, ss);

	ss.Format(_T("这是动态链接库的计算阶乘函数%d"), factorial_dll(5));
	pDC->TextOutW(600, 500, ss);
	FAC_dll fac_dll;
	ss.Format(_T("这是动态链接库的角度转换函数%f"), fac_dll.convert_dll(30.0));
	pDC->TextOutW(600, 600, ss);


	// TODO: 在此处为本机数据添加绘制代码
}


// CMy2020050401View 打印

BOOL CMy2020050401View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2020050401View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2020050401View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy2020050401View 诊断

#ifdef _DEBUG
void CMy2020050401View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020050401View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020050401Doc* CMy2020050401View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020050401Doc)));
	return (CMy2020050401Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020050401View 消息处理程序
