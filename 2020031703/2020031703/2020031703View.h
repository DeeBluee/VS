
// 2020031703View.h : CMy2020031703View 类的接口
//

#pragma once


class CMy2020031703View : public CView
{
protected: // 仅从序列化创建
	CMy2020031703View();
	DECLARE_DYNCREATE(CMy2020031703View)

// 特性
public:
	CMy2020031703Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	int set = 1;
	int f = 1;
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
	virtual ~CMy2020031703View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 2020031703View.cpp 中的调试版本
inline CMy2020031703Doc* CMy2020031703View::GetDocument() const
   { return reinterpret_cast<CMy2020031703Doc*>(m_pDocument); }
#endif

