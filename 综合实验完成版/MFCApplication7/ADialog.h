#pragma once


// ADialog �Ի���

class ADialog : public CDialogEx
{
	DECLARE_DYNAMIC(ADialog)

public:
	ADialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ADialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
