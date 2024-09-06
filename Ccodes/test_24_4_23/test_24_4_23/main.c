#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

enum {
	// normal
	NORMAL,

	// benring part
	BENRING_RECOG = 30000,
	BENRING_TRACE,
	BENRING_DEPATURE,

	// barrier part
	BARRIER_LEFT = 20000,
	BARRIER_STRAIGHT,
	BARRIER_RIGHT,
};

int car_status = 0;

float angle_z = 0;
int encoder_count = 0;

bool encoder_flag = false;
bool angle_flag = false;

void status(void) {
	switch (car_status) {
	case BENRING_RECOG:
		encoder_flag = true;  // 开始计距
		if (encoder_count > 140 * 30) {  // 140一厘米
			// 开始转向
			if (!angle_flag) {
				angle_flag = true;
				angle_z = 0;
			}
			// 转向
			// 判断是左苯环还是右苯环
			// 
			// 
			// 判断是否到达相应角度
			if (abs(angle_z) > 30) {
				car_status = BENRING_TRACE;
				angle_flag = false;
				encoder_flag = false;
				encoder_count = 0;
			}
		}
		break;
	case BENRING_TRACE:
		break;
	case BENRING_DEPATURE:
		break;
	}
}

void adc(int adc) {
	if (adc > 10) {
		if(car_status == NORMAL)
			car_status = BENRING_RECOG;
		if(car_status = BENRING_TRACE)
			car_status = BENRING_DEPATURE;
	}
}

int main()
{
	while (1) {

	}

	return 0;
}