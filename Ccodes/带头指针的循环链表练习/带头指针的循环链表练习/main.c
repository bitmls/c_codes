#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//װ������
typedef struct Equipment {
	int weapon;
	int experience;
	int health_point;
	int gold;
}Equipment;

//˫��ѭ����ͷ����
typedef struct EquNode {
	Equipment data;
	struct EquNode* prev;
	struct EquNode* next;
}EquNode;

//����һ�����
EquNode* CreateNode(Equipment equ) {
	EquNode* new_node = (EquNode*)malloc(sizeof(EquNode));
	new_node->data = equ;
	new_node->prev = NULL;
	new_node->next = NULL;
	printf("��㴴���ɹ�\n");
	return new_node;
}

//�����ʼ��
EquNode* ListInit() {
	EquNode* phead = (EquNode*)malloc(sizeof(EquNode));
	phead->data.weapon = 0;
	phead->data.experience = 0;
	phead->data.health_point = 0;
	phead->data.gold = 0;
	phead->prev = phead;  //��ǰ���ͺ�̶�ָ���Լ�
	phead->next = phead;
	printf("��ʼ���ɹ�\n");
	return phead;
}

//��������
void ListDestory(EquNode** pphead) {
	EquNode* cur = (*pphead)->next;  //��ͷָ��ĺ�̽�㿪ʼ������ɾ��ֱ��ָ������
	EquNode* next = NULL;
	while (cur != *pphead) {
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(*pphead);
	*pphead = NULL;
	printf("���ٳɹ�\n");
}

//��ӡ����
void PrintList(const EquNode* phead) {
	EquNode* cur = phead->next;
	printf("\n");
	while (cur != phead) {
		printf("%d %d %d %d\n", cur->data.weapon, cur->data.experience, cur->data.health_point, cur->data.gold);
		cur = cur->next;
	}
	printf("��ӡ����\n\n");
}

//β����
void ListEndInsertNode(EquNode* phead, Equipment equ) {
	assert(phead != NULL);
	EquNode* new_node = CreateNode(equ);
	EquNode* tail = phead->prev;  //ͨ��ͷ����ҵ�β���
	tail->next = new_node;  //��β���ĺ����Ϊ�½��
	new_node->prev = tail;  //���½���ǰ����Ϊβ���
	new_node->next = phead;  //���½��ĺ����Ϊͷ���
	phead->prev = new_node;  //��ͷ����ǰ����Ϊ�½��
	printf("������ɹ�\n");
}

//ͷ����
void ListHeadInsertNode(EquNode* phead, Equipment equ) {
	assert(phead != NULL);
	EquNode* new_node = CreateNode(equ);
	EquNode* first = phead->next;  //ͨ��ͷ����ҵ���һ�����
	first->prev = new_node;  //����ʱ��һ��������½������
	new_node->next = first;
	new_node->prev = phead;  //���½����ͷ�������
	phead->next = new_node;
	printf("������ɹ�\n");
}

//βɾ���
void ListEndDeleteNode(EquNode* phead) {
	assert(phead != NULL);  //ͷ��㲻Ϊ��
	assert(phead->next != phead);  //����Ϊ��
	EquNode* tail = phead->prev;
	EquNode* prev = tail->prev;
	prev->next = phead;  //��ͷ�����β���ǰһ������
	phead->prev = prev;
	free(tail);
	tail = NULL;
	printf("���ɾ���ɹ�\n");
}

//ͷɾ���
void ListHeadDeleteNode(EquNode* phead) {
	assert(phead != NULL);
	assert(phead->prev != phead);
	EquNode* first = phead->next;
	EquNode* next = first->next;
	phead->next = next;  //��ͷ������һ���ĺ�һ�������
	next->prev = phead;
	free(first);
	first = NULL;
	printf("���ɾ���ɹ�\n");
}

//���ҽ��ֵ��ĳ��ֵΪ���ٵĽ�㣬�����ؽ��ָ��
EquNode* ListFindByEqu(EquNode* phead, Equipment equ) {
	EquNode* cur = phead->next;
	while (cur != phead) {
		if (cur->data.weapon == equ.weapon)  //����Ψһ��׼�ж�
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//��ָ��posǰ����һ�����
void ListPosInsertNode(EquNode* pos, Equipment equ) {
	assert(pos != NULL);
	EquNode* new_node = CreateNode(equ);
	EquNode* prev = pos->prev;  //pos����һ�����
	pos->prev = new_node;  //��new_node��pos��������
	new_node->next = pos;
	prev->next = new_node;  //��prev��new_node��������
	new_node->prev = prev;
	printf("������ɹ�\n");
}

//ɾ��posָ���Ľ��
void ListPosDeleteNode(EquNode* pos) {
	assert(pos != NULL);
	EquNode* next = pos->next;
	EquNode* prev = pos->prev;
	next->prev = prev;  //��pos�ĺ�̽����pos��ǰ�������������
	prev->next = next;
	free(pos);
	pos = NULL;
	printf("pos���ɾ���ɹ�\n");
}

//����������
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

	printf("������Ϊ%d\n", ListLength(equ_list));

	ListDestory(&equ_list);

	return 0;
}