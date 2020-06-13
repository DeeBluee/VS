#pragma once


// ADialog 对话框

class ADialog : public CDialogEx
{
	DECLARE_DYNAMIC(ADialog)

public:
	ADialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ADialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString aname;
	CString ano;
	CString adept;
	CString asex;
	CString aage;
	CString aphone;
	CString aaddress;
	CString apic_name;
	CString apic_path;
};
