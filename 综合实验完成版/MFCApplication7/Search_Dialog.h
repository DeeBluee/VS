#pragma once


// Search_Dialog 对话框

class Search_Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(Search_Dialog)

public:
	Search_Dialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Search_Dialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Search };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString search;
};
