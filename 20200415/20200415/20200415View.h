
// 20200415View.h : CMy20200415View ��Ľӿ�
//

#pragma once
#include "20200415Doc.h"

class CMy20200415View : public CView
{
protected: // �������л�����
	CMy20200415View();
	DECLARE_DYNCREATE(CMy20200415View)

// ����
public:
	CMy20200415Doc* GetDocument() const;

// ����
public:
	CString strFile = _T("");
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
	virtual ~CMy20200415View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnDialog();
};

#ifndef _DEBUG  // 20200415View.cpp �еĵ��԰汾
inline CMy20200415Doc* CMy20200415View::GetDocument() const
   { return reinterpret_cast<CMy20200415Doc*>(m_pDocument); }
#endif

