
// 2020041303.h : 2020041303 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy2020041303App:
// �йش����ʵ�֣������ 2020041303.cpp
//

class CMy2020041303App : public CWinAppEx
{
public:
	CMy2020041303App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2020041303App theApp;
