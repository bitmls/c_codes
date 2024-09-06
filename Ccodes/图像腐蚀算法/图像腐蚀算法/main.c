#include <stdio.h>

#define H  8
#define W  8

#define WHITE  255
#define BLACK  0

unsigned short binary_image[H][W];

//void ImageCorrode(unsigned short (*image)[W]) {
//	// ����ṹԪ��
//	unsigned short structural_element[2][2] = {
//		1,0,
//		1,1
//	};  // �ṹԪ��ԭ��λ��Ϊ(1,0)
//
//	unsigned short corroded_image[H][W] = { 0 };  // ����ʴ���ͼ��
//
//	// ��ʴͼ��
//	for (int i = 0; i < H; i++) {
//		for (int j = 0; j < W; j++) {
//			// �ж��Ƿ����
//			if (i + 1 >= H || j + 1 >= W)
//				continue;
//			// �ж��Ƿ���ṹԪ���غϣ����غ����¼ԭ����Ϣ
//			if (image[i][j] == structural_element[0][0] &&
//				image[i + 1][j] == structural_element[1][0] &&
//				image[i + 1][j + 1] == structural_element[1][1]) {
//				corroded_image[i + 1][j] = 1;
//			}
//		}
//	}
//
//	// ����ʴͼ��ֵ��ԭͼ��
//	for (int i = 0; i < H; i++) {
//		for (int j = 0; j < W; j++) {
//			image[i][j] = corroded_image[i][j];
//		}
//	}
//}

void ImageCorrode(unsigned short(*image)[W]) {
    // ����ṹԪ��
    unsigned short structural_element[2][2] = {
        {WHITE,BLACK},
        {WHITE,WHITE}
    };  // �ṹԪ��ԭ��λ��Ϊ(1,0)

    unsigned short corroded_image[H][W];  // ����ʴ���ͼ��

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            corroded_image[i][j] = BLACK;
        }
    }

    // ��ʴͼ��
    for (int i = 0; i < H - 1; i++) {
        for (int j = 0; j < W - 1; j++) {
            //// �ж��Ƿ����
            //if (i + 1 < H || j + 1 < W) {
                // �ж��Ƿ���ṹԪ���غϣ����غ����¼ԭ����Ϣ
                if (image[i][j] == structural_element[0][0] &&
                    image[i + 1][j] == structural_element[1][0] &&
                    image[i + 1][j + 1] == structural_element[1][1]) {
                    corroded_image[i + 1][j] = WHITE;
                }
            //}
        }
    }

    // ����ʴͼ��ֵ��ԭͼ��
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            binary_image[i][j] = corroded_image[i][j];
        }
    }
}

void PrintImage(unsigned short(*image)[W]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			printf("%4d ", image[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
	unsigned short bin_image[H][W] = {
		    0,    0,    0,    0,    0,    0,    0,WHITE,
		    0,    0,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,
		    0,    0,    0,    0,WHITE,WHITE,WHITE,    0,
		    0,WHITE,    0,WHITE,WHITE,WHITE,    0,    0,
		    0,    0,WHITE,    0,WHITE,WHITE,WHITE,    0,
		    0,    0,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,
		WHITE,    0,WHITE,    0,WHITE,WHITE,WHITE,WHITE,
		    0,    0,    0,    0,WHITE,WHITE,WHITE,0
	};

	PrintImage(bin_image);

	ImageCorrode(bin_image);

	PrintImage(binary_image);

	//ImageCorrode(bin_image);

	//PrintImage(binary_image);

	return 0;
}