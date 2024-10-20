#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    int len = mx_strlen(s);
    int i = 0;
    while (i < len/2) {
        mx_swap_char(&s[i], &s[len - i - 1]);
        i++;
    }
}
