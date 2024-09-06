#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Graph {
	char* vexs;  // 顶点
	int** arcs;  // 边，邻接矩阵
	int vex_num;  // 顶点个数
	int arc_num;  // 边的个数
}Graph;

typedef struct LinkQueueNode {
	int data;
	struct LinkQueueNode* next;
}LinkQueueNode;

typedef struct LinkQueue {
	LinkQueueNode* head, * tail;
}LinkQueue;

LinkQueueNode* CreateLinkQueueNode(int data) {
	LinkQueueNode* new_node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void InitLinkQueue(LinkQueue* Q) {
	Q->head = Q->tail = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	Q->head->next = NULL;
}

bool IsEmptyQueue(LinkQueue* Q) {
	if (Q->head == Q->tail)
		return true;
	return false;
}

void EnQueue(LinkQueue* Q, int data) {
	LinkQueueNode* new_node = CreateLinkQueueNode(data);
	Q->tail->next = new_node;
	Q->tail = new_node;
}

LinkQueueNode* DeQueue(LinkQueue* Q) {
	if (IsEmptyQueue(Q))
		return NULL;
	LinkQueueNode* node = Q->head->next;
	Q->head->next = node->next;
	if (Q->tail == node)  // 如果删除元素为最后一个元素
		Q->tail = Q->head;
	return node;
}

Graph* InitGraph(int vex_num) {
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->vexs = (char*)malloc(sizeof(char) * vex_num);
	G->arcs = (int**)malloc(sizeof(int*) * vex_num);
	for (int i = 0; i < vex_num; i++) {
		G->arcs[i] = (int*)malloc(sizeof(int) * vex_num);  // 为二维数组每一行开辟空间
	}
	G->vex_num = vex_num;
	G->arc_num = 0;  // 将边的数量初识为0
	return G;
}

void CreateGraph(Graph* G, char* vexs, int* arcs) {
	for (int i = 0; i < G->vex_num; i++) {
		G->vexs[i] = vexs[i];
		for (int j = 0; j < G->vex_num; j++) {
			G->arcs[i][j] = *(arcs + i * G->vex_num + j);
			if (G->arcs[i][j] != 0)
				G->arc_num++;
		}
	}
	G->arc_num /= 2;  // 无向图
}

// depth-first search
void DFS(Graph* G, int* visited, int index) {
	printf("%c ", G->vexs[index]);
	visited[index] = 1;
	for (int i = 0; i < G->vex_num; i++) {
		if (G->arcs[index][i] == 1 && visited[i] == 0) {
			DFS(G, visited, i);
		}
	}
}

// breadth-first search
void BFS(Graph* G, int* visited, int index) {
	LinkQueue* Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	InitLinkQueue(Q);
	printf("%c ", G->vexs[index]);
	visited[index] = 1;
	EnQueue(Q, index);
	while (!IsEmptyQueue(Q)) {
		LinkQueueNode* node = DeQueue(Q);
		int i = node->data;
		for (int j = 0; j < G->vex_num; j++) {
			if (G->arcs[i][j] == 1 && !visited[j]) {
				printf("%c ", G->vexs[j]);
				visited[j] = 1;
				EnQueue(Q, j);
			}
		}
	}
}

int main() {
	Graph* graph = InitGraph(5);
	int* visited = (int*)malloc(sizeof(int) * graph->vex_num);
	for (int i = 0; i < graph->vex_num; i++)
		visited[i] = 0;
	int arcs[5][5] = {
		0,1,1,1,0,
		1,0,1,1,1,
		1,1,0,0,0,
		1,1,0,0,1,
		0,1,0,1,0
	};
	CreateGraph(graph, "ABCDE", (int*)arcs);

	//DFS(graph, visited, 0);

	BFS(graph, visited, 0);

	return 0;
}