#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int s1_len = mx_strlen(s1);
    int s2_len = mx_strlen(s2);
    int final_len = s1_len + s2_len;

    for (int i = s1_len; i < final_len; i++) {
        s1[i] = s2[i - s1_len];
    }
    s1[final_len] = '\0';

    return s1;
}
