
// 2020041303View.h : CMy2020041303View 类的接口
//

#pragma once


class CMy2020041303View : public CView
{
protected: // 仅从序列化创建
	CMy2020041303View();
	DECLARE_DYNCREATE(CMy2020041303View)

// 特性
public:
	CMy2020041303Doc* GetDocument() const;

// 操作
public:
	int f = -1; //记录圆上一次的状态，用于暂停
	int flag = -1; // 圆的状态，-1表示停止，1表示左，2表示右，0表示暂停
	CRect cr;
	CPoint p;
	int x = 50;
	CRect CR;
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
	virtual ~CMy2020041303View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 2020041303View.cpp 中的调试版本
inline CMy2020041303Doc* CMy2020041303View::GetDocument() const
   { return reinterpret_cast<CMy2020041303Doc*>(m_pDocument); }
#endif

