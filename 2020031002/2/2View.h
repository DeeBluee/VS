
// 2View.h : CMy2View ��Ľӿ�
//

#pragma once


class CMy2View : public CView
{
protected: // �������л�����
	CMy2View();
	DECLARE_DYNCREATE(CMy2View)

// ����
public:
	CMy2Doc* GetDocument() const;

// ����
public:
	CArray<CRect, CRect&> ca;
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
	virtual ~CMy2View();
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
};

#ifndef _DEBUG  // 2View.cpp �еĵ��԰汾
inline CMy2Doc* CMy2View::GetDocument() const
   { return reinterpret_cast<CMy2Doc*>(m_pDocument); }
#endif

