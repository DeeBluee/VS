
// 2020032403View.h : CMy2020032403View ��Ľӿ�
//

#pragma once


class CMy2020032403View : public CView
{
protected: // �������л�����
	CMy2020032403View();
	DECLARE_DYNCREATE(CMy2020032403View)

// ����
public:
	CMy2020032403Doc* GetDocument() const;

// ����
public:
	int flag, set;
	CPoint start, mid, end;
	CRect cr;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy2020032403View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaintline();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaintrectangle();
	afx_msg void OnPaintoval();
};

#ifndef _DEBUG  // 2020032403View.cpp �еĵ��԰汾
inline CMy2020032403Doc* CMy2020032403View::GetDocument() const
   { return reinterpret_cast<CMy2020032403Doc*>(m_pDocument); }
#endif

