
// 20200421View.cpp : CMy20200421View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SAVE, &CMy20200421View::OnSave)
	ON_COMMAND(ID_SHOW, &CMy20200421View::OnShow)
END_MESSAGE_MAP()

// CMy20200421View ����/����

CMy20200421View::CMy20200421View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy20200421View::~CMy20200421View()
{
}

BOOL CMy20200421View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy20200421View ����

void CMy20200421View::OnDraw(CDC* /*pDC*/)
{
	CMy20200421Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy20200421View ��ӡ

BOOL CMy20200421View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy20200421View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy20200421View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy20200421View ���

#ifdef _DEBUG
void CMy20200421View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20200421View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20200421Doc* CMy20200421View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20200421Doc)));
	return (CMy20200421Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20200421View ��Ϣ�������


void CMy20200421View::OnSave()
{
	// TODO: �ڴ���������������
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
	
	
	



	// TODO: �ڴ���������������
}
