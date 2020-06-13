
// MFCApplication7View.cpp : CMFCApplication7View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication7.h"
#endif

#include "MFCApplication7Set.h"
#include "MFCApplication7Doc.h"
#include "MFCApplication7View.h"
#include "SDialog.h"
#include "GDialog.h"
#include "ADialog.h"
#include "Order_Dialog.h"
#include "Search_Dialog.h"
#include "SetDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication7View

IMPLEMENT_DYNCREATE(CMFCApplication7View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication7View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_RECORD_FIRST, &CMFCApplication7View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCApplication7View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCApplication7View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCApplication7View::OnRecordLast)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication7View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication7View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication7View::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication7View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication7View::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication7View::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication7View::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication7View::OnBnClickedButton8)
END_MESSAGE_MAP()

// CMFCApplication7View 构造/析构

CMFCApplication7View::CMFCApplication7View()
	: CRecordView(IDD_MFCAPPLICATION7_FORM)
	, sname(_T(""))
	, sno(_T(""))
	, sdept(_T(""))
	, ssex(_T(""))
	, sage(_T(""))
	, sphone(_T(""))
	, saddress(_T(""))
	, pic_name(_T(""))
	, pic_path(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFCApplication7View::~CMFCApplication7View()
{
}

void CMFCApplication7View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column7);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column8);
	DDX_Text(pDX, IDC_EDIT9, m_pSet->column9);
}

BOOL CMFCApplication7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication7View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication7Set;
	CRecordView::OnInitialUpdate();
	

}


// CMFCApplication7View 打印

BOOL CMFCApplication7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplication7View 诊断

#ifdef _DEBUG
void CMFCApplication7View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication7View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication7Doc* CMFCApplication7View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication7Doc)));
	return (CMFCApplication7Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication7View 数据库支持
CRecordset* CMFCApplication7View::OnGetRecordset()
{
	return m_pSet;
}




void CMFCApplication7View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFCApplication7View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveNext();
	}
	UpdateData(false);
	Invalidate();
}


void CMFCApplication7View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF()) {
		m_pSet->MovePrev();
	}
	UpdateData(false);
	Invalidate();
}


void CMFCApplication7View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}




void CMFCApplication7View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	GetDlgItemText(IDC_EDIT9, pic_path);
	GetDlgItemText(IDC_EDIT8, pic_name);
	path =  pic_path + "\\" + pic_name;
	path.Replace(_T("\\"), _T("\\\\"));
	CImage img;
	img.Load(path);
	CWnd *pWnd = GetDlgItem(IDC_1);  //获取句柄
	CDC* pDC = pWnd->GetDC();   //获取显示区
	CRect rect;
	pWnd->GetClientRect(&rect);  //获取大小
	SetStretchBltMode(pDC->m_hDC, HALFTONE); //图片不失真
	img.StretchBlt(pDC->m_hDC, rect);

}


void CMFCApplication7View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	SDialog sdlg;
	int r = sdlg.DoModal();
	if (r == IDOK) {

	}
}


void CMFCApplication7View::OnBnClickedButton2()
{
	GDialog gdlg;
	if (gdlg.DoModal() == IDOK) {
		m_pSet->AddNew();
		m_pSet->column1 = gdlg.gname;
		m_pSet->column2 = gdlg.gno;
		m_pSet->column3 = gdlg.gdept;
		m_pSet->column4 = gdlg.gsex;
		m_pSet->column5 = gdlg.gage;
		m_pSet->column6 = gdlg.gphone;
		m_pSet->column7 = gdlg.gaddress;
		m_pSet->column8 = gdlg.gpic_name;
		m_pSet->column9 = gdlg.gpic_path;
		m_pSet->Update();
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication7View::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	UpdateData(false);
	Invalidate();
}


void CMFCApplication7View::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	ADialog adlg;
	adlg.aname = m_pSet->column1;
	adlg.ano = m_pSet->column2;
	adlg.adept = m_pSet->column3;
	adlg.asex = m_pSet->column4;
	adlg.aage = m_pSet->column5;
	adlg.aphone = m_pSet->column6;
	adlg.aaddress = m_pSet->column7;
	adlg.apic_name = m_pSet->column8;
	adlg.apic_path = m_pSet->column9;
	int r = adlg.DoModal();
	if (r == IDOK) {
		m_pSet->Edit();
		m_pSet->column1 = adlg.aname;
		m_pSet->column2 = adlg.ano;
		m_pSet->column3 = adlg.adept;
		m_pSet->column4 = adlg.asex;
		m_pSet->column5 = adlg.aage;
		m_pSet->column6 = adlg.aphone;
		m_pSet->column7 = adlg.aaddress;
		m_pSet->column8 = adlg.apic_name;
		m_pSet->column9 = adlg.apic_path;
		m_pSet->Update();
	}
	UpdateData(false);
}


void CMFCApplication7View::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	Order_Dialog odlg;
	int r = odlg.DoModal();
	if (r == IDOK) {
		m_pSet->m_strSort = odlg.order_by;
		m_pSet->Requery();
	}
}


void CMFCApplication7View::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	Search_Dialog ssdlg;
	int r = ssdlg.DoModal();
	if (r == IDOK) {
		m_pSet->m_strFilter = ssdlg.search;
		m_pSet->Requery();
		UpdateData(false);
		Invalidate();
	}

}


void CMFCApplication7View::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	
	m_pSet->MoveFirst();
	CString str;
	while (!m_pSet->IsEOF()) {
		CString s;
		int n = m_pSet->GetODBCFieldCount();
		for (int i =0; i <n; i++) {
			m_pSet->GetFieldValue((short)i, s);
			str += s + _T("   ");
		}
		str += "\r\n";
		m_pSet->MoveNext();
		
	}
	
	SetDialog sdlg;
	sdlg.set = str;
	int r = sdlg.DoModal();
	if (r == IDOK) {

	}


}


void CMFCApplication7View::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->m_strFilter = _T("");
	m_pSet->Requery();
	UpdateData(false);
	Invalidate();
}
