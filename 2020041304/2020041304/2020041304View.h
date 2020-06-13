
// 2020041304View.h : CMy2020041304View 类的接口
//

#pragma once


class CMy2020041304View : public CView
{
protected: // 仅从序列化创建
	CMy2020041304View();
	DECLARE_DYNCREATE(CMy2020041304View)

// 特性
public:
	CMy2020041304Doc* GetDocument() const;

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
	virtual ~CMy2020041304View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 2020041304View.cpp 中的调试版本
inline CMy2020041304Doc* CMy2020041304View::GetDocument() const
   { return reinterpret_cast<CMy2020041304Doc*>(m_pDocument); }
#endif

