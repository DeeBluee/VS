
// 20200415.h : 20200415 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy20200415App:
// �йش����ʵ�֣������ 20200415.cpp
//

class CMy20200415App : public CWinAppEx
{
public:
	CMy20200415App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy20200415App theApp;
