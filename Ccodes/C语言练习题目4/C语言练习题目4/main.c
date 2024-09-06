#define _CRT_SECURE_NO_WARNINGS  1

//第1题
//数组调整
//#include <stdio.h>
//
//int main()
//{
//	int arr[1000] = { 0 };
//	int n = 0;  //数组长度
//	int k = 0;  //需要改变的数组的第几个数
//	int sum = 0;  //存储最后输出的和
//
//	scanf("%d%d", &n, &k);
//
//	//输入这个数组
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	arr[k - 1] = -arr[k - 1];  //将对应元素变为负数
//
//	//将所有的值加起来
//	for (int i = 0; i < n; i++)
//	{
//		sum += arr[i];
//	}
//
//	printf("%d", sum);
//
//	return 0;
//}


//第2题
//排排队
//#include <stdio.h>
//
//int main()
//{
//	int arr1[100] = { 0 };  //存储奇数学号
//	int arr2[100] = { 0 };  //存储偶数学号
//	int n = 0;              //总共n个小朋友
//	int count1 = 0, count2 = 0;
//
//	scanf("%d", &n);
//
//	while(count1 + count2 < n)
//	{
//		int num = 0;
//		scanf("%d", &num);
//		if (num % 2 != 0)  //偶数
//		{
//			arr1[count1] = num;
//			count1++;
//		}
//		else  //奇数
//		{
//			arr2[count2] = num;
//			count2++;
//		}
//	}
//
//	for (int i = 0; i < count1; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < count2; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//
//	return 0;
//}


//第3题
//判断字符串是否为回文
#include <stdio.h>
#include <string.h>

int main()
{
	char str[100] = { 0 };
	int result = 1;
	int len = 0;

	scanf("%s", str);

	len = strlen(str);  //计算字符串的长度

	for (int i = 0; i <= len / 2; i++)
	{
		//判断对应位置字符是否不相等
		if (str[i] != str[len - 1 - i])
		{
			result = 0;
		}
	}

	if (result == 1)
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}


//第4题
//最长平台
//#include <stdio.h>
//
//int main()
//{
//	int arr[100] = { 0 };
//	int n = 0;  //数组元素个数
//	int count = 1;
//	int max = 1;  //最长平台数
//
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	for (int i = 0; i < n - 1; i++)
//	{
//		if (arr[i] == arr[i + 1])
//		{
//			count++;  //记录当前平台数
//			//如果当前平台数大于最长平台数，将count赋值给max
//			if (count > max)
//			{
//				max = count;
//			}
//		}
//		//当两个元素不相等时
//		else
//		{
//			count = 1;  //将平台数重新置1
//		}
//	}
//
//	printf("%d\n", max);
//
//	return 0;
//}


//第5题
//白细胞计数
/*思路：将数组输入并排序，将排序后的数组的第一位与最后一位不纳入计算，
最后将平均值与最大误差输出*/
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	double arr[300] = { 0 };
//	int n = 0;             //数组元素个数
//	double avg = 0;        //平均值
//	double max_error = 0;  //最大误差
//
//	scanf("%d", &n);  //输入样本个数
//
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%lf", &arr[i]);  //输入每次样本的值
//	}
//
//	//用冒泡排序法给数组排序
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				double temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//
//	//求和并计算出平均值
//	for (int i = 1; i < n - 1; i++)
//	{
//		avg += arr[i];
//	}
//	avg /= n - 2;
//
//	//计算出最大误差
//	for (int i = 1; i < n - 1; i++)
//	{
//		int error = abs(arr[i] - avg);
//		if (max_error < error)
//		{
//			max_error = error;
//		}
//	}
//
//	//保留两位小数输出
//	printf("%.2lf %.2lf\n", avg, max_error);
//
//	return 0;
//}


//第6题
//开关灯
/*假设灯数组中1为灯的打开状态，0为灯的关闭状态*/
//#include <stdio.h>
//
//int main()
//{
//	int arr[5000] = { 0 };
//	int N = 0;
//
//	scanf("%d", &N);  //输入灯的数量
//
//	for (int i = 0; i < N; i++)
//	{
//		arr[i] = 1;  //初始时所有灯都为开启状态
//	}
//
//	for (int i = 1; i <= N; i++)  //从第一个人到最后一个人
//	{
//		for (int j = 1; j <= N; j++)  //对所有灯进行处理
//		{
//			if (j % i == 0)  //当灯的编号是第i个人的倍数时
//			{
//				arr[j - 1] = !arr[j - 1];
//			}
//		}
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		if (arr[i] == 0)  //输出关闭的灯的编号
//		{
//			printf("%d ", i + 1);
//		}
//	}
//
//	return 0;
//}


//第7题
//棋盘问题
/*找规律，2*3大小的棋盘，1*1的正方形有(2-0)*(3-0)=6个，2*2的正方形有(2-1)*(3-1)=2个
1*2的长方形有(2-0)*(3-1)=4个，1*3的长方形有(2-0)*(3-2)=2个，2*1的长方形有(2-1)*(3-0)=3个，2*3的长方形有(2-1)*(3-2)=1个，
或者计算出所有长方形和正方形的和(3+2+1)*(2+1)=18再减去正方形个数8个，得到长方形个数10个*/
//#include <stdio.h>
//
////计算一个数从1加到它累加的和
//int accumulate(int x)
//{
//	int ret = 0;
//	for (int i = x; i > 0; i--)
//	{
//		ret += i;
//	}
//	return ret;
//}
//
//int main()
//{
//	int row = 0, col = 0;  //棋盘的行列
//	int square = 0, rectangle;  //正方形，长方形个数
//
//	scanf("%d%d", &row, &col);  //输入棋盘的行列大小
//
//	//计算正方形个数
//	for (int i = 0; i < (row < col ? row : col); i++)
//	{
//		square += (row - i) * (col - i);
//	}
//
//	rectangle = accumulate(row) * accumulate(col) - square;  //计算出所有矩形的数量，再减去正方形的数量
//
//	printf("%d %d\n", square, rectangle);
//
//	return 0;
//}


//第8题
//找到二维数组中最大的数
//#include <stdio.h>
//
//int main()
//{
//	int arr[100][100] = { 0 };
//	int row = 0, col = 0;
//	int max = 0;
//
//	scanf("%d%d", &row, &col);
//
//	for (int i = 0; i < row; i++)
//	{
//		static int flag = 1;
//		for (int j = 0; j < col; j++)
//		{
//			scanf("%d", &arr[i][j]);  //输入二维数组值
//
//			if (flag)  //将第一次输入的值放进max里，后续不再执行
//			{
//				max = arr[i][j];
//				flag = 0;
//			}
//
//			//判断输入值是否大于max，大于则将值赋值给max
//			if (max < arr[i][j])
//			{
//				max = arr[i][j];
//			}
//		}
//	}
//
//	//输出
//	printf("%d\n", max);
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


//第9题
//矩阵加法
//#include <stdio.h>
//
//int main()
//{
//	int	arr1[100][100] = { 0 };
//	int arr2[100][100] = { 0 };
//	int m = 0, n = 0;
//
//	scanf("%d%d", &m, &n);  //输入矩阵的行和列
//	for (int i = 0; i < m; i++)  //输入矩阵1的值
//		for (int j = 0; j < n; j++)
//			scanf("%d", &arr1[i][j]);
//	for (int i = 0; i < m; i++)  //输入矩阵2的值
//		for (int j = 0; j < n; j++)
//			scanf("%d", &arr2[i][j]);
//
//	for (int i = 0; i < m; i++)  //将两个矩阵求和并输出
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%d ", arr1[i][j] + arr2[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


//第10题
//山峰
//#include <stdio.h>
//
////判断这一土地是否为山峰，是则返回1，不是则返回0
//int isPeak(int arr[][100], int row, int col, int max_row, int max_col)
//{
//	int up = 0, down = 0, left = 0, right = 0;  //是否高于上下左右
//	int thisLand = arr[row][col];
//
//	//当土地位于边缘时，超出边缘的土地不用判断，判断周围地块是否比thisLand低
//	if (row == 0)       { up    = 1; } else if (arr[row - 1][col] < thisLand) { up    = 1; }
//	if (col == 0)       { left  = 1; } else if (arr[row][col - 1] < thisLand) { left  = 1; }
//	if (row == max_row) { down  = 1; } else if (arr[row + 1][col] < thisLand) { down  = 1; }
//	if (col == max_col) { right = 1; } else if (arr[row][col - 1] < thisLand) { right = 1; }
//
//	//当上下左右的值都为真时，返回1，否则返回0
//	if (up && down && left && right)
//		return 1;
//	return 0;
//}
//
//int main()
//{
//	int land[100][100] = { 0 };  //王国的土地
//	int mark[100][100] = { 0 };  //标记对应的土地是否为山峰
//	int n = 0, m = 0;            //土地的行列
//	int count = 0;               //山峰的个数
//	int T = 0;				     //地理变迁次数
//
//	scanf("%d%d", &n, &m);
//
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			scanf("%d", &land[i][j]);  //输入土地的海拔
//
//	scanf("%d", &T);  //输入地理变迁次数
//
//	//进行地质变换
//	for (int i = 0; i < T; i++)
//	{
//		int x1, y1, x2, y2;
//		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
//		int temp             = land[x1 - 1][y1 - 1];
//		land[x1 - 1][y1 - 1] = land[x2 - 1][y2 - 1];
//		land[x2 - 1][y2 - 1] = temp;
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			//如果判断结果为真
//			if (isPeak(land, i, j, n, m) == 1)
//			{
//				count++;  //山峰数+1
//				mark[i][j] = 1;
//			}
//		}
//	}
//
//	//输出
//	printf("%d\n", count);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (mark[i][j] == 1)
//			{
//				printf("%d %d\n", i + 1, j + 1);
//			}
//		}
//	}
//
//	return 0;
//}
