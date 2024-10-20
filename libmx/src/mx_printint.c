#include "../inc/libmx.h"

void mx_printint(int n) {
    long num = n;
    if (num < 0) {
        mx_printchar('-');
        num = -num;
    }
    else if (num == 0) {
        mx_printchar('0');
    }
    
    int digits[12];
    int i = 0;

    while (num > 0) {
        digits[i++] = num % 10;
        num /= 10;
    }

    for (int j = i - 1; j >= 0; --j) {
        mx_printchar(digits[j] + 48);
    }
}


