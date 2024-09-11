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

void Floyd(Graph* G) {
	int* d = (int*)malloc(sizeof(int) * G->vex_num);
	int* p = (int*)malloc(sizeof(int) * G->vex_num);
	for (int i = 0; i < G->vex_num; i++) {
		for (int j = 0; j < G->vex_num; j++) {
			*(d + i * G->vex_num + j) = G->arcs[i][j];
			if (G->arcs[i][j] > 0 && G->arcs[i][j] != MAX)
				*(p + i * G->vex_num + j) = i;
			else
				*(p + i * G->vex_num + j) = -1;
		}
	}

	for (int i = 0; i < G->vex_num; i++) {  // 将所有元素添加进去
		for (int j = 0; j < G->vex_num; j++) {
			for (int k = 0; k < G->vex_num; k++) {
				if (*(d + i * G->vex_num + j) + *(d + j * G->vex_num + k) < *(d + i * G->vex_num + k)) {
					*(d + i * G->vex_num + k) = *(d + i * G->vex_num + j) + *(d + j * G->vex_num + k);
					*(p + i * G->vex_num + k) = *(p + j * G->vex_num + k);
				}
			}
		}
	}

	for (int i = 0; i < G->vex_num; i++) {
		for (int j = 0; j < G->vex_num; j++) {
			printf("%5d ", *(d + i * G->vex_num + j));
		}
		printf("\n");
	}
	for (int i = 0; i < G->vex_num; i++) {
		for (int j = 0; j < G->vex_num; j++) {
			printf("%3d ", *(p + i * G->vex_num + j));
		}
		printf("\n");
	}
}

int main() {
	Graph* G = InitGraph(4);
	int arcs[4][4] = {
		0, 1, MAX, 3,
		1, 0, 2, 2,
		MAX, 2, 0, 8,
		3, 2, 8, 0
	};
	CreateGraph(G, "1234", arcs);

	int* visited = (int*)malloc(sizeof(int) * G->vex_num);
	for (int i = 0; i < G->vex_num; i++)
		visited[i] = 0;
	//DFS(G, visited, 0);

	Floyd(G);

	return 0;
}