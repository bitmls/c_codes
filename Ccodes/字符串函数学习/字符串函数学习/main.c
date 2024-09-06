#define _CRT_SECURE_NO_WARNINGS  1	

#include <stdio.h>
#include <string.h>
#include <assert.h>

//int my_strlen(const char* str)
//{
//	int count = 0;
//
//	assert(str != NULL);
//
//	while(*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int main()
//{
//	char str[] = "abc";
//
//	int ret = my_strlen(str);
//
//	printf("%d\n", ret);
//
//	return 0;
//}


//int main()
//{
//	char arr[20] = "#############";
//
//	strcpy(arr, "hello");
//
//	return 0;
//}


//char* my_strcat(char* arr1, const char* arr2)
//{
//	char* ret = arr1;
//
//	//将目标字符串指向\0
//	while (*arr1 != '\0')
//	{
//		arr1++;
//	}
//	while (*arr1++ = *arr2++);
//
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "hello";
//	char arr2[] = " world";
//
//	//strcat(arr1, arr2);
//
//	printf("%s\n", my_strcat(arr1, arr2));
//
//	return 0;
//}


//int main()
//{
//	char* p = "aaaa";
//	char* q = "aaa";
//
//	printf("%d\n", strcmp(p, q));
//
//	return 0;
//}

//int my_strcmp(const char* s1, const char* s2)
//{
//	int ret = 0;
//	while (*s1 == *s2)
//	{
//		s1++;
//		s2++;
//		if (*s1 == '\0' && *s2 == '\0')
//			return 0;
//	}
//	return *s1 - *s2 > 0 ? 1 : -1;
//}
//
//int main()
//{
//	char* p = "aa";
//	char* q = "aaa";
//
//	int ret = my_strcmp(p, q);
//
//	if (ret > 0)
//	{
//		printf("p > q\n");
//	}
//	else if (ret == 0)
//	{
//		printf("p == q\n");
//	}
//	else
//	{
//		printf("p < q\n");
//	}
//
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	char arr1[20] = "abcde";
//	char arr2[] = "abbb";
//
//	//strncpy(arr1, arr2, 6);
//	//strncat(arr1, arr2, 3);
//	int ret = strncmp(arr1, arr2, 2);
//
//	//printf("%s\n", arr1);
//	printf("%d\n", ret);
//
//	return 0;
//}


//char* my_strstr(const char* s1, const char* s2)
//{
//	assert(s1 && s2);
//}
//
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "abc";
//
//	char* ret = my_strstr(arr1, arr2);
//
//	printf("%d\n", ret != NULL);
//
//	return 0;
//}


//int main()
//{
//	char arr[20] = "3187787216@qq.com";
//	char* temp = arr;
//	char* p = "@.";
//
//	char* ret = NULL;
//	for (ret = strtok(temp, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}

#include <errno.h>

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	return 0;
//}



//#include <stdio.h>
//#include <ctype.h>

//int main()
//{
//	char ch = 'F';
//	
//	//int ret = isdigit(ch);
//	int ret = isupper(ch);
//
//	printf("%d\n", ret);
//
//	return 0;
//}


//#include <ctype.h>
//
//int main()
//{
//	char arr[20] = { 0 };
//
//	scanf("%s", arr);
//
//	int i = 0;
//	while (arr[i] != '\0')
//	{
//		if (isupper(arr[i]))
//		{
//			arr[i] = tolower(arr[i]);
//		}
//		printf("%c", arr[i]);
//		i++;
//	}
//
//	return 0;
//}


//void* my_memcpy(void* dest, void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		(char*)dest += 1;
//		(char*)src += 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int arr2[10] = { 0 };
//
//	my_memcpy(arr1 + 2, arr1, 24);
//
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//    int arr[10] = { 0 };
//
//    memset(arr, 1, 20);
//
//    return 0;
//}

