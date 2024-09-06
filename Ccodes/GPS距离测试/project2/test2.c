#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

#define ANGLE_TO_RAD(x)    ((x) * PI / 180.0)                                   // 角度转换为弧度
#define RAD_TO_ANGLE(x)    ((x) * 180.0 / PI)                                   // 弧度转换为角度
#define PI                 3.141592     /*(3.1415926535898)*/

//自定义abs函数
double func_abs_my(double x)
{
    return (x >= 0 ? x : -x);
}

//自定义pow函数
double func_pow(double x, int k)
{
    if (k > 0)
        return x * func_pow(x, k - 1);
    else if (k == 0)
        return 1;
    else
        return 1.0 / func_pow(x, -k);
}

//自定义sqrt函数
double func_sqrt(double x)
{
    double j, k;
    j = 0.0;
    k = x / 2;
    while (j != k)
    {
        j = k;
        k = (j + x / j) / 2;
    }
    return j;
}

//自定义cos函数
double func_cos(double x)
{
    x = func_abs_my(x);
    int t, q = 1;
    double term, factorial = 1.0, sum2 = 1, sxm, sum1 = 0;
    for (t = 2;; t++)
    {
        factorial = factorial * t;
        if (t % 2 == 0)
        {
            sum1 = sum2;
            q = q * (-1);
            sxm = func_abs_my(func_pow(x, t));
            term = sxm / factorial;
            sum2 = q * term + sum2;
        }
        if (func_abs_my(sum2 - sum1) <= 1e-13)
            break;
    }
    return sum2;
}

//自定义sin函数
double func_sin(double x)
{
    int counter = 0;
    if (x < 0)
        counter = 1;
    else
        counter = 0;
    x = func_abs_my(x);
    int t, q = 1;
    double term, factorial = 1.0, sum2, sxm, sum1 = 0;
    sum2 = x;
    for (t = 2;; t++)
    {
        factorial = factorial * t;
        if (t % 2 != 0)
        {
            sum1 = sum2;
            q = q * (-1);
            sxm = func_abs_my(func_pow(x, t));
            term = sxm / factorial;
            sum2 = q * term + sum2;
        }
        if (func_abs_my(sum2 - sum1) <= 1e-13)
            break;
    }
    if (counter == 1)
    {
        sum2 = -sum2;
        return sum2;
    }
    else
        return sum2;
}


double get_two_points_distance_function(double latitude1, double longitude1, double latitude2, double longitude2)
{
    const double EARTH_RADIUS = 6378137;                                        // 地球半径(单位：m)
    double rad_latitude1;
    double rad_latitude2;
    double rad_longitude1;
    double rad_longitude2;
    double distance/*, distance1, distance10, distance11, distance12, distance13, distance14, distance2, distance3*/;
    double a;
    double b;

    rad_latitude1 = ANGLE_TO_RAD(latitude1);                                    // 根据角度计算弧度
    rad_latitude2 = ANGLE_TO_RAD(latitude2);
    rad_longitude1 = ANGLE_TO_RAD(longitude1);
    rad_longitude2 = ANGLE_TO_RAD(longitude2);

    a = rad_latitude1 - rad_latitude2;
    b = rad_longitude1 - rad_longitude2;

    distance = 2 * asinf(func_sqrt(func_pow(func_sin(a / 2), 2) + func_cos(rad_latitude1) * func_cos(rad_latitude2) * func_pow(func_sin(b / 2), 2)));   // google maps 里面实现的算法
    distance = distance * EARTH_RADIUS;

    return distance;
}

int main()
{
    double dis = 0.0;

    dis = get_two_points_distance_function(0, 0, 0.000008, 0.000008);

    printf("%lf\n", dis);

    return 0;
}