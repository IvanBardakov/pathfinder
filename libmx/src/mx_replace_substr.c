#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace){
if (!str || !sub || !replace) return NULL;

    int sub_len = mx_strlen(sub);
    int replace_len = mx_strlen(replace);
    int count = mx_count_substr(str, sub);

    if (count == 0) return mx_strdup(str);

    int new_len = mx_strlen(str) + (replace_len - sub_len) * count;
    char *result = mx_strnew(new_len);
    if (!result) return NULL;

    const char *temp = str;
    char *res_ptr = result;

    while ((temp = mx_strstr(temp, sub)) != NULL) {
        int len = temp - str;
        mx_strncpy(res_ptr, str, len);
        res_ptr += len;
        mx_strncpy(res_ptr, replace, replace_len);
        res_ptr += replace_len;
        temp += sub_len;
        str = temp;
    }
    mx_strcpy(res_ptr, str);

    return result;
}
