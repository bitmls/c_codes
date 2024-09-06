#include <stdio.h>
#include <stdlib.h>


typedef struct HuffmanTreeNode {
	int weight;
	int parent;
	int lchild;
	int rchild;
}HuffmanTreeNode;

typedef struct HFTree {
	HuffmanTreeNode* data;
	int length;
}HFTree;

HFTree* InitHFTree(int* weight, int length) {
	HFTree* T = (HFTree*)malloc(sizeof(HFTree));
	T->data = (HuffmanTreeNode*)malloc(sizeof(HuffmanTreeNode) *  (2 * length - 1));
	T->length = length;
	for (int i = 0; i < length; i++) {
		T->data[i].weight = weight[i];
		T->data[i].parent = 0;
		T->data[i].lchild = -1;
		T->data[i].rchild = -1;
	}
	return T;
}

int* SelectMin(HFTree* T) {
	int min = 10000;
	int second_min = 10000;
	int min_index;
	int second_index;
	for (int i = 0; i < T->length; i++) {
		if (T->data[i].parent == 0) {
			if (T->data[i].weight < min) {
				min = T->data[i].weight;
				min_index = i;
			}
		}
	}
	for (int i = 0; i < T->length; i++) {
		if (T->data[i].parent == 0 && i != min_index) {
			if (T->data[i].weight < second_min) {
				second_min = T->data[i].weight;
				second_index = i;
			}
		}
	}
	int* res = (int*)malloc(sizeof(int) * 2);
	res[0] = min_index;
	res[1] = second_index;
	return res;
}

void CreateHFTree(HFTree* T) {
	int* res;
	int min_index;
	int second_index;
	int len = T->length * 2 - 1;
	for (int i = T->length; i < len; i++) {
		res = SelectMin(T);
		min_index = res[0];
		second_index = res[1];
		T->data[i].lchild = min_index;
		T->data[i].rchild = second_index;
		T->data[i].weight = T->data[min_index].weight + T->data[second_index].weight;
		T->data[i].parent = 0;
		T->data[min_index].parent = i;
		T->data[second_index].parent = i;
		T->length++;
	}
}

void PreOrder(HFTree* T, int index) {
	if (index != -1) {
		printf("%d ", T->data[index].weight);
		PreOrder(T, T->data[index].lchild);
		PreOrder(T, T->data[index].rchild);
	}
}

int main() {
	int weight[] = { 5, 1, 3, 6, 11, 2, 4 };
	HFTree* huffman_tree = InitHFTree(weight, sizeof(weight)/sizeof(int));
	CreateHFTree(huffman_tree);
	PreOrder(huffman_tree, huffman_tree->length - 1);

	return 0;
}