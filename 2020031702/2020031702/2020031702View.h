
// 2020031702View.h : CMy2020031702View 类的接口
//

#pragma once


class CMy2020031702View : public CView
{
protected: // 仅从序列化创建
	CMy2020031702View();
	DECLARE_DYNCREATE(CMy2020031702View)

// 特性
public:
	CMy2020031702Doc* GetDocument() const;

// 操作
public:
	int mx, my, x, y;
	int height, width;
	int flag ;
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
	virtual ~CMy2020031702View();
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
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // 2020031702View.cpp 中的调试版本
inline CMy2020031702Doc* CMy2020031702View::GetDocument() const
   { return reinterpret_cast<CMy2020031702Doc*>(m_pDocument); }
#endif

