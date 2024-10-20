#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

void mx_print_error_line(int line_number, const char* message) {
    mx_printerr("error: line ");
    char* line_num_str = mx_itoa(line_number);
    mx_printerr(line_num_str);
    mx_printerr(message);
    mx_strdel(&line_num_str);
}

void mx_print_error_and_cleanup(const char* msg, char* line_number_str,
                                char** island_names, char* line, char** tokens,
                                char** island2_tokens) {
    mx_printerr(msg);
    if (line_number_str) {
        mx_printerr(line_number_str);
        mx_strdel(&line_number_str);
    }
    mx_strdel(&line);
    mx_del_strarr(&tokens);
    mx_del_strarr(&island2_tokens);
    mx_del_strarr(&island_names);
}
