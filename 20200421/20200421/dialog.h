#pragma once


// dialog �Ի���

class dialog : public CDialogEx
{
	DECLARE_DYNAMIC(dialog)

public:
	dialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~dialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
