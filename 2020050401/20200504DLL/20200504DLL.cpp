// 20200504DLL.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "20200504DLL.h"


// ���ǵ���������һ��ʾ��
MY20200504DLL_API int nMy20200504DLL=0;

// ���ǵ���������һ��ʾ����
MY20200504DLL_API int fnMy20200504DLL(void)
{
    return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� 20200504DLL.h
CMy20200504DLL::CMy20200504DLL()
{
    return;
}


int MY20200504DLL_API factorial_dll(int n) {
	if (n >= 20 || n <= 0) {
		return -1;
	}
	if (n == 1) {
		return 1;
	}
	else {
		return n*factorial_dll(n - 1);
	}
}

float MY20200504DLL_API FAC_dll::convert_dll(float deg) {
	float hudu = 3.14 / 180 * deg;
	return hudu;
}
