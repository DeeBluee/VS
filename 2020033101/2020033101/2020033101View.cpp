
// 2020033101View.cpp : CMy2020033101View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CMy2020033101View ����/����

CMy2020033101View::CMy2020033101View()
{
	// TODO: �ڴ˴���ӹ������
	defp.SetPoint(-1, -1);
}

CMy2020033101View::~CMy2020033101View()
{
}

BOOL CMy2020033101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2020033101View ����

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
	CString ss = _T("ע�⣺�����Ǿ���ֻʹ�����֣������ַ������ڴ�С�仯�����²���Ԥ�ϵĴ��������������������ַ������˫����ʾ�ڵ��λ�ò����ַ�������Ҽ���ʾ��ĩβ����ַ�");
	pDC->TextOutW(0, 0, ss);
	if (!s.IsEmpty()) {
		line = cs_width / 200; //��ʾһ����Ҫ���������
		min = cs_width / s.GetLength();//ƽ��ÿ���ַ���ռ�����ؿ��
		left = cs_width % 200;//���һ��ʣ�������
		left_num = left / min; //���һ��ʣ����ַ���
		num = 200 / min;//ÿһ��������ַ�����
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
				else if (i<line) {//����δ������һ��ʱ
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
		OldBrush = (CBrush*)dc.SelectStockObject(NULL_BRUSH);//����һ�������Ļ�ˢ
		dc.Rectangle(cr);
		dc.SelectObject(OldBrush);
	}

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2020033101View ��ӡ

BOOL CMy2020033101View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2020033101View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2020033101View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy2020033101View ���

#ifdef _DEBUG
void CMy2020033101View::AssertValid() const
{
	CView::AssertValid();
}

void CMy2020033101View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2020033101Doc* CMy2020033101View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2020033101Doc)));
	return (CMy2020033101Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy2020033101View ��Ϣ�������


void CMy2020033101View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CClientDC dc(this);
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(defp.x==-1&&defp.y==-1)
		defp = point;
	CView::OnLButtonDown(nFlags, point);
}


//void CMy2020033101View::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//					   // TODO: �ڴ˴������Ϣ����������
//					   // ��Ϊ��ͼ��Ϣ���� CView::OnPaint()
//
//}


//void CMy2020033101View::OnMButtonDblClk(UINT nFlags, CPoint point)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	
//	CView::OnMButtonDblClk(nFlags, point);
//}


void CMy2020033101View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 1;
	CPoint insert = point;
	int len = s.GetLength();
	h=(insert.y - defp.y) / cs_height;//�����е�λ��
	l = (insert.x - defp.x) / (cs_width / len); //�����еĵ�λ��
	CClientDC dc(this);
	
	CView::OnLButtonDblClk(nFlags, point);
}


void CMy2020033101View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 0;
	CView::OnRButtonDown(nFlags, point);
}
