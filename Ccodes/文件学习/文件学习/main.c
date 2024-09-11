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
//	//struct S s = { "李华", 19, 98.5 };
//	struct S s = { 0 };
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");	
//		return 1;
//	}
//	//写文件
//	//fprintf(pf, "%s %d %f", s.name, s.age, s.score);
//
//	//读文件
//	fscanf(pf, "%s %d %f", s.name, &(s.age), &(s.score));
//	fprintf(stdout, "%s %d %f", s.name, s.age, s.score);
//
//	//关闭文件
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
//	//struct S s = { "李华", 19, 98.5f };
//	struct S s = { 0 };
//	//打开文件
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	//fwrite(&s, sizeof(s), 1, pf);
//
//	//读文件
//	fread(&s, sizeof(struct S), 1, pf);
//
//	printf("%s %d %f", s.name, s.age, s.score);
//
//	fputs(s.name, stdout);
//	fprintf(stdout, "%d %f", s.age, s.score);
//
//	//关闭文件
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
//	//打开文件
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//读文件
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	//调整文件指针
//	fseek(pf, 2, SEEK_SET);
//
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	//告知文件指针距离起始位置的偏移量
//	int ret = ftell(pf);
//	printf("%d\n", ret);
//
//	//将文件指针置为首位
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



//int main()
//{
//	int a = 10000;
//	//打开文件
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	fwrite(&a, sizeof(int), 1, pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


int main()
{
	//打开文件
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

	//读写文件
	int ch = 0;
	while ((ch = fgetc(pfread)) != EOF)
	{
		//写文件
		fputc(ch, pfwrite);
	}

	//判断文件是否正常结束
	if (feof(fread))
	{
		printf("遇到文件结束标志，文件正常结束\n");
	}
	else if (ferror(fread))
	{
		printf("文件读取失败结束\n");
	}

	//关闭文件
	fclose(pfread);
	pfread = NULL;
	fclose(pfwrite);
	pfwrite = NULL;

	return 0;
}