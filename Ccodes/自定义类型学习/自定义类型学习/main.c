#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>


//struct stu
//{
//	char name[20];
//	int age;
//	int id[20];
//}stu1, stu2;
//
////匿名结构体类型
//struct
//{
//	char a;
//	int b;
//	double c;
//}s;
//
//int main()
//{
//	struct stu stu3, stu4;
//
//	return 0;
//}


//struct s
//{
//	char c;
//	int i;
//	int b;
//};
//
//struct j
//{
//	char c;
//	double d;
//	struct s s;
//	float f;
//};
//
//int main()
//{
//	struct j a = { 'a', 3.14, {'a', 1, 3}, 3.1 };
//
//	printf("%d\n", sizeof(struct j));
//
//	return 0;
//}



////将默认对齐数改为2
//#pragma pack(1)
//struct S
//{
//	char ch1;
//	int i;
//	char ch2;
//};
//#pragma pack()
//
//int main()
//{
//	struct S s;
//	int i;
//
//	printf("%d\n", i = sizeof(s));
//
//	return 0;
//}


////用宏计算偏移量
//
//#include <stddef.h>
//
//struct S
//{
//	char ch1;
//	int i;
//	char ch2;
//};
//
//int main()
//{
//	printf("%d\n", offsetof(struct S, ch1));
//	printf("%d\n", offsetof(struct S, i));
//	printf("%d\n", offsetof(struct S, ch2));
//
//	return 0;
//}


////位段
//
//struct S
//{
//	int a : 1;
//	int b : 2;
//	unsigned int c : 10;
//	signed int d : 32;
//};
//




//enum Color
//{
//	RED,
//	GREEN,
//	BLUE
//};
//
//
//int main()
//{
//	enum Color c = BLUE;
//
//	printf("%d\n", RED);
//	printf("%d\n", GREEN);
//	printf("%d\n", BLUE);
//	printf("%d\n", c);
//
//	return 0;
//}



////联合体或共用体
//int check_sys(void)
//{
//	union Un
//	{
//		char ch;
//		int i;
//	}u;
//	u.i = 1;
//	return u.ch;
//	//返回1  小端
//	//返回0  大端
//}
//
//int main()
//{
//	int ret = check_sys();
//
//	if (ret)
//		printf("小端\n");
//	else
//		printf("大端\n");
//
//	return 0;
//}

//
//#include <stdlib.h>
//
//int main()
//{
//	//在栈区上开辟空间
//	int arr[10] = { 0 };
//
//	//动态内存开辟
//	int* p = (int*)malloc(10 * sizeof(int));
//
//	//使用前判断是否开辟成功
//	if (p == NULL)
//	{
//		perror("main");  //main: xxxxxxx
//		return 0;
//	}
//
//	//使用
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//
//	//归还空间
//	free(p);
//	p = NULL;
//
//	return 0;
//}


//#include <stdlib.h>
//
//int main()
//{
//	//int* p = (int*)malloc(10 * sizeof(int));
//	int* p = (int*)calloc(10, sizeof(int));
//
//	if (p == NULL)
//	{
//		perror("main");
//		return 1;
//	}
//
//	int i = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		*(p + i) = 5;
//	}
//
//	//增加空间
//	int* ptr = realloc(p, 10 * sizeof(int));
//	if (ptr != NULL)  //判断空间是否开辟成功
//	{
//		p = ptr;
//	}
//
//	free(p);
//	p = NULL;
//
//	return 0;
//}


//#define FLAG  1
//
//int main()
//{
//#if FLAG
//	printf("hello\n");
//#endif
//
//	return 0;
//}


//#define FLAG  3
//
//int main()
//{
//#if FLAG == 1
//	printf("hello\n");
//#elif FLAG == 2
//	printf("hehe\n");
//#else
//	printf("world\n");
//#endif
//
//	return 0;
//
//}


//#define FLAG  3
//
//int main()
//{
//#ifdef FLAG
//	printf("hello\n");
//#endif
//
//#if defined FLAG
//	printf("hi\n");
//#endif
//
//#ifndef HELLO
//	printf("byebye\n");
//#endif
//
//#if !defined HELLO
//	printf("goodbye\n");
//#endif
//
//	return 0;
//}


////库文件包含，包含头文件用<>
//#include <stdio.h>
//
////本地文件包含，包含自定义文件用""
//#include "add.h"
//
//int main()
//{
//	
//
//	return 0;
//}



//#include <stdio.h>
//
//void mat_add(int arr1[][3], int arr2[][3], int sum[][3])
//{
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			sum[i][j] = arr1[i][j] + arr2[i][j];
//		}
//	}
//}
//
//void mat_print(int arr[][3])
//{
//	for (int i = 0; i < 4; i++)
//	{
//		printf("第%d位同学 ", i + 1);
//		for (int j = 0; j < 3; j++)
//		{
//			printf("%3d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	//四名学生，三科课程，两次考试
//	int tensu1[4][3] = { {91, 63, 78}, {67, 72, 46}, {89, 34, 53}, {32, 54, 34} };
//	int tensu2[4][3] = { {97, 67, 82}, {73, 43, 46}, {97, 56, 21}, {85, 46, 35} };
//	int sum[4][3] = { 0 };
//
//	mat_add(tensu1, tensu2, sum);  //求两次考试成绩总和
//
//	printf("第一次考试的分数：\n");
//	mat_print(tensu1);
//
//	printf("第二次考试的分数：\n");
//	mat_print(tensu2);
//
//	printf("两次考试总分\n");
//	mat_print(sum);
//
//	return 0;
//}


//#include <stdio.h>
//
//#pragma pack(4)
//struct A
//{
//	int a;
//	short b;
//	int c;
//	char d;
//};
//
//struct B
//{
//	int a;
//	short b;
//	char c;
//	int d;
//};
//#pragma pack()
//
//int main()
//{
//	struct A sa = { 0 };
//	struct B sb = { 0 };
//
//	printf("%d\n", sizeof(sa));
//	printf("%d\n", sizeof(sb));
//
//	return 0;
//}



//int decide1(int num)
//{
//	do {
//		if (num <= 1) {
//			printf("\a请输入大于1的自然数:");
//			scanf("%d", &num);
//		}
//	} while (num <= 1);
//	return num;
//}
//
//void decide2(const int n)
//{
//	int i;
//
//	if (n == 2)
//		printf("%d是质数.\n", n);
//	else
//	{
//		for (i = 2; i < n; i++) {
//			if (n % i == 0)
//			{
//				printf("%d不是质数.\n", n);
//				break;
//			}
//
//			if (n % i != 0 && i == n - 1)
//				printf("%d是质数.\n", n);
//		}
//	}
//}
//
//int	main(void)
//{
//	int n;
//
//	printf("请输入一个大于1的自然数:");
//	scanf("%d", &n);
//
//	n = decide1(n);
//	decide2(n);
//
//	return	0;
//}



//#include <stdio.h>
//#include <math.h>
//
////判断传入的数是否为质数，如果是返回1，不是返回0
//int isPrime(int n)
//{
//	if (n > 0 && n <= 2)
//		return 1;
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//			return 0;
//	}
//	return 1;
//}
//
//
//int main()
//{
//	int n = 0;
//
//	do
//	{
//		printf("请输入一个整数：");
//		scanf("%d", &n);
//
//		if (n <= 0)
//			printf("输入为负数，请重新输入\n");
//	} while (n <= 0);
//
//
//	int ret = isPrime(n);
//
//	if (ret == 1)
//		printf("%d是质数\n", n);
//	else
//		printf("%d不是质数\n", n);
//
//	return 0;
//}


//int count_bits(unsigned x)
//{
//	int bits = 0;
//	while (x)
//	{
//		if (x & 1U)
//			bits++;
//		x >>= 1;
//	}
//	return bits;
//}
//
//int int_bits(void)
//{
//	return count_bits(0U);
//}
//
//void print_bits(unsigned x)
//{
//	int i;
//	for (i = int_bits() - 1; i >= 0; i--)
//		putchar(((x >> i) & 1U) ? '1' : '0');
//}
//
//int main()
//{
//	unsigned a, b;
//	printf("请输入两个非负整数：\n");
//	printf("a:");  scanf("%d", &a);
//	printf("b:");  scanf("%d", &b);
//
//	printf("\na     = ");  print_bits(a);
//	printf("\nb     = ");  print_bits(b);
//	printf("\na & b = ");  print_bits(a & b);
//	printf("\na ! b = ");  print_bits(a | b);
//	printf("\na ^ b = ");  print_bits(a ^ b);
//	printf("\n~a    = ");  print_bits(~a);
//	printf("\n~b    = ");  print_bits(~b);
//
//	return 0;
//}



//unsigned	set(unsigned x, int pos)
//{
//	unsigned	i = x >> pos - 1;
//
//	if (i & 1u == 1)
//		return	x;
//
//	if (i & 1u == 0) {
//		unsigned	j = i | 1u;
//		unsigned	k = j << pos - 1;
//		return	k | x;
//	}
//}


#include <stdio.h>
#include <math.h>

unsigned int set(unsigned x, int pos)
{
	unsigned ret = x;
	x %= (unsigned)pow(2, pos);
	if (x >= pow(2, pos - 1))
	{
		return ret;
	}
	else
	{
		return ret + pow(2, pos - 1);
	}
}

int		main(void)
{
	unsigned	x;
	int		pos;

	printf("请输入一个整数:");
	scanf("%u", &x);

	printf("位数:");
	scanf("%d", &pos);

	printf("无符号整数%u的第%d位设为1后的值:%u\n", x, pos, set(x, pos));

	return	0;
}
