#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ���Ľڵ�
typedef struct TreeNode {
	char data;
	struct TreeNode* l_child, * r_child;
}TreeNode;

// ���еĽڵ�
typedef struct QueueNode {
	TreeNode* data;
	struct QueueNode* next;
}QueueNode;

// ��ʽ����
typedef struct LinkQueue {
	struct QueueNode* front, * rear;
}LinkQueue;

// ����һ�����ڵ�
TreeNode* CreateTreeNode(char data) {
	TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
	new_node->data = data;
	new_node->l_child = NULL;
	new_node->r_child = NULL;
}

// ������
void CreateTree(TreeNode** tree, char* data, int* index) {
	char ch = data[*index];  // ����ǰ����ȡ��
	*index += 1;  // ÿִ��һ������+1
	if (ch == '#') {
		return;
	}
	TreeNode* new_node = CreateTreeNode(ch);
	*tree = new_node;  // �������õĽ�㸳ֵ����
	CreateTree(&(*tree)->l_child, data, index);
	CreateTree(&(*tree)->r_child, data, index);
}

// ����һ�����нڵ�
QueueNode* CreateQueueNode(TreeNode* data) {
	QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

// ��ʼ������
void QueueInit(LinkQueue* Q) {
	Q->front = Q->rear = CreateQueueNode(NULL);
	Q->front->next = NULL;  // ��ͷ�ڵ�ָ�����ÿ�
}

// �ж϶����Ƿ�Ϊ��
bool IsEmptyQueue(LinkQueue* Q) {
	if (Q->front == Q->rear)
		return true;
	return false;
}

// Ԫ�����
void EnQueue(LinkQueue* Q, TreeNode* data) {
	QueueNode* new_node = CreateQueueNode(data);
	Q->rear->next = new_node;
	Q->rear = new_node;  // ��βָ��ָ���½ڵ�
}

// Ԫ�س���
QueueNode* DeQueue(LinkQueue* Q) {
	if (IsEmptyQueue(Q)) {
		printf("����Ϊ��\n");
		return NULL;
	}
	QueueNode* node = Q->front->next;  // ��¼�µ�һ���ڵ�
	Q->front->next = node->next;  // ���ڶ����ڵ����ͷ�ڵ����
	if (node == Q->rear) {  // �������Ԫ��Ϊ��βԪ��
		Q->rear = Q->front;  // ��β�ڵ�ӵ�ͷ�ڵ�
	}
	return node;
}

// �������
void PreOrder(TreeNode* tree) {
	if (tree == NULL) {
		return;
	}
	printf("%c ", tree->data);
	PreOrder(tree->l_child);
	PreOrder(tree->r_child);
}

// �������
void MidOrder(TreeNode* tree) {
	if (tree == NULL) {
		return;
	}
	MidOrder(tree->l_child);
	printf("%c ", tree->data);
	MidOrder(tree->r_child);
}

// �������
void PostOrder(TreeNode* tree) {
	if (tree == NULL) {
		return;
	}
	PostOrder(tree->l_child);
	PostOrder(tree->r_child);
	printf("%c ", tree->data);
}

// �������
void LevelOrderTraverse(TreeNode* tree, LinkQueue* Q) {
	EnQueue(Q, tree);  // �����ڵ����
	while (!IsEmptyQueue(Q)) {  // �ж϶����Ƿ�Ϊ��
		QueueNode* node = DeQueue(Q);  // ����ͷ����
		printf("%c ", node->data->data);
		if (node->data->l_child)  // �������Ԫ�����Ӳ�Ϊ��
			EnQueue(Q, node->data->l_child);  // ���������
		if (node->data->r_child)  // �������Ԫ���Һ��Ӳ�Ϊ��
			EnQueue(Q, node->data->r_child);  // ���Һ������
		free(node);
	}
}

int main(int argc, char* argv[]) {
	TreeNode* bi_tree;
	char* data = "ABC##D##E##";
	int index = 0;

	CreateTree(&bi_tree, data, &index);

	//PreOrder(bi_tree);
	//printf("\n");
	//MidOrder(bi_tree);
	//printf("\n");
	//PostOrder(bi_tree);
	//printf("\n");
	
	LinkQueue Q;
	QueueInit(&Q);
	LevelOrderTraverse(bi_tree, &Q);

	return 0;
}