#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

static void print_path_details(t_path* path, t_island* islands) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(islands[path->src_dest[0]].name);
    mx_printstr(" -> ");
    mx_printstr(islands[path->src_dest[1]].name);
    mx_printstr("\nRoute: ");

    if (path->path_edges_count == 0) {
        mx_printstr("No edges found for this path.\n");
        return;
    }

    mx_printstr(islands[path->src_dest[0]].name);

    int total_distance = 0;
    int distances[path->path_edges_count];
    int last_dest_index = path->src_dest[0];

    for (int i = 0; i < path->path_edges_count; i++) {
        int src_index = path->route_edges[i].src;
        int dest_index = path->route_edges[i].dest;

        if (last_dest_index == src_index) {
            mx_printstr(" -> ");
            mx_printstr(islands[dest_index].name);
        } else if (last_dest_index == dest_index) {
            mx_printstr(" -> ");
            mx_printstr(islands[src_index].name);
        } else {
            mx_printstr(" -> ");
            mx_printstr(islands[dest_index].name);
        }

        distances[i] = path->route_edges[i].weight;
        total_distance += distances[i];

        last_dest_index =
                (last_dest_index == src_index) ? dest_index : src_index;
    }

    mx_printstr("\n");

    if (path->path_edges_count == 1) {
        mx_printstr("Distance: ");
        mx_printint(total_distance);
        mx_printstr("\n");
    } else {
        mx_printstr("Distance: ");
        for (int i = 0; i < path->path_edges_count; i++) {
            mx_printint(distances[i]);
            if (i != path->path_edges_count - 1) {
                mx_printstr(" + ");
            }
        }
        mx_printstr(" = ");
        mx_printint(total_distance);
        mx_printstr("\n");
    }

    mx_printstr("========================================\n");
}

void mx_print_all_paths(t_path* collected_paths, int collected_path_count,
                        t_island* islands) {
    for (int i = 0; i < collected_path_count; i++) {
        print_path_details(&collected_paths[i], islands);
    }
}
