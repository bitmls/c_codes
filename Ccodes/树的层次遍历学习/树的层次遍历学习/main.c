#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 树的节点
typedef struct TreeNode {
	char data;
	struct TreeNode* l_child, * r_child;
}TreeNode;

// 队列的节点
typedef struct QueueNode {
	TreeNode* data;
	struct QueueNode* next;
}QueueNode;

// 链式队列
typedef struct LinkQueue {
	struct QueueNode* front, * rear;
}LinkQueue;

// 创建一个树节点
TreeNode* CreateTreeNode(char data) {
	TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
	new_node->data = data;
	new_node->l_child = NULL;
	new_node->r_child = NULL;
}

// 创建树
void CreateTree(TreeNode** tree, char* data, int* index) {
	char ch = data[*index];  // 将当前数据取出
	*index += 1;  // 每执行一次索引+1
	if (ch == '#') {
		return;
	}
	TreeNode* new_node = CreateTreeNode(ch);
	*tree = new_node;  // 将创建好的结点赋值给树
	CreateTree(&(*tree)->l_child, data, index);
	CreateTree(&(*tree)->r_child, data, index);
}

// 创建一个队列节点
QueueNode* CreateQueueNode(TreeNode* data) {
	QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

// 初始化队列
void QueueInit(LinkQueue* Q) {
	Q->front = Q->rear = CreateQueueNode(NULL);
	Q->front->next = NULL;  // 将头节点指针域置空
}

// 判断队列是否为空
bool IsEmptyQueue(LinkQueue* Q) {
	if (Q->front == Q->rear)
		return true;
	return false;
}

// 元素入队
void EnQueue(LinkQueue* Q, TreeNode* data) {
	QueueNode* new_node = CreateQueueNode(data);
	Q->rear->next = new_node;
	Q->rear = new_node;  // 将尾指针指向新节点
}

// 元素出队
QueueNode* DeQueue(LinkQueue* Q) {
	if (IsEmptyQueue(Q)) {
		printf("队列为空\n");
		return NULL;
	}
	QueueNode* node = Q->front->next;  // 记录下第一个节点
	Q->front->next = node->next;  // 将第二个节点接在头节点后面
	if (node == Q->rear) {  // 如果出队元素为队尾元素
		Q->rear = Q->front;  // 将尾节点接到头节点
	}
	return node;
}

// 先序遍历
void PreOrder(TreeNode* tree) {
	if (tree == NULL) {
		return;
	}
	printf("%c ", tree->data);
	PreOrder(tree->l_child);
	PreOrder(tree->r_child);
}

// 中序遍历
void MidOrder(TreeNode* tree) {
	if (tree == NULL) {
		return;
	}
	MidOrder(tree->l_child);
	printf("%c ", tree->data);
	MidOrder(tree->r_child);
}

// 后序遍历
void PostOrder(TreeNode* tree) {
	if (tree == NULL) {
		return;
	}
	PostOrder(tree->l_child);
	PostOrder(tree->r_child);
	printf("%c ", tree->data);
}

// 层序遍历
void LevelOrderTraverse(TreeNode* tree, LinkQueue* Q) {
	EnQueue(Q, tree);  // 将根节点入队
	while (!IsEmptyQueue(Q)) {  // 判断队列是否为空
		QueueNode* node = DeQueue(Q);  // 将队头出队
		printf("%c ", node->data->data);
		if (node->data->l_child)  // 如果出队元素左孩子不为空
			EnQueue(Q, node->data->l_child);  // 将左孩子入队
		if (node->data->r_child)  // 如果出队元素右孩子不为空
			EnQueue(Q, node->data->r_child);  // 将右孩子入队
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