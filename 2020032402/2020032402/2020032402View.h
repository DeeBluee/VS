
// 2020032402View.h : CMy2020032402View 类的接口
//

#pragma once


class CMy2020032402View : public CView
{
protected: // 仅从序列化创建
	CMy2020032402View();
	DECLARE_DYNCREATE(CMy2020032402View)

// 特性
public:
	CMy2020032402Doc* GetDocument() const;

// 操作
public:
	CBitmap bm;
	int bm_width, bm_height;
	
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
	virtual ~CMy2020032402View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 2020032402View.cpp 中的调试版本
inline CMy2020032402Doc* CMy2020032402View::GetDocument() const
   { return reinterpret_cast<CMy2020032402Doc*>(m_pDocument); }
#endif

