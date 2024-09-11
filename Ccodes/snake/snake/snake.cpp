/*
	��Ŀ��־
	6��18��
	��ʼ����д��һ������
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>

#define SNAKE_NUM  10000

struct Snake
{
	int size;				 //�ߵĳ���
	int dir;				 //�ߵķ���
	int speed;				 //�ߵ��ٶ�
	POINT coor[SNAKE_NUM];	 //�ߵ�����
}snake;

struct Food
{
	int x;
	int y;
	int r;		  //ʳ��뾶
	bool flag;    //ʳ���Ƿ񱻳Ե�
	DWORD color;  //ʳ����ɫ
}food;

enum DIR  //�ߵķ���
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

void GameInit(void)
{
	//��ʼ��graph����
	initgraph(1000, 600/*, SHOWCONSOLE*/);  //SHOWCONSOLE��ʾ����̨
	//���������
	srand(GetTickCount());  //GetTickCount()��ȡϵͳ���������ڵĺ�����
	//�ߵĳ�ʼ����һ��ʼ������
	snake.size = 3;
	snake.dir = DOWN;
	snake.speed = 5;
	for(int i = snake.size - 1; i >= 0; i--)
	{
		snake.coor[i].x = 40 - 10 * i;
		snake.coor[i].y = 10;
	}
	//��ʼ��rand()�����������һ�����������û��������������ӣ�ÿ�β����Ķ��ǹ̶�����
	//����������Ҫͷ�ļ�stdlib.h һ���ǰ�ʱ����Ϊ��������ӣ���Ϊʱ�����ڲ��ϱ仯��
	food.x = rand() % 1001;
	food.y = rand() % 601;
	food.color = RGB(255, 0, 0);
	food.r = 10;
	food.flag = true;
}

void GameDraw(void)
{
	//˫�����ͼ
	BeginBatchDraw();
	//���ñ�����ɫ��
	setbkcolor(RGB(253, 255, 148));
	cleardevice();
	//������
	setfillcolor(RGB(115, 194, 118));
	solidcircle(snake.coor[0].x, snake.coor[0].y, 7);
	setfillcolor(RGB(24, 255, 30));
	for(int i = 1; i < snake.size; i++)
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	setfillcolor(food.color);
	if (food.flag)
		solidcircle(food.x, food.y, food.r);
	EndBatchDraw();
}

//�ƶ���
void snakeMove(void)
{
	//���������ͷ�ƶ�
	for (int i = snake.size - 1; i > 0; i--)
	{
		snake.coor[i] = snake.coor[i - 1];
	}
	switch (snake.dir)
	{
	case UP:
		snake.coor[0].y -= snake.speed;
		if (snake.coor[0].y <= 0)
			snake.coor[0].y = 600;
		break;
	case DOWN:
		if (snake.coor[0].y >= 600)
			snake.coor[0].y = 0;
		snake.coor[0].y += snake.speed;
		break;
	case LEFT:
		if (snake.coor[0].x <= 0)
			snake.coor[0].x = 1000;
		snake.coor[0].x -= snake.speed;
		break;
	case RIGHT:
		if (snake.coor[0].x >= 1000)
			snake.coor[0].x = 0;
		snake.coor[0].x += snake.speed;
		break;
	}
}

//���������ߵ��ƶ�����
void keyControl(void)
{
	//����Ƿ��а������£����򷵻���
	if (_kbhit())
	{
		//72 80 75 77  �������ҵ��ĸ���ֵ
		switch (_getch())
		{
		case 'w':
		case 'W':
		case 72:
			if(snake.dir != DOWN)
				snake.dir = UP;
			break;
		case 's':
		case 'S':
		case 80:
			if (snake.dir != UP)
				snake.dir = DOWN;
			break;
		case 'a':
		case 'A':
		case 75:
			if (snake.dir != RIGHT)
				snake.dir = LEFT;
			break;
		case 'd':
		case 'D':
		case 77:
			if (snake.dir != LEFT)
				snake.dir = RIGHT;
			break;
		case ' ':
			while (_getch() == ' ')
				return;
		}
	}
}

//�ж����Ƿ�Ե��˹���
void eatFood(void)
{
	if (food.flag == true 
		&& abs(snake.coor[0].x - food.x) <= food.r + 5
		&& abs(snake.coor[0].y - food.y) <= food.r + 5)
	{
		food.flag = false;
		snake.size += 5;
	}
	//���ʳ�ﱻ�ԣ���������һ��ʳ��
	if (!food.flag)
	{
		food.x = rand() % 1001;
		food.y = rand() % 601;
		food.color = RGB(255, 0, 0);
		food.r = 10;
		food.flag = true;
	}
}

int main()
{
	GameInit();

	while (1)
	{
		GameDraw();
		snakeMove();
		keyControl();
		eatFood();
		Sleep(1);
	}

	return 0;
}