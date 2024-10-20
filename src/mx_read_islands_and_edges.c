#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

static int add_islands_and_edges(char* island1, char* island2, long length,
                                 t_island* islands, int* island_count,
                                 t_edge* edges, int* edge_count) {
    int index1 = mx_find_island_index(islands, *island_count, island1);
    if (index1 == -1) {
        islands[*island_count].name = mx_strdup(island1);
        if (islands[*island_count].name == NULL) {
            return 1;
        }
        islands[*island_count].index = *island_count;
        index1 = *island_count;
        (*island_count)++;
    }

    int index2 = mx_find_island_index(islands, *island_count, island2);
    if (index2 == -1) {
        islands[*island_count].name = mx_strdup(island2);
        if (islands[*island_count].name == NULL) {
            mx_free_resources(islands, edges, *island_count);
            return 1;
        }
        islands[*island_count].index = *island_count;
        index2 = *island_count;
        (*island_count)++;
    }

    for (int i = 0; i < *edge_count; i++) {
        if ((edges[i].src == index1 && edges[i].dest == index2) ||
            (edges[i].src == index2 && edges[i].dest == index1)) {
            mx_printerr("error: duplicate bridges\n");
            return 1;
        }
    }

    edges[*edge_count].src = index1;
    edges[*edge_count].dest = index2;
    edges[*edge_count].weight = length;
    edges[*edge_count].input_order = *edge_count;
    (*edge_count)++;

    return 0;
}

static int validate_line(int line_number, const char* island1,
                         const char* island2, long long length,
                         unsigned long long* total_path_weight) {
    if (mx_strcmp(island1, island2) == 0) {
        mx_print_error_line(line_number, " is not valid\n");
        return 1;
    }

    if (length <= 0) {
        mx_print_error_line(line_number, " is not valid\n");
        return 1;
    }

    *total_path_weight += length;
    if (*total_path_weight > LONG_MAX) {
        mx_print_error_line(line_number, " is not valid\n");
        return -1;
    }

    if (*total_path_weight > INT_MAX) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        return -1;
    }

    return 0;
}

static int tokenize_line(char* line, char*** tokens, char*** tokens2,
                         int line_number) {
    *tokens = mx_strsplit(line, '-');
    if (*tokens == NULL || (*tokens)[1] == NULL || (*tokens)[2] != NULL) {
        mx_print_error_line(line_number, " is not valid\n");
        mx_del_strarr(tokens);
        return 1;
    }

    *tokens2 = mx_strsplit((*tokens)[1], ',');
    if (*tokens2 == NULL || (*tokens2)[1] == NULL || (*tokens2)[2] != NULL ||
        !mx_isdigit((*tokens2)[1][0])) {
        mx_print_error_line(line_number, " is not valid\n");
        mx_del_strarr(tokens);
        mx_del_strarr(tokens2);
        return 1;
    }

    return 0;
}

static int parse_line(char* line, int line_number, t_island* islands,
                      int* island_count, t_edge* edges, int* edge_count,
                      unsigned long long* total_path_weight) {
    char** tokens = NULL;
    char** tokens2 = NULL;

    if (tokenize_line(line, &tokens, &tokens2, line_number) != 0) {
        return 1;
    }

    char* island1 = tokens[0];
    char* island2 = tokens2[0];
    long long length = mx_atoi(tokens2[1]);

    if (validate_line(line_number, island1, island2, length,
                      total_path_weight) != 0) {
        mx_del_strarr(&tokens);
        mx_del_strarr(&tokens2);
        return 1;
    }

    if (add_islands_and_edges(island1, island2, length, islands, island_count,
                              edges, edge_count) != 0) {
        mx_del_strarr(&tokens);
        mx_del_strarr(&tokens2);
        return 1;
    }

    mx_del_strarr(&tokens);
    mx_del_strarr(&tokens2);
    return 0;
}

int mx_read_islands_and_edges(int fd, t_island** islands, t_edge** edges,
                              int* num_islands) {
    if (mx_allocate_memory(islands, edges, *num_islands) != 0) {
        return 1;
    }

    char* line = NULL;
    size_t buf_size = 1024;
    int res = 0;
    int island_count = 0;
    int edge_count = 0;
    unsigned long long total_path_weight = 0;

    res = mx_read_line(&line, buf_size, '\n', fd);
    mx_strdel(&line);

    int line_number = 2;

    while ((res = mx_read_line(&line, buf_size, '\n', fd)) > 0) {
        if (parse_line(line, line_number, *islands, &island_count, *edges,
                       &edge_count, &total_path_weight) != 0) {
            mx_strdel(&line);
            mx_free_resources(*islands, *edges, island_count);
            return 1;
        }

        mx_strdel(&line);
        line_number++;
    }

    return 0;
}

int mx_parse_first_line(int fd, int* num_islands, char* filename) {
    char* line = NULL;
    size_t buf_size = 1024;
    int res = mx_read_line(&line, buf_size, '\n', fd);

    if (res < 0) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        return 1;
    }

    *num_islands = mx_atoi(line);
    mx_strdel(&line);

    if (*num_islands <= 0) {
        mx_printerr("error: line 1 is not valid\n");
        return 1;
    }
    return 0;
}
