#define _CRT_SECURE_NO_WARNINGS  1
//
////1.����һ�������¶�F������Ҫ���д���򣬼����Ӧ�������¶�C��
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
//	printf("�����¶�Ϊ%d\n", C);
//
//	return 0;
//}
//
//
////2.���������������Ƚ��������Ĵ�С���ɴ�С�����
////(1)�ȽϷ�
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
////(2)����
//#include <stdio.h>
//
//#define ARR_MAX  3   //�����С
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
//	//ð������
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
////3.����һ�����֣�����10�����ڣ���������С�5���ĸ���
//#include <stdio.h>
//
//int main()
//{
//	int num = 0, count = 0;
//
//	scanf("%d", &num);
//
//	//������С��0������ѭ��
//	while (num > 0)
//	{
//		int n = num % 10;  //ÿ��ȡ��num�����һλ
//		num /= 10;         //��num���һλȥ��
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
////4.�õ��ú����ķ�������1!��2!+3!����n!
//#include <stdio.h>
//
////����n�Ľ׳�
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
////����1!��2!+3!����n!
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
////5.һ��Ƥ���100�׸߶��������£�ÿ����غ󷴵���ԭ�߶ȵ�һ�룬
////�����£��ٷ�����������10�����ʱ���������˶����ף���10�η�����ߣ�
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
////6.����һ�����������һ�����ֽ�������
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++)  //��������n��
//	{
//		//��ӡǰ��Ŀո�
//		for (int j = 1; j < n - i; j++)
//		{
//			printf(" ");
//		}
//		//��ӡǰ�벿������
//		for (int j = 1; j <= i + 1; j++)
//		{
//			printf("%d", j);
//		}
//		//��ӡ��벿������
//		for (int j = i; j > 0; j--)
//		{
//			printf("%d", j);
//		}
//		printf("\n");  //��ӡ����
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
//	int flag = 0;  //�ж��Ƿ��ҵ��ı�־λ
//
//	scanf("%d", &num);
//
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			if (a[i][j] == num)  //�ҵ��������
//			{
//				printf("%d %d\n", i + 1, j + 1);
//				flag = 1;  //��־λ��1
//				break;  //����ѭ��
//			}
//		}
//	}
//
//	if (flag == 0)
//	{
//		printf("�Ҳ���\n");
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
////9.�ڶ���
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
//		//�����ֵ���λ�ֱ�����
//		for (i = 0; i < 4; i++) {
//			number[i] = num % 10;
//			num /= 10;
//		}
//
//		if (number[0] == number[1] && number[0] == number[2] && number[0] == number[3]) {
//			printf("�ⲻ��һ���ڶ�����\n");
//			break;
//		}
//		else {
//			j = 0;
//			//������ٷ��ҳ������Сֵ
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
////10.��̳
//#include <stdio.h>
//
//int main()
//{
//	int flowerbed[1000] = { 0 };
//	int n = 0;  //��̳�ĳ���
//	int count = 0;  //�ɲ��뻨�ĸ���
//	int num = 0;  //׼������Ļ��ĸ���
//
//	scanf("%d", &n);  //���뻨̳����
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &flowerbed[i]);  //���뻨̳�ֻ����
//	}
//	scanf("%d", &num);  //����׼�����뻨�ĸ���
//
//	for (int i = 0; i < n; i++)
//	{
//		if (i == 0)  //��̳��ʼ��λ��
//		{
//			if (flowerbed[0] == 0 && flowerbed[1] == 0)
//			{
//				count++;
//				flowerbed[0] = 1;
//			}
//		}
//		else if (i == n - 1)  //��̳����λ��
//		{
//			if (flowerbed[i] == 0 && flowerbed[i - 1] == 0)
//			{
//				count++;
//				flowerbed[i] = 1;
//			}
//		}
//		else  //��̳������λ��
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
////11.�������ַ�����0-9��ת��Ϊ����
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str[100] = { 0 };
//	int num = 0;  //����ת���ĵ�������
//	int len = 0;  //�洢�����ַ�����
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
////12.������
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
