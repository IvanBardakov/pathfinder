#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (!lineptr || fd < 0 || buf_size <= 0) {
        return -2;
    }

    static char buffer[4096];
    static int buffer_size = 0;
    static int buffer_index = 0;

    int total_bytes = 0;
    *lineptr = mx_strnew(0); 
    if (!*lineptr) {
        return -2; 
    }

    while (1) {
        
        if (buffer_index >= buffer_size) {
            buffer_size = read(fd, buffer, sizeof(buffer));
            buffer_index = 0;

            
            if (buffer_size <= 0) {
                if (total_bytes > 0) {
                    (*lineptr)[total_bytes] = '\0'; 
                    return total_bytes; 
                }
                free(*lineptr); 
                return buffer_size == 0 ? -1 : -2;
            }
        }

        while (buffer_index < buffer_size) {
            if (buffer[buffer_index] == delim) {
                buffer_index++;
                (*lineptr)[total_bytes] = '\0'; 
                return total_bytes; 
            }

            
            char *temp = mx_realloc(*lineptr, total_bytes + 2);
            if (!temp) {
                free(*lineptr); 
                return -2; 
            }
            *lineptr = temp;

            (*lineptr)[total_bytes] = buffer[buffer_index];
            total_bytes++;
            buffer_index++;
        }
    }
}
