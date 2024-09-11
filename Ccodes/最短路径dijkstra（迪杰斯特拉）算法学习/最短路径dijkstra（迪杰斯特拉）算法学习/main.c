#include <stdio.h>
#include <stdlib.h>

#define MAX  32767

typedef struct Graph {
	char* vexs;
	int** arcs;
	int vex_num;
	int arc_num;
}Graph;

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

int GetMin(int* d, int* s, Graph* G) {
	int min = MAX;
	int index;
	for (int i = 0; i < G->vex_num; i++) {
		if (!s[i] && d[i] < min) {
			min = d[i];
			index = i;
		}
	}
	return index;
}

void Dijkstra(Graph* G, int index) {
	// 创建辅助数组
	int* s = (int*)malloc(sizeof(int) * G->vex_num);
	int* p = (int*)malloc(sizeof(int) * G->vex_num);
	int* d = (int*)malloc(sizeof(int) * G->vex_num);
	// 初始化辅助数组
	for (int i = 0; i < G->vex_num; i++) {
		if (i == index)
			s[i] = 1;
		else
			s[i] = 0;
		if (G->arcs[index][i] > 0 && G->arcs[index][i] != MAX)
			p[i] = index;
		else
			p[i] = -1;
		d[i] = G->arcs[index][i];
	}
	for (int i = 0; i < G->vex_num - 1; i++) {
		int index = GetMin(d, s, G);
		s[index] = 1;
		for (int j = 0; j < G->vex_num; j++) {
			if (!s[j] && d[index] + G->arcs[index][j] < d[j]) {
				d[j] = d[index] + G->arcs[index][j];
				p[j] = index;
			}
		}
	}
	for (int i = 0; i < G->vex_num; i++) {
		printf("%d %d %d\n", s[i], p[i], d[i]);
	}
}

int main() {
	Graph* G = InitGraph(7);
	int arcs[7][7] = {
		0, 12, MAX, MAX, MAX, 16, 14,
		12, 0, 10, MAX, MAX, 7, MAX,
		MAX, 10, 0, 3, 5, 6, MAX,
		MAX, MAX, 3, 0, 4, MAX, MAX,
		MAX, MAX, 5, 4, 0, 2, 8,
		16, 7, 6, MAX, 2, 0, 9,
		14, MAX, MAX, MAX, 8, 9, 0
	};

	CreateGraph(G, "1234567", arcs);

	int* visited = (int*)malloc(sizeof(int) * G->vex_num);
	for (int i = 0; i < G->vex_num; i++)
		visited[i] = 0;

	//DFS(G, visited, 0);

	Dijkstra(G, 0);

	return 0;
}