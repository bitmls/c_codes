#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int a = 0, result = 0, temp = 0;
//	int i, j;
//
//	scanf("%d", &a);
//
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			temp += a * pow(10, j);
//		}
//		result += temp;
//		temp = 0;
//	}
//
//	printf("%d\n", result);
//
//	return 0;
//}


//#include <stdio.h>
//
//void print(int* parr, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", *(parr + i));
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//
//	print(arr, n);
//
//	return 0;
//}



//���0��100000֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ�������
//�� : 153 = 1 ^ 3 + 5 ^ 3 + 3 ^ 3����153��һ����ˮ�ɻ�������

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int num = 0, n = 0, i = 0, num_r = 0,num2 = 0;
//
//	for (int num = 0; num <= 100000; num++)
//	{
//		num_r = num;
//		while (num_r)
//		{
//			num_r /= 10;
//			n++;
//		}
//
//		num_r = num;
//		for (i = 0; i < n; i++)
//		{
//			num2 += pow(num_r % 10, n);
//			num_r /= 10;
//		}
//
//		if (num == num2)
//			printf("%d ", num);
//
//		num2 = 0;
//		n = 0;
//	}
//
//	return 0;
//}



////дһ�����������������ַ�������
//#include <stdio.h>
//
//int main()
//{
//	char str[] = "abcdefg";
//	char str2[7];
//	int sz = sizeof(str) / sizeof(str[0]);
//	int i = 0, j = 0;
//
//	for (i = sz - 1; i >= 0; i--)
//	{
//		str2[j] = str[i];
//		j++;
//	}
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%c", str2[i]);
//	}
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//void reverse(char* str)
//{
//	assert(str != NULL);
//
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//
//	while (left < right)
//	{
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char str[] = "123456789";
//	reverse(str);
//	printf("%s\n", str);
//
//	return 0;
//}



//��ѭ���ķ�ʽ��ӡ���µ�һ������
//       *
//      ***
//     *****
//    *******
//   *********
//  ***********
// *************
//***************
// *************
//  ***********
//   *********
//    *******
//     *****
//      ***
//       *

//#include <stdio.h>
//
//int main()
//{
//	int i = 0, j = 0, n = 0;
//
//	scanf("%d", &n);
//
//	//�ϰ벿��
//	for (i = 0; i < n; i++)
//	{
//		//��ӡ�ո�
//		for (j = 1; j < (n - i); j++)
//		{
//			printf("%c", ' ');
//		}
//		//��ӡ*
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("%c", '*');
//		}
//		printf("\n");
//	}
//	//�°벿��
//	for (i = n - 1; i > 0; i--)
//	{
//		//��ӡ�ո�
//		for (j = i; j <= n - 1; j++)
//		{
//			printf("%c", ' ');
//		}
//		//��ӡ*
//		for (j = 0; j < 2 * i - 1; j++)
//		{
//			printf("%c", '*');
//		}
//		printf("\n");
//	}
//
//	return 0;
//}



//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ���ƿ��ˮ(���ʵ��)

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
//	while (empty_bottle >= 2)  //����ƿ���ܹ����жһ�
//	{
//		num += empty_bottle / 2;  //ÿ������ƿ�ܺ�һ����ˮ
//		empty_bottle = empty_bottle / 2 + empty_bottle % 2;  //��ʣ��Ŀ�ƿ��ͳ�ƣ�������������ƿ©�µ�һ����ƿ
//	}
//
//	printf("%d\n", num);
//
//	return 0;
//}



//��Ŀ����:
//��������ż��˳����Ŀ����:
//��������ʹ����ȫ����λ��ż��ǰ�档
//��Ŀ :
//����һ���������飬ʵ��һ����������
//����������ά�����ֵ�����ʹ�����������е�����λ����ά��ǰ�벿�֣�����ż��λ����ϸ�ĺ�벿�֡�

#include <stdio.h>

//int main()
//{
//	int arr[100] = { 0 }, arr1[100] = { 0 }, arr2[100] = { 0 };
//	int i = 0, n = 0, a1 = 0, a2 = 0;
//
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//		if (arr[i] % 2)
//		{
//			arr1[a1] = arr[i];
//			a1++;
//		}
//		else
//		{
//			arr2[a2] = arr[i];
//			a2++;
//		}
//	}
//
//	for (i = 0; i < a1; i++)
//	{
//		arr[i] = arr1[i];
//	}
//	for (i = 0; i < a2; i++)
//	{
//		arr[a1 + i] = arr2[i];
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


//void print(int* parr, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", *(parr + i));
//	}
//	printf("\n");
//}
//
//void move(int* parr, int n)
//{
//	int* left = parr;
//	int* right = parr + n - 1;
//
//	while (left < right)
//	{
//		while(*left % 2 == 1)
//		{
//			left++;
//		}
//		while (*right % 2 == 0)
//		{
//			right--;
//		}
//		if(left < right)
//		{
//			int temp = *left;
//			*left = *right;
//			*right = temp;
//		}
//	}
//}
//
//int main()
//{
//	int arr[100] = { 0 };
//	int i = 0, n = 0;
//
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	move(arr, n);
//	print(arr, n);
//
//	return 0;
//}



//��ӡһ���������
//#include <stdio.h>
//
//int main()
//{
//	int arr[10][10] = { 0 };
//	int i = 0, j = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0)
//				arr[i][j] = 1;
//			if (j == i)
//				arr[i][j] = 1;
//			if (i >= 2 && j >= 1)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}



//#include <stdio.h>

//int main()
//{
//	char killer = '\0';
//	int res = 0;
//
//	while(1)
//	{
//		scanf("%c", &killer);
//
//		if (killer != 'a')
//			res++;
//		if (killer == 'c')
//			res++;
//		if (killer == 'd')
//			res++;
//		if (killer != 'd')
//			res++;
//
//		if (res == 3)
//		{
//			printf("killer is %c\n", killer);
//			break;
//		}
//		else
//		{
//			printf("�²����\n");
//			res = 0;
//			killer = '\0';
//		}
//	}
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	char killer = 0;
//
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			printf("killer is %c\n", killer);
//		}
//	}
//
//	return 0;
//}




//#include <stdio.h>
//
//int main()
//{
//	int a, b, c, d, e;
//
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b == 2) + (a == 3) == 1)
//							&& ((b == 2) + (e == 4) == 1)
//							&& ((c == 1) + (b == 2) == 1)
//							&& ((c == 5) + (d == 3) == 1)
//							&& ((e == 4) + (a == 1) == 1)
//							)
//						{
//							if (a * b * c * d * e == 120)
//							{
//								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//
//	return 0;
//}



//#include <stdio.h>
//
//void test(int** ppa)
//{
//	**ppa = 20;
//}
//
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int** ppa = &pa;
//
//	test(ppa);
//
//	printf("%d\n", a);
//
//	return 0;
//}


//#include <stdio.h>
//
//int test(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//
//	int arr[10] = { 0 };
//	int(*parr)[10] = &arr;
//
//	int(*pf)(int, int) = &test;
//	
//	int res = (*pf)(5, 6);
//	printf("%d\n", res);
//
//	return 0;
//}



//#include <stdio.h>
//
//typedef void(*pfun_t)(int);
//
//int main()
//{
//	void (*signal(int, void(*)(int)))(int);
//	pfun_t signal(int, pfun_t);
//
//	return 0;
//}


//#include <stdio.h>
//
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int Sub(int a, int b)
//{
//	return a - b;
//}
//
//int Mul(int a, int b)
//{
//	return a * b;
//}
//
//int Div(int a, int b)
//{
//	return a / b;
//}
//
//void menu(void)
//{
//	printf("***********************\n");
//	printf("**** 1.Add   2.Sub ****\n");
//	printf("**** 3.Mul   4.Div ****\n");
//	printf("****     0.exit    ****\n");
//	printf("***********************\n");
//}
//
//int main()
//{
//	int input = 0;
//	int (*pfun[5])(int, int) = { NULL, Add, Sub, Mul, Div };
//
//	do
//	{
//		int a = 0, b = 0, res = 0;
//
//		menu();
//
//		printf("���������ѡ��");
//		scanf("%d", &input);
//
//		if(input >= 1 && input <= 4)
//		{
//			printf("��������������");
//			scanf("%d %d", &a, &b);
//			res = pfun[input](a, b);
//		}
//
//		if (input >= 1 && input <= 4)
//			printf("���Ϊ%d\n", res);
//		else if (!input)
//			printf("---�˳�---\n");
//		else
//			printf("�����������������\n");
//
//	} while (input);
//
//	return 0;
//}


//#include <stdio.h>
//
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int Sub(int a, int b)
//{
//	return a - b;
//}
//
//int Mul(int a, int b)
//{
//	return a * b;
//}
//
//int Div(int a, int b)
//{
//	return a / b;
//}
//
//void menu(void)
//{
//	printf("***********************\n");
//	printf("**** 1.Add   2.Sub ****\n");
//	printf("**** 3.Mul   4.Div ****\n");
//	printf("****     0.exit    ****\n");
//	printf("***********************\n");
//}
//
//int Calc(int(*pfun)(int, int))
//{
//	int  a = 0, b = 0;
//	printf("��������������");
//	scanf("%d %d", &a, &b);
//	return pfun(a, b);
//}
//
//int main()
//{
//	int input = 0;
//
//	do
//	{
//		int res = 0;
//
//		menu();
//
//		printf("���������ѡ��");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			res = Calc(Add);
//			printf("%d\n", res);
//			break;
//		case 2:
//			res = Calc(Sub);
//			printf("%d\n", res);
//			break;
//		case 3:
//			res = Calc(Mul);
//			printf("%d\n", res);
//			break;
//		case 4:
//			res = Calc(Div);
//			printf("%d\n", res);
//			break;
//		case 0:
//			printf("---�˳�---\n");
//			break;
//		default:
//			printf("�����������������\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}


//#include <stdio.h>
//
//int bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	print_arr(arr, sz);
//	bubble_sort(arr, sz);
//	print_arr(arr, sz);
//
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//void print_arr(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//void test1(void)
//{
//	//�������͵ıȽ�
//	int arr[10] = { 9, 7, 8, 6, 5, 4, 3, 2, 1, 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	print_arr(arr, sz);
//
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//
//	print_arr(arr, sz);
//}
//
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int cmp_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//
//int cmp_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//
//void print_Stu_age(struct Stu s[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", (s + i)->age);
//	}
//}
//
//void print_Stu_name(struct Stu s[], int sz)
//{
//	int i = 0; 
//	for (i = 0; i < sz; i++)
//	{
//		printf("%s ", (s + i)->name);
//	}
//}
//
//void test2(void)
//{
//	//�ṹ�����͵ıȽ�
//	struct Stu s[3] = { {"zhangsan", 20}, {"lisi", 19}, {"wangwu", 18} };
//	int sz = sizeof(s) / sizeof(s[0]);
//
//	//qsort(s, sz, sizeof(s[0]), cmp_by_age);
//	//print_Stu_age(s, sz);
//
//	qsort(s, sz, sizeof(s[0]), cmp_by_name);
//	print_Stu_name(s, sz);
//}
//
//int main()
//{
//	//test1();
//	test2();
//
//	return 0;
//}



//#include <stdio.h>
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//void Swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char temp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = temp;
//		buf1++;
//		buf2++;
//	}
//}
//
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//int cmp_by_name(const void* e1, const void* e2)
//{
//	return strcmp((*(struct Stu*)e1).name, (*(struct Stu*)e2).name);
//}
//
//void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			//��һֵ������һֵ������
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//void print_int(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//}
//
//void print_name(struct Stu* s, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%s ", *(s + i)->name);
//	}
//}
//
//int main()
//{
//	int arr[10] = { 2, 4, 6, 8, 0, 1, 3, 5, 7, 9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	struct Stu s[3] = { {"zhangsan", 20}, {"lisi", 19}, {"wangwu", 18} };
//	int sz1 = sizeof(s) / sizeof(s[0]);
//
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	print_int(&arr, sz);
//
//	bubble_sort(s, sz1, sizeof(s[0]), cmp_by_name);
//	print_name(s, sz1);
//
//	return 0;
//}



//#include <stdio.h>
//
//int main()
//{
//	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//	char arr[] = "abcdef";
//
//	printf("%d\n", strlen(arr));
//	printf("%d\n", strlen(arr + 0));
//	printf("%d\n", strlen(*arr));
//	printf("%d\n", strlen(arr[1]));
//	printf("%d\n", strlen(&arr));
//	printf("%d\n", strlen(&arr + 1));
//	printf("%d\n", strlen(&arr[0] + 1));
//
//	return 0;
//}



//#include <stdio.h>
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&arr + 1);
//	int* ptr2 = (int*)((int)arr + 1);
//
//	printf("%#x %#x\n", ptr1, ptr2);
//
//	return 0;
//}


#include <stdio.h>

//int main()
//{
//	int a[3][4] = { 0 };
//	int b = 2;
//
//	//printf("%d\n", sizeof(a));
//	//printf("%d\n", sizeof(&a));
//	//printf("%d\n", sizeof(a[0]));
//	//printf("%d\n", sizeof(a[0][0]));
//	//printf("%d\n", sizeof(a[0] + 1));
//	//printf("%d\n", sizeof(a + 1));
//	//printf("%d\n", sizeof(*a));
//
//	char ch;
//	printf("%c", ch = '7' + '9');
//
//	return 0;
//}


//#include <stdio.h>
//
//int numMax(int x)
//{
//	int max = 0;
//	for (int i = 1; i <= x; i++)
//	{
//		int temp = i;
//		while (temp != 1)
//		{
//			//ż��
//			if (temp % 2 == 0)
//			{
//				temp /= 2;
//			}
//			//����
//			else
//			{
//				temp = temp * 3 + 1;
//			}
//			if (temp > max)
//				max = temp;
//		}
//	}
//	return max;
//}
//
//int main()
//{
//	int N = 0;
//
//	scanf("%d", &N);
//
//	printf("%d\n", numMax(N));
//
//	return 0;
//}



//#include <stdio.h>
//
//int my_pow(int a, int n);
//
//int main()
//{
//	int a, n;
//
//	scanf("%d %d", &a, &n);
//
//	printf("%d\n", my_pow(a, n));
//
//	return 0;
//}
////��Ĵ��뽫������·�



//#include <stdio.h>
//
////int calc(int a, char symbol, int b);
//
//int main()
//{
//	int a, b;
//	char symbol;
//
//	scanf("%d%c%d", &a, &symbol, &b);
//
//	printf("%d %c %d = \n", a, symbol, b /*calc(a, symbol, b)*/);
//
//	return 0;
//}

//2.ʵ��һ��ӵ�м򵥼��������ܵĺ������ܽ��мӼ��˳����㡣
//��������ӿڣ�
//int calc(int a, char symbol, int b);
//
//���в��Գ���������
//#include <stdio.h>
//
//int calc(int a, char symbol, int b);
//
//int main()
//{
//	int a, b;
//	char symbol;
//
//	scanf("%d%c%d", &a, &symbol, &b);
//
//	printf("%d %c %d = %d\n", a, symbol, b, calc(a, symbol, b));
//
//	return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//
//
//
//��������1��3 + 4
//�������1��3 + 4 = 7
//��������2��5 / 3
//�������2��5 / 3 = 1

//#include <stdio.h>
//
//int count(int n);
//
//int main()
//{
//	int num;
//
//	scanf("%d", &num);
//
//	printf("%d\n", count(num));
//
//	return 0;
//}




//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 0 }, sz;
//	sz = sizeof(arr) / sizeof(arr[0]);
//
//	for (int i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	//���������
//	for (int i = 0; i < sz - 1; i++)
//	{
//		//һ�����򽻻��Ĵ���
//		for (int j = 0; j < sz - i - 1; j++)
//		{
//			int temp;
//			if (arr[j] > arr[j + 1])
//			{
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


//#include <stdio.h>
//
//int num = 0;
//
//void f(int flower, int store, int sum) //flower��¼�������Ĵ�����store��¼������Ĵ�����
//// sumΪ��ǰ�Ƶ����� 
//{
//	if (flower > 9 || store > 5)   // �жϵݹ�ĳ��ڶ��ڵݹ���˵ʮ�ֹؼ� 
//		return;
//	if (flower == 9 && store == 5)  //���������һ�ο϶�Ϊ��������ڵ����ڶ���ʱ�����Ϊ
//									//����9�λ���5�ε꣬����ʣ����һ����sum=1
//	{
//		if (sum == 1)
//		{
//			num++;
//			return;
//		}
//		else
//			return;
//	}
//	f(flower + 1, store, sum - 1);   //������һ������sum-1 
//	f(flower, store + 1, sum * 2);   //�����һ������sum*2 
//}
//
//int main()
//{
//	f(0, 0, 2);  //���εݹ�ĳ�ʼ���� 
//
//	printf("%d", num);
//	return 0;
//}






//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int num = 0, n = 0, i = 0, num_r = 0, num2 = 0;
//	int a, b;
//
//	scanf("%d %d", &a, &b);
//
//	for (int num = a; num <= b; num++)
//	{
//		//��������ж���λ
//		num_r = num;
//		while (num_r)
//		{
//			num_r /= 10;
//			n++;
//		}
//
//		//����ÿһλ����n�˷���ĺ�
//		num_r = num;
//		for (i = 0; i < n; i++)
//		{
//			num2 += pow(num_r % 10, n);
//			num_r /= 10;
//		}
//
//		//��������ԭ������ȣ���Ϊˮ�ɻ���
//		if (num == num2)
//			printf("%d ", num);
//
//		num2 = 0;
//		n = 0;
//	}
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	char* a[] = { "abc", "hello", "alibaba" };
//	char** pa = &a;
//
//	pa++;
//
//	printf("%s\n", *pa);
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	char* c[] = {"ENTER", "NEW", "POINT", "FIRST"};
//	char** cp[] = { c + 3, c + 2, c + 1, c };
//	char*** cpp = cp;
//
//	printf("%s\n", **++cpp);
//	printf("%s\n", *-- * ++cpp + 3);
//	printf("%s\n", *cpp[-2] + 3);
//	printf("%s\n", cpp[-1][-1] + 1);
//
//	return 0;
//}



//#include <stdio.h>
//
//int find_num(int arr[3][3], int* px, int* py, int k)
//{
//	int x = 0, y = *py - 1;
//
//	while (x < *px - 1 && y > 0)
//	{
//		if (arr[x][y] < k)
//		{
//			x++;
//		}
//		else if (arr[x][y] > k)
//		{
//			y--;
//		}
//		else
//		{
//			*px = x;
//			*py = y;
//			return 1;
//		}
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int k = 2;
//	int x = 3, y = 3;
//
//	int ret = find_num(arr, &x, &y, k);
//
//	if (ret == 1)
//	{
//		printf("found it\n");
//		printf("�±�Ϊ%d %d\n", x, y);
//	}
//	else
//	{
//		printf("not found it\n");
//	}
//
//	return 0;
//}



////�ַ�����
//
//#include <stdio.h>
//#include <string.h>
//
//void string_rotation(char* pstr, int k)
//{
//	char ch;
//	for (int i = 0; i < k; i++)
//	{
//		ch = *pstr;  //ȡ���ַ��������Ԫ���ַ�
//		int j = 0;
//		int len = strlen(pstr);
//		//����һλ�õ�ֵ�ŵ�ǰһλ��ȥ
//		for (j = 0; j < len - 1; j++)
//		{
//			*(pstr + j) = *(pstr + j + 1);
//		}
//		//����һλ��Ԫ�ط������һλȥ
//		*(pstr + len - 1) = ch;
//	}
//}
//
//int main()
//{
//	char str[] = "ABCDEF";
//	int k = 0;
//
//	scanf("%d", &k);
//
//	string_rotation(&str, k);
//	
//	printf("%s\n", str);
//
//	return 0;
//}


//#include <stdio.h>
//#include <assert.h>
//
//void reverse(char* left, char* right)
//{
//	while (left < right)
//	{
//		char temp;
//		temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//}
//
//void string_rotation(char* pstr, int k)
//{
//	assert(pstr);  //���ԣ���ֹpstrΪ��ָ��
//
//	int len = strlen(pstr);
//	reverse(pstr, pstr + k - 1); //���
//	reverse(pstr + k, pstr + len - 1);
//	reverse(pstr, pstr + len - 1);
//}
//
//int main()
//{
//	char str[] = "ABCDEF";
//	int k = 5;
//
//	//scanf("%d", &k);
//
//	string_rotation(str, k);
//
//	printf("%s\n", str);
//
//	return 0;
//}



//#include <string.h>
//#include <stdio.h>
//
//int main()
//{
//	char arr[20] = "hello";
//
//	strncat(arr, arr, 5);
//
//	printf("%s\n", arr);
//
//	return 0;
//}



////�ж�һ���ַ����Ƿ�������һ���ַ�����ת�õ���
//#include <stdio.h>
//#include <string.h>
//
//int is_string_rotation(char* arr, char* arr1)
//{
//	if (strlen(arr1) != strlen(arr))
//		return 0;
//
//	strncat(arr, arr, 5);
//
//	//�ж�arr1���Ƿ�Ϊarr���Ӵ�������ǣ������ظ����ݵĵ�ַ��������ǣ����ؿ�ָ��
//	char* ret = strstr(arr, arr1);
//
//	return ret != NULL;
//}
//
//int main()
//{
//	char arr[20] = "AABCD";
//	char arr1[6] = "CDAAB";
//	int ret = 0;
//
//	ret = is_string_rotation(arr, arr1);
//
//	if (ret == 1)
//	{
//		printf("�������ĵõ���\n");
//	}
//	else
//	{
//		printf("���������õ���\n");
//	}
//
//	return 0;
//}



//#include <stdio.h>
//
//int main()
//{
//	int aa[2][5] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//
//	printf("%d %d\n", *(ptr1 - 1), *(ptr2 - 1));
//
//	return 0;
//}

//#include <stdio.h>
//
//void print_arr(int (*arr)[5], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		int j = 0;
//		for (j = 0; j < col; j++)
//		{
//			printf("%d", *(*(arr + i) + j));
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//
//	print_arr(arr, 3, 5);
//
//	return 0;
//}



//qsort����ʵ��