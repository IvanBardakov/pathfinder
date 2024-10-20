#include "../inc/libmx.h"

char* mx_strdup(const char* str) {
    int len = mx_strlen(str);
    char* str1;
    str1 = mx_strnew(len);
    char* str2 = mx_strcpy(str1, str);
    return str2;
}
