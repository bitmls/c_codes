#include <stdio.h>

//��д����fun:��s��ָ�ַ�����asciֵΪż�����ַ�ɾ�����ַ�����ʣ���ַ��γ�һ�����ַ���

void fun(char* s, char* s_change)
{
	int i = 0;
	while (*s != '\0')
	{
		if (*s % 2 != 0)
		{
			s_change[i] = *s;
			i++;
		}
		s++;
	}
}

int main()
{
	char str[] = "123456789";
	char str_change[100] = { '0' };
	fun(str, str_change);

	int i = 0;
	int sz = sizeof(str_change) / sizeof(str_change[0]);
	for (i = 0; i < sz; i++)
	{
		printf("%c", str_change[i]);
	}

	return 0;
}