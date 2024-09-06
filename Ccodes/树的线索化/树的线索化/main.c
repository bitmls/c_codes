#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
	char data;
	struct TreeNode* l_child, * r_child, * parent;
	int l_tag, r_tag;
}TreeNode;

// 创建一个树节点
TreeNode* CreateTreeNode(char data) {
	TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
	new_node->data = data;
	new_node->l_child = NULL;
	new_node->r_child = NULL;
	new_node->parent = NULL;
	new_node->l_tag = 0;
	new_node->r_tag = 0;
}

// 创建树
void CreateTree(TreeNode** tree, char* data, int* index, TreeNode* parent) {
	char ch = data[*index];  // 将当前数据取出
	*index += 1;  // 每执行一次索引+1
	if (ch == '#') {
		return;
	}
	TreeNode* new_node = CreateTreeNode(ch);
	new_node->parent = parent;
	*tree = new_node;  // 将创建好的结点赋值给树
	CreateTree(&(*tree)->l_child, data, index, *tree);
	CreateTree(&(*tree)->r_child, data, index, *tree);
}

// 先序遍历
void PreOrder(TreeNode* T) {
	if (T == NULL)
		return;
	PreOrder(T->l_child);
	PreOrder(T->r_child);
}

// 中序线索化
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
		*pre = T;  // 将pre指针指向的节点变为当前树的节点
		MidThreadTree(T->r_child, pre);
	}
}

// 先序线索化
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
		if(T->l_tag == 0)  // 判断是否已经线索化，若已经线索化，则无需继续线索化左孩子
			PreThreadTree(T->l_child, pre);
		PreThreadTree(T->r_child, pre);
	}
}

// 后序线索化
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
		// 是根节点
		if (node->parent == NULL)
			return NULL;
		// 是右孩子
		else if (node->parent->r_child == node)
			return node->parent;
		// 是左孩子
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

	// 中序线索化
	//TreeNode* pre = NULL;
	//MidThreadTree(tree, &pre);
	//pre->r_tag = 1;
	//pre->r_child = NULL;

	//for (TreeNode* node = MidGetFirst(tree); node != NULL; node = MidGetNext(node)) {
	//	printf("%c ", node->data);
	//}
	//printf("\n");

	//// 先序线索化
	//TreeNode* pre = NULL;
	//PreThreadTree(tree, &pre);
	//pre->r_tag = 1;
	//pre->r_child = NULL;

	//for (TreeNode* node = tree; node != NULL; node = PreGetNext(node)) {
	//	printf("%c ", node->data);
	//}
	//printf("\n");

	// 后序线索化
	TreeNode* pre = NULL;
	PostThreadTree(tree, &pre);
	// 后序遍历结束后，pre节点指向根节点，无需置空
	for (TreeNode* node = PostGetFirst(tree); node != NULL; node = PostGetNext(node)) {
		printf("%c ", node->data);
	}
	printf("\n");

	return 0;
}