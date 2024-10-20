#include "../inc/libmx.h"

char* mx_strndup(const char* s1, size_t n) {
    char* str1 = mx_strnew(n);
    
    for (size_t i = 0; i < n && s1[i] != '\0'; i++) {
        str1[i] = s1[i];
    }
    str1[n] = '\0';

    return str1;
}
