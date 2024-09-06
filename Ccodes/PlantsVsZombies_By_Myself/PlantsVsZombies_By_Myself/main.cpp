//������־
//ʵ�ּ򵥵���Ϸ����

//---------------------------------ͷ�ļ�����---------------------------------//
#include <easyx.h>
//---------------------------------ͷ�ļ�����---------------------------------//

#define WIN_WIDTH   900
#define WIN_HEIGHT  720

IMAGE imgBg;  //��ʾ����ͼƬ
IMAGE imgBar;  //��ʾ��Ƭ��

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

void gameInit(void)
{
	//����ͼƬ
	loadimage(&imgBg, "res/PVZ��ƺ.png");
	loadimage(&imgBar, "res/ֲ�￨��.png");

	//��������
	initgraph(WIN_WIDTH, WIN_HEIGHT, 0);
}

void updateWindow(void)
{
	//��ʼ˫�����ͼ
	BeginBatchDraw();

	putimage(0, 0, &imgBg);
	putimagePNG(120, 12, &imgBar);

	//����˫�����ͼ
	EndBatchDraw();
}

int main()
{
	gameInit();

	while (1)
	{
		updateWindow();
	}

	system("pause");

	return 0;
}