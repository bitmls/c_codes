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


void fun(int* arr1, int* str1, int sz)  //接收原数组，取出后的数组，原数组长度
{
	int i = 0;  //通用循环变量
	for (i = 0; i < sz; i++)
	{
		if (*arr1 % 2 == 0 && *arr1 != '\0')  //当数组值为偶数且不为\0时
		{
			*str1 = *arr1;  //将当前值赋值给取出后的数组
			str1++;  //地址加1
		}
		arr1++;  //地址加1个int单位长度
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
