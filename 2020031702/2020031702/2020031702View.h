
// 2020031702View.h : CMy2020031702View ��Ľӿ�
//

#pragma once


class CMy2020031702View : public CView
{
protected: // �������л�����
	CMy2020031702View();
	DECLARE_DYNCREATE(CMy2020031702View)

// ����
public:
	CMy2020031702Doc* GetDocument() const;

// ����
public:
	int mx, my, x, y;
	int height, width;
	int flag ;
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
	virtual ~CMy2020031702View();
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
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // 2020031702View.cpp �еĵ��԰汾
inline CMy2020031702Doc* CMy2020031702View::GetDocument() const
   { return reinterpret_cast<CMy2020031702Doc*>(m_pDocument); }
#endif

