
// 4View.h : CMy4View 类的接口
//

#pragma once


class CMy4View : public CView
{
protected: // 仅从序列化创建
	CMy4View();
	DECLARE_DYNCREATE(CMy4View)

// 特性
public:
	CMy4Doc* GetDocument() const;

// 操作
public:

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
	virtual ~CMy4View();
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
};

#ifndef _DEBUG  // 4View.cpp 中的调试版本
inline CMy4Doc* CMy4View::GetDocument() const
   { return reinterpret_cast<CMy4Doc*>(m_pDocument); }
#endif

