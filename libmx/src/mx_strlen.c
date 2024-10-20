#include "../inc/libmx.h"

int mx_strlen(const char *s)
{
    int len = 0;
    int i = 0;
    while (s[i] != '\0') {
        len++;
        i++;
    }
    return len;
}
