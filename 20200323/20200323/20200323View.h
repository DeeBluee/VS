
// 20200323View.h : CMy20200323View ��Ľӿ�
//

#pragma once


class CMy20200323View : public CView
{
protected: // �������л�����
	CMy20200323View();
	DECLARE_DYNCREATE(CMy20200323View)

// ����
public:
	CMy20200323Doc* GetDocument() const;

// ����
	int i, flag;
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
	virtual ~CMy20200323View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSizechange();
	afx_msg void OnColorchange();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 20200323View.cpp �еĵ��԰汾
inline CMy20200323Doc* CMy20200323View::GetDocument() const
   { return reinterpret_cast<CMy20200323Doc*>(m_pDocument); }
#endif

