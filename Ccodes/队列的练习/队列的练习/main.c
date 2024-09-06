#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE  5

typedef struct Data {
	int num;
	char ch;
}Data;

typedef struct Queue {
	Data data[MAX_SIZE];  //��Ŷ���Ԫ��
	int front, rear;  //�洢ͷԪ��λ�ú�βԪ��λ��
}Queue;  //������һ��FIFO�ṹ��first in first out �ṹ

//��ʼ��һ������
void InitQueue(Queue* q) {
	q->front = 0;
	q->rear = 0;
}

//�ж϶����Ƿ�Ϊ��
bool QueueIsEmpty(Queue q) {
	if (q.front == q.rear)
		return true;
	return false;
}

//������г���
int QueueLength(Queue q) {
	return (q.rear - q.front + MAX_SIZE) % MAX_SIZE;  //��������Ҫ����һ����Ԫ�����ֶ����Ͷӿ�
}

//Ԫ�����
bool QueueEnter(Queue* q, Data d) {
	if ((q->rear + 1) % MAX_SIZE == q->front)  //�����������
		return false;
	q->data[q->rear] = d;
	q->rear = (q->rear + 1) % MAX_SIZE;  //rearָ������ƶ�һλ�����Ϊ���һλ��ת�Ƶ�ͷ��
	return true;
}

//Ԫ�س���
bool QueueDelete(Queue* q, Data* d) {
	if (q->rear == q->front) //�������Ϊ��
		return false;
	*d = q->data[q->front];
	q->front = (q->front - 1 + MAX_SIZE) % MAX_SIZE;  //frontָ����ǰ�ƶ�һλ�����Ϊ��һλ��ת�Ƶ�β��
	return true;
	return true;
}

int main() {
	Queue queue1 = { 0 };

	InitQueue(&queue1);

	Data data1 = { 1, 'a' };
	EnterQueue(&queue1, data1);

	if (QueueIsEmpty(queue1))
		printf("����Ϊ��\n");
	else
		printf("���в�Ϊ��\n");

	return 0;
}