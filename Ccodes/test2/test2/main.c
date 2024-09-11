#define _CRT_SECURE_NO_WARNINGS  1

//#include	<stdio.h>
//int		main(void)
//{
//	int	F;
//	int C;
//
//	scanf("%d", &F);
//	C = 5 * (F - 32) / 9;
//	printf("摄氏温度为%d", C);
//
//	return	0;
//}


//#include	<stdio.h>
//int		main(void)
//{
//	int i, j;
//	int num[3];
//
//	for (i = 0; i < 3; i++)
//		scanf("%d", &num[i]);
//
//	for (i = 2; i > 0; i--) {
//		for (j = 2; j > 0; j--) {
//			if (num[j] > num[j - 1]) {
//				num[j] = num[j] ^ num[j - 1];
//				num[j - 1] = num[j] ^ num[j - 1];
//				num[j] = num[j] ^ num[j - 1];
//			}
//		}
//	}
//	for (i = 0; i < 3; i++)
//		printf("%d ", num[i]);
//
//	return	0;
//}


//#include	<stdio.h>
//int		main(void)
//{
//	int i, j = 0;
//	char num[10];
//
//	gets(num);
//
//	for (i = 0; i < 10; i++) {
//		if (num[i] == '5')
//			j++;
//	}
//	printf("%d", j);
//
//	return	0;
//}


//#include	<stdio.h>
//int		jc(int num)
//{
//	int i;
//	int j = 1;
//
//	for (i = 1; i <= num; i++) {
//		j *= i;
//	}
//	return	j;
//}
//int		add(int n)
//{
//	int i;
//	int sum = 0;
//
//	for (i = 1; i <= n; i++) {
//		sum += jc(i);
//	}
//	return sum;
//}
//int		main(void)
//{
//	int n;
//
//	scanf("%d", &n);
//	printf("%d", add(n));
//
//	return 0;
//}


//#include	<stdio.h>
//int		main(void)
//{
//	double i, j, s = 100.0, d = 50.0;
//
//	for (i = 1; i <= 10; i++) {
//		d /= 2;
//	}
//	printf("第10次反弹%f米\n", d);
//
//	for (i = 1, j = 50.0; i < 10; i++) {
//		s += j * 2;
//		j /= 2;
//	}
//	printf("第10次落地时共经过%f米\n", s);
//
//	return	0;
//}


//#include	<stdio.h>
//int		main(void)
//{
//	int n;
//	int i, j, k;
//
//	scanf("%d", &n);
//
//	for (i = 1; i <= n; i++) {
//		for (j = 1; j <= n - i; j++) {
//			putchar(' ');
//		}
//		k = i - 1;
//		for (j = 1; j <= (2 * i - 1); j++) {
//			if (j <= i)
//				printf("%d", j);
//			else {
//				printf("%d", k);
//				k--;
//			}
//		}
//		putchar('\n');
//	}
//
//	return	0;
//}


//#include	<stdio.h>
//int		main(void)
//{
//	int x;
//	int i, j, k = 0;
//	int a[3][4] = { {5,7,13,34},{78,26,12,19},{63,97,81,15} };
//
//	scanf("%d", &x);
//
//	for (i = 0; i < 3; i++) {
//		for (j = 0; j < 4; j++) {
//			if (a[i][j] == x) {
//				printf("第%d行第%d列", i + 1, j + 1);
//				k++;
//				break;
//			}
//			else if (i == 2 && j == 3 && a[2][3] != x)
//				printf("找不到");
//		}
//		if (k == 1)
//			break;
//	}
//	return	0;
//}


//#include	<stdio.h>
//double		fact(int n)
//{
//	int i;
//	int j = 1;
//
//	for (i = 1; i <= n; i++) {
//		j *= i;
//	}
//	return	j;
//}
//int		main(void)
//{
//	int m, n;
//
//	scanf("%d%d", &m, &n);
//
//	printf("result=%f", fact(n) / fact(m) * fact(n - m));
//
//	return	0;
//}


//#include	<stdio.h>
//#define NUMBER 5
//int		main(void)
//{
//	int i, j = 0;
//	int n;
//	int flowerbed[NUMBER];
//
//	for (i = 0; i < NUMBER; i++)
//		scanf("%d", &flowerbed[i]);
//
//	scanf("%d", &n);
//
//	for (i = 0; i < NUMBER; i++) {
//		if (flowerbed[i] == 1) {
//			if (i == 0) {
//				if (flowerbed[i + 1] == 0 && flowerbed[i + 2] == 0 && flowerbed[i + 3] == 0)
//					j++;
//			}
//			else if (i == NUMBER - 1) {
//				if (flowerbed[i - 1] == 0 && flowerbed[i - 2] == 0 && flowerbed[i - 3] == 0)
//					j++;
//			}
//			else
//				if (flowerbed[i + 1] == 0 && flowerbed[i + 2] == 0 && flowerbed[i + 3] == 0 && flowerbed[i - 1] == 0 && flowerbed[i - 2] == 0 && flowerbed[i - 3] == 0)
//					j++;
//		}
//	}
//	if (n <= j)
//		printf("true");
//	else
//		printf("false");
//
//	return	0;
//}


//#include	<stdio.h>
//#include	<string.h>
//#define NUMBER 6
//int		main(void)
//{
//	int i;
//	char num[NUMBER];
//
//	gets(num);
//
//	for (i = 0; i < NUMBER - 1; i++) {
//		if (num[i] < '0' && num[i]>'9') {
//			printf("This is a error");
//			break;
//		}
//		else if (i == NUMBER - 2 && num[i] >= '0' && num[i] <= '9') {
//			printf("字符串的长度为%d\n", strlen(num));
//			printf("转换后数字为：");
//			for (i = 0; i < NUMBER; i++)
//				printf("%d", num[i]);
//		}
//	}
//
//	return	0;
//}



//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	char str[100] = { 0 };
//	long long int num = 0;
//	int flag = 1;  //是否全为数字的标志
//
//	scanf("%s", str);
//
//	int len = strlen(str);
//	int n = pow(10, len - 1);
//
//	for (int i = 0; i < len; i++)
//	{
//		if (str[i] < '0' || str[i] > '9')
//		{
//			printf("This is error\n");
//			flag = 0;
//			break;
//		}
//		else
//		{
//			num += (str[i] - 48) * n;
//			n /= 10;
//		}
//	}
//
//	if (flag)
//	{
//		printf("%d\n", num);
//	}
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int max = 0;  //存储最大值
//
//	for (int i = 0; i < 3; i++)
//	{
//		int temp = 0;
//		scanf("%d", &temp);
//
//		static flag = 1;
//		if (flag)
//		{
//			max = temp;  //将第一次输入的数赋值给max
//			flag = 0;
//		}
//
//		//判断是否大于最大值
//		if (temp > max)
//		{
//			max = temp;
//		}
//	}
//
//	printf("%d\n", max);
//
//	return 0;
//}

//#include <stdio.h>
//
//int days[2][12] = {  // 存储对应平年和闰年的天数
//	{31,28,31,30,31,30,31,31,30,31,30,31},
//	{31,29,31,30,31,30,31,31,30,31,30,31} };
//
////判断是否为闰年，是闰年则返回1，否则返回0
//int IsLeap(int year) {
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
//		return 1;
//	}
//	return 0;
//}
//
////修改为后一天的日期
//void increment_date(int* y, int* m, int* d) {
//	if (*m < 1 || *m > 12) {
//		printf("月份输入错误\n");
//		return;
//	}
//	else if (*d < 1 || *d > 31) {
//		printf("日期输入错误\n");
//		return;
//	}
//
//	(*d)++;  //日期+1
//
//	if (*d > days[IsLeap(*y)][*m - 1]) {
//		(*m)++;  //月份+1
//		if (*m > 12) {
//			(*y)++;  //年份+1
//			*m = 1;  //月份归为1月
//		}
//		*d = 1;  //日期归为第一天
//	}
//}
//
////修改为前一天的日期
//void decrement_date(int* y, int* m, int* d) {
//	if (*m < 1 || *m > 12) {
//		printf("月份输入错误\n");
//		return;
//	}
//	else if (*d < 1 || *d > 31) {
//		printf("日期输入错误\n");
//		return;
//	}
//
//	(*d)--;  //日期-1
//
//	if (*d < 1) {
//		(*m)--;
//		if (*m < 1) {
//			(*y)--;  //年份-1
//			*m = 12;  //月份归为12月
//		}
//		*d = days[IsLeap(*y)][*m - 1];  //日期归为当月最后一天
//	}
//}
//
//int main() {
//	int year, month, day;
//
//	scanf("%d%d%d", &year, &month, &day);
//
//	printf("%d年%d月%d日\n", year, month, day);
//
//	//decrement_date(&year, &month, &day);
//
//	//printf("%d年%d月%d日\n", year, month, day);
//
//	increment_date(&year, &month, &day);
//
//	printf("%d年%d月%d日\n", year, month, day);
//
//	return 0;
//}



//#include <stdio.h>
//#include <math.h>
//
//typedef struct {
//    double w; // 实部
//    double x, y, z; // 虚部
//} Quaternion;
//
//// 四元数乘法
//Quaternion multiplyQuaternions(Quaternion q1, Quaternion q2) {
//    Quaternion result;
//    result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
//    result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
//    result.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
//    result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
//    return result;
//}
//
//// 角速度向量转旋转矩阵
//void omegaToRotationMatrix(double omega[3], double matrix[3][3]) {
//    matrix[0][0] = cos(omega[2]) * cos(omega[1]);
//    matrix[0][1] = -sin(omega[2]) * cos(omega[0]) + cos(omega[2]) * sin(omega[1]) * sin(omega[0]);
//    matrix[0][2] = sin(omega[2]) * sin(omega[0]) + cos(omega[2]) * sin(omega[1]) * cos(omega[0]);
//    matrix[1][0] = sin(omega[2]) * cos(omega[1]);
//    matrix[1][1] = cos(omega[2]) * cos(omega[0]) + sin(omega[2]) * sin(omega[1]) * sin(omega[0]);
//    matrix[1][2] = -cos(omega[2]) * sin(omega[0]) + sin(omega[2]) * sin(omega[1]) * cos(omega[0]);
//    matrix[2][0] = -sin(omega[1]);
//    matrix[2][1] = cos(omega[1]) * sin(omega[0]);
//    matrix[2][2] = cos(omega[1]) * cos(omega[0]);
//}
//
//int main() {
//    // 初始化当前时刻的四元数
//    Quaternion currentQuaternion = { 1.0, 0.0, 0.0, 0.0 };
//
//    // 陀螺仪测量的角速度（示例数据）
//    double angularVelocities[3] = { 10, 500, 10 }; // (x, y, z) 三轴角速度
//
//    // 采样周期和姿态变化量
//    double deltaTime = 0.01; // 采样周期
//    double deltaTheta[3]; // 姿态变化量
//
//    // 将角速度转换为旋转矩阵
//    double rotationMatrix[3][3];
//    omegaToRotationMatrix(angularVelocities, rotationMatrix);
//
//    // 计算姿态变化量
//    deltaTheta[0] = atan2(rotationMatrix[2][1], rotationMatrix[2][2]);
//    deltaTheta[1] = atan2(-rotationMatrix[2][0], sqrt(rotationMatrix[2][1] * rotationMatrix[2][1] + rotationMatrix[2][2] * rotationMatrix[2][2]));
//    deltaTheta[2] = atan2(rotationMatrix[1][0], rotationMatrix[0][0]);
//
//    // 将姿态变化量转换为四元数
//    Quaternion deltaQuaternion;
//    double halfDeltaTheta[3];
//    halfDeltaTheta[0] = 0.5 * deltaTheta[0];
//    halfDeltaTheta[1] = 0.5 * deltaTheta[1];
//    halfDeltaTheta[2] = 0.5 * deltaTheta[2];
//    deltaQuaternion.w = cos(halfDeltaTheta[0]) * cos(halfDeltaTheta[1]) * cos(halfDeltaTheta[2]) + sin(halfDeltaTheta[0]) * sin(halfDeltaTheta[1]) * sin(halfDeltaTheta[2]);
//    deltaQuaternion.x = sin(halfDeltaTheta[0]) * cos(halfDeltaTheta[1]) * cos(halfDeltaTheta[2]) - cos(halfDeltaTheta[0]) * sin(halfDeltaTheta[1]) * sin(halfDeltaTheta[2]);
//    deltaQuaternion.y = cos(halfDeltaTheta[0]) * sin(halfDeltaTheta[1]) * cos(halfDeltaTheta[2]) + sin(halfDeltaTheta[0]) * cos(halfDeltaTheta[1]) * sin(halfDeltaTheta[2]);
//    deltaQuaternion.z = cos(halfDeltaTheta[0]) * cos(halfDeltaTheta[1]) * sin(halfDeltaTheta[2]) - sin(halfDeltaTheta[0]) * sin(halfDeltaTheta[1]) * cos(halfDeltaTheta[2]);
//
//    // 更新当前时刻的四元数
//    currentQuaternion = multiplyQuaternions(currentQuaternion, deltaQuaternion);
//
//    // 输出当前姿态的四元数
//    printf("Current Quaternion: (%f, %f, %f, %f)\n", currentQuaternion.w, currentQuaternion.x, currentQuaternion.y, currentQuaternion.z);
//
//    return 0;
//}



//#include <stdio.h>
//#include <math.h>
//
//#define M_PI  3.14159265
//
//typedef struct {
//    double w; // 实部
//    double x, y, z; // 虚部
//} Quaternion;
//
//// 四元数乘法
//Quaternion multiplyQuaternions(Quaternion q1, Quaternion q2) {
//    Quaternion result;
//    result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
//    result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
//    result.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
//    result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
//    return result;
//}
//
////// 角速度向量转旋转矩阵
////void omegaToRotationMatrix(double omega[3], double matrix[3][3]) {
////    double omegaRad[3];
////    omegaRad[0] = omega[0] * M_PI / 180.0;
////    omegaRad[1] = omega[1] * M_PI / 180.0;
////    omegaRad[2] = omega[2] * M_PI / 180.0;
////
////    matrix[0][0] = cos(omegaRad[2]) * cos(omegaRad[1]);
////    matrix[0][1] = -sin(omegaRad[2]) * cos(omegaRad[0]) + cos(omegaRad[2]) * sin(omegaRad[1]) * sin(omegaRad[0]);
////    matrix[0][2] = sin(omegaRad[2]) * sin(omegaRad[0]) + cos(omegaRad[2]) * sin(omegaRad[1]) * cos(omegaRad[0]);
////    matrix[1][0] = sin(omegaRad[2]) * cos(omegaRad[1]);
////    matrix[1][1] = cos(omegaRad[2]) * cos(omegaRad[0]) + sin(omegaRad[2]) * sin(omegaRad[1]) * sin(omegaRad[0]);
////    matrix[1][2] = -cos(omegaRad[2]) * sin(omegaRad[0]) + sin(omegaRad[2]) * sin(omegaRad[1]) * cos(omegaRad[0]);
////    matrix[2][0] = -sin(omegaRad[1]);
////    matrix[2][1] = cos(omegaRad[1]) * sin(omegaRad[0]);
////    matrix[2][2] = cos(omegaRad[1]) * cos(omegaRad[0]);
////}
//
//int main() {
//    // 初始化当前时刻的四元数
//    Quaternion currentQuaternion = { 1.0, 0.0, 0.0, 0.0 };
//
//    // 陀螺仪测量的角速度（示例数据，单位：度每秒）
//    double angularVelocities[3] = { 0, 100, 100 }; // (x, y, z) 三轴角速度
//
//    double last_angle_x = 0;
//    double last_angle_y = 0;
//    double last_angle_z = 0;
//
//    while (1) {
//        // 将角速度转换为旋转矩阵
//        //double rotationMatrix[3][3];
//
//        //scanf("%lf%lf%lf", &angularVelocities[0], &angularVelocities[1], &angularVelocities[2]);
//
//        //omegaToRotationMatrix(angularVelocities, rotationMatrix);
//
//        // 采样周期和姿态变化量（单位：秒、度）
//        double deltaTime = 0.01; // 采样周期
//        double deltaTheta[3]; // 姿态变化量（单位：度）
//
//        scanf("%lf%lf%lf", &angularVelocities[0], &angularVelocities[1], &angularVelocities[2]);
//
//        deltaTheta[0] = (angularVelocities[0] - last_angle_x) * deltaTime;
//        deltaTheta[1] = (angularVelocities[1] - last_angle_y) * deltaTime;
//        deltaTheta[2] = (angularVelocities[2] - last_angle_z) * deltaTime;
//
//        last_angle_x = angularVelocities[0];
//        last_angle_y = angularVelocities[1];
//        last_angle_z = angularVelocities[2];
//
//        //deltaTheta[0] = atan2(rotationMatrix[2][1], rotationMatrix[2][2]) * 180.0 / M_PI;
//        //deltaTheta[1] = atan2(-rotationMatrix[2][0], sqrt(rotationMatrix[2][1] * rotationMatrix[2][1] + rotationMatrix[2][2] * rotationMatrix[2][2])) * 180.0 / M_PI;
//        //deltaTheta[2] = atan2(rotationMatrix[1][0], rotationMatrix[0][0]) * 180.0 / M_PI;
//
//        // 将姿态变化量转换为四元数
//        Quaternion deltaQuaternion;
//        double halfDeltaTheta[3];
//        halfDeltaTheta[0] = 0.5 * deltaTheta[0] * M_PI / 180.0;
//        halfDeltaTheta[1] = 0.5 * deltaTheta[1] * M_PI / 180.0;
//        halfDeltaTheta[2] = 0.5 * deltaTheta[2] * M_PI / 180.0;
//        deltaQuaternion.w = cos(halfDeltaTheta[0]) * cos(halfDeltaTheta[1]) * cos(halfDeltaTheta[2]) + sin(halfDeltaTheta[0]) * sin(halfDeltaTheta[1]) * sin(halfDeltaTheta[2]);
//        deltaQuaternion.x = sin(halfDeltaTheta[0]) * cos(halfDeltaTheta[1]) * cos(halfDeltaTheta[2]) - cos(halfDeltaTheta[0]) * sin(halfDeltaTheta[1]) * sin(halfDeltaTheta[2]);
//        deltaQuaternion.y = cos(halfDeltaTheta[0]) * sin(halfDeltaTheta[1]) * cos(halfDeltaTheta[2]) + sin(halfDeltaTheta[0]) * cos(halfDeltaTheta[1]) * sin(halfDeltaTheta[2]);
//        deltaQuaternion.z = cos(halfDeltaTheta[0]) * cos(halfDeltaTheta[1]) * sin(halfDeltaTheta[2]) - sin(halfDeltaTheta[0]) * sin(halfDeltaTheta[1]) * cos(halfDeltaTheta[2]);
//
//        // 更新当前时刻的四元数
//        currentQuaternion = multiplyQuaternions(currentQuaternion, deltaQuaternion);
//
//        // 输出当前姿态的四元数
//        printf("Current Quaternion: (%f, %f, %f, %f)\n", currentQuaternion.w, currentQuaternion.x, currentQuaternion.y, currentQuaternion.z);
//
//        // 将四元数转换为欧拉角
//        double roll, pitch, yaw;
//        roll = atan2(2 * (currentQuaternion.w * currentQuaternion.x + currentQuaternion.y * currentQuaternion.z),
//            1 - 2 * (currentQuaternion.x * currentQuaternion.x + currentQuaternion.y * currentQuaternion.y));
//        pitch = asin(2 * (currentQuaternion.w * currentQuaternion.y - currentQuaternion.z * currentQuaternion.x));
//        yaw = atan2(2 * (currentQuaternion.w * currentQuaternion.z + currentQuaternion.x * currentQuaternion.y),
//            1 - 2 * (currentQuaternion.y * currentQuaternion.y + currentQuaternion.z * currentQuaternion.z));
//
//        // 将欧拉角转换为角度（单位：度）
//        roll = roll * 180.0 / M_PI;
//        pitch = pitch * 180.0 / M_PI;
//        yaw = yaw * 180.0 / M_PI;
//
//        // 输出修改后的角度数值
//        printf("Modified Angles: Roll=%.2f, Pitch=%.2f, Yaw=%.2f\n", roll, pitch, yaw);
//
//        system("pause");
//    }
//
//    return 0;
//}


//#include <stdio.h>
//#include <math.h>
//
//#define PI  3.14159265
//#define RAD_TO_ANGLE(X)  ((X) * 180.0) / PI
//#define ANGLE_TO_RAD(X)  ((X) * PI) / 180.0
//
////三轴陀螺仪数据类型
//typedef struct
//{
//    double roll;   //翻滚角
//    double pitch;  //俯仰角
//    double yaw;    //偏航角
//
//    float deltaTime;  //执行频率,单位为ms
//}gyroscope_info_struct;
//
////四元数数据类型
//typedef struct
//{
//    double w;        //实部
//    double x, y, z;  //虚部
//}Quaternion;
//
//gyroscope_info_struct gyro = { 0.0, 0.0, 0.0, 10 };
//Quaternion currentQuaternion = { 1.0, 0.0, 0.0, 0.0 };
//
//// 四元数乘法
//// 参数：    第一个四元数
//// 参数：    第二个四元数
//// 返回参数：返回相乘后得到的新四元数
//// 备注：    无
//Quaternion MultiplyQuaternions(Quaternion q1, Quaternion q2)
//{
//    Quaternion result;
//    result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
//    result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
//    result.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
//    result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
//    return result;
//}
//
//// 角速度向量转旋转矩阵
//// 参数：    输入三个角速度向量值
//// 参数：    存储转换后的旋转矩阵
//// 返回参数：void
//// 备注：    无
//void OmegaToRotationMatrix(double omega[3], double matrix[3][3])
//{
//    double omegaRad[3];
//    omegaRad[0] = omega[0] * PI / 180.0;
//    omegaRad[1] = omega[1] * PI / 180.0;
//    omegaRad[2] = omega[2] * PI / 180.0;
//
//    matrix[0][0] = cos(omega[2]) * cos(omega[1]);
//    matrix[0][1] = -sin(omega[2]) * cos(omega[0]) + cos(omega[2]) * sin(omega[1]) * sin(omega[0]);
//    matrix[0][2] = sin(omega[2]) * sin(omega[0]) + cos(omega[2]) * sin(omega[1]) * cos(omega[0]);
//    matrix[1][0] = sin(omega[2]) * cos(omega[1]);
//    matrix[1][1] = cos(omega[2]) * cos(omega[0]) + sin(omega[2]) * sin(omega[1]) * sin(omega[0]);
//    matrix[1][2] = -cos(omega[2]) * sin(omega[0]) + sin(omega[2]) * sin(omega[1]) * cos(omega[0]);
//    matrix[2][0] = -sin(omega[1]);
//    matrix[2][1] = cos(omega[1]) * sin(omega[0]);
//    matrix[2][2] = cos(omega[1]) * cos(omega[0]);
//}
//
//// 计算姿态变化量（单位：度）
//void CalculationDeltaTheta(double deltaTheta[3], double rotationMatrix[3][3])
//{
//    deltaTheta[0] = atan2(rotationMatrix[2][1], rotationMatrix[2][2]) * 180.0 / PI;
//    deltaTheta[1] = atan2(-rotationMatrix[2][0], sqrt(rotationMatrix[2][1] * rotationMatrix[2][1] + rotationMatrix[2][2] * rotationMatrix[2][2])) * 180.0 / PI;
//    deltaTheta[2] = atan2(rotationMatrix[1][0], rotationMatrix[0][0]) * 180.0 / PI;
//}
//
//// 姿态变化量转换为四元数
//Quaternion ThetaToQuaternion(double deltaTheta[3])
//{
//    Quaternion deltaQuaternion;
//    double halfDeltaTheta[3];
//    halfDeltaTheta[0] = 0.5 * deltaTheta[0] * PI / 180.0;
//    halfDeltaTheta[1] = 0.5 * deltaTheta[1] * PI / 180.0;
//    halfDeltaTheta[2] = 0.5 * deltaTheta[2] * PI / 180.0;
//    deltaQuaternion.w = cos(halfDeltaTheta[0]) * cos(halfDeltaTheta[1]) * cos(halfDeltaTheta[2]) + sin(halfDeltaTheta[0]) * sin(halfDeltaTheta[1]) * sin(halfDeltaTheta[2]);
//    deltaQuaternion.x = sin(halfDeltaTheta[0]) * cos(halfDeltaTheta[1]) * cos(halfDeltaTheta[2]) - cos(halfDeltaTheta[0]) * sin(halfDeltaTheta[1]) * sin(halfDeltaTheta[2]);
//    deltaQuaternion.y = cos(halfDeltaTheta[0]) * sin(halfDeltaTheta[1]) * cos(halfDeltaTheta[2]) + sin(halfDeltaTheta[0]) * cos(halfDeltaTheta[1]) * sin(halfDeltaTheta[2]);
//    deltaQuaternion.z = cos(halfDeltaTheta[0]) * cos(halfDeltaTheta[1]) * sin(halfDeltaTheta[2]) - sin(halfDeltaTheta[0]) * sin(halfDeltaTheta[1]) * cos(halfDeltaTheta[2]);
//    return deltaQuaternion;
//}
//
//// 更新当前四元数
//Quaternion UpdateQuaternion(Quaternion currentQuaternion, Quaternion deltaQuaternion)
//{
//    return MultiplyQuaternions(currentQuaternion, deltaQuaternion);
//}
//
//// 将四元数转换为欧拉角
//void QuaternionToEulerAngle(Quaternion currentQuaternion, double* roll, double* pitch, double* yaw)
//{
//    *roll = atan2(2 * (currentQuaternion.w * currentQuaternion.x + currentQuaternion.y * currentQuaternion.z),
//        1 - 2 * (currentQuaternion.x * currentQuaternion.x + currentQuaternion.y * currentQuaternion.y));
//    *pitch = asin(2 * (currentQuaternion.w * currentQuaternion.y - currentQuaternion.z * currentQuaternion.x));
//    *yaw = atan2(2 * (currentQuaternion.w * currentQuaternion.z + currentQuaternion.x * currentQuaternion.y),
//        1 - 2 * (currentQuaternion.y * currentQuaternion.y + currentQuaternion.z * currentQuaternion.z));
//}
//
//// 把欧拉角转换为角度
//void EulerAngleToAngle(double* roll, double* pitch, double* yaw)
//{
//    *roll = RAD_TO_ANGLE(*roll);
//    *pitch = RAD_TO_ANGLE(*pitch);
//    *yaw = RAD_TO_ANGLE(*yaw);
//}
//
//// 四元数解算陀螺仪
//void QuaternionCalculationGyroscope(void)
//{
//    double angularVelocities[3];      // 通过陀螺仪测得的三轴角速度
//    double matrix[3][3];  // 转换后的旋转矩阵
//    angularVelocities[0] = ANGLE_TO_RAD(1);
//    angularVelocities[1] = ANGLE_TO_RAD(1);
//    angularVelocities[2] = ANGLE_TO_RAD(2);
//    OmegaToRotationMatrix(angularVelocities, matrix);  // 得到当前的旋转矩阵
//
//    double deltaTheta[3];  //姿态变化量
//    CalculationDeltaTheta(deltaTheta, matrix);  // 计算姿态变化量
//    Quaternion deltaQuaternion = ThetaToQuaternion(deltaTheta);  // 把姿态变化量转换为四元数
//    currentQuaternion = UpdateQuaternion(currentQuaternion, deltaQuaternion);  // 更新四元数
//
//    QuaternionToEulerAngle(currentQuaternion, &gyro.roll, &gyro.pitch, &gyro.yaw);  // 将四元数转换为欧拉角
//    EulerAngleToAngle(&gyro.roll, &gyro.pitch, &gyro.yaw);
//}
//
//
//int main()
//{
//    while (1)
//    {
//        QuaternionCalculationGyroscope();
//
//        printf("%lf %lf %lf\n", gyro.roll, gyro.pitch, gyro.yaw);
//
//        system("pause");
//    }
//
//    return 0;
//}


//#include<stdio.h>
//#include<math.h>
//
//#define PI 3.1415926  // 圆周率
//#define SAMPLE_RATE 100.0  // 采样率，单位Hz
//#define SAMPLE_TIME (1.0 / SAMPLE_RATE)  // 采样周期，单位秒
//
//// 四元数结构体
//typedef struct {
//    double w;
//    double x;
//    double y;
//    double z;
//} Quaternion;
//
//// 将角度转换为弧度
//double deg2rad(double deg) {
//    return deg * PI / 180.0;
//}
//
//// 将弧度转换为角度
//double rad2deg(double rad) {
//    return rad * 180.0 / PI;
//}
//
//// 计算两个四元数的乘积
//Quaternion quaternion_multiply(Quaternion q1, Quaternion q2) {
//    Quaternion result;
//    result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
//    result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
//    result.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
//    result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
//    return result;
//}
//
//// 陀螺仪数据输入函数，模拟从传感器中获取角速度值
//void get_gyro_data(double* gyro_x, double* gyro_y, double* gyro_z) {
//    // 这里使用静态变量模拟传感器数据
//    static double t = 0.0;
//    *gyro_x = 20.0 * sin(2 * PI * 0.1 * t);
//    *gyro_y = 30.0 * sin(2 * PI * 0.2 * t);
//    *gyro_z = 40.0 * sin(2 * PI * 0.3 * t);
//    t += SAMPLE_TIME;
//}
//
//int main() {
//    double gyro_x, gyro_y, gyro_z;  // 角速度，单位度每秒
//    double angle_x = 0.0, angle_y = 0.0, angle_z = 0.0;  // 欧拉角，初始值为0
//    Quaternion q = { 1, 0, 0, 0 };  // 当前四元数
//
//    while (1) {
//        scanf("%lf%lf%lf", &gyro_x, &gyro_y, &gyro_z);
//        // 获取陀螺仪角速度数据
//        get_gyro_data(&gyro_x, &gyro_y, &gyro_z);
//
//        // 将角速度转换为弧度每秒
//        double omega_x = deg2rad(gyro_x);
//        double omega_y = deg2rad(gyro_y);
//        double omega_z = deg2rad(gyro_z);
//
//        // 计算角速度对应的四元数变化量
//        Quaternion delta_q;
//        delta_q.w = cos(omega_x / 2) * cos(omega_y / 2) * cos(omega_z / 2) + sin(omega_x / 2) * sin(omega_y / 2) * sin(omega_z / 2);
//        delta_q.x = sin(omega_x / 2) * cos(omega_y / 2) * cos(omega_z / 2) - cos(omega_x / 2) * sin(omega_y / 2) * sin(omega_z / 2);
//        delta_q.y = cos(omega_x / 2) * sin(omega_y / 2) * cos(omega_z / 2) + sin(omega_x / 2) * cos(omega_y / 2) * sin(omega_z / 2);
//        delta_q.z = cos(omega_x / 2) * cos(omega_y / 2) * sin(omega_z / 2) - sin(omega_x / 2) * sin(omega_y / 2) * cos(omega_z / 2);
//
//        // 更新当前四元数
//        q = quaternion_multiply(q, delta_q);
//
//        // 计算欧拉角，并输出结果
//        double qw2 = q.w * q.w;
//        double qx2 = q.x * q.x;
//        double qy2 = q.y * q.y;
//        double qz2 = q.z * q.z;
//        double sinr_cosp = 2 * (q.w * q.x + q.y * q.z);
//        double cosr_cosp = qw2 + qx2 - qy2 - qz2;
//        angle_x = rad2deg(atan2(sinr_cosp, cosr_cosp));
//        double sinp = 2 * (q.w * q.y - q.z * q.x);
//        if (fabs(sinp) >= 1)
//            angle_y = rad2deg(copysign(PI / 2, sinp));
//        else
//            angle_y = rad2deg(asin(sinp));
//        double siny_cosp = 2 * (q.w * q.z + q.x * q.y);
//        double cosy_cosp = qw2 - qx2 - qy2 + qz2;
//        angle_z = rad2deg(atan2(siny_cosp, cosy_cosp));
//        printf("angle_x:%f, angle_y:%f, angle_z:%f\n", angle_x, angle_y, angle_z);
//
//        //// 等待采样周期后继续循环
//        //usleep(SAMPLE_TIME * 1000000);
//        system("pause");
//    }
//
//    return 0;
//}



//#include <stdio.h>
//#include <math.h>
//
//#define PI  3.14159265
//
//#define RAD_TO_ANGLE(X)  (((X) * 180.0) / PI)
//#define ANGLE_TO_RAD(X)  (((X) / PI) * 180.0)
//
//typedef struct {
//    double w; // 实部
//    double x, y, z; // 虚部
//} Quaternion;
//
//// 四元数乘法
//Quaternion multiplyQuaternions(Quaternion q1, Quaternion q2) {
//    Quaternion result;
//    result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
//    result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
//    result.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
//    result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
//    return result;
//}
//
//Quaternion currentQ = { 1.0, 0.0, 0.0, 0.0 };  // 初始化四元数
//Quaternion deltaQ   = { 0.0, 0.0, 0.0, 0.0 };
//
//double roll = 0, pitch = 0, yaw = 0;
//
//double gyro_x = 0, gyro_y = 0, gyro_z = 0;  //陀螺仪获取到的角速度
//
////∆q = [cos(θ/2), sin(θ/2) * (ωx/θ), sin(θ/2) * (ωy/θ), sin(θ/2) * (ωz/θ)]
//
//int main()
//{
//    while (1)
//    {
//        //模拟陀螺仪测量到的角速度
//        scanf("%lf%lf%lf", &gyro_x, &gyro_y, &gyro_z);
//        gyro_x = ANGLE_TO_RAD(gyro_x);
//
//        deltaQ.w = 0;
//        deltaQ.x = sin(gyro_x / 2);
////        deltaQuaternion.w = cos(halfDeltaTheta[0]) * cos(halfDeltaTheta[1]) * cos(halfDeltaTheta[2]) + sin(halfDeltaTheta[0]) * sin(halfDeltaTheta[1]) * sin(halfDeltaTheta[2]);
////        deltaQuaternion.x = sin(halfDeltaTheta[0]) * cos(halfDeltaTheta[1]) * cos(halfDeltaTheta[2]) - cos(halfDeltaTheta[0]) * sin(halfDeltaTheta[1]) * sin(halfDeltaTheta[2]);
////        deltaQuaternion.y = cos(halfDeltaTheta[0]) * sin(halfDeltaTheta[1]) * cos(halfDeltaTheta[2]) + sin(halfDeltaTheta[0]) * cos(halfDeltaTheta[1]) * sin(halfDeltaTheta[2]);
////        deltaQuaternion.z = cos(halfDeltaTheta[0]) * cos(halfDeltaTheta[1]) * sin(halfDeltaTheta[2]) - sin(halfDeltaTheta[0]) * sin(halfDeltaTheta[1]) * cos(halfDeltaTheta[2]);
//    }
//
//    return 0;
//}



////#include <math.h>
//#define PI  3.1415926
//
//float Atan2(float y, float x, int infNum)
//{
//    int i;
//    float z = y / x, sum = 0.0f, temp;
//    float del = z / infNum;
//
//    for (i = 0; i < infNum; i++)
//    {
//        z = i * del;
//        temp = 1 / (z * z + 1) * del;
//        sum += temp;
//    }
//
//    if (x > 0)
//    {
//        return sum;
//    }
//    else if (y >= 0 && x < 0)
//    {
//        return sum + PI;
//    }
//    else if (y < 0 && x < 0)
//    {
//        return sum - PI;
//    }
//    else if (y > 0 && x == 0)
//    {
//        return PI / 2;
//    }
//    else if (y < 0 && x == 0)
//    {
//        return -1 * PI / 2;
//    }
//    else
//    {
//        return 0;
//    }
//}
//
//
//int main()
//{
//    printf("%f", )
//
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//    int a;
//    double numend = 1, num1 = 1;
//    for (a = 1; a <= 63; a++)
//    {
//        num1 *= 2;
//        numend += num1;
//    }
//    printf("%lf", numend);
//    return 0;
//}


//#include <stdio.h>
//#include <stdbool.h>
//#include <math.h>
//
//#define QUEUE_MAX  4
//
//typedef struct Queue {
//    float data[QUEUE_MAX];
//    int head;
//    int tail;
//}Queue;
//
//Queue filter_data;
//
//void init_queue(Queue* Q) {
//    for (int i = 0; i < QUEUE_MAX; i++)
//        Q->data[i] = 0;
//    Q->head = 0;
//    Q->tail = 0;
//}
//
//bool is_full_queue(Queue* Q) {
//    if ((Q->tail + 1) % QUEUE_MAX == Q->head)  // 判断队尾指针与队头指针是否相差一个元素
//        return true;
//    return false;
//}
//
//void en_queue(Queue* Q, float data) {
//    Q->data[Q->tail] = data;  // 队尾进入
//    Q->tail = (Q->tail + 1) % QUEUE_MAX;  // 将队尾指针+1，如果队尾指针到数组结尾回归数组开头
//}
//
//void de_queue(Queue* Q) {
//    Q->data[Q->head] = 0;
//    Q->head = (Q->head + 1) % QUEUE_MAX;  // 将队头指针+1，如果队头指针到数组结尾回归数组开头
//}
//
//float get_queue_avg(Queue* Q) {
//    float result = 0;
//    for (int i = 0; i < QUEUE_MAX; i++) {
//        result += Q->data[i];
//    }
//    return result /= QUEUE_MAX - 1;
//}
//
//float limiting_filter(float data) {
//    if (!is_full_queue(&filter_data)) {
//        en_queue(&filter_data, data);
//    }
//    else {
//        if (abs(data - get_queue_avg(&filter_data)) < 30) {
//            de_queue(&filter_data);
//            en_queue(&filter_data, data);
//        }
//    }
//    return get_queue_avg(&filter_data);
//}
//
//int main() {
//    float data = 0;
//    while (1) {
//        scanf("%f", &data);
//        printf("%f\n", limiting_filter(data));
//    }
//
//    return 0;
//}

