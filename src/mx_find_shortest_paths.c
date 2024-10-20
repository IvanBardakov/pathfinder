#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

void mx_find_shortest_paths(int num_islands, t_edge* edges, int edge_count,
                            t_island* islands) {
    t_path* collected_paths = NULL;
    int collected_path_count = 0;

    for (int i = 0; i < num_islands; i++) {
        int* dist = malloc(num_islands * sizeof(int));
        int** prev = malloc(num_islands * sizeof(int*));
        for (int k = 0; k < num_islands; k++) {
            prev[k] = malloc(num_islands * sizeof(int));
        }
        int* prev_count = malloc(num_islands * sizeof(int));

        mx_dijkstra(num_islands, edges, edge_count, i, dist, prev, prev_count);

        for (int j = i + 1; j < num_islands; j++) {
            int path[num_islands];

            mx_collect_paths(i, j, j, prev, prev_count, path, 0, islands, edges,
                             edge_count, num_islands, &collected_paths,
                             &collected_path_count);
        }

        free(dist);
        for (int k = 0; k < num_islands; k++) {
            free(prev[k]);
        }
        free(prev);
        free(prev_count);
    }

    mx_sort_paths(collected_paths, collected_path_count);

    mx_print_all_paths(collected_paths, collected_path_count, islands);

    for (int i = 0; i < collected_path_count; i++) {
        free(collected_paths[i].src_dest);
        free(collected_paths[i].route_edges);
    }
    free(collected_paths);
}
