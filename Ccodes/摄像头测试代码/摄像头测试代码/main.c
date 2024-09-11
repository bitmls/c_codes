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
////�������ƣ�void get_start_point(uint8 start_row)
////����˵����Ѱ�������߽�ı߽����Ϊ������ѭ������ʼ��
////����˵����������������
////�������أ���
////�޸�ʱ�䣺2022��9��8��
////��    ע��
////example��  get_start_point(image_h-2)
//// */
////uint8 start_point_l[2] = { 0 };//�������x��yֵ
////uint8 start_point_r[2] = { 0 };//�ұ�����x��yֵ
////uint8 get_start_point(uint8 start_row)
////{
////	uint8 i = 0, l_found = 0, r_found = 0;
////	//����
////	start_point_l[0] = 0;//x
////	start_point_l[1] = 0;//y
////
////	start_point_r[0] = 0;//x
////	start_point_r[1] = 0;//y
////
////	//���м�����ߣ��������
////	for (i = image_w / 2; i > border_min; i--)
////	{
////		start_point_l[0] = i;//x
////		start_point_l[1] = start_row;//y
////		if (bin_image[start_row][i] == 255 && bin_image[start_row][i - 1] == 0)
////		{
////			//printf("�ҵ�������image[%d][%d]\n", start_row,i);
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
////			//printf("�ҵ��ұ����image[%d][%d]\n",start_row, i);
////			r_found = 1;
////			break;
////		}
////	}
////
////	if (l_found && r_found)return 1;
////	else {
////		//printf("δ�ҵ����\n");
////		return 0;
////	}
////}
//
//
///*
//�������ƣ�void search_l_r(uint16 break_flag, uint8(*image)[image_w],uint16 *l_stastic, uint16 *r_stastic,
//							uint8 l_start_x, uint8 l_start_y, uint8 r_start_x, uint8 r_start_y,uint8*hightest)
//
//����˵������������ʽ��ʼ���ұߵ�ĺ�������������е�࣬���õ�ʱ��Ҫ©�ˣ������������һ�������ꡣ
//����˵����
//break_flag_r			�������Ҫѭ���Ĵ���
//(*image)[image_w]		����Ҫ�����ҵ��ͼ�����飬�����Ƕ�ֵͼ,�����������Ƽ���
//					   �ر�ע�⣬��Ҫ�ú궨��������Ϊ����������������ݿ����޷����ݹ���
//*l_stastic				��ͳ��������ݣ����������ʼ�����Ա����ź�ȡ��ѭ������
//*r_stastic				��ͳ���ұ����ݣ����������ʼ�����Ա����ź�ȡ��ѭ������
//l_start_x				�������������
//l_start_y				��������������
//r_start_x				���ұ���������
//r_start_y				���ұ����������
//hightest				��ѭ���������õ�����߸߶�
//�������أ���
//�޸�ʱ�䣺2022��9��25��
//��    ע��
//example��
//	search_l_r((uint16)USE_num,image,&data_stastics_l, &data_stastics_r,start_point_l[0],
//				start_point_l[1], start_point_r[0], start_point_r[1],&hightest);
// */
//
//#define image_h  60
//#define image_w  94
//
//#define USE_num	 image_h*3	//�����ҵ�������Ա��������˵300�����ܷ��£�������Щ�������ȷʵ�Ѷ����ඨ����һ��
//
//typedef unsigned short  uint16;
//typedef unsigned char   uint8;
//typedef signed char     int8;
//
//
// //��ŵ��x��y����
//uint16 points_l[(uint16)USE_num][2] = { {  0 } };//����
//uint16 points_r[(uint16)USE_num][2] = { {  0 } };//����
//uint16 dir_r[(uint16)USE_num] = { 0 };//�����洢�ұ���������
//uint16 dir_l[(uint16)USE_num] = { 0 };//�����洢�����������
//uint16 data_stastics_l = 0;//ͳ������ҵ���ĸ���
//uint16 data_stastics_r = 0;//ͳ���ұ��ҵ���ĸ���
//uint8 hightest = 0;//��ߵ�
//void search_l_r(uint16 break_flag, uint8(*image)[image_w], uint16* l_stastic, uint16* r_stastic, uint8 l_start_x, uint8 l_start_y, uint8 r_start_x, uint8 r_start_y, uint8* hightest)
//{
//	uint8 i = 0, j = 0;
//
//	//��߱���
//	uint8 search_filds_l[8][2] = { {  0 } };
//	uint8 index_l = 0;
//	uint8 temp_l[8][2] = { {  0 } };
//	uint8 center_point_l[2] = { 0 };
//	uint16 l_data_statics;//ͳ�����
//	//����˸�����
//	static int8 seeds_l[8][2] = { {0,  1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,  0},{1, 1}, };
//	//{-1,-1},{0,-1},{+1,-1},
//	//{-1, 0},	     {+1, 0},
//	//{-1,+1},{0,+1},{+1,+1},
//	//�����˳ʱ��
//
//	//�ұ߱���
//	uint8 search_filds_r[8][2] = { {  0 } };
//	uint8 center_point_r[2] = { 0 };//���������
//	uint8 index_r = 0;//�����±�
//	uint8 temp_r[8][2] = { {  0 } };
//	uint16 r_data_statics;//ͳ���ұ�
//	//����˸�����
//	static int8 seeds_r[8][2] = { {0,  1},{1,1},{1,0}, {1,-1},{0,-1},{-1,-1}, {-1,  0},{-1, 1}, };
//	//{-1,-1},{0,-1},{+1,-1},
//	//{-1, 0},	     {+1, 0},
//	//{-1,+1},{0,+1},{+1,+1},
//	//�������ʱ��
//
//	l_data_statics = *l_stastic;//ͳ���ҵ��˶��ٸ��㣬��������ѵ�ȫ��������
//	r_data_statics = *r_stastic;//ͳ���ҵ��˶��ٸ��㣬��������ѵ�ȫ��������
//
//	//��һ�θ��������  ���ҵ������ֵ������
//	center_point_l[0] = l_start_x;//x
//	center_point_l[1] = l_start_y;//y
//	center_point_r[0] = r_start_x;//x
//	center_point_r[1] = r_start_y;//y
//
//	//��������ѭ��
//	while (break_flag--)
//	{
//		//���
//		for (i = 0; i < 8; i++)//����8F����
//		{
//			search_filds_l[i][0] = center_point_l[0] + seeds_l[i][0];//x
//			search_filds_l[i][1] = center_point_l[1] + seeds_l[i][1];//y
//		}
//		//�����������䵽�Ѿ��ҵ��ĵ���
//		points_l[l_data_statics][0] = center_point_l[0];//x
//		points_l[l_data_statics][1] = center_point_l[1];//y
//		l_data_statics++;//������һ
//
//		//�ұ�
//		for (i = 0; i < 8; i++)//����8F����
//		{
//			search_filds_r[i][0] = center_point_r[0] + seeds_r[i][0];//x
//			search_filds_r[i][1] = center_point_r[1] + seeds_r[i][1];//y
//		}
//		//�����������䵽�Ѿ��ҵ��ĵ���
//		points_r[r_data_statics][0] = center_point_r[0];//x
//		points_r[r_data_statics][1] = center_point_r[1];//y
//
//		index_l = 0;//�����㣬��ʹ��
//		for (i = 0; i < 8; i++)
//		{
//			temp_l[i][0] = 0;//�����㣬��ʹ��
//			temp_l[i][1] = 0;//�����㣬��ʹ��
//		}
//
//		//����ж�
//		for (i = 0; i < 8; i++)
//		{
//			if (image[search_filds_l[i][1]][search_filds_l[i][0]] == 0
//				&& image[search_filds_l[(i + 1) & 7][1]][search_filds_l[(i + 1) & 7][0]] == 255)
//			{
//				temp_l[index_l][0] = search_filds_l[(i)][0];
//				temp_l[index_l][1] = search_filds_l[(i)][1];
//				index_l++;
//				dir_l[l_data_statics - 1] = (i);//��¼��������
//			}
//
//			if (index_l)
//			{
//				//���������
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
//			//printf("���ν���ͬһ���㣬�˳�\n");
//			break;
//		}
//		if (my_abs(points_r[r_data_statics][0] - points_l[l_data_statics - 1][0]) < 2
//			&& my_abs(points_r[r_data_statics][1] - points_l[l_data_statics - 1][1] < 2)
//			)
//		{
//			//printf("\n���������˳�\n");	
//			*hightest = (points_r[r_data_statics][1] + points_l[l_data_statics - 1][1]) >> 1;//ȡ����ߵ�
//			//printf("\n��y=%d���˳�\n",*hightest);
//			break;
//		}
//		if ((points_r[r_data_statics][1] < points_l[l_data_statics - 1][1]))
//		{
//			printf("\n�����߱��ұ߸��ˣ���ߵȴ��ұ�\n");
//			continue;//�����߱��ұ߸��ˣ���ߵȴ��ұ�
//		}
//		if (dir_l[l_data_statics - 1] == 7
//			&& (points_r[r_data_statics][1] > points_l[l_data_statics - 1][1]))//��߱��ұ߸����Ѿ�����������
//		{
//			//printf("\n��߿�ʼ�����ˣ��ȴ��ұߣ��ȴ���... \n");
//			center_point_l[0] = points_l[l_data_statics - 1][0];//x
//			center_point_l[1] = points_l[l_data_statics - 1][1];//y
//			l_data_statics--;
//		}
//		r_data_statics++;//������һ
//
//		index_r = 0;//�����㣬��ʹ��
//		for (i = 0; i < 8; i++)
//		{
//			temp_r[i][0] = 0;//�����㣬��ʹ��
//			temp_r[i][1] = 0;//�����㣬��ʹ��
//		}
//
//		//�ұ��ж�
//		for (i = 0; i < 8; i++)
//		{
//			if (image[search_filds_r[i][1]][search_filds_r[i][0]] == 0
//				&& image[search_filds_r[(i + 1) & 7][1]][search_filds_r[(i + 1) & 7][0]] == 255)
//			{
//				temp_r[index_r][0] = search_filds_r[(i)][0];
//				temp_r[index_r][1] = search_filds_r[(i)][1];
//				index_r++;//������һ
//				dir_r[r_data_statics - 1] = (i);//��¼��������
//				//printf("dir[%d]:%d\n", r_data_statics - 1, dir_r[r_data_statics - 1]);
//			}
//			if (index_r)
//			{
//
//				//���������
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
//	//ȡ��ѭ������
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
////ѹ��ͼƬ��ά����ָ�봫���ҵ���Ӧֵ
//#define GET_IMAGE_ARR(ARR, X, Y)  (*((ARR) + ((X) * IMAGE_W) + (Y)))
//
//
//typedef struct
//{
//    uint8 x;  //������
//    uint8 y;  //������
//}point_info_struct;
//
//typedef struct
//{
//    uint8 image[IMAGE_H][IMAGE_W];  //ѹ�����ͼ��
//    uint8 image_bin[IMAGE_H][IMAGE_W];  //��ֵ�����ͼ��
//    uint8 threshold;                //��ֵ����ֵ
//    int8  mode;                     //��ʾģʽ
//}camera_info_struct;
//
//
//point_info_struct  counterclockwise[9] = { {0,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };   //��ʱ���8���㣬Ϊ����д���򣬵�һ����д������
//point_info_struct  clockwise[9] = { {0,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1} };   //˳ʱ���8���㣬Ϊ����д���򣬵�һ����д������
//
//point_info_struct  l_start_point = { (IMAGE_W / 2) - 1, IMAGE_H - 2 };  //���������ߵ�����ʼ��
//point_info_struct  r_start_point = { IMAGE_W / 2,      IMAGE_H - 2 };  //���������ߵ�����ʼ��
//
//point_info_struct  left_edge[IMAGE_H * 3];   //�洢�����
//point_info_struct  right_edge[IMAGE_H * 3];  //�洢�ұ���
//
//camera_info_struct  camera;
//
//
//
//void EightNeighborhoodsGetEdge(const uint8* image_bin, point_info_struct l_start, point_info_struct r_start)
//{
//    uint8 l_src_x = l_start.x, l_src_y = l_start.y;  //�����ϴ���������ʼ��
//    uint8 r_src_x = r_start.x, r_src_y = r_start.y;
//    uint8 l_dst_x = l_src_x, l_dst_y = l_src_y;    //��������������ĵ�
//    uint8 r_dst_x = r_src_x, r_dst_y = r_src_y;
//
//    int l_count = 1;  //�洢����ߴ洢�˶��ٵ㣬��ʼ�����ҵ�����ֵΪ1
//    int r_count = 1;  //�洢�ұ��ߴ洢�˶��ٵ㣬��ʼ�����ҵ�����ֵΪ1
//
//    left_edge[0].x = l_start.x, left_edge[0].y = l_start.y;  //�����ߵĵ�һ�㸳ֵ
//    right_edge[0].x = r_start.x, right_edge[0].y = r_start.y;
//
//    int break_flag = IMAGE_H * 4; //����ѭ����־
//    while (break_flag--)
//    {
//        l_dst_x = l_src_x;  //��Ŀ������
//        l_dst_y = l_src_y;
//        r_dst_x = r_src_x;
//        r_dst_y = r_src_y;
//
//        if (left_edge[l_count - 1].x > 0)  //���������ߵ�
//        {
//            for (int i = 0; i < 8; i++)  //��߰�����ѭ������ʱ��Ѱ��
//            {
//                uint8 last_point = GET_IMAGE_ARR(image_bin, l_src_x + counterclockwise[i].x, l_src_y + counterclockwise[i].y);
//                uint8 point = GET_IMAGE_ARR(image_bin, l_src_x + counterclockwise[i + 1].x, l_src_y + counterclockwise[i + 1].y);
//                 if (last_point == WHITE && point == BLACK)  //�ж��Ƿ�Ϊ�׺�ͻ��
//                {
//                    l_dst_x = l_src_x + counterclockwise[i].x;  //��������ͻ�����������
//                    l_dst_y = l_src_y + counterclockwise[i].y;
//                    left_edge[l_count].x = l_dst_x;  //���ɼ����ı��ߴ洢����
//                    left_edge[l_count].y = l_dst_y;
//                    l_count++;  //���ҵ��ı��ߵ����+1
//                    break;
//                }
//            }
//        }
//
//        if (right_edge[r_count - 1].x > 0)  //�ұ�������ߵ�
//        {
//            for (int i = 0; i < 8; i++)  //�ұ߰�����ѭ����˳ʱ��Ѱ��
//            {
//                uint8 last_point = GET_IMAGE_ARR(image_bin, r_src_x + clockwise[i].x, r_src_y + clockwise[i].y);
//                uint8 point = GET_IMAGE_ARR(image_bin, r_src_x + clockwise[i + 1].x, r_src_y + clockwise[i + 1].y);
//                if (last_point == WHITE && point == BLACK)  //�ж��Ƿ�Ϊ�׺�ͻ��
//                {
//                    r_dst_x = r_src_x + clockwise[i].x;  //��������ͻ�����������
//                    r_dst_y = r_src_y + clockwise[i].y;
//                    right_edge[r_count].x = r_dst_x;  //���ɼ����ı��ߴ洢����
//                    right_edge[r_count].y = r_dst_y;
//                    r_count++;  //���ҵ��ı��ߵ����+1
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
    double OmegaBack = 0, OmegaFore = 0, MicroBack = 0, MicroFore = 0, SigmaB = 0, Sigma = 0;                            // ��䷽��;
    uint8 MinValue = 0, MaxValue = 0;
    uint8 Threshold = 0;

    for (Y = 0; Y < Image_Height; Y++) //Y<Image_Height��ΪY =Image_Height���Ա���� �ж�ֵ��
    {
        //Y=Image_Height;
        for (X = 0; X < Image_Width; X++)
        {
            HistGram[(int)data[Y * Image_Width + X]]++; //ͳ��ÿ���Ҷ�ֵ�ĸ�����Ϣ
        }
    }

    for (MinValue = 0; MinValue < 256 && HistGram[MinValue] == 0; MinValue++);        //��ȡ��С�Ҷȵ�ֵ
    for (MaxValue = 255; MaxValue > MinValue && HistGram[MinValue] == 0; MaxValue--); //��ȡ���Ҷȵ�ֵ

    if (MaxValue == MinValue)
    {
        return MaxValue;          // ͼ����ֻ��һ����ɫ
    }
    if (MinValue + 1 == MaxValue)
    {
        return MinValue;      // ͼ����ֻ�ж�����ɫ
    }

    for (Y = MinValue; Y <= MaxValue; Y++)
    {
        Amount += HistGram[Y];        //  ��������
    }

    PixelIntegral = 0;
    for (Y = MinValue; Y <= MaxValue; Y++)
    {
        PixelIntegral += HistGram[Y] * Y;//�Ҷ�ֵ����
    }
    SigmaB = -1;
    for (Y = MinValue; Y < MaxValue; Y++)
    {
        PixelBack = PixelBack + HistGram[Y];    //ǰ�����ص���
        PixelFore = Amount - PixelBack;         //�������ص���
        OmegaBack = (double)PixelBack / Amount;//ǰ�����ذٷֱ�
        OmegaFore = (double)PixelFore / Amount;//�������ذٷֱ�
        PixelIntegralBack += HistGram[Y] * Y;  //ǰ���Ҷ�ֵ
        PixelIntegralFore = PixelIntegral - PixelIntegralBack;//�����Ҷ�ֵ
        MicroBack = (double)PixelIntegralBack / PixelBack;//ǰ���ҶȰٷֱ�
        MicroFore = (double)PixelIntegralFore / PixelFore;//�����ҶȰٷֱ�
        Sigma = OmegaBack * OmegaFore * (MicroBack - MicroFore) * (MicroBack - MicroFore);//g
        if (Sigma > SigmaB)//����������䷽��g
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