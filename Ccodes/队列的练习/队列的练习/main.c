#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE  5

typedef struct Data {
	int num;
	char ch;
}Data;

typedef struct Queue {
	Data data[MAX_SIZE];  //存放队列元素
	int front, rear;  //存储头元素位置和尾元素位置
}Queue;  //队列是一种FIFO结构，first in first out 结构

//初始化一个队列
void InitQueue(Queue* q) {
	q->front = 0;
	q->rear = 0;
}

//判断队列是否为空
bool QueueIsEmpty(Queue q) {
	if (q.front == q.rear)
		return true;
	return false;
}

//计算队列长度
int QueueLength(Queue q) {
	return (q.rear - q.front + MAX_SIZE) % MAX_SIZE;  //队列中需要牺牲一个单元来区分队满和队空
}

//元素入队
bool QueueEnter(Queue* q, Data d) {
	if ((q->rear + 1) % MAX_SIZE == q->front)  //如果队列已满
		return false;
	q->data[q->rear] = d;
	q->rear = (q->rear + 1) % MAX_SIZE;  //rear指针向后移动一位，如果为最后一位则转移到头部
	return true;
}

//元素出队
bool QueueDelete(Queue* q, Data* d) {
	if (q->rear == q->front) //如果队列为空
		return false;
	*d = q->data[q->front];
	q->front = (q->front - 1 + MAX_SIZE) % MAX_SIZE;  //front指针向前移动一位，如果为第一位则转移到尾部
	return true;
	return true;
}

int main() {
	Queue queue1 = { 0 };

	InitQueue(&queue1);

	Data data1 = { 1, 'a' };
	EnterQueue(&queue1, data1);

	if (QueueIsEmpty(queue1))
		printf("队列为空\n");
	else
		printf("队列不为空\n");

	return 0;
}