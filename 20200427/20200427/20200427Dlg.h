
// 20200427Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMy20200427Dlg �Ի���
class CMy20200427Dlg : public CDialogEx
{
// ����
public:
	CMy20200427Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20200427_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	~CMy20200427Dlg();
	CString filename;
	CListBox LBox;
	CString data;
	CString save_data;
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClose();
	
};
