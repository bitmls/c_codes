#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�������̴�С
#define ROW 3
#define COL 3

//���̳�ʼ��
Board_Init(char board[ROW][COL], int row, int col);

//��ӡ����
Board_Print(char board[ROW][COL], int row, int col);

//��һغ�
void Player_Round(char board[ROW][COL], int row, int col);

//���Իغ�
void Computer_Round(char board[ROW][COL], int row, int col);

//�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col);

//-------------------------------------------------
//˫��ģʽ
void Player1_Round(char board[ROW][COL], int row, int col);
void Player2_Round(char board[ROW][COL], int row, int col);

//���ѵ���ģʽ
void Computer_Round_Hard(char board[ROW][COL], int row, int col);