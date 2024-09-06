#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("------------------------------\n");
	printf("|****************************|\n");
	printf("|****  (1)输入1开始游戏  ****|\n");
	printf("|****  (2)输入2双人游戏  ****|\n");
	printf("|****  (0)输入0退出游戏  ****|\n");
	printf("|****************************|\n");
	printf("------------------------------\n");
}

void menu1()
{
	printf("------------------------------\n");
	printf("|****************************|\n");
	printf("|****  (1)输入1简单模式  ****|\n");
	printf("|****  (2)输入2困难模式  ****|\n");
	printf("|****************************|\n");
	printf("------------------------------\n");
}

void game1()
{
	//生成随机数
	srand((unsigned int)time(NULL));
	//存储棋盘数据 - 二维数组
	char board[ROW][COL];
	//棋盘初始化
	Board_Init(board, ROW, COL);
	//打印棋盘
	Board_Print(board, ROW, COL);

	char ret;
	while (1)
	{
		//玩家回合
		Player_Round(board, ROW, COL);
		Board_Print(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("玩家获胜!!!\n");
			}
			else if(ret == '#')
			{
				printf("电脑获胜!!!\n");
			}
			else
			{
				printf("平局~~~\n");
			}
			break;
		}

		//电脑回合
		Computer_Round(board, ROW, COL);
		Board_Print(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("玩家获胜!!!\n");
			}
			else if (ret == '#')
			{
				printf("电脑获胜!!!\n");
			}
			else
			{
				printf("平局~~~\n");
			}
			break;
		}
	}
}

void game2()
{
	//存储棋盘数据 - 二维数组
	char board[ROW][COL];
	//棋盘初始化
	Board_Init(board, ROW, COL);
	//打印棋盘
	Board_Print(board, ROW, COL);

	char ret;
	while (1)
	{
		//玩家1回合
		Player1_Round(board, ROW, COL);
		Board_Print(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("玩家1获胜!!!\n");
			}
			else if (ret == '#')
			{
				printf("玩家2获胜!!!\n");
			}
			else
			{
				printf("平局~~~\n");
			}
			break;
		}
		//玩家2回合
		Player2_Round(board, ROW, COL);
		Board_Print(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("玩家1获胜!!!\n");
			}
			else if (ret == '#')
			{
				printf("玩家2获胜!!!\n");
			}
			else
			{
				printf("平局~~~\n");
			}
			break;
		}
	}
}

void game3()
{
	//生成随机数
	srand((unsigned int)time(NULL));
	//存储棋盘数据 - 二维数组
	char board[ROW][COL];
	//棋盘初始化
	Board_Init(board, ROW, COL);
	//打印棋盘
	Board_Print(board, ROW, COL);

	char ret;
	while (1)
	{
		//玩家回合
		Player_Round(board, ROW, COL);
		Board_Print(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("玩家获胜!!!\n");
			}
			else if (ret == '#')
			{
				printf("电脑获胜!!!\n");
			}
			else
			{
				printf("平局~~~\n");
			}
			break;
		}

		//电脑回合
		Computer_Round_Hard(board, ROW, COL);
		Board_Print(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("玩家获胜!!!\n");
			}
			else if (ret == '#')
			{
				printf("电脑获胜!!!\n");
			}
			else
			{
				printf("平局~~~\n");
			}
			break;
		}
	}
}

int main()
{
	int input = 0;

	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			menu1();
			printf("请选择：");
			scanf("%d", &input);
			switch (input)
			{
			//简单模式
			case 1:
				printf("三子棋游戏开始\n");
				game1();
				break;
			//困难模式
			case 2:
				printf("三子棋游戏开始\n");
				game3();
				break;
			default:
				printf("输入错误，请重新输入\n");
				break;
			}
			break;
		case 2:
			printf("三子棋双人模式开始\n");
			game2();
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误,请重新输入!!!\n");
			break;
		}
	} while (input);

	return 0;
}