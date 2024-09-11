#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <math.h>

enum max {
	BULLET_MAX = 100,
	ENEMY_MAX = 100,
	ENEMY_BULLET_MAX = 10,
};

enum size {
	BK_WIDTH = 500,
	BK_HEIGHT = 700,

	PLAYER_WIDTH = 70,
	PLAYER_HEIGHT = 70,

	BULLET_WIDTH = 20,
	BULLET_HEIGHT = 30,

	ENEMY_BULLET_1_WIDTH = 12,
	ENEMY_BULLET_1_HEIGHT = 20,

	ENEMY_1_WIDTH = 70,
	ENEMY_1_HEIGHT = 70,
	ENEMY_2_WIDTH = 200,
	ENEMY_2_HEIGHT = 200,
};

enum damage {
	PLAYER_BULLET_DAMAGE = 50,
};

enum speed {
	PLAYER_SPEED = 3,
	PLAYER_BULLET_SPEED = 8,
	ENEMY_BULLET_SPEED = 6,
};

enum time {
	BULLET_CREATE_TIME = 200,
	ENEMY_CREATE_ADD_TIME = 50,
	ENEMY_CREATE_MIN_TIME = 50,
};

enum timer {
	COMMON,
	MOVE,
	PLAYER_BULLET,
	ENEMY,
	ENEMY_BULLET,
};

typedef struct Plane {
	int x;
	int y;
	bool live_flag;  // �Ƿ����־λ
	int speed;
}Plane;
Plane player;

typedef struct EnemyType {
	int index;
	int hp;
	int speed;
}EnemyType;
EnemyType type1 = { 1, 100, 5 };
EnemyType type2 = { 2, 500, 3 };

typedef struct Enemy {
	int x;
	int y;
	bool live_flag;
	EnemyType type;
}Enemy;
Enemy enemys[ENEMY_MAX];

typedef struct Bullet {
	int x;
	int y;
	bool used;
	int speed;
	int damage;
}Bullet;
Bullet bullets[BULLET_MAX];
Bullet enemy_bullets[ENEMY_MAX][ENEMY_BULLET_MAX];

bool start_flag = false;
int count = 0;
int add_time = 1000;
int max_score = 0;
FILE* pfread;
FILE* pfwrite;

// ����PNGͼ��ȥ͸������
void _putimagePNG(int  picture_x, int picture_y, IMAGE* picture) //xΪ����ͼƬ��X���꣬yΪY����
{
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬EASYX�Դ�
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //��ȡpicture���Դ�ָ��
	int picture_width = picture->getwidth(); //��ȡpicture�Ŀ�ȣ�EASYX�Դ�
	int picture_height = picture->getheight(); //��ȡpicture�ĸ߶ȣ�EASYX�Դ�
	int graphWidth = getwidth();       //��ȡ��ͼ���Ŀ�ȣ�EASYX�Դ�
	int graphHeight = getheight();     //��ȡ��ͼ���ĸ߶ȣ�EASYX�Դ�
	int dstX = 0;    //���Դ������صĽǱ�

	// ʵ��͸����ͼ ��ʽ�� Cp=��p*FP+(1-��p)*BP �� ��Ҷ˹���������е���ɫ�ĸ��ʼ���
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //���Դ������صĽǱ�
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA��͸����
			int sr = ((src[srcX] & 0xff0000) >> 16); //��ȡRGB���R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //���Դ������صĽǱ�
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)
					| (sb * sa / 255 + db * (255 - sa) / 255);
			}
		}
	}
}

// ������ y <0 �Լ�x<0���κ����
void putimagePNG(int x, int y, IMAGE* picture) {

	IMAGE imgTmp, imgTmp2, imgTmp3;
	int winWidth = getwidth();
	int winHeight = getheight();
	if (y < 0) {
		SetWorkingImage(picture);
		getimage(&imgTmp, 0, -y,
			picture->getwidth(), picture->getheight() + y);
		SetWorkingImage();
		y = 0;
		picture = &imgTmp;
	}
	else if (y >= getheight() || x >= getwidth()) {
		return;
	}
	else if (y + picture->getheight() > winHeight) {
		SetWorkingImage(picture);
		getimage(&imgTmp, x, y, picture->getwidth(), winHeight - y);
		SetWorkingImage();
		picture = &imgTmp;
	}

	if (x < 0) {
		SetWorkingImage(picture);
		getimage(&imgTmp2, -x, 0, picture->getwidth() + x, picture->getheight());
		SetWorkingImage();
		x = 0;
		picture = &imgTmp2;
	}

	if (x > winWidth - picture->getwidth()) {
		SetWorkingImage(picture);
		getimage(&imgTmp3, 0, 0, winWidth - x, picture->getheight());
		SetWorkingImage();
		picture = &imgTmp3;
	}


	_putimagePNG(x, y, picture);
}

void DrawPixelExpand(int x, int y, int color) {
	for (int i = -2; i < 3; i++) {
		for (int j = -2; j < 3; j++) {
			putpixel(x + i, y + j, color);
		}
	}
}

IMAGE start_UI_img;
IMAGE start_button_1_img;
IMAGE start_button_2_img;
IMAGE exit_button_1_img;
IMAGE exit_button_2_img;
IMAGE over_UI_img;
IMAGE bk;
IMAGE player_img;
IMAGE player_bullet_img;
IMAGE enemy_1_img;
IMAGE enemy_bullet_1_img;

void LoadImg() {
	// �������������ַ������ԣ���unicode�ַ�����Ϊ���ֽ��ַ���
	// ����ͼƬ
	loadimage(&start_UI_img, "../res/�ɻ���ս��ʼ����.png");
	loadimage(&start_button_1_img, "../res/��ʼ��ť.png");
	loadimage(&start_button_2_img, "../res/��ʼ��ť�������.png");
	loadimage(&exit_button_1_img, "../res/�˳���ť.png");
	loadimage(&exit_button_2_img, "../res/�˳���ť�������.png");
	loadimage(&over_UI_img, "../res/�ɻ���ս��������.png");
	loadimage(&bk, "../res/̫�ձ���.png");
	loadimage(&player_img, "../res/��ҷɻ�.png");
	loadimage(&player_bullet_img, "../res/��ͨ�ӵ�1.png");
	loadimage(&enemy_1_img, "../res/�л�1.png");
	loadimage(&enemy_bullet_1_img, "../res/�л��ӵ�1.png");
}

int StartUI() {
	BeginBatchDraw();

	static bool start_show_flag = false;
	static bool exit_show_flag = false;

	ExMessage msg;
	if (peekmessage(&msg)) {
		if (msg.x > 26 * 5 && msg.x < 76 * 5 &&
			msg.y > 59 * 5 && msg.y < 79 * 5) {
			start_show_flag = true;
		}
		else {
			start_show_flag = false;
		}
		if (msg.x > 26 * 5 && msg.x < 76 * 5 &&
			msg.y > 87 * 5 && msg.y < 107 * 5) {
			exit_show_flag = true;
		}
		else {
			exit_show_flag = false;
		}
		if (msg.message == WM_LBUTTONUP &&
			msg.x > 26 * 5 && msg.x < 76 * 5 &&
			msg.y > 59 * 5 && msg.y < 79 * 5) {
			return 1;
		}
		if (msg.message == WM_LBUTTONUP &&
			msg.x > 26 * 5 && msg.x < 76 * 5 &&
			msg.y > 76 * 5 && msg.y < 107 * 5) {
			return -1;
		}
	}

	putimagePNG(0, 0, &start_UI_img);
	putimagePNG(0, 0, start_show_flag ? &start_button_2_img : &start_button_1_img);
	putimagePNG(0, 0, exit_show_flag ? &exit_button_2_img : &exit_button_1_img);

	if (GetAsyncKeyState(13)) {  // ����enter������
		putimagePNG(0, 0, &start_button_2_img);
		return 1;
	}

	EndBatchDraw();

	return 0;
}

void OverUI() {
	BeginBatchDraw();

	putimagePNG(0, 0, &over_UI_img);

	EndBatchDraw();
}

void GameInit() {
	player.x = (BK_WIDTH - PLAYER_WIDTH) / 2;
	player.y = BK_HEIGHT - 2 * PLAYER_HEIGHT;
	player.live_flag = true;
	player.speed = PLAYER_SPEED;
	
	for (int i = 0; i < BULLET_MAX; i++) {
		bullets[i].x = 0;
		bullets[i].y = 0;
		bullets[i].used = false;
		bullets[i].speed = PLAYER_BULLET_SPEED;
		bullets[i].damage = PLAYER_BULLET_DAMAGE;
	}

	for (int i = 0; i < ENEMY_MAX; i++) {
		enemys[i].x = 0;
		enemys[i].y = 0;
		enemys[i].live_flag = false;
		enemys[i].type = type1;
	}

	for (int i = 0; i < ENEMY_MAX; i++) {
		for (int j = 0; j < ENEMY_BULLET_MAX; j++) {
			enemy_bullets[i][j].x = 0;
			enemy_bullets[i][j].y = 0;
			enemy_bullets[i][j].used = false;
			enemy_bullets[i][j].speed = ENEMY_BULLET_SPEED;
			enemy_bullets[i][j].damage = 100;
		}
	}

	add_time = 1000;
	count = 0;
}

void GameDraw() {
	// ��ͼ
	putimage(0, 0, &bk);
	putimagePNG(player.x, player.y, &player_img);
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullets[i].used) {
			putimagePNG(bullets[i].x, bullets[i].y, &player_bullet_img);
		}
	}
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemys[i].live_flag) {
			putimagePNG(enemys[i].x, enemys[i].y, &enemy_1_img);
		}
	}
	for (int i = 0; i < ENEMY_MAX; i++) {
		for (int j = 0; j < ENEMY_BULLET_MAX; j++) {
			if (enemy_bullets[i][j].used) {
				putimagePNG(enemy_bullets[i][j].x, enemy_bullets[i][j].y, &enemy_bullet_1_img);
			}
		}
	}
	char str[30];
	sprintf(str, "����л�������Ϊ: %d", count); // ��ʽ���ַ���
	outtextxy(330, 0, str); // ��ָ��λ�û�������
	sprintf(str, "��߷�Ϊ��%d", max_score);
	outtextxy(0, 0, str);
}

bool Timer(int ms, int index_x, int index_y) {
	static DWORD timer[10][ENEMY_MAX] = {0};
	if (clock() - timer[index_x][index_y] >= ms) {
		timer[index_x][index_y] = clock();
		return true;
	}
	return false;
}
     
void CreateBullet(void) {
	int num = 0;
	for (int i = 0; i < BULLET_MAX; i++) {
		if (!bullets[i].used && num == 0) {
			bullets[i].x = player.x + PLAYER_WIDTH / 2 - 18 - BULLET_WIDTH / 4 * 3;
			bullets[i].y = player.y + 22;
			bullets[i].used = true;
			num++;
			i++;
		}
		if (!bullets[i].used && num == 1) {
			bullets[i].x = player.x + PLAYER_WIDTH / 2 + 18 - BULLET_WIDTH / 4;
			bullets[i].y = player.y + 22;
			bullets[i].used = true;
			num++;
		}
		if (num >= 2)
			break;
	}
}

void CreateEnemyBullet(int x, int y, int index) {
	for (int i = 0; i < ENEMY_BULLET_MAX; i++)	{
		if (!enemy_bullets[index][i].used) {
			enemy_bullets[index][i].x = x;
			enemy_bullets[index][i].y = y;
			enemy_bullets[index][i].used = true;
			return;
		}
	}
}

void CreateEnemy(void) {
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (!enemys[i].live_flag) {
			enemys[i].x = rand() % (BK_WIDTH - ENEMY_1_WIDTH);
			enemys[i].y = 0;
			enemys[i].live_flag = true;
			enemys[i].type = type1;
			break;
		}
	}
}

void PlayerMove(int speed) {
#if 0
	if (_kbhit()) {  // �ж��а�������
		char key = _getch();
		switch (key) {
		case 'w':
		case 'W':
			player.y -= speed;
			break;
		case 's':
		case 'S':
			player.y += speed;
			break;
		case 'a':
		case 'A':
			player.x -= speed;
			break;
		case 'd':
		case 'D':
			player.x += speed;
			break;
		}
	}
#elif 1
	static float x = 0, y = 0;
	float num = 5;
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) {
		if (Timer(10, MOVE, 0))
			if(player.y >= 0)  // ��ֹ�ɻ������ܳ���Ļ
				player.y -= speed;
	}
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) {
		if (Timer(10, MOVE, 1))
			if(player.y < BK_HEIGHT - PLAYER_HEIGHT - 10)  // ��ֹ�ɻ������ܳ���Ļ
				player.y += speed;
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {
		if (Timer(10, MOVE, 2))
			if(player.x > 0)  // ��ֹ�ɻ������ܳ���Ļ
				player.x -= speed;
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
		if (Timer(10, MOVE, 3))
			if(player.x < BK_WIDTH - PLAYER_WIDTH)  // ��ֹ�ɻ������ܳ���Ļ
				player.x += speed;
	}
#endif
	static DWORD t1 = 0, t2 = 0;
	// ���¿ո�������ӵ�
	if (GetAsyncKeyState(VK_SPACE) && t2 - t1 > BULLET_CREATE_TIME) {
		t1 = t2;
		CreateBullet();
	}
	t2 = GetTickCount();
}

void BulletMove(void) {
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullets[i].used)
			if(Timer(20, PLAYER_BULLET, i))
				bullets[i].y -= bullets[i].speed;
		if (bullets[i].y <= 0)
			bullets[i].used = false;
	}
}

void EnemyBulletMove(void) {
	for (int i = 0; i < ENEMY_MAX; i++) {
		for (int j = 0; j < ENEMY_BULLET_MAX; j++) {
			if (enemy_bullets[i][j].used)
				if (Timer(20, ENEMY_BULLET, i))
					enemy_bullets[i][j].y += enemy_bullets[i][j].speed;
			if (enemy_bullets[i][j].y >= BK_HEIGHT)
				enemy_bullets[i][j].used = 0;
		}
	}
}

void EnemyMove(void) {
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemys[i].live_flag) {
			if (Timer(50, ENEMY, i)) {
				enemys[i].y += enemys[i].type.speed;
			}
			if (Timer(50, ENEMY_BULLET, i))
				CreateEnemyBullet(enemys[i].x + ENEMY_1_WIDTH / 2 - ENEMY_BULLET_1_WIDTH / 2,
								  enemys[i].y + ENEMY_1_HEIGHT / 3 * 2 - ENEMY_BULLET_1_HEIGHT / 2,
								  i);
			if (enemys[i].y >= BK_HEIGHT) {  // ����ɻ��������ڣ���������
				enemys[i].live_flag = false;
			}
		}
	}
}

void ArticleHit(void) {  // �ж���Ʒ�Ƿ���ײ
	int x_difference = 0;
	int y_difference = 0;
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (!enemys[i].live_flag)  // ����δ���ɵĵл�
			continue;
		// �ж��ӵ��Ƿ���л���ײ
		for (int j = 0; j < BULLET_MAX; j++) {
			if (!bullets[j].used)  // ����δ���ɵ��ӵ�
				continue;
			x_difference = bullets[j].x - enemys[i].x;
			y_difference = bullets[j].y - enemys[i].y;
			// �ж��ӵ���ɻ��Ƿ��غ�
			if (x_difference > 0 - BULLET_WIDTH / 2 && x_difference < ENEMY_1_WIDTH - BULLET_WIDTH / 2) {
				if (y_difference > 0 - BULLET_HEIGHT / 2 && y_difference < ENEMY_1_HEIGHT - BULLET_HEIGHT / 2) {
					bullets[j].used = false;  // ���ӵ�����
					enemys[i].type.hp -= bullets[j].damage;
				}
			}
		}
		if (enemys[i].type.hp <= 0) {  // ����л�����ֵΪ0����������
			enemys[i].live_flag = false;
			count++;
		}
		// �ж�����Ƿ���л���ײ
		x_difference = player.x + PLAYER_WIDTH / 2 - (enemys[i].x + ENEMY_1_WIDTH / 2);
		y_difference = player.y + PLAYER_HEIGHT / 2 - (enemys[i].y + ENEMY_1_HEIGHT / 2);
		if (pow(x_difference, 2) + pow(y_difference, 2) < pow(PLAYER_HEIGHT / 3 * 2, 2)) {
			player.live_flag = false;
			return;
		}
	}
	// �ж�����Ƿ���з��ӵ���ײ�����ܷ�����һ��ѭ���ڣ��˴�����Ҫ�жϵл��Ƿ���
	for (int i = 0; i < ENEMY_MAX; i++) {
		for (int j = 0; j < ENEMY_BULLET_MAX; j++) {
			x_difference = player.x + PLAYER_WIDTH / 2 - (enemy_bullets[i][j].x + ENEMY_BULLET_1_WIDTH / 2);
			y_difference = player.y + PLAYER_HEIGHT / 2 - (enemy_bullets[i][j].y + ENEMY_BULLET_1_HEIGHT / 2);
			if (pow(x_difference, 2) + pow(y_difference, 2) < pow(PLAYER_HEIGHT / 5 * 2, 2)) {
				player.live_flag = false;
				return;
			}
		}
	}
}

int main() {
	// ��������
	initgraph(BK_WIDTH, BK_HEIGHT, 1);
	// ����ͼƬ
	LoadImg();
	// ��Ϸ��ʼ��
	GameInit();

	int game_status = 0;

	// ��ʼ˫�����ͼ
	BeginBatchDraw();
	while (1) {
		if (!start_flag) {
			game_status = StartUI();
			if (game_status == 1) {
				start_flag = true;
				GameInit();
				pfread = fopen("data.txt", "r");
				if (pfread == NULL)
					pfread = fopen("data.txt", "a");
				fscanf(pfread, "%d", &max_score);
				fclose(pfread);
			}
			else if (game_status == -1)
				return 1;
		}
		else {
			// ��Ϸ��Ⱦ
			GameDraw();
			// ˢ��
			FlushBatchDraw();
			// ��������
			if (Timer(add_time, COMMON, 0)) {
				CreateEnemy();
			}
			if (add_time > ENEMY_CREATE_MIN_TIME) {
				if (Timer(ENEMY_CREATE_ADD_TIME, COMMON, 1)) {
					add_time -= 1;
				}
			}
			// ����ƶ�
			PlayerMove(player.speed);
			// �ӵ��ƶ�
			BulletMove();
			// �л��ӵ��ƶ�
			EnemyBulletMove();
			// �����ƶ�
			EnemyMove();
			// ��Ʒ��ײ
			ArticleHit();

			if (!player.live_flag) {
				start_flag = false;
				int num = 0;
				while (num <= 30) {
					if (Timer(100, COMMON, 2))
						num++;
					OverUI();
				}
				if (count > max_score) {
					pfwrite = fopen("data.txt", "w");
					fprintf(pfwrite, "%d", count);
					fclose(pfwrite);
				}
			}
		}
	}
	// ����˫�����ͼ
	EndBatchDraw();

	return 0;
}