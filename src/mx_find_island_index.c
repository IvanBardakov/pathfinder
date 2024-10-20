#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

int mx_find_island_index(t_island* islands, int island_count,
                         const char* name) {
    for (int i = 0; i < island_count; i++) {
        if (islands[i].name != NULL && mx_strcmp(islands[i].name, name) == 0) {
            return islands[i].index;
        }
    }
    return -1;
}
