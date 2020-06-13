
// 2020031701View.h : CMy2020031701View 类的接口
//

#pragma once


class CMy2020031701View : public CView
{
protected: // 仅从序列化创建
	CMy2020031701View();
	DECLARE_DYNCREATE(CMy2020031701View)

// 特性
public:
	CMy2020031701Doc* GetDocument() const;

// 操作
public:
	int num;
	CPoint start;
	CPoint end;
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
	virtual ~CMy2020031701View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 2020031701View.cpp 中的调试版本
inline CMy2020031701Doc* CMy2020031701View::GetDocument() const
   { return reinterpret_cast<CMy2020031701Doc*>(m_pDocument); }
#endif

