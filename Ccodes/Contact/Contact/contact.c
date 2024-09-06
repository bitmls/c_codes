#define _CRT_SECURE_NO_WARNINGS  1

#include "contact.h"

//��̬�汾
////ͨѶ¼�ṹ���ʼ��
//void InitContact(Contact* pc)
//{
//	memset(pc->data, 0, sizeof(pc->data));
//	pc->sz = 0;
//}

////��̬�汾
//void InitContact(Contact* pc)
//{
//	pc->data = (PeoInfo*)calloc(DEFUALT_SZ, sizeof(PeoInfo));
//	if (pc->data == NULL)
//	{
//		perror("InitContact");
//		return;
//	}
//	pc->sz = 0;
//	pc->capacity = DEFUALT_SZ;
//}

//�ļ��汾
void InitContact(Contact* pc)
{
	pc->data = (PeoInfo*)calloc(DEFUALT_SZ, sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;
	pc->capacity = DEFUALT_SZ;

	//���ļ����뵽ͨѶ¼
	LoadContact(pc);
}

//��̬�汾
////ͨѶ¼������ϵ��
//void AddContact(Contact* pc)
//{
//	if (pc->sz >= MAX)
//	{
//		printf("ͨѶ¼�����������޷�����\n");
//		return;
//	}
//
//	printf("������������");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("�������Ա�");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("���������䣺");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("������绰��");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("�������ַ��");
//	scanf("%s", pc->data[pc->sz].addr);
//
//	pc->sz++;
//	printf("���ӳɹ���Ŀǰ��ϵ������Ϊ%d\n", pc->sz);
//}

//��̬�汾
void AddContact(Contact* pc)
{
	//��������
	CheckContact(pc);

	printf("������������");
	scanf("%s", pc->data[pc->sz].name);
	printf("�������Ա�");
	scanf("%s", pc->data[pc->sz].sex);
	printf("���������䣺");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("������绰��");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ��");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("���ӳɹ���Ŀǰ��ϵ������Ϊ%d\n", pc->sz);
}


static int FindByName(const Contact* pc, char name[])
{
	int i = 0;
	while (i < pc->sz)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;
		i++;
	}
	return -1;
}

//ͨѶ¼ɾ����ϵ��
void DelContact(Contact* pc)
{
	if (pc->sz <= 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
		return;
	}

	char name[MAX_NAME] = { 0 };
	printf("������Ҫɾ����ϵ�˵�������");
	scanf("%s", name);

	int pos = FindByName(pc, name);

	if (pos == -1)
	{
		printf("û���ҵ�\n");
		return;
	}
	//ɾ��
	for (int i = pos; i < pc->sz - 1; i++)
	{
		//����һλ�������Ƶ�ǰһλ��
		pc->data[i] = pc->data[i + 1];
	}

	pc->sz--;
	printf("ɾ���ɹ�\n");
}


//������ϵ��
void SearchContact(const Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ������ϵ�˵�������");
	scanf("%s", name);

	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("�Ҳ�������ϵ��\n");
		return;
	}

	printf("%-4s\t%-5s\t%-5d\t%-12s\t%-10s\n",
		pc->data[pos].name,
		pc->data[pos].sex,
		pc->data[pos].age,
		pc->data[pos].tele,
		pc->data[pos].addr);
}


//�޸���ϵ��
void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸���ϵ�˵�������");
	scanf("%s", name);

	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("�Ҳ�������ϵ��\n");
		return;
	}

	printf("������������");
	scanf("%s", pc->data[pos].name);
	printf("�������Ա�");
	scanf("%s", pc->data[pos].sex);
	printf("���������䣺");
	scanf("%d", &(pc->data[pos].age));
	printf("������绰��");
	scanf("%s", pc->data[pos].tele);
	printf("�������ַ��");
	scanf("%s", pc->data[pos].addr);

	printf("�޸ĳɹ�\n");
}


//��ӡͨѶ¼
void PrintContact(const Contact* pc)
{	
	printf("%-4s\t%-5s\t%-5s\t%-12s\t%-10s\n", "����", "�Ա�", "����", "�绰", "��ַ");

	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-4s\t%-5s\t%-5d\t%-12s\t%-10s\n\n",
			pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}


//����ͨѶ¼
void DestoryContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
	printf("���ٳɹ�\n");
}


//��ͨѶ¼���浽�ļ�
void SaveContact(Contact* pc)
{
	FILE* pf = fopen("Contact.dat", "w");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	//д�ļ�
	for (int i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;

	printf("����ɹ�\n");
}


//���ļ����뵽ͨѶ¼
void LoadContact(Contact* pc)
{
	//���ļ�
	FILE* pf = fopen("Contact.dat", "r");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}

	//���ļ�
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		//��������
		CheckContact(pc);

		pc->data[pc->sz] = tmp;
		pc->sz++;
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}


//��������
void CheckContact(Contact* pc)
{
	if (pc->sz >= pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("���ݳɹ�\n");
		}
		else
		{
			perror("AddContact");
			printf("����ʧ��\n");
			return;
		}
	}
}