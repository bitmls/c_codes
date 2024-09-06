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
	for (int i = 0; i < length; i++) {
		list->data[i] = 0;
	}
	list->length = length;
	list->num = 1;
}

void ListAdd(List* list, int data) {
	if (list->num >= list->length)
		return;
	list->data[list->num] = data;
	list->num = list->num + 1;
}

int ListSearch(List* list, int key) {
	int i;
	list->data[0] = key;
	for (i = (list->length) - 1; list->data[i] != key; i--);
	return i;
}

void PrintList(List* list) {
	for (int i = 0; i < list->num; i++) {
		printf("%d ", list->data[i]);
	}
}

int main() {
	List* list = InitList(5);
	int data[4] = { 1,5,2,3 };
	for (int i = 0; i < list->length - 1; i++) {
		ListAdd(list, data[i]);
	}
	PrintList(list);
	printf("\n%d\n", ListSearch(list, 2));
	PrintList(list);

	return 0;
}