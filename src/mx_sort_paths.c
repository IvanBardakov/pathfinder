#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

static bool edges_compare(t_path* path1, t_path* path2) {
    int min_length = (path1->path_edges_count < path2->path_edges_count)
                             ? path1->path_edges_count
                             : path2->path_edges_count;

    for (int i = 0; i < min_length; i++) {
        int src1_index = path1->route_edges[i].src;
        int src2_index = path2->route_edges[i].src;
        int dest1_index = path1->route_edges[i].dest;
        int dest2_index = path2->route_edges[i].dest;

        if ((src1_index == src2_index && dest1_index == dest2_index) ||
            (src1_index == dest2_index && dest1_index == src2_index)) {
            continue;
        }

        if (src1_index == src2_index) {
            return dest1_index < dest2_index;
        }

        if (dest1_index == dest2_index) {
            return src1_index < src2_index;
        }

        if (src1_index == dest2_index) {
            return dest1_index < src2_index;
        }

        if (dest1_index == src2_index) {
            return src1_index < dest2_index;
        }
    }

    return false;
}

void mx_sort_paths(t_path* paths, int path_count) {
    for (int i = 0; i < path_count - 1; i++) {
        for (int j = 0; j < path_count - 1 - i; j++) {
            if (paths[j].src_dest[0] == paths[j + 1].src_dest[0] &&
                paths[j].src_dest[1] == paths[j + 1].src_dest[1]) {
                if (!edges_compare(&paths[j], &paths[j + 1])) {
                    t_path temp = paths[j];
                    paths[j] = paths[j + 1];
                    paths[j + 1] = temp;
                }
            }
        }
    }
}
