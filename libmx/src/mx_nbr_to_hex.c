#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr == 0) {
        char* result = mx_strnew(1);
        result[0] = '0';
        return result;
    }

    unsigned long temp = nbr;
    int length = 0;
    while (temp > 0) {
        temp /= 16;
        length++;
    }

    char* result = mx_strnew(length);
    if (!result) {
        return NULL;
    }

    for (int i = length - 1; i >= 0; i--) {
        int remainder = nbr % 16;
        if (remainder < 10) {
            result[i] = '0' + remainder;
        }
        else {
            result[i] = 'a' + remainder - 10;
        }
        nbr /= 16;
    }

    return result;
}
