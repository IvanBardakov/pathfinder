#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    size_t needle_len = mx_strlen(needle);

    if (needle_len == 0) {
        return (char *)haystack;
    }

    for (const char *haystack_ptr = haystack; *haystack_ptr; haystack_ptr++) {
        if (mx_strncmp(haystack_ptr, needle, needle_len) == 0) {
            return (char *)haystack_ptr;
        }
    }

    return NULL;
}
