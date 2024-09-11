#include <stdio.h>
#include <stdlib.h>

#define NUM  5

typedef struct HashList {
	int num;
	char* data;
}HashList;

HashList* InitHashList() {
	HashList* list = (HashList*)malloc(sizeof(HashList));
	list->num = 0;
	list->data = (char*)malloc(sizeof(char) * NUM);
	for (int i = 0; i < NUM; i++)
		list->data[i] = 0;
	return list;
}

int Hash(int data) {
	return data % NUM;
}

void Put(HashList* list, char data) {
	int index = Hash(data);
	if (list->data[index] != 0) {
		int count = 1;
		while (list->data[index] != 0) {
			index = Hash(Hash(data) + count);
			count++;
		}
	}
	list->data[index] = data;
}

int main() {
	HashList* list = InitHashList();
	Put(list, 'A');
	Put(list, 'F');
	Put(list, 'B');
	printf("%c\n", list->data[0]);
	printf("%c\n", list->data[1]);
	printf("%c\n", list->data[2]);
	return 0;
}