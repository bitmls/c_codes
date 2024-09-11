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


//打印链栈
void PrintLinkStack(LinkStack stack) {
	if (stack.count == 0)
		printf("为空栈\n");
	while (stack.count--) {
		printf("%d %c %d\n", stack.top->data.num, stack.top->data.ch, stack.count);
	}
}

//链栈的进栈，在栈顶插入元素e为新的栈顶元素
bool LinkStackPush(LinkStack* stack, Data data) {
	StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
	new_node->data = data;
	new_node->next = stack->top;  //将栈顶接在新结点后面
	stack->top = new_node;  //将新结点赋值给栈顶指针
	stack->count++;
	return true;
}

//链栈的出栈，将栈顶元素删除，用e保留元素
bool LinkStackPop(LinkStack* stack, Data* data) {
	if (stack->count == 0)  //如果为空栈
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