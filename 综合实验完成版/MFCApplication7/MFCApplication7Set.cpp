
// MFCApplication7Set.cpp : CMFCApplication7Set ���ʵ��
//

#include "stdafx.h"
#include "MFCApplication7.h"
#include "MFCApplication7Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication7Set ʵ��

// ���������� 2020��5��30��, 15:12

IMPLEMENT_DYNAMIC(CMFCApplication7Set, CRecordset)

CMFCApplication7Set::CMFCApplication7Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = L"";
	column3 = L"";
	column4 = L"";
	column5 = L"";
	column6 = L"";
	column7 = L"";
	column8 = L"";
	column9 = L"";
	m_nFields = 10;
	m_nDefaultType = dynaset;
}
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCApplication7Set::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x4fe1\x606f;DBQ=C:\\Users\\12850\\Desktop\\\x5b66\x751f\x4fe1\x606f.mdb;DefaultDir=C:\\Users\\12850\\Desktop;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCApplication7Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��]");
}

void CMFCApplication7Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Text(pFX, _T("[ѧ��]"), column2);
	RFX_Text(pFX, _T("[רҵ]"), column3);
	RFX_Text(pFX, _T("[�Ա�]"), column4);
	RFX_Text(pFX, _T("[��������]"), column5);
	RFX_Text(pFX, _T("[�ֻ�����]"), column6);
	RFX_Text(pFX, _T("[��ͥסַ]"), column7);
	RFX_Text(pFX, _T("[��Ƭ��]"), column8);
	RFX_Text(pFX, _T("[��Ƭ�ļ���]"), column9);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication7Set ���

#ifdef _DEBUG
void CMFCApplication7Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCApplication7Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

