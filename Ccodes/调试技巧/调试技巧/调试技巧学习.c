#include <stdio.h>

//void test()
//{
//	int a = 10;
//	int b = 20;
//	int c = a + b;
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		test();
//		arr[i] = i + 1;
//	}
//
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i < 15; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//
//	return 0;
//}


void fun(int* arr1, int* str1, int sz)  //����ԭ���飬ȡ��������飬ԭ���鳤��
{
	int i = 0;  //ͨ��ѭ������
	for (i = 0; i < sz; i++)
	{
		if (*arr1 % 2 == 0 && *arr1 != '\0')  //������ֵΪż���Ҳ�Ϊ\0ʱ
		{
			*str1 = *arr1;  //����ǰֵ��ֵ��ȡ���������
			str1++;  //��ַ��1
		}
		arr1++;  //��ַ��1��int��λ����
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int str[] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	fun(arr, str, sz);

	int s = sizeof(str) / sizeof(str[0]);
	int i = 0;
	for (i = 0; i < s; i++)
	{
		printf("%c", str[i]);
	}

	return 0;
}
