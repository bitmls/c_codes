#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX  8

typedef struct Stack {
	int x;
	int y;
	int dir;
}Stack;

Stack stack[MAX * MAX];
int top = -1;  // 栈顶指针

int dir[8][2] = {  // 马的行进方向
	{-2,1},{-1,2},{1,2},  {2,1},
	{2,-1},{1,-2},{-1,-2},{-2,-1}
};
int board[MAX][MAX] = { 0 };  // 棋盘

int out_stack = 0;  // 回溯次数

// 判断当前点是否在棋盘内
bool IsInBoard(int x, int y) {
	return x >= 0 && x < MAX && y >= 0 && y < MAX && !board[x][y];
}

// 打印棋盘
void PrintBoard() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			printf("%4d", board[i][j]);
		}
		printf("\n");
	}
}

// 压栈
void Push(int x, int y) {
	top++;
	stack[top].x = x;
	stack[top].y = y;
	stack[top].dir = -1;
	board[x][y] = top + 1;
}

// 出栈
void Pop() {
	if (top <= -1)
		return;
	board[stack[top].x][stack[top].y] = 0;
	stack[top].x = 0;
	stack[top].y = 0;
	stack[top].dir = -1;
	top--;
}

void GetNext(int x, int y, int* next) {
	for (int i = 0; i < 8; i++) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (IsInBoard(tx, ty)) {
			for (int j = 0; j < 8; j++) {
				int ttx = tx + dir[j][0];
				int tty = ty + dir[j][1];
				if (IsInBoard(ttx, tty)) {
					next[i]++;
				}
			}
		}
	}
}

// 给方向排序，让马优先走路径更少的方向，减少回溯次数
void GetSeq(int* next, int* seq) {
	int n[8];  // 为防止next被排序，复制一份next数组
	for (int i = 0; i < 8; i++)
		n[i] = next[i];
	for (int i = 0; i < 7; i++) {  // 冒泡排序
		for (int j = 0; j < 7 - i; j++) {
			if (n[j] > n[j + 1]) {
				int tmp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = tmp;
				// n数组交换时，tmp数组也进行交换
				tmp = seq[j];
				seq[j] = seq[j + 1];
				seq[j + 1] = tmp;
			}
		}
	}
}

void RunHorse(int x, int y) {
	Push(x, y);
	int i = 0;
	while (1) {
		bool flag = false;
		if (top >= MAX * MAX - 1) {
			PrintBoard();  // 打印棋盘
			system("pause");
			printf("\n");
			//break;
		}
		int next[8] = { 0 };
		GetNext(x, y, next);
		int seq[8] = { 0,1,2,3,4,5,6,7 };
		GetSeq(next, seq);
		for (i = stack[top].dir + 1; i < 8; i++) {  // 此处dir需要偏移一位，以免回溯时进入死循环
			int tx = x + dir[seq[i]][0];
			int ty = y + dir[seq[i]][1];
			stack[top].dir++;
			if (IsInBoard(tx, ty)) {
				Push(tx, ty);
				x = tx;
				y = ty;
				flag = true;
				break;
			}
		}
		if (i == 8 && !flag) {
			Pop();
			x = stack[top].x;
			y = stack[top].y;
			out_stack++;
			if (out_stack % 100000000 == 0)
				printf("%d\n", out_stack);
		}
		if (top <= -1) {
			printf("栈的元素全部退出\n");
			printf("无解\n");
			break;
		}
	}
}

int main() {
	int x, y;
	do {
		system("cls");
		printf("请输入马的坐标：");
		scanf("%d%d", &x, &y);
	} while (!IsInBoard(x, y));

	RunHorse(x, y);
	printf("栈顶元素退出次数为%d\n", out_stack);

	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>z
//#include<stdbool.h>
//
//#define ROW 8
//#define COL 8
//#define DIR -1		//方向默认为-1，-1表示不能走
//
//int dir[8][2] = { {2,-1},{-2,-1},{-2,1},{2,1},{1,-2},{-1,-2},{-1,2},{1,2} };
////int dir[8][2] = {  // 马的行进方向
////	{-2,1},{-1,2},{1,2},  {2,1},
////	{2,-1},{1,-2},{-1,-2},{-2,-1}
////};
//int map[ROW][COL];
//
////定义栈的结构体
//typedef struct
//{
//	int x;
//	int y;
//	int dir;	//方向
//}Stack;
//
//Stack chess[ROW * COL + 5];		//存储每步的棋子位置
//int top = -1;					//栈顶指针
//int out_stack = 0;				//出栈次数
//
//bool in(int x, int y)
//{
//	return x >= 0 && x < ROW && y >= 0 && y < COL && !map[x][y];
//}
////注意这里整合了  !map[x][y]
//
//void printMap()		//打印棋盘
//{
//	printf("\n\n");
//	for (int i = 0; i < ROW; i++)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			printf("%4d", map[i][j]);
//		}
//		printf("\n\n");
//	}
//	printf("\n\n");
//}
//void getNext(int x, int y, int* next)
//{
//	for (int i = 0; i < 8; i++)
//	{
//		int tx = x + dir[i][0];
//		int ty = y + dir[i][1];
//		if (in(tx, ty))
//		{
//			for (int j = 0; j < 8; j++)
//			{
//				int ttx = tx + dir[j][0];
//				int tty = ty + dir[j][1];
//				if (in(ttx, tty))
//				{
//					next[i]++;
//				}
//			}
//		}
//	}
//}
//
//
//void getSeq(int* next, int* seq)
//{
//	int n[8];
//	for (int i = 0; i < 8; i++)
//		n[i] = next[i];
//	//防止原本的next数组被排序，复制个next数组来排序就可
//
//	//冒泡排序，不过捆绑了Seq数组，当然，这里也可以用结构体实现
//	for (int i = 0; i < 7; i++)
//	{
//		for (int j = 0; j < 7 - i; j++)
//		{
//			if (n[j] > n[j + 1])
//			{
//				int t = n[j];
//				n[j] = n[j + 1];
//				n[j + 1] = t;
//				//n数组交换时，让seq数组进行同样的交换
//				t = seq[j];
//				seq[j] = seq[j + 1];
//				seq[j + 1] = t;
//			}
//		}
//	}
//}
//
//
//
////入栈的时候会进行初始化
//void push(int x, int y)
//{
//	top++;
//	chess[top].x = x;
//	chess[top].y = y;
//	chess[top].dir = DIR;
//	map[x][y] = top + 1;//因为top是从负一开始的，而第一步是1
//}
//
////出栈，要把栈顶数据给初始化，然后再top--；
//void pop()
//{
//	map[chess[top].x][chess[top].y] = 0;
//	chess[top].x = 0;
//	chess[top].y = 0;
//	chess[top].dir = DIR;
//	top--;
//}
//
//void dfs()
//{
//	while (1)
//	{
//		if (top >= 64 - 1)		//top从0开始，【64】，最大就是63，共有64个
//		{
//			//打印棋盘
//			printMap();
//			break;
//		}
//		int x = chess[top].x;
//		int y = chess[top].y;
//
//		int next[8] = { 0,0,0,0,0,0,0,0 };
//		getNext(x, y, next);
//		int seq[8] = { 0,1,2,3,4,5,6,7 };
//		getSeq(next, seq);
//
//		bool flag = false;//用来标记是否进栈
//		for (int i = chess[top].dir + 1; i < 8; i++)
//		{	//i = chess[top].dir+1 是因为要先偏移一位，才能判断其他数据，不然当需要回溯时，先出栈，
//			//然后再到这个位置的时候，i还是等于之前那个需要回溯的dir，然后就成死循环了
//			int tx = x + dir[seq[i]][0];
//			int ty = y + dir[seq[i]][1];
//			chess[top].dir++;
//			if (in(tx, ty))
//			{
//				push(tx, ty);
//				flag = true;
//				break;
//			}
//
//		}
//		//如果前面8个方向已经判断完，且没有进栈，就说明目前没有方向可以走了，只能出栈
//		//这个dir方向中，只有输入7 5 才会发生回溯
//		if (chess[top].dir == 7 && flag == false)
//		{
//			out_stack++;
//			pop();
//		}
//
//	}
//}
//
//void run()
//{
//	int x, y;
//	printf("请输入起始坐标：");
//	scanf("%d%d", &x, &y);
//	if (!in(x, y))
//	{
//		printf("\n\n坐标输入错误！！\n\n");
//		return;
//	}
//	push(x, y);
//	dfs();
//	printf("\n\n共回溯%d次\n\n", out_stack);
//}
//
//int main()
//{
//	run();
//	return 0;
//}


//#define _CRT_SECURE_NO_WARNINGS  1
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//#define MAX  7
//
//typedef struct StackNode {
//	int* data;
//	struct StackNode* next;
//}StackNode;
//
//int board[MAX][MAX] = { 0 };
//bool visited[MAX][MAX];
//int pos[2];  // 马的坐标
//int step = 0;  // 记录马走的步数
//int count = 0;
//
//int dir[8][2] = {  // 马走棋盘的偏移量
//	{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
//	{1, 2},   {2, 1},   {2, -1}, {1, -2}
//};
//
//// 创建栈结点
//StackNode* CreateStackNode(int* data) {
//	StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
//	if (data != NULL) {
//		new_node->data = (int*)malloc(sizeof(int) * 3);
//		new_node->data[0] = data[0];  // 前两个存储马的x和y
//		new_node->data[1] = data[1];
//		new_node->data[2] = -1;  // 后一个存储当前的方向
//	}
//	new_node->next = NULL;
//	return new_node;
//}
//
//// 初始化栈头节点
//StackNode* InitStack() {
//	StackNode* stack = CreateStackNode(NULL);
//	return stack;
//}
//
//// 判断是否为空栈
//bool IsEmptyStack(StackNode* stack) {
//	if (stack->next == NULL)
//		return true;
//	return false;
//}
//
//// 压栈
//void Push(StackNode* stack, int* data, int dir) {
//	StackNode* new_node = CreateStackNode(data);
//	new_node->next = stack->next;
//	stack->next = new_node;
//	if (new_node->next != NULL)
//		new_node->next->data[2] = dir;
//}
//
//// 出栈
//StackNode* Pop(StackNode* stack) {
//	if (IsEmptyStack(stack))
//		return NULL;
//	StackNode* node = stack->next;
//	stack->next = node->next;
//	return node;
//}
//
//// 判断是否越界
//bool IsCrossed() {
//	if (pos[0] < 0 || pos[0] >= MAX || pos[1] < 0 || pos[1] >= MAX)
//		return true;
//	return false;
//}
//
//// 判断是否走满整个棋盘
//bool IsFull() {
//	if (step >= MAX * MAX)
//		return true;
//	return false;
//}
//
//void PrintBoard() {
//	for (int i = 0; i < MAX; i++) {
//		for (int j = 0; j < MAX; j++) {
//			printf("%3d ", board[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void Horse() {
//	StackNode* stack = InitStack();
//	Push(stack, pos, -1);
//	visited[pos[0]][pos[1]] = true;
//	board[pos[0]][pos[1]] = ++step;
//	while (1) {
//		int i = 0;
//		if (IsFull()) {  // 如果棋盘走满了就退出
//			break;
//		}
//		for (i = stack->next->data[2] + 1; i < 8; i++) {  // 将栈顶元素的行进方向记录下来然后向后遍历
//			pos[0] += dir[i][0];
//			pos[1] += dir[i][1];
//			if (IsCrossed() || visited[pos[0]][pos[1]] == true) {  // 判断是否越界或被访问过
//				pos[0] -= dir[i][0];
//				pos[1] -= dir[i][1];
//				continue;
//			}
//			Push(stack, pos, i);
//			visited[pos[0]][pos[1]] = true;
//			board[pos[0]][pos[1]] = ++step;
//			i = 0;
//			count++;
//			printf("%d\n", count);
//			break;
//		}
//		if (i == 8) {
//			StackNode* node = Pop(stack);
//			if (!IsEmptyStack(stack)) {
//				pos[0] = stack->next->data[0];
//				pos[1] = stack->next->data[1];
//				board[node->data[0]][node->data[1]] = 0;
//				visited[node->data[0]][node->data[1]] = false;
//				step--;
//			}
//			free(node->data);
//			free(node);
//			node = NULL;
//		}
//		if (IsEmptyStack(stack))  // 如果栈退空了，则退出
//			break;
//	}
//}
//
//int main() {
//	do {
//		printf("请输入马的初始位置：");
//		scanf("%d%d", &pos[0], &pos[1]);
//		if (IsCrossed()) {
//			system("cls");
//			printf("输入位置越界，请重新输入。\n");
//		}
//	} while (IsCrossed());
//	
//	Horse();
//
//	PrintBoard();
//
//	if (!IsFull())
//		printf("无解\n");
//
//	return 0;
//}