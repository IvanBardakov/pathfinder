#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    if (!list) return;

    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node) return;

    new_node->data = data;
    new_node->next = NULL;

    if (*list == NULL) {
        *list = new_node;
    } else {
        t_list *current_node = *list;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}
