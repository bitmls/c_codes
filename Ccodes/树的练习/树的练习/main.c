#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree {
	char data;
	struct BiTree* l_child, * r_child;
}BiTree;

void CreateTree(BiTree** tree, char* data, int* index) {
	char ch = data[*index];  // 取出当前索引的数据
	*index += 1;  // 每次访问索引+1
	if (ch == '#') {  // 接收数据为 '#' 时，该节点为NULL
		*tree = NULL;
		return;
	}
	BiTree* new_node = (BiTree*)malloc(sizeof(BiTree));
	new_node->data = ch;
	new_node->l_child = NULL;
	new_node->r_child = NULL;
	*tree = new_node;  // 将创建的新节点赋给树

	// 先序遍历创建左子树
	CreateTree(&(*tree)->l_child, data, index);
	// 先序遍历创建右子树
	CreateTree(&(*tree)->r_child, data, index);
}

void PreOrder(BiTree* tree) {
	if (tree == NULL) {
		return;
	}
	// 访问根节点
	printf("%c ", tree->data);
	// 先序遍历左孩子
	PreOrder(tree->l_child);
	// 先序遍历右孩子
	PreOrder(tree->r_child);
}

void MidOrder(BiTree* tree) {
	if (tree == NULL) {
		return;
	}
	// 中序遍历左孩子
	MidOrder(tree->l_child);
	// 访问根节点
	printf("%c ", tree->data);
	// 中序遍历右孩子
	MidOrder(tree->r_child);
}

void PostOrder(BiTree* tree) {
	if (tree == NULL) {
		return;
	}
	// 后序遍历左孩子
	PostOrder(tree->l_child);
	// 后序遍历右孩子
	PostOrder(tree->r_child);
	// 访问根节点
	printf("%c ", tree->data);
}

int main() {
	BiTree* bi_tree;  // 创建二叉树根节点
	char data_test[100];
	int index_test = 0;

	scanf("%s", data_test);

	CreateTree(&bi_tree, data_test, &index_test);

	printf("先序遍历结果：");
	PreOrder(bi_tree);
	printf("\n");

	printf("中序遍历结果：");
	MidOrder(bi_tree);
	printf("\n");

	printf("后续遍历结果：");
	PostOrder(bi_tree);
	printf("\n");

	return 0;
}




//#include <stdio.h>
//#include <stdlib.h>
//
//// 创建二叉树结构
//typedef struct BiTreeNode {
//	int data;
//	struct BiTreeNode* lchild, * rchild;
//}BiTreeNode;
//
//// 创建一个新节点
//BiTreeNode* CreateNode(int data) {
//	BiTreeNode* new_node = (BiTreeNode*)malloc(sizeof(BiTreeNode));
//	new_node->data = data;
//	new_node->lchild = NULL;
//	new_node->rchild = NULL;
//	return new_node;
//}
//
//// 先序遍历二叉树
//void PreBiTree(BiTreeNode* tree) {
//	if (tree == NULL) {
//		return;
//	}
//	printf("%d ", tree->data);
//	PreBiTree(tree->lchild);
//	PreBiTree(tree->rchild);
//}
//
//// 中序遍历二叉树
//void MidBiTree(BiTreeNode* tree) {
//	if (tree == NULL) {
//		return;
//	}
//	MidBiTree(tree->lchild);
//	printf("%d ", tree->data);
//	MidBiTree(tree->rchild);
//}
//
//// 后序遍历二叉树
//void PostBiTree(BiTreeNode* tree) {
//	if (tree == NULL) {
//		return;
//	}
//	PostBiTree(tree->lchild);
//	PostBiTree(tree->rchild);
//	printf("%d ", tree->data);
//}
//
//// 先序创建二叉树
//void CreateBiTree(BiTreeNode** tree) {
//	int n;
//	scanf("%d", &n);
//	if (n == 0) {
//		*tree == NULL;
//		return;
//	} else {
//		*tree = CreateNode(n);
//		// 先序遍历创建当前节点的左子树
//		CreateBiTree(&(*tree)->lchild);
//		// 先序遍历创建当前节点的右子树
//		CreateBiTree(&(*tree)->rchild);
//	}
//}
//
//int main() {
//	BiTreeNode* bi_tree;
//	CreateBiTree(&bi_tree);
//
//	// 使用先序遍历
//	PreBiTree(bi_tree);
//	printf("\n");
//
//	// 使用中序遍历
//	MidBiTree(bi_tree);
//	printf("\n");
//
//	// 使用后序遍历
//	PostBiTree(bi_tree);
//	printf("\n");
//
//	return 0;
//}