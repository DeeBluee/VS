#pragma once
#include "afxwin.h"


// Calculate �Ի���

class Calculate : public CDialogEx
{
	DECLARE_DYNAMIC(Calculate)

public:
	Calculate(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Calculate();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
