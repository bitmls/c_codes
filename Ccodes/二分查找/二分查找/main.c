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

void PrintList(List* list) {
	for (int i = 0; i < list->num; i++) {
		printf("%d ", list->data[i]);
	}
}

int BinarySearch(List* list, int key) {
	int start = 0;
	int end = list->num - 1;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (list->data[mid] < key)
			start = mid + 1;
		else if (list->data[mid] > key)
			end = mid - 1;
		else
			return mid;
	}
	return -1;
}

int BinarySearchRecursion(List* list, int key, int start, int end) {
	if (start == end) {
		if (list->data[start] == key)
			return start;
		return -1;
	}
	int mid = (start + end) / 2;
	if (key < list->data[mid])
		BinarySearchRecursion(list, key, start, mid - 1);
	else if (key > list->data[mid])
		BinarySearchRecursion(list, key, mid + 1, end);
	else
		return mid;
}

int main() {
	List* list = InitList(5);
	int data[5] = { 1,2,3,4,5 };
	for (int i = 0; i < list->length; i++) {
		ListAdd(list, data[i]);
	}
	PrintList(list);
	//printf("\n%d\n", BinarySearch(list, 8));
	printf("\n%d\n", BinarySearchRecursion(list, 3, 0, list->num));

	return 0;
}