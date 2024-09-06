#include <stdio.h>

int count = 0;

int Hanoi(int x)
{
	if (x == 1)
	{
		count++;
	}
	else
	{
		Hanoi(x - 1);
		count++;
		Hanoi(x - 1);
	}
}

int main()
{
	Hanoi(5);

	printf("%d\n", count);

	return 0;
}