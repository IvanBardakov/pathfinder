#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    if (!head || !*head) return;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    t_list *current_node = *head;
    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }

    free(current_node->next);
    current_node->next = NULL;
}
