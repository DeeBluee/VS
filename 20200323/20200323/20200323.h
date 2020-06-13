
// 20200323.h : 20200323 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMy20200323App:
// 有关此类的实现，请参阅 20200323.cpp
//

class CMy20200323App : public CWinAppEx
{
public:
	CMy20200323App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy20200323App theApp;
