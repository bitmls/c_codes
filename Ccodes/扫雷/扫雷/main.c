#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("****************************\n");
	printf("***** ��1����1��ʼ��Ϸ *****\n");
	printf("***** ��1����2�˳���Ϸ *****\n");
	printf("****************************\n");
}

void game()
{
	char board[ROWS][COLS] = { 0 };  //��һ������洢ը��
	char show[ROWS][COLS] = { 0 };  //�ڶ���������ʾ����
	//�����ʼ��
	Board_Init(board, ROWS, COLS, '0');
	Board_Init(show, ROWS, COLS, '*');
	//��ӡ����
	Display_Board(board, ROW, COL);
	Display_Board(show, ROW, COL);

}

int main()
{
	int input = 0;

	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);

	return 0;
}