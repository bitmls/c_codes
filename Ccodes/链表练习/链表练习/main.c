#include <stdio.h>
#include <stdlib.h>

typedef struct LinkListNode {
	int data;
    struct LinkListNode* next;
}ListNode;

ListNode* CreateNode(int data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	node->next = NULL;
	return node;
}

void PrintList(ListNode* list) {
	ListNode* temp = list->next;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void InsertList(ListNode** list, int data) {
	ListNode* node = CreateNode(data);
	ListNode* temp = (*list)->next;
	if (temp == NULL) {
		(*list)->next = node;
		return;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = node;
}

int main() {
	ListNode* link_list = CreateNode(-1);

	InsertList(&link_list, 1);
	InsertList(&link_list, 2);
	InsertList(&link_list, 3);

	PrintList(link_list);

	return 0;
}