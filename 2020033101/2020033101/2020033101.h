
// 2020033101.h : 2020033101 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy2020033101App:
// �йش����ʵ�֣������ 2020033101.cpp
//

class CMy2020033101App : public CWinAppEx
{
public:
	CMy2020033101App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2020033101App theApp;
