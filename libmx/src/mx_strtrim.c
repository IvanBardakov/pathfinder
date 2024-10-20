#include "../inc/libmx.h"

char *mx_strtrim(const char *str)
{
    if (str == NULL)
    {
        return NULL;
    }

    int start = 0;
    int end = mx_strlen(str) - 1;

    while (mx_isspace(str[start]))
    {
        start++;
    }

    while (end >= start && mx_isspace(str[end]))
    {
        end--;
    }

    int len = end - start + 1;

    char *trimmed_str = mx_strnew(len);
    if (trimmed_str == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < len; i++)
    {
        trimmed_str[i] = str[start + i];
    }

    return trimmed_str;
}
