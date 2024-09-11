#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MENU_MAX  7

void test1()
{
    printf("���˵�\n");
}
void test2()
{
    printf("�˵�2\n");
}
void test3()
{
    printf("�˵�3\n");
}
void test4()
{
    printf("�˵�4\n");
}
void test5()
{
    printf("�˵�5\n");
}
void test6()
{
    printf("�˵�6\n");
}
void test7()
{
    printf("�˵�7\n");
}

typedef struct menu
{
    int ID;                   //�˵��ı�ʶ��
    unsigned char total;      //�˵������
    struct menu               //�������˵��Ĺ�ϵ��Ϣ
        * up,                  //up��   �ϼ��˵�
        * down,                //down�� ��1�¼��˵�
        * left,                //left�� ͬ�����ڲ˵�
        * right;               //right��ͬ�����ڲ˵�
    int cur;                  //��ǰѡ�еĲ˵���Ŀ��
    void (*show)(void);
}MENU;

typedef struct T_MENU
{
    MENU menus[MENU_MAX];
    MENU cur_menu;
    int flag;
}T_MENU;

T_MENU t_menu =
{//  ID   total  up    down  left  right  cur
   {{1,   6,     NULL, NULL, NULL, NULL,  0, test1},
    {11,  1,     NULL, NULL, NULL, NULL,  0, test2},
    {12,  1,     NULL, NULL, NULL, NULL,  0, test3},
    {13,  1,     NULL, NULL, NULL, NULL,  0, test4},
    {14,  1,     NULL, NULL, NULL, NULL,  0, test5},
    {15,  1,     NULL, NULL, NULL, NULL,  0, test6},
    {16,  1,     NULL, NULL, NULL, NULL,  0, test7}},

    {1,   6,     NULL, NULL, NULL, NULL,  0, test1},
    0
};

//--------------------------------�˵�ID�ŵı�Ź���--------------------------------//
//��һ���¼��˵���ID���ϼ��˵���ID�ų�10���ټ��¼��˵����ϼ��˵����¼��˵��ж�Ӧ��������(1,2,3...)
//�����˵�ID�Ŷ���Ϊ0�������¼��˵��ı��Ϊ11,12,13...�������ڱ��11���´β˵����Ϊ111,112,113...
//--------------------------------�˵�ID�ŵı�Ź���--------------------------------//

//����ID�Ų��Ҳ˵��ṹ�����
MENU* getMenuFromID(int id)
{
    //�����˵��ṹ�����飬�����Ƿ������ID�����򷵻�����˵��ĵ�ַ��û���򷵻�NULL
    for (int i = 0; i < MENU_MAX; i++)
        if (t_menu.menus[i].ID == id)
            return (&t_menu.menus[i]);
    return (NULL);
}

//��ID�ŶԲ˵����ϵ�ÿ���˵��ڵ�Ĺ�ϵ�˵���Ϣ���и�ֵ
void initMenuTree(void)
{
    for (int i = 0; i < MENU_MAX; i++)
    {
        t_menu.menus[i].up = getMenuFromID(t_menu.menus[i].ID / 10);
        t_menu.menus[i].down = getMenuFromID(t_menu.menus[i].ID * 10 + 1);
        t_menu.menus[i].left = getMenuFromID(t_menu.menus[i].ID - 1);
        t_menu.menus[i].right = getMenuFromID(t_menu.menus[i].ID + 1);
    }
}


int main()
{
    initMenuTree();

    MENU m = t_menu.menus[0];

    int num = 0;

    while (1)
    {
        m.show();
        scanf("%d", &num);
        if (num == 1) { num = 0, m = *m.down; }
        if (num == 2) { num = 0, m = *m.up; }
        if (num == 3) { num = 0, m = *m.left; }
        if (num == 4) { num = 0, m = *m.right; }
    }

    return 0;
}




//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//
//#define MENU_MAX  7
//
//void test1()
//{
//    printf("���˵�\n");
//}
//void test2()
//{
//    printf("�˵�2\n");
//}
//void test3()
//{
//    printf("�˵�3\n");
//}
//void test4()
//{
//    printf("�˵�4\n");
//}
//void test5()
//{
//    printf("�˵�5\n");
//}
//void test6()
//{
//    printf("�˵�6\n");
//}
//void test7()
//{
//    printf("�˵�7\n");
//}
//
//typedef struct menu
//{
//    int ID;                   //�˵��ı�ʶ��
//    unsigned char total;      //�˵������
//    struct menu               //�������˵��Ĺ�ϵ��Ϣ
//        * up,                  //up��   �ϼ��˵�
//        * down,                //down�� ��1�¼��˵�
//        * left,                //left�� ͬ�����ڲ˵�
//        * right;               //right��ͬ�����ڲ˵�
//    int cur;                  //��ǰѡ�еĲ˵���Ŀ��
//    void (*show)(void);
//}MENU;
//
//MENU menus[MENU_MAX] =
//{//  ID   total  up    down  left  right  cur
//    {1,   6,     NULL, NULL, NULL, NULL,  0, test1},
//    {11,  1,     NULL, NULL, NULL, NULL,  0, test2},
//    {12,  1,     NULL, NULL, NULL, NULL,  0, test3},
//    {13,  1,     NULL, NULL, NULL, NULL,  0, test4},
//    {14,  1,     NULL, NULL, NULL, NULL,  0, test5},
//    {15,  1,     NULL, NULL, NULL, NULL,  0, test6},
//    {16,  1,     NULL, NULL, NULL, NULL,  0, test7},
//};
//
////--------------------------------�˵�ID�ŵı�Ź���--------------------------------//
////��һ���¼��˵���ID���ϼ��˵���ID�ų�10���ټ��¼��˵����ϼ��˵����¼��˵��ж�Ӧ��������(1,2,3...)
////�����˵�ID�Ŷ���Ϊ0�������¼��˵��ı��Ϊ11,12,13...�������ڱ��11���´β˵����Ϊ111,112,113...
////--------------------------------�˵�ID�ŵı�Ź���--------------------------------//
//
////����ID�Ų��Ҳ˵��ṹ�����
//MENU* getMenuFromID(int id)
//{
//    //�����˵��ṹ�����飬�����Ƿ������ID�����򷵻�����˵��ĵ�ַ��û���򷵻�NULL
//    for (int i = 0; i < MENU_MAX; i++)
//        if (menus[i].ID == id)
//            return (&menus[i]);
//    return (NULL);
//}
//
////��ID�ŶԲ˵����ϵ�ÿ���˵��ڵ�Ĺ�ϵ�˵���Ϣ���и�ֵ
//void initMenuTree(void)
//{
//    for (int i = 0; i < MENU_MAX; i++)
//    {
//        menus[i].up    = getMenuFromID(menus[i].ID / 10);
//        menus[i].down  = getMenuFromID(menus[i].ID * 10 + 1);
//        menus[i].left  = getMenuFromID(menus[i].ID - 1);
//        menus[i].right = getMenuFromID(menus[i].ID + 1);
//    }
//}
//
//
//int main()
//{
//    initMenuTree();
//
//    MENU m = menus[0];
//
//    int num = 0;
//
//    while (1)
//    {
//        m.show();
//        scanf("%d", &num);
//        if (num == 1) { num = 0, m = *m.down; }
//        if (num == 2) { num = 0, m = *m.up; }
//        if (num == 3) { num = 0, m = *m.left; }
//        if (num == 4) { num = 0, m = *m.right; }
//    }
//
//    return 0;
//}
