
// 2020032403View.h : CMy2020032403View 类的接口
//

#pragma once


class CMy2020032403View : public CView
{
protected: // 仅从序列化创建
	CMy2020032403View();
	DECLARE_DYNCREATE(CMy2020032403View)

// 特性
public:
	CMy2020032403Doc* GetDocument() const;

// 操作
public:
	int flag, set;
	CPoint start, mid, end;
	CRect cr;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy2020032403View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaintline();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaintrectangle();
	afx_msg void OnPaintoval();
};

#ifndef _DEBUG  // 2020032403View.cpp 中的调试版本
inline CMy2020032403Doc* CMy2020032403View::GetDocument() const
   { return reinterpret_cast<CMy2020032403Doc*>(m_pDocument); }
#endif

