#include <stdio.h>

//写程序判断当前机器的字节序（大端存储或者小端存储）
//a   00 00 00 01  (大端存储）  低位字节序存在高地址位
//    01 00 00 00 （小端存储）  高位字节序存在低地址位
//int main()
//{
//	int a = 1;
//	char* pa = (char*)&a;//直接取出是int*类型，需要强制转换
//	if (*pa == 1)
//	{
//		printf("该机器为小端存储\n");
//	}
//	else
//	{
//		printf("该机器为大端存储\n");
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
	char* pa = (char*)&a;//直接取出是int*类型，需要强制转换
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
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}

	return 0;
}