#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("------------------------------\n");
	printf("|****************************|\n");
	printf("|****  (1)����1��ʼ��Ϸ  ****|\n");
	printf("|****  (2)����2˫����Ϸ  ****|\n");
	printf("|****  (0)����0�˳���Ϸ  ****|\n");
	printf("|****************************|\n");
	printf("------------------------------\n");
}

void menu1()
{
	printf("------------------------------\n");
	printf("|****************************|\n");
	printf("|****  (1)����1��ģʽ  ****|\n");
	printf("|****  (2)����2����ģʽ  ****|\n");
	printf("|****************************|\n");
	printf("------------------------------\n");
}

void game1()
{
	//���������
	srand((unsigned int)time(NULL));
	//�洢�������� - ��ά����
	char board[ROW][COL];
	//���̳�ʼ��
	Board_Init(board, ROW, COL);
	//��ӡ����
	Board_Print(board, ROW, COL);

	char ret;
	while (1)
	{
		//��һغ�
		Player_Round(board, ROW, COL);
		Board_Print(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("��һ�ʤ!!!\n");
			}
			else if(ret == '#')
			{
				printf("���Ի�ʤ!!!\n");
			}
			else
			{
				printf("ƽ��~~~\n");
			}
			break;
		}

		//���Իغ�
		Computer_Round(board, ROW, COL);
		Board_Print(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("��һ�ʤ!!!\n");
			}
			else if (ret == '#')
			{
				printf("���Ի�ʤ!!!\n");
			}
			else
			{
				printf("ƽ��~~~\n");
			}
			break;
		}
	}
}

void game2()
{
	//�洢�������� - ��ά����
	char board[ROW][COL];
	//���̳�ʼ��
	Board_Init(board, ROW, COL);
	//��ӡ����
	Board_Print(board, ROW, COL);

	char ret;
	while (1)
	{
		//���1�غ�
		Player1_Round(board, ROW, COL);
		Board_Print(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("���1��ʤ!!!\n");
			}
			else if (ret == '#')
			{
				printf("���2��ʤ!!!\n");
			}
			else
			{
				printf("ƽ��~~~\n");
			}
			break;
		}
		//���2�غ�
		Player2_Round(board, ROW, COL);
		Board_Print(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("���1��ʤ!!!\n");
			}
			else if (ret == '#')
			{
				printf("���2��ʤ!!!\n");
			}
			else
			{
				printf("ƽ��~~~\n");
			}
			break;
		}
	}
}

void game3()
{
	//���������
	srand((unsigned int)time(NULL));
	//�洢�������� - ��ά����
	char board[ROW][COL];
	//���̳�ʼ��
	Board_Init(board, ROW, COL);
	//��ӡ����
	Board_Print(board, ROW, COL);

	char ret;
	while (1)
	{
		//��һغ�
		Player_Round(board, ROW, COL);
		Board_Print(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("��һ�ʤ!!!\n");
			}
			else if (ret == '#')
			{
				printf("���Ի�ʤ!!!\n");
			}
			else
			{
				printf("ƽ��~~~\n");
			}
			break;
		}

		//���Իغ�
		Computer_Round_Hard(board, ROW, COL);
		Board_Print(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			if (ret == '*')
			{
				printf("��һ�ʤ!!!\n");
			}
			else if (ret == '#')
			{
				printf("���Ի�ʤ!!!\n");
			}
			else
			{
				printf("ƽ��~~~\n");
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
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			menu1();
			printf("��ѡ��");
			scanf("%d", &input);
			switch (input)
			{
			//��ģʽ
			case 1:
				printf("��������Ϸ��ʼ\n");
				game1();
				break;
			//����ģʽ
			case 2:
				printf("��������Ϸ��ʼ\n");
				game3();
				break;
			default:
				printf("�����������������\n");
				break;
			}
			break;
		case 2:
			printf("������˫��ģʽ��ʼ\n");
			game2();
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������,����������!!!\n");
			break;
		}
	} while (input);

	return 0;
}