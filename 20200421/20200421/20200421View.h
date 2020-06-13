
// 20200421View.h : CMy20200421View 类的接口
//

#pragma once
#include "20200421Doc.h"

class CMy20200421View : public CView
{
protected: // 仅从序列化创建
	CMy20200421View();
	DECLARE_DYNCREATE(CMy20200421View)

// 特性
public:
	CMy20200421Doc* GetDocument() const;

// 操作
public:
	CString path;
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
	virtual ~CMy20200421View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSave();
	afx_msg void OnShow();
};

#ifndef _DEBUG  // 20200421View.cpp 中的调试版本
inline CMy20200421Doc* CMy20200421View::GetDocument() const
   { return reinterpret_cast<CMy20200421Doc*>(m_pDocument); }
#endif

