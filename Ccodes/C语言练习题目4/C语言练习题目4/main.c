#define _CRT_SECURE_NO_WARNINGS  1

//��1��
//�������
//#include <stdio.h>
//
//int main()
//{
//	int arr[1000] = { 0 };
//	int n = 0;  //���鳤��
//	int k = 0;  //��Ҫ�ı������ĵڼ�����
//	int sum = 0;  //�洢�������ĺ�
//
//	scanf("%d%d", &n, &k);
//
//	//�����������
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	arr[k - 1] = -arr[k - 1];  //����ӦԪ�ر�Ϊ����
//
//	//�����е�ֵ������
//	for (int i = 0; i < n; i++)
//	{
//		sum += arr[i];
//	}
//
//	printf("%d", sum);
//
//	return 0;
//}


//��2��
//���Ŷ�
//#include <stdio.h>
//
//int main()
//{
//	int arr1[100] = { 0 };  //�洢����ѧ��
//	int arr2[100] = { 0 };  //�洢ż��ѧ��
//	int n = 0;              //�ܹ�n��С����
//	int count1 = 0, count2 = 0;
//
//	scanf("%d", &n);
//
//	while(count1 + count2 < n)
//	{
//		int num = 0;
//		scanf("%d", &num);
//		if (num % 2 != 0)  //ż��
//		{
//			arr1[count1] = num;
//			count1++;
//		}
//		else  //����
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


//��3��
//�ж��ַ����Ƿ�Ϊ����
#include <stdio.h>
#include <string.h>

int main()
{
	char str[100] = { 0 };
	int result = 1;
	int len = 0;

	scanf("%s", str);

	len = strlen(str);  //�����ַ����ĳ���

	for (int i = 0; i <= len / 2; i++)
	{
		//�ж϶�Ӧλ���ַ��Ƿ����
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


//��4��
//�ƽ̨
//#include <stdio.h>
//
//int main()
//{
//	int arr[100] = { 0 };
//	int n = 0;  //����Ԫ�ظ���
//	int count = 1;
//	int max = 1;  //�ƽ̨��
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
//			count++;  //��¼��ǰƽ̨��
//			//�����ǰƽ̨�������ƽ̨������count��ֵ��max
//			if (count > max)
//			{
//				max = count;
//			}
//		}
//		//������Ԫ�ز����ʱ
//		else
//		{
//			count = 1;  //��ƽ̨��������1
//		}
//	}
//
//	printf("%d\n", max);
//
//	return 0;
//}


//��5��
//��ϸ������
/*˼·�����������벢���򣬽�����������ĵ�һλ�����һλ��������㣬
���ƽ��ֵ�����������*/
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	double arr[300] = { 0 };
//	int n = 0;             //����Ԫ�ظ���
//	double avg = 0;        //ƽ��ֵ
//	double max_error = 0;  //������
//
//	scanf("%d", &n);  //������������
//
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%lf", &arr[i]);  //����ÿ��������ֵ
//	}
//
//	//��ð�����򷨸���������
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
//	//��Ͳ������ƽ��ֵ
//	for (int i = 1; i < n - 1; i++)
//	{
//		avg += arr[i];
//	}
//	avg /= n - 2;
//
//	//�����������
//	for (int i = 1; i < n - 1; i++)
//	{
//		int error = abs(arr[i] - avg);
//		if (max_error < error)
//		{
//			max_error = error;
//		}
//	}
//
//	//������λС�����
//	printf("%.2lf %.2lf\n", avg, max_error);
//
//	return 0;
//}


//��6��
//���ص�
/*�����������1Ϊ�ƵĴ�״̬��0Ϊ�ƵĹر�״̬*/
//#include <stdio.h>
//
//int main()
//{
//	int arr[5000] = { 0 };
//	int N = 0;
//
//	scanf("%d", &N);  //����Ƶ�����
//
//	for (int i = 0; i < N; i++)
//	{
//		arr[i] = 1;  //��ʼʱ���еƶ�Ϊ����״̬
//	}
//
//	for (int i = 1; i <= N; i++)  //�ӵ�һ���˵����һ����
//	{
//		for (int j = 1; j <= N; j++)  //�����еƽ��д���
//		{
//			if (j % i == 0)  //���Ƶı���ǵ�i���˵ı���ʱ
//			{
//				arr[j - 1] = !arr[j - 1];
//			}
//		}
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		if (arr[i] == 0)  //����رյĵƵı��
//		{
//			printf("%d ", i + 1);
//		}
//	}
//
//	return 0;
//}


//��7��
//��������
/*�ҹ��ɣ�2*3��С�����̣�1*1����������(2-0)*(3-0)=6����2*2����������(2-1)*(3-1)=2��
1*2�ĳ�������(2-0)*(3-1)=4����1*3�ĳ�������(2-0)*(3-2)=2����2*1�ĳ�������(2-1)*(3-0)=3����2*3�ĳ�������(2-1)*(3-2)=1����
���߼�������г����κ������εĺ�(3+2+1)*(2+1)=18�ټ�ȥ�����θ���8�����õ������θ���10��*/
//#include <stdio.h>
//
////����һ������1�ӵ����ۼӵĺ�
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
//	int row = 0, col = 0;  //���̵�����
//	int square = 0, rectangle;  //�����Σ������θ���
//
//	scanf("%d%d", &row, &col);  //�������̵����д�С
//
//	//���������θ���
//	for (int i = 0; i < (row < col ? row : col); i++)
//	{
//		square += (row - i) * (col - i);
//	}
//
//	rectangle = accumulate(row) * accumulate(col) - square;  //��������о��ε��������ټ�ȥ�����ε�����
//
//	printf("%d %d\n", square, rectangle);
//
//	return 0;
//}


//��8��
//�ҵ���ά������������
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
//			scanf("%d", &arr[i][j]);  //�����ά����ֵ
//
//			if (flag)  //����һ�������ֵ�Ž�max���������ִ��
//			{
//				max = arr[i][j];
//				flag = 0;
//			}
//
//			//�ж�����ֵ�Ƿ����max��������ֵ��ֵ��max
//			if (max < arr[i][j])
//			{
//				max = arr[i][j];
//			}
//		}
//	}
//
//	//���
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


//��9��
//����ӷ�
//#include <stdio.h>
//
//int main()
//{
//	int	arr1[100][100] = { 0 };
//	int arr2[100][100] = { 0 };
//	int m = 0, n = 0;
//
//	scanf("%d%d", &m, &n);  //���������к���
//	for (int i = 0; i < m; i++)  //�������1��ֵ
//		for (int j = 0; j < n; j++)
//			scanf("%d", &arr1[i][j]);
//	for (int i = 0; i < m; i++)  //�������2��ֵ
//		for (int j = 0; j < n; j++)
//			scanf("%d", &arr2[i][j]);
//
//	for (int i = 0; i < m; i++)  //������������Ͳ����
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


//��10��
//ɽ��
//#include <stdio.h>
//
////�ж���һ�����Ƿ�Ϊɽ�壬���򷵻�1�������򷵻�0
//int isPeak(int arr[][100], int row, int col, int max_row, int max_col)
//{
//	int up = 0, down = 0, left = 0, right = 0;  //�Ƿ������������
//	int thisLand = arr[row][col];
//
//	//������λ�ڱ�Եʱ��������Ե�����ز����жϣ��ж���Χ�ؿ��Ƿ��thisLand��
//	if (row == 0)       { up    = 1; } else if (arr[row - 1][col] < thisLand) { up    = 1; }
//	if (col == 0)       { left  = 1; } else if (arr[row][col - 1] < thisLand) { left  = 1; }
//	if (row == max_row) { down  = 1; } else if (arr[row + 1][col] < thisLand) { down  = 1; }
//	if (col == max_col) { right = 1; } else if (arr[row][col - 1] < thisLand) { right = 1; }
//
//	//���������ҵ�ֵ��Ϊ��ʱ������1�����򷵻�0
//	if (up && down && left && right)
//		return 1;
//	return 0;
//}
//
//int main()
//{
//	int land[100][100] = { 0 };  //����������
//	int mark[100][100] = { 0 };  //��Ƕ�Ӧ�������Ƿ�Ϊɽ��
//	int n = 0, m = 0;            //���ص�����
//	int count = 0;               //ɽ��ĸ���
//	int T = 0;				     //�����Ǩ����
//
//	scanf("%d%d", &n, &m);
//
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			scanf("%d", &land[i][j]);  //�������صĺ���
//
//	scanf("%d", &T);  //��������Ǩ����
//
//	//���е��ʱ任
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
//			//����жϽ��Ϊ��
//			if (isPeak(land, i, j, n, m) == 1)
//			{
//				count++;  //ɽ����+1
//				mark[i][j] = 1;
//			}
//		}
//	}
//
//	//���
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
