
// 2020050401.h : 2020050401 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy2020050401App:
// �йش����ʵ�֣������ 2020050401.cpp
//

class CMy2020050401App : public CWinAppEx
{
public:
	CMy2020050401App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2020050401App theApp;
