#include <stdio.h>

//编写函数fun:将s所指字符串中asci值为偶数的字符删除，字符串中剩余字符形成一个新字符串

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