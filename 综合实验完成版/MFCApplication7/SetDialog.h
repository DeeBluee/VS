#pragma once


// SetDialog �Ի���

class SetDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SetDialog)

public:
	SetDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SetDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString set;
};
