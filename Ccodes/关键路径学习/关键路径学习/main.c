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
		if (G->arcs[index][i] > 0 && G->arcs[index][i] != MAX && visited[i] == 0)
			DFS(G, visited, i);
	}
}

int* FindIndegrees(Graph* G) {
	int* indegrees = (int*)malloc(sizeof(int) * G->vex_num);
	for (int i = 0; i < G->vex_num; i++)
		indegrees[i] = 0;
	for (int i = 0; i < G->vex_num; i++) {
		for (int j = 0; j < G->vex_num; j++) {
			if (G->arcs[i][j] > 0 && G->arcs[i][j] != MAX)
				indegrees[j]++;
		}
	}
	return indegrees;
}

int* TopologicalSort(Graph* G) {
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
			if (G->arcs[vex][i] > 0 && G->arcs[vex][i] != MAX) {
				indegrees[i] -= 1;
				if (indegrees[i] == 0)
					Push(stack, i);
			}
		}
	}
	for (int i = 0; i < G->vex_num; i++) {
		printf("%d ", top[i]);
	}
	return top;
}

int GetTopIndex(int* top, Graph* G, int i) {
	int j;
	for (j = 0; j < G->vex_num; j++)
		if (top[j] == i)
			break;
	return j;
}

void CriticalPath(Graph* G) {
	int* top = TopologicalSort(G);
	int* early = (int*)malloc(sizeof(int) * G->vex_num);  // 最早发生时间
	int* late = (int*)malloc(sizeof(int) * G->vex_num);  // 最晚发生时间
	for (int i = 0; i < G->vex_num; i++) {
		early[i] = 0;
		late[i] = 0;
	}
	// 计算最早发生时间
	for (int i = 0; i < G->vex_num; i++) {
		int max = 0;
		for (int j = 0; j < G->vex_num; j++) {
			if (G->arcs[j][top[i]] > 0 && G->arcs[j][top[i]] != MAX) {
				int index = GetTopIndex(top, G, j);
				if (early[index] + G->arcs[j][top[i]] > max)
					max = early[index] + G->arcs[j][top[i]];
			}
		}
		early[i] = max;
	}
	printf("\n");
	for (int i = 0; i < G->vex_num; i++) {
		printf("%d ", early[i]);
	}
	printf("\n");
	// 计算最晚发生时间
	late[G->vex_num - 1] = early[G->vex_num - 1];
	for (int i = (G->vex_num) - 2; i >= 0; i--) {
		int min = MAX;
		for (int j = 0; j < G->vex_num; j++) {
			if (G->arcs[top[i]][j] > 0 && G->arcs[top[i]][j] != MAX) {
				int index = GetTopIndex(top, G, j);
				if (late[index] - G->arcs[top[i]][j] < min)
					min = late[index] - G->arcs[top[i]][j];
			}
		}
		late[i] = min;
	}
	for (int i = 0; i < G->vex_num; i++) {
		printf("%d ", late[i]);
	}
	printf("\n");
	for (int i = 0; i < G->vex_num; i++) {
		for (int j = 0; j < G->vex_num; j++) {
			if (G->arcs[i][j] > 0 && G->arcs[i][j] != MAX) {
				int start = GetTopIndex(top, G, i);
				int end = GetTopIndex(top, G, j);
				if (late[end] - G->arcs[i][j] - early[start] == 0)
					printf("start = %d, end = %d\n", i, j);
			}
		}
	}
}

int main() {
	Graph* G = InitGraph(9);
	int arcs[9][9] = {
		0,   6,   4,   5,   MAX, MAX, MAX, MAX, MAX,
		MAX, 0,   MAX, MAX, 1,   MAX, MAX, MAX, MAX,
		MAX, MAX, 0,   MAX, 1,   MAX, MAX, MAX, MAX,
		MAX, MAX, MAX, 0,   MAX, 2,   MAX, MAX, MAX,
		MAX, MAX, MAX, MAX, 0,   MAX, 9,   7,   MAX,
		MAX, MAX, MAX, MAX, MAX, 0,   MAX, 4,   MAX,
		MAX, MAX, MAX, MAX, MAX, MAX, 0,   MAX, 2,
		MAX, MAX, MAX, MAX, MAX, MAX, MAX, 0,   4,
		MAX, MAX, MAX, MAX, MAX, MAX, MAX, MAX, 0
	};
	CreateGraph(G, "012345678", arcs);
	
	int* visited = (int*)malloc(sizeof(int) * G->vex_num);
	for (int i = 0; i < G->vex_num; i++)
		visited[i] = 0;
	DFS(G, visited, 0);
	printf("\n");

	//TopologicalSort(G);

	CriticalPath(G);

	return 0;
}
