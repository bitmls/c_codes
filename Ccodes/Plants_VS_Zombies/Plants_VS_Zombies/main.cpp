/*
* 开发日志（2023年6月28日）
* 1.创建新项目（空项目模板）
* 2.导入素材
* 3.实现最开始的游戏场景
*/


#include <stdio.h>
#include <graphics.h>  //easyx图形库的头文件，需要安装easyx图形库
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

IMAGE imgBg;  //表示背景图片
IMAGE imgBar;  //表示卡片槽
IMAGE imgCards[PLANTS_COUNT];  //表示卡牌
IMAGE* imgPlants[PLANTS_COUNT][10];  //表示植物

int curX = -100, curY = -100;  //当前被拖动的卡牌坐标
int curPlant = -1;  //-1.没有选中， 0.选择了第一种植物

struct plant
{
	int type;  //-1.没有选中， 0.选择了第一种植物， 1.选择了第二种植物
	int frameIndex;  //序列帧的序号
}map[9][5];

struct sunshineBall
{
	int x, y;  //阳光球在飘落下来时的位置
	int frameIndex;  //当前显示图片序列帧的序号
	int destY;  //飘落目标位置的y坐标
	bool used;  //是否在使用
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

//获取时间函数
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

//输出PNG格式的图片
void putimagePNG(int x, int y, IMAGE* img) {
	DWORD* pwin = GetImageBuffer();//获取窗口缓冲区指针
	DWORD* pimg = GetImageBuffer(img);//获取图片缓冲区指针
	int win_w = getwidth();
	int win_h = getheight();
	int img_w = img->getwidth();
	int img_h = img->getheight();
	//判断x,y坐标是否超出了窗口的范围
	int real_w = (x + img_w > win_w) ? win_w - x : img_w;//超出右边界实际贴图的宽度
	int real_h = (y + img_h > win_h) ? win_h - y : img_h;//超出下边界
	if (x < 0) {//超出左边界处理
		pimg += -x;//让指针向后偏移
		real_w -= -x;
		x = 0;
	}
	if (y < 0) {//超出上边界处理
		pimg += (img_w * -y);//让指针向后偏移
		real_h -= -y;
		y = 0;
	}
	pwin += (win_w * y + x);

	for (int iy = 0; iy < real_h; iy++) {
		for (int ix = 0; ix < real_w; ix++) {
			UCHAR alpha = pimg[ix] >> 24;
			if (alpha > 200)//alpha  0 表示完全透明
			{
				pwin[ix] = pimg[ix];
			}
		}
		//换到下一行
		pwin += win_w;
		pimg += img_w;

	}
}

//判断文件是否存在函数
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

//游戏初始化
void gameInit(void)
{
	//加载游戏背景图片
	//把字符集修改为多字节字符集
	loadimage(&imgBg, "res/草坪.jpg");
	loadimage(&imgBar, "res/卡牌槽.png");

	memset(imgPlants, 0, sizeof(imgPlants));

	//初始化草坪上的植物
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			map[i][j].type = -1;
		}
	}

	//初始化植物卡牌
	char name[64];
	for (int i = 0; i < PLANTS_COUNT; i++)
	{
		sprintf_s(name, sizeof(name), "res/植物卡牌/plant_%d.png", i + 1);
		loadimage(&imgCards[i], name);

		for (int j = 0; j < 20; j++)
		{
			sprintf_s(name, sizeof(name), "res/植物/%d/%d.png", i, j + 1);
			//先判断这个文件是否存在
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

	//curPlant = -1;  //将当前选中植物初始化为-1
	sunshine = 50;  //将初始时的阳光设为50

	memset(balls, 0, sizeof(balls));
	for (int i = 0; i < 8; i++)
	{
		sprintf_s(name, sizeof(name), "res/sunshine/阳光%d.png", i + 1);
		loadimage(&imgSunshineBall[i], name);
	}

	//随机数种子
	srand(time(NULL));  //从1970年1月1日到现在多少秒数

	//创建游戏的图形窗口
	initgraph(WIN_WIDTH, WIN_HEIGHT, 1);

	//设置字体
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 30;
	f.lfWeight = 15;
	strcpy(f.lfFaceName, "Segoe UI Black");
	f.lfQuality = ANTIALIASED_QUALITY;  //抗锯齿效果
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	setcolor(BLACK);

	//初始化僵尸数据
	memset(zombies, 0, sizeof(zombies));
	for (int i = 0; i < 1; i++)
	{
		sprintf_s(name, sizeof(name), "res/zombies/僵尸%d.png", i + 1);
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

//窗口画面更新
void updateWindow(void)
{
	BeginBatchDraw();  //开始双缓冲绘图

	putimage(0, 0, &imgBg);
	putimage(180, 0, &imgBar);

	for (int i = 0; i < PLANTS_COUNT; i++)
	{
		putimage(250 + 46 * i, 6, &imgCards[i]);
	}

	//渲染种下来的植物
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

	//渲染阳光
	for (int i = 0; i < ballsMax; i++)
	{
		if (balls[i].used)
		{
			IMAGE* img = &imgSunshineBall[balls[i].frameIndex];
			putimagePNG(balls[i].x, balls[i].y, img);
		}
	}

	//渲染拖动中的植物
	if (curPlant > -1)
	{
		IMAGE* img = imgPlants[curPlant][0];
		putimagePNG(curX - img->getwidth() / 2, curY - img->getheight() / 2, img);
	}

	char scoreText[8];
	sprintf_s(scoreText, sizeof(scoreText), "%d", sunshine);
	outtextxy(195, 46, scoreText);

	//渲染僵尸
	drawZombies();

	EndBatchDraw();  //结束双缓冲绘图
}

//收集阳光
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
				//mciSendString("play res/");  //播放音乐
			}
		}
	}
}

//检测玩家点击
void userClick(void)
{
	ExMessage msg;
	static int status = 0;
	if (peekmessage(&msg))
	{
		if (msg.message == WM_LBUTTONDOWN)
		{
			//判断是否在卡牌槽页选择卡牌
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

				//当原位置没有植物时种植
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

//创建阳光
void createSunshine(void)
{
	static int count = 0;
	static int fre = 400;
	count++;
	if(count >= fre)
	{
		count = 0;
		fre = 200 + rand() % 200;

		//从阳光池中取一个可以使用的
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

//更新阳光
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

//创建僵尸
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

//更新僵尸状态
void updateZombies(void)
{
	static int ZMfre = 2;
	static int count = 0;
	count++;
	if (count > ZMfre)
	{
		count = 0;

		//更新僵尸的位置
		for (int i = 0; i < zombiesMax; i++)
		{
			if (zombies[i].used)
			{
				zombies[i].x -= zombies[i].speed;
				if (zombies[i].x < 190)
				{
					printf("GAME OVER\n");
					MessageBox(NULL, "over", "over", 0);  //待优化
					exit(0);  //待优化
				}
			}
		}
	}
}

//更新游戏的状态
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

	createSunshine();  //创建阳光
	updateSunshine();  //更新阳光状态

	createZombies();  //创建僵尸
	updateZombies();  //更新僵尸状态
}

void startUI(void)
{
	IMAGE imgBg, imgMenu1, imgMenu2;
	loadimage(&imgBg, "res/menu/开始菜单.png");
	loadimage(&imgMenu1, "res/menu/开始菜单按钮.png");
	loadimage(&imgMenu2, "res/menu/开始菜单按钮1.png");

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