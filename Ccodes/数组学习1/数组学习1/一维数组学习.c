#include <stdio.h>

//int main()
//{
//	int i = 0;
//	int arr1[] = { 1, 2, 3, 4, 5 };
//	int arr2[5] = { 1, 2, 3, 4, 5 };
//
//	char ch1[] = { 'b', 'i', 't' };
//	char ch2[5] = { 'b', 'i', 't' };
//	char ch3[] = "bit";
//	char ch4[5] = "bit";
//
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ",arr1[i]);
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ",arr2[i]);
//	}
//	printf("\n");
//	printf("%s\n",ch1);
//	printf("%s\n",ch2);
//	printf("%s\n",ch3);
//	printf("%s\n",ch4);
//
//	return 0;
//}

////数组常用打印元素方式
//int main()
//{
//	int i = 0;
//	int arr1[10] = { 0 };
//	arr1[4] = 8;
//
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//
//	printf("\n");
//	printf("%d\n", sizeof(arr1));
//	printf("%d\n", sizeof(arr1[0]));
//
//	return 0;
//}

//另外一种方式打印数组
int main()
{
	int i = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* p = arr;//数组名是数组的首位元素地址
	int sz = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < sz; i++)
	{
		printf("%d ", *p);
		p++;
	}

	return 0;
}