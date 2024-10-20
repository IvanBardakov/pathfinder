#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

int mx_allocate_memory(t_island** islands, t_edge** edges, int num_islands) {
    *islands = malloc(num_islands * sizeof(t_island));
    if (*islands == NULL) {
        mx_printerr("error: memory allocation failed for islands\n");
        return 1;
    }

    for (int i = 0; i < num_islands; i++) {
        (*islands)[i].name = NULL;
    }

    int max_edges = num_islands * (num_islands - 1) / 2;
    *edges = malloc(max_edges * sizeof(t_edge));
    if (*edges == NULL) {
        mx_printerr("error: memory allocation failed for edges\n");
        mx_cleanup_memory(islands, edges, num_islands);
        return 1;
    }

    for (int i = 0; i < max_edges; i++) {
        (*edges)[i].src = 0;
        (*edges)[i].dest = 0;
        (*edges)[i].weight = 0;
    }

    return 0;
}
