#include <stdio.h>

//�����鰴��������
void Bubble_Sort(int arr[], int sz)  //���飬���鳤��
{
	//����
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		//ÿ�˽��бȽϵĴ���
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])  //���ǰһ�����Ⱥ���С������λ��
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	Bubble_Sort(arr, sz);

	return 0;
}