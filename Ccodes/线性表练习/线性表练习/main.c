#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LENGTH  3

typedef struct {
	float p;  //����
	int e;  //ָ��
}Polynomial;

typedef struct {
	Polynomial* elem;  //����̬����
	int length;  //�����ܳ���
	int capacity;  //���������
}SqList;


//��ʼ�����Ա�
void InitList(SqList* list, int capacity) {
	list->elem = (Polynomial*)malloc(capacity * sizeof(Polynomial));
	list->length = 0;
	list->capacity = capacity;
}

//�ͷ����Ա��ڴ�
void FreeList(SqList* list) {
	free(list->elem);
	list->elem = NULL;
	list->length = 0;
	list->capacity = 0;
}

//�����Ա��ڲ���Ԫ��
void InsertElem(SqList* list, int index, float p, int e) {
	if (index < 0 || index > list->length) {
		printf("����λ�ò�����\n");
		return;
	}

	//�ж��Ƿ���Ҫ����
	if (list->length == list->capacity) {
		Polynomial* newElem = (Polynomial*)realloc(list->elem, (list->capacity + 2) * sizeof(Polynomial));
		if (newElem == NULL) {
			printf("�ڴ����ʧ��\n");
			return;
		}
		printf("���ݳɹ�\n");
		list->elem = newElem;
		list->capacity += 2;
	}

	//��index��Ԫ��λ������ƶ�1λ
	for (int i = list->length; i > index; i--) {
		list->elem[i + 1] = list->elem[i];
	}

	//���������ݲ����Ӧindexλ��
	list->elem[index].p = p;
	list->elem[index].e = e;
	
	//���鳤�ȶ�Ӧ����1
	list->length++;
}

//ɾ�����Ա��ڵ�Ԫ��
void DeleteElem(SqList* list, int index) {
	if (index < 0 || index >= list->length) {
		printf("ɾ��λ�ò��Ϸ�\n");
		return;
	}

	//����Ӧ�±�λ�õ�Ԫ�غ������Ԫ����ǰ��һλ
	for (int i = index; i < list->length; i++) {
		list->elem[i] = list->elem[i + 1];
	}
	list->length--;
	printf("ɾ���ɹ�\n");

	//����������������鳤�ȴ�3������2���ռ�ɾ��
	if (list->capacity - list->length >= 3) {
		Polynomial* newElem = (Polynomial*)realloc(list->elem, (list->capacity - 2) * sizeof(Polynomial));
		if (newElem == NULL) {
			printf("�ڴ��ط���ʧ��\n");
			return;
		}
		list->elem = newElem;
		list->capacity -= 2;
		printf("�ڴ�ռ���ٳɹ�\n");
	}
}

//��ȡ����ĳ������
float GetListP(const SqList* list, int index) {
	return list->elem[index].p;
}

//��ȡ����ĳ��ָ��
int GetListE(const SqList* list, int index) {
	return list->elem[index].e;
}

//��ӡ���Ա��ڵ�Ԫ��
void PrintList(const SqList* list) {
	for (int i = 0; i < list->length; i++) {
		printf("%.2f ", list->elem[i].p);
		printf("%d\n", list->elem[i].e);
	}
}

//��������������ʽ
float CalcFunc(SqList* list, float x) {
	float ret = 0;
	for (int i = 0; i < list->length; i++) {
		ret += list->elem[i].p * pow(x, list->elem[i].e);
	}
	return ret;
}

int main() {
	SqList list1;

	InitList(&list1, 3);

	InsertElem(&list1, 0, 5, 7);
	InsertElem(&list1, 1, 3, 2);
	InsertElem(&list1, 2, 2, 1);
	InsertElem(&list1, 3, 6, 0);

	PrintList(&list1);

	DeleteElem(&list1, 1);
	DeleteElem(&list1, 1);

	PrintList(&list1);

	printf("%f\n", CalcFunc(&list1, 1));

	printf("%f %d\n", GetListP(&list1, 0), GetListE(&list1, 0));

	FreeList(&list1);

	return 0;
}