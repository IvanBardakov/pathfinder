#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void*, void*)) {
    if (!lst || !cmp) return lst;

    for (t_list *i = lst; i->next != NULL; i = i->next) {
        t_list *min = i;
        for (t_list *j = i->next; j != NULL; j = j->next) {
            if (cmp(min->data, j->data)) {
                min = j;
            }
        }
        if (min != i) {
            void *temp = i->data;
            i->data = min->data;
            min->data = temp;
        }
    }
    return lst;
}
