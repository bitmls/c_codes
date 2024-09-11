#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BinarySearchTreeNode {
	int data;
	struct BinarySearchTreeNode* lchild, * rchild;
}BSTNode;

BSTNode* CreateBSTNode(int data) {
	BSTNode* new_node = (BSTNode*)malloc(sizeof(BSTNode));
	new_node->data = data;
	new_node->lchild = NULL;
	new_node->rchild = NULL;
}

BSTNode* BSTSearch(BSTNode* T, int data) {
	if (T) {
		if (T->data == data)
			return T;
		else if (data > T->data)
			return BSTSearch(T->rchild, data);
		else
			return BSTSearch(T->lchild, data);
	}
	else
		return NULL;
}

void BSTInsert(BSTNode** T, int data) {
	if (*T == NULL)
		*T = CreateBSTNode(data);
	else {
		if (data == (*T)->data)
			return;
		else if (data > (*T)->data)
			BSTInsert(&(*T)->rchild, data);
		else
			BSTInsert(&(*T)->lchild, data);
	}
}

void PreOrder(BSTNode* T) {
	if (T == NULL)
		return;
	printf("%d ", T->data);
	PreOrder(T->lchild);
	PreOrder(T->rchild);
}

int main() {
	BSTNode* bst = NULL;
	int data[6] = { 8, 6, 10, 9, 11, 23 };
	for (int i = 0; i < 6; i++)
		BSTInsert(&bst, data[i]);
	PreOrder(bst);

	return 0;
}