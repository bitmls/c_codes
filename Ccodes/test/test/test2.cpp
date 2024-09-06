#include <stdio.h>

#define SCC8660_H  10
#define SCC8660_W  10

#define WHITE  255

unsigned short image[SCC8660_H][SCC8660_W];

int Get_Error(unsigned short (*image)[SCC8660_W])
{
    int error = 0;
    for (int i = 0; i < SCC8660_H; i++)
    {
        for (int j = 0; j < SCC8660_W; j++)
        {
            if (i <= 4)  // 左半部分
            {
                if (image[i][j] == WHITE)
                {
                    error -= 1;
                }
            }
            else  // 右半部分
            {
                if (image[i][j] == WHITE)
                {
                    error += 1;
                }
            }
        }
    }
    return error;
}

int main() {
    unsigned short image[SCC8660_H][SCC8660_W] = {
        255,  0,    255,  0,    255,  0,    255,  0,    255,  0,    
        0,    255,  0,    255,  0,    255,  0,    255,  0,    255,  
        255,  0,    255,  0,    255,  0,    255,  0,    255,  0,    
        0,    255,  0,    255,  0,    255,  0,    255,  0,    255,  
        255,  0,    255,  0,    255,  0,    255,  0,    255,  0,    
        0,    255,  0,    255,  0,    255,  0,    255,  0,    255,  
        255,  0,    255,  0,    255,  0,    255,  0,    255,  0,    
        0,    255,  0,    255,  0,    255,  0,    255,  0,    255,  
        255,  0,    255,  0,    255,  0,    255,  0,    255,  0,    
        0,    255,  0,    255,  0,    255,  0,    255,  0,    255
    };

    int error;

    error = Get_Error(image);

    printf("%d\n",   error);

    return 0;
}