//#include <stdio.h>
//
//int arr1[] = { 1,2,3,4,5 };
//int arr2[] = { 1,2,3,4 };
//int arr3[] = { 1,2,3 };
//int num[] = { 5, 4, 3 };
//
//int(*arr[])[] = {arr1, arr2, arr3};
//
//int main() {
//	for (int i = 0; i < 3; i++) {
//		int n = num[i];
//		for (int j = 0; j < n; j++) {
//			printf("%d ", (*arr[i])[j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

#include <stdio.h>
#include <math.h>

//unsigned long long square_digits(unsigned n) {
//    int count = 0;
//    int res = 0;
//    while (n > 0) {
//        int num = n % 10;
//        n /= 10;
//        res += num * num * (int)pow(10, count);
//        if (num * num > 10)
//            count += 2;
//        else
//            count += 1;
//    }
//    return res;
//}

unsigned long long square_digits(unsigned n) {
    int count = 0;
    unsigned long long res = 0;
    while (n > 0) {
        int num = n % 10;
        n /= 10;
        unsigned long long pow = 1;
        for (int i = 0; i < count; i++)
            pow *= 10;
        res += num * num * pow;
        if (num * num > 10)
            count += 2;
        else
            count += 1;
    }
    return res;
}

int main() {
    unsigned long long res = square_digits(3210987654);
    printf("%lld\n", res);
	return 0;
}