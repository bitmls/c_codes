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
	int top;  //����ջ��ָ��
}Stack;


//ջ�ĳ�ʼ��
void StackInit(Stack* s) {
	s->top = -1;  //��ʼʱΪ-1����ջ
}

//�ж��Ƿ�Ϊ��ջ��Ϊ���򷵻�true�����򷵻�false
bool IsEmptyStack(Stack s)  {
	if (s.top == -1)
		return true;
	else
		return false;
}

//����Ԫ��Ϊ�µ�ջ��Ԫ��
bool StackPush(Stack* s, Data d) {
	//��ջ
	if (s->top == MAX_SIZE - 1)
		return false;
	s->top++;
	s->data[s->top] = d;
	return true;
}

//�����������Ƴ�ջ����d������ֵ
bool StackPop(Stack* s, Data* d) {
	//�����ʱΪ��ջ����false
	if (s->top == -1)
		return false;
	*d = *(s->data);
	s->top--;
	return true;
}

//��ȡջ��Ԫ��
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
		printf("ջΪ��\n");
	else
		printf("ջ��Ϊ��\n");

	Data data1 = { 1, 'a' };
	StackPush(&stack1, data1);

	if (IsEmptyStack(stack1))
		printf("ջΪ��\n");
	else
		printf("ջ��Ϊ��\n");

	//Data data2 = { 0 };
	//StackPop(&stack1, &data2);

	//if (IsEmptyStack(stack1))
	//	printf("ջΪ��\n");
	//else
	//	printf("ջ��Ϊ��\n");

	Data data3 = { 0 };
	StackGetTop(stack1, &data3);
	printf("%d %c\n", data3.num, data3.ch);

	return 0;
}