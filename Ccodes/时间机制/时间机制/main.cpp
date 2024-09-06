//项目日志
// 
//无具体目标，随便写写


//---------------------------------头文件---------------------------------//
#include <stdio.h>
#include <graphics.h>
//---------------------------------头文件---------------------------------//

//---------------------------------宏定义---------------------------------//
#define WIN_WIDTH   1000
#define WIN_HEIGHT  600
//---------------------------------宏定义---------------------------------//


//检测用户点击
void userClick(void)
{
	ExMessage msg;
	if (peekmessage(&msg))
	{
		if (msg.message == WM_LBUTTONDOWN)
		{
			printf("%d %d\n", msg.x, msg.y);
		}
	}
}


int main()
{
	initgraph(WIN_WIDTH, WIN_HEIGHT, 1);

	while (1)
	{
		userClick();
	}

	return 0;
}