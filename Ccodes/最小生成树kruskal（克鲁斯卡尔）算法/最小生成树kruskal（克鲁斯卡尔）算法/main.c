#include <stdio.h>
#include <stdlib.h>

#define MAX  32767

typedef struct Graph {
	char* vexs;
	int** arcs;
	int vex_num;
	int arc_num;
}Graph;

typedef struct Edge {
	int start;
	int end;
	int weight;
}Edge;

Edge* InitEdge(Graph* G) {
	int index = 0;
	Edge* edge = (Edge*)malloc(sizeof(Edge) * G->arc_num);
	for (int i = 0; i < G->vex_num; i++) {
		for (int j = i + 1; j < G->vex_num; j++) {
			if (G->arcs[i][j] != MAX) {
				edge[index].start = i;
				edge[index].end = j;
				edge[index].weight = G->arcs[i][j];
				index++;
			}
		}
	}
	return edge;
}

void SortEdge(Edge* edge, Graph* G) {
	Edge temp;
	for (int i = 0; i < G->arc_num - 1; i++) {
		for (int j = 0; j < G->arc_num - i - 1; j++) {
			if (edge[j].weight > edge[j + 1].weight) {
				temp = edge[j];
				edge[j] = edge[j + 1];
				edge[j + 1] = temp;
			}         
		}
	}
}

void Kruskal(Graph* G) {
	int* connected = (int*)malloc(sizeof(int) * G->vex_num);
	for (int i = 0; i < G->vex_num; i++)
		connected[i] = i;
	Edge* edge = InitEdge(G);
	SortEdge(edge, G);
	for (int i = 0; i < G->arc_num; i++) {
		int start = connected[edge[i].start];
		int end = connected[edge[i].end];
		if (start != end) {
			printf("v%c --> v%c weight = %d\n", G->vexs[edge[i].start], G->vexs[edge[i].end], edge[i].weight);
			for (int j = 0; j < G->vex_num; j++) {
				if (connected[j] == end)
					connected[j] = start;
			}
		}
	}
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
			if (G->arcs[i][j] > 0 && G->arcs[i][j] != MAX)
				G->arc_num++;
		}
	}
	G->arc_num /= 2;
}

void DFS(Graph* G, int* visited, int index) {
	printf("%c ", G->vexs[index]);
	visited[index] = 1;
	for (int i = 0; i < G->vex_num; i++) {
		if (G->arcs[index][i] > 0 && G->arcs[index][i] != MAX && !visited[i])
			DFS(G, visited, i);
	}
}

int main() {
	Graph* G = InitGraph(6);
	int arcs[6][6] = {
		0, 6, 1, 5, MAX, MAX,
		6, 0, 5, MAX, 3, MAX,
		1, 5, 0, 5, 6, 4,
		5, MAX, 5, 0, MAX, 2,
		MAX, 3, 6, MAX, 0, 6,
		MAX, MAX, 4, 2, 6, 0
	};

	CreateGraph(G, "123456", arcs);

	int* visited = (int*)malloc(sizeof(int) * G->vex_num);
	for (int i = 0; i < G->vex_num; i++)
		visited[i] = 0;

	//DFS(G, visited, 0);

	Kruskal(G);

	return 0;
}  