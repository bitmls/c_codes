#include "game.h"

void Board_Init(char ch[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			ch[i][j] = set;
		}
	}
}

void Display_Board(char ch[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		for (j = 0; j <= col; j++)
		{
			printf("%c ", ch[i][j]);
		}
		printf("\n");
	}
}