#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME  20
#define MAX_SEX  10
#define MAX_TELE  12
#define MAX_ADDR  30

//#define MAX  1000

#define DEFUALT_SZ  3
#define INC_SZ		2

typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//静态版本
//typedef struct Contact
//{
//	PeoInfo data[MAX];
//	int sz;
//}Contact;

//动态版本
typedef struct Contact
{
	PeoInfo* data;
	int sz;  //数组当前数据个数
	int capacity;  //数组当前的最大容量
}Contact;



//-------------------------------函数声明-------------------------------//
//通讯录结构体初始化
void InitContact(Contact* pc);

//通讯录增加联系人
void AddContact(Contact* pc);

//通讯录删除联系人
void DelContact(Contact* pc);

//查找联系人
void SearchContact(const Contact* pc);

//修改联系人
void ModifyContact(Contact* pc);

//打印通讯录
void PrintContact(const Contact* pc);

//销毁通讯录
void DestoryContact(Contact* pc);

//将通讯录保存到文件
void SaveContact(Contact* pc);

//将文件导入到通讯录
void LoadContact(Contact* pc);

//考虑增容
void CheckContact(Contact* pc);
//-------------------------------函数声明-------------------------------//