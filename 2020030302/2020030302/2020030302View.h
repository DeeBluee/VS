
// 2020030302View.h : CMy2020030302View ��Ľӿ�
//

#pragma once


class CMy2020030302View : public CView
{
protected: // �������л�����
	CMy2020030302View();
	DECLARE_DYNCREATE(CMy2020030302View)

// ����
public:
	CMy2020030302Doc* GetDocument() const;

// ����
public:

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
	virtual ~CMy2020030302View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 2020030302View.cpp �еĵ��԰汾
inline CMy2020030302Doc* CMy2020030302View::GetDocument() const
   { return reinterpret_cast<CMy2020030302Doc*>(m_pDocument); }
#endif

