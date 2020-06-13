
// 20200421View.cpp : CMy20200421View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "20200421.h"
#endif

#include "20200421Doc.h"
#include "20200421View.h"
#include "fstream"
#include "string"
#include "iostream"
#include "dialog.h"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20200421View

IMPLEMENT_DYNCREATE(CMy20200421View, CView)

BEGIN_MESSAGE_MAP(CMy20200421View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SAVE, &CMy20200421View::OnSave)
	ON_COMMAND(ID_SHOW, &CMy20200421View::OnShow)
END_MESSAGE_MAP()

// CMy20200421View 构造/析构

CMy20200421View::CMy20200421View()
{
	// TODO: 在此处添加构造代码

}

CMy20200421View::~CMy20200421View()
{
}

BOOL CMy20200421View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy20200421View 绘制

void CMy20200421View::OnDraw(CDC* /*pDC*/)
{
	CMy20200421Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy20200421View 打印

BOOL CMy20200421View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy20200421View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy20200421View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy20200421View 诊断

#ifdef _DEBUG
void CMy20200421View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20200421View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20200421Doc* CMy20200421View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20200421Doc)));
	return (CMy20200421Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20200421View 消息处理程序


void CMy20200421View::OnSave()
{
	// TODO: 在此添加命令处理程序代码
	CString filename;
	CFileDialog cfd(true);
	if (cfd.DoModal() == IDOK) {
		filename = cfd.GetPathName();
		ofstream ofs(_T("C:\\Users\\12850\\Desktop\\abc.txt"));
		ofs << CT2A(filename.GetString());
		
	}
}


void CMy20200421View::OnShow()
{
	ifstream ifs(_T("C:\\Users\\12850\\Desktop\\abc.txt"));
	string pathname;
	ifs >> pathname;
	path = CString(pathname.c_str());
	path.Replace(_T("\\"), _T("\\\\"));
	dialog dlg;
	dlg.DoModal();
	
	
	



	// TODO: 在此添加命令处理程序代码
}
