#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

int mx_open_file(const char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
    }
    return fd;
}
