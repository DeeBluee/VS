
// 2020032402View.h : CMy2020032402View ��Ľӿ�
//

#pragma once


class CMy2020032402View : public CView
{
protected: // �������л�����
	CMy2020032402View();
	DECLARE_DYNCREATE(CMy2020032402View)

// ����
public:
	CMy2020032402Doc* GetDocument() const;

// ����
public:
	CBitmap bm;
	int bm_width, bm_height;
	
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
	virtual ~CMy2020032402View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 2020032402View.cpp �еĵ��԰汾
inline CMy2020032402Doc* CMy2020032402View::GetDocument() const
   { return reinterpret_cast<CMy2020032402Doc*>(m_pDocument); }
#endif

