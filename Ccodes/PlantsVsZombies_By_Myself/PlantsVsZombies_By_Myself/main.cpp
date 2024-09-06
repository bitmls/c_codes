//开发日志
//实现简单的游戏界面

//---------------------------------头文件包含---------------------------------//
#include <easyx.h>
//---------------------------------头文件包含---------------------------------//

#define WIN_WIDTH   900
#define WIN_HEIGHT  720

IMAGE imgBg;  //表示背景图片
IMAGE imgBar;  //表示卡片槽

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

void gameInit(void)
{
	//导入图片
	loadimage(&imgBg, "res/PVZ草坪.png");
	loadimage(&imgBar, "res/植物卡槽.png");

	//创建窗口
	initgraph(WIN_WIDTH, WIN_HEIGHT, 0);
}

void updateWindow(void)
{
	//开始双缓冲绘图
	BeginBatchDraw();

	putimage(0, 0, &imgBg);
	putimagePNG(120, 12, &imgBar);

	//结束双缓冲绘图
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