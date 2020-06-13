#pragma once


// Order_Dialog 对话框

class Order_Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(Order_Dialog)

public:
	Order_Dialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Order_Dialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Order };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString order_by;
};
