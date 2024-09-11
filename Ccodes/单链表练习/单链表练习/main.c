#include <stdio.h>

////学生数据类型
//typedef struct {
//	int ID;
//	char name[10];
//	float score;
//}StuData;
//
////学生结点类型
//typedef struct {
//	StuData* data;
//	struct StudentNode* NextNode;
//}StudentNode, HeadNode;
//
//
////初始化头结点
//void InitHead(HeadNode* head) {
//	head->NextNode = NULL;
//}
//
////判断是否为空列表，为空返回1，否则返回0
//int IsEmpty(const HeadNode* head) {
//	if (head->NextNode == NULL) {
//		return 1;
//	}
//	return 0;
//}
//
//int main() {
//	HeadNode* headList;
//	
//	InitHead(&headList);
//
//	printf("%d\n", IsEmpty(&headList));
//
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
////学生信息
//typedef struct Student {
//    int ID;
//    char* name;
//    int age;
//}Student;
//
////学生数据链表
//typedef struct Node {
//    Student data;
//    struct Node* next;
//}LNode, * LinkList;
//
//
////初始化头结点
//void InitList(LinkList* head) {
//    *head = (LNode*)malloc(sizeof(LNode));
//    (*head)->next = NULL;
//}
//
////创建学生信息
//Student CreateStu(int ID, char* name, int age) {
//    Student stu;
//    stu.ID = ID;
//    stu.name = name;
//    stu.age = age;
//    return stu;
//}
//
////创建结点
//LNode* CreateNode(Student stu) {
//    LNode* new_node = (LNode*)malloc(sizeof(LNode));
//    new_node->data = stu;
//    new_node->next = NULL;
//    return new_node;
//}
//
////向链表结尾插入一个数据
//void ListEndInsertNode(LinkList* head, Student stu) {
//    LNode* new_node = CreateNode(stu);
//    if ((*head)->next == NULL) {  //如果链表中没有元素
//        (*head)->next = new_node;
//    }
//    else {  //普通情况
//        LNode* tail = *head;
//        while (tail->next != NULL) {
//            tail = tail->next;
//        }
//        tail->next = new_node;  //将新节点接到链表的最后一位
//    }
//}
//
////打印链表
//void PrintList(LinkList head) {
//    LNode* temp = head;
//    while (temp->next != NULL) {
//        temp = temp->next;
//        printf("%d %s %d\n", temp->data.ID, temp->data.name, temp->data.age);
//    }
//}
//
//int main() {
//    LinkList stu_list = { 0 };
//    InitList(&stu_list);
//
//    Student stu1 = CreateStu(1, "张三", 20);
//    ListEndInsertNode(&stu_list, stu1);
//
//    PrintList(stu_list);
//
//    return 0;
//}



#include <stdio.h>
#include <stdlib.h>

//学生信息
typedef struct Student {
    int ID;
    char* name;
    int age;
}Student;

//学生数据链表
typedef struct Node {
    Student data;
    struct Node* next;
}LNode, * LinkList;

//打印链表
void PrintList(LNode* phead) {
    LNode* cur = phead;
    while (cur != NULL) {
        printf("%d %s %d\n", cur->data.ID, cur->data.name, cur->data.age);
        cur = cur->next;
    }
    printf("\n");
}

//清空链表（因为最后需要把头结点的指针也置为NULL，所以需要传头结点的指针）
void ClearList(LNode** pphead) {
    LNode* cur = *pphead;
    LNode* next = NULL;
    while (cur != NULL) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    *pphead = NULL;
}

//创建结点
LNode* CreateNode(Student stu) {
    LNode* new_node = (LNode*)malloc(sizeof(LNode));
    new_node->data = stu;
    new_node->next = NULL;
    return new_node;
}

//尾插结点
void ListEndInsertNode(LNode** pphead, Student stu) {
    LNode* new_node = CreateNode(stu);  //创建一个新结点
    if (*pphead == NULL) {  //如果链表为空时
        *pphead = new_node;
    }
    else {  //一般情况
        LNode* tail = *pphead;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = new_node;  //找到最后一个结点，将新结点赋值上去
    }
}

//头插结点
void ListHeadInsertNode(LNode** pphead, Student stu) {
    LNode* new_node = CreateNode(stu);  //创建一个新结点
    new_node->next = *pphead;  //将头结点接在新结点的后面
    *pphead = new_node;  //将新结点作为头结点
}

//尾删结点
void ListEndDeleteNode(LNode** pphead) {
    if (*pphead == NULL) {  //如果链表为空
        return;
    }
    else if ((*pphead)->next == NULL) {  //如果链表只有一个元素
        free(*pphead);
        *pphead = NULL;
    }
    else {  //如果链表有多个元素
        LNode* prev = NULL;
        LNode* tail = *pphead;
        while (tail->next != NULL) {  //循环找到链表尾
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        prev->next = NULL;
    }
}

//头删结点
void ListHeadDeleteNode(LNode** pphead) {
    if (*pphead == NULL) {  //如果链表为空
        return;
    }
    else {
        LNode* next = (*pphead)->next;  //将头结点的下一结点存储起来
        free(*pphead);  //释放掉头结点
        *pphead = next;  //将下一个结点作为头结点
    }
}

//查找对应学号的结点
LNode* ListFindNodeByID(LNode* phead, int ID) {
    LNode* cur = phead;
    while (cur != NULL) {
        if (cur->data.ID == ID) {
            return cur;  //找到返回该结点的指针
        }
        cur = cur->next;  //每次向下一个结点寻找
    }
    return NULL;  //找不到返回NULL
}

//在对应的指针前插入一个结点
void ListPosInsertNode(LNode** pphead, LNode* pos, Student stu) {
    if (*pphead == pos) {  //如果目标位置为第一位
        ListHeadInsertNode(pphead, stu);
    }
    else {
        LNode* new_node = CreateNode(stu);
        LNode* prev = *pphead;
        while (prev->next != pos) {  //找到pos的前一个结点，如果pos为第一个结点，那么pos->next就一直找不到pos，直至解引用NULL，程序崩溃
            prev = prev->next;
        }
        prev->next = new_node;  //将prev的下一个结点置为新结点
        new_node->next = pos;  //将新结点的下一个结点置为pos
    }
}

//删除pos指针指向的结点
void ListPosDeleteNode(LNode** pphead, LNode* pos) {
    if (*pphead == pos) {  //如果要删除的结点为头结点
        ListHeadDeleteNode(pphead);
    }
    else {  //常规情况
        LNode* prev = *pphead;
        while (prev->next != pos) {
            prev = prev->next;
        }
        prev->next = pos->next;
        free(pos);
    }
}


int main() {
    LNode* stu_list = NULL;
    Student stu1 = { 1, "Louis", 20 };
    ListEndInsertNode(&stu_list, stu1);

    Student stu2 = { 2, "Mike", 19 };
    ListEndInsertNode(&stu_list, stu2);

    Student stu3 = { 3, "Gao Hang", 19 };
    ListHeadInsertNode(&stu_list, stu3);

    PrintList(stu_list);

    ListEndDeleteNode(&stu_list);
    ListHeadDeleteNode(&stu_list);

    PrintList(stu_list);

    LNode* node_1 = ListFindNodeByID(stu_list, 1);
    if (node_1 != NULL)
        printf("%d\n", (*node_1).data.age);
    else
        printf("error\n");

    Student stu4 = { 4, "Alex", 21 };
    ListPosInsertNode(&stu_list, node_1, stu4);

    PrintList(stu_list);

    ListPosDeleteNode(&stu_list, ListFindNodeByID(stu_list, 1));

    PrintList(stu_list);

    return 0;
}