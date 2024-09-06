#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	int num;
	int ch;
}Data;

typedef struct StackNode{
	Data data;
	struct LinkStack* next;
}StackNode;

typedef struct LinkStack{
	StackNode* top;
	int count;
}LinkStack;


//��ӡ��ջ
void PrintLinkStack(LinkStack stack) {
	if (stack.count == 0)
		printf("Ϊ��ջ\n");
	while (stack.count--) {
		printf("%d %c %d\n", stack.top->data.num, stack.top->data.ch, stack.count);
	}
}

//��ջ�Ľ�ջ����ջ������Ԫ��eΪ�µ�ջ��Ԫ��
bool LinkStackPush(LinkStack* stack, Data data) {
	StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
	new_node->data = data;
	new_node->next = stack->top;  //��ջ�������½�����
	stack->top = new_node;  //���½�㸳ֵ��ջ��ָ��
	stack->count++;
	return true;
}

//��ջ�ĳ�ջ����ջ��Ԫ��ɾ������e����Ԫ��
bool LinkStackPop(LinkStack* stack, Data* data) {
	if (stack->count == 0)  //���Ϊ��ջ
		return false;
	*data = stack->top->data;
	StackNode* head;
	head = stack->top;
	stack->top = stack->top->next;
	free(head);
	stack->count--;
	return true;
}

int main() {
	LinkStack link_stack1 = { NULL, 0 };

	Data data1 = { 1, 'a' };
	LinkStackPush(&link_stack1, data1);

	PrintLinkStack(link_stack1);

	Data data2 = { 0 };
	LinkStackPop(&link_stack1, &data2);
	printf("%d %c\n", data2.num, data2.ch);

	PrintLinkStack(link_stack1);

	return 0;
}