
// 20200421View.h : CMy20200421View ��Ľӿ�
//

#pragma once
#include "20200421Doc.h"

class CMy20200421View : public CView
{
protected: // �������л�����
	CMy20200421View();
	DECLARE_DYNCREATE(CMy20200421View)

// ����
public:
	CMy20200421Doc* GetDocument() const;

// ����
public:
	CString path;
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
	virtual ~CMy20200421View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSave();
	afx_msg void OnShow();
};

#ifndef _DEBUG  // 20200421View.cpp �еĵ��԰汾
inline CMy20200421Doc* CMy20200421View::GetDocument() const
   { return reinterpret_cast<CMy20200421Doc*>(m_pDocument); }
#endif

