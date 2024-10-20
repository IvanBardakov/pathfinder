#include "../inc/libmx.h"

char *mx_itoa(int number) {
    if (number == -2147483648) {
        char *str = mx_strnew(11);
        if (str != NULL) {
            mx_strcpy(str, "-2147483648");
        }
        return str;
    }
    
    int temp = number;
    int length = (number < 0) ? 1 : 0;
    if (number == 0) length = 1;

    while (temp != 0) {
        length++;
        temp /= 10;
    }

    char *str = mx_strnew(length);
    if (str == NULL) {
        return NULL;
    }

    if (number < 0) {
        str[0] = '-';
        number = -number;
    }

    for (int i = length - 1; i >= 0; i--) {
        if (i == 0 && str[0] == '-') break;
        str[i] = (number % 10) + '0';
        number /= 10;
    }

    return str;
}

