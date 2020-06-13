
// 2020041301View.h : CMy2020041301View 类的接口
//

#pragma once


class CMy2020041301View : public CView
{
protected: // 仅从序列化创建
	CMy2020041301View();
	DECLARE_DYNCREATE(CMy2020041301View)

// 特性
public:
	CMy2020041301Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	CPoint p;
	int flag = 1;  //1表示还未画矩形，2表示移动过程，3表示放下
	int h_height;
	int h_width;
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
	virtual ~CMy2020041301View();
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
};

#ifndef _DEBUG  // 2020041301View.cpp 中的调试版本
inline CMy2020041301Doc* CMy2020041301View::GetDocument() const
   { return reinterpret_cast<CMy2020041301Doc*>(m_pDocument); }
#endif

