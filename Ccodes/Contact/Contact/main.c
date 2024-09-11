#define _CRT_SECURE_NO_WARNINGS  1

//通讯录
//1.通讯录能存放1000人的信息
//每个人的信息
//名字+性别+年龄+电话+地址
//2.增加人的信息
//3.删减指定人的信息
//4.修改指定人的信息
//5.查找指定人的信息
//6.排序通讯录的信息

//版本2
//动态增长的版本
//1.最开始时开辟3个人的信息
//2.当空间不够时每次增加2个人的信息




#include "contact.h"


void menu()
{
	printf("*****************************\n");
	printf("****  1.add     2.del    ****\n");
	printf("****  3.search  4.modify ****\n");
	printf("****  5.sort    6.print  ****\n");
	printf("****       0.exit        ****\n");
	printf("*****************************\n");
}

enum Option
{
	EXIT,   ADD,
	DEL,    SEARCH,
	MODIFY, SORT,
	PRINT
};

int main()
{

	int input = 0;

	//Contact con[MAX];
	Contact con;

	//通讯录结构体初始化
	InitContact(&con);

	do
	{
		menu();
		printf("请输入：");
		scanf("%d", &input);

		switch (input)
		{
		case ADD:  //通讯录增加联系人
			AddContact(&con);
			break;
		case DEL:  //通讯录删除联系人
			DelContact(&con);
			break;
		case SEARCH:  //查找联系人
			SearchContact(&con);
			break;
		case MODIFY:  //修改联系人
			ModifyContact(&con);
			break;
		case SORT:  //排序
			printf("暂时没写\n");
			break;
		case PRINT:  //打印通讯录
			PrintContact(&con);
			break;
		case EXIT:  //退出
			//将通讯录保存到文件
			SaveContact(&con);
			//销毁通讯录
			DestoryContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);

	return 0;
}