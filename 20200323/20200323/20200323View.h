
// 20200323View.h : CMy20200323View 类的接口
//

#pragma once


class CMy20200323View : public CView
{
protected: // 仅从序列化创建
	CMy20200323View();
	DECLARE_DYNCREATE(CMy20200323View)

// 特性
public:
	CMy20200323Doc* GetDocument() const;

// 操作
	int i, flag;
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
	virtual ~CMy20200323View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSizechange();
	afx_msg void OnColorchange();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 20200323View.cpp 中的调试版本
inline CMy20200323Doc* CMy20200323View::GetDocument() const
   { return reinterpret_cast<CMy20200323Doc*>(m_pDocument); }
#endif

