
// 2020041301View.h : CMy2020041301View ��Ľӿ�
//

#pragma once


class CMy2020041301View : public CView
{
protected: // �������л�����
	CMy2020041301View();
	DECLARE_DYNCREATE(CMy2020041301View)

// ����
public:
	CMy2020041301Doc* GetDocument() const;

// ����
public:
	CRect cr;
	CPoint p;
	int flag = 1;  //1��ʾ��δ�����Σ�2��ʾ�ƶ����̣�3��ʾ����
	int h_height;
	int h_width;
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
	virtual ~CMy2020041301View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 2020041301View.cpp �еĵ��԰汾
inline CMy2020041301Doc* CMy2020041301View::GetDocument() const
   { return reinterpret_cast<CMy2020041301Doc*>(m_pDocument); }
#endif

