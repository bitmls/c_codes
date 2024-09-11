#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LENGTH  3

typedef struct {
	float p;  //参数
	int e;  //指数
}Polynomial;

typedef struct {
	Polynomial* elem;  //管理动态数组
	int length;  //数组总长度
	int capacity;  //数组的容量
}SqList;


//初始化线性表
void InitList(SqList* list, int capacity) {
	list->elem = (Polynomial*)malloc(capacity * sizeof(Polynomial));
	list->length = 0;
	list->capacity = capacity;
}

//释放线性表内存
void FreeList(SqList* list) {
	free(list->elem);
	list->elem = NULL;
	list->length = 0;
	list->capacity = 0;
}

//向线性表内插入元素
void InsertElem(SqList* list, int index, float p, int e) {
	if (index < 0 || index > list->length) {
		printf("插入位置不合适\n");
		return;
	}

	//判断是否需要扩容
	if (list->length == list->capacity) {
		Polynomial* newElem = (Polynomial*)realloc(list->elem, (list->capacity + 2) * sizeof(Polynomial));
		if (newElem == NULL) {
			printf("内存分配失败\n");
			return;
		}
		printf("扩容成功\n");
		list->elem = newElem;
		list->capacity += 2;
	}

	//将index后元素位置向后移动1位
	for (int i = list->length; i > index; i--) {
		list->elem[i + 1] = list->elem[i];
	}

	//将输入数据插入对应index位置
	list->elem[index].p = p;
	list->elem[index].e = e;
	
	//数组长度对应增长1
	list->length++;
}

//删除线性表内的元素
void DeleteElem(SqList* list, int index) {
	if (index < 0 || index >= list->length) {
		printf("删除位置不合法\n");
		return;
	}

	//将对应下标位置的元素后的所有元素向前移一位
	for (int i = index; i < list->length; i++) {
		list->elem[i] = list->elem[i + 1];
	}
	list->length--;
	printf("删除成功\n");

	//如果数组容量比数组长度大3，将后2个空间删除
	if (list->capacity - list->length >= 3) {
		Polynomial* newElem = (Polynomial*)realloc(list->elem, (list->capacity - 2) * sizeof(Polynomial));
		if (newElem == NULL) {
			printf("内存重分配失败\n");
			return;
		}
		list->elem = newElem;
		list->capacity -= 2;
		printf("内存空间减少成功\n");
	}
}

//获取其中某个参数
float GetListP(const SqList* list, int index) {
	return list->elem[index].p;
}

//获取其中某个指数
int GetListE(const SqList* list, int index) {
	return list->elem[index].e;
}

//打印线性表内的元素
void PrintList(const SqList* list) {
	for (int i = 0; i < list->length; i++) {
		printf("%.2f ", list->elem[i].p);
		printf("%d\n", list->elem[i].e);
	}
}

//计算这个函数表达式
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