#include <stdio.h>

//д�����жϵ�ǰ�������ֽ��򣨴�˴洢����С�˴洢��
//a   00 00 00 01  (��˴洢��  ��λ�ֽ�����ڸߵ�ַλ
//    01 00 00 00 ��С�˴洢��  ��λ�ֽ�����ڵ͵�ַλ
//int main()
//{
//	int a = 1;
//	char* pa = (char*)&a;//ֱ��ȡ����int*���ͣ���Ҫǿ��ת��
//	if (*pa == 1)
//	{
//		printf("�û���ΪС�˴洢\n");
//	}
//	else
//	{
//		printf("�û���Ϊ��˴洢\n");
//	}
//
//	return 0;
//}

/**
  * @brief   
  * @param   
  * @retval  
  */
int check_sys()
{
	int a = 1;
	char* pa = (char*)&a;//ֱ��ȡ����int*���ͣ���Ҫǿ��ת��
	//if (*pa == 1)
	//{
	//	return 1;
	//}
	//else
	//{
	//	return 0;
	//}
	return *pa;
}

int main()
{
	int Check = check_sys();
	if (Check == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}

	return 0;
}