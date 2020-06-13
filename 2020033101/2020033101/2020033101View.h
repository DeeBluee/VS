
// 2020033101View.h : CMy2020033101View 类的接口
//

#pragma once


class CMy2020033101View : public CView
{
protected: // 仅从序列化创建
	CMy2020033101View();
	DECLARE_DYNCREATE(CMy2020033101View)

// 特性
public:
	CMy2020033101Doc* GetDocument() const;

// 操作
public:
	CString s;
	CPoint defp;
	int cs_width = 0, cs_height = 0;
	CRect cr;
	int flag = 0; //插入开关，0表示正常输入，1表示在特定位置插入
	int line = 1; //当前输出在第几行
	int h, l; //分别表示第几行、第几列
	int num=0;//表示每一行有多少字符
	int min = 0;
	int left = 0;
	int left_num = 0;
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
	virtual ~CMy2020033101View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnPaint();
//	afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 2020033101View.cpp 中的调试版本
inline CMy2020033101Doc* CMy2020033101View::GetDocument() const
   { return reinterpret_cast<CMy2020033101Doc*>(m_pDocument); }
#endif

