
// 20200427.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy20200427App: 
// �йش����ʵ�֣������ 20200427.cpp
//

class CMy20200427App : public CWinApp
{
public:
	CMy20200427App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy20200427App theApp;