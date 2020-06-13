
// MFCApplication7Set.cpp : CMFCApplication7Set 类的实现
//

#include "stdafx.h"
#include "MFCApplication7.h"
#include "MFCApplication7Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication7Set 实现

// 代码生成在 2020年5月30日, 15:12

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
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CMFCApplication7Set::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x4fe1\x606f;DBQ=C:\\Users\\12850\\Desktop\\\x5b66\x751f\x4fe1\x606f.mdb;DefaultDir=C:\\Users\\12850\\Desktop;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCApplication7Set::GetDefaultSQL()
{
	return _T("[学生信息表]");
}

void CMFCApplication7Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[姓名]"), column1);
	RFX_Text(pFX, _T("[学号]"), column2);
	RFX_Text(pFX, _T("[专业]"), column3);
	RFX_Text(pFX, _T("[性别]"), column4);
	RFX_Text(pFX, _T("[出生年月]"), column5);
	RFX_Text(pFX, _T("[手机号码]"), column6);
	RFX_Text(pFX, _T("[家庭住址]"), column7);
	RFX_Text(pFX, _T("[相片名]"), column8);
	RFX_Text(pFX, _T("[相片文件夹]"), column9);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication7Set 诊断

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

