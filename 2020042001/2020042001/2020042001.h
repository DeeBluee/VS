
// 2020042001.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy2020042001App: 
// �йش����ʵ�֣������ 2020042001.cpp
//

class CMy2020042001App : public CWinApp
{
public:
	CMy2020042001App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy2020042001App theApp;