#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

void mx_collect_paths(int real_src, int real_dest, int dest, int** prev,
                      int* prev_count, int* path, int path_length,
                      t_island* islands, t_edge* edges, int edge_count,
                      int num_islands, t_path** collected_paths,
                      int* collected_path_count) {

    path[path_length] = dest;

    if (dest == real_src) {
        int* reversed_path = malloc((path_length + 1) * sizeof(int));
        for (int i = 0; i <= path_length; i++) {
            reversed_path[i] = path[path_length - i];
        }

        (*collected_path_count)++;
        t_path* temp_paths = mx_realloc(
                *collected_paths, (*collected_path_count) * sizeof(t_path));
        if (temp_paths == NULL) {
            free(reversed_path);
            return;
        }
        *collected_paths = temp_paths;
        t_path* new_path = &(*collected_paths)[*collected_path_count - 1];

        new_path->src_dest = malloc(2 * sizeof(int));
        new_path->src_dest[0] = real_src;
        new_path->src_dest[1] = real_dest;

        new_path->route_edges = malloc(path_length * sizeof(t_edge));
        new_path->path_edges_count = 0;

        for (int i = 0; i < path_length; i++) {
            for (int j = 0; j < edge_count; j++) {
                if ((edges[j].src == reversed_path[i] &&
                     edges[j].dest == reversed_path[i + 1]) ||
                    (edges[j].src == reversed_path[i + 1] &&
                     edges[j].dest == reversed_path[i])) {
                    new_path->route_edges[new_path->path_edges_count++] =
                            edges[j];
                    break;
                }
            }
        }

        free(reversed_path);
        return;
    }

    int* sorted_prev = malloc(prev_count[dest] * sizeof(int));
    for (int i = 0; i < prev_count[dest]; i++) {
        sorted_prev[i] = prev[dest][i];
    }

    for (int i = 0; i < prev_count[dest]; i++) {
        mx_collect_paths(real_src, real_dest, sorted_prev[i], prev, prev_count,
                         path, path_length + 1, islands, edges, edge_count,
                         num_islands, collected_paths, collected_path_count);
    }

    free(sorted_prev);
}
