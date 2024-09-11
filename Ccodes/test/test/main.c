//#define _CRT_SECURE_NO_WARNINGS  1
//
//#include <stdio.h>
//
//typedef struct
//{
//	unsigned short Red, Green, Blue;
//}COLOR_RGB;
//
//unsigned short r, g, b;
//
//
//
//void RGB565_To_RGB888(unsigned short rgb, COLOR_RGB* color_rgb)
//{
//	color_rgb->Red = (unsigned char)((rgb & 0xF800) >> 8);
//	color_rgb->Green = (unsigned char)((rgb & 0x07E0) >> 3);
//	color_rgb->Blue = (unsigned char)((rgb & 0x001F) << 3);
//}
//
//int main() {
//	unsigned short rgb565_1 = 45088, rgb565_2 = 40992, rgb565_3 = 38976, rgb565_4 = 34880;
//	COLOR_RGB rgb1, rgb2, rgb3, rgb4, rgb888;
//	RGB565_To_RGB888(rgb565_1, &rgb1);
//	RGB565_To_RGB888(rgb565_2, &rgb2);
//	RGB565_To_RGB888(rgb565_3, &rgb3);
//	RGB565_To_RGB888(rgb565_4, &rgb4);
//	unsigned short red = ((rgb1.Red + rgb2.Red + rgb3.Red + rgb4.Red) / 4) >> 3;
//	unsigned short green = ((rgb1.Green + rgb2.Green + rgb3.Green + rgb4.Green) / 4) >> 2;
//	unsigned short blue = ((rgb1.Blue + rgb2.Blue + rgb3.Blue + rgb4.Blue) / 4) >> 3;
//
//	unsigned short rgb565 = (red << 11) + (green << 5) + blue;
//
//	printf("%d\n", rgb565);
//
//	RGB565_To_RGB888(rgb565, &rgb888);
//
//	printf("%d %d %d\n", rgb888.Red, rgb888.Green, rgb888.Blue);
//
//	//unsigned short rgb1 = 40747;
//
//	//r = rgb565 >> 11 << 3;
//	//g = (rgb565 & 2047) >> 5 << 2;
//	//b = (rgb565 & 31) << 3;
//
//	//printf("%d %d %d\n", r, g, b);
//
//	//r = (rgb565 & 0xF800) >> 8;
//	//g = (rgb565 & 0x07E0) >> 3;
//	//b = (rgb565 & 0x001F) << 3;
//
//	//printf("%d %d %d\n", r, g, b);
//
//	return 0;
//}
//
//
