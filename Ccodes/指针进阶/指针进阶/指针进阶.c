#include <stdio.h>

//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int b[5] = { 2, 3, 4, 5, 6 };
//	int c[5] = { 3, 4, 5, 6, 7 };
//
//	int* arr[3] = { a, b, c };
//
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(arr[i] + j));
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


int main()
{
	int a = 10;
	int* pa = &a;  //整形指针
	char ch = 'w';
	char* pch = &ch;  //字符指针

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*parr)[10] = &arr;  //数组指针

	double* d[5];
	double* (*pd)[5] = &d;

	return 0;
}