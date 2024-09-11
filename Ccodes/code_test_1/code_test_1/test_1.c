#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


typedef struct PID {
	float kp;
	float ki;
	float kd;
}PID_info_struct;

PID_info_struct motor_PID = { 1.5, 0.0, 0.5 };

// 编码器值
int encoder_num = 0;

// 目标编码器值
int target_speed = 40;

int limit(int num, int max, int min) {
	if (num > max)
		num = max;
	else if (num < min)
		num = min;
	return num;
}

// PID控制器，输入为编码器差值，输出为PWM
int PID_motor_ctrl(int error) {
	int pwm = 0;
	static int last_error = 0;  // 保存上次误差
	static int integral_error = 0;  // 积分误差

	integral_error += error;  // 每次将当前误差累加
	integral_error = limit(integral_error, 20, -20);

	pwm = motor_PID.kp * error +
		  motor_PID.ki * integral_error +
		  motor_PID.kd * (error - last_error);

	last_error = error;  // 将这次编码器误差值保存，作为下一次计算使用
	return 100 * pwm;
}

int main() {
	int pwm = 0;

	while (1) {
		scanf("%d", &encoder_num);
		pwm = PID_motor_ctrl(target_speed - encoder_num);
		printf("%d\n", pwm);
	}

	return 0;
}