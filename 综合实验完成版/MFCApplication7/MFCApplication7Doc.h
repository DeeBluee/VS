
// MFCApplication7Doc.h : CMFCApplication7Doc ��Ľӿ�
//


#pragma once
#include "MFCApplication7Set.h"


class CMFCApplication7Doc : public CDocument
{
protected: // �������л�����
	CMFCApplication7Doc();
	DECLARE_DYNCREATE(CMFCApplication7Doc)

// ����
public:
	CMFCApplication7Set m_MFCApplication7Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFCApplication7Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
