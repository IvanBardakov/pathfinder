#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (!str || !sub) {
        return -2;
    }

    char *substr_ptr = mx_strstr(str, sub);
    if (substr_ptr) {
        return substr_ptr - str;
    }

    return -1;
}

