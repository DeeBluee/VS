
// 2020042701.h : 2020042701 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy2020042701App:
// �йش����ʵ�֣������ 2020042701.cpp
//

class CMy2020042701App : public CWinAppEx
{
public:
	CMy2020042701App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2020042701App theApp;
