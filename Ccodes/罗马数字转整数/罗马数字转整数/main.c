#include <stdio.h>

// I -> 1 V -> 5 X -> 10 L -> 50 C -> 100 
// D -> 500 M -> 1000
int romanToInt(char* s) {
    char roman[7] = "IVXLCDM";
    int num[7] = { 1,5,10,50,100,500,1000 };
    int result = 0;
    int index = 0;  // 当前读取的字符
    int ch_index = 0;
    int tmp = 0;
    while (s[index] != '\0') {
        for (int i = 0; i < 7; i++) {  // 找到当前字母的索引，将字母对应的数字值赋值给tmp
            if (s[index] == roman[i]) {
                tmp = num[i];
                ch_index = i;
                break;
            }
        }
        if (s[index + 1] != '\0') {
            for (int i = 0; i < 7; i++) {  // 找到当前字母下一个的索引，将字母对应的数字值赋值给tmp
                if (s[index + 1] == roman[i]) {
                    if (ch_index < i) {
                        tmp = -tmp;
                    }
                    break;
                }
            }
        }
        result += tmp;
        index++;
    }
    return result;
}

int main() {
    char roman_num[] = "MCMXCIV";
    printf("%d\n", romanToInt(roman_num));
    return 0;
}