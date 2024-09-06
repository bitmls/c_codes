#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>


#define int16   short
#define uint32  unsigned int
#define int32   int
#define uint8   unsigned char

#define MT9V03X_CSI_H  120
#define MT9V03X_CSI_W  188

/***************************************************************
* �������ƣ�GetOSTU(mt9v03x_csi_image); ���
* �������룺����ͷ������ͼ�����飨mt9v03x_csi_image��
* �����������ֵ��С ��Threshold��
* ����˵��������ֵ��С
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
    double OmegaBack, OmegaFore, MicroBack, MicroFore, SigmaB, Sigma; // ��䷽��; 
    int16 MinValue, MaxValue;
    uint8 Threshold = 0;
    uint8 HistoGram[256];              //  

    for (j = 0; j < 256; j++)  HistoGram[j] = 0; //��ʼ���Ҷ�ֱ��ͼ 

    for (j = 0; j < MT9V03X_CSI_H; j++)
    {
        for (i = 0; i < MT9V03X_CSI_W; i++)
        {
            HistoGram[tmImage[j][i]]++; //ͳ�ƻҶȼ���ÿ������������ͼ���еĸ���
        }
    }

    for (MinValue = 0; MinValue < 256 && HistoGram[MinValue] == 0; MinValue++);        //��ȡ��С�Ҷȵ�ֵ
    for (MaxValue = 255; MaxValue > MinValue && HistoGram[MinValue] == 0; MaxValue--); //��ȡ���Ҷȵ�ֵ

    if (MaxValue == MinValue)     return MaxValue;         // ͼ����ֻ��һ����ɫ    
    if (MinValue + 1 == MaxValue)  return MinValue;        // ͼ����ֻ�ж�����ɫ

    for (j = MinValue; j <= MaxValue; j++)    Amount += HistoGram[j];        //  ��������

    PixelIntegral = 0;
    for (j = MinValue; j <= MaxValue; j++)
    {
        PixelIntegral += HistoGram[j] * j;//�Ҷ�ֵ����
    }
    SigmaB = -1;
    for (j = MinValue; j < MaxValue; j++)
    {
        PixelBack = PixelBack + HistoGram[j];   //ǰ�����ص���
        PixelFore = Amount - PixelBack;         //�������ص���
        OmegaBack = (double)PixelBack / Amount;//ǰ�����ذٷֱ�
        OmegaFore = (double)PixelFore / Amount;//�������ذٷֱ�
        PixelIntegralBack += HistoGram[j] * j;  //ǰ���Ҷ�ֵ
        PixelIntegralFore = PixelIntegral - PixelIntegralBack;//�����Ҷ�ֵ
        MicroBack = (double)PixelIntegralBack / PixelBack;   //ǰ���ҶȰٷֱ�
        MicroFore = (double)PixelIntegralFore / PixelFore;   //�����ҶȰٷֱ�
        Sigma = OmegaBack * OmegaFore * (MicroBack - MicroFore) * (MicroBack - MicroFore);//������䷽��
        if (Sigma > SigmaB)                    //����������䷽��g //�ҳ������䷽���Լ���Ӧ����ֵ
        {
            SigmaB = Sigma;
            Threshold = j;
        }
    }
    return Threshold;                        //���������ֵ;
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