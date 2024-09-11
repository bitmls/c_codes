#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
	char data;
	struct TreeNode* l_child, * r_child, * parent;
	int l_tag, r_tag;
}TreeNode;

// ����һ�����ڵ�
TreeNode* CreateTreeNode(char data) {
	TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
	new_node->data = data;
	new_node->l_child = NULL;
	new_node->r_child = NULL;
	new_node->parent = NULL;
	new_node->l_tag = 0;
	new_node->r_tag = 0;
}

// ������
void CreateTree(TreeNode** tree, char* data, int* index, TreeNode* parent) {
	char ch = data[*index];  // ����ǰ����ȡ��
	*index += 1;  // ÿִ��һ������+1
	if (ch == '#') {
		return;
	}
	TreeNode* new_node = CreateTreeNode(ch);
	new_node->parent = parent;
	*tree = new_node;  // �������õĽ�㸳ֵ����
	CreateTree(&(*tree)->l_child, data, index, *tree);
	CreateTree(&(*tree)->r_child, data, index, *tree);
}

// �������
void PreOrder(TreeNode* T) {
	if (T == NULL)
		return;
	PreOrder(T->l_child);
	PreOrder(T->r_child);
}

// ����������
void MidThreadTree(TreeNode* T, TreeNode** pre) {
	if (T) {
		MidThreadTree(T->l_child, pre);
		// do something
		if (T->l_child == NULL) {
			T->l_tag = 1;
			T->l_child = *pre;
		}
		if (*pre != NULL && (*pre)->r_child == NULL) {
			(*pre)->r_tag = 1;
			(*pre)->r_child = T;
		}
		*pre = T;  // ��preָ��ָ��Ľڵ��Ϊ��ǰ���Ľڵ�
		MidThreadTree(T->r_child, pre);
	}
}

// ����������
void PreThreadTree(TreeNode* T, TreeNode** pre) {
	if (T) {
		if (T->l_child == NULL) {
			T->l_tag = 1;
			T->l_child = *pre;
		}
		if ((*pre) != NULL && (*pre)->r_child == NULL) {
			(*pre)->r_tag = 1;
			(*pre)->r_child = T;
		}
		*pre = T;
		if(T->l_tag == 0)  // �ж��Ƿ��Ѿ������������Ѿ����������������������������
			PreThreadTree(T->l_child, pre);
		PreThreadTree(T->r_child, pre);
	}
}

// ����������
void PostThreadTree(TreeNode* T, TreeNode** pre) {
	if (T) {
		PostThreadTree(T->l_child, pre);
		PostThreadTree(T->r_child, pre);
		if (T->l_child == NULL) {
			T->l_tag = 1;
			T->l_child = *pre;
		}
		if (*pre != NULL && (*pre)->r_child == NULL) {
			(*pre)->r_tag = 1;
			(*pre)->r_child = T;
		}
		*pre = T;
	}
}

TreeNode* MidGetFirst(TreeNode* T) {
	while (T->l_tag == 0)
		T = T->l_child;
	return T;
}

TreeNode* MidGetNext(TreeNode* node) {
	if (node->r_tag == 1)
		return node->r_child;
	else
		return MidGetFirst(node->r_child);
}

TreeNode* PreGetNext(TreeNode* node) {
	if (node->r_tag == 1 || node->l_tag == 1)
		return node->r_child;
	else
		return node->l_child;
}

TreeNode* PostGetFirst(TreeNode* T) {
	while (T->l_tag == 0)
		T = T->l_child;
	if (T->r_tag == 0)
		return PostGetFirst(T->r_child);
	return T;
}

TreeNode* PostGetNext(TreeNode* node) {
	if (node->r_tag == 1)
		return node->r_child;
	else {
		// �Ǹ��ڵ�
		if (node->parent == NULL)
			return NULL;
		// ���Һ���
		else if (node->parent->r_child == node)
			return node->parent;
		// ������
		else {
			if (node->parent->l_tag == 0)
				return PostGetFirst(node->parent->r_child);
			else
				return node->parent;
		}
	}
}

int main() {
	TreeNode* tree;
	char* data = "ABD##E##C##";
	int index = 0;
	CreateTree(&tree, data, &index, NULL);
	PreOrder(tree);

	// ����������
	//TreeNode* pre = NULL;
	//MidThreadTree(tree, &pre);
	//pre->r_tag = 1;
	//pre->r_child = NULL;

	//for (TreeNode* node = MidGetFirst(tree); node != NULL; node = MidGetNext(node)) {
	//	printf("%c ", node->data);
	//}
	//printf("\n");

	//// ����������
	//TreeNode* pre = NULL;
	//PreThreadTree(tree, &pre);
	//pre->r_tag = 1;
	//pre->r_child = NULL;

	//for (TreeNode* node = tree; node != NULL; node = PreGetNext(node)) {
	//	printf("%c ", node->data);
	//}
	//printf("\n");

	// ����������
	TreeNode* pre = NULL;
	PostThreadTree(tree, &pre);
	// �������������pre�ڵ�ָ����ڵ㣬�����ÿ�
	for (TreeNode* node = PostGetFirst(tree); node != NULL; node = PostGetNext(node)) {
		printf("%c ", node->data);
	}
	printf("\n");

	return 0;
}