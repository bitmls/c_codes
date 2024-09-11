#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <stdbool.h>

//����������
//����4��1 - 10�����֣�ͨ���Ӽ��˳����õ�����Ϊ24����ʤ��
//���룺4��1 - 10�����֡�[���������ظ�����ÿ�����ֽ�����ʹ��һ�Σ�����������֤���쳣����]
//����� true or false


//�����������
char Operator[4] = { '+', '-', '*', '/' };

//�����������ļӼ��˳�
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
		printf("����ֵ��Ϊ������\n");
		break;
	}
	return 0;
}

//��ÿ�����д��
//((a#b)#c)#d
//(a#(b#c))#d
//a#(b#(c#d))
//(a#b)#(c#d)
//a#((b#c)#d)
//�������

//���1  ((a#b)#c)#d
double expression1(double a, double b, double c, double d, char op1, char op2, char op3)
{
	double ret = 0;
	ret = fun(a, b, op1);
	ret = fun(ret, c, op2);
	ret = fun(ret, d, op3);
	return ret;
}

//���2  (a#(b#c))#d
double expression2(double a, double b, double c, double d, char op1, char op2, char op3)
{
	double ret = 0;
	ret = fun(b, c, op2);
	ret = fun(a, ret, op1);
	ret = fun(ret, c, op3);
	return ret;
}

//���3  a#(b#(c#d))
double expression3(double a, double b, double c, double d, char op1, char op2, char op3)
{
	double ret = 0;
	ret = fun(c, d, op3);
	ret = fun(b, ret, op2);
	ret = fun(a, ret, op1);
	return ret;
}

//���4  (a#b)#(c#d)
double expression4(double a, double b, double c, double d, char op1, char op2, char op3)
{
	double ret1 = 0;
	double ret2 = 0;
	ret1 = fun(a, b, op1);
	ret2 = fun(c, d, op3);
	ret1 = fun(ret1, ret2, op2);
	return ret1;
}

//���5  a#((b#c)#d)
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
				//���1
				int ret = (int)(0.00001 + expression1(arr[0], arr[1], arr[2], arr[3], Operator[i], Operator[j], Operator[k]));
				if (ret == 24)
				{
					count++;
					printf("((%d %c %d) %c %d) %c %d = 24\n", arr[0], Operator[i], arr[1], Operator[j], arr[2], Operator[k], arr[3]);
				}
				//���2
				ret = (int)(0.00001 + expression2(arr[0], arr[1], arr[2], arr[3], Operator[i], Operator[j], Operator[k]));
				if (ret == 24)
				{
					count++;
					printf("(%d %c (%d %c %d)) %c %d = 24\n", arr[0], Operator[i], arr[1], Operator[j], arr[2], Operator[k], arr[3]);
				}
				//���3
				ret = (int)(0.00001 + expression3(arr[0], arr[1], arr[2], arr[3], Operator[i], Operator[j], Operator[k]));
				if (ret == 24)
				{
					count++;
					printf("%d %c (%d %c (%d %c %d)) = 24\n", arr[0], Operator[i], arr[1], Operator[j], arr[2], Operator[k], arr[3]);
				}
				//���4
				ret = (int)(0.00001 + expression4(arr[0], arr[1], arr[2], arr[3], Operator[i], Operator[j], Operator[k]));
				if (ret == 24)
				{
					count++;
					printf("(%d %c %d) %c (%d %c %d) = 24\n", arr[0], Operator[i], arr[1], Operator[j], arr[2], Operator[k], arr[3]);
				}
				//���5
				ret = (int)(0.00001 + expression5(arr[0], arr[1], arr[2], arr[3], Operator[i], Operator[j], Operator[k]));
				if (ret == 24)
				{
					count++;
					printf("%d %c ((%d %c %d) %c %d) = 24\n", arr[0], Operator[i], arr[1], Operator[j], arr[2], Operator[k], arr[3]);
				}
			}
		}
	}

	printf("�õ�����Ϊ%d\n", count);

	return 0;
}