#include <stdio.h>

enum color {
	RED,
	BLUE,
	YELLOW,
	GREEN
};

typedef struct Road {
	int color;   // �ܵ���ɫ
	int status;  // �ܵ��ɻ�����
}Road;

Road plane_road[30];
Road dest_road[4][6];

typedef struct Plane {
	int color;
	int used; 
}Plance;

void InitRoad(void) {

}

int main() {
	return 0;
}