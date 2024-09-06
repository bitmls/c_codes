#include <stdio.h>
#include <stdlib.h>

#define MAX  32767

typedef struct Graph {
	char* vexs;
	int** arcs;
	int vex_num;
	int arc_num;
}Graph;

typedef struct StackNode {
	int data;
	struct StackNode* next;
}StackNode;

StackNode* CreateStackNode(int data) {
	StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

StackNode* InitStack() {
	StackNode* stack = CreateStackNode(-1);
	return stack;
}

int IsEmptyStack(StackNode* stack) {
	if (stack->next == NULL)
		return 1;
	return 0;
}

void Push(StackNode* stack, int data) {
	StackNode* new_node = CreateStackNode(data);
	new_node->next = stack->next;
	stack->next = new_node;
}

int Pop(StackNode* stack) {
	if (IsEmptyStack(stack) == 1)
		return -1;
	StackNode* node = stack->next;
	stack->next = node->next;
	return node->data;
}

Graph* InitGraph(int vex_num) {
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->vexs = (char*)malloc(sizeof(char) * vex_num);
	G->arcs = (int**)malloc(sizeof(int*) * vex_num);
	for (int i = 0; i < vex_num; i++)
		G->arcs[i] = (int*)malloc(sizeof(int) * vex_num);
	G->vex_num = vex_num;
	G->arc_num = 0;
	return G;
}

void CreateGraph(Graph* G, char* vexs, int* arcs) {
	for (int i = 0; i < G->vex_num; i++) {
		G->vexs[i] = vexs[i];
		for (int j = 0; j < G->vex_num; j++) {
			G->arcs[i][j] = *(arcs + i * G->vex_num + j);
			if (G->arcs[i][j] != MAX && G->arcs[i][j] > 0)
				G->arc_num++;
		}
	}
	G->arc_num /= 2;
}

void DFS(Graph* G, int* visited, int index) {
	printf("%c ", G->vexs[index]);
	visited[index] = 1;
	for (int i = 0; i < G->vex_num; i++) {
		if (G->arcs[index][i] != 0 && visited[i] == 0)
			DFS(G, visited, i);
	}
}

int* FindIndegrees(Graph* G) {
	int* indegrees = (int*)malloc(sizeof(int) * G->vex_num);
	for (int i = 0; i < G->vex_num; i++)
		indegrees[i] = 0;
	for (int i = 0; i < G->vex_num; i++) {
		for (int j = 0; j < G->vex_num; j++) {
			if (G->arcs[i][j] > 0)
				indegrees[j]++;
		}
	}
	return indegrees;
}

void TopologicalSort(Graph* G) {
	int index = 0;
	int* top = (int*)malloc(sizeof(int) * G->vex_num);
	int* indegrees = FindIndegrees(G);
	StackNode* stack = InitStack();
	for (int i = 0; i < G->vex_num; i++)
		if (indegrees[i] == 0)
			Push(stack, i);
	while (!IsEmptyStack(stack)) {
		int vex = Pop(stack);
		top[index++] = vex;
		for (int i = 0; i < G->vex_num; i++) {
			if (G->arcs[vex][i] > 0) {
				indegrees[i] -= 1;
				if (indegrees[i] == 0)
					Push(stack, i);
			}
		}
	}
	for (int i = 0; i < G->vex_num; i++) {
		printf("%d ", top[i] + 1);
	}
}

int main() {
	Graph* G = InitGraph(6);
	int arcs[6][6] = {
		0, 1, 1, 1, 0, 0,
		0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 1, 0,
		0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 1, 0
	};
	CreateGraph(G, "123456", arcs);

	int* visited = (int*)malloc(sizeof(int) * G->vex_num);
	for (int i = 0; i < G->vex_num; i++)
		visited[i] = 0;
	DFS(G, visited, 0);
	printf("\n");

	TopologicalSort(G);

	return 0;
}



//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX  32767
//
//typedef struct Graph {
//	char* vexs;
//	int** arcs;
//	int vex_num;
//	int arc_num;
//}Graph;
//
//typedef struct StackNode {
//	int data;
//	struct StackNode* next;
//}StackNode;
//
//StackNode* CreateStackNode(int data) {
//	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
//	node->data = data;
//	node->next = NULL;
//	return node;
//}
//
//void Push(StackNode* head, int data) {
//	StackNode* node = CreateStackNode(data);
//	node->next = head->next;
//	head->next = node;
//}
//
//int IsEmptyStack(StackNode* head) {
//	if (head->next == NULL)
//		return 1;
//	return 0;
//}
//
//int Pop(StackNode* head) {
//	if (IsEmptyStack(head))
//		return -1;
//	StackNode* node = head->next;
//	head->next = node->next;
//	return node->data;
//}
//
//int* FindInDegrees(Graph* G) {
//	int* in_degrees = (int*)malloc(sizeof(int) * G->vex_num);
//	for (int i = 0; i < G->vex_num; i++)
//		in_degrees[i] = 0;
//	for (int i = 0; i < G->vex_num; i++) {
//		for (int j = 0; j < G->vex_num; j++) {
//			if (G->arcs[i][j])
//				in_degrees[j] += 1;
//		}
//	}
//	return in_degrees;
//}
//
//void TopologicSort(Graph* G) {
//	int index = 0;
//	int* top = (int*)malloc(sizeof(int) * G->vex_num);
//	int* in_degrees = FindInDegrees(G);
//	StackNode* stack = CreateStackNode(index);
//	for (int i = 0; i < G->vex_num; i++) {
//		if (in_degrees[i] == 0) {
//			Push(stack, i);
//		}
//	}
//	while (!IsEmptyStack(stack)) {
//		int vex = Pop(stack);
//		top[index++] = vex;
//		for (int i = 0; i < G->vex_num; i++) {
//			if (G->arcs[vex][i]) {
//				in_degrees[i]--;
//				if (in_degrees[i] == 0)
//					Push(stack, i);
//			}
//		}
//	}
//	for (int i = 0; i < G->vex_num; i++) {
//		printf("%d ", top[i]);
//	}
//}
//
//Graph* InitGraph(int vex_num) {
//	Graph* G = (Graph*)malloc(sizeof(Graph));
//	G->vexs = (char*)malloc(sizeof(char) * vex_num);
//	G->arcs = (int**)malloc(sizeof(int*) * vex_num);
//	for (int i = 0; i < vex_num; i++)
//		G->arcs[i] = (int*)malloc(sizeof(int) * vex_num);
//	G->vex_num = vex_num;
//	G->arc_num = 0;
//	return G;
//}
//
//void CreateGraph(Graph* G, char* vexs, int* arcs) {
//	for (int i = 0; i < G->vex_num; i++) {
//		G->vexs[i] = vexs[i];
//		for (int j = 0; j < G->vex_num; j++) {
//			G->arcs[i][j] = *(arcs + i * G->vex_num + j);
//			if (G->arcs[i][j] > 0 && G->arcs[i][j] != MAX)
//				G->arc_num++;
//		}
//	}
//	G->arc_num /= 2;
//}
//
//void DFS(Graph* G, int* visited, int index) {
//	printf("%c ", G->vexs[index]);
//	visited[index] = 1;
//	for (int i = 0; i < G->vex_num; i++) {
//		if (G->arcs[index][i] > 0 && G->arcs[index][i] != MAX && !visited[i])
//			DFS(G, visited, i);
//	}
//}
//
//int main() {
//	Graph* G = InitGraph(6);
//	int arcs[6][6] = {
//		0, 1, 1, 1, 0, 0,
//		0, 0, 0, 0, 0, 0,
//		0, 1, 0, 0, 1, 0,
//		0, 0, 0, 0, 1, 0,
//		0, 0, 0, 0, 0, 0,
//		0, 0, 0, 1, 1, 0
//	};
//	CreateGraph(G, "123456", arcs);
//
//	int* visited = (int*)malloc(sizeof(int) * G->vex_num);
//	for (int i = 0; i < G->vex_num; i++)
//		visited[i] = 0;
//	DFS(G, visited, 0);
//	printf("\n");
//
//	TopologicSort(G);
//
//	return 0;
//}