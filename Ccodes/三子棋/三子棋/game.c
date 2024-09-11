#include "game.h"

//���̳�ʼ�� - ������Ԫ�ر�Ϊ�ո�
Board_Init(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//��ӡ����
Board_Print(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row + 1; i++)
	{
		for (j = 0; j < col + 1; j++)
		{
			printf("+");
			if(j < col)
				printf("---");
		}
		printf("\n");

		if (i < row)
		{
			for (j = 0; j < col + 1; j++)
			{
				printf("|");
				if(j < col)
					printf(" %c ", board[i][j]);
			}
			printf("\n");
		}
	}
}

//��һغ�
void Player_Round(char board[ROW][COL], int row, int col)
{
	int x = 0;  //��������
	int y = 0;  //��������
	while (1)
	{
		printf("��һغ�>>>\n");
		printf("���������ӵ�������");
		scanf("%d", &x);
		printf("\n���������ӵ�������");
		scanf("%d", &y);
	
		//�ж������Ƿ���Ч
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("����λ�ñ�ռ�ã�����������\n");
			}
		}
		else
		{
			printf("����λ����Ч������������\n");
		}
	}
}

void Computer_Round(char board[ROW][COL], int row, int col)
{
	printf("���Իغ�>>>\n");
	while (1)
	{
		//����0~2�������
		int x = rand() % row;
		int y = rand() % col;
		//�ж��Ƿ�Ϊ�ո�
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

void Computer_Round_Hard(char board[ROW][COL], int row, int col)
{
	printf("���Իغ�>>>\n");
	while (1)
	{
		int i = 0;

		//�жϵ���ÿ���Ƿ��3
		if (board[0][0] == board[0][1] && board[0][0] == '#') { if (board[0][2] == ' ') { board[0][2] = '#'; break; } }
		if (board[0][0] == board[0][2] && board[0][0] == '#') { if (board[0][1] == ' ') { board[0][1] = '#'; break; } }
		if (board[0][1] == board[0][2] && board[0][1] == '#') { if (board[0][0] == ' ') { board[0][0] = '#'; break; } }
	
		if (board[1][0] == board[1][1] && board[1][0] == '#') { if (board[1][2] == ' ') { board[1][2] = '#'; break; } }
		if (board[1][0] == board[1][2] && board[1][0] == '#') { if (board[1][1] == ' ') { board[1][1] = '#'; break; } }
		if (board[1][1] == board[1][2] && board[1][1] == '#') { if (board[1][0] == ' ') { board[1][0] = '#'; break; } }

		if (board[2][0] == board[2][1] && board[2][0] == '#') { if (board[2][2] == ' ') { board[2][2] = '#'; break; } }
		if (board[2][0] == board[2][2] && board[2][0] == '#') { if (board[2][1] == ' ') { board[2][1] = '#'; break; } }
		if (board[2][1] == board[2][2] && board[2][1] == '#') { if (board[2][0] == ' ') { board[2][0] = '#'; break; } }
		//�жϵ���ÿ���Ƿ��3
		if (board[0][0] == board[1][0] && board[0][0] == '#') { if (board[2][0] == ' ') { board[2][0] = '#'; break; } }
		if (board[0][0] == board[2][0] && board[0][0] == '#') { if (board[1][0] == ' ') { board[1][0] = '#'; break; } }
		if (board[1][0] == board[2][0] && board[1][0] == '#') { if (board[0][0] == ' ') { board[0][0] = '#'; break; } }

		if (board[0][1] == board[1][1] && board[0][1] == '#') { if (board[2][1] == ' ') { board[2][1] = '#'; break; } }
		if (board[0][1] == board[2][1] && board[0][1] == '#') { if (board[1][1] == ' ') { board[1][1] = '#'; break; } }
		if (board[1][1] == board[2][1] && board[1][1] == '#') { if (board[0][1] == ' ') { board[0][1] = '#'; break; } }

		if (board[0][1] == board[1][2] && board[0][2] == '#') { if (board[2][2] == ' ') { board[2][2] = '#'; break; } }
		if (board[0][1] == board[2][2] && board[0][2] == '#') { if (board[1][2] == ' ') { board[1][2] = '#'; break; } }
		if (board[1][1] == board[2][2] && board[1][2] == '#') { if (board[0][2] == ' ') { board[0][2] = '#'; break; } }
		//�жϵ��ԶԽ����Ƿ��3
		if (board[0][0] == board[1][1] && board[0][0] == '#') { if (board[2][2] == ' ') { board[2][2] = '#'; break; } }
		if (board[0][0] == board[2][2] && board[0][0] == '#') { if (board[1][1] == ' ') { board[1][1] = '#'; break; } }
		if (board[1][1] == board[2][2] && board[1][1] == '#') { if (board[0][0] == ' ') { board[0][0] = '#'; break; } }

		if (board[0][2] == board[1][1] && board[1][1] == '#') { if (board[2][0] == ' ') { board[2][0] = '#'; break; } }
		if (board[0][2] == board[2][0] && board[0][2] == '#') { if (board[1][1] == ' ') { board[1][1] = '#'; break; } }
		if (board[1][1] == board[2][0] && board[1][1] == '#') { if (board[0][2] == ' ') { board[0][2] = '#'; break; } }

		//�ж����ĵ�
		if (board[1][1] == ' ')
		{
			board[1][1] = '#';
			break;
		}

		//�ж����ÿ���Ƿ��3
		if (board[0][0] == board[0][1] && board[0][0] == '*') { if (board[0][2] == ' ') { board[0][2] = '#'; break; } }
		if (board[0][0] == board[0][2] && board[0][0] == '*') { if (board[0][1] == ' ') { board[0][1] = '#'; break; } }
		if (board[0][1] == board[0][2] && board[0][1] == '*') { if (board[0][0] == ' ') { board[0][0] = '#'; break; } }

		if (board[1][0] == board[1][1] && board[1][0] == '*') { if (board[1][2] == ' ') { board[1][2] = '#'; break; } }
		if (board[1][0] == board[1][2] && board[1][0] == '*') { if (board[1][1] == ' ') { board[1][1] = '#'; break; } }
		if (board[1][1] == board[1][2] && board[1][1] == '*') { if (board[1][0] == ' ') { board[1][0] = '#'; break; } }

		if (board[2][0] == board[2][1] && board[2][0] == '*') { if (board[2][2] == ' ') { board[2][2] = '#'; break; } }
		if (board[2][0] == board[2][2] && board[2][0] == '*') { if (board[2][1] == ' ') { board[2][1] = '#'; break; } }
		if (board[2][1] == board[2][2] && board[2][1] == '*') { if (board[2][0] == ' ') { board[2][0] = '#'; break; } }
		//�ж����ÿ���Ƿ��3
		if (board[0][0] == board[1][0] && board[0][0] == '*') { if (board[2][0] == ' ') { board[2][0] = '#'; break; } }
		if (board[0][0] == board[2][0] && board[0][0] == '*') { if (board[1][0] == ' ') { board[1][0] = '#'; break; } }
		if (board[1][0] == board[2][0] && board[1][0] == '*') { if (board[0][0] == ' ') { board[0][0] = '#'; break; } }

		if (board[0][1] == board[1][1] && board[0][1] == '*') { if (board[2][1] == ' ') { board[2][1] = '#'; break; } }
		if (board[0][1] == board[2][1] && board[0][1] == '*') { if (board[1][1] == ' ') { board[1][1] = '#'; break; } }
		if (board[1][1] == board[2][1] && board[1][1] == '*') { if (board[0][1] == ' ') { board[0][1] = '#'; break; } }

		if (board[0][1] == board[1][2] && board[0][2] == '*') { if (board[2][2] == ' ') { board[2][2] = '#'; break; } }
		if (board[0][1] == board[2][2] && board[0][2] == '*') { if (board[1][2] == ' ') { board[1][2] = '#'; break; } }
		if (board[1][1] == board[2][2] && board[1][2] == '*') { if (board[0][2] == ' ') { board[0][2] = '#'; break; } }
		//�ж���ҶԽ����Ƿ��3
		if (board[0][0] == board[1][1] && board[0][0] == '*') { if (board[2][2] == ' ') { board[2][2] = '#'; break; } }
		if (board[0][0] == board[2][2] && board[0][0] == '*') { if (board[1][1] == ' ') { board[1][1] = '#'; break; } }
		if (board[1][1] == board[2][2] && board[1][1] == '*') { if (board[0][0] == ' ') { board[0][0] = '#'; break; } }

		if (board[0][2] == board[1][1] && board[1][1] == '*') { if (board[2][0] == ' ') { board[2][0] = '#'; break; } }
		if (board[0][2] == board[2][0] && board[0][2] == '*') { if (board[1][1] == ' ') { board[1][1] = '#'; break; } }
		if (board[1][1] == board[2][0] && board[1][1] == '*') { if (board[0][2] == ' ') { board[0][2] = '#'; break; } }

		//����0~2�������
		int x = rand() % row;
		int y = rand() % col;
		//�ж��Ƿ�Ϊ�ո�
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//�ж���Ӯ
//���Ӯ-����*
//����Ӯ-����#
//ƽ��-����Q
//����-����C

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;  //����û��
			}
		}
	}
	return 1;  //��������
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//�ж���
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//�ж���
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//�ж�ƽ��
	int Full_ret = IsFull(board, row, col);
	if (Full_ret == 1)
	{
		return 'Q';  //ƽ����
	}
	//����
	return 'C';
}

//-----------------------------------------------------------------------------
//���1
void Player1_Round(char board[ROW][COL], int row, int col)
{
	int x = 0;  //��������
	int y = 0;  //��������
	while (1)
	{
		printf("���1�غ�>>>\n");
		printf("���������ӵ�������");
		scanf("%d", &x);
		printf("\n���������ӵ�������");
		scanf("%d", &y);

		//�ж������Ƿ���Ч
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("����λ�ñ�ռ�ã�����������\n");
			}
		}
		else
		{
			printf("����λ����Ч������������\n");
		}
	}
}

//���2
void Player2_Round(char board[ROW][COL], int row, int col)
{
	int x = 0;  //��������
	int y = 0;  //��������
	while (1)
	{
		printf("���2�غ�>>>\n");
		printf("���������ӵ�������");
		scanf("%d", &x);
		printf("\n���������ӵ�������");
		scanf("%d", &y);

		//�ж������Ƿ���Ч
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("����λ�ñ�ռ�ã�����������\n");
			}
		}
		else
		{
			printf("����λ����Ч������������\n");
		}
	}
}