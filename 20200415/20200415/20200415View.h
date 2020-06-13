
// 20200415View.h : CMy20200415View 类的接口
//

#pragma once
#include "20200415Doc.h"

class CMy20200415View : public CView
{
protected: // 仅从序列化创建
	CMy20200415View();
	DECLARE_DYNCREATE(CMy20200415View)

// 特性
public:
	CMy20200415Doc* GetDocument() const;

// 操作
public:
	CString strFile = _T("");
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
	virtual ~CMy20200415View();
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
	afx_msg void OnDialog();
};

#ifndef _DEBUG  // 20200415View.cpp 中的调试版本
inline CMy20200415Doc* CMy20200415View::GetDocument() const
   { return reinterpret_cast<CMy20200415Doc*>(m_pDocument); }
#endif

