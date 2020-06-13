#pragma once


// GDialog 对话框

class GDialog : public CDialogEx
{
	DECLARE_DYNAMIC(GDialog)

public:
	GDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~GDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString gname;
	CString gno;
	CString gdept;
	CString gsex;
	CString gage;
	CString gphone;
	CString gaddress;
	CString gpic_name;
	CString gpic_path;
};
