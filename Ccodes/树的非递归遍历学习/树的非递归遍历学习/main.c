#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BiTreeNode {
	char data;
	struct BiTreeNode* l_child, * r_child;
	bool flag;
}BiTreeNode;

typedef struct StackNode {
	BiTreeNode* data;
	struct StackNode* next;
}StackNode;

// ����һ���������ڵ�
BiTreeNode* CreateBiTreeNode(char data) {
	BiTreeNode* new_node = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	new_node->data = data;
	new_node->l_child = NULL;
	new_node->r_child = NULL;
	new_node->flag = false;
	return new_node;
}

// ������
void CreateTree(BiTreeNode** tree, char* data, int* index) {
	char ch = data[*index];  // ����ǰ����ȡ��
	*index += 1;  // ÿִ��һ������+1
	if (ch == '#') {
		return;
	}
	BiTreeNode* new_node = CreateBiTreeNode(ch);
	*tree = new_node;  // �������õĽ�㸳ֵ����
	CreateTree(&(*tree)->l_child, data, index);
	CreateTree(&(*tree)->r_child, data, index);
}

// �������
void PreOrder(BiTreeNode* tree) {
	if (tree == NULL) {
		return;
	}
	printf("%c ", tree->data);
	PreOrder(tree->l_child);
	PreOrder(tree->r_child);
}

// ����һ��ջ�ڵ�
StackNode* CreateStackNode(BiTreeNode* data) {
	StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

// ѹջ
void StackPush(BiTreeNode* data, StackNode* S) {
	StackNode* new_node = CreateStackNode(data);
	new_node->next = S->next;  // ��ͷ�ڵ��Ľڵ�����½ڵ��
	S->next = new_node;  // ���½ڵ����ͷ�ڵ��
}

// �ж�ջ�Ƿ�Ϊ��
bool StackIsEmpty(StackNode* S) {
	if (S->next == NULL)
		return true;
	return false;
}

// ��ȡջ��Ԫ��
StackNode* GetStackTop(StackNode* S) {
	if (S->next == NULL)
		return NULL;
	return S->next;
}

// ��ջ
StackNode* StackPop(StackNode* S) {
	if (StackIsEmpty(S))
		return NULL;
	StackNode* node = S->next;
	S->next = node->next;  // ��ͷ�ڵ��ڶ����ڵ����ͷ�ڵ��
	return node;
}

// ʹ��ջ��ʵ���������
void StackPreOrder(BiTreeNode* tree) {
	BiTreeNode* node = tree;
	// ����ջ
	StackNode* S = CreateStackNode(NULL);
	while (node || !StackIsEmpty(S)) {  // ���ڵ㲻Ϊ�ջ���ջ��Ϊ��ʱ
		if (node) {
			printf("%c ", node->data);
			StackPush(node, S);
			node = node->l_child;
		}
		else {
			node = StackPop(S)->data;
			node = node->r_child;
		}
	}
}

// ʹ��ջ��ʵ���������
void StackMidOrder(BiTreeNode* tree) {
	BiTreeNode* node = tree;
	// ����ջ
	StackNode* S = CreateStackNode(NULL);
	while (node || !StackIsEmpty(S)) {
		if (node) {
			StackPush(node, S);
			node = node->l_child;
		}
		else {
			node = StackPop(S)->data;
			printf("%c ", node->data);
			node = node->r_child;
		}
	}
}

// ʹ��ջ��ʵ�ֺ������
void StackPostOrder(BiTreeNode* tree) {
	BiTreeNode* node = tree;
	// ����ջ
	StackNode* S = CreateStackNode(NULL);
	while (node || !StackIsEmpty(S)) {
		if (node) {
			StackPush(node, S);
			node = node->l_child;
		}
		else {
			// ���ж�ջ��Ԫ�ص��������Ƿ�Ϊ�գ�Ϊ�պ�����ջ
			BiTreeNode* top = GetStackTop(S)->data;
			if (top->r_child && top->r_child->flag == 0) {  // ջ��Ԫ�ص��Һ��Ӳ�Ϊ�ղ��ҽ����־Ϊ0
				top = top->r_child;
				StackPush(top, S);
				node = top->l_child;
			}
			else {
				top = StackPop(S)->data;
				printf("%c ", top->data);
				top->flag = 1;
			}
		}
	}
}

int main() {
	BiTreeNode* bi_tree;

	char* data = "ABD##E##C##";
	int index = 0;

	CreateTree(&bi_tree, data, &index);
	PreOrder(bi_tree);
	printf("\n");
	StackPreOrder(bi_tree);
	printf("\n");
	StackMidOrder(bi_tree);
	printf("\n");
	StackPostOrder(bi_tree);
	printf("\n");

	return 0;
}