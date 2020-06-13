
// Text1View.h : CText1View 类的接口
//

#pragma once


class CText1View : public CView
{
protected: // 仅从序列化创建
	CText1View();
	DECLARE_DYNCREATE(CText1View)

// 特性
public:
	CText1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CText1View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Text1View.cpp 中的调试版本
inline CText1Doc* CText1View::GetDocument() const
   { return reinterpret_cast<CText1Doc*>(m_pDocument); }
#endif

