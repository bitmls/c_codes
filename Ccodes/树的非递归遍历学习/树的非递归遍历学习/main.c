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

// 创建一个二叉树节点
BiTreeNode* CreateBiTreeNode(char data) {
	BiTreeNode* new_node = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	new_node->data = data;
	new_node->l_child = NULL;
	new_node->r_child = NULL;
	new_node->flag = false;
	return new_node;
}

// 创建树
void CreateTree(BiTreeNode** tree, char* data, int* index) {
	char ch = data[*index];  // 将当前数据取出
	*index += 1;  // 每执行一次索引+1
	if (ch == '#') {
		return;
	}
	BiTreeNode* new_node = CreateBiTreeNode(ch);
	*tree = new_node;  // 将创建好的结点赋值给树
	CreateTree(&(*tree)->l_child, data, index);
	CreateTree(&(*tree)->r_child, data, index);
}

// 先序遍历
void PreOrder(BiTreeNode* tree) {
	if (tree == NULL) {
		return;
	}
	printf("%c ", tree->data);
	PreOrder(tree->l_child);
	PreOrder(tree->r_child);
}

// 创建一个栈节点
StackNode* CreateStackNode(BiTreeNode* data) {
	StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

// 压栈
void StackPush(BiTreeNode* data, StackNode* S) {
	StackNode* new_node = CreateStackNode(data);
	new_node->next = S->next;  // 将头节点后的节点接在新节点后
	S->next = new_node;  // 将新节点接在头节点后
}

// 判断栈是否为空
bool StackIsEmpty(StackNode* S) {
	if (S->next == NULL)
		return true;
	return false;
}

// 获取栈顶元素
StackNode* GetStackTop(StackNode* S) {
	if (S->next == NULL)
		return NULL;
	return S->next;
}

// 出栈
StackNode* StackPop(StackNode* S) {
	if (StackIsEmpty(S))
		return NULL;
	StackNode* node = S->next;
	S->next = node->next;  // 将头节点后第二个节点接在头节点后
	return node;
}

// 使用栈来实现先序遍历
void StackPreOrder(BiTreeNode* tree) {
	BiTreeNode* node = tree;
	// 创建栈
	StackNode* S = CreateStackNode(NULL);
	while (node || !StackIsEmpty(S)) {  // 当节点不为空或者栈不为空时
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

// 使用栈来实现中序遍历
void StackMidOrder(BiTreeNode* tree) {
	BiTreeNode* node = tree;
	// 创建栈
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

// 使用栈来实现后序遍历
void StackPostOrder(BiTreeNode* tree) {
	BiTreeNode* node = tree;
	// 创建栈
	StackNode* S = CreateStackNode(NULL);
	while (node || !StackIsEmpty(S)) {
		if (node) {
			StackPush(node, S);
			node = node->l_child;
		}
		else {
			// 先判断栈顶元素的右子树是否为空，为空后再入栈
			BiTreeNode* top = GetStackTop(S)->data;
			if (top->r_child && top->r_child->flag == 0) {  // 栈顶元素的右孩子不为空并且进入标志为0
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