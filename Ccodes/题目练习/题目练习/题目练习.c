#define _CRT_SECURE_NO_WARNINGS  1

//#include <stdio.h>
//
////找出不是两个数组共有的元素
//void fun(int* pa1, int* pa2, int* pd, int s1, int s2)
//{
//	
//}
//
//int main()
//{
//	int arr1[] = { 0 };
//	int arr2[] = { 0 };
//	int different[] = { 0 };
//	int sz1 = 0;
//	int sz2 = 0;
//	printf("请输入一串数字：");
//	int c = 0;  //判断输入字符
//	while((c = getchar()) != 13)
//	fun(arr1, arr2, different, sz1, sz2); 
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	char ch = "A";
//
//	printf("%c\n", ch);
//
//	return 0;
//}

//#include <stdio.h>
//
////利用辗转相除法
//int gcd(int a, int b)
//{
//	int ret = a % b;
//	if (ret == 0)
//		return b;
//	else
//		gcd(b, ret);
//}
//
//int main()
//{
//	int x = 3;
//	int y = 12;
//	int ret = gcd(x, y);
//	printf("%d和%d的最大公约数为%d\n", x, y, ret);
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	char ch[100] = { 0 };
//
//	scanf("%[^\n]", ch);
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int num;
//	scanf("%d", &num);
//
//	printf("%d=", num);
//
//	for (int i = 2; i <= num; i++)
//	{
//		if (num % i == 0)
//		{
//			printf("%d*", i);
//			num /= i;
//			i = 1;
//		}
//	}
// 	printf("\b");
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	double n = 1;
//	double sum = 1;
//	for (i = 0; i < 63; i++)
//	{
//		n *= 2;
//		sum += n;
//	}
//	printf("%lf", sum);
//
//	return 0;
//}



//#include <stdio.h>
//
//int main()
//{
//	int i, n, isPrime = 0;
//
//	printf("1\n");
//	for (n = 2; n < 100; n++)
//	{
//		for (i = 2; i < n; i++)
//		{
//			if (n % i == 0)
//			{
//				isPrime = 1;
//				break;
//			}
//		}
//		if (isPrime == 0)
//		{
//			printf("%d\n", n);
//		}
//	}
//
//	return 0;
//}


////第1题
////输出不同的三位数
//#include<stdio.h> 
//main(void)
//{
//	int x, y, z, sum;
//	sum = 0;
//
//	for (x = 1; x < 5; ++x)
//	{
//		for (y = 1; y < 5; ++y)
//		{
//
//			for (z = 1; z < 5; ++z)
//			{
//				if (x != y && x != z && y != z)
//				{
//					printf("%d%d%d\n", x, y, z);
//					++sum;
//				}
//			}
//
//		}
//
//	}
//	printf("sum=%d\n", sum);
//}


////第2题
////分奇偶数 
//#include <stdio.h>
//
//int main()
//{
//	int i, n, a;
//	scanf("%d", &n);
//	int A = 0, B = 0;
//
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &a);
//		if (a % 2 == 0)
//		{
//			A++;
//		}
//		else
//		{
//			B++;
//		}
//
//	}
//
//	printf("%d %d", B, A);
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int i, j, result;
//	printf("\n");
//	for (i = 1; i < 10; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			result = i * j;
//			printf("%d*%d=%-3d", j, i, result);
//
//		}
//		printf("\n");/* 每一行后换行 */
//	}
//}


////第4题
////肥胖问题
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	double m, h;
//	double BMI;
//
//	scanf("%lf%lf", &m, &h);
//
//	BMI = m / (pow(h, 2));
//
//	if (BMI < 18.5)
//	{
//		printf("Underweight\n");
//	}
//	else if (BMI >= 18.5 && BMI < 24)
//	{
//		printf("Normal\n");
//	}
//	else
//	{
//		printf("%.2lf\n", BMI);
//		printf("Overweight\n");
//	}
//
//	return 0;
//}


#include <stdio.h>

int main()
{
	float a, cost = 0.0;
	int b, c, time = 0, s;
	int cost1, cost2;
	scanf("%f %d", &a, &b);
	if (!a % 1 == 0)
	{
		s = a / 1 + 1;
	}
	time = b / 5;
	if (s <= 3)
	{
		cost = 10;
	}
	if (s <= 10 && s > 3)
	{
		cost = 10 + (a - 3) * 2;
	}
	if (s > 10)
	{
		cost = 10 + 14 + (a - 10) * 3;
	}
	if (!time == 0)
	{
		cost += time * 2;
	}
	cost2 = cost * 10;
	c = cost2 % 10;
	if (c >= 5)
	{
		cost1 = cost / 1 + 1;
	}
	else
	{
		cost1 = cost / 1;
	}

	printf("%d", cost1);
	return 0;
}