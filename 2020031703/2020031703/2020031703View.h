
// 2020031703View.h : CMy2020031703View ��Ľӿ�
//

#pragma once


class CMy2020031703View : public CView
{
protected: // �������л�����
	CMy2020031703View();
	DECLARE_DYNCREATE(CMy2020031703View)

// ����
public:
	CMy2020031703Doc* GetDocument() const;

// ����
public:
	CRect cr;
	int set = 1;
	int f = 1;
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
	virtual ~CMy2020031703View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 2020031703View.cpp �еĵ��԰汾
inline CMy2020031703Doc* CMy2020031703View::GetDocument() const
   { return reinterpret_cast<CMy2020031703Doc*>(m_pDocument); }
#endif

