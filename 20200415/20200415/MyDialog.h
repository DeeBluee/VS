#pragma once
#include "afxwin.h"
#include "20200415View.h"
#include "MainFrm.h"
// MyDialog �Ի���

class MyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialog)

public:
	MyDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CMDIChildWnd* pChild;
	CMy20200415View* pView;  
	CListBox b;
	virtual BOOL OnInitDialog();
	CString a;
};
