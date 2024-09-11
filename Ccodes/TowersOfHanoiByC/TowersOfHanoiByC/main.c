#include <stdio.h>

int count = 0;  //记录搬了多少次铁块

void Hanoi(int x)
{
	if (x == 1)
	{
		count++;  //当铁块为1块时，仅需搬动一次
	}
	else
	{
		//当搬运铁块为多块时，可拆分成三步
		// 1是先将x-1块铁块搬到辅助柱上
		// 2是将初始柱上较大的一块搬到目标柱上
		// 3是将辅助柱上的x-1块铁块搬到目标柱上
		Hanoi(x - 1);
		count++;
		Hanoi(x - 1);
	}
}

int main()
{
	Hanoi(3);

	printf("%d\n", count);

	return 0;
}