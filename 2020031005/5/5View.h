
// 5View.h : CMy5View 类的接口
//

#pragma once


class CMy5View : public CView
{
protected: // 仅从序列化创建
	CMy5View();
	DECLARE_DYNCREATE(CMy5View)

// 特性
public:
	CMy5Doc* GetDocument() const;

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
	virtual ~CMy5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 5View.cpp 中的调试版本
inline CMy5Doc* CMy5View::GetDocument() const
   { return reinterpret_cast<CMy5Doc*>(m_pDocument); }
#endif

