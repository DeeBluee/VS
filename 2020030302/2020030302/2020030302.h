
// 2020030302.h : 2020030302 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy2020030302App:
// �йش����ʵ�֣������ 2020030302.cpp
//

class CMy2020030302App : public CWinAppEx
{
public:
	CMy2020030302App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2020030302App theApp;
