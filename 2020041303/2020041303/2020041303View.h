
// 2020041303View.h : CMy2020041303View ��Ľӿ�
//

#pragma once


class CMy2020041303View : public CView
{
protected: // �������л�����
	CMy2020041303View();
	DECLARE_DYNCREATE(CMy2020041303View)

// ����
public:
	CMy2020041303Doc* GetDocument() const;

// ����
public:
	int f = -1; //��¼Բ��һ�ε�״̬��������ͣ
	int flag = -1; // Բ��״̬��-1��ʾֹͣ��1��ʾ��2��ʾ�ң�0��ʾ��ͣ
	CRect cr;
	CPoint p;
	int x = 50;
	CRect CR;
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
	virtual ~CMy2020041303View();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 2020041303View.cpp �еĵ��԰汾
inline CMy2020041303Doc* CMy2020041303View::GetDocument() const
   { return reinterpret_cast<CMy2020041303Doc*>(m_pDocument); }
#endif

