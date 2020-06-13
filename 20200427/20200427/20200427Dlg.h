
// 20200427Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMy20200427Dlg 对话框
class CMy20200427Dlg : public CDialogEx
{
// 构造
public:
	CMy20200427Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20200427_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	~CMy20200427Dlg();
	CString filename;
	CListBox LBox;
	CString data;
	CString save_data;
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClose();
	
};
