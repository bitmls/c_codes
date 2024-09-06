//#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory(str);
//	if (str == NULL)
//	{
//		printf("����ʧ��\n");
//		return;
//	}
//	strcpy(str, "hello world");
//	printf(str);
//
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}



//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	if (str == NULL)
//	{
//		printf("����ʧ��\n");
//		return;
//	}
//	strcpy(str, "hello world");
//	printf(str);
//
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}


////��������
//struct S
//{
//	int n;
//	int arr[0];
//};
//
//int main()
//{
//	//��������ʹ��malloc����
//	struct S s;
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));
//
//	ps->n = 10;
//	for (int i = 0; i < ps->n; i++)
//	{
//		ps->arr[i] = i;
//	}
//
//	//��չ�ռ�
//	struct S* ptr = (struct S*)realloc(ps, sizeof(struct S) + 20 * sizeof(int));
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//
//	//ʹ��
//	//......
//
//	//�ͷ�
//	free(ps);
//	ps = NULL;
//
//	return 0;
//}




#include <stdio.h>

int CheckLeapYear(int year) {
    if (year % 400 != 0 && year % 4 == 0)
        return 1;
    else
        return 0;
}

int CheckDays(int year, int month) {
    int ret = 0;
    switch (month) {
    case 1:
        return 31;
    case 2:
        ret = CheckLeapYear(year);
        return ret ? 29 : 28;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    default:
        printf("�·��������\n");
        break;
    }
}

int main() {
    int year, month;
    while (scanf("%d %d", &year, &month) != EOF) {
        int num = CheckDays(year, month);
        printf("%d\n", num);
    }

    return 0;
}