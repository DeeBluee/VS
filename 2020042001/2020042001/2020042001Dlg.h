
// 2020042001Dlg.h : ͷ�ļ�
//

#pragma once


// CMy2020042001Dlg �Ի���
class CMy2020042001Dlg : public CDialogEx
{
// ����
public:
	CMy2020042001Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY2020042001_DIALOG };
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
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	float operated;
	float operate;
	float result;
	CString ope;
	afx_msg void OnBnClickedButton3();
	float x;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
