#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define MENU_MAX  7

void test1()
{
    printf("主菜单\n");
}
void test2()
{
    printf("菜单2\n");
}
void test3()
{
    printf("菜单3\n");
}
void test4()
{
    printf("菜单4\n");
}
void test5()
{
    printf("菜单5\n");
}
void test6()
{
    printf("菜单6\n");
}
void test7()
{
    printf("菜单7\n");
}

typedef struct menu
{
    int ID;                   //菜单的标识码
    unsigned char total;      //菜单项个数
    struct menu               //和其他菜单的关系信息
        * up,                  //up：   上级菜单
        * down,                //down： 第1下级菜单
        * left,                //left： 同级左邻菜单
        * right;               //right：同级右邻菜单
    int cur;                  //当前选中的菜单条目号
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

//--------------------------------菜单ID号的编号规则--------------------------------//
//第一个下级菜单的ID是上级菜单的ID号乘10，再加下级菜单在上级菜单在下级菜单中对应的子项编号(1,2,3...)
//将主菜单ID号定义为0，则其下级菜单的编号为11,12,13...；而对于编号11的下次菜单编号为111,112,113...
//--------------------------------菜单ID号的编号规则--------------------------------//

//根据ID号查找菜单结构体变量
MENU* getMenuFromID(int id)
{
    //遍历菜单结构体数组，查找是否有这个ID，有则返回这个菜单的地址，没有则返回NULL
    for (int i = 0; i < MENU_MAX; i++)
        if (t_menu.menus[i].ID == id)
            return (&t_menu.menus[i]);
    return (NULL);
}

//按ID号对菜单树上的每个菜单节点的关系菜单信息进行赋值
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
//    printf("主菜单\n");
//}
//void test2()
//{
//    printf("菜单2\n");
//}
//void test3()
//{
//    printf("菜单3\n");
//}
//void test4()
//{
//    printf("菜单4\n");
//}
//void test5()
//{
//    printf("菜单5\n");
//}
//void test6()
//{
//    printf("菜单6\n");
//}
//void test7()
//{
//    printf("菜单7\n");
//}
//
//typedef struct menu
//{
//    int ID;                   //菜单的标识码
//    unsigned char total;      //菜单项个数
//    struct menu               //和其他菜单的关系信息
//        * up,                  //up：   上级菜单
//        * down,                //down： 第1下级菜单
//        * left,                //left： 同级左邻菜单
//        * right;               //right：同级右邻菜单
//    int cur;                  //当前选中的菜单条目号
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
////--------------------------------菜单ID号的编号规则--------------------------------//
////第一个下级菜单的ID是上级菜单的ID号乘10，再加下级菜单在上级菜单在下级菜单中对应的子项编号(1,2,3...)
////将主菜单ID号定义为0，则其下级菜单的编号为11,12,13...；而对于编号11的下次菜单编号为111,112,113...
////--------------------------------菜单ID号的编号规则--------------------------------//
//
////根据ID号查找菜单结构体变量
//MENU* getMenuFromID(int id)
//{
//    //遍历菜单结构体数组，查找是否有这个ID，有则返回这个菜单的地址，没有则返回NULL
//    for (int i = 0; i < MENU_MAX; i++)
//        if (menus[i].ID == id)
//            return (&menus[i]);
//    return (NULL);
//}
//
////按ID号对菜单树上的每个菜单节点的关系菜单信息进行赋值
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
