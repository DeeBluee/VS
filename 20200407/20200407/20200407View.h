
// 20200407View.h : CMy20200407View ��Ľӿ�
//

#pragma once


class CMy20200407View : public CView
{
protected: // �������л�����
	CMy20200407View();
	DECLARE_DYNCREATE(CMy20200407View)

// ����
public:
	CMy20200407Doc* GetDocument() const;

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
	virtual ~CMy20200407View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopdialog();
};

#ifndef _DEBUG  // 20200407View.cpp �еĵ��԰汾
inline CMy20200407Doc* CMy20200407View::GetDocument() const
   { return reinterpret_cast<CMy20200407Doc*>(m_pDocument); }
#endif

