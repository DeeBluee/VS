
// Text1View.h : CText1View ��Ľӿ�
//

#pragma once


class CText1View : public CView
{
protected: // �������л�����
	CText1View();
	DECLARE_DYNCREATE(CText1View)

// ����
public:
	CText1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CText1View();
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

#ifndef _DEBUG  // Text1View.cpp �еĵ��԰汾
inline CText1Doc* CText1View::GetDocument() const
   { return reinterpret_cast<CText1Doc*>(m_pDocument); }
#endif
