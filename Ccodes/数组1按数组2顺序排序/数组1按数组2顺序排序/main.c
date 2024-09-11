//#include <stdio.h>
//
//int main() {
//	int arr1[] = { 9,9,7,13,22,54,46,77,91,22,91,7,54,99,912,29,16,32,51,7,8,12,13,77};
//	int arr2[] = { 9,22,7,77,13,22,54 };
//
//	int arr1_cnt = 0;  // 用于记录数组1当前访问到的下标
//
//	int len1 = sizeof(arr1) / sizeof(int);
//	int len2 = sizeof(arr2) / sizeof(int);
//
//	for (int i = 0; i < len2; i++) {  // 循环遍历所有第二个数组的元素
//		for (int j = arr1_cnt; j < len1; j++) {
//			if (arr1[j] == arr2[i]) {
//				int temp = arr1[arr1_cnt];
//				arr1[arr1_cnt] = arr1[j];
//				arr1[j] = temp;
//				arr1_cnt++;
//			}
//		}
//	}
//
//	for (int i = arr1_cnt; i < len1; i++) {
//		for (int j = i; j < len1 - 1; j++) {
//			if (arr1[j] > arr1[j + 1]) {
//				int temp = arr1[j];
//				arr1[j] = arr1[j + 1];
//				arr1[j + 1] = temp;
//			}
//		}
//	}
//
//	for (int i = 0; i < len1; i++)
//		printf("%d ", arr1[i]);
//
//	return 0;
//}


//#include <stdio.h>
//
//void RelativeSortArray(int* arr1, int len1, int* arr2, int len2) {
//	int arr1_cnt = 0;  // 记录下当前在第一个数组的下标
//	for (int i = 0; i < len2; i++) {
//		for (int j = arr1_cnt; j < len1; j++) {
//			if (arr1[j] == arr2[i]) {  // 如果找到与第二个数组相关的元素，则将其位置前移
//				int temp = arr1[arr1_cnt];
//				arr1[arr1_cnt] = arr1[j];
//				arr1[j] = temp;
//				arr1_cnt++;
//			}
//		}
//	}
//
//	for (int i = arr1_cnt; i < len1; i++) {  // 用冒泡排序把结尾的元素按升序排列
//		for (int j = i; j < len1 - 1; j++) {
//			if (arr1[j] > arr1[j + 1]) {
//				int temp = arr1[j];
//				arr1[j] = arr1[j + 1];
//				arr1[j + 1] = temp;
//			}
//		}
//	}
//}
//
//int main() {
//	int arr1[] = { 9,9,7,13,22,54,46,77,91,22,91,7,54,99,912,29,16,32,51,7,8,12,13,77};
//	int arr2[] = { 9,22,7,77,13,22,54 };
//
//	int len1 = sizeof(arr1) / sizeof(int);
//	int len2 = sizeof(arr2) / sizeof(int);
//
//	RelativeSortArray(arr1, len1, arr2, len2);
//
//	for (int i = 0; i < len1; i++)
//		printf("%d ", arr1[i]);
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int* RelativeSortArray(int* arr1, int len1, int* arr2, int len2, int* res_len) {
//	int cnt_arr[1001] = { 0 };
//	for (int i = 0; i < len1; i++)
//		cnt_arr[arr1[i]]++;
//	int* res = (int*)malloc(sizeof(int) * len1);
//	*res_len = 0;
//	for (int i = 0; i < len2; i++) {
//		while (cnt_arr[arr2[i]] != 0) {
//			cnt_arr[arr2[i]]--;
//			res[*res_len] = arr2[i];
//			(*res_len)++;
//		}
//	}
//	for (int i = 0; i < 1001; i++) {
//		while (cnt_arr[i] != 0) {
//			cnt_arr[i]--;
//			res[*res_len] = i;
//			(*res_len)++;
//		}
//	}
//	return res;
//}
//
//int main() {
//	int arr1[] = { 9,9,7,13,22,54,46,77,91,22,91,7,54,99,912,29,16,32,51,7,8,12,13,77};
//	int arr2[] = { 9,22,7,77,13,22,54 };
//
//	int len1 = sizeof(arr1) / sizeof(int);
//	int len2 = sizeof(arr2) / sizeof(int);
//
//	int* res;
//	int res_len;
//	res = RelativeSortArray(arr1, len1, arr2, len2, &res_len);
//
//	for (int i = 0; i < res_len; i++)
//		printf("%d ", res[i]);
//
//	return 0;
//}


