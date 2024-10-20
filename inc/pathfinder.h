#ifndef PATHFINDER
#define PATHFINDER

typedef struct {
    char* name;
    int index;
} t_island;

typedef struct {
    int src;
    int dest;
    int weight;
    int input_order;
} t_edge;

typedef struct {
    int* src_dest;
    t_edge* route_edges;
    int path_edges_count;
} t_path;

int mx_find_island_index(t_island* islands, int island_count, const char* name);
void mx_print_path(t_island* islands, int* path, int path_length, t_edge* edges,
                   int edge_count);
void mx_dijkstra(int num_islands, t_edge* edges, int edge_count, int src,
                 int* dist, int** prev, int* prev_count);
void mx_collect_paths(int real_src, int real_dest, int dest, int** prev,
                      int* prev_count, int* path, int path_length,
                      t_island* islands, t_edge* edges, int edge_count,
                      int num_islands, t_path** collected_paths,
                      int* collected_path_count);
void reverse_path(int* path, int path_length);
int mx_open_file(const char* filename);
int mx_read_islands_and_edges(int fd, t_island** islands, t_edge** edges,
                              int* num_islands);
int mx_parse_first_line(int fd, int* num_islands, char* filename);
int mx_allocate_memory(t_island** islands, t_edge** edges, int num_islands);
void mx_find_shortest_paths(int num_islands, t_edge* edges, int edge_count,
                            t_island* islands);
void mx_free_resources(t_island* islands, t_edge* edges, int island_count);
void mx_cleanup_memory(t_island** islands, t_edge** edges, int island_count);
int mx_check_islands(int fd, int expected_islands);
void mx_print_error_and_cleanup(const char* msg, char* line_number_str,
                                char** island_names, char* line, char** tokens,
                                char** island2_tokens);
void mx_print_error_line(int line_number, const char* message);
void mx_print_all_paths(t_path* collected_paths, int collected_path_count,
                        t_island* islands);
void mx_sort_paths(t_path* paths, int path_count);
#endif
