//#define _CRT_SECURE_NO_WARNINGS  1
//
////C������Ŀ����
////��10��
//
//
////��1��
////��������������������ǵĺ�
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
////��2��
////���������������������ǵ�ֵ
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
////��3��
////����3��double���͵�ֵ���ж�������ֵ�ܷ��ʾһ�������ε�������
//#include <stdio.h>
//
//int main()
//{
//	double a, b, c;
//
//	scanf("%lf%lf%lf", &a, &b, &c);
//
//	//����������֮�ʹ��ڵ�����
//	if (a + b > c && a + c > b && b + c > a)
//	{
//		printf("��\n");
//	}
//	else
//	{
//		printf("��\n");
//	}
//
//	return 0;
//}
//
//
////��4��
////����һ�������ж����Ƿ�Ϊ�������������Ϊ�����������������û������ż��֮�֡�
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
//		printf("����û������ż��֮��\n");
//	}
//	else if (x % 2 == 0)
//	{
//		printf("%d��ż��\n", x);
//	}
//	else
//	{
//		printf("%d������\n", x);
//	}
//
//	return 0;
//}
//
//
////��5��
////ѭ����ӡ1~10��ֵ
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
////��6��
////����10��������������ǵ����ֵ����Сֵ��ƽ��ֵ�����
//#include <stdio.h>
//
//#define INT_MAX  2147483647
//
//int main()
//{
//	int num = 0;
//	int max = -(INT_MAX + 1), min = INT_MAX;  //�洢���ֵ����Сֵ
//	double avg = 0; //�洢ƽ��ֵ
// 
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &num);
//		if (num > max)  //���������������ֵ����num��ֵ��max
//		{
//			max = num;
//		}
//		if (num < min)  //��������С����Сֵ����num��ֵ��min
//		{
//			min = num;
//		}
//		avg += (double)num;  //����10�����ĺ�
//	}
//	avg /= 10;  //��10�����ĺͳ���10
//
//	printf("%d %d %lf\n", max, min, avg);
//}
//
//
////��7��
////����n�Ľ׳�
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
////��8��
////ӡ�ȹ����Ľ���������2��0�η��ӵ�2��63�η�
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	double sum = 0;  //�洢���ֵ
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
////��9��
////����һ���������飬�������ڵ�Ԫ���������в����
//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 0 };
//
//	//������������
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	//������Ԫ�ص���
//	for (int i = 0; i < 10 / 2; i++)
//	{
//		int temp = arr[i];
//		arr[i] = arr[10 - i - 1];
//		arr[10 - i - 1] = temp;
//	}
//
//	//�����������
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}
//
//
////��ʮ��
////��д���򣬽��������ַ���ȥ���ظ��ַ��󣬽������
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str[100] = {"This is a string"};
//	char ch = 0;
//
//	//��������scanf�ĸ߼��÷����˽�
//	scanf("%[^\n]", str);  //����һ���Իس���β���ַ��������Զ�ȡ�ո�
//	scanf("%*c");		   //��ȡ�������������еĻ��з�����ֹ�Ժ�һ���е��������Ӱ��
//	scanf("%c", &ch);	   //������Ҫȥ�����ַ�
//
//	//strlen���������ַ�������
//	for (int i = 0; i < strlen(str); i++)
//	{
//		//�������i��ֵΪ�����ַ�ʱ
//		if (str[i] == ch)
//		{
//			//�Ӵ��ַ�λ�ÿ�ʼ��������ַ���ǰŲ������ǰһλ 
//			for (int j = i; j < strlen(str); j++)
//			{
//				str[j] = str[j + 1]; 
//			}
//		}
//	}
//
//	printf("%s", str);  //�������ַ���
//
//	return 0;
//}