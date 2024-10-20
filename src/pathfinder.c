#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 1;
    }

    char* filename = argv[1];
    int fd = mx_open_file(filename);
    if (fd < 0) {
        return 1;
    }

    t_island* islands = NULL;
    t_edge* edges = NULL;
    int num_islands = 0;
    if (mx_parse_first_line(fd, &num_islands, filename) != 0) {
        return 1;
    }

    if (mx_check_islands(fd, num_islands) != 0) {
        return 1;
    }

    fd = mx_open_file(filename);
    if (mx_read_islands_and_edges(fd, &islands, &edges, &num_islands) != 0) {
        close(fd);
        return 1;
    }

    close(fd);
    mx_find_shortest_paths(num_islands, edges,
                           num_islands * (num_islands - 1) / 2, islands);
    mx_free_resources(islands, edges, num_islands);
    return 0;
}
