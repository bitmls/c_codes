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

//��̬�汾
//typedef struct Contact
//{
//	PeoInfo data[MAX];
//	int sz;
//}Contact;

//��̬�汾
typedef struct Contact
{
	PeoInfo* data;
	int sz;  //���鵱ǰ���ݸ���
	int capacity;  //���鵱ǰ���������
}Contact;



//-------------------------------��������-------------------------------//
//ͨѶ¼�ṹ���ʼ��
void InitContact(Contact* pc);

//ͨѶ¼������ϵ��
void AddContact(Contact* pc);

//ͨѶ¼ɾ����ϵ��
void DelContact(Contact* pc);

//������ϵ��
void SearchContact(const Contact* pc);

//�޸���ϵ��
void ModifyContact(Contact* pc);

//��ӡͨѶ¼
void PrintContact(const Contact* pc);

//����ͨѶ¼
void DestoryContact(Contact* pc);

//��ͨѶ¼���浽�ļ�
void SaveContact(Contact* pc);

//���ļ����뵽ͨѶ¼
void LoadContact(Contact* pc);

//��������
void CheckContact(Contact* pc);
//-------------------------------��������-------------------------------//