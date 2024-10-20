#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

bool is_valid_island_name(const char* name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!mx_isupper(name[i]) && !mx_islower(name[i])) {
            return false;
        }
    }
    return true;
}

int process_island(const char* island, char** island_names, int* island_count,
                   int expected_islands) {

    if (!is_valid_island_name(island)) {
        return -1;
    }

    for (int j = 0; j < *island_count; j++) {
        if (mx_strcmp(island, island_names[j]) == 0) {
            return 0;
        }
    }

    if (*island_count < expected_islands) {
        island_names[(*island_count)++] = mx_strdup(island);
        return 0;
    } else {
        return 1;
    }
}

int mx_check_islands(int fd, int expected_islands) {
    char* line = NULL;
    size_t buf_size = 1024;
    int res = 0;
    int island_count = 0;
    int line_number = 2;

    char** island_names = malloc((expected_islands + 1) * sizeof(char*));
    if (!island_names) {
        mx_printerr("error: memory allocation failed for island names\n");
        return 1;
    }

    for (int i = 0; i < expected_islands + 1; i++) {
        island_names[i] = NULL;
    }

    while ((res = mx_read_line(&line, buf_size, '\n', fd)) >= 0) {
        if (res == 0) {
            mx_print_error_and_cleanup("error: line ", mx_itoa(line_number),
                                       island_names, line, NULL, NULL);
            mx_printerr(" is not valid\n");
            return -1;
        }

        char** tokens = mx_strsplit(line, '-');
        if (!tokens || !tokens[0] || !tokens[1]) {
            mx_print_error_and_cleanup("error: line ", mx_itoa(line_number),
                                       island_names, line, tokens, NULL);
            mx_printerr(" is not valid\n");
            return -1;
        }

        char** island2_tokens = mx_strsplit(tokens[1], ',');
        if (!island2_tokens || !island2_tokens[0]) {
            mx_print_error_and_cleanup("error: line ", mx_itoa(line_number),
                                       island_names, line, tokens,
                                       island2_tokens);
            mx_printerr(" is not valid\n");
            return -1;
        }

        int res1 = process_island(tokens[0], island_names, &island_count,
                                  expected_islands);
        int res2 = process_island(island2_tokens[0], island_names,
                                  &island_count, expected_islands);

        if (res1 < 0 || res2 < 0) {
            char* line_number_str = mx_itoa(line_number);
            mx_printerr("error: line ");
            mx_printerr(line_number_str);
            mx_printerr(" is not valid\n");
            mx_strdel(&line_number_str);
            mx_print_error_and_cleanup("", line_number_str, island_names, line,
                                       tokens, island2_tokens);
            return -1;
        }
        if (res1 == 1 || res2 == 1) {
            mx_printerr("error: invalid number of islands\n");
            mx_strdel(&line);
            mx_del_strarr(&tokens);
            mx_del_strarr(&island2_tokens);
            mx_del_strarr(&island_names);
            return 1;
        }

        mx_strdel(&line);
        mx_del_strarr(&island2_tokens);
        mx_del_strarr(&tokens);
        line_number++;
    }

    if (island_count != expected_islands) {
        mx_printerr("error: invalid number of islands\n");
        for (int i = 0; i < island_count; i++) {
            mx_strdel(&island_names[i]);
        }
        mx_del_strarr(&island_names);
        return 1;
    }

    mx_del_strarr(&island_names);

    return 0;
}
