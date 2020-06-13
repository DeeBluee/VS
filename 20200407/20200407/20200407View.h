
// 20200407View.h : CMy20200407View 类的接口
//

#pragma once


class CMy20200407View : public CView
{
protected: // 仅从序列化创建
	CMy20200407View();
	DECLARE_DYNCREATE(CMy20200407View)

// 特性
public:
	CMy20200407Doc* GetDocument() const;

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
	virtual ~CMy20200407View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopdialog();
};

#ifndef _DEBUG  // 20200407View.cpp 中的调试版本
inline CMy20200407Doc* CMy20200407View::GetDocument() const
   { return reinterpret_cast<CMy20200407Doc*>(m_pDocument); }
#endif

