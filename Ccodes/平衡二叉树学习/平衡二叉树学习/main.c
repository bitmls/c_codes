#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
	int data;
	int height;
	struct AVLNode* lchild;
	struct AVLNode* rchild;
}AVLNode;

AVLNode* CreateAVLNode(int data) {
	AVLNode* new_node = (AVLNode*)malloc(sizeof(AVLNode));
	new_node->data = data;
	new_node->height = 0;
	new_node->lchild = NULL;
	new_node->rchild = NULL;
	return new_node;
}

// ��ȡ��ǰ���ĸ߶ȣ����node��Ϊ�շ��ظ߶ȣ����򷵻�0
int GetHeight(AVLNode* node) {
	return node ? node->height : 0;
}

// ��ȡ���������ֵ
int Max(int x1, int x2) {
	return x1 > x2 ? x1 : x2;
}

// LL��ת
void LL_Rotation(AVLNode* node, AVLNode** root) {
	AVLNode* temp = node->lchild;  // �������ӱ���
	node->lchild = temp->rchild;
	temp->rchild = node;
	node->height = Max(GetHeight(node->lchild), GetHeight(node->rchild)) + 1;
	temp->height = Max(GetHeight(temp->lchild), GetHeight(temp->rchild)) + 1;
	*root = temp;
}

// RR��ת
void RR_Rotation(AVLNode* node, AVLNode** root) {
	AVLNode* temp = node->rchild;  // �������Һ���
	node->rchild = temp->lchild;
	temp->lchild = node;
	node->height = Max(GetHeight(node->lchild), GetHeight(node->rchild)) + 1;
	temp->height = Max(GetHeight(temp->lchild), GetHeight(temp->rchild)) + 1;
	*root = temp;
}

void AVLInsert(AVLNode** T, int data) {
	if (*T == NULL)
		*T = CreateAVLNode(data);
	else if ((*T)->data == data)
		return;
	else if (data < (*T)->data) {
		AVLInsert(&(*T)->lchild, data);
		// �õ���ǰ�ڵ����������ĸ߶�
		int LHeight = GetHeight((*T)->lchild);
		int RHeight = GetHeight((*T)->rchild);
		// �жϸ߶Ȳ�
		if (LHeight - RHeight == 2) {  // �����������߶Ȳ����2ʱ����Ҫ������ת����
			if (data < (*T)->lchild->data) {  // ����dataֵС�������ӵĽڵ�
				// LL����
				LL_Rotation(*T, T);
			}
			else {
				// LR����
				RR_Rotation((*T)->lchild, &(*T)->lchild);
				LL_Rotation(*T, T);
			}
		}
	}
	else {
		AVLInsert(&(*T)->rchild, data);
		// �õ���ǰ�ڵ����������ĸ߶�
		int LHeight = GetHeight((*T)->lchild);
		int RHeight = GetHeight((*T)->rchild);
		// �жϸ߶Ȳ�
		if (RHeight - LHeight == 2) {  // �����������߶Ȳ����2ʱ����Ҫ������ת����
			if (data > (*T)->rchild->data) {  // ����dataֵ�������Һ��ӵĽڵ�
				// RR����
				RR_Rotation(*T, T);
			}
			else {
				// RL����
				LL_Rotation((*T)->rchild, &(*T)->rchild);
				RR_Rotation(*T, T);
			}
		}
	}
	(*T)->height = Max(GetHeight((*T)->lchild), GetHeight((*T)->rchild)) + 1;  // ���¸߶�
}

void PreOrder(AVLNode* T) {
	if (T) {
		printf("%d ", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

int main() {
	AVLNode* avl_tree = NULL;
	int data[5] = { 1,8,6,7,10 };
	for (int i = 0; i < 5; i++) {
		AVLInsert(&avl_tree, data[i]);
	}
	PreOrder(avl_tree);

	return 0;
}