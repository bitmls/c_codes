//��Ŀ��־
// 
//�޾���Ŀ�꣬���дд


//---------------------------------ͷ�ļ�---------------------------------//
#include <stdio.h>
#include <graphics.h>
//---------------------------------ͷ�ļ�---------------------------------//

//---------------------------------�궨��---------------------------------//
#define WIN_WIDTH   1000
#define WIN_HEIGHT  600
//---------------------------------�궨��---------------------------------//


//����û����
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