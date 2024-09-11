#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE  50

typedef struct {
	int num;
	char ch;
}Data;

typedef struct DoubleStack {
	Data data[MAX_SIZE];
	int top0;
	int top1;
}DoubleStack;

//栈初始化
void DoubleStackInit(DoubleStack* stack) {
	stack->top0 = -1;
	stack->top1 = MAX_SIZE - 1;
}

//在对应栈内插入元素
bool DoubleStackPush(DoubleStack* stack, Data data, int stack_number) {
	if (stack->top0 + 1 == stack->top1)  //如果满栈
		return false;
	switch (stack_number) {
	case 0: stack->data[++stack->top0] = data; break;
	case 1: stack->data[--stack->top1] = data; break;
	}
	return true;
}

//在对应栈内删除元素
bool DoubleStackPop(DoubleStack* stack, Data* data, int stack_number) {
	switch (stack_number) {
	case 0:
		if (stack->top0 == -1)
			return false;
		*data = stack->data[stack->top0--];
		break;
	case 1:
		if (stack->top1 == MAX_SIZE - 1)
			return false;
		*data = stack->data[stack->top1++];
		break;
	}
	return true;
}


int main() {
	DoubleStack dbl_stack1;
	DoubleStackInit(&dbl_stack1);

	Data data1 = { 1, 'a' };
	DoubleStackPush(&dbl_stack1, data1, 0);

	Data data2 = { 0 };
	DoubleStackPop(&dbl_stack1, &data2, 0);

	printf("%d %c\n", data2.num, data2.ch);

	return 0;
}