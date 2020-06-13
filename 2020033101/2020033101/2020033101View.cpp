
// 2020033101View.cpp : CMy2020033101View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2020033101.h"
#endif

#include "2020033101Doc.h"
#include "2020033101View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2020033101View

IMPLEMENT_DYNCREATE(CMy2020033101View, CView)

BEGIN_MESSAGE_MAP(CMy2020033101View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
//	ON_WM_PAINT()
//ON_WM_MBUTTONDBLCLK()
ON_WM_LBUTTONDBLCLK()
ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMy2020033101View 构造/析构

CMy2020033101View::CMy2020033101View()
{
	// TODO: 在此处添加构造代码
	defp.SetPoint(-1, -1);
}

CMy2020033101View::~CMy2020033101View()
{
}

BOOL CMy2020033101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy2020033101View 绘制

void CMy2020033101View::OnDraw(CDC* pDC)
{

	CMy2020033101Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	CSize size = dc.GetTextExtent(s);
	cs_width = size.cx;
	cs_height = size.cy;
	CString ss = _T("注意：测试是尽量只使用数字，其他字符会由于大小变化而导致不可预料的错误，鼠标左键单击后输入字符，鼠标双击表示在点击位置插入字符，鼠标右键表示在末尾添加字符");
	pDC->TextOutW(0, 0, ss);
	if (!s.IsEmpty()) {
		line = cs_width / 200; //表示一共需要输出多少行
		min = cs_width / s.GetLength();//平均每个字符所占的像素宽度
		left = cs_width % 200;//最后一行剩余的像素
		left_num = left / min; //最后一行剩余的字符数
		num = 200 / min;//每一行输出的字符个数
		if (left != 0) line++;
		if (cs_width < 200) {
			dc.TextOutW(defp.x, defp.y, s);
		}
		else {
			
			for (int i = 1; i <= line; i++) {
				if (i == 1) {
					CString ss = s.Left(num);
					dc.TextOutW(defp.x, defp.y + (i - 1)*cs_height, ss);
				}
				else if (i<line) {//当还未输出最后一行时
					CString ss = s.Mid(num*(i - 1), num);
					dc.TextOutW(defp.x, defp.y + (i - 1)*cs_height, ss);
				}
				else {

					CString ss;
					if (left_num == 0)
						ss = s.Right(num);
					else
						ss = s.Right(left_num);
					dc.TextOutW(defp.x, defp.y + (i - 1)*cs_height, ss);
				}
			}
		}
		cr.SetRect(defp.x, defp.y, defp.x + 200, defp.y + cs_height*(line));
		CBrush *OldBrush;
		OldBrush = (CBrush*)dc.SelectStockObject(NULL_BRUSH);//创建一个不填充的画刷
		dc.Rectangle(cr);
		dc.SelectObject(OldBrush);
	}

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy2020033101View 打印

BOOL CMy2020033101View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2020033101View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2020033101View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy2020033101View 诊断

#ifdef _DEBUG
void CMy2020033101View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020033101View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020033101Doc* CMy2020033101View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020033101Doc)));
	return (CMy2020033101Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020033101View 消息处理程序


void CMy2020033101View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CClientDC dc(this);
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	char ch = (char)nChar;
	if (flag == 0)
		s.AppendChar(ch);
	else {
		s.Insert(h*num + l, ch);
	}
	Invalidate();

	
}


void CMy2020033101View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(defp.x==-1&&defp.y==-1)
		defp = point;
	CView::OnLButtonDown(nFlags, point);
}


//void CMy2020033101View::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//					   // TODO: 在此处添加消息处理程序代码
//					   // 不为绘图消息调用 CView::OnPaint()
//
//}


//void CMy2020033101View::OnMButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	
//	CView::OnMButtonDblClk(nFlags, point);
//}


void CMy2020033101View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 1;
	CPoint insert = point;
	int len = s.GetLength();
	h=(insert.y - defp.y) / cs_height;//插入行的位置
	l = (insert.x - defp.x) / (cs_width / len); //计算列的的位置
	CClientDC dc(this);
	
	CView::OnLButtonDblClk(nFlags, point);
}


void CMy2020033101View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 0;
	CView::OnRButtonDown(nFlags, point);
}
