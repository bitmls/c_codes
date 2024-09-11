#define _CRT_SECURE_NO_WARNINGS  1

//��Ŀ��־
//1.����������Ĳ˵�
//2.�������ƵĽṹ��
//3.��������Ľṹ��
//4.����������ƻ���
//5.�����Ϸ�����ж�
//6.����˻����ƹ���


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int round = 0;  //��Ϸ�غ���
int rural_round = 0;  //���ֻغ���

int game_input = 0;  //��Ϸ������

bool over_flag = false;  //��Ϸ������־

//������������
struct Cards
{
	int num;
	bool used;
}card[11];

//������������
struct Desks
{
	int arr[10];  //��ǰ�����Ƶ�����
	int n;        //��ǰ���ϵ�����
}desk1, desk2;

//����̨��������
enum ConInput
{
	EXIT,
	START
};

//��Ϸ����������
enum GameInput
{
	G_EXIT,
	DRAW,
	SKIP
};

//�˵�
void menu(void)
{
	printf("******************************\n");
	printf("*****     1.��ʼ��Ϸ     *****\n");
	printf("*****     0.�˳���Ϸ     *****\n");
	printf("******************************\n");
}

//��Ϸ�ڲ˵�
void gameMenu(void)
{
	printf("******************************\n");
	printf("*****     1.��һ����     *****\n");
	printf("*****     2.�����غ�     *****\n");
	printf("*****     0.������Ϸ     *****\n");
	printf("******************************\n");
}

//��Ϸ��ʼ��
void gameInit(void)
{
	//�Կ��ƽ��г�ʼ��
	for (int i = 0; i < 11; i++)
	{
		card[i].num  = i + 1;
		card[i].used = false;
	}
	//�������ʼ��
	memset(desk1.arr, 0, 4 * 10);
	desk1.n = 2;  //ÿ�˿�ʼʱ�����ſ���
	memset(desk2.arr, 0, 4 * 10);
	desk2.n = 2;

	//�������������
	srand(time(NULL));
}

//������ƺ���
static int randomNum(void)
{
	do
	{
		int num = (rand() % 11) + 1;
		//����11���ƣ��ж�ʹ������һ��
		for (int i = 0; i < 11; i++)
		{
			//�ж��������Ƿ������ʹ��
			if (card[i].num == num && card[i].used == false)
			{
				card[i].used = true;
				return num;
			}
		}
	} while (1);
}

//��Ϸ��ʼ
void gameStart(void)
{
	//Ϊÿλ��ҷ�������
	for (int i = 0; i < 2; i++)
	{
		desk1.arr[i] = randomNum();
		desk2.arr[i] = randomNum();
	}
}

//��ӡ����
void printDesk(void)
{
	printf(" ROUND %d\n\n", round + 1);
	printf("�������� ");
	for (int i = 0; i < 2; i++)
	{
		printf("%3d ", desk1.arr[i]);
	}
	for (int i = 2; i < desk1.n; i++)
	{
		printf("  * ");
	}
	printf("\b\n\n������� ");
	for (int i = 0; i < desk2.n; i++)
	{
		printf("%3d ", desk2.arr[i]);
	}
	printf("\b\n\n");
}

//��Ϸ����ʱ��ӡ����
void overedPrintDesk(void)
{
	printf(" ROUND %d\n\n", round + 1);
	printf("�������� ");
	for (int i = 0; i < desk1.n; i++)
	{
		printf("%3d ", desk1.arr[i]);
	}
	printf("\b\n\n������� ");
	for (int i = 0; i < desk2.n; i++)
	{
		printf("%3d ", desk2.arr[i]);
	}
	printf("\b\n\n");
}

//��ӡ�ȴ�������
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

//������Ϸ״̬
void updateGame(void)
{
	scanf("%d", &game_input);
	switch (game_input)  //����������ж�
	{
	case DRAW:  //��һ����
		desk2.n++;
		desk2.arr[desk2.n - 1] = randomNum();
		round++;  //�غ���+1
		printf("�����һ����\n");
		waitPoints();
		break;
	case SKIP:  //�����غ�
		round++;  //�غ���+1
		break;
	case G_EXIT:
		break;
	default:
		printf("�����������������\n");
		break;
	}

	//�˻����Ʋ���
	if (rural_round < round)
	{
		printf("���ֻغ�\n");
		waitPoints();
		
		int sum = 0;
		for (int i = 0; i < desk1.n; i++)
		{
			sum += desk1.arr[i];  //�������ǰ�����Ͽ��Ƶĺ�
		}
		if (sum < 17)
		{
			desk1.n++;
			desk1.arr[desk1.n - 1] = randomNum();
			rural_round++;  //���ֻغ���+1
			printf("���ֳ���һ����\n");
		}
		else
		{
			rural_round++;
			over_flag = true;
			printf("��Ķ��������˻غ�\n");
		}
	}
}

//�ж��Ƿ�ʤ����ʤ������1��ʧ�ܷ���-1��ƽ�ַ���0
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
		printf("������~~~\n");
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
	int input = 0;  //����̨����

	do
	{
		gameInit();
		system("cls");  //��տ���̨
		menu();
		scanf("%d", &input);  //�������ѡ��
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
					printf("�˳��ɹ�\n");
					system("pause");
					break;
				}

				waitPoints();

				//�ж���Ϸ�Ƿ����
				if (over_flag == true 
					&& round == rural_round 
					&& game_input == SKIP)
				{
					int ret = isWin();
					if (ret == 1)
						printf("��Ӯ�ˣ�����\n");
					else if (ret == -1)
						printf("~~~������~~~\n");
					else
						printf("--ƽ��--\n");
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
			printf("��Ϸ����\n");
			system("pause");
			break;
		default:
			printf("�����������������\n");
			system("pause");
			break;
		}
	} while (input);

	system("cls");
	printf("лл����\n");

	return 0;
}