#pragma once
#include "afxwin.h"


// Combine �Ի���

class Combine : public CDialogEx
{
	DECLARE_DYNAMIC(Combine)

public:
	Combine(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Combine();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString a1;
	int a2;
	CString a3;
	CButton show;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};
