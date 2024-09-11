#define _CRT_SECURE_NO_WARNINGS  1
//
////1.给定一个华氏温度F，本题要求编写程序，计算对应的摄氏温度C。
//#include <stdio.h>
//
//int main()
//{
//	int C = 0, F = 0;
//
//	scanf("%d", &F);
//
//	C = 5 * (F - 32) / 9;
//
//	printf("摄氏温度为%d\n", C);
//
//	return 0;
//}
//
//
////2.输入三个整数，比较三个数的大小并由大到小输出。
////(1)比较法
//#include <stdio.h>
//
//int main()
//{
//	int a = 0, b = 0, c = 0, temp = 0;
//
//	scanf("%d%d%d", &a, &b, &c);
//
//	if (a < b)
//	{
//		temp = a;
//		a = b;
//		b = temp;
//	}
//	if (a < c)
//	{
//		temp = a;
//		a = c;
//		c = temp;
//	}
//	if (b < c)
//	{
//		temp = b;
//		b = c;
//		c = temp;
//	}
//
//	printf("%d %d %d\n", a, b, c);
//
//	return 0;
//}
//
////(2)排序法
//#include <stdio.h>
//
//#define ARR_MAX  3   //数组大小
//
//int main()
//{
//	int arr[ARR_MAX] = { 0 };
//
//	for (int i = 0; i < ARR_MAX; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	//冒泡排序
//	for (int i = 0; i < ARR_MAX; i++)
//	{
//		for (int j = 0; j < ARR_MAX - 1; j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//
//	for (int i = 0; i < ARR_MAX; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}
//
//
////3.输入一段数字（长度10个以内），输出其中‘5’的个数
//#include <stdio.h>
//
//int main()
//{
//	int num = 0, count = 0;
//
//	scanf("%d", &num);
//
//	//当数字小于0后跳出循环
//	while (num > 0)
//	{
//		int n = num % 10;  //每次取出num的最后一位
//		num /= 10;         //将num最后一位去掉
//
//		if (n == 5)
//		{
//			count++;
//		}
//	}
//
//	printf("%d\n", count);
//
//	return 0;
//}
//
//
////4.用调用函数的方法计算1!＋2!+3!……n!
//#include <stdio.h>
//
////计算n的阶乘
//int factorial(int n)
//{
//	int ret = 1;
//	while (n > 0)
//	{
//		ret *= n;
//		n--;
//	}
//	return ret;
//}
//
////计算1!＋2!+3!……n!
//int func(int n)
//{
//	int ret = 0;
//	while (n > 0)
//	{
//		ret += factorial(n);
//		n--;
//	}
//	return ret;
//}
//
//int main()
//{
//	int num = 0;
//
//	scanf("%d", &num);
//
//	printf("%d\n", func(num));
//
//	return 0;
//}
//
//
////5.一个皮球从100米高度自由落下，每次落地后反弹回原高度的一半，
////再落下，再反弹。求当它第10次落地时，共经过了多少米，第10次反弹多高？
//#include <stdio.h>
//
//int main()
//{
//	double hight = 100, distance = 100;
//
//	for (int i = 0; i < 9; i++)
//	{
//		hight /= 2;
//		distance += 2 * hight;
//	}
//	hight /= 2;
//
//	printf("%lf %lf", distance, hight);
//
//	return 0;
//}
//
//
////6.输入一个整数，输出一个数字金字塔。
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++)  //金字塔有n行
//	{
//		//打印前面的空格
//		for (int j = 1; j < n - i; j++)
//		{
//			printf(" ");
//		}
//		//打印前半部分数字
//		for (int j = 1; j <= i + 1; j++)
//		{
//			printf("%d", j);
//		}
//		//打印后半部分数字
//		for (int j = i; j > 0; j--)
//		{
//			printf("%d", j);
//		}
//		printf("\n");  //打印换行
//	}
//
//	return 0;
//}
//
//
////7.
//#include <stdio.h>
//
//int main()
//{
//	int a[3][4] = { {5,7,13,34}, {78,26,12,19}, {63,97,81,15} };
//	int num = 0;
//	int i = 0, j = 0;
//	int flag = 0;  //判断是否找到的标志位
//
//	scanf("%d", &num);
//
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			if (a[i][j] == num)  //找到这个数后
//			{
//				printf("%d %d\n", i + 1, j + 1);
//				flag = 1;  //标志位置1
//				break;  //跳出循环
//			}
//		}
//	}
//
//	if (flag == 0)
//	{
//		printf("找不到\n");
//	}
//
//	return 0;
//}
//
//
////8.
//#include <stdio.h>
//
//double fact(int n)
//{
//	double ret = 1;
//
//	while (n > 0)
//	{
//		ret *= n;
//		n--;
//	}
//
//	return ret;
//}
//
//double func(int m, int n)
//{
//	return fact(m) * fact(n - m) / fact(n);
//}
//
//int main()
//{
//	int m = 0, n = 0;
//
//	scanf("%d%d", &m, &n);
//
//	printf("%lf\n", func(m, n));
//
//	return 0;
//}
//
//
////9.黑洞数
//#include <stdio.h>
//int	main(void)
//{
//	int	num;
//	int i, j, k, a, b, c, d;
//
//	scanf("%d", &num);
//
//	for (k = 1; num != 6174; k++) {
//
//		int number[4] = { 0 }, number0[1000] = { 0 };
//
//		//将数字的四位分别拆出来
//		for (i = 0; i < 4; i++) {
//			number[i] = num % 10;
//			num /= 10;
//		}
//
//		if (number[0] == number[1] && number[0] == number[2] && number[0] == number[3]) {
//			printf("这不是一个黑洞数。\n");
//			break;
//		}
//		else {
//			j = 0;
//			//利用穷举法找出最大最小值
//			for (a = 0; a < 4; a++) {
//				for (b = 0; b < 4; b++) {
//					for (c = 0; c < 4; c++) {
//						for (d = 0; d < 4; d++) {
//							if (a != b && a != c && a != d && b != c && b != d && c != d) {
//								number0[j] = number[a] * 1000 + number[b] * 100 + number[c] * 10 + number[d];
//								j++;
//							}
//						}
//					}
//				}
//			}
//
//			int max = number0[0], min = number0[0];
//
//			for (i = 1; i < j; i++) {
//				if (number0[i] > max)
//					max = number0[i];
//				if (number0[i] < min)
//					min = number0[i];
//			}
//
//			printf("%d-%d=%d\n", max, min, max - min);
//
//			num = max - min;
//		}
//	}
//
//	return 0;
//}
//
//
////10.花坛
//#include <stdio.h>
//
//int main()
//{
//	int flowerbed[1000] = { 0 };
//	int n = 0;  //花坛的长度
//	int count = 0;  //可插入花的个数
//	int num = 0;  //准备插入的花的个数
//
//	scanf("%d", &n);  //输入花坛长度
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &flowerbed[i]);  //输入花坛种花情况
//	}
//	scanf("%d", &num);  //输入准备插入花的个数
//
//	for (int i = 0; i < n; i++)
//	{
//		if (i == 0)  //花坛开始的位置
//		{
//			if (flowerbed[0] == 0 && flowerbed[1] == 0)
//			{
//				count++;
//				flowerbed[0] = 1;
//			}
//		}
//		else if (i == n - 1)  //花坛最后的位置
//		{
//			if (flowerbed[i] == 0 && flowerbed[i - 1] == 0)
//			{
//				count++;
//				flowerbed[i] = 1;
//			}
//		}
//		else  //花坛的其他位置
//		{
//			if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
//			{
//				count++;
//				flowerbed[i] = 1;
//			}
//		}
//	}
//
//	printf("%s\n", num <= count ? "true" : "false");
//
//	return 0;
//}
//
//
////11.将任意字符串（0-9）转换为整数
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str[100] = { 0 };
//	int num = 0;  //最终转换的到的数字
//	int len = 0;  //存储输入字符长度
//
//	scanf("%s", str);
//	len = strlen(str);
//
//	for (int i = 0; i < len; i++)
//	{
//		num *= 10;
//		num += str[i] - '0';
//	}
//
//	printf("%d\n", num);
//
//	return 0;
//}
//
//
////12.冰雹数
//#include<stdio.h>
//int main()
//{
//	int n, max;
//	scanf("%d", &n);
//	max = n;
//	for (int i = 1; i <= n; i++)
//	{
//		int temp = i;
//		while (temp > 1)
//		{
//			if (temp % 2 == 0)
//			{
//				temp = temp / 2;
//			}
//			else
//			{
//				temp = temp * 3 + 1;
//			}
//			if (max < temp)
//			{
//				max = temp;
//			}
//		}
//	}
//	printf("%d\n", max);
//	return 0;
//}
