#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const unsigned char *ptr = (const unsigned char *)s + n;

    while (n-- > 0) {
        if (*(--ptr) == (unsigned char)c) {
            return (void *)ptr;
        }
    }
    return NULL;
}
