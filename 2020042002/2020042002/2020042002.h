
// 2020042002.h : 2020042002 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy2020042002App:
// �йش����ʵ�֣������ 2020042002.cpp
//

class CMy2020042002App : public CWinAppEx
{
public:
	CMy2020042002App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2020042002App theApp;
