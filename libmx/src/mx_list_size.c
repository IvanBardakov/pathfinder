#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    int count = 0;
    t_list *current_node = list;

    while (current_node != NULL) {
        count++;
        current_node = current_node->next;
    }

    return count;
}
