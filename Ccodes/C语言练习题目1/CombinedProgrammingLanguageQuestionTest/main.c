//#define _CRT_SECURE_NO_WARNINGS  1
//
////C语言题目测试
////共10题
//
//
////第1题
////输入两个整数，输出它们的和
//#include <stdio.h>
//
//int main()
//{
//	int a, b;
// 
//	scanf("%d%d", &a, &b);
//
//	printf("%d\n", a + b);
//
//	return 0;
//}
//
//
////第2题
////输入两个整数，交换它们的值
//#include <stdio.h>
//
//int main()
//{
//	int a, b, temp;
//
//	scanf("%d%d", &a, &b);
//
//	temp = a;
//	a = b;
//	b = temp;
//
//	printf("%d %d", a, b);
//
//	return 0;
//}
//
//
////第3题
////输入3个double类型的值，判断这三个值能否表示一个三角形的三条边
//#include <stdio.h>
//
//int main()
//{
//	double a, b, c;
//
//	scanf("%lf%lf%lf", &a, &b, &c);
//
//	//三角形两边之和大于第三边
//	if (a + b > c && a + c > b && b + c > a)
//	{
//		printf("是\n");
//	}
//	else
//	{
//		printf("否\n");
//	}
//
//	return 0;
//}
//
//
////第4题
////输入一个数，判断它是否为奇数，如果输入为负数，则输出“负数没有奇数偶数之分”
//#include <stdio.h>
//
//int main()
//{
//	int x;
//
//	scanf("%d", &x);
//
//	if (x < 0)
//	{
//		printf("负数没有奇数偶数之分\n");
//	}
//	else if (x % 2 == 0)
//	{
//		printf("%d是偶数\n", x);
//	}
//	else
//	{
//		printf("%d是奇数\n", x);
//	}
//
//	return 0;
//}
//
//
////第5题
////循环打印1~10的值
//#include <stdio.h>
//
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		printf("%d ", i);
//		i++;
//	}
//
//	return 0;
//}
//
//
//
////第6题
////输入10个数，计算出它们的最大值、最小值和平均值并输出
//#include <stdio.h>
//
//#define INT_MAX  2147483647
//
//int main()
//{
//	int num = 0;
//	int max = -(INT_MAX + 1), min = INT_MAX;  //存储最大值和最小值
//	double avg = 0; //存储平均值
// 
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &num);
//		if (num > max)  //当输入数大于最大值，将num赋值给max
//		{
//			max = num;
//		}
//		if (num < min)  //当输入数小于最小值，将num赋值给min
//		{
//			min = num;
//		}
//		avg += (double)num;  //计算10个数的和
//	}
//	avg /= 10;  //将10个数的和除以10
//
//	printf("%d %d %lf\n", max, min, avg);
//}
//
//
////第7题
////计算n的阶乘
//#include <stdio.h>
//
//int main()
//{
//	int n, num = 1;
//
//	scanf("%d", &n);
//
//	while (n)
//	{
//		num *= n;
//		n--;
//	}
//
//	printf("%d\n", num);
//
//	return 0;
//}
//
//
////第8题
////印度国王的奖励，计算2的0次方加到2的63次方
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	double sum = 0;  //存储结果值
//	for (int i = 0; i < 64; i++)
//	{
//		sum += pow(2, i);
//	}
//	printf("%lf\n", sum);
//
//	return 0;
//}
//
//
////第9题
////给定一个整形数组，将数组内的元素逆序排列并输出
//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 0 };
//
//	//输入数组内容
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	//将数组元素倒置
//	for (int i = 0; i < 10 / 2; i++)
//	{
//		int temp = arr[i];
//		arr[i] = arr[10 - i - 1];
//		arr[10 - i - 1] = temp;
//	}
//
//	//输出数组内容
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}
//
//
////第十题
////编写程序，将给定的字符串去掉重复字符后，将其输出
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str[100] = {"This is a string"};
//	char ch = 0;
//
//	//可搜索“scanf的高级用法”了解
//	scanf("%[^\n]", str);  //输入一串以回车结尾的字符串，可以读取空格
//	scanf("%*c");		   //读取并丢弃缓冲区中的换行符，防止对后一句中的输入产生影响
//	scanf("%c", &ch);	   //输入想要去掉的字符
//
//	//strlen函数计算字符串长度
//	for (int i = 0; i < strlen(str); i++)
//	{
//		//当数组第i个值为给定字符时
//		if (str[i] == ch)
//		{
//			//从此字符位置开始，后面的字符向前挪到数组前一位 
//			for (int j = i; j < strlen(str); j++)
//			{
//				str[j] = str[j + 1]; 
//			}
//		}
//	}
//
//	printf("%s", str);  //输出这个字符串
//
//	return 0;
//}