#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <stdbool.h>

//问题描述：
//给出4个1 - 10的数字，通过加减乘除，得到数字为24就算胜利
//输入：4个1 - 10的数字。[数字允许重复，但每个数字仅允许使用一次，测试用例保证无异常数字]
//输出： true or false


//四则运算符号
char Operator[4] = { '+', '-', '*', '/' };

//计算两个数的加减乘除
double fun(double a, double b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		printf("输入值不为操作符\n");
		break;
	}
	return 0;
}

//将每种情况写出
//((a#b)#c)#d
//(a#(b#c))#d
//a#(b#(c#d))
//(a#b)#(c#d)
//a#((b#c)#d)
//五种情况

//情况1  ((a#b)#c)#d
double expression1(double a, double b, double c, double d, char op1, char op2, char op3)
{
	double ret = 0;
	ret = fun(a, b, op1);
	ret = fun(ret, c, op2);
	ret = fun(ret, d, op3);
	return ret;
}

//情况2  (a#(b#c))#d
double expression2(double a, double b, double c, double d, char op1, char op2, char op3)
{
	double ret = 0;
	ret = fun(b, c, op2);
	ret = fun(a, ret, op1);
	ret = fun(ret, c, op3);
	return ret;
}

//情况3  a#(b#(c#d))
double expression3(double a, double b, double c, double d, char op1, char op2, char op3)
{
	double ret = 0;
	ret = fun(c, d, op3);
	ret = fun(b, ret, op2);
	ret = fun(a, ret, op1);
	return ret;
}

//情况4  (a#b)#(c#d)
double expression4(double a, double b, double c, double d, char op1, char op2, char op3)
{
	double ret1 = 0;
	double ret2 = 0;
	ret1 = fun(a, b, op1);
	ret2 = fun(c, d, op3);
	ret1 = fun(ret1, ret2, op2);
	return ret1;
}

//情况5  a#((b#c)#d)
double expression5(double a, double b, double c, double d, char op1, char op2, char op3)
{
	double ret = 0;
	ret = fun(b, c, op2);
	ret = fun(ret, d, op3);
	ret = fun(a, ret, op1);
	return ret;
}

int main()
{
	int count = 0;
	int arr[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				//情况1
				int ret = (int)(0.00001 + expression1(arr[0], arr[1], arr[2], arr[3], Operator[i], Operator[j], Operator[k]));
				if (ret == 24)
				{
					count++;
					printf("((%d %c %d) %c %d) %c %d = 24\n", arr[0], Operator[i], arr[1], Operator[j], arr[2], Operator[k], arr[3]);
				}
				//情况2
				ret = (int)(0.00001 + expression2(arr[0], arr[1], arr[2], arr[3], Operator[i], Operator[j], Operator[k]));
				if (ret == 24)
				{
					count++;
					printf("(%d %c (%d %c %d)) %c %d = 24\n", arr[0], Operator[i], arr[1], Operator[j], arr[2], Operator[k], arr[3]);
				}
				//情况3
				ret = (int)(0.00001 + expression3(arr[0], arr[1], arr[2], arr[3], Operator[i], Operator[j], Operator[k]));
				if (ret == 24)
				{
					count++;
					printf("%d %c (%d %c (%d %c %d)) = 24\n", arr[0], Operator[i], arr[1], Operator[j], arr[2], Operator[k], arr[3]);
				}
				//情况4
				ret = (int)(0.00001 + expression4(arr[0], arr[1], arr[2], arr[3], Operator[i], Operator[j], Operator[k]));
				if (ret == 24)
				{
					count++;
					printf("(%d %c %d) %c (%d %c %d) = 24\n", arr[0], Operator[i], arr[1], Operator[j], arr[2], Operator[k], arr[3]);
				}
				//情况5
				ret = (int)(0.00001 + expression5(arr[0], arr[1], arr[2], arr[3], Operator[i], Operator[j], Operator[k]));
				if (ret == 24)
				{
					count++;
					printf("%d %c ((%d %c %d) %c %d) = 24\n", arr[0], Operator[i], arr[1], Operator[j], arr[2], Operator[k], arr[3]);
				}
			}
		}
	}

	printf("得到次数为%d\n", count);

	return 0;
}