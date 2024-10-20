#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

void mx_dijkstra(int num_islands, t_edge* edges, int edge_count, int src,
                 int* dist, int** prev, int* prev_count) {
    bool visited[num_islands];

    for (int i = 0; i < num_islands; i++) {
        dist[i] = INT_MAX;
        prev_count[i] = 0;
        visited[i] = false;
    }
    dist[src] = 0;

    for (int i = 0; i < num_islands - 1; i++) {
        int min_dist = INT_MAX;
        int u = -1;

        for (int j = 0; j < num_islands; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        if (u == -1) {
            break;
        }
        visited[u] = true;

        for (int j = 0; j < edge_count; j++) {
            if (edges[j].src == u || edges[j].dest == u) {
                int v = (edges[j].src == u) ? edges[j].dest : edges[j].src;
                int weight = edges[j].weight;

                if (!visited[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;

                    prev[v][0] = u;
                    prev_count[v] = 1;
                }

                else if (!visited[v] && dist[u] + weight == dist[v]) {
                    prev[v][prev_count[v]++] = u;
                }
            }
        }
    }
}
