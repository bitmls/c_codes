#define _CRT_SECURE_NO_WARNINGS  1

//项目日志
//1.制作最基本的菜单
//2.创建卡牌的结构体
//3.创建桌面的结构体
//4.创建随机抽牌机制
//5.添加游戏结束判断
//6.添加人机抽牌规则


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int round = 0;  //游戏回合数
int rural_round = 0;  //对手回合数

int game_input = 0;  //游戏内输入

bool over_flag = false;  //游戏结束标志

//创建卡牌类型
struct Cards
{
	int num;
	bool used;
}card[11];

//创建桌面类型
struct Desks
{
	int arr[10];  //当前桌上牌的种类
	int n;        //当前桌上的牌数
}desk1, desk2;

//控制台输入类型
enum ConInput
{
	EXIT,
	START
};

//游戏内输入类型
enum GameInput
{
	G_EXIT,
	DRAW,
	SKIP
};

//菜单
void menu(void)
{
	printf("******************************\n");
	printf("*****     1.开始游戏     *****\n");
	printf("*****     0.退出游戏     *****\n");
	printf("******************************\n");
}

//游戏内菜单
void gameMenu(void)
{
	printf("******************************\n");
	printf("*****     1.抽一张牌     *****\n");
	printf("*****     2.跳过回合     *****\n");
	printf("*****     0.结束游戏     *****\n");
	printf("******************************\n");
}

//游戏初始化
void gameInit(void)
{
	//对卡牌进行初始化
	for (int i = 0; i < 11; i++)
	{
		card[i].num  = i + 1;
		card[i].used = false;
	}
	//对桌面初始化
	memset(desk1.arr, 0, 4 * 10);
	desk1.n = 2;  //每人开始时抽两张卡牌
	memset(desk2.arr, 0, 4 * 10);
	desk2.n = 2;

	//配置随机数种子
	srand(time(NULL));
}

//随机发牌函数
static int randomNum(void)
{
	do
	{
		int num = (rand() % 11) + 1;
		//遍历11张牌，判断使用了哪一张
		for (int i = 0; i < 11; i++)
		{
			//判断这张牌是否存在与使用
			if (card[i].num == num && card[i].used == false)
			{
				card[i].used = true;
				return num;
			}
		}
	} while (1);
}

//游戏开始
void gameStart(void)
{
	//为每位玩家发两张牌
	for (int i = 0; i < 2; i++)
	{
		desk1.arr[i] = randomNum();
		desk2.arr[i] = randomNum();
	}
}

//打印桌面
void printDesk(void)
{
	printf(" ROUND %d\n\n", round + 1);
	printf("对手桌面 ");
	for (int i = 0; i < 2; i++)
	{
		printf("%3d ", desk1.arr[i]);
	}
	for (int i = 2; i < desk1.n; i++)
	{
		printf("  * ");
	}
	printf("\b\n\n你的桌面 ");
	for (int i = 0; i < desk2.n; i++)
	{
		printf("%3d ", desk2.arr[i]);
	}
	printf("\b\n\n");
}

//游戏结束时打印桌面
void overedPrintDesk(void)
{
	printf(" ROUND %d\n\n", round + 1);
	printf("对手桌面 ");
	for (int i = 0; i < desk1.n; i++)
	{
		printf("%3d ", desk1.arr[i]);
	}
	printf("\b\n\n你的桌面 ");
	for (int i = 0; i < desk2.n; i++)
	{
		printf("%3d ", desk2.arr[i]);
	}
	printf("\b\n\n");
}

//打印等待进度条
void waitPoints(void)
{
	printf("*");
	Sleep(300);
	printf("\b");
	printf(" ");
	printf("\b");

	printf("***");
	Sleep(300);
	printf("\b\b\b");
	printf("   ");
	printf("\b\b\b");

	printf("*****");
	Sleep(300);
	printf("\b\b\b\b\b");
	printf("     ");
	printf("\b\b\b\b\b");

	printf("*******");
	Sleep(200);
	printf("\b\b\b\b\b\b\b");
	printf("       ");
	printf("\b\b\b\b\b\b\b");

	printf("*********");
	Sleep(200);
	printf("\b\b\b\b\b\b\b\b\b");
	printf("         ");
	printf("\b\b\b\b\b\b\b\b\b");
}

//更新游戏状态
void updateGame(void)
{
	scanf("%d", &game_input);
	switch (game_input)  //对输入进行判断
	{
	case DRAW:  //抽一张牌
		desk2.n++;
		desk2.arr[desk2.n - 1] = randomNum();
		round++;  //回合数+1
		printf("你抽了一张牌\n");
		waitPoints();
		break;
	case SKIP:  //跳过回合
		round++;  //回合数+1
		break;
	case G_EXIT:
		break;
	default:
		printf("输入错误，请重新输入\n");
		break;
	}

	//人机抽牌部分
	if (rural_round < round)
	{
		printf("对手回合\n");
		waitPoints();
		
		int sum = 0;
		for (int i = 0; i < desk1.n; i++)
		{
			sum += desk1.arr[i];  //计算出当前手牌上卡牌的和
		}
		if (sum < 17)
		{
			desk1.n++;
			desk1.arr[desk1.n - 1] = randomNum();
			rural_round++;  //对手回合数+1
			printf("对手抽了一张牌\n");
		}
		else
		{
			rural_round++;
			over_flag = true;
			printf("你的对手跳过了回合\n");
		}
	}
}

//判断是否胜利，胜利返回1，失败返回-1，平局返回0
int isWin(void)
{
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < desk1.n; i++)
	{
		sum1 += desk1.arr[i];
	}
	for (int i = 0; i < desk2.n; i++)
	{
		sum2 += desk2.arr[i];
	}

	if (sum1 > 21 && sum2 <= 21)
	{
		return 1;
	}
	else if (sum1 <= 21 && sum2 > 21)
	{
		printf("你输了~~~\n");
		return -1;
	}
	else if (sum1 <= 21 && sum2 <= 21)
	{
		if (sum1 > sum2)
			return -1;
		else if (sum1 < sum2)
			return 1;
		else
			return 0;
	}
	else
	{
		if (sum1 > sum2)
			return 1;
		else if (sum1 < sum2)
			return -1;
		else
			return 0;
	}
}

int main()
{
	int input = 0;  //控制台输入

	do
	{
		gameInit();
		system("cls");  //清空控制台
		menu();
		scanf("%d", &input);  //输入控制选项
		switch (input)
		{
		case START:
			gameStart();
			while (1)
			{
				system("cls");
				printDesk();
				gameMenu();
				updateGame();

				if (game_input == G_EXIT)
				{
					printf("退出成功\n");
					system("pause");
					break;
				}

				waitPoints();

				//判断游戏是否结束
				if (over_flag == true 
					&& round == rural_round 
					&& game_input == SKIP)
				{
					int ret = isWin();
					if (ret == 1)
						printf("你赢了！！！\n");
					else if (ret == -1)
						printf("~~~你输了~~~\n");
					else
						printf("--平局--\n");
					overedPrintDesk();

					rural_round = 0;
					round = 0;

					system("pause");
					break;
				}
				system("pause");
			}
			break;
		case EXIT:
			printf("游戏结束\n");
			system("pause");
			break;
		default:
			printf("输入错误，请重新输入\n");
			system("pause");
			break;
		}
	} while (input);

	system("cls");
	printf("谢谢游玩\n");

	return 0;
}