#pragma once


// ColorDialog �Ի���

class ColorDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ColorDialog)

public:
	ColorDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ColorDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int r;
	int g;
	int b;
};
