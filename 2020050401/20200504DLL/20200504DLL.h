// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 MY20200504DLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// MY20200504DLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef MY20200504DLL_EXPORTS
#define MY20200504DLL_API __declspec(dllexport)
#else
#define MY20200504DLL_API __declspec(dllimport)
#endif

// 此类是从 20200504DLL.dll 导出的
class MY20200504DLL_API CMy20200504DLL {
public:
	CMy20200504DLL(void);
	// TODO:  在此添加您的方法。
};

extern MY20200504DLL_API int nMy20200504DLL;

MY20200504DLL_API int fnMy20200504DLL(void);

MY20200504DLL_API int factorial_dll(int n);

class MY20200504DLL_API FAC_dll {
public:
	float convert_dll(float deg);
};
