#include "../inc/libmx.h"

int mx_count_words(const char* str, char c) {

    if (str == NULL) {
        return -1;
    }


    int i = 0;
    int res = 0;
    bool in_word = false;

    while (str[i]) {
        if (str[i] == c) {
            if (in_word) {
                res++;
                in_word = false;
            }
        }
        else {
            in_word = true;
        }
        i++;
    }

    if (in_word) {
        res++;
    }

    return res;
}
