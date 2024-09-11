#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree {
	char data;
	struct BiTree* l_child, * r_child;
}BiTree;

void CreateTree(BiTree** tree, char* data, int* index) {
	char ch = data[*index];  // ȡ����ǰ����������
	*index += 1;  // ÿ�η�������+1
	if (ch == '#') {  // ��������Ϊ '#' ʱ���ýڵ�ΪNULL
		*tree = NULL;
		return;
	}
	BiTree* new_node = (BiTree*)malloc(sizeof(BiTree));
	new_node->data = ch;
	new_node->l_child = NULL;
	new_node->r_child = NULL;
	*tree = new_node;  // ���������½ڵ㸳����

	// �����������������
	CreateTree(&(*tree)->l_child, data, index);
	// �����������������
	CreateTree(&(*tree)->r_child, data, index);
}

void PreOrder(BiTree* tree) {
	if (tree == NULL) {
		return;
	}
	// ���ʸ��ڵ�
	printf("%c ", tree->data);
	// �����������
	PreOrder(tree->l_child);
	// ��������Һ���
	PreOrder(tree->r_child);
}

void MidOrder(BiTree* tree) {
	if (tree == NULL) {
		return;
	}
	// �����������
	MidOrder(tree->l_child);
	// ���ʸ��ڵ�
	printf("%c ", tree->data);
	// ��������Һ���
	MidOrder(tree->r_child);
}

void PostOrder(BiTree* tree) {
	if (tree == NULL) {
		return;
	}
	// �����������
	PostOrder(tree->l_child);
	// ��������Һ���
	PostOrder(tree->r_child);
	// ���ʸ��ڵ�
	printf("%c ", tree->data);
}

int main() {
	BiTree* bi_tree;  // �������������ڵ�
	char data_test[100];
	int index_test = 0;

	scanf("%s", data_test);

	CreateTree(&bi_tree, data_test, &index_test);

	printf("������������");
	PreOrder(bi_tree);
	printf("\n");

	printf("������������");
	MidOrder(bi_tree);
	printf("\n");

	printf("�������������");
	PostOrder(bi_tree);
	printf("\n");

	return 0;
}




//#include <stdio.h>
//#include <stdlib.h>
//
//// �����������ṹ
//typedef struct BiTreeNode {
//	int data;
//	struct BiTreeNode* lchild, * rchild;
//}BiTreeNode;
//
//// ����һ���½ڵ�
//BiTreeNode* CreateNode(int data) {
//	BiTreeNode* new_node = (BiTreeNode*)malloc(sizeof(BiTreeNode));
//	new_node->data = data;
//	new_node->lchild = NULL;
//	new_node->rchild = NULL;
//	return new_node;
//}
//
//// �������������
//void PreBiTree(BiTreeNode* tree) {
//	if (tree == NULL) {
//		return;
//	}
//	printf("%d ", tree->data);
//	PreBiTree(tree->lchild);
//	PreBiTree(tree->rchild);
//}
//
//// �������������
//void MidBiTree(BiTreeNode* tree) {
//	if (tree == NULL) {
//		return;
//	}
//	MidBiTree(tree->lchild);
//	printf("%d ", tree->data);
//	MidBiTree(tree->rchild);
//}
//
//// �������������
//void PostBiTree(BiTreeNode* tree) {
//	if (tree == NULL) {
//		return;
//	}
//	PostBiTree(tree->lchild);
//	PostBiTree(tree->rchild);
//	printf("%d ", tree->data);
//}
//
//// ���򴴽�������
//void CreateBiTree(BiTreeNode** tree) {
//	int n;
//	scanf("%d", &n);
//	if (n == 0) {
//		*tree == NULL;
//		return;
//	} else {
//		*tree = CreateNode(n);
//		// �������������ǰ�ڵ��������
//		CreateBiTree(&(*tree)->lchild);
//		// �������������ǰ�ڵ��������
//		CreateBiTree(&(*tree)->rchild);
//	}
//}
//
//int main() {
//	BiTreeNode* bi_tree;
//	CreateBiTree(&bi_tree);
//
//	// ʹ���������
//	PreBiTree(bi_tree);
//	printf("\n");
//
//	// ʹ���������
//	MidBiTree(bi_tree);
//	printf("\n");
//
//	// ʹ�ú������
//	PostBiTree(bi_tree);
//	printf("\n");
//
//	return 0;
//}