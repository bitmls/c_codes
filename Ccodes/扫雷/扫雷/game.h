#pragma once
#include <stdio.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

//数组初始化
void Board_Init(char ch[ROWS][COLS], int rows, int cols, char set);

//打印数组
void Display_Board(char ch[ROWS][COLS], int row, int col);