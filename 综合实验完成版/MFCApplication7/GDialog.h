#pragma once


// GDialog �Ի���

class GDialog : public CDialogEx
{
	DECLARE_DYNAMIC(GDialog)

public:
	GDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~GDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
