
// 2020032401View.h : CMy2020032401View ��Ľӿ�
//

#pragma once


class CMy2020032401View : public CView
{
protected: // �������л�����
	CMy2020032401View();
	DECLARE_DYNCREATE(CMy2020032401View)

// ����
public:
	CMy2020032401Doc* GetDocument() const;

// ����
public:

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
	virtual ~CMy2020032401View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // 2020032401View.cpp �еĵ��԰汾
inline CMy2020032401Doc* CMy2020032401View::GetDocument() const
   { return reinterpret_cast<CMy2020032401Doc*>(m_pDocument); }
#endif

