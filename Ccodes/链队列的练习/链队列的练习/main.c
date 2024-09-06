#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int num;
	char ch;
}Data;

//链式存储节点
typedef struct {
	Data data;
	struct LinkNode *next;
}LinkNode;

//链式队列
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;


//创建结点
LinkNode* CreateNode() {
	LinkNode* new_node = (LinkNode*)malloc(sizeof(LinkNode));
	new_node->next = NULL;
	return new_node;
}

//链队列初始化
void LinkQueueInit(LinkQueue* link_q) {
	link_q->front = CreateNode();  //创建头结点
	link_q->rear = link_q->front;  //尾结点与头结点指向同一结点
}

//打印链队列
void LinkQueuePrint(LinkQueue* link_q) {
	if (link_q->front == link_q->rear) {
		printf("为空链队列\n");
		return;
	}
	LinkNode* temp = link_q->front->next;  //找到头结点的后继结点
	while (1) {
		printf("%d %c\n", temp->data.num, temp->data.ch);
		if (temp == link_q->rear)
			return;
		temp = temp->next;
	}
}

//链队列入队
void LinkQueueEnter(LinkQueue* link_q, Data d) {
	LinkNode* new_node = CreateNode();
	new_node->data = d;
	link_q->rear->next = new_node;  //将新结点接在尾结点后面
	link_q->rear = new_node;  //将当前尾结点设置为新结点
}

//链队列出队
void LinkQueueDelete(LinkQueue* link_q, Data* d) {
	if (link_q->front == link_q->rear)
		return;
	LinkNode* next = link_q->front->next;
	*d = next->data;
	link_q->front = next->next;  //将头结点后一个结点的后继接在头结点上
	if (next == link_q->rear)  //如果删除的结点为链队列的尾结点，则将rear指向头结点上
		 link_q->rear = link_q->front;
	free(next);
}

int main() {
	LinkQueue link_queue1 = { NULL, NULL };

	LinkQueueInit(&link_queue1);

	Data data1 = { 1, 'a' };
	LinkQueueEnter(&link_queue1, data1);

	LinkQueuePrint(&link_queue1);

	Data data2 = { 0 };
	LinkQueueDelete(&link_queue1, &data2);
	printf("%d %c\n", data2.num, data2.ch);
	LinkQueuePrint(&link_queue1);

	return 0;
}