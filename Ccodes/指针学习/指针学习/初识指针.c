#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	int arr[10] = { 0 };
//	int* pa = arr;
//	int i = 0;
//	int sz = 0;
//
//	sz = sizeof(arr) / sizeof(arr[0]);
//	printf("{");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(pa + i) = 1);
//	}
//	printf("\b}");
//
//	return 0;
//}


//#define N_VALUE 5
//
//int main()
//{
//	float value[N_VALUE];
//	float* vp;
//	for (vp = &value[0]; vp < &value[N_VALUE];)
//	{
//		*vp++ = 0;
//	}
//
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%.2lf ", value[i]);
//	}
//
//	return 0;
//}


//#define NUM 10
//
//int main()
//{
//	int arr[NUM] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int* pend = arr + NUM - 1;
//	while (p <= pend)
//	{
//		printf("%d\n", *p);
//		p++;
//	}
//
//	return 0;
//}


//#include <string.h>
////指针+-整数
//int my_strlen(char* ch)
//{
//	int count = 0;
//	while (*ch != '\0')
//	{
//		count++;
//		ch++;
//	}
//	return count;
//}
//
////指针-指针
//int my_strlen(char* ch)
//{
//	char* start = ch;
//	while (*ch != '\0')
//	{
//		ch++;
//	}
//	return ch - start;
//}
//
//int main()
//{
//	int a = my_strlen("abc");
//	printf("%d\n", a);
//
//	return 0;
//}


//int main()
//{
//	int i, a[10], d = 0, e = 0, g = 0, h = 0;
//	static int b[10], c[10];
//
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (i = 0; i < 10; i++)
//	{
//		if (a[i] % 2 == 0)
//		{
//			b[i] = a[i];
//		}
//		else
//		{
//			c[i] = a[i];
//		}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		d = b[i];
//		e = d + e;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		h = c[i];
//		g = g + h;
//	}
//	printf("偶数和是%d\n", e);
//	printf("奇数和是%d", g);
//}


//int my_strlen(char* str)
//{
//	int count = 0;
//
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//
//	return count;
//}
//
//int my_strlen(char* str)
//{
//	char* start = str;
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return str - start;
//}


//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int* pa = arr;
//	for (i = 0; i < 10; i++)
//	{
//		*(pa + i) = i;
//		printf("%d ", *(pa + i));
//	}
//	printf("\b");
//
//	return 0;
//}

//递归方法
//int my_strlen(char str[])
//{
//	
//}
//
//int main()
//{
//	int ret = 0;
//	ret = my_strlen("abcd efgh");
//	printf("%d\n", ret);
//
//	return 0;
//}



int main()
{
	int a = 10;
	int * pa = &a;
	int* * ppa = &pa;  //二级指针

	return 0;
}