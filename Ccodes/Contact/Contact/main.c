#define _CRT_SECURE_NO_WARNINGS  1

//ͨѶ¼
//1.ͨѶ¼�ܴ��1000�˵���Ϣ
//ÿ���˵���Ϣ
//����+�Ա�+����+�绰+��ַ
//2.�����˵���Ϣ
//3.ɾ��ָ���˵���Ϣ
//4.�޸�ָ���˵���Ϣ
//5.����ָ���˵���Ϣ
//6.����ͨѶ¼����Ϣ

//�汾2
//��̬�����İ汾
//1.�ʼʱ����3���˵���Ϣ
//2.���ռ䲻��ʱÿ������2���˵���Ϣ




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

	//ͨѶ¼�ṹ���ʼ��
	InitContact(&con);

	do
	{
		menu();
		printf("�����룺");
		scanf("%d", &input);

		switch (input)
		{
		case ADD:  //ͨѶ¼������ϵ��
			AddContact(&con);
			break;
		case DEL:  //ͨѶ¼ɾ����ϵ��
			DelContact(&con);
			break;
		case SEARCH:  //������ϵ��
			SearchContact(&con);
			break;
		case MODIFY:  //�޸���ϵ��
			ModifyContact(&con);
			break;
		case SORT:  //����
			printf("��ʱûд\n");
			break;
		case PRINT:  //��ӡͨѶ¼
			PrintContact(&con);
			break;
		case EXIT:  //�˳�
			//��ͨѶ¼���浽�ļ�
			SaveContact(&con);
			//����ͨѶ¼
			DestoryContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);

	return 0;
}