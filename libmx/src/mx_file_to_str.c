#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    if (!file)
        return NULL;

    int fd = open(file, O_RDONLY);
    if (fd < 0)
        return NULL;

    char buffer[1024];
    int total_size = 0;
    int bytes_read;
    char *result = NULL;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        char *new_result = mx_realloc(result, total_size + bytes_read + 1);
        if (!new_result) {
            free(result);
            close(fd);
            return NULL;
        }
        result = new_result;
        mx_memcpy(result + total_size, buffer, bytes_read);
        total_size += bytes_read;
    }

    
    if (total_size == 0) {
        close(fd);
        return mx_strdup("");
    }

    if (bytes_read < 0) {
        free(result);
        close(fd);
        return NULL;
    }

    result[total_size] = '\0';
    close(fd);
    return result;
}
