#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 队列节点类型
typedef struct QueueNode {
	char data;
	struct QueueNode* next;
}QueueNode;

// 队列数据类型
typedef struct LinkQueue {
	struct QueueNode* front, * rear;  // 存储头指针和尾指针，类型为队列节点指针
}LinkQueue;

// 初始化队列
void QueueInit(LinkQueue* Q) {
	Q->front = Q->rear = (QueueNode*)malloc(sizeof(QueueNode));  // 创建头节点，头指针与尾指针都指向头结点
	Q->front->next = NULL;  // 将队列的头节点的next置为空
}

// 判断队列是否为空
bool IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) {  // 当头指针与尾指针所指节点相同时，队列为空
		printf("队列为空\n");
		return true;
	}
	return false;
}

// 创建节点
QueueNode* CreateNode(char data) {
	QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

// 销毁节点
void DeleteNode(QueueNode** node) {
	free(*node);
	*node = NULL;
	printf("销毁成功\n");
}

// 尾插元素
void QueueInsert(LinkQueue* Q, char data) {
	QueueNode* new_node = CreateNode(data);
	Q->rear->next = new_node;  // 将创建好的新结点接在队尾
	Q->rear = new_node;  // 将新结点作为队尾
	printf("插入成功\n");
}

// 头出元素
QueueNode* QueueDelete(LinkQueue* Q) {
	if (IsEmpty(*Q)) { // 如果队列为空, 返回NULL
		return NULL;
	}
	QueueNode* first = Q->front->next;  // 将头节点的后一位，即首个结点保存，准备出队
	Q->front->next = first->next;  // 将队列的第二位元素接在头结点处
	if (first == Q->rear) {  // 如果出队的元素为队尾
		Q->rear = Q->front;  // 将尾指针指向头节点
	}
	printf("出队成功\n");
	return first;
}

// 打印队列
void QueuePrint(LinkQueue* Q) {
	QueueNode* node = Q->front->next;
	while (node != NULL) {
		printf("%c ", node->data);
		node = node->next;
	}
	printf("\n");
}

int main() {
	LinkQueue queue;
	QueueInit(&queue);
	IsEmpty(queue);
	QueueInsert(&queue, 'a');
	QueueInsert(&queue, 'b');
	QueueInsert(&queue, 'c');
	QueueInsert(&queue, 'd');
	QueuePrint(&queue);
	QueueNode* del_node = QueueDelete(&queue);
	DeleteNode(&del_node);
	QueuePrint(&queue);

	return 0;
}