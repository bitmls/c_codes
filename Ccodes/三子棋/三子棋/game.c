#include "game.h"

//棋盘初始化 - 将所有元素变为空格
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

//打印棋盘
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

//玩家回合
void Player_Round(char board[ROW][COL], int row, int col)
{
	int x = 0;  //落子行数
	int y = 0;  //落子列数
	while (1)
	{
		printf("玩家回合>>>\n");
		printf("请输入落子的行数：");
		scanf("%d", &x);
		printf("\n请输入落子的列数：");
		scanf("%d", &y);
	
		//判断输入是否有效
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("输入位置被占用，请重新输入\n");
			}
		}
		else
		{
			printf("输入位置无效，请重新输入\n");
		}
	}
}

void Computer_Round(char board[ROW][COL], int row, int col)
{
	printf("电脑回合>>>\n");
	while (1)
	{
		//生成0~2的随机数
		int x = rand() % row;
		int y = rand() % col;
		//判断是否为空格
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

void Computer_Round_Hard(char board[ROW][COL], int row, int col)
{
	printf("电脑回合>>>\n");
	while (1)
	{
		int i = 0;

		//判断电脑每行是否成3
		if (board[0][0] == board[0][1] && board[0][0] == '#') { if (board[0][2] == ' ') { board[0][2] = '#'; break; } }
		if (board[0][0] == board[0][2] && board[0][0] == '#') { if (board[0][1] == ' ') { board[0][1] = '#'; break; } }
		if (board[0][1] == board[0][2] && board[0][1] == '#') { if (board[0][0] == ' ') { board[0][0] = '#'; break; } }
	
		if (board[1][0] == board[1][1] && board[1][0] == '#') { if (board[1][2] == ' ') { board[1][2] = '#'; break; } }
		if (board[1][0] == board[1][2] && board[1][0] == '#') { if (board[1][1] == ' ') { board[1][1] = '#'; break; } }
		if (board[1][1] == board[1][2] && board[1][1] == '#') { if (board[1][0] == ' ') { board[1][0] = '#'; break; } }

		if (board[2][0] == board[2][1] && board[2][0] == '#') { if (board[2][2] == ' ') { board[2][2] = '#'; break; } }
		if (board[2][0] == board[2][2] && board[2][0] == '#') { if (board[2][1] == ' ') { board[2][1] = '#'; break; } }
		if (board[2][1] == board[2][2] && board[2][1] == '#') { if (board[2][0] == ' ') { board[2][0] = '#'; break; } }
		//判断电脑每列是否成3
		if (board[0][0] == board[1][0] && board[0][0] == '#') { if (board[2][0] == ' ') { board[2][0] = '#'; break; } }
		if (board[0][0] == board[2][0] && board[0][0] == '#') { if (board[1][0] == ' ') { board[1][0] = '#'; break; } }
		if (board[1][0] == board[2][0] && board[1][0] == '#') { if (board[0][0] == ' ') { board[0][0] = '#'; break; } }

		if (board[0][1] == board[1][1] && board[0][1] == '#') { if (board[2][1] == ' ') { board[2][1] = '#'; break; } }
		if (board[0][1] == board[2][1] && board[0][1] == '#') { if (board[1][1] == ' ') { board[1][1] = '#'; break; } }
		if (board[1][1] == board[2][1] && board[1][1] == '#') { if (board[0][1] == ' ') { board[0][1] = '#'; break; } }

		if (board[0][1] == board[1][2] && board[0][2] == '#') { if (board[2][2] == ' ') { board[2][2] = '#'; break; } }
		if (board[0][1] == board[2][2] && board[0][2] == '#') { if (board[1][2] == ' ') { board[1][2] = '#'; break; } }
		if (board[1][1] == board[2][2] && board[1][2] == '#') { if (board[0][2] == ' ') { board[0][2] = '#'; break; } }
		//判断电脑对角线是否成3
		if (board[0][0] == board[1][1] && board[0][0] == '#') { if (board[2][2] == ' ') { board[2][2] = '#'; break; } }
		if (board[0][0] == board[2][2] && board[0][0] == '#') { if (board[1][1] == ' ') { board[1][1] = '#'; break; } }
		if (board[1][1] == board[2][2] && board[1][1] == '#') { if (board[0][0] == ' ') { board[0][0] = '#'; break; } }

		if (board[0][2] == board[1][1] && board[1][1] == '#') { if (board[2][0] == ' ') { board[2][0] = '#'; break; } }
		if (board[0][2] == board[2][0] && board[0][2] == '#') { if (board[1][1] == ' ') { board[1][1] = '#'; break; } }
		if (board[1][1] == board[2][0] && board[1][1] == '#') { if (board[0][2] == ' ') { board[0][2] = '#'; break; } }

		//判断中心点
		if (board[1][1] == ' ')
		{
			board[1][1] = '#';
			break;
		}

		//判断玩家每行是否成3
		if (board[0][0] == board[0][1] && board[0][0] == '*') { if (board[0][2] == ' ') { board[0][2] = '#'; break; } }
		if (board[0][0] == board[0][2] && board[0][0] == '*') { if (board[0][1] == ' ') { board[0][1] = '#'; break; } }
		if (board[0][1] == board[0][2] && board[0][1] == '*') { if (board[0][0] == ' ') { board[0][0] = '#'; break; } }

		if (board[1][0] == board[1][1] && board[1][0] == '*') { if (board[1][2] == ' ') { board[1][2] = '#'; break; } }
		if (board[1][0] == board[1][2] && board[1][0] == '*') { if (board[1][1] == ' ') { board[1][1] = '#'; break; } }
		if (board[1][1] == board[1][2] && board[1][1] == '*') { if (board[1][0] == ' ') { board[1][0] = '#'; break; } }

		if (board[2][0] == board[2][1] && board[2][0] == '*') { if (board[2][2] == ' ') { board[2][2] = '#'; break; } }
		if (board[2][0] == board[2][2] && board[2][0] == '*') { if (board[2][1] == ' ') { board[2][1] = '#'; break; } }
		if (board[2][1] == board[2][2] && board[2][1] == '*') { if (board[2][0] == ' ') { board[2][0] = '#'; break; } }
		//判断玩家每列是否成3
		if (board[0][0] == board[1][0] && board[0][0] == '*') { if (board[2][0] == ' ') { board[2][0] = '#'; break; } }
		if (board[0][0] == board[2][0] && board[0][0] == '*') { if (board[1][0] == ' ') { board[1][0] = '#'; break; } }
		if (board[1][0] == board[2][0] && board[1][0] == '*') { if (board[0][0] == ' ') { board[0][0] = '#'; break; } }

		if (board[0][1] == board[1][1] && board[0][1] == '*') { if (board[2][1] == ' ') { board[2][1] = '#'; break; } }
		if (board[0][1] == board[2][1] && board[0][1] == '*') { if (board[1][1] == ' ') { board[1][1] = '#'; break; } }
		if (board[1][1] == board[2][1] && board[1][1] == '*') { if (board[0][1] == ' ') { board[0][1] = '#'; break; } }

		if (board[0][1] == board[1][2] && board[0][2] == '*') { if (board[2][2] == ' ') { board[2][2] = '#'; break; } }
		if (board[0][1] == board[2][2] && board[0][2] == '*') { if (board[1][2] == ' ') { board[1][2] = '#'; break; } }
		if (board[1][1] == board[2][2] && board[1][2] == '*') { if (board[0][2] == ' ') { board[0][2] = '#'; break; } }
		//判断玩家对角线是否成3
		if (board[0][0] == board[1][1] && board[0][0] == '*') { if (board[2][2] == ' ') { board[2][2] = '#'; break; } }
		if (board[0][0] == board[2][2] && board[0][0] == '*') { if (board[1][1] == ' ') { board[1][1] = '#'; break; } }
		if (board[1][1] == board[2][2] && board[1][1] == '*') { if (board[0][0] == ' ') { board[0][0] = '#'; break; } }

		if (board[0][2] == board[1][1] && board[1][1] == '*') { if (board[2][0] == ' ') { board[2][0] = '#'; break; } }
		if (board[0][2] == board[2][0] && board[0][2] == '*') { if (board[1][1] == ' ') { board[1][1] = '#'; break; } }
		if (board[1][1] == board[2][0] && board[1][1] == '*') { if (board[0][2] == ' ') { board[0][2] = '#'; break; } }

		//生成0~2的随机数
		int x = rand() % row;
		int y = rand() % col;
		//判断是否为空格
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//判断输赢
//玩家赢-返回*
//电脑赢-返回#
//平局-返回Q
//继续-返回C

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
				return 0;  //棋盘没满
			}
		}
	}
	return 1;  //棋盘满了
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//判断行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//判断列
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//判断平局
	int Full_ret = IsFull(board, row, col);
	if (Full_ret == 1)
	{
		return 'Q';  //平局了
	}
	//继续
	return 'C';
}

//-----------------------------------------------------------------------------
//玩家1
void Player1_Round(char board[ROW][COL], int row, int col)
{
	int x = 0;  //落子行数
	int y = 0;  //落子列数
	while (1)
	{
		printf("玩家1回合>>>\n");
		printf("请输入落子的行数：");
		scanf("%d", &x);
		printf("\n请输入落子的列数：");
		scanf("%d", &y);

		//判断输入是否有效
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("输入位置被占用，请重新输入\n");
			}
		}
		else
		{
			printf("输入位置无效，请重新输入\n");
		}
	}
}

//玩家2
void Player2_Round(char board[ROW][COL], int row, int col)
{
	int x = 0;  //落子行数
	int y = 0;  //落子列数
	while (1)
	{
		printf("玩家2回合>>>\n");
		printf("请输入落子的行数：");
		scanf("%d", &x);
		printf("\n请输入落子的列数：");
		scanf("%d", &y);

		//判断输入是否有效
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("输入位置被占用，请重新输入\n");
			}
		}
		else
		{
			printf("输入位置无效，请重新输入\n");
		}
	}
}