#include <stdio.h>

////ѧ����������
//typedef struct {
//	int ID;
//	char name[10];
//	float score;
//}StuData;
//
////ѧ���������
//typedef struct {
//	StuData* data;
//	struct StudentNode* NextNode;
//}StudentNode, HeadNode;
//
//
////��ʼ��ͷ���
//void InitHead(HeadNode* head) {
//	head->NextNode = NULL;
//}
//
////�ж��Ƿ�Ϊ���б�Ϊ�շ���1�����򷵻�0
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
////ѧ����Ϣ
//typedef struct Student {
//    int ID;
//    char* name;
//    int age;
//}Student;
//
////ѧ����������
//typedef struct Node {
//    Student data;
//    struct Node* next;
//}LNode, * LinkList;
//
//
////��ʼ��ͷ���
//void InitList(LinkList* head) {
//    *head = (LNode*)malloc(sizeof(LNode));
//    (*head)->next = NULL;
//}
//
////����ѧ����Ϣ
//Student CreateStu(int ID, char* name, int age) {
//    Student stu;
//    stu.ID = ID;
//    stu.name = name;
//    stu.age = age;
//    return stu;
//}
//
////�������
//LNode* CreateNode(Student stu) {
//    LNode* new_node = (LNode*)malloc(sizeof(LNode));
//    new_node->data = stu;
//    new_node->next = NULL;
//    return new_node;
//}
//
////�������β����һ������
//void ListEndInsertNode(LinkList* head, Student stu) {
//    LNode* new_node = CreateNode(stu);
//    if ((*head)->next == NULL) {  //���������û��Ԫ��
//        (*head)->next = new_node;
//    }
//    else {  //��ͨ���
//        LNode* tail = *head;
//        while (tail->next != NULL) {
//            tail = tail->next;
//        }
//        tail->next = new_node;  //���½ڵ�ӵ���������һλ
//    }
//}
//
////��ӡ����
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
//    Student stu1 = CreateStu(1, "����", 20);
//    ListEndInsertNode(&stu_list, stu1);
//
//    PrintList(stu_list);
//
//    return 0;
//}



#include <stdio.h>
#include <stdlib.h>

//ѧ����Ϣ
typedef struct Student {
    int ID;
    char* name;
    int age;
}Student;

//ѧ����������
typedef struct Node {
    Student data;
    struct Node* next;
}LNode, * LinkList;

//��ӡ����
void PrintList(LNode* phead) {
    LNode* cur = phead;
    while (cur != NULL) {
        printf("%d %s %d\n", cur->data.ID, cur->data.name, cur->data.age);
        cur = cur->next;
    }
    printf("\n");
}

//���������Ϊ�����Ҫ��ͷ����ָ��Ҳ��ΪNULL��������Ҫ��ͷ����ָ�룩
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

//�������
LNode* CreateNode(Student stu) {
    LNode* new_node = (LNode*)malloc(sizeof(LNode));
    new_node->data = stu;
    new_node->next = NULL;
    return new_node;
}

//β����
void ListEndInsertNode(LNode** pphead, Student stu) {
    LNode* new_node = CreateNode(stu);  //����һ���½��
    if (*pphead == NULL) {  //�������Ϊ��ʱ
        *pphead = new_node;
    }
    else {  //һ�����
        LNode* tail = *pphead;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = new_node;  //�ҵ����һ����㣬���½�㸳ֵ��ȥ
    }
}

//ͷ����
void ListHeadInsertNode(LNode** pphead, Student stu) {
    LNode* new_node = CreateNode(stu);  //����һ���½��
    new_node->next = *pphead;  //��ͷ�������½��ĺ���
    *pphead = new_node;  //���½����Ϊͷ���
}

//βɾ���
void ListEndDeleteNode(LNode** pphead) {
    if (*pphead == NULL) {  //�������Ϊ��
        return;
    }
    else if ((*pphead)->next == NULL) {  //�������ֻ��һ��Ԫ��
        free(*pphead);
        *pphead = NULL;
    }
    else {  //��������ж��Ԫ��
        LNode* prev = NULL;
        LNode* tail = *pphead;
        while (tail->next != NULL) {  //ѭ���ҵ�����β
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        prev->next = NULL;
    }
}

//ͷɾ���
void ListHeadDeleteNode(LNode** pphead) {
    if (*pphead == NULL) {  //�������Ϊ��
        return;
    }
    else {
        LNode* next = (*pphead)->next;  //��ͷ������һ���洢����
        free(*pphead);  //�ͷŵ�ͷ���
        *pphead = next;  //����һ�������Ϊͷ���
    }
}

//���Ҷ�Ӧѧ�ŵĽ��
LNode* ListFindNodeByID(LNode* phead, int ID) {
    LNode* cur = phead;
    while (cur != NULL) {
        if (cur->data.ID == ID) {
            return cur;  //�ҵ����ظý���ָ��
        }
        cur = cur->next;  //ÿ������һ�����Ѱ��
    }
    return NULL;  //�Ҳ�������NULL
}

//�ڶ�Ӧ��ָ��ǰ����һ�����
void ListPosInsertNode(LNode** pphead, LNode* pos, Student stu) {
    if (*pphead == pos) {  //���Ŀ��λ��Ϊ��һλ
        ListHeadInsertNode(pphead, stu);
    }
    else {
        LNode* new_node = CreateNode(stu);
        LNode* prev = *pphead;
        while (prev->next != pos) {  //�ҵ�pos��ǰһ����㣬���posΪ��һ����㣬��ôpos->next��һֱ�Ҳ���pos��ֱ��������NULL���������
            prev = prev->next;
        }
        prev->next = new_node;  //��prev����һ�������Ϊ�½��
        new_node->next = pos;  //���½�����һ�������Ϊpos
    }
}

//ɾ��posָ��ָ��Ľ��
void ListPosDeleteNode(LNode** pphead, LNode* pos) {
    if (*pphead == pos) {  //���Ҫɾ���Ľ��Ϊͷ���
        ListHeadDeleteNode(pphead);
    }
    else {  //�������
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