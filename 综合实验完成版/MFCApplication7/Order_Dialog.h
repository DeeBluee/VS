#pragma once


// Order_Dialog �Ի���

class Order_Dialog : public CDialogEx
{
	DECLARE_DYNAMIC(Order_Dialog)

public:
	Order_Dialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Order_Dialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Order };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString order_by;
};
