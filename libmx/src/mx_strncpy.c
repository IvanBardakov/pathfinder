#include "../inc/libmx.h"

char* mx_strncpy(char* dst, const char* src, int len) {
    int i = 0;
    while (i < len && src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }

    if (i < len) {
        dst[i] = '\0';
    } else if (len > 0) {
        dst[len] = '\0';
    }

    return dst;
}


