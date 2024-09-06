#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>


#define int16   short
#define uint32  unsigned int
#define int32   int
#define uint8   unsigned char

#define MT9V03X_CSI_H  120
#define MT9V03X_CSI_W  188

/***************************************************************
* 函数名称：GetOSTU(mt9v03x_csi_image); 大津法
* 函数输入：摄像头传感器图像数组（mt9v03x_csi_image）
* 函数输出：阈值大小 （Threshold）
* 功能说明：求阈值大小
***************************************************************/
uint8 GetOSTU(uint8 tmImage[MT9V03X_CSI_H][MT9V03X_CSI_W])
{
    int16 i, j;
    uint32 Amount = 0;
    uint32 PixelBack = 0;
    uint32 PixelIntegralBack = 0;
    uint32 PixelIntegral = 0;
    int32 PixelIntegralFore = 0;
    int32 PixelFore = 0;
    double OmegaBack, OmegaFore, MicroBack, MicroFore, SigmaB, Sigma; // 类间方差; 
    int16 MinValue, MaxValue;
    uint8 Threshold = 0;
    uint8 HistoGram[256];              //  

    for (j = 0; j < 256; j++)  HistoGram[j] = 0; //初始化灰度直方图 

    for (j = 0; j < MT9V03X_CSI_H; j++)
    {
        for (i = 0; i < MT9V03X_CSI_W; i++)
        {
            HistoGram[tmImage[j][i]]++; //统计灰度级中每个像素在整幅图像中的个数
        }
    }

    for (MinValue = 0; MinValue < 256 && HistoGram[MinValue] == 0; MinValue++);        //获取最小灰度的值
    for (MaxValue = 255; MaxValue > MinValue && HistoGram[MinValue] == 0; MaxValue--); //获取最大灰度的值

    if (MaxValue == MinValue)     return MaxValue;         // 图像中只有一个颜色    
    if (MinValue + 1 == MaxValue)  return MinValue;        // 图像中只有二个颜色

    for (j = MinValue; j <= MaxValue; j++)    Amount += HistoGram[j];        //  像素总数

    PixelIntegral = 0;
    for (j = MinValue; j <= MaxValue; j++)
    {
        PixelIntegral += HistoGram[j] * j;//灰度值总数
    }
    SigmaB = -1;
    for (j = MinValue; j < MaxValue; j++)
    {
        PixelBack = PixelBack + HistoGram[j];   //前景像素点数
        PixelFore = Amount - PixelBack;         //背景像素点数
        OmegaBack = (double)PixelBack / Amount;//前景像素百分比
        OmegaFore = (double)PixelFore / Amount;//背景像素百分比
        PixelIntegralBack += HistoGram[j] * j;  //前景灰度值
        PixelIntegralFore = PixelIntegral - PixelIntegralBack;//背景灰度值
        MicroBack = (double)PixelIntegralBack / PixelBack;   //前景灰度百分比
        MicroFore = (double)PixelIntegralFore / PixelFore;   //背景灰度百分比
        Sigma = OmegaBack * OmegaFore * (MicroBack - MicroFore) * (MicroBack - MicroFore);//计算类间方差
        if (Sigma > SigmaB)                    //遍历最大的类间方差g //找出最大类间方差以及对应的阈值
        {
            SigmaB = Sigma;
            Threshold = j;
        }
    }
    return Threshold;                        //返回最佳阈值;
}


int main()
{
    uint8 arr[MT9V03X_CSI_H][MT9V03X_CSI_W] = { 0 };

    for(int i = 0; i < MT9V03X_CSI_H - 100; i++)
        for(int j = 0; j < MT9V03X_CSI_W - 100; j++)
            arr[i][j] = 100;

    for (int i = MT9V03X_CSI_H - 100; i < MT9V03X_CSI_H; i++)
        for (int j = MT9V03X_CSI_W - 100; j < MT9V03X_CSI_W; j++)
            arr[i][j] = 200;

    unsigned int num = GetOSTU(arr);

    printf("%d\n", num);

    return 0;
}