#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>

//int main()
//{
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//int main()
//{
//	char* arr[10] = { 0 };
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	
//	fgets(arr, 6, pf);
//	printf("%s\n", arr);
//	fputs(arr, stdout);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//struct S
//{
//	char name[10];
//	int age;
//	float score;
//};
//
//int main()
//{
//	//struct S s = { "�", 19, 98.5 };
//	struct S s = { 0 };
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");	
//		return 1;
//	}
//	//д�ļ�
//	//fprintf(pf, "%s %d %f", s.name, s.age, s.score);
//
//	//���ļ�
//	fscanf(pf, "%s %d %f", s.name, &(s.age), &(s.score));
//	fprintf(stdout, "%s %d %f", s.name, s.age, s.score);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//struct S
//{
//	char name[10];
//	int age;
//	float score;
//};
//
//int main()
//{
//	//struct S s = { "�", 19, 98.5f };
//	struct S s = { 0 };
//	//���ļ�
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//д�ļ�
//	//fwrite(&s, sizeof(s), 1, pf);
//
//	//���ļ�
//	fread(&s, sizeof(struct S), 1, pf);
//
//	printf("%s %d %f", s.name, s.age, s.score);
//
//	fputs(s.name, stdout);
//	fprintf(stdout, "%d %f", s.age, s.score);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



//#include <stdio.h>
//
//struct S
//{
//	char name[10];
//	int age;
//	float score;
//};
//
//int main()
//{
//	struct S s = { "hello", 20, 98.5 };
//	struct S tmp = { 0 };
//
//	char buf[100] = { 0 };
//	sprintf(buf, "%s %d %f", s.name, s.age, s.score);
//
//	printf("%s\n", buf);
//
//	sscanf(buf, "%s %d %f", tmp.name, &(tmp.age), &(tmp.score));
//
//	printf("%s %d %f\n", tmp.name, tmp.age, tmp.score);
//
//	return 0;
//}


//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ļ�
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	//�����ļ�ָ��
//	fseek(pf, 2, SEEK_SET);
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	//��֪�ļ�ָ�������ʼλ�õ�ƫ����
//	int ret = ftell(pf);
//	printf("%d\n", ret);
//
//	//���ļ�ָ����Ϊ��λ
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



//int main()
//{
//	int a = 10000;
//	//���ļ�
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//д�ļ�
//	fwrite(&a, sizeof(int), 1, pf);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


int main()
{
	//���ļ�
	FILE* pfread = fopen("test.txt", "r");
	if (pfread == NULL)
	{
		perror("fopen pfread");
		return 1;
	}
	FILE* pfwrite = fopen("test2.txt", "w");
	if (pfwrite == NULL)
	{
		perror("fopen pfwrite");
		fclose(pfread);
		pfread = NULL;
		return 1;
	}

	//��д�ļ�
	int ch = 0;
	while ((ch = fgetc(pfread)) != EOF)
	{
		//д�ļ�
		fputc(ch, pfwrite);
	}

	//�ж��ļ��Ƿ���������
	if (feof(fread))
	{
		printf("�����ļ�������־���ļ���������\n");
	}
	else if (ferror(fread))
	{
		printf("�ļ���ȡʧ�ܽ���\n");
	}

	//�ر��ļ�
	fclose(pfread);
	pfread = NULL;
	fclose(pfwrite);
	pfwrite = NULL;

	return 0;
}