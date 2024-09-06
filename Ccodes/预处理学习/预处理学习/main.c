#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>

//int main()
//{
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//	printf("%s\n", __FUNCTION__);
//
//	return 0;
//}


#define PRINT(X, FORMAT)  printf("the value of " #X " is " "%"#FORMAT "\n", X)

int main()
{
	int a = 10, b = 20, c = 30;

	PRINT(a, d);

	return 0;
}
