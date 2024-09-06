#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int a = 0, result = 0, temp = 0;
//	int i, j;
//
//	scanf("%d", &a);
//
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			temp += a * pow(10, j);
//		}
//		result += temp;
//		temp = 0;
//	}
//
//	printf("%d\n", result);
//
//	return 0;
//}


//#include <stdio.h>
//
//void print(int* parr, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", *(parr + i));
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//
//	print(arr, n);
//
//	return 0;
//}



//求出0～100000之间的所有“水仙花数”并输出。
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，
//如 : 153 = 1 ^ 3 + 5 ^ 3 + 3 ^ 3，则153是一个“水仙花数”。

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int num = 0, n = 0, i = 0, num_r = 0,num2 = 0;
//
//	for (int num = 0; num <= 100000; num++)
//	{
//		num_r = num;
//		while (num_r)
//		{
//			num_r /= 10;
//			n++;
//		}
//
//		num_r = num;
//		for (i = 0; i < n; i++)
//		{
//			num2 += pow(num_r % 10, n);
//			num_r /= 10;
//		}
//
//		if (num == num2)
//			printf("%d ", num);
//
//		num2 = 0;
//		n = 0;
//	}
//
//	return 0;
//}



////写一个函数，可以逆序字符串内容
//#include <stdio.h>
//
//int main()
//{
//	char str[] = "abcdefg";
//	char str2[7];
//	int sz = sizeof(str) / sizeof(str[0]);
//	int i = 0, j = 0;
//
//	for (i = sz - 1; i >= 0; i--)
//	{
//		str2[j] = str[i];
//		j++;
//	}
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%c", str2[i]);
//	}
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//void reverse(char* str)
//{
//	assert(str != NULL);
//
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//
//	while (left < right)
//	{
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char str[] = "123456789";
//	reverse(str);
//	printf("%s\n", str);
//
//	return 0;
//}



//用循环的方式打印如下的一个菱形
//       *
//      ***
//     *****
//    *******
//   *********
//  ***********
// *************
//***************
// *************
//  ***********
//   *********
//    *******
//     *****
//      ***
//       *

//#include <stdio.h>
//
//int main()
//{
//	int i = 0, j = 0, n = 0;
//
//	scanf("%d", &n);
//
//	//上半部分
//	for (i = 0; i < n; i++)
//	{
//		//打印空格
//		for (j = 1; j < (n - i); j++)
//		{
//			printf("%c", ' ');
//		}
//		//打印*
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("%c", '*');
//		}
//		printf("\n");
//	}
//	//下半部分
//	for (i = n - 1; i > 0; i--)
//	{
//		//打印空格
//		for (j = i; j <= n - 1; j++)
//		{
//			printf("%c", ' ');
//		}
//		//打印*
//		for (j = 0; j < 2 * i - 1; j++)
//		{
//			printf("%c", '*');
//		}
//		printf("\n");
//	}
//
//	return 0;
//}



//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少瓶汽水(编程实现)

//#include <stdio.h>
//
//int main()
//{
//	int money = 0;
//
//	scanf("%d", &money);
//
//	int num = money, empty_bottle = money;
//
//	while (empty_bottle >= 2)  //当空瓶数能够进行兑换
//	{
//		num += empty_bottle / 2;  //每两个空瓶能喝一次汽水
//		empty_bottle = empty_bottle / 2 + empty_bottle % 2;  //将剩余的空瓶数统计，加上奇数个空瓶漏下的一个空瓶
//	}
//
//	printf("%d\n", num);
//
//	return 0;
//}



//题目名称:
//调整奇数偶数顺序题目内容:
//调整数组使奇数全部都位于偶数前面。
//题目 :
//输入一个整数数组，实现一个函数数，
//来调整该数维中数字的则序使得数组中所有的奇数位于数维的前半部分，所有偶数位于数细的后半部分。

#include <stdio.h>

//int main()
//{
//	int arr[100] = { 0 }, arr1[100] = { 0 }, arr2[100] = { 0 };
//	int i = 0, n = 0, a1 = 0, a2 = 0;
//
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//		if (arr[i] % 2)
//		{
//			arr1[a1] = arr[i];
//			a1++;
//		}
//		else
//		{
//			arr2[a2] = arr[i];
//			a2++;
//		}
//	}
//
//	for (i = 0; i < a1; i++)
//	{
//		arr[i] = arr1[i];
//	}
//	for (i = 0; i < a2; i++)
//	{
//		arr[a1 + i] = arr2[i];
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


//void print(int* parr, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", *(parr + i));
//	}
//	printf("\n");
//}
//
//void move(int* parr, int n)
//{
//	int* left = parr;
//	int* right = parr + n - 1;
//
//	while (left < right)
//	{
//		while(*left % 2 == 1)
//		{
//			left++;
//		}
//		while (*right % 2 == 0)
//		{
//			right--;
//		}
//		if(left < right)
//		{
//			int temp = *left;
//			*left = *right;
//			*right = temp;
//		}
//	}
//}
//
//int main()
//{
//	int arr[100] = { 0 };
//	int i = 0, n = 0;
//
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	move(arr, n);
//	print(arr, n);
//
//	return 0;
//}



//打印一个杨辉三角
//#include <stdio.h>
//
//int main()
//{
//	int arr[10][10] = { 0 };
//	int i = 0, j = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0)
//				arr[i][j] = 1;
//			if (j == i)
//				arr[i][j] = 1;
//			if (i >= 2 && j >= 1)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}



//#include <stdio.h>

//int main()
//{
//	char killer = '\0';
//	int res = 0;
//
//	while(1)
//	{
//		scanf("%c", &killer);
//
//		if (killer != 'a')
//			res++;
//		if (killer == 'c')
//			res++;
//		if (killer == 'd')
//			res++;
//		if (killer != 'd')
//			res++;
//
//		if (res == 3)
//		{
//			printf("killer is %c\n", killer);
//			break;
//		}
//		else
//		{
//			printf("猜测错误\n");
//			res = 0;
//			killer = '\0';
//		}
//	}
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	char killer = 0;
//
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			printf("killer is %c\n", killer);
//		}
//	}
//
//	return 0;
//}




//#include <stdio.h>
//
//int main()
//{
//	int a, b, c, d, e;
//
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b == 2) + (a == 3) == 1)
//							&& ((b == 2) + (e == 4) == 1)
//							&& ((c == 1) + (b == 2) == 1)
//							&& ((c == 5) + (d == 3) == 1)
//							&& ((e == 4) + (a == 1) == 1)
//							)
//						{
//							if (a * b * c * d * e == 120)
//							{
//								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//
//	return 0;
//}



//#include <stdio.h>
//
//void test(int** ppa)
//{
//	**ppa = 20;
//}
//
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int** ppa = &pa;
//
//	test(ppa);
//
//	printf("%d\n", a);
//
//	return 0;
//}


//#include <stdio.h>
//
//int test(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//
//	int arr[10] = { 0 };
//	int(*parr)[10] = &arr;
//
//	int(*pf)(int, int) = &test;
//	
//	int res = (*pf)(5, 6);
//	printf("%d\n", res);
//
//	return 0;
//}



//#include <stdio.h>
//
//typedef void(*pfun_t)(int);
//
//int main()
//{
//	void (*signal(int, void(*)(int)))(int);
//	pfun_t signal(int, pfun_t);
//
//	return 0;
//}


//#include <stdio.h>
//
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int Sub(int a, int b)
//{
//	return a - b;
//}
//
//int Mul(int a, int b)
//{
//	return a * b;
//}
//
//int Div(int a, int b)
//{
//	return a / b;
//}
//
//void menu(void)
//{
//	printf("***********************\n");
//	printf("**** 1.Add   2.Sub ****\n");
//	printf("**** 3.Mul   4.Div ****\n");
//	printf("****     0.exit    ****\n");
//	printf("***********************\n");
//}
//
//int main()
//{
//	int input = 0;
//	int (*pfun[5])(int, int) = { NULL, Add, Sub, Mul, Div };
//
//	do
//	{
//		int a = 0, b = 0, res = 0;
//
//		menu();
//
//		printf("请输入你的选择：");
//		scanf("%d", &input);
//
//		if(input >= 1 && input <= 4)
//		{
//			printf("请输入两个数：");
//			scanf("%d %d", &a, &b);
//			res = pfun[input](a, b);
//		}
//
//		if (input >= 1 && input <= 4)
//			printf("结果为%d\n", res);
//		else if (!input)
//			printf("---退出---\n");
//		else
//			printf("输入错误，请重新输入\n");
//
//	} while (input);
//
//	return 0;
//}


//#include <stdio.h>
//
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int Sub(int a, int b)
//{
//	return a - b;
//}
//
//int Mul(int a, int b)
//{
//	return a * b;
//}
//
//int Div(int a, int b)
//{
//	return a / b;
//}
//
//void menu(void)
//{
//	printf("***********************\n");
//	printf("**** 1.Add   2.Sub ****\n");
//	printf("**** 3.Mul   4.Div ****\n");
//	printf("****     0.exit    ****\n");
//	printf("***********************\n");
//}
//
//int Calc(int(*pfun)(int, int))
//{
//	int  a = 0, b = 0;
//	printf("请输入两个数：");
//	scanf("%d %d", &a, &b);
//	return pfun(a, b);
//}
//
//int main()
//{
//	int input = 0;
//
//	do
//	{
//		int res = 0;
//
//		menu();
//
//		printf("请输入你的选择：");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			res = Calc(Add);
//			printf("%d\n", res);
//			break;
//		case 2:
//			res = Calc(Sub);
//			printf("%d\n", res);
//			break;
//		case 3:
//			res = Calc(Mul);
//			printf("%d\n", res);
//			break;
//		case 4:
//			res = Calc(Div);
//			printf("%d\n", res);
//			break;
//		case 0:
//			printf("---退出---\n");
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}


//#include <stdio.h>
//
//int bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	print_arr(arr, sz);
//	bubble_sort(arr, sz);
//	print_arr(arr, sz);
//
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//void test1(void)
//{
//	//整数类型的比较
//	int arr[10] = { 9, 7, 8, 6, 5, 4, 3, 2, 1, 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	print_arr(arr, sz);
//
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//
//	print_arr(arr, sz);
//}
//
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int cmp_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//
//int cmp_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//void print_Stu_age(struct Stu s[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", (s + i)->age);
//	}
//}
//
//void print_Stu_name(struct Stu s[], int sz)
//{
//	int i = 0; 
//	for (i = 0; i < sz; i++)
//	{
//		printf("%s ", (s + i)->name);
//	}
//}
//
//void test2(void)
//{
//	//结构体类型的比较
//	struct Stu s[3] = { {"zhangsan", 20}, {"lisi", 19}, {"wangwu", 18} };
//	int sz = sizeof(s) / sizeof(s[0]);
//
//	//qsort(s, sz, sizeof(s[0]), cmp_by_age);
//	//print_Stu_age(s, sz);
//
//	qsort(s, sz, sizeof(s[0]), cmp_by_name);
//	print_Stu_name(s, sz);
//}
//
//int main()
//{
//	//test1();
//	test2();
//
//	return 0;
//}



//#include <stdio.h>
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//void Swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char temp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = temp;
//		buf1++;
//		buf2++;
//	}
//}
//
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//int cmp_by_name(const void* e1, const void* e2)
//{
//	return strcmp((*(struct Stu*)e1).name, (*(struct Stu*)e2).name);
//}
//
//void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			//上一值大于下一值，交换
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//void print_int(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//}
//
//void print_name(struct Stu* s, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%s ", *(s + i)->name);
//	}
//}
//
//int main()
//{
//	int arr[10] = { 2, 4, 6, 8, 0, 1, 3, 5, 7, 9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	struct Stu s[3] = { {"zhangsan", 20}, {"lisi", 19}, {"wangwu", 18} };
//	int sz1 = sizeof(s) / sizeof(s[0]);
//
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	print_int(&arr, sz);
//
//	bubble_sort(s, sz1, sizeof(s[0]), cmp_by_name);
//	print_name(s, sz1);
//
//	return 0;
//}



//#include <stdio.h>
//
//int main()
//{
//	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//	char arr[] = "abcdef";
//
//	printf("%d\n", strlen(arr));
//	printf("%d\n", strlen(arr + 0));
//	printf("%d\n", strlen(*arr));
//	printf("%d\n", strlen(arr[1]));
//	printf("%d\n", strlen(&arr));
//	printf("%d\n", strlen(&arr + 1));
//	printf("%d\n", strlen(&arr[0] + 1));
//
//	return 0;
//}



//#include <stdio.h>
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&arr + 1);
//	int* ptr2 = (int*)((int)arr + 1);
//
//	printf("%#x %#x\n", ptr1, ptr2);
//
//	return 0;
//}


#include <stdio.h>

//int main()
//{
//	int a[3][4] = { 0 };
//	int b = 2;
//
//	//printf("%d\n", sizeof(a));
//	//printf("%d\n", sizeof(&a));
//	//printf("%d\n", sizeof(a[0]));
//	//printf("%d\n", sizeof(a[0][0]));
//	//printf("%d\n", sizeof(a[0] + 1));
//	//printf("%d\n", sizeof(a + 1));
//	//printf("%d\n", sizeof(*a));
//
//	char ch;
//	printf("%c", ch = '7' + '9');
//
//	return 0;
//}


//#include <stdio.h>
//
//int numMax(int x)
//{
//	int max = 0;
//	for (int i = 1; i <= x; i++)
//	{
//		int temp = i;
//		while (temp != 1)
//		{
//			//偶数
//			if (temp % 2 == 0)
//			{
//				temp /= 2;
//			}
//			//奇数
//			else
//			{
//				temp = temp * 3 + 1;
//			}
//			if (temp > max)
//				max = temp;
//		}
//	}
//	return max;
//}
//
//int main()
//{
//	int N = 0;
//
//	scanf("%d", &N);
//
//	printf("%d\n", numMax(N));
//
//	return 0;
//}



//#include <stdio.h>
//
//int my_pow(int a, int n);
//
//int main()
//{
//	int a, n;
//
//	scanf("%d %d", &a, &n);
//
//	printf("%d\n", my_pow(a, n));
//
//	return 0;
//}
////你的代码将会放在下方



//#include <stdio.h>
//
////int calc(int a, char symbol, int b);
//
//int main()
//{
//	int a, b;
//	char symbol;
//
//	scanf("%d%c%d", &a, &symbol, &b);
//
//	printf("%d %c %d = \n", a, symbol, b /*calc(a, symbol, b)*/);
//
//	return 0;
//}

//2.实现一个拥有简单计算器功能的函数，能进行加减乘除运算。
//函数定义接口：
//int calc(int a, char symbol, int b);
//
//裁判测试程序样例：
//#include <stdio.h>
//
//int calc(int a, char symbol, int b);
//
//int main()
//{
//	int a, b;
//	char symbol;
//
//	scanf("%d%c%d", &a, &symbol, &b);
//
//	printf("%d %c %d = %d\n", a, symbol, b, calc(a, symbol, b));
//
//	return 0;
//}
//
///* 你的代码将被嵌在这里 */
//
//
//
//输入样例1：3 + 4
//输出样例1：3 + 4 = 7
//输入样例2：5 / 3
//输出样例2：5 / 3 = 1

//#include <stdio.h>
//
//int count(int n);
//
//int main()
//{
//	int num;
//
//	scanf("%d", &num);
//
//	printf("%d\n", count(num));
//
//	return 0;
//}




//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 0 }, sz;
//	sz = sizeof(arr) / sizeof(arr[0]);
//
//	for (int i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	//排序的趟数
//	for (int i = 0; i < sz - 1; i++)
//	{
//		//一趟排序交换的次数
//		for (int j = 0; j < sz - i - 1; j++)
//		{
//			int temp;
//			if (arr[j] > arr[j + 1])
//			{
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


//#include <stdio.h>
//
//int num = 0;
//
//void f(int flower, int store, int sum) //flower记录遇到花的次数，store记录遇到店的次数，
//// sum为当前酒的总数 
//{
//	if (flower > 9 || store > 5)   // 判断递归的出口对于递归来说十分关键 
//		return;
//	if (flower == 9 && store == 5)  //由题意最后一次肯定为花，因此在倒数第二次时的情况为
//									//经过9次花，5次店，并且剩下了一斗酒sum=1
//	{
//		if (sum == 1)
//		{
//			num++;
//			return;
//		}
//		else
//			return;
//	}
//	f(flower + 1, store, sum - 1);   //遇花喝一斗，即sum-1 
//	f(flower, store + 1, sum * 2);   //遇店多一倍，即sum*2 
//}
//
//int main()
//{
//	f(0, 0, 2);  //初次递归的初始条件 
//
//	printf("%d", num);
//	return 0;
//}






//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int num = 0, n = 0, i = 0, num_r = 0, num2 = 0;
//	int a, b;
//
//	scanf("%d %d", &a, &b);
//
//	for (int num = a; num <= b; num++)
//	{
//		//计算该数有多少位
//		num_r = num;
//		while (num_r)
//		{
//			num_r /= 10;
//			n++;
//		}
//
//		//计算每一位数与n乘方后的和
//		num_r = num;
//		for (i = 0; i < n; i++)
//		{
//			num2 += pow(num_r % 10, n);
//			num_r /= 10;
//		}
//
//		//如果结果与原数字相等，则为水仙花数
//		if (num == num2)
//			printf("%d ", num);
//
//		num2 = 0;
//		n = 0;
//	}
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	char* a[] = { "abc", "hello", "alibaba" };
//	char** pa = &a;
//
//	pa++;
//
//	printf("%s\n", *pa);
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	char* c[] = {"ENTER", "NEW", "POINT", "FIRST"};
//	char** cp[] = { c + 3, c + 2, c + 1, c };
//	char*** cpp = cp;
//
//	printf("%s\n", **++cpp);
//	printf("%s\n", *-- * ++cpp + 3);
//	printf("%s\n", *cpp[-2] + 3);
//	printf("%s\n", cpp[-1][-1] + 1);
//
//	return 0;
//}



//#include <stdio.h>
//
//int find_num(int arr[3][3], int* px, int* py, int k)
//{
//	int x = 0, y = *py - 1;
//
//	while (x < *px - 1 && y > 0)
//	{
//		if (arr[x][y] < k)
//		{
//			x++;
//		}
//		else if (arr[x][y] > k)
//		{
//			y--;
//		}
//		else
//		{
//			*px = x;
//			*py = y;
//			return 1;
//		}
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int k = 2;
//	int x = 3, y = 3;
//
//	int ret = find_num(arr, &x, &y, k);
//
//	if (ret == 1)
//	{
//		printf("found it\n");
//		printf("下标为%d %d\n", x, y);
//	}
//	else
//	{
//		printf("not found it\n");
//	}
//
//	return 0;
//}



////字符左旋
//
//#include <stdio.h>
//#include <string.h>
//
//void string_rotation(char* pstr, int k)
//{
//	char ch;
//	for (int i = 0; i < k; i++)
//	{
//		ch = *pstr;  //取出字符数组的首元素字符
//		int j = 0;
//		int len = strlen(pstr);
//		//将后一位置的值放到前一位置去
//		for (j = 0; j < len - 1; j++)
//		{
//			*(pstr + j) = *(pstr + j + 1);
//		}
//		//将第一位的元素放在最后一位去
//		*(pstr + len - 1) = ch;
//	}
//}
//
//int main()
//{
//	char str[] = "ABCDEF";
//	int k = 0;
//
//	scanf("%d", &k);
//
//	string_rotation(&str, k);
//	
//	printf("%s\n", str);
//
//	return 0;
//}


//#include <stdio.h>
//#include <assert.h>
//
//void reverse(char* left, char* right)
//{
//	while (left < right)
//	{
//		char temp;
//		temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//}
//
//void string_rotation(char* pstr, int k)
//{
//	assert(pstr);  //断言，防止pstr为空指针
//
//	int len = strlen(pstr);
//	reverse(pstr, pstr + k - 1); //左边
//	reverse(pstr + k, pstr + len - 1);
//	reverse(pstr, pstr + len - 1);
//}
//
//int main()
//{
//	char str[] = "ABCDEF";
//	int k = 5;
//
//	//scanf("%d", &k);
//
//	string_rotation(str, k);
//
//	printf("%s\n", str);
//
//	return 0;
//}



//#include <string.h>
//#include <stdio.h>
//
//int main()
//{
//	char arr[20] = "hello";
//
//	strncat(arr, arr, 5);
//
//	printf("%s\n", arr);
//
//	return 0;
//}



////判断一个字符串是否是由另一个字符串旋转得到的
//#include <stdio.h>
//#include <string.h>
//
//int is_string_rotation(char* arr, char* arr1)
//{
//	if (strlen(arr1) != strlen(arr))
//		return 0;
//
//	strncat(arr, arr, 5);
//
//	//判断arr1内是否为arr的子串，如果是，返回重复内容的地址，如果不是，返回空指针
//	char* ret = strstr(arr, arr1);
//
//	return ret != NULL;
//}
//
//int main()
//{
//	char arr[20] = "AABCD";
//	char arr1[6] = "CDAAB";
//	int ret = 0;
//
//	ret = is_string_rotation(arr, arr1);
//
//	if (ret == 1)
//	{
//		printf("是左旋的得到的\n");
//	}
//	else
//	{
//		printf("不是左旋得到的\n");
//	}
//
//	return 0;
//}



//#include <stdio.h>
//
//int main()
//{
//	int aa[2][5] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//
//	printf("%d %d\n", *(ptr1 - 1), *(ptr2 - 1));
//
//	return 0;
//}

//#include <stdio.h>
//
//void print_arr(int (*arr)[5], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		int j = 0;
//		for (j = 0; j < col; j++)
//		{
//			printf("%d", *(*(arr + i) + j));
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//
//	print_arr(arr, 3, 5);
//
//	return 0;
//}



//qsort函数实现