//#define _CRT_SECURE_NO_WARNINGS  1
//
////��1��
////����һ��������������һ����Ӧ������������
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		//��ӡ�ո񲿷�
//		for (int j = i + 1; j < n; j++)
//		{
//			printf(" ");
//		}
//		//��ӡ�ǺŲ���
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
////��2��
////��д���򣬼������� 1 + 1/2 + 1/3 + ... ��ǰN��֮�ͣ����ʱ����3λС����
//#include <stdio.h>
//
//int main()
//{
//	double ret = 0;  //�洢��������ֵ
//	int n = 0;
// 
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++)
//	{
//		ret += 1.0 / (double)i;  //retÿ�μ���1/n
//	}
//
//	printf("%.3lf", ret);
//
//	return 0;
//}
//
//
////��3��
////����һ����ݣ��ж��������ǲ�������
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
//		printf("%d��������\n", year);
//	}
//	else
//	{
//		printf("%d�겻������\n", year);
//	}
//
//	return 0;
//}
//
//
////��4��
////���100~200֮�������
//#include <stdio.h>
//#include <math.h>
//
//int isPrime(int x)
//{
//	for (int i = 2; i <= sqrt(x); i++)
//	{
//		//�ж�x�Ƿ��ܱ�����������ܱ���������Ϊ����������0
//		if (x % i == 0)
//		{
//			return 0;
//		}
//	}
//	//������ܱ��������򷵻������
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
////��5��
////���ٹ�·���ٴ���
//#include <stdio.h>
//
//int main()
//{
//	int v, max_v;  //���ٺ�����
//	double proportion;  //���ٱ���
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
////��6��
////���
//#include <stdio.h>
//
////���㲢����1+2+...+n��ֵ
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
//	int k = 0;     //���Ž�ҵ�����
//	int wage = 1;  //��ʿ����Ĺ���
//	int sum = 0;   //��ʿ�õ����ܽ����
//
//	scanf("%d", &k);
//
//	for (int i = 1; i <= k; i++)
//	{
//		sum += wage;  //��ʿÿ���õ���Ĺ���
//		if (i == accumulate(wage))  //��ǰ�����ﵽ��������������ʱ
//		{
//			wage++;  //�ù���+1
//		}
//	}
//
//	printf("%d\n", sum);
//
//	return 0;
//}
//
//
////��7��
////�����ڴ�
//#include <stdio.h>
//#include <math.h>
//
////�ж�һ�����Ƿ�Ϊ��������Ϊ�����򷵻������������Ϊ�򷵻�0
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
//	int max_vol = 0;       //��ʾ�ڴ����������
//	int sum = 0;           //�洢��ǰ�������ܺ�
//	int arr[100] = { 0 };  //�����洢����
//	int count = 0;         //��¼��ǰ�洢�����ĸ���
//
//	scanf("%d", &max_vol);
//
//	while (1)
//	{
//		static int i = 2;
//		
//		sum += isPrime(i);
//
//		//��������Ϊ�������ҿڴ�������ܺ�С���������
//		if (isPrime(i) != 0 && sum <= max_vol)
//		{
//			arr[count] = i;  //��������浽������
//			count++;         //������+1
//		}
//		//���ܺʹ������ֵʱ
//		if (sum > max_vol)
//		{
//			break;
//		}
//
//		i++;
//	}
//	
//	//����ڴ������
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
////��9��
////�����������ͬ������֮��
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
//		//�ҵ��������е����ֵ
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		//�������е�Ԫ�ز�Ϊ���ֵ
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
////��10��
////����ȥ��
//#include <stdio.h>
//
//int main()
//{
//	int n = 0;  //����Ԫ�صĸ���
//	int arr[100] = { 0 };
//
//	//�������ĸ���
//	scanf("%d", &n);
//
//	//ѭ�������������ֵ
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	//����һ������
//	for (int i = 0; i < n; i++)
//	{
//		//��j��ֵΪ��ǰi����һλ�ã��ӵ�ǰλ�ÿ�ʼ������Ƿ�����ͬ��Ԫ��
//		for (int j = i + 1; j < n; j++)
//		{
//			//ѭ��֪��û���ҵ���ͬԪ�غ�
//			while(arr[j] == arr[i])
//			{
//				//�����Ԫ�غ����Ԫ�ض���ǰŲһλ
//				for (int k = j; k < n; k++)
//				{
//					arr[k] = arr[k + 1];
//				}
//				n--;  //��������1
//			}
//		}
//	}
//
//	//ѭ����ӡ����
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}