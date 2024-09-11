#define _CRT_SECURE_NO_WARNINGS  1

#include "contact.h"

//静态版本
////通讯录结构体初始化
//void InitContact(Contact* pc)
//{
//	memset(pc->data, 0, sizeof(pc->data));
//	pc->sz = 0;
//}

////动态版本
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

//文件版本
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

	//将文件导入到通讯录
	LoadContact(pc);
}

//静态版本
////通讯录增加联系人
//void AddContact(Contact* pc)
//{
//	if (pc->sz >= MAX)
//	{
//		printf("通讯录人数已满，无法增加\n");
//		return;
//	}
//
//	printf("请输入姓名：");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("请输入性别：");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("请输入年龄：");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("请输入电话：");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("请输入地址：");
//	scanf("%s", pc->data[pc->sz].addr);
//
//	pc->sz++;
//	printf("增加成功，目前联系人总数为%d\n", pc->sz);
//}

//动态版本
void AddContact(Contact* pc)
{
	//考虑增容
	CheckContact(pc);

	printf("请输入姓名：");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别：");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入年龄：");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入电话：");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址：");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("增加成功，目前联系人总数为%d\n", pc->sz);
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

//通讯录删除联系人
void DelContact(Contact* pc)
{
	if (pc->sz <= 0)
	{
		printf("通讯录为空，无需删除\n");
		return;
	}

	char name[MAX_NAME] = { 0 };
	printf("请输入要删除联系人的姓名：");
	scanf("%s", name);

	int pos = FindByName(pc, name);

	if (pos == -1)
	{
		printf("没有找到\n");
		return;
	}
	//删除
	for (int i = pos; i < pc->sz - 1; i++)
	{
		//将后一位的数据移到前一位来
		pc->data[i] = pc->data[i + 1];
	}

	pc->sz--;
	printf("删除成功\n");
}


//查找联系人
void SearchContact(const Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找联系人的姓名：");
	scanf("%s", name);

	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("找不到该联系人\n");
		return;
	}

	printf("%-4s\t%-5s\t%-5d\t%-12s\t%-10s\n",
		pc->data[pos].name,
		pc->data[pos].sex,
		pc->data[pos].age,
		pc->data[pos].tele,
		pc->data[pos].addr);
}


//修改联系人
void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改联系人的姓名：");
	scanf("%s", name);

	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("找不到该联系人\n");
		return;
	}

	printf("请输入姓名：");
	scanf("%s", pc->data[pos].name);
	printf("请输入性别：");
	scanf("%s", pc->data[pos].sex);
	printf("请输入年龄：");
	scanf("%d", &(pc->data[pos].age));
	printf("请输入电话：");
	scanf("%s", pc->data[pos].tele);
	printf("请输入地址：");
	scanf("%s", pc->data[pos].addr);

	printf("修改成功\n");
}


//打印通讯录
void PrintContact(const Contact* pc)
{	
	printf("%-4s\t%-5s\t%-5s\t%-12s\t%-10s\n", "姓名", "性别", "年龄", "电话", "地址");

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


//销毁通讯录
void DestoryContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
	printf("销毁成功\n");
}


//将通讯录保存到文件
void SaveContact(Contact* pc)
{
	FILE* pf = fopen("Contact.dat", "w");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	//写文件
	for (int i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
	}

	//关闭文件
	fclose(pf);
	pf = NULL;

	printf("保存成功\n");
}


//将文件导入到通讯录
void LoadContact(Contact* pc)
{
	//打开文件
	FILE* pf = fopen("Contact.dat", "r");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}

	//读文件
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		//考虑扩容
		CheckContact(pc);

		pc->data[pc->sz] = tmp;
		pc->sz++;
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}


//考虑增容
void CheckContact(Contact* pc)
{
	if (pc->sz >= pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("增容成功\n");
		}
		else
		{
			perror("AddContact");
			printf("增容失败\n");
			return;
		}
	}
}