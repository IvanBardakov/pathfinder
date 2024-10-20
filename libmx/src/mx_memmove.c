#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;

    if (d == s) {
        return dst;
    }

    if (d < s || d >= s + len) {
        return mx_memcpy(dst, src, len);
    } else {
        unsigned char temp[len];
        mx_memcpy(temp, src, len);
        mx_memcpy(dst, temp, len);
    }

    return dst;
}
