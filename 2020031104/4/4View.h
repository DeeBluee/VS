
// 4View.h : CMy4View ��Ľӿ�
//

#pragma once


class CMy4View : public CView
{
protected: // �������л�����
	CMy4View();
	DECLARE_DYNCREATE(CMy4View)

// ����
public:
	CMy4Doc* GetDocument() const;

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
	virtual ~CMy4View();
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

#ifndef _DEBUG  // 4View.cpp �еĵ��԰汾
inline CMy4Doc* CMy4View::GetDocument() const
   { return reinterpret_cast<CMy4Doc*>(m_pDocument); }
#endif

