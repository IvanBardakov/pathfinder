#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

void mx_free_resources(t_island* islands, t_edge* edges, int island_count) {
    for (int i = 0; i < island_count; i++) {
        mx_strdel(&islands[i].name);
    }
    free(islands);
    free(edges);
}

void mx_cleanup_memory(t_island** islands, t_edge** edges, int island_count) {
    for (int i = 0; i < island_count; i++) {
        free((*islands)[i].name);
    }
    free(*islands);
    free(*edges);
}
