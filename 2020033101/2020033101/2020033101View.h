
// 2020033101View.h : CMy2020033101View ��Ľӿ�
//

#pragma once


class CMy2020033101View : public CView
{
protected: // �������л�����
	CMy2020033101View();
	DECLARE_DYNCREATE(CMy2020033101View)

// ����
public:
	CMy2020033101Doc* GetDocument() const;

// ����
public:
	CString s;
	CPoint defp;
	int cs_width = 0, cs_height = 0;
	CRect cr;
	int flag = 0; //���뿪�أ�0��ʾ�������룬1��ʾ���ض�λ�ò���
	int line = 1; //��ǰ����ڵڼ���
	int h, l; //�ֱ��ʾ�ڼ��С��ڼ���
	int num=0;//��ʾÿһ���ж����ַ�
	int min = 0;
	int left = 0;
	int left_num = 0;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy2020033101View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnPaint();
//	afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 2020033101View.cpp �еĵ��԰汾
inline CMy2020033101Doc* CMy2020033101View::GetDocument() const
   { return reinterpret_cast<CMy2020033101Doc*>(m_pDocument); }
#endif

