
// 2020031701.h : 2020031701 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy2020031701App:
// �йش����ʵ�֣������ 2020031701.cpp
//

class CMy2020031701App : public CWinApp
{
public:
	CMy2020031701App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2020031701App theApp;
