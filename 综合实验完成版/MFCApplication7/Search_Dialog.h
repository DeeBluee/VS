#pragma once


// Search_Dialog �Ի���

class Search_Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(Search_Dialog)

public:
	Search_Dialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Search_Dialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Search };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString search;
};
