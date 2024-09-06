#define _CRT_SECURE_NO_WARNINGS  1


//第一题  10

//第二题  10

//第三题  10

//第四题  10

//第五题  8

//第六题  4

//第七题  2

//第八题  

//第九题  10

//第十题  

//附加题一

//附加题二



#include <stdio.h>
#define N 10

//int main()
//{
//    int a[N];
//    for (int i = 0; i < N; i++)
//    {
//        scanf("%d", &a[i]);
//    }
//    for (int i = 0; i < N; i++)
//    {
//        for (int j = 0; j < N - 1; j++)
//        {
//            if (a[j] < a[j + 1])
//            {
//                int temp = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = temp;
//            }
//        }
//    }
//    for (int i = 0; i < N; i++)
//    {
//        printf("%d ", a[i]);
//    }
//    return 0;
//}


//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<iostream>
//#include<math.h>
//#include<limits.h>
//#include<stdlib.h>
//
//int m = 0;
//int n = 0;
//void weizhi(int n, int m);
//int x[12] = { 11,27,24,32,17,21,31,34,27,20,12,29 };
//int y[12] = { 22,20,18,17,15,14,14,14,13,11,8,8 };
//int main()
//{
//	int w = 12;
//	while (w > 0)
//	{
//		weizhi(m, n);
//		w = w - 1;
//	}
//
//}
//
//void weizhi(int m, int n)
//{
//	int a = 0;
//	int b = 0;
//	int ax = 0;
//	int ay = 0;
//	int bx = 0;
//	int min = 100000000;
//	int sum = 0;
//
//	for (int i = 0; i < 12; i++)
//	{
//		a = x[i] - m;
//		if (a < 0)
//		{
//			a = 0 - a;
//		}
//		b = y[i] - n;
//		if (b < 0)
//		{
//			b = 0 - b;
//		}
//		sum = a + b;
//		if (min > sum)
//		{
//			min = sum;
//			ax = x[i];
//			ay = y[i];
//			bx = i;
//
//		}
//
//
//	}
//	m = ax;
//	n = ay;
//	x[bx] = 100;
//	y[bx] = 100;
//	printf("%d %d\n", m, n);
//}


//#include <stdio.h>
//
//int main() {
//	int n;
//	char str[4], a;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%s", &str[i]);
//	}
//	for (int j = 0; j < n; j++) {
//		a = str[0];
//		if (a > 32) {
//			a = a - '26';
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		printf("%s", str);
//		printf("\n");
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int sum = 20;
//	int n = 20;
//	int y = 0;
//	int isPrime = 1;
//	while (isPrime)
//	{
//		n = n / 2;
//		sum += n;
//		y = n % 2;
//		if (n == 1)
//			isPrime = 0;
//	}
//	printf("%d", sum);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	char str[200 * 100] = { 0 };
//	char longest_str[200] = { 0 };
//	char shortest_str[200] = { 0 };
//	int max = 0, min = 200;
//	int count = 0;
//
//	scanf("%[^\n]", str);
//
//	int i = 0;
//	while (str[i] != '\0')
//	{
//		if (str[i] == ' ' || str[i] == ',' || str[i] == '.')  //在此之前是一个单词
//		{
//			if (count > max)  //找到最长单词
//			{
//				max = count;
//				int k = 0;
//				for (int j = i - count; j < i; j++)
//				{
//					longest_str[k] = str[j];
//					k++;
//				}
//			}
//			if (count < min)  //找到最短单词
//			{
//				min = count;
//				int k = 0;
//				for (int j = i - count; j < i; j++)
//				{
//					shortest_str[k] = str[j];
//					k++;
//				}
//				shortest_str[k] = '\0';
//			}
//			count = 0;
//			i++;
//		}
//		i++;
//		count++;  //记录单词长度
//	}
//
//	printf("%s\n%s", longest_str, shortest_str);
//
//	return 0;
//}


//已经走过的点要删掉

#include <stdio.h>
#include <math.h>

int GetTheMostClosePoint(int x[], int y[], int* x_now, int* y_now, int len)
{
	int min_s = 10000;
	int min_index = 0;  //最短距离的下标
	for (int i = 0; i < len; i++)
	{
		int distance = 0;
		distance = pow(abs(x[i] - *x_now), 2) + pow(abs(y[i] - *y_now), 2);
		if (distance < min_s)
		{
			min_s = distance;
			min_index = i;
		}
	}
	*x_now = x[min_index];
	*y_now = y[min_index];
	return min_index;
}

void DeletePoint(int x[], int y[], int final_x[], int final_y[], int index, int* len)
{
	static int n = 0;
	final_x[n] = x[index];
	final_y[n] = y[index];
	n++;

	for (int i = index; i < *len - 1; i++)
	{
		x[i] = x[i + 1];
		y[i] = y[i + 1];
	}
	(*len)--;
}

int main()
{
	int x[12] = { 11,27,24,32,17,21,31,34,27,20,12,29 };
	int y[12] = { 22,20,18,17,15,14,14,14,13,11,8 ,8 };

	int final_x[12] = { 0 };
	int final_y[12] = { 0 };

	int x_now = 0, y_now = 0;  //当前点
	int len = 12;  //数组长度
	int min_index = 0;

	while (len)
	{
		min_index = GetTheMostClosePoint(x, y, &x_now, &y_now, len);
		DeletePoint(x, y, final_x, final_y, min_index, &len);
	}

	for (int i = 0; i < 12; i++)
	{
		printf("%d ", final_x[i]);
		printf("%d ", final_y[i]);
		printf("\n");
	}
}


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