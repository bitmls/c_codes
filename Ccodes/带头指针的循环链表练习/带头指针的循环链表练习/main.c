#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//装备类型
typedef struct Equipment {
	int weapon;
	int experience;
	int health_point;
	int gold;
}Equipment;

//双向循环带头链表
typedef struct EquNode {
	Equipment data;
	struct EquNode* prev;
	struct EquNode* next;
}EquNode;

//创建一个结点
EquNode* CreateNode(Equipment equ) {
	EquNode* new_node = (EquNode*)malloc(sizeof(EquNode));
	new_node->data = equ;
	new_node->prev = NULL;
	new_node->next = NULL;
	printf("结点创建成功\n");
	return new_node;
}

//链表初始化
EquNode* ListInit() {
	EquNode* phead = (EquNode*)malloc(sizeof(EquNode));
	phead->data.weapon = 0;
	phead->data.experience = 0;
	phead->data.health_point = 0;
	phead->data.gold = 0;
	phead->prev = phead;  //将前驱和后继都指向自己
	phead->next = phead;
	printf("初始化成功\n");
	return phead;
}

//销毁链表
void ListDestory(EquNode** pphead) {
	EquNode* cur = (*pphead)->next;  //从头指针的后继结点开始，依次删除直到指向自身
	EquNode* next = NULL;
	while (cur != *pphead) {
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(*pphead);
	*pphead = NULL;
	printf("销毁成功\n");
}

//打印链表
void PrintList(const EquNode* phead) {
	EquNode* cur = phead->next;
	printf("\n");
	while (cur != phead) {
		printf("%d %d %d %d\n", cur->data.weapon, cur->data.experience, cur->data.health_point, cur->data.gold);
		cur = cur->next;
	}
	printf("打印结束\n\n");
}

//尾插结点
void ListEndInsertNode(EquNode* phead, Equipment equ) {
	assert(phead != NULL);
	EquNode* new_node = CreateNode(equ);
	EquNode* tail = phead->prev;  //通过头结点找到尾结点
	tail->next = new_node;  //将尾结点的后继置为新结点
	new_node->prev = tail;  //将新结点的前驱置为尾结点
	new_node->next = phead;  //将新结点的后继置为头结点
	phead->prev = new_node;  //将头结点的前驱置为新结点
	printf("结点插入成功\n");
}

//头插结点
void ListHeadInsertNode(EquNode* phead, Equipment equ) {
	assert(phead != NULL);
	EquNode* new_node = CreateNode(equ);
	EquNode* first = phead->next;  //通过头结点找到第一个结点
	first->prev = new_node;  //将当时的一个结点与新结点连接
	new_node->next = first;
	new_node->prev = phead;  //将新结点与头结点连接
	phead->next = new_node;
	printf("结点插入成功\n");
}

//尾删结点
void ListEndDeleteNode(EquNode* phead) {
	assert(phead != NULL);  //头结点不为空
	assert(phead->next != phead);  //链表不为空
	EquNode* tail = phead->prev;
	EquNode* prev = tail->prev;
	prev->next = phead;  //将头结点与尾结点前一点连接
	phead->prev = prev;
	free(tail);
	tail = NULL;
	printf("结点删除成功\n");
}

//头删结点
void ListHeadDeleteNode(EquNode* phead) {
	assert(phead != NULL);
	assert(phead->prev != phead);
	EquNode* first = phead->next;
	EquNode* next = first->next;
	phead->next = next;  //将头结点与第一结点的后一结点连接
	next->prev = phead;
	free(first);
	first = NULL;
	printf("结点删除成功\n");
}

//查找结点值中某个值为多少的结点，并返回结点指针
EquNode* ListFindByEqu(EquNode* phead, Equipment equ) {
	EquNode* cur = phead->next;
	while (cur != phead) {
		if (cur->data.weapon == equ.weapon)  //根据唯一标准判定
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//在指定pos前插入一个结点
void ListPosInsertNode(EquNode* pos, Equipment equ) {
	assert(pos != NULL);
	EquNode* new_node = CreateNode(equ);
	EquNode* prev = pos->prev;  //pos的上一个结点
	pos->prev = new_node;  //将new_node与pos连接起来
	new_node->next = pos;
	prev->next = new_node;  //将prev与new_node连接起来
	new_node->prev = prev;
	printf("结点插入成功\n");
}

//删除pos指定的结点
void ListPosDeleteNode(EquNode* pos) {
	assert(pos != NULL);
	EquNode* next = pos->next;
	EquNode* prev = pos->prev;
	next->prev = prev;  //将pos的后继结点与pos的前驱结点连接起来
	prev->next = next;
	free(pos);
	pos = NULL;
	printf("pos结点删除成功\n");
}

//计算链表长度
int ListLength(EquNode* phead) {
	int len = 0;
	EquNode* cur = phead->next;
	while (cur != phead) {
		len++;
		cur = cur->next;
	}
	return len;
}

int main() {
	EquNode* equ_list = ListInit();

	Equipment equ1 = { 1, 100, 100, 0 };
	ListEndInsertNode(equ_list, equ1);

	Equipment equ2 = { 2, 50, 200, 50 };
	ListHeadInsertNode(equ_list, equ2);
	PrintList(equ_list);

	ListEndDeleteNode(equ_list);
	PrintList(equ_list);

	Equipment equ3 = { 3, 150, 70, 100 };
	ListEndInsertNode(equ_list, equ3);
	PrintList(equ_list);

	ListHeadDeleteNode(equ_list);
	PrintList(equ_list);

	ListPosInsertNode(ListFindByEqu(equ_list, equ3), equ1);
	PrintList(equ_list);

	ListPosDeleteNode(ListFindByEqu(equ_list, equ3));
	PrintList(equ_list);

	printf("链表长度为%d\n", ListLength(equ_list));

	ListDestory(&equ_list);

	return 0;
}