/*
* ������־��2023��6��28�գ�
* 1.��������Ŀ������Ŀģ�壩
* 2.�����ز�
* 3.ʵ���ʼ����Ϸ����
*/


#include <stdio.h>
#include <graphics.h>  //easyxͼ�ο��ͷ�ļ�����Ҫ��װeasyxͼ�ο�
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")


#define WIN_WIDTH	900
#define WIN_HEIGHT	463

enum
{
	WAN_DOU, XIANG_RI_KUI,
	PLANTS_COUNT
};

IMAGE imgBg;  //��ʾ����ͼƬ
IMAGE imgBar;  //��ʾ��Ƭ��
IMAGE imgCards[PLANTS_COUNT];  //��ʾ����
IMAGE* imgPlants[PLANTS_COUNT][10];  //��ʾֲ��

int curX = -100, curY = -100;  //��ǰ���϶��Ŀ�������
int curPlant = -1;  //-1.û��ѡ�У� 0.ѡ���˵�һ��ֲ��

struct plant
{
	int type;  //-1.û��ѡ�У� 0.ѡ���˵�һ��ֲ� 1.ѡ���˵ڶ���ֲ��
	int frameIndex;  //����֡�����
}map[9][5];

struct sunshineBall
{
	int x, y;  //��������Ʈ������ʱ��λ��
	int frameIndex;  //��ǰ��ʾͼƬ����֡�����
	int destY;  //Ʈ��Ŀ��λ�õ�y����
	bool used;  //�Ƿ���ʹ��
	int timer;
}balls[10];
IMAGE imgSunshineBall[10];
int ballsMax = sizeof(balls) / sizeof(balls[0]);
int sunshine;

struct zombie
{
	int x, y;
	int frameIndex;
	int used;
	int speed;
}zombies[20];
IMAGE imgZombie[1];
int zombiesMax = sizeof(zombies) / sizeof(zombies[0]);

//��ȡʱ�亯��
int getDelay(void)
{
	static unsigned long long lastTime = 0;
	unsigned long long currentTime = GetTickCount();
	if (lastTime == 0)
	{
		lastTime = currentTime;
		return 0;
	}
	else
	{
		int ret = currentTime - lastTime;
		lastTime = currentTime;
		return ret;
	}
}

//���PNG��ʽ��ͼƬ
void putimagePNG(int x, int y, IMAGE* img) {
	DWORD* pwin = GetImageBuffer();//��ȡ���ڻ�����ָ��
	DWORD* pimg = GetImageBuffer(img);//��ȡͼƬ������ָ��
	int win_w = getwidth();
	int win_h = getheight();
	int img_w = img->getwidth();
	int img_h = img->getheight();
	//�ж�x,y�����Ƿ񳬳��˴��ڵķ�Χ
	int real_w = (x + img_w > win_w) ? win_w - x : img_w;//�����ұ߽�ʵ����ͼ�Ŀ��
	int real_h = (y + img_h > win_h) ? win_h - y : img_h;//�����±߽�
	if (x < 0) {//������߽紦��
		pimg += -x;//��ָ�����ƫ��
		real_w -= -x;
		x = 0;
	}
	if (y < 0) {//�����ϱ߽紦��
		pimg += (img_w * -y);//��ָ�����ƫ��
		real_h -= -y;
		y = 0;
	}
	pwin += (win_w * y + x);

	for (int iy = 0; iy < real_h; iy++) {
		for (int ix = 0; ix < real_w; ix++) {
			UCHAR alpha = pimg[ix] >> 24;
			if (alpha > 200)//alpha  0 ��ʾ��ȫ͸��
			{
				pwin[ix] = pimg[ix];
			}
		}
		//������һ��
		pwin += win_w;
		pimg += img_w;

	}
}

//�ж��ļ��Ƿ���ں���
bool fileExist(const char* name)
{
	FILE* fp = fopen(name, "r");
	if (fp == NULL)
	{
		return false;
	}
	else
	{
		fclose(fp);
		return true;
	}
}

//��Ϸ��ʼ��
void gameInit(void)
{
	//������Ϸ����ͼƬ
	//���ַ����޸�Ϊ���ֽ��ַ���
	loadimage(&imgBg, "res/��ƺ.jpg");
	loadimage(&imgBar, "res/���Ʋ�.png");

	memset(imgPlants, 0, sizeof(imgPlants));

	//��ʼ����ƺ�ϵ�ֲ��
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			map[i][j].type = -1;
		}
	}

	//��ʼ��ֲ�￨��
	char name[64];
	for (int i = 0; i < PLANTS_COUNT; i++)
	{
		sprintf_s(name, sizeof(name), "res/ֲ�￨��/plant_%d.png", i + 1);
		loadimage(&imgCards[i], name);

		for (int j = 0; j < 20; j++)
		{
			sprintf_s(name, sizeof(name), "res/ֲ��/%d/%d.png", i, j + 1);
			//���ж�����ļ��Ƿ����
			if (fileExist(name))
			{
				imgPlants[i][j] = new IMAGE;
				loadimage(imgPlants[i][j], name);
			}
			else
			{
				break;
			}
		}
	}

	//curPlant = -1;  //����ǰѡ��ֲ���ʼ��Ϊ-1
	sunshine = 50;  //����ʼʱ��������Ϊ50

	memset(balls, 0, sizeof(balls));
	for (int i = 0; i < 8; i++)
	{
		sprintf_s(name, sizeof(name), "res/sunshine/����%d.png", i + 1);
		loadimage(&imgSunshineBall[i], name);
	}

	//���������
	srand(time(NULL));  //��1970��1��1�յ����ڶ�������

	//������Ϸ��ͼ�δ���
	initgraph(WIN_WIDTH, WIN_HEIGHT, 1);

	//��������
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 30;
	f.lfWeight = 15;
	strcpy(f.lfFaceName, "Segoe UI Black");
	f.lfQuality = ANTIALIASED_QUALITY;  //�����Ч��
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	setcolor(BLACK);

	//��ʼ����ʬ����
	memset(zombies, 0, sizeof(zombies));
	for (int i = 0; i < 1; i++)
	{
		sprintf_s(name, sizeof(name), "res/zombies/��ʬ%d.png", i + 1);
		loadimage(&imgZombie[i], name);
	}
}

void drawZombies(void)
{
	for (int i = 0; i < zombiesMax; i++)
	{
		if (zombies[i].used)
		{
			IMAGE* img = &imgZombie[zombies[i].frameIndex];
			putimagePNG(zombies[i].x, zombies[i].y - img->getheight(), img);
		}
	}
}

//���ڻ������
void updateWindow(void)
{
	BeginBatchDraw();  //��ʼ˫�����ͼ

	putimage(0, 0, &imgBg);
	putimage(180, 0, &imgBar);

	for (int i = 0; i < PLANTS_COUNT; i++)
	{
		putimage(250 + 46 * i, 6, &imgCards[i]);
	}

	//��Ⱦ��������ֲ��
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (map[i][j].type > -1)
			{
				int x = 190 + 62.22 * i;
				int y = 70 + 74 * j;
				int plantType = map[i][j].type;
				int index = map[i][j].frameIndex;
				putimagePNG(x, y, imgPlants[plantType][index]);
			}
		}
	}

	//��Ⱦ����
	for (int i = 0; i < ballsMax; i++)
	{
		if (balls[i].used)
		{
			IMAGE* img = &imgSunshineBall[balls[i].frameIndex];
			putimagePNG(balls[i].x, balls[i].y, img);
		}
	}

	//��Ⱦ�϶��е�ֲ��
	if (curPlant > -1)
	{
		IMAGE* img = imgPlants[curPlant][0];
		putimagePNG(curX - img->getwidth() / 2, curY - img->getheight() / 2, img);
	}

	char scoreText[8];
	sprintf_s(scoreText, sizeof(scoreText), "%d", sunshine);
	outtextxy(195, 46, scoreText);

	//��Ⱦ��ʬ
	drawZombies();

	EndBatchDraw();  //����˫�����ͼ
}

//�ռ�����
void collectSunshine(ExMessage* msg)
{
	int w = imgSunshineBall[0].getwidth();
	int h = imgSunshineBall[0].getheight();
	for (int i = 0; i < ballsMax; i++)
	{
		if(balls[i].used)
		{
			int x = balls[i].x;
			int y = balls[i].y;
			if (msg->x > x && msg->x < x + w &&
				msg->y > y && msg->y < y + h)
			{
				balls[i].used = false;
				sunshine += 25;
				//mciSendString("play res/");  //��������
			}
		}
	}
}

//�����ҵ��
void userClick(void)
{
	ExMessage msg;
	static int status = 0;
	if (peekmessage(&msg))
	{
		if (msg.message == WM_LBUTTONDOWN)
		{
			//�ж��Ƿ��ڿ��Ʋ�ҳѡ����
			if (msg.x > 250 && msg.x < 250 + 46 * PLANTS_COUNT && msg.y > 6 && msg.y < 86)
			{
				int index = (msg.x - 250) / 46;
				status = 1;
				printf("%d\n", index);
				curPlant = index;
			}
			else
			{
				collectSunshine(&msg);
			}
		}
		else if (msg.message == WM_MOUSEMOVE && status == 1)
		{
			curX = msg.x;
			curY = msg.y;
		}
		else if (msg.message == WM_LBUTTONUP)
		{
			if (msg.x > 190 && msg.x < 750 && msg.y > 70 && msg.y < 440)
			{
				int row = (msg.x - 190) / 62.222;
				int col = (msg.y - 70) / 74;
				printf("%d ", row);
				printf("%d\n", col);

				//��ԭλ��û��ֲ��ʱ��ֲ
				if (map[row][col].type < 0)
				{
					map[row][col].type = curPlant;
					map[row][col].frameIndex = 0;
				}
			}

			curPlant = -1;
			status = 0;
		}
	}
}

//��������
void createSunshine(void)
{
	static int count = 0;
	static int fre = 400;
	count++;
	if(count >= fre)
	{
		count = 0;
		fre = 200 + rand() % 200;

		//���������ȡһ������ʹ�õ�
		int i = 0;
		for (i = 0; i < ballsMax && balls[i].used; i++);
		if (i >= ballsMax)
			return;

		balls[i].used = true;
		balls[i].frameIndex = 0;
		balls[i].x = 195 + rand() % (750 - 195);  //750  190
		balls[i].y = 0;
		balls[i].destY = 50 + rand() % (440 - 90);  //440  70
		balls[i].timer = 0;
	}
}

//��������
void updateSunshine(void)
{
	for (int i = 0; i < ballsMax; i++)
	{
		if (balls[i].used)
		{
			balls[i].frameIndex = (balls[i].frameIndex + 1) % 8;
			if (balls[i].timer == 0)
			{
				balls[i].y += 2;
			}
			if (balls[i].y > balls[i].destY)
			{
				balls[i].timer++;
				if(balls[i].timer > 100)
				{
					balls[i].used = false;
				}
			}
		}
	}
}

//������ʬ
void createZombies(void)
{
	static int ZMfre = 100;
	static int count = 0;
	count++;
	if (count > ZMfre)
	{
		count = 0;
		ZMfre = 60 + rand() % 41;

		int i = 0;
		for (i = 0; i < zombiesMax && zombies[i].used; i++);
		if (i < zombiesMax)
		{
			zombies[i].used = true;
			zombies[i].x = WIN_WIDTH;
			zombies[i].y = 70 + 74 * (rand() % 5 + 1);
			zombies[i].speed = 1;
		}
	}
}

//���½�ʬ״̬
void updateZombies(void)
{
	static int ZMfre = 2;
	static int count = 0;
	count++;
	if (count > ZMfre)
	{
		count = 0;

		//���½�ʬ��λ��
		for (int i = 0; i < zombiesMax; i++)
		{
			if (zombies[i].used)
			{
				zombies[i].x -= zombies[i].speed;
				if (zombies[i].x < 190)
				{
					printf("GAME OVER\n");
					MessageBox(NULL, "over", "over", 0);  //���Ż�
					exit(0);  //���Ż�
				}
			}
		}
	}
}

//������Ϸ��״̬
void updateGame(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (map[i][j].type > -1)
			{
				map[i][j].frameIndex++;
				int plantType = map[i][j].type;
				int index = map[i][j].frameIndex;
				if (imgPlants[plantType][index] == NULL)
				{
					map[i][j].frameIndex = 0;
				}
			}
		}
	}

	createSunshine();  //��������
	updateSunshine();  //��������״̬

	createZombies();  //������ʬ
	updateZombies();  //���½�ʬ״̬
}

void startUI(void)
{
	IMAGE imgBg, imgMenu1, imgMenu2;
	loadimage(&imgBg, "res/menu/��ʼ�˵�.png");
	loadimage(&imgMenu1, "res/menu/��ʼ�˵���ť.png");
	loadimage(&imgMenu2, "res/menu/��ʼ�˵���ť1.png");

	int flag = 0;
	while(1)
	{
		BeginBatchDraw();
		putimagePNG(0, 0, &imgBg);
		putimagePNG(0, 0, flag ? &imgMenu2 : &imgMenu1);

		ExMessage msg;
		if (peekmessage(&msg))
		{
			if (msg.x > 500 && msg.x < 735 &&
				msg.y > 72 && msg.y < 150)
			{
				flag = 1;
			}
			else
			{
				flag = 0;
			}

			if (msg.message == WM_LBUTTONDOWN &&
				msg.x > 500 && msg.x < 735 &&
				msg.y > 72  && msg.y < 150)
			{

			}
			else if (msg.message == WM_LBUTTONUP &&
				msg.x > 500 && msg.x < 735 &&
				msg.y > 72  && msg.y < 150)
			{
				return;
			}
		}
		EndBatchDraw();
	}
}

int main()
{
	gameInit();

	startUI();

	int timer = 0;
	bool flag = false;

	while(1)
	{
		userClick();

		timer += getDelay();
		if (timer > 5)
		{
			timer = 0;
			flag = true;
		}

		if (flag)
		{
			flag = false;
			updateGame();
		}

		updateWindow();
	}

	system("pause");
	return 0;
}