
// 2020041302View.h : CMy2020041302View ��Ľӿ�
//

#pragma once


class CMy2020041302View : public CView
{
protected: // �������л�����
	CMy2020041302View();
	DECLARE_DYNCREATE(CMy2020041302View)

// ����
public:
	CMy2020041302Doc* GetDocument() const;

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
	virtual ~CMy2020041302View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCalculate();
};

#ifndef _DEBUG  // 2020041302View.cpp �еĵ��԰汾
inline CMy2020041302Doc* CMy2020041302View::GetDocument() const
   { return reinterpret_cast<CMy2020041302Doc*>(m_pDocument); }
#endif

