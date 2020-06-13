
// Text1View.cpp : CText1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Text1.h"
#endif

#include "Text1Doc.h"
#include "Text1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CText1View

IMPLEMENT_DYNCREATE(CText1View, CView)

BEGIN_MESSAGE_MAP(CText1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CText1View 构造/析构

CText1View::CText1View()
{
	// TODO: 在此处添加构造代码

}

CText1View::~CText1View()
{
}

BOOL CText1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CText1View 绘制

void CText1View::OnDraw(CDC* pDC)
{
	CText1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	//CString s = _T("我是***");
	//int a = 1;
	//CString A;
	//A.Format(_T("%d"), a);
	//pDC->TextOutW(200, 200, s);  //调用pDC类即设备环境类的成员函数
	//pDC->TextOutW(300, 300, A);

	pDC->TextOutW(200, 200, pDoc->s);
	pDC->TextOutW(300, 300, pDoc->A);


}


// CText1View 诊断

#ifdef _DEBUG
void CText1View::AssertValid() const
{
	CView::AssertValid();
}

void CText1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CText1Doc* CText1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CText1Doc)));
	return (CText1Doc*)m_pDocument;
}
#endif //_DEBUG


// CText1View 消息处理程序


void CText1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CText1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	pDoc->count += 1;
}


void CText1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	CText1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	
	CClientDC dc(this); 
	CString ss;
	ss.Format(_T("%d"), pDoc->count);
	dc.TextOutW(500, 500, ss);
	CView::OnRButtonDown(nFlags, point);

}
