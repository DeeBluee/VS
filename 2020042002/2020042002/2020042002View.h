
// 2020042002View.h : CMy2020042002View ��Ľӿ�
//

#pragma once


class CMy2020042002View : public CView
{
protected: // �������л�����
	CMy2020042002View();
	DECLARE_DYNCREATE(CMy2020042002View)

// ����
public:
	CMy2020042002Doc* GetDocument() const;

// ����
public:
	CRect rect;
	CPoint startpoint;
	CPoint endpoint;
	int flag = 0;
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
	virtual ~CMy2020042002View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMenu();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnColor();
};

#ifndef _DEBUG  // 2020042002View.cpp �еĵ��԰汾
inline CMy2020042002Doc* CMy2020042002View::GetDocument() const
   { return reinterpret_cast<CMy2020042002Doc*>(m_pDocument); }
#endif

