
// 20200330View.h : CMy20200330View ��Ľӿ�
//

#pragma once


class CMy20200330View : public CView
{
protected: // �������л�����
	CMy20200330View();
	DECLARE_DYNCREATE(CMy20200330View)

// ����
public:
	CMy20200330Doc* GetDocument() const;

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
	virtual ~CMy20200330View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // 20200330View.cpp �еĵ��԰汾
inline CMy20200330Doc* CMy20200330View::GetDocument() const
   { return reinterpret_cast<CMy20200330Doc*>(m_pDocument); }
#endif

