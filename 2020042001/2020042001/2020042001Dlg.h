
// 2020042001Dlg.h : 头文件
//

#pragma once


// CMy2020042001Dlg 对话框
class CMy2020042001Dlg : public CDialogEx
{
// 构造
public:
	CMy2020042001Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY2020042001_DIALOG };
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
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	float operated;
	float operate;
	float result;
	CString ope;
	afx_msg void OnBnClickedButton3();
	float x;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
