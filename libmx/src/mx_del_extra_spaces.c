#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str)
{
     if (!str) {
        return NULL;
    }

    int len = mx_strlen(str);
    if (len == 0) {
        return mx_strnew(0); 
    }

    char *temp_string = mx_strnew(len);
    if (!temp_string) {
        return NULL;
    }

    int i = 0, j = 0;
    while (str[i]) {
        if (!mx_isspace(str[i])) {
            temp_string[j++] = str[i];
        } else if (j > 0 && !mx_isspace(temp_string[j - 1])) {
            temp_string[j++] = ' ';
        }
        i++;
    }

    if (j > 0 && temp_string[j - 1] == ' ') {
        j--;
    }
    temp_string[j] = '\0';

    char *result = mx_strtrim(temp_string);
    mx_strdel(&temp_string);
    return result;
}
