
//ѧϰʱ�����ͺ�����ʹ��

#include <stdio.h>
#include <graphics.h>
#include <time.h>
//#include <mmsystem.h>
//#pragma comment(lib, "winmm.lib")

//��ȡ��ǰ���ú���ʱ��ʱ������ϴε��øú�����ʱ��
int getDelay(void)
{
	static long long int lastTime = 0;
	long long int currentTime = GetTickCount();
	if (lastTime == 0)
	{
		lastTime = currentTime;
		return 0;
	}
	else
	{
		int ret = currentTime - lastTime;
		lastTime = currentTime;
		return ret;
	}
}
//
//int main()
//{
//	int time = 0;
//
//	while (1)
//	{
//		if (time > 1)
//		{
//			printf("Hello! ");
//			time = 0;
//		}
//		else
//		{
//			time += getDelay();
//		}
//	}
//
//	return 0;
//}


////ͨ��ʱ�������������
//int main()
//{
//	int Time = 0;
//	srand(time(NULL));
//
//	while (1)
//	{
//		if (Time > 500)
//		{
//			printf("%d ", rand());
//			Time = 0;
//		}
//		else
//		{
//			Time += getDelay();
//		}
//	}
//
//	return 0;
//}