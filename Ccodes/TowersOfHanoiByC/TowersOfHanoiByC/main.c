#include <stdio.h>

int count = 0;  //��¼���˶��ٴ�����

void Hanoi(int x)
{
	if (x == 1)
	{
		count++;  //������Ϊ1��ʱ������ᶯһ��
	}
	else
	{
		//����������Ϊ���ʱ���ɲ�ֳ�����
		// 1���Ƚ�x-1������ᵽ��������
		// 2�ǽ���ʼ���Ͻϴ��һ��ᵽĿ������
		// 3�ǽ��������ϵ�x-1������ᵽĿ������
		Hanoi(x - 1);
		count++;
		Hanoi(x - 1);
	}
}

int main()
{
	Hanoi(3);

	printf("%d\n", count);

	return 0;
}