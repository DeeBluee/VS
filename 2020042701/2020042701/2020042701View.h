
// 2020042701View.h : CMy2020042701View ��Ľӿ�
//

#pragma once


class CMy2020042701View : public CView
{
protected: // �������л�����
	CMy2020042701View();
	DECLARE_DYNCREATE(CMy2020042701View)

// ����
public:
	CMy2020042701Doc* GetDocument() const;

// ����
public:
	CRect rect;
	CPoint start, end;
	int state = 0;
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
	virtual ~CMy2020042701View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 2020042701View.cpp �еĵ��԰汾
inline CMy2020042701Doc* CMy2020042701View::GetDocument() const
   { return reinterpret_cast<CMy2020042701Doc*>(m_pDocument); }
#endif

