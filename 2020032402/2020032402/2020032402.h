
// 2020032402.h : 2020032402 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy2020032402App:
// �йش����ʵ�֣������ 2020032402.cpp
//

class CMy2020032402App : public CWinApp
{
public:
	CMy2020032402App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2020032402App theApp;
