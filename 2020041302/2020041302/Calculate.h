#pragma once
#include "afxwin.h"


// Calculate 对话框

class Calculate : public CDialogEx
{
	DECLARE_DYNAMIC(Calculate)

public:
	Calculate(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Calculate();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	float a;
	float b;
	float d;
	CString c;
	CString e;
	CListBox ch;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};
