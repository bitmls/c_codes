#include <stdio.h>
#include <stdlib.h>

// 此处MAX表示两元素之间不互通
#define MAX  32767

typedef struct Graph {
	char* vexs;
	int** arcs;
	int vex_num;
	int arc_num;
}Graph;

typedef struct Edge {
	char vex;
	int weight;
}Edge;

Edge* InitEdge(Graph* G, int index) {
	Edge* edge = (Edge*)malloc(sizeof(Edge) * G->vex_num);
	for (int i = 0; i < G->vex_num; i++) {
		edge[i].vex = G->vexs[index];
		edge[i].weight = G->arcs[index][i];
	}
	return edge;
}

int GetMinEdge(Edge* edge, Graph* G) {
	int index;
	int min = MAX;
	for (int i = 0; i < G->vex_num; i++) {
		if (edge[i].weight < min && edge[i].weight != 0) {
			min = edge[i].weight;
			index = i;
		}
	}
	return index;
}

void Prim(Graph* G, int index) {
	Edge* edge = InitEdge(G, index);
	int min;
	for (int i = 0; i < G->vex_num - 1; i++) {
		min = GetMinEdge(edge, G);
		printf("v%c --> v%c, weight = %d\n", edge[min].vex, G->vexs[min], edge[min].weight);
		edge[min].weight = 0;
		for (int j = 0; j < G->vex_num; j++) {
			if (G->arcs[min][j] < edge[j].weight) {
				edge[j].weight = G->arcs[min][j];
				edge[j].vex = G->vexs[min];
			}
		}
	}
}

Graph* InitGraph(int vex_num) {
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->vexs = (char*)malloc(sizeof(char) * vex_num);
	G->arcs = (int**)malloc(sizeof(int*) * vex_num);
	for (int i = 0; i < vex_num; i++) {
		G->arcs[i] = (int*)malloc(sizeof(int) * vex_num);
	}
	G->vex_num = vex_num;
	G->arc_num = 0;
	return G;
}

void CreateGraph(Graph* G, char* vexs, int* arcs) {
	for (int i = 0; i < G->vex_num; i++) {
		G->vexs[i] = vexs[i];
		for (int j = 0; j < G->vex_num; j++) {
			G->arcs[i][j] = *(arcs + i * G->vex_num + j);
			if (G->arcs[i][j] != 0 && G->arcs[i][j] != MAX)
				G->arc_num++;
		}
	}
	G->arc_num /= 2;
}

void DFS(Graph* G, int* visited, int index) {
	printf("%c ", G->vexs[index]);
	visited[index] = 1;
	for (int i = 0; i < G->vex_num; i++) {
		if (G->arcs[index][i] != 0 && G->arcs[index][i] != MAX && !visited[i]) {
			DFS(G, visited, i);
		}
	}
}

int main() {
	Graph* graph = InitGraph(6);
	int arcs[6][6] = {
		0, 6, 1, 5, MAX, MAX,
		6, 0, 5, MAX, 3, MAX,
		1, 5, 0, 5, 6, 4,
		5, MAX, 5, 0, MAX, 2,
		MAX, 3, 6, MAX, 0, 6,
		MAX, MAX, 4, 2, 6, 0
	};
	int* visited = (int*)malloc(sizeof(int) * 6);
	for (int i = 0; i < 6; i++)
		visited[i] = 0;

	CreateGraph(graph, "123456", arcs);

	//DFS(graph, visited, 0);

	Prim(graph, 0);

	return 0;
}