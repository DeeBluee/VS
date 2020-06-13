
// 2020041303View.cpp : CMy2020041303View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2020041303.h"
#endif

#include "2020041303Doc.h"
#include "2020041303View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020041303View

IMPLEMENT_DYNCREATE(CMy2020041303View, CView)

BEGIN_MESSAGE_MAP(CMy2020041303View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy2020041303View 构造/析构

CMy2020041303View::CMy2020041303View()
{
	// TODO: 在此处添加构造代码
	p.SetPoint(150, 150);
	x = 50;
	
}

CMy2020041303View::~CMy2020041303View()
{
}

BOOL CMy2020041303View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy2020041303View 绘制

void CMy2020041303View::OnDraw(CDC* pDC)
{
	CMy2020041303Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (flag == -1) {
		cr.SetRect(p.x - x, p.y - x, p.x + x, p.y + x);
		pDC->Ellipse(cr);
	}
	else {
		cr.SetRect(p.x - x, p.y - x, p.x + x, p.y + x);
		pDC->Ellipse(cr);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy2020041303View 打印

BOOL CMy2020041303View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2020041303View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2020041303View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy2020041303View 诊断

#ifdef _DEBUG
void CMy2020041303View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020041303View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020041303Doc* CMy2020041303View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020041303Doc)));
	return (CMy2020041303Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020041303View 消息处理程序


void CMy2020041303View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	f = flag;
	flag = 0;
	KillTimer(1);
	CView::OnLButtonDblClk(nFlags, point);
}


void CMy2020041303View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	GetClientRect(&CR);
	if (flag == 0) { //表示暂停，恢复到上一次的状态
		flag = f;
	}
	else if(flag==-1){
		f = flag;
		flag = 2;
	}
		

	SetTimer(1, 500, NULL);
	CView::OnLButtonDown(nFlags, point);
}


void CMy2020041303View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 1) {
		
		if (p.x - x <= 0) {
			f = flag;
			flag = 2;
		}
		else
			p.x -= x;
	}
	else  if (flag == 2) {
		if (p.x + x >= CR.Width()) {
			f = flag;
			flag = 1;
		}
		else
			p.x += x;
	}
	Invalidate();
	
	CView::OnTimer(nIDEvent);
}
