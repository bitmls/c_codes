#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int num;
	char ch;
}Data;

//��ʽ�洢�ڵ�
typedef struct {
	Data data;
	struct LinkNode *next;
}LinkNode;

//��ʽ����
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;


//�������
LinkNode* CreateNode() {
	LinkNode* new_node = (LinkNode*)malloc(sizeof(LinkNode));
	new_node->next = NULL;
	return new_node;
}

//�����г�ʼ��
void LinkQueueInit(LinkQueue* link_q) {
	link_q->front = CreateNode();  //����ͷ���
	link_q->rear = link_q->front;  //β�����ͷ���ָ��ͬһ���
}

//��ӡ������
void LinkQueuePrint(LinkQueue* link_q) {
	if (link_q->front == link_q->rear) {
		printf("Ϊ��������\n");
		return;
	}
	LinkNode* temp = link_q->front->next;  //�ҵ�ͷ���ĺ�̽��
	while (1) {
		printf("%d %c\n", temp->data.num, temp->data.ch);
		if (temp == link_q->rear)
			return;
		temp = temp->next;
	}
}

//���������
void LinkQueueEnter(LinkQueue* link_q, Data d) {
	LinkNode* new_node = CreateNode();
	new_node->data = d;
	link_q->rear->next = new_node;  //���½�����β������
	link_q->rear = new_node;  //����ǰβ�������Ϊ�½��
}

//�����г���
void LinkQueueDelete(LinkQueue* link_q, Data* d) {
	if (link_q->front == link_q->rear)
		return;
	LinkNode* next = link_q->front->next;
	*d = next->data;
	link_q->front = next->next;  //��ͷ����һ�����ĺ�̽���ͷ�����
	if (next == link_q->rear)  //���ɾ���Ľ��Ϊ�����е�β��㣬��rearָ��ͷ�����
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