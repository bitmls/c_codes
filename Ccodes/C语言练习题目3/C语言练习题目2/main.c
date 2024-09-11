//#define _CRT_SECURE_NO_WARNINGS  1
//
////第1题
////输入一个正整数，画出一个对应层数的三角形
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		//打印空格部分
//		for (int j = i + 1; j < n; j++)
//		{
//			printf(" ");
//		}
//		//打印星号部分
//		for (int j = 0; j < i * 2 + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	return 0;
//}
//
//
////第2题
////编写程序，计算序列 1 + 1/2 + 1/3 + ... 的前N项之和，输出时保留3位小数。
//#include <stdio.h>
//
//int main()
//{
//	double ret = 0;  //存储最后输出的值
//	int n = 0;
// 
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++)
//	{
//		ret += 1.0 / (double)i;  //ret每次加上1/n
//	}
//
//	printf("%.3lf", ret);
//
//	return 0;
//}
//
//
////第3题
////输入一个年份，判断这个年份是不是闰年
//#include <stdio.h>
//
//int main()
//{
//	int year = 0;
//
//	scanf("%d", &year);
//
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//	{
//		printf("%d年是闰年\n", year);
//	}
//	else
//	{
//		printf("%d年不是闰年\n", year);
//	}
//
//	return 0;
//}
//
//
////第4题
////输出100~200之间的素数
//#include <stdio.h>
//#include <math.h>
//
//int isPrime(int x)
//{
//	for (int i = 2; i <= sqrt(x); i++)
//	{
//		//判断x是否能被整除，如果能被整除，则不为素数，返回0
//		if (x % i == 0)
//		{
//			return 0;
//		}
//	}
//	//如果不能被整除，则返回这个数
//	return x;
//}
//
//int main()
//{
//	int num = 0;
//	for (int i = 100; i <= 200; i++)
//	{
//		num = isPrime(i);
//		if (num != 0)
//		{
//			printf("%d ", num);
//		}
//	}
//
//	return 0;
//}
//
//
////第5题
////高速公路超速处罚
//#include <stdio.h>
//
//int main()
//{
//	int v, max_v;  //车速和限速
//	double proportion;  //超速比例
//
//	scanf("%d%d", &v, &max_v);
//
//	proportion = (double)(v - max_v) / (double)max_v;
//
//	if (proportion <= 0.1)
//	{
//		printf("OK\n");
//	}
//	else if (proportion > 0.1 && proportion < 0.5)
//	{
//		printf("Exceed %.lf%%. Ticket 200", proportion * 100);
//	}
//	else
//	{
//		printf("Exceed %.lf%%. License Revoked", proportion * 100);
//	}
//
//	return 0;
//}
//
//
////第6题
////金币
//#include <stdio.h>
//
////计算并返回1+2+...+n的值
//int accumulate(int n)
//{
//	int ret = 0;
//	while (n)
//	{
//		ret += n;
//		n--;
//	}
//	return ret;
//}
//
//int main()
//{
//	int k = 0;     //发放金币的天数
//	int wage = 1;  //骑士当天的工资
//	int sum = 0;   //骑士得到的总金币数
//
//	scanf("%d", &k);
//
//	for (int i = 1; i <= k; i++)
//	{
//		sum += wage;  //骑士每天获得当天的工资
//		if (i == accumulate(wage))  //当前天数达到工资增长的天数时
//		{
//			wage++;  //让工资+1
//		}
//	}
//
//	printf("%d\n", sum);
//
//	return 0;
//}
//
//
////第7题
////质数口袋
//#include <stdio.h>
//#include <math.h>
//
////判断一个数是否为质数，若为质数则返回这个数，若不为则返回0
//int isPrime(int num)
//{
//	for (int i = 2; i <= sqrt(num); i++)
//	{
//		if (num % i == 0)
//		{
//			return 0;
//		}
//	}
//	return num;
//}
//
//int main()
//{
//	int max_vol = 0;       //表示口袋的最大容量
//	int sum = 0;           //存储当前质数的总和
//	int arr[100] = { 0 };  //用来存储质数
//	int count = 0;         //记录当前存储质数的个数
//
//	scanf("%d", &max_vol);
//
//	while (1)
//	{
//		static int i = 2;
//		
//		sum += isPrime(i);
//
//		//如果这个数为素数并且口袋里的数总和小于最大容量
//		if (isPrime(i) != 0 && sum <= max_vol)
//		{
//			arr[count] = i;  //将这个数存到数组里
//			count++;         //将计数+1
//		}
//		//当总和大于最大值时
//		if (sum > max_vol)
//		{
//			break;
//		}
//
//		i++;
//	}
//	
//	//输出口袋里的数
//	for (int i = 0; i < count; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	printf("%d\n", count);
//
//	return 0;
//}
//
//
////第9题
////不与最大数相同的数字之和
//#include <stdio.h>
//
//int main()
//{
//	int N = 0;
//	int arr[100] = { 0 };
//	int max = -1000000;
//	int sum = 0;
//
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d", &arr[i]);
//		//找到这组数中的最大值
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		//当数组中的元素不为最大值
//		if (arr[i] != max)
//		{
//			sum += arr[i];
//		}
//	}
//
//	printf("%d\n", sum);
//
//	return 0;
//}
//
//
////第10题
////整数去重
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;  //输入元素的个数
//	int arr[100] = { 0 };
//
//	//输入数的个数
//	scanf("%d", &n);
//
//	//循环输入数组里的值
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	//遍历一遍数组
//	for (int i = 0; i < n; i++)
//	{
//		//将j赋值为当前i的下一位置，从当前位置开始向后找是否有相同的元素
//		for (int j = i + 1; j < n; j++)
//		{
//			//循环知道没有找到相同元素后
//			while(arr[j] == arr[i])
//			{
//				//将这个元素后面的元素都向前挪一位
//				for (int k = j; k < n; k++)
//				{
//					arr[k] = arr[k + 1];
//				}
//				n--;  //将总数减1
//			}
//		}
//	}
//
//	//循环打印数组
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}