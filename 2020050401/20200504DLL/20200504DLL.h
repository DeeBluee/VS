// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� MY20200504DLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// MY20200504DLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef MY20200504DLL_EXPORTS
#define MY20200504DLL_API __declspec(dllexport)
#else
#define MY20200504DLL_API __declspec(dllimport)
#endif

// �����Ǵ� 20200504DLL.dll ������
class MY20200504DLL_API CMy20200504DLL {
public:
	CMy20200504DLL(void);
	// TODO:  �ڴ�������ķ�����
};

extern MY20200504DLL_API int nMy20200504DLL;

MY20200504DLL_API int fnMy20200504DLL(void);

MY20200504DLL_API int factorial_dll(int n);

class MY20200504DLL_API FAC_dll {
public:
	float convert_dll(float deg);
};
