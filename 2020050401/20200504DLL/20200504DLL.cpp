// 20200504DLL.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "20200504DLL.h"


// 这是导出变量的一个示例
MY20200504DLL_API int nMy20200504DLL=0;

// 这是导出函数的一个示例。
MY20200504DLL_API int fnMy20200504DLL(void)
{
    return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 20200504DLL.h
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
