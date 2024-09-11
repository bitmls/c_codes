/*
	项目日志
	6月18日
	开始尝试写第一个场景
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>

#define SNAKE_NUM  10000

struct Snake
{
	int size;				 //蛇的长度
	int dir;				 //蛇的方向
	int speed;				 //蛇的速度
	POINT coor[SNAKE_NUM];	 //蛇的坐标
}snake;

struct Food
{
	int x;
	int y;
	int r;		  //食物半径
	bool flag;    //食物是否被吃掉
	DWORD color;  //食物颜色
}food;

enum DIR  //蛇的方向
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

void GameInit(void)
{
	//初始化graph窗口
	initgraph(1000, 600/*, SHOWCONSOLE*/);  //SHOWCONSOLE显示控制台
	//随机数种子
	srand(GetTickCount());  //GetTickCount()获取系统开机到现在的毫秒数
	//蛇的初始化，一开始有三节
	snake.size = 3;
	snake.dir = DOWN;
	snake.speed = 5;
	for(int i = snake.size - 1; i >= 0; i--)
	{
		snake.coor[i].x = 40 - 10 * i;
		snake.coor[i].y = 10;
	}
	//初始化rand()让其随机产生一个整数，如果没有设置随机数种子，每次产生的都是固定的数
	//设置种子需要头文件stdlib.h 一般是把时间作为随机数种子，因为时间是在不断变化的
	food.x = rand() % 1001;
	food.y = rand() % 601;
	food.color = RGB(255, 0, 0);
	food.r = 10;
	food.flag = true;
}

void GameDraw(void)
{
	//双缓冲绘图
	BeginBatchDraw();
	//设置背景颜色板
	setbkcolor(RGB(253, 255, 148));
	cleardevice();
	//绘制蛇
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

//移动蛇
void snakeMove(void)
{
	//让身体跟着头移动
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

//按键控制蛇的移动方向
void keyControl(void)
{
	//检测是否有按键按下，有则返回真
	if (_kbhit())
	{
		//72 80 75 77  上下左右的四个键值
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

//判断蛇是否吃到了果子
void eatFood(void)
{
	if (food.flag == true 
		&& abs(snake.coor[0].x - food.x) <= food.r + 5
		&& abs(snake.coor[0].y - food.y) <= food.r + 5)
	{
		food.flag = false;
		snake.size += 5;
	}
	//如果食物被吃，重新生成一个食物
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