#include "../inc/libmx.h"

void mx_del_strarr(char ***strarr) {
    if (!strarr || !*strarr) return;
    for (int i = 0; (*strarr)[i] != NULL; i++) {
        mx_strdel(&(*strarr)[i]); 
    }
    free(*strarr); 
    *strarr = NULL; 
}
