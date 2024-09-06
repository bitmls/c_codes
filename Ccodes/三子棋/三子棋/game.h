#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//定义棋盘大小
#define ROW 3
#define COL 3

//棋盘初始化
Board_Init(char board[ROW][COL], int row, int col);

//打印棋盘
Board_Print(char board[ROW][COL], int row, int col);

//玩家回合
void Player_Round(char board[ROW][COL], int row, int col);

//电脑回合
void Computer_Round(char board[ROW][COL], int row, int col);

//判断输赢
char IsWin(char board[ROW][COL], int row, int col);

//-------------------------------------------------
//双人模式
void Player1_Round(char board[ROW][COL], int row, int col);
void Player2_Round(char board[ROW][COL], int row, int col);

//困难电脑模式
void Computer_Round_Hard(char board[ROW][COL], int row, int col);