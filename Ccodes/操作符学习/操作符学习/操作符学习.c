#include <stdio.h>

//int main()
//{
//	int a = 7;
//	int b = 0;
//
//	b = a >> 1;
//	printf("%d\n", b);
//
//	return 0;
//}

//int main()
//{
//	int a = 0b1101;
//	int b = 0b1010;
//	int c = 0;
//
//	c = a | b;
//	printf("%d", c);
//
//	return 0;
//}

//int main()
//{
//	int a = 46;
//	int b = 190;
//
//	printf("a=%d\n", a);
//	printf("b=%d\n", b);
//
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//
//	printf("-------------\n");
//	printf("a=%d\n", a);
//	printf("b=%d\n", b);
//
//	return 0;
//}


////����һ�����������е�1�ĸ���
//int main()
//{
//	int i = 0;  //ѭ������
//	int a = 16;
//	int b = a;  //����a��ֵ
//	int count = 0;  //��������
//
//	for (i = 0; i < 32; i++)
//	{
//		if (a & 1 == 1)
//		{
//			count++;
//			
//		}
//		a = a >> 1;
//	}
//	printf("%d\n", count);
//	a = b;
//
//	return 0;
//}

//struct Book
//{
//	char name[20];
//	char id[20];
//	int price;
//};
//
//int main()
//{
//	struct Book a = { "C����", "c1102302", 60 };
//	struct Book * pa = &a;
//
//	printf("%s\n", a.name);
//	printf("%s\n", a.id);
//	printf("%d\n", a.price);
//
//	printf("%s\n", (*pa).name);
//	printf("%s\n", (*pa).id);
//	printf("%d\n", (*pa).price);
//
//	printf("%s\n", pa->name);
//	printf("%s\n", pa->id);
//	printf("%d\n", pa->price);
//
//	return 0;
//}

