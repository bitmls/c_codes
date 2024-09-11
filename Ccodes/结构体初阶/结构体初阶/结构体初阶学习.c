#define _CRT_SECURE_NO_WARNINGS  1

//#include <stdio.h>
//
//struct Information
//{
//	int high;
//	char sex[2];
//};
//
//struct Stu
//{
//	char name[10];
//	struct Information personal;
//	int age;
//	char id[9];
//}student_2;
//
//void print1(struct Stu t)
//{
//	printf("%s %d %s %d %s\n", t.name, t.personal.high, t.personal.sex, t.age, t.id);
//}
//
//void print2(struct Stu* pt)
//{
//	printf("%s %d %s %d %s\n", pt->name, pt->personal.high, pt->personal.sex, pt->age, pt->id);
//}
//
//int main()
//{
//	struct Stu student_1 = { "张三", { 180, "男" }, 18, "202204378" };
//	//struct Stu* ps1 = &student_1;
//	//printf("%d\n", ps1->personal.high);
//	//printf("%s\n", (*ps1).personal.sex);
//	//printf("%d\n", ps1->age);
//
//	print1(student_1);   //传值打印
//	print2(&student_1);  //传址打印
//
//	return 0;
//}


#include <stdio.h>

int main()
{
	int a, b, sum = 0;

	printf("请输入a和b的值：");
	scanf("%d %d", &a, &b);

	do
	{
		sum += a;
		a++;
	} while (a <= b);

	printf("%d\n", sum);

	return 0;
}