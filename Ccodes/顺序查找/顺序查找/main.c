#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	int* data;
	int length;
	int num;
}List;

List* InitList(int length) {
	List* list = (List*)malloc(sizeof(List));
	list->data = (int*)malloc(sizeof(int) * length);
	list->length = length;
	list->num = 0;
}

void ListAdd(List* list, int data) {
	if (list->num >= list->length)
		return;
	list->data[list->num] = data;
	list->num = list->num + 1;
}

int ListSearch(List* list, int key) {
	for (int i = 0; i < list->length; i++) {
		if (list->data[i] == key)
			return i;
	}
	return -1;
}

void PrintList(List* list) {
	for (int i = 0; i < list->num; i++) {
		printf("%d ", list->data[i]);
	}
}

int main() {
	List* list = InitList(5);
	int data[5] = { 1,5,2,3,4 };
	for (int i = 0; i < list->length; i++) {
		ListAdd(list, data[i]);
	}
	PrintList(list);
	printf("\n%d\n", ListSearch(list, 5));

	return 0;
}