#define _CRT_SECURE_NO_WARNINGS  1

#include <stdio.h>
#include <math.h>


#define PI  3.14159265
#define ANGLE_TO_RAD(x)     ( (x) * PI / 180.0 )

//自定义abs
float my_abs(float num)
{
    if (num < 0) {
        return -num;
    }
    else {
        return num;
    }
}

//自定义pow函数
double my_pow(double x, int k)
{
    if (k > 0)
        return x * my_pow(x, k - 1);
    else if (k == 0)
        return 1;
    else
        return 1.0 / my_pow(x, -k);

}

double my_cos(double x)
{
    x = my_abs(x);
    int t, q = 1;
    double term, factorial = 1.0, sum2 = 1, sxm, sum1 = 0;
    for (t = 2;; t++)
    {
        factorial = factorial * t;
        if (t % 2 == 0)
        {
            sum1 = sum2;
            q = q * (-1);
            sxm = my_abs(my_pow(x, t));
            term = sxm / factorial;
            sum2 = q * term + sum2;
        }
        if (my_abs(sum2 - sum1) <= 1e-13)
            break;
    }
    return sum2;
}

//自定义sin函数
double my_sin(double x)
{
    int counter = 0;
    if (x < 0)
        counter = 1;
    else
        counter = 0;
    x = my_abs(x);
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
            sxm = my_abs(my_pow(x, t));
            term = sxm / factorial;
            sum2 = q * term + sum2;
        }
        if (my_abs(sum2 - sum1) <= 1e-13)
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

int main() {
    float angle;
    int count = 0;
    int count_x = 0, count_y = 0;

    do {
        scanf("%f", &angle);
        scanf("%d", &count);
        if (angle <= 180) {
            count_x += (int)(sin(ANGLE_TO_RAD(angle)) * count);
            count_y += (int)(cos(ANGLE_TO_RAD(angle)) * count);
        }
        else {
            count_x += (int)(count * sin(ANGLE_TO_RAD(angle - 360)));
            count_y += (int)(count * cos(ANGLE_TO_RAD(angle - 360)));
        }
        printf("my_sin=%f my_cos=%f\n", my_sin(ANGLE_TO_RAD(angle)), my_cos(ANGLE_TO_RAD(angle)));
        printf("sin=%f cos=%f\n", sin(ANGLE_TO_RAD(angle)), cos(ANGLE_TO_RAD(angle)));
        printf("%d %d\n", count_x, count_y);
    } while (1);

    return 0;
}