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

// 获取当前树的高度，如果node不为空返回高度，否则返回0
int GetHeight(AVLNode* node) {
	return node ? node->height : 0;
}

// 获取二者中最大值
int Max(int x1, int x2) {
	return x1 > x2 ? x1 : x2;
}

// LL旋转
void LL_Rotation(AVLNode* node, AVLNode** root) {
	AVLNode* temp = node->lchild;  // 将其左孩子保存
	node->lchild = temp->rchild;
	temp->rchild = node;
	node->height = Max(GetHeight(node->lchild), GetHeight(node->rchild)) + 1;
	temp->height = Max(GetHeight(temp->lchild), GetHeight(temp->rchild)) + 1;
	*root = temp;
}

// RR旋转
void RR_Rotation(AVLNode* node, AVLNode** root) {
	AVLNode* temp = node->rchild;  // 保存其右孩子
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
		// 拿到当前节点左右子树的高度
		int LHeight = GetHeight((*T)->lchild);
		int RHeight = GetHeight((*T)->rchild);
		// 判断高度差
		if (LHeight - RHeight == 2) {  // 当左右子树高度差大于2时，需要进行旋转调整
			if (data < (*T)->lchild->data) {  // 输入data值小于树左孩子的节点
				// LL调整
				LL_Rotation(*T, T);
			}
			else {
				// LR调整
				RR_Rotation((*T)->lchild, &(*T)->lchild);
				LL_Rotation(*T, T);
			}
		}
	}
	else {
		AVLInsert(&(*T)->rchild, data);
		// 拿到当前节点左右子树的高度
		int LHeight = GetHeight((*T)->lchild);
		int RHeight = GetHeight((*T)->rchild);
		// 判断高度差
		if (RHeight - LHeight == 2) {  // 当左右子树高度差大于2时，需要进行旋转调整
			if (data > (*T)->rchild->data) {  // 输入data值大于树右孩子的节点
				// RR调整
				RR_Rotation(*T, T);
			}
			else {
				// RL调整
				LL_Rotation((*T)->rchild, &(*T)->rchild);
				RR_Rotation(*T, T);
			}
		}
	}
	(*T)->height = Max(GetHeight((*T)->lchild), GetHeight((*T)->rchild)) + 1;  // 更新高度
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