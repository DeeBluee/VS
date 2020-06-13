
// MFCApplication7View.h : CMFCApplication7View 类的接口
//

#pragma once
#include "string"
#include "MFCApplication7Doc.h"
using namespace std;
class CMFCApplication7Set;

class CMFCApplication7View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCApplication7View();
	DECLARE_DYNCREATE(CMFCApplication7View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION7_FORM };
#endif
	CMFCApplication7Set* m_pSet;

// 特性
public:
	CMFCApplication7Doc* GetDocument() const;

// 操作
public:
	CString path;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCApplication7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString sname;
	CString sno;
	CString sdept;
	CString ssex;
	CString sage;
	CString sphone;
	CString saddress;
	CString pic_name;
	CString pic_path;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};

#ifndef _DEBUG  // MFCApplication7View.cpp 中的调试版本
inline CMFCApplication7Doc* CMFCApplication7View::GetDocument() const
   { return reinterpret_cast<CMFCApplication7Doc*>(m_pDocument); }
#endif

