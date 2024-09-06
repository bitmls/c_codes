#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("****************************\n");
	printf("***** （1）按1开始游戏 *****\n");
	printf("***** （1）按2退出游戏 *****\n");
	printf("****************************\n");
}

void game()
{
	char board[ROWS][COLS] = { 0 };  //第一个数组存储炸弹
	char show[ROWS][COLS] = { 0 };  //第二个数组显示数字
	//数组初始化
	Board_Init(board, ROWS, COLS, '0');
	Board_Init(show, ROWS, COLS, '*');
	//打印数组
	Display_Board(board, ROW, COL);
	Display_Board(show, ROW, COL);

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
			printf("游戏开始\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);

	return 0;
}