
// 2020042002View.h : CMy2020042002View 类的接口
//

#pragma once


class CMy2020042002View : public CView
{
protected: // 仅从序列化创建
	CMy2020042002View();
	DECLARE_DYNCREATE(CMy2020042002View)

// 特性
public:
	CMy2020042002Doc* GetDocument() const;

// 操作
public:
	CRect rect;
	CPoint startpoint;
	CPoint endpoint;
	int flag = 0;
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
	virtual ~CMy2020042002View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMenu();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnColor();
};

#ifndef _DEBUG  // 2020042002View.cpp 中的调试版本
inline CMy2020042002Doc* CMy2020042002View::GetDocument() const
   { return reinterpret_cast<CMy2020042002Doc*>(m_pDocument); }
#endif

