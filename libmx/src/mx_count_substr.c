#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (!str || !sub) {
        return -1;
    }

    if (*sub == '\0') {
        return 0;
    }

    int count = 0;
    const char *temp = str;

    while ((temp = mx_strstr(temp, sub)) != NULL) {
        count++;
        temp++;
    }

    return count;
}
