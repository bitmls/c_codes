#include <stdio.h>

//#define ROW_MAX  5
//#define COL_MAX  5
//
//typedef struct
//{
//	int x;
//	int y;
//}Point;
//
//Point directions[9] = { {1,0}, {1,0}, {1,1}, {0,1}, {-1,1}, {-1,0},  {-1,-1}, {0,-1}, {1,-1} };
//
//int main()
//{
//	int image[ROW_MAX][COL_MAX] = {
//		{1, 1, 1, 0, 0},
//		{1, 1, 1, 0, 0},
//		{0, 1, 1, 1, 0},
//		{0, 1, 1, 1, 0},
//		{0, 1, 1, 1, 0}
//	};
//	int line[ROW_MAX][COL_MAX] = { 0 };
//	int src_x = ROW_MAX - 1, src_y = (COL_MAX - 1) / 2;
//	int dst_x = src_x, dst_y = src_y;
//
//	while(1)
//	{
//		dst_x = src_x;
//		dst_y = src_y;
//		for (int i = 1; i <= 8; i++)
//		{
//			if (src_x + directions[i].x >= 0 &&
//				src_y + directions[i].y >= 0 &&
//				src_x + directions[i].x < ROW_MAX &&
//				src_y + directions[i].y < COL_MAX)
//			{
//				if (image[src_x + directions[i - 1].x][src_y + directions[i - 1].y] == 1 && image[src_x + directions[i].x][src_y + directions[i].y] == 0)
//				{
//					dst_x = src_x + directions[i].x;
//					dst_y = src_y + directions[i].y;
//					break;
//				}
//			}
//		}
//		if (src_x != dst_x || src_y != dst_y)
//		{
//			src_x = dst_x;
//			src_y = dst_y;
//		}
//		else if (src_y > 0)
//		{
//			src_y--;
//		}
//		else if (src_x > 0)
//		{
//			src_x--;
//		}
//		line[src_x][src_y] = 1;
//	}
//
//	return 0;
//}


/////*
////函数名称：void get_start_point(uint8 start_row)
////功能说明：寻找两个边界的边界点作为八邻域循环的起始点
////参数说明：输入任意行数
////函数返回：无
////修改时间：2022年9月8日
////备    注：
////example：  get_start_point(image_h-2)
//// */
////uint8 start_point_l[2] = { 0 };//左边起点的x，y值
////uint8 start_point_r[2] = { 0 };//右边起点的x，y值
////uint8 get_start_point(uint8 start_row)
////{
////	uint8 i = 0, l_found = 0, r_found = 0;
////	//清零
////	start_point_l[0] = 0;//x
////	start_point_l[1] = 0;//y
////
////	start_point_r[0] = 0;//x
////	start_point_r[1] = 0;//y
////
////	//从中间往左边，先找起点
////	for (i = image_w / 2; i > border_min; i--)
////	{
////		start_point_l[0] = i;//x
////		start_point_l[1] = start_row;//y
////		if (bin_image[start_row][i] == 255 && bin_image[start_row][i - 1] == 0)
////		{
////			//printf("找到左边起点image[%d][%d]\n", start_row,i);
////			l_found = 1;
////			break;
////		}
////	}
////
////	for (i = image_w / 2; i < border_max; i++)
////	{
////		start_point_r[0] = i;//x
////		start_point_r[1] = start_row;//y
////		if (bin_image[start_row][i] == 255 && bin_image[start_row][i + 1] == 0)
////		{
////			//printf("找到右边起点image[%d][%d]\n",start_row, i);
////			r_found = 1;
////			break;
////		}
////	}
////
////	if (l_found && r_found)return 1;
////	else {
////		//printf("未找到起点\n");
////		return 0;
////	}
////}
//
//
///*
//函数名称：void search_l_r(uint16 break_flag, uint8(*image)[image_w],uint16 *l_stastic, uint16 *r_stastic,
//							uint8 l_start_x, uint8 l_start_y, uint8 r_start_x, uint8 r_start_y,uint8*hightest)
//
//功能说明：八邻域正式开始找右边点的函数，输入参数有点多，调用的时候不要漏了，这个是左右线一次性找完。
//参数说明：
//break_flag_r			：最多需要循环的次数
//(*image)[image_w]		：需要进行找点的图像数组，必须是二值图,填入数组名称即可
//					   特别注意，不要拿宏定义名字作为输入参数，否则数据可能无法传递过来
//*l_stastic				：统计左边数据，用来输入初始数组成员的序号和取出循环次数
//*r_stastic				：统计右边数据，用来输入初始数组成员的序号和取出循环次数
//l_start_x				：左边起点横坐标
//l_start_y				：左边起点纵坐标
//r_start_x				：右边起点横坐标
//r_start_y				：右边起点纵坐标
//hightest				：循环结束所得到的最高高度
//函数返回：无
//修改时间：2022年9月25日
//备    注：
//example：
//	search_l_r((uint16)USE_num,image,&data_stastics_l, &data_stastics_r,start_point_l[0],
//				start_point_l[1], start_point_r[0], start_point_r[1],&hightest);
// */
//
//#define image_h  60
//#define image_w  94
//
//#define USE_num	 image_h*3	//定义找点的数组成员个数按理说300个点能放下，但是有些特殊情况确实难顶，多定义了一点
//
//typedef unsigned short  uint16;
//typedef unsigned char   uint8;
//typedef signed char     int8;
//
//
// //存放点的x，y坐标
//uint16 points_l[(uint16)USE_num][2] = { {  0 } };//左线
//uint16 points_r[(uint16)USE_num][2] = { {  0 } };//右线
//uint16 dir_r[(uint16)USE_num] = { 0 };//用来存储右边生长方向
//uint16 dir_l[(uint16)USE_num] = { 0 };//用来存储左边生长方向
//uint16 data_stastics_l = 0;//统计左边找到点的个数
//uint16 data_stastics_r = 0;//统计右边找到点的个数
//uint8 hightest = 0;//最高点
//void search_l_r(uint16 break_flag, uint8(*image)[image_w], uint16* l_stastic, uint16* r_stastic, uint8 l_start_x, uint8 l_start_y, uint8 r_start_x, uint8 r_start_y, uint8* hightest)
//{
//	uint8 i = 0, j = 0;
//
//	//左边变量
//	uint8 search_filds_l[8][2] = { {  0 } };
//	uint8 index_l = 0;
//	uint8 temp_l[8][2] = { {  0 } };
//	uint8 center_point_l[2] = { 0 };
//	uint16 l_data_statics;//统计左边
//	//定义八个邻域
//	static int8 seeds_l[8][2] = { {0,  1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,  0},{1, 1}, };
//	//{-1,-1},{0,-1},{+1,-1},
//	//{-1, 0},	     {+1, 0},
//	//{-1,+1},{0,+1},{+1,+1},
//	//这个是顺时针
//
//	//右边变量
//	uint8 search_filds_r[8][2] = { {  0 } };
//	uint8 center_point_r[2] = { 0 };//中心坐标点
//	uint8 index_r = 0;//索引下标
//	uint8 temp_r[8][2] = { {  0 } };
//	uint16 r_data_statics;//统计右边
//	//定义八个邻域
//	static int8 seeds_r[8][2] = { {0,  1},{1,1},{1,0}, {1,-1},{0,-1},{-1,-1}, {-1,  0},{-1, 1}, };
//	//{-1,-1},{0,-1},{+1,-1},
//	//{-1, 0},	     {+1, 0},
//	//{-1,+1},{0,+1},{+1,+1},
//	//这个是逆时针
//
//	l_data_statics = *l_stastic;//统计找到了多少个点，方便后续把点全部画出来
//	r_data_statics = *r_stastic;//统计找到了多少个点，方便后续把点全部画出来
//
//	//第一次更新坐标点  将找到的起点值传进来
//	center_point_l[0] = l_start_x;//x
//	center_point_l[1] = l_start_y;//y
//	center_point_r[0] = r_start_x;//x
//	center_point_r[1] = r_start_y;//y
//
//	//开启邻域循环
//	while (break_flag--)
//	{
//		//左边
//		for (i = 0; i < 8; i++)//传递8F坐标
//		{
//			search_filds_l[i][0] = center_point_l[0] + seeds_l[i][0];//x
//			search_filds_l[i][1] = center_point_l[1] + seeds_l[i][1];//y
//		}
//		//中心坐标点填充到已经找到的点内
//		points_l[l_data_statics][0] = center_point_l[0];//x
//		points_l[l_data_statics][1] = center_point_l[1];//y
//		l_data_statics++;//索引加一
//
//		//右边
//		for (i = 0; i < 8; i++)//传递8F坐标
//		{
//			search_filds_r[i][0] = center_point_r[0] + seeds_r[i][0];//x
//			search_filds_r[i][1] = center_point_r[1] + seeds_r[i][1];//y
//		}
//		//中心坐标点填充到已经找到的点内
//		points_r[r_data_statics][0] = center_point_r[0];//x
//		points_r[r_data_statics][1] = center_point_r[1];//y
//
//		index_l = 0;//先清零，后使用
//		for (i = 0; i < 8; i++)
//		{
//			temp_l[i][0] = 0;//先清零，后使用
//			temp_l[i][1] = 0;//先清零，后使用
//		}
//
//		//左边判断
//		for (i = 0; i < 8; i++)
//		{
//			if (image[search_filds_l[i][1]][search_filds_l[i][0]] == 0
//				&& image[search_filds_l[(i + 1) & 7][1]][search_filds_l[(i + 1) & 7][0]] == 255)
//			{
//				temp_l[index_l][0] = search_filds_l[(i)][0];
//				temp_l[index_l][1] = search_filds_l[(i)][1];
//				index_l++;
//				dir_l[l_data_statics - 1] = (i);//记录生长方向
//			}
//
//			if (index_l)
//			{
//				//更新坐标点
//				center_point_l[0] = temp_l[0][0];//x
//				center_point_l[1] = temp_l[0][1];//y
//				for (j = 0; j < index_l; j++)
//				{
//					if (center_point_l[1] > temp_l[j][1])
//					{
//						center_point_l[0] = temp_l[j][0];//x
//						center_point_l[1] = temp_l[j][1];//y
//					}
//				}
//			}
//
//		}
//		if ((points_r[r_data_statics][0] == points_r[r_data_statics - 1][0] && points_r[r_data_statics][0] == points_r[r_data_statics - 2][0]
//			&& points_r[r_data_statics][1] == points_r[r_data_statics - 1][1] && points_r[r_data_statics][1] == points_r[r_data_statics - 2][1])
//			|| (points_l[l_data_statics - 1][0] == points_l[l_data_statics - 2][0] && points_l[l_data_statics - 1][0] == points_l[l_data_statics - 3][0]
//				&& points_l[l_data_statics - 1][1] == points_l[l_data_statics - 2][1] && points_l[l_data_statics - 1][1] == points_l[l_data_statics - 3][1]))
//		{
//			//printf("三次进入同一个点，退出\n");
//			break;
//		}
//		if (my_abs(points_r[r_data_statics][0] - points_l[l_data_statics - 1][0]) < 2
//			&& my_abs(points_r[r_data_statics][1] - points_l[l_data_statics - 1][1] < 2)
//			)
//		{
//			//printf("\n左右相遇退出\n");	
//			*hightest = (points_r[r_data_statics][1] + points_l[l_data_statics - 1][1]) >> 1;//取出最高点
//			//printf("\n在y=%d处退出\n",*hightest);
//			break;
//		}
//		if ((points_r[r_data_statics][1] < points_l[l_data_statics - 1][1]))
//		{
//			printf("\n如果左边比右边高了，左边等待右边\n");
//			continue;//如果左边比右边高了，左边等待右边
//		}
//		if (dir_l[l_data_statics - 1] == 7
//			&& (points_r[r_data_statics][1] > points_l[l_data_statics - 1][1]))//左边比右边高且已经向下生长了
//		{
//			//printf("\n左边开始向下了，等待右边，等待中... \n");
//			center_point_l[0] = points_l[l_data_statics - 1][0];//x
//			center_point_l[1] = points_l[l_data_statics - 1][1];//y
//			l_data_statics--;
//		}
//		r_data_statics++;//索引加一
//
//		index_r = 0;//先清零，后使用
//		for (i = 0; i < 8; i++)
//		{
//			temp_r[i][0] = 0;//先清零，后使用
//			temp_r[i][1] = 0;//先清零，后使用
//		}
//
//		//右边判断
//		for (i = 0; i < 8; i++)
//		{
//			if (image[search_filds_r[i][1]][search_filds_r[i][0]] == 0
//				&& image[search_filds_r[(i + 1) & 7][1]][search_filds_r[(i + 1) & 7][0]] == 255)
//			{
//				temp_r[index_r][0] = search_filds_r[(i)][0];
//				temp_r[index_r][1] = search_filds_r[(i)][1];
//				index_r++;//索引加一
//				dir_r[r_data_statics - 1] = (i);//记录生长方向
//				//printf("dir[%d]:%d\n", r_data_statics - 1, dir_r[r_data_statics - 1]);
//			}
//			if (index_r)
//			{
//
//				//更新坐标点
//				center_point_r[0] = temp_r[0][0];//x
//				center_point_r[1] = temp_r[0][1];//y
//				for (j = 0; j < index_r; j++)
//				{
//					if (center_point_r[1] > temp_r[j][1])
//					{
//						center_point_r[0] = temp_r[j][0];//x
//						center_point_r[1] = temp_r[j][1];//y
//					}
//				}
//
//			}
//		}
//
//
//	}
//
//
//	//取出循环次数
//	*l_stastic = l_data_statics;
//	*r_stastic = r_data_statics;
//
//}


//#include <stdio.h>
//
//typedef unsigned char  uint8;
//
//uint8 image[6][6] = {
//    {1, 1, 1, 0, 0, 0},
//    {1, 1, 1, 0, 0, 0},
//    {0, 1, 1, 1, 0, 0},
//    {0, 1, 1, 1, 0, 0},
//    {0, 1, 1, 1, 0, 0},
//    {0, 1, 1, 1, 0, 0},
//};
//
//uint8 image_compressed[3][3];
//
//void ImageCompression(const uint8* src, uint8* dst)
//{
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            uint8* source = src + (2 * i) * 6 + 2 * j;
//            uint8* destination = dst + i * 3 + j;
//            *destination = *source;
//        }
//    }
//}
//
//int main()
//{
//    ImageCompression(image, image_compressed);
//
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            printf("%d", image_compressed[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}


//typedef unsigned char  uint8;
//typedef signed char    int8;
//
//#define MT9V03X_CSI_H  12
//#define MT9V03X_CSI_W  12
//#define IMAGE_H  (MT9V03X_CSI_H / 2)
//#define IMAGE_W  (MT9V03X_CSI_W / 2)
//
//#define BLACK  0
//#define WHITE  1
//
//#define MODE_MAX  4
//
////压缩图片二维数组指针传参找到对应值
//#define GET_IMAGE_ARR(ARR, X, Y)  (*((ARR) + ((X) * IMAGE_W) + (Y)))
//
//
//typedef struct
//{
//    uint8 x;  //行坐标
//    uint8 y;  //列坐标
//}point_info_struct;
//
//typedef struct
//{
//    uint8 image[IMAGE_H][IMAGE_W];  //压缩后的图像
//    uint8 image_bin[IMAGE_H][IMAGE_W];  //二值化后的图像
//    uint8 threshold;                //二值化阈值
//    int8  mode;                     //显示模式
//}camera_info_struct;
//
//
//point_info_struct  counterclockwise[9] = { {0,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };   //逆时针的8个点，为方便写程序，第一个点写了两个
//point_info_struct  clockwise[9] = { {0,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1} };   //顺时针的8个点，为方便写程序，第一个点写了两个
//
//point_info_struct  l_start_point = { (IMAGE_W / 2) - 1, IMAGE_H - 2 };  //八邻域找线的左起始点
//point_info_struct  r_start_point = { IMAGE_W / 2,      IMAGE_H - 2 };  //八邻域找线的右起始点
//
//point_info_struct  left_edge[IMAGE_H * 3];   //存储左边线
//point_info_struct  right_edge[IMAGE_H * 3];  //存储右边线
//
//camera_info_struct  camera;
//
//
//
//void EightNeighborhoodsGetEdge(const uint8* image_bin, point_info_struct l_start, point_info_struct r_start)
//{
//    uint8 l_src_x = l_start.x, l_src_y = l_start.y;  //定义上次爬到的起始点
//    uint8 r_src_x = r_start.x, r_src_y = r_start.y;
//    uint8 l_dst_x = l_src_x, l_dst_y = l_src_y;    //定义八邻域爬到的点
//    uint8 r_dst_x = r_src_x, r_dst_y = r_src_y;
//
//    int l_count = 1;  //存储左边线存储了多少点，起始点已找到，初值为1
//    int r_count = 1;  //存储右边线存储了多少点，起始点已找到，初值为1
//
//    left_edge[0].x = l_start.x, left_edge[0].y = l_start.y;  //将边线的第一点赋值
//    right_edge[0].x = r_start.x, right_edge[0].y = r_start.y;
//
//    int break_flag = IMAGE_H * 4; //跳出循环标志
//    while (break_flag--)
//    {
//        l_dst_x = l_src_x;  //将目标点更新
//        l_dst_y = l_src_y;
//        r_dst_x = r_src_x;
//        r_dst_y = r_src_y;
//
//        if (left_edge[l_count - 1].x > 0)  //左边爬到最高点
//        {
//            for (int i = 0; i < 8; i++)  //左边八邻域循环，逆时针寻找
//            {
//                uint8 last_point = GET_IMAGE_ARR(image_bin, l_src_x + counterclockwise[i].x, l_src_y + counterclockwise[i].y);
//                uint8 point = GET_IMAGE_ARR(image_bin, l_src_x + counterclockwise[i + 1].x, l_src_y + counterclockwise[i + 1].y);
//                 if (last_point == WHITE && point == BLACK)  //判断是否为白黑突变
//                {
//                    l_dst_x = l_src_x + counterclockwise[i].x;  //将爬到的突变点的坐标更新
//                    l_dst_y = l_src_y + counterclockwise[i].y;
//                    left_edge[l_count].x = l_dst_x;  //将采集到的边线存储起来
//                    left_edge[l_count].y = l_dst_y;
//                    l_count++;  //将找到的边线点计数+1
//                    break;
//                }
//            }
//        }
//
//        if (right_edge[r_count - 1].x > 0)  //右边爬到最高点
//        {
//            for (int i = 0; i < 8; i++)  //右边八邻域循环，顺时针寻找
//            {
//                uint8 last_point = GET_IMAGE_ARR(image_bin, r_src_x + clockwise[i].x, r_src_y + clockwise[i].y);
//                uint8 point = GET_IMAGE_ARR(image_bin, r_src_x + clockwise[i + 1].x, r_src_y + clockwise[i + 1].y);
//                if (last_point == WHITE && point == BLACK)  //判断是否为白黑突变
//                {
//                    r_dst_x = r_src_x + clockwise[i].x;  //将爬到的突变点的坐标更新
//                    r_dst_y = r_src_y + clockwise[i].y;
//                    right_edge[r_count].x = r_dst_x;  //将采集到的边线存储起来
//                    right_edge[r_count].y = r_dst_y;
//                    r_count++;  //将找到的边线点计数+1
//                    break;
//                }
//            }
//        }
//
//        l_src_x = l_dst_x;
//        l_src_y = l_dst_y;
//        r_src_x = r_dst_x;
//        r_src_y = r_dst_y;
//    }
//}
//
//
//int main()
//{
//    uint8 image[IMAGE_H][IMAGE_W] = {
//        {0, 0, 0, 0, 0, 0},
//        {0, 1, 1, 0, 0, 0},
//        {0, 1, 1, 1, 0, 0},
//        {0, 1, 1, 1, 0, 0},
//        {0, 1, 1, 1, 0, 0},
//        {0, 0, 0, 0, 0, 0},
//    };
//
//    EightNeighborhoodsGetEdge((uint8*)image, l_start_point, r_start_point);
//
//    for (int i = 0; i < IMAGE_H * 3; i++)
//    {
//        printf("%d ", left_edge[i]);
//        printf("%d ", left_edge[i]);
//    }
//
//    return 0;
//}



typedef unsigned char  uint8;
typedef unsigned int   uint16;
typedef unsigned long  uint32;
typedef long           int32;

uint8 OtsuThreshold(uint8* image, uint16 col, uint16 row)
{
#define GrayScale 256
    uint16 Image_Width = col;
    uint16 Image_Height = row;
    int X; uint16 Y;
    uint8* data = image;
    int HistGram[GrayScale] = { 0 };

    uint32 Amount = 0;
    uint32 PixelBack = 0;
    uint32 PixelIntegralBack = 0;
    uint32 PixelIntegral = 0;
    int32 PixelIntegralFore = 0;
    int32 PixelFore = 0;
    double OmegaBack = 0, OmegaFore = 0, MicroBack = 0, MicroFore = 0, SigmaB = 0, Sigma = 0;                            // 类间方差;
    uint8 MinValue = 0, MaxValue = 0;
    uint8 Threshold = 0;

    for (Y = 0; Y < Image_Height; Y++) //Y<Image_Height改为Y =Image_Height；以便进行 行二值化
    {
        //Y=Image_Height;
        for (X = 0; X < Image_Width; X++)
        {
            HistGram[(int)data[Y * Image_Width + X]]++; //统计每个灰度值的个数信息
        }
    }

    for (MinValue = 0; MinValue < 256 && HistGram[MinValue] == 0; MinValue++);        //获取最小灰度的值
    for (MaxValue = 255; MaxValue > MinValue && HistGram[MinValue] == 0; MaxValue--); //获取最大灰度的值

    if (MaxValue == MinValue)
    {
        return MaxValue;          // 图像中只有一个颜色
    }
    if (MinValue + 1 == MaxValue)
    {
        return MinValue;      // 图像中只有二个颜色
    }

    for (Y = MinValue; Y <= MaxValue; Y++)
    {
        Amount += HistGram[Y];        //  像素总数
    }

    PixelIntegral = 0;
    for (Y = MinValue; Y <= MaxValue; Y++)
    {
        PixelIntegral += HistGram[Y] * Y;//灰度值总数
    }
    SigmaB = -1;
    for (Y = MinValue; Y < MaxValue; Y++)
    {
        PixelBack = PixelBack + HistGram[Y];    //前景像素点数
        PixelFore = Amount - PixelBack;         //背景像素点数
        OmegaBack = (double)PixelBack / Amount;//前景像素百分比
        OmegaFore = (double)PixelFore / Amount;//背景像素百分比
        PixelIntegralBack += HistGram[Y] * Y;  //前景灰度值
        PixelIntegralFore = PixelIntegral - PixelIntegralBack;//背景灰度值
        MicroBack = (double)PixelIntegralBack / PixelBack;//前景灰度百分比
        MicroFore = (double)PixelIntegralFore / PixelFore;//背景灰度百分比
        Sigma = OmegaBack * OmegaFore * (MicroBack - MicroFore) * (MicroBack - MicroFore);//g
        if (Sigma > SigmaB)//遍历最大的类间方差g
        {
            SigmaB = Sigma;
            Threshold = (uint8)Y;
        }
    }
    return Threshold;
}

int main()
{


    return 0;
}