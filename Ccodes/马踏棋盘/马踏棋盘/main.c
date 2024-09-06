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
int top = -1;  // ջ��ָ��

int dir[8][2] = {  // ����н�����
	{-2,1},{-1,2},{1,2},  {2,1},
	{2,-1},{1,-2},{-1,-2},{-2,-1}
};
int board[MAX][MAX] = { 0 };  // ����

int out_stack = 0;  // ���ݴ���

// �жϵ�ǰ���Ƿ���������
bool IsInBoard(int x, int y) {
	return x >= 0 && x < MAX && y >= 0 && y < MAX && !board[x][y];
}

// ��ӡ����
void PrintBoard() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			printf("%4d", board[i][j]);
		}
		printf("\n");
	}
}

// ѹջ
void Push(int x, int y) {
	top++;
	stack[top].x = x;
	stack[top].y = y;
	stack[top].dir = -1;
	board[x][y] = top + 1;
}

// ��ջ
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

// ��������������������·�����ٵķ��򣬼��ٻ��ݴ���
void GetSeq(int* next, int* seq) {
	int n[8];  // Ϊ��ֹnext�����򣬸���һ��next����
	for (int i = 0; i < 8; i++)
		n[i] = next[i];
	for (int i = 0; i < 7; i++) {  // ð������
		for (int j = 0; j < 7 - i; j++) {
			if (n[j] > n[j + 1]) {
				int tmp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = tmp;
				// n���齻��ʱ��tmp����Ҳ���н���
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
			PrintBoard();  // ��ӡ����
			system("pause");
			printf("\n");
			//break;
		}
		int next[8] = { 0 };
		GetNext(x, y, next);
		int seq[8] = { 0,1,2,3,4,5,6,7 };
		GetSeq(next, seq);
		for (i = stack[top].dir + 1; i < 8; i++) {  // �˴�dir��Ҫƫ��һλ���������ʱ������ѭ��
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
			printf("ջ��Ԫ��ȫ���˳�\n");
			printf("�޽�\n");
			break;
		}
	}
}

int main() {
	int x, y;
	do {
		system("cls");
		printf("������������꣺");
		scanf("%d%d", &x, &y);
	} while (!IsInBoard(x, y));

	RunHorse(x, y);
	printf("ջ��Ԫ���˳�����Ϊ%d\n", out_stack);

	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>z
//#include<stdbool.h>
//
//#define ROW 8
//#define COL 8
//#define DIR -1		//����Ĭ��Ϊ-1��-1��ʾ������
//
//int dir[8][2] = { {2,-1},{-2,-1},{-2,1},{2,1},{1,-2},{-1,-2},{-1,2},{1,2} };
////int dir[8][2] = {  // ����н�����
////	{-2,1},{-1,2},{1,2},  {2,1},
////	{2,-1},{1,-2},{-1,-2},{-2,-1}
////};
//int map[ROW][COL];
//
////����ջ�Ľṹ��
//typedef struct
//{
//	int x;
//	int y;
//	int dir;	//����
//}Stack;
//
//Stack chess[ROW * COL + 5];		//�洢ÿ��������λ��
//int top = -1;					//ջ��ָ��
//int out_stack = 0;				//��ջ����
//
//bool in(int x, int y)
//{
//	return x >= 0 && x < ROW && y >= 0 && y < COL && !map[x][y];
//}
////ע������������  !map[x][y]
//
//void printMap()		//��ӡ����
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
//	//��ֹԭ����next���鱻���򣬸��Ƹ�next����������Ϳ�
//
//	//ð�����򣬲���������Seq���飬��Ȼ������Ҳ�����ýṹ��ʵ��
//	for (int i = 0; i < 7; i++)
//	{
//		for (int j = 0; j < 7 - i; j++)
//		{
//			if (n[j] > n[j + 1])
//			{
//				int t = n[j];
//				n[j] = n[j + 1];
//				n[j + 1] = t;
//				//n���齻��ʱ����seq�������ͬ���Ľ���
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
////��ջ��ʱ�����г�ʼ��
//void push(int x, int y)
//{
//	top++;
//	chess[top].x = x;
//	chess[top].y = y;
//	chess[top].dir = DIR;
//	map[x][y] = top + 1;//��Ϊtop�ǴӸ�һ��ʼ�ģ�����һ����1
//}
//
////��ջ��Ҫ��ջ�����ݸ���ʼ����Ȼ����top--��
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
//		if (top >= 64 - 1)		//top��0��ʼ����64����������63������64��
//		{
//			//��ӡ����
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
//		bool flag = false;//��������Ƿ��ջ
//		for (int i = chess[top].dir + 1; i < 8; i++)
//		{	//i = chess[top].dir+1 ����ΪҪ��ƫ��һλ�������ж��������ݣ���Ȼ����Ҫ����ʱ���ȳ�ջ��
//			//Ȼ���ٵ����λ�õ�ʱ��i���ǵ���֮ǰ�Ǹ���Ҫ���ݵ�dir��Ȼ��ͳ���ѭ����
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
//		//���ǰ��8�������Ѿ��ж��꣬��û�н�ջ����˵��Ŀǰû�з���������ˣ�ֻ�ܳ�ջ
//		//���dir�����У�ֻ������7 5 �Żᷢ������
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
//	printf("��������ʼ���꣺");
//	scanf("%d%d", &x, &y);
//	if (!in(x, y))
//	{
//		printf("\n\n����������󣡣�\n\n");
//		return;
//	}
//	push(x, y);
//	dfs();
//	printf("\n\n������%d��\n\n", out_stack);
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
//int pos[2];  // �������
//int step = 0;  // ��¼���ߵĲ���
//int count = 0;
//
//int dir[8][2] = {  // �������̵�ƫ����
//	{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
//	{1, 2},   {2, 1},   {2, -1}, {1, -2}
//};
//
//// ����ջ���
//StackNode* CreateStackNode(int* data) {
//	StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
//	if (data != NULL) {
//		new_node->data = (int*)malloc(sizeof(int) * 3);
//		new_node->data[0] = data[0];  // ǰ�����洢���x��y
//		new_node->data[1] = data[1];
//		new_node->data[2] = -1;  // ��һ���洢��ǰ�ķ���
//	}
//	new_node->next = NULL;
//	return new_node;
//}
//
//// ��ʼ��ջͷ�ڵ�
//StackNode* InitStack() {
//	StackNode* stack = CreateStackNode(NULL);
//	return stack;
//}
//
//// �ж��Ƿ�Ϊ��ջ
//bool IsEmptyStack(StackNode* stack) {
//	if (stack->next == NULL)
//		return true;
//	return false;
//}
//
//// ѹջ
//void Push(StackNode* stack, int* data, int dir) {
//	StackNode* new_node = CreateStackNode(data);
//	new_node->next = stack->next;
//	stack->next = new_node;
//	if (new_node->next != NULL)
//		new_node->next->data[2] = dir;
//}
//
//// ��ջ
//StackNode* Pop(StackNode* stack) {
//	if (IsEmptyStack(stack))
//		return NULL;
//	StackNode* node = stack->next;
//	stack->next = node->next;
//	return node;
//}
//
//// �ж��Ƿ�Խ��
//bool IsCrossed() {
//	if (pos[0] < 0 || pos[0] >= MAX || pos[1] < 0 || pos[1] >= MAX)
//		return true;
//	return false;
//}
//
//// �ж��Ƿ�������������
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
//		if (IsFull()) {  // ������������˾��˳�
//			break;
//		}
//		for (i = stack->next->data[2] + 1; i < 8; i++) {  // ��ջ��Ԫ�ص��н������¼����Ȼ��������
//			pos[0] += dir[i][0];
//			pos[1] += dir[i][1];
//			if (IsCrossed() || visited[pos[0]][pos[1]] == true) {  // �ж��Ƿ�Խ��򱻷��ʹ�
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
//		if (IsEmptyStack(stack))  // ���ջ�˿��ˣ����˳�
//			break;
//	}
//}
//
//int main() {
//	do {
//		printf("��������ĳ�ʼλ�ã�");
//		scanf("%d%d", &pos[0], &pos[1]);
//		if (IsCrossed()) {
//			system("cls");
//			printf("����λ��Խ�磬���������롣\n");
//		}
//	} while (IsCrossed());
//	
//	Horse();
//
//	PrintBoard();
//
//	if (!IsFull())
//		printf("�޽�\n");
//
//	return 0;
//}