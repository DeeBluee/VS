
// 2020041304View.h : CMy2020041304View ��Ľӿ�
//

#pragma once


class CMy2020041304View : public CView
{
protected: // �������л�����
	CMy2020041304View();
	DECLARE_DYNCREATE(CMy2020041304View)

// ����
public:
	CMy2020041304Doc* GetDocument() const;

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
	virtual ~CMy2020041304View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 2020041304View.cpp �еĵ��԰汾
inline CMy2020041304Doc* CMy2020041304View::GetDocument() const
   { return reinterpret_cast<CMy2020041304Doc*>(m_pDocument); }
#endif

