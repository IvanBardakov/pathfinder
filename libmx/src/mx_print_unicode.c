#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    char mb_str[4];
    int len = 0;

    if (c < 0x80) {
        mb_str[0] = c;
        len = 1;
    } else if (c < 0x800) {
        mb_str[0] = (c >> 6) | 0xC0;
        mb_str[1] = (c & 0x3F) | 0x80;
        len = 2;
    } else if (c < 0x10000) {
        mb_str[0] = (c >> 12) | 0xE0;
        mb_str[1] = ((c >> 6) & 0x3F) | 0x80;
        mb_str[2] = (c & 0x3F) | 0x80;
        len = 3;
    } else if (c < 0x110000) {
        mb_str[0] = (c >> 18) | 0xF0;
        mb_str[1] = ((c >> 12) & 0x3F) | 0x80;
        mb_str[2] = ((c >> 6) & 0x3F) | 0x80;
        mb_str[3] = (c & 0x3F) | 0x80;
        len = 4;
    }

    write(1, mb_str, len);
}
