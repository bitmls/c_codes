#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE  50

typedef struct{
	int num;
	char ch;
}Data;

typedef struct Stack{
	Data data[MAX_SIZE];
	int top;  //用于栈顶指针
}Stack;


//栈的初始化
void StackInit(Stack* s) {
	s->top = -1;  //初始时为-1，空栈
}

//判断是否为空栈，为空则返回true，否则返回false
bool IsEmptyStack(Stack s)  {
	if (s.top == -1)
		return true;
	else
		return false;
}

//插入元素为新的栈顶元素
bool StackPush(Stack* s, Data d) {
	//满栈
	if (s->top == MAX_SIZE - 1)
		return false;
	s->top++;
	s->data[s->top] = d;
	return true;
}

//将顶部数据移出栈，用d返回其值
bool StackPop(Stack* s, Data* d) {
	//如果此时为空栈返回false
	if (s->top == -1)
		return false;
	*d = *(s->data);
	s->top--;
	return true;
}

//读取栈顶元素
bool StackGetTop(Stack s, Data* d) {
	if (s.top == -1)
		return false;
	*d = s.data[s.top];
	return true;
}

int main() {
	Stack stack1;
	StackInit(&stack1);

	if (IsEmptyStack(stack1))
		printf("栈为空\n");
	else
		printf("栈不为空\n");

	Data data1 = { 1, 'a' };
	StackPush(&stack1, data1);

	if (IsEmptyStack(stack1))
		printf("栈为空\n");
	else
		printf("栈不为空\n");

	//Data data2 = { 0 };
	//StackPop(&stack1, &data2);

	//if (IsEmptyStack(stack1))
	//	printf("栈为空\n");
	//else
	//	printf("栈不为空\n");

	Data data3 = { 0 };
	StackGetTop(stack1, &data3);
	printf("%d %c\n", data3.num, data3.ch);

	return 0;
}