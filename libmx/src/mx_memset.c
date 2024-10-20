#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *ptr = (unsigned char *)b;
    while (len-- > 0) {
        *ptr++ = (unsigned char)c;
    }
    return b;
}
