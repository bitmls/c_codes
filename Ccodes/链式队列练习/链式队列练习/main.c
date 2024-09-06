#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ���нڵ�����
typedef struct QueueNode {
	char data;
	struct QueueNode* next;
}QueueNode;

// ������������
typedef struct LinkQueue {
	struct QueueNode* front, * rear;  // �洢ͷָ���βָ�룬����Ϊ���нڵ�ָ��
}LinkQueue;

// ��ʼ������
void QueueInit(LinkQueue* Q) {
	Q->front = Q->rear = (QueueNode*)malloc(sizeof(QueueNode));  // ����ͷ�ڵ㣬ͷָ����βָ�붼ָ��ͷ���
	Q->front->next = NULL;  // �����е�ͷ�ڵ��next��Ϊ��
}

// �ж϶����Ƿ�Ϊ��
bool IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) {  // ��ͷָ����βָ����ָ�ڵ���ͬʱ������Ϊ��
		printf("����Ϊ��\n");
		return true;
	}
	return false;
}

// �����ڵ�
QueueNode* CreateNode(char data) {
	QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

// ���ٽڵ�
void DeleteNode(QueueNode** node) {
	free(*node);
	*node = NULL;
	printf("���ٳɹ�\n");
}

// β��Ԫ��
void QueueInsert(LinkQueue* Q, char data) {
	QueueNode* new_node = CreateNode(data);
	Q->rear->next = new_node;  // �������õ��½����ڶ�β
	Q->rear = new_node;  // ���½����Ϊ��β
	printf("����ɹ�\n");
}

// ͷ��Ԫ��
QueueNode* QueueDelete(LinkQueue* Q) {
	if (IsEmpty(*Q)) { // �������Ϊ��, ����NULL
		return NULL;
	}
	QueueNode* first = Q->front->next;  // ��ͷ�ڵ�ĺ�һλ�����׸���㱣�棬׼������
	Q->front->next = first->next;  // �����еĵڶ�λԪ�ؽ���ͷ��㴦
	if (first == Q->rear) {  // ������ӵ�Ԫ��Ϊ��β
		Q->rear = Q->front;  // ��βָ��ָ��ͷ�ڵ�
	}
	printf("���ӳɹ�\n");
	return first;
}

// ��ӡ����
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